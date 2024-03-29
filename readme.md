MiniNinja
===
A small C++ SDL2 game project.
---
This is a 2D game built using C++ and SDL2. It is an unfinished project from highschool.

The game engine contains a console, a layered scene management system, scene serialization & deserialization, and a collision system (with broad phase and narrow phase collision). The game renders entities in a window, responds to keyboard input, plays audio, manages textures, and supports fonts via SDL2.

I never got around to actually making the game, but building this low-quality game engine was fun and taught me a lot!
After abandoning this game, I started working on [YZE](https://github.com/mboyea/YZE), which implements collision resolution and a proper ECS (entity-component system).

### Install On Windows
* [Install 7-Zip](https://7-zip.org/download.html).
* [Install Git Bash](https://git-scm.com/download/win); make sure to choose "Run Git from the Windows Command Prompt" during installation. This should result in a MINGW64 Bash installation that can access your Windows PATH while having access to Linux commands (ie. the `find` command).
* Install GCC. In the directory `C:\`, download and unzip [MinGW x86_64-XX.X.X-release-win32-seh-msvcrt-rt_vXX-revX.7z](https://github.com/niXman/mingw-builds-binaries/releases); the location of `g++.exe` should be `C:\mingw64\bin\g++.exe`.
* Add `C:\mingw64\bin` to the Windows Environment Variable [PATH](https://www.computerhope.com/issues/ch000549.htm).
* Install [Make for Windows](https://gnuwin32.sourceforge.net/packages/make.htm); the location of `make.exe` should be `C:\Program Files (x86)\GnuWin32\bin\make.exe`.
* Add `C:\Program Files (x86)\GnuWin32\bin\` to the Windows Environment Variable [PATH](https://www.computerhope.com/issues/ch000549.htm).(https://www.computerhope.com/issues/ch000549.htm).
* [Clone this repository](https://docs.github.com/en/repositories/creating-and-managing-repositories/cloning-a-repository#cloning-a-repository) to a directory on your computer. That directory will be referred to as `root`.
* Create directory `root/lib`.
* Install SDL2. In the directory `root/lib`, download and unzip the latest stable buxfix release from the following dependencies: [SDL2-devel-X.XX.X-mingw.zip](https://github.com/libsdl-org/SDL/releases), [SDL2_image-devel-X.XX.X-mingw.zip](https://github.com/libsdl-org/SDL_image/releases), [SDL2_mixer-devel-X.XX.X-mingw.zip](https://github.com/libsdl-org/SDL_mixer/releases), & [SDL2_ttf-devel-X.XX.X-mingw.zip](https://github.com/libsdl-org/SDL_ttf/releases).

From here, everything should be installed to compile & run this software. Note that the Makefile assumes you want to build this with x86_64 SDL.

### Install on Arch Linux
* [Clone this repository](https://docs.github.com/en/repositories/creating-and-managing-repositories/cloning-a-repository#cloning-a-repository) to a directory on your computer. That directory will be referred to as `root`.
* [Install sdl2 sdl2_image sdl2_mixer sdl2_ttf](https://wiki.archlinux.org/title/SDL).

From here, everything should be installed to compile & run this software. Isn't Linux great?

### Compile & Run Scripts
To run a script, open a Bash (or equivalent) terminal within `root` and type the command.

| command | description |
|:----------- |:----------- |
| `make` | compile, link, and run the program |
| `make clean` | remove all compiled files |

### Contribute
Unfortunately, this project doesn't support community contributions right now. Feel free to fork, but be sure to read the license.
