


class EXPORT_CPP CMeshBuilder public : Ogre::ManualResourceLoader
{
        Ogre::MeshPtr ConstructMesh( const Ogre::String& name    ,
                                     const Ogre::String& rcgroup ) const;
};