# Raptor Setup
Creates and edits the SETUP.INI config file for Raptor Call Of The Shadows DOS versions and
with additional features for the reverse-engineered source port Raptor as well.
This tool based on the awesome libtextscreen from chocolate-doom.

![Alt text](https://imgur.com/hCShMSr.jpg "Raptor Setup")
## Build
The project supports the compilers msvc and gcc. Supported architectures are 32 bit and 64 bit
for Windows and Linux. When you have installed git on your system you can clone the repository 
by type in `git clone https://github.com/skynettx/raptorsetup.git`.

### Windows
You can use the projectfile for Visual Studio 2019 under `msvc\` or the projectfile for CodeBlocks under `gcc\`.
 
### Linux
Please remember to install the required dependencies lib-sdl2 32 bit and or 64 bit. In some distros there is an extra libsdl2-dev 32 bit or 64 bit package like Debian or Ubuntu.  
You can use the projectfile for CodeBlocks under `gcc\`.
Otherwise you can use cmake. To use cmake type in the root of the repository:  
```
mkdir build  
cd build  
cmake ..  
make  
```

## Install

### Windows
Copy the `SDL.dll` from `include\SDL2-devel-2.0.14-VC\SDL2-2.0.14\lib\x86\` `include\SDL2-devel-2.0.14-VC\SDL2-2.0.14\lib\x64\` folder or from 
`include\SDL2-devel-2.0.14-mingw\SDL2-2.0.14\i686-w64-mingw32\bin\` `include\SDL2-devel-2.0.14-mingw\SDL2-2.0.14\x86_64-w64-mingw32\bin\` folder (depending on which version you prefer) to working directory.

### Linux
Install lib-sdl2 32 bit and or 64 bit from the packagemanager of your respective distro.

## Thanks
Special thanks for libtextscreen to all contributors from chocolate-doom project.
