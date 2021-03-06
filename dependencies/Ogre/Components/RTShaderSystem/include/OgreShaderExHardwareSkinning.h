/*
-----------------------------------------------------------------------------
This source file is part of OGRE
(Object-oriented Graphics Rendering Engine)
For the latest info, see http://www.ogre3d.org

Copyright (c) 2000-2009 Torus Knot Software Ltd
Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
-----------------------------------------------------------------------------
*/
#ifndef _ShaderExHardwareSkinning_
#define _ShaderExHardwareSkinning_

#include "OgreShaderPrerequisites.h"
#ifdef RTSHADER_SYSTEM_BUILD_EXT_SHADERS
#include "OgreShaderSubRenderState.h"
#include "OgreShaderParameter.h"
#include "OgreRenderSystem.h"
#include "OgreShaderFunctionAtom.h"

#define HS_MAX_WEIGHT_COUNT 4
namespace Ogre {
namespace RTShader {

class HardwareSkinningFactory;

/** \addtogroup Core
*  @{
*/
/** \addtogroup RTShader
*  @{
*/

/** Implement a sub render state which performes hardware skinning.
Meaning, this sub render states adds calculations which multiply
the points and normals by thier assigned bone matricies.
*/
class _OgreRTSSExport HardwareSkinning : public SubRenderState
{

// Interface.
public:

	/** Class default constructor */
	HardwareSkinning();

	/** 
	@see SubRenderState::getType.
	*/
	virtual const String& getType() const;

	/** 
	@see SubRenderState::getType.
	*/
	virtual int getExecutionOrder() const;

	/** 
	@see SubRenderState::copyFrom.
	*/
	virtual void copyFrom(const SubRenderState& rhs);

		/** 
	Set the hardware skinning parameters.
	@param boneCount The maximum number of bones in the model this material
		 is assigned to. Note that this parameter can be higher but not
		 lower than the actual number of bones.
	 @param weightCount The maximum number of weights/bones affecting
		a vertex. Note that this parameter can be higher but not
		 lower than the actual number of affecting bones.
	*/
	void setHardwareSkinningParam(ushort boneCount, ushort weightCount);

	/** 
	Returns the number of bones in the model assigned to the material.
	@see setHardwareSkinningParam().
	*/
	ushort getBoneCount();

	/** 
	Returns the number of weights/bones affecting a vertex.
	@see setHardwareSkinningParam().
	*/
	ushort getWeightCount();
	
	/** 
	@see SubRenderState::preAddToRenderState.
	*/
	virtual bool preAddToRenderState(RenderState* renderState, Pass* srcPass, Pass* dstPass);

	
	/**
	Sets whether skinning will be enabled for materials not containing hardware
	skinning in their original material.
	@note 
	This value is by default false. However the value is automaticly changed
	to true if the render state was created as a result of material script
	parsing.
	*/
	void setAllowSkinningStateChange(bool value) { mAllowStateChange = value; }
	

	/**
	Returns whether skinning will be enabled for materials not containing hardware
	skinning in their original material.
	@see setAllowSkinningStateChange
	*/
	bool getAllowSkinningStateChange() const {	return mAllowStateChange; }
	

	/**
	Set the factory which created this sub render state
	*/
	void _setCreator(const HardwareSkinningFactory* pCreator) { mCreator = pCreator; }

	static String Type;

	
// Protected methods
protected:


	/** 
	@see SubRenderState::resolveParameters.
	*/
	virtual bool resolveParameters(ProgramSet* programSet);

	/** 
	@see SubRenderState::resolveDependencies.
	*/
	virtual bool resolveDependencies		(ProgramSet* programSet);

	/** 
	@see SubRenderState::addFunctionInvocations.
	*/
	virtual bool addFunctionInvocations	(ProgramSet* programSet);

	/** Adds functions to calculate position data in world, object and projective space */
	void addPositionCalculations(Function* vsMain, int& funcCounter);

	/** Adds the weight of a given position for a given index */
	void addIndexedPositionWeight(Function* vsMain, int index, int& funcCounter);

	/** Adds the calculations for calculating a normal related element */
	void addNormalRelatedCalculations(Function* vsMain,
								ParameterPtr& pNormalRelatedParam, 
								ParameterPtr& pNormalWorldRelatedParam, 
								int& funcCounter);

	/** Adds the weight of a given normal related parameter for a given index */
	void addIndexedNormalRelatedWeight(Function* vsMain, ParameterPtr& pNormalRelatedParam, 
						ParameterPtr& pNormalWorldRelatedParam, 
						int index, int& funcCounter);

	/** Translates an index number to a mask value */
	Operand::OpMask indexToMask(int index);


// Attributes.
protected:
	
	ushort mBoneCount;
	ushort mWeightCount;
	bool mAllowStateChange;

	bool mDoBoneCalculations;
	
	ParameterPtr mParamInPosition;
	ParameterPtr mParamInNormal;
	ParameterPtr mParamInBiNormal;
	ParameterPtr mParamInTangent;		
	ParameterPtr mParamInIndices;
	ParameterPtr mParamInWeights;
	UniformParameterPtr mParamInWorldMatrices;
	UniformParameterPtr mParamInInvWorldMatrix;
	UniformParameterPtr mParamInViewProjMatrix;
	UniformParameterPtr mParamInWorldMatrix;
	UniformParameterPtr mParamInWorldViewProjMatrix;
	
	ParameterPtr mParamTempFloat4;
	ParameterPtr mParamTempFloat3;
	ParameterPtr mParamLocalPositionWorld;
	ParameterPtr mParamLocalNormalWorld;
	ParameterPtr mParamLocalTangentWorld;
	ParameterPtr mParamLocalBinormalWorld;
	ParameterPtr mParamOutPositionProj;

	const HardwareSkinningFactory* mCreator; ///The factory which created this sub render state


};


/** 
A factory that enables creation of HardwareSkinning instances.
@remarks Sub class of SubRenderStateFactory
*/
class _OgreRTSSExport HardwareSkinningFactory : public SubRenderStateFactory
{
public:

	/** 
	@see SubRenderStateFactory::getType.
	*/
	virtual const String& getType() const;

	/** 
	@see SubRenderStateFactory::createInstance.
	*/
	virtual SubRenderState* createInstance(ScriptCompiler* compiler, PropertyAbstractNode* prop, Pass* pass, SGScriptTranslator* translator);

	/** 
	@see SubRenderStateFactory::writeInstance.
	*/
	virtual void writeInstance(MaterialSerializer* ser, SubRenderState* subRenderState, Pass* srcPass, Pass* dstPass);

	/** 
	Sets the list of custom shadow caster materials
	*/
	virtual void setCustomShadowCasterMaterials(const MaterialPtr& caster1Weight, const MaterialPtr& caster2Weight,
		const MaterialPtr& caster3Weight, const MaterialPtr& caster4Weight);
	
	/** 
	Sets the list of custom shadow receiver materials
	*/
	virtual void setCustomShadowReceiverMaterials(const MaterialPtr& receiver1Weight, const MaterialPtr& receiver2Weight,
		const MaterialPtr& receiver3Weight, const MaterialPtr& receiver4Weight);

	/** 
	Returns the name of a custom shadow caster material for a given number of weights
	*/
	const MaterialPtr& getCustomShadowCasterMaterial(ushort index) const;

	/** 
	Returns the name of a custom shadow receiver material for a given number of weights
	*/
	const MaterialPtr& getCustomShadowReceiverMaterial(ushort index) const;


protected:

	/** 
	@see SubRenderStateFactory::createInstanceImpl.
	*/
	virtual SubRenderState* createInstanceImpl();

	/// A set of custom shadow caster materials
	MaterialPtr	mCustomShadowCasterMaterials[HS_MAX_WEIGHT_COUNT];
	/// A set of custom shadow receiver materials
	MaterialPtr	mCustomShadowReceiverMaterials[HS_MAX_WEIGHT_COUNT];
};

/** @} */
/** @} */


}
}

#endif
#endif

