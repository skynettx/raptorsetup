# Raptor Setup
Creates and edits the SETUP.INI config file for Raptor Call Of The Shadows DOS versions and
with additional features for the reverse-engineered source port Raptor as well.
This tool based on the awesome libtextscreen from chocolate-doom.

![Alt text](https://imgur.com/Lo5FQQu.jpg "Raptor Setup")  

The `SETUP.INI` configuration file is created and edited in the following directories under the listed operating systems:
```
Windows: Users\Username\AppData\Roaming\Raptor\
Linux: ~/.local/share/Raptor/
macOS: ~/Library/Application Support/Raptor/
```
Under all other non-officially supported systems, `SETUP.INI` is created and edited in the current working directory.

## Build
The project supports the compilers msvc, gcc and clang. Supported architectures are 32 bit and 64 bit
for Windows, Linux and macOS. When you have installed git on your system you can clone the repository 
by type in `git clone https://github.com/skynettx/raptorsetup.git`.

### Windows
You can use the projectfile for Visual Studio 2022 under `msvc\` or the projectfile for CodeBlocks under `gcc\`.
 
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

### macOS
Please remember to install the required dependencies lib-sdl2.
To build use cmake, type in the root of the repository:
```
mkdir build
cd build
cmake ..
make
```

## Install

### Windows
Copy the file `SDL.dll` from `include\SDL2-devel-2.28.2-VC\SDL2-2.28.2\lib\x86\` for 32 bit installation or for 64 bit installation from `include\SDL2-devel-2.28.2-VC\SDL2-2.28.2\lib\x64\` to working directory.

### Linux
Install lib-sdl2 32 bit and or 64 bit from the packagemanager of your respective distro.

### macOS
Install lib-sdl2 from dmg or from a packagemanager like brew etc.

## Thanks
Special thanks for libtextscreen to all contributors from [chocolate-doom project](https://github.com/chocolate-doom).
