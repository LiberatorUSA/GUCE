
Version numbers of the supported dependencies are as follows:
- Ogre 3D: > 1.7.3 (1.8 HEAD)
- Freetype2 2.6.3
- PCRE 7.0

Note dependencies can have dependencies of their own.
The dependency requirements for those dependancies are dictated by those libraries and should be taken 
into account when updating to a new version of a dependency to avoid conflicts.

- FreeType2 is not itself a dependency for GUCE libraries but rather for most GUI plugins and is as such located in this folder.
- CEGUI 1.6.1 requires PCRE 7.0 
