WORKDIR = `pwd`

CC = gcc
CXX = g++
AR = ar
LD = g++
WINDRES = 

INC = 
CFLAGS = -Wall
RESINC = 
LIBDIR = 
LIB = 
LDFLAGS = 

INC_LINUX_64_BIT__DEBUG = $(INC) -I/usr/include/SDL2 -I../include/textscreen/include
CFLAGS_LINUX_64_BIT__DEBUG = $(CFLAGS) -m64 -g
RESINC_LINUX_64_BIT__DEBUG = $(RESINC)
RCFLAGS_LINUX_64_BIT__DEBUG = $(RCFLAGS)
LIBDIR_LINUX_64_BIT__DEBUG = $(LIBDIR) -L/usr/lib -L../include/textscreen/liblinux/x64
LIB_LINUX_64_BIT__DEBUG = $(LIB) 
LDFLAGS_LINUX_64_BIT__DEBUG = $(LDFLAGS) -m64 -ltextscreen -lSDL2main -lSDL2
OBJDIR_LINUX_64_BIT__DEBUG = x64/obj/Debug
DEP_LINUX_64_BIT__DEBUG = 
OUT_LINUX_64_BIT__DEBUG = x64/bin/Debug/raptorsetup

INC_LINUX_64_BIT__RELEASE = $(INC) -I/usr/include/SDL2 -I../include/textscreen/include
CFLAGS_LINUX_64_BIT__RELEASE = $(CFLAGS) -O2 -m64
RESINC_LINUX_64_BIT__RELEASE = $(RESINC)
RCFLAGS_LINUX_64_BIT__RELEASE = $(RCFLAGS)
LIBDIR_LINUX_64_BIT__RELEASE = $(LIBDIR) -L/usr/lib -L../include/textscreen/liblinux/x64
LIB_LINUX_64_BIT__RELEASE = $(LIB) 
LDFLAGS_LINUX_64_BIT__RELEASE = $(LDFLAGS) -s -m64 -lSDL2main -lSDL2 -ltextscreen
OBJDIR_LINUX_64_BIT__RELEASE = x64/obj/Release
DEP_LINUX_64_BIT__RELEASE = 
OUT_LINUX_64_BIT__RELEASE = x64/bin/Release/raptorsetup

OBJ_LINUX_64_BIT__DEBUG = $(OBJDIR_LINUX_64_BIT__DEBUG)/__/src/txt_mouseinput.o $(OBJDIR_LINUX_64_BIT__DEBUG)/__/src/txt_keyinput.o $(OBJDIR_LINUX_64_BIT__DEBUG)/__/src/txt_joyinput.o $(OBJDIR_LINUX_64_BIT__DEBUG)/__/src/sound.o $(OBJDIR_LINUX_64_BIT__DEBUG)/__/src/prefapi.o $(OBJDIR_LINUX_64_BIT__DEBUG)/__/src/music.o $(OBJDIR_LINUX_64_BIT__DEBUG)/__/src/main.o $(OBJDIR_LINUX_64_BIT__DEBUG)/__/src/input.o

OBJ_LINUX_64_BIT__RELEASE = $(OBJDIR_LINUX_64_BIT__RELEASE)/__/src/txt_mouseinput.o $(OBJDIR_LINUX_64_BIT__RELEASE)/__/src/txt_keyinput.o $(OBJDIR_LINUX_64_BIT__RELEASE)/__/src/txt_joyinput.o $(OBJDIR_LINUX_64_BIT__RELEASE)/__/src/sound.o $(OBJDIR_LINUX_64_BIT__RELEASE)/__/src/prefapi.o $(OBJDIR_LINUX_64_BIT__RELEASE)/__/src/music.o $(OBJDIR_LINUX_64_BIT__RELEASE)/__/src/main.o $(OBJDIR_LINUX_64_BIT__RELEASE)/__/src/input.o

all: linux_64_bit__debug linux_64_bit__release

clean: clean_linux_64_bit__debug clean_linux_64_bit__release

before_linux_64_bit__debug: 
	test -d x64/bin/Debug || mkdir -p x64/bin/Debug
	test -d $(OBJDIR_LINUX_64_BIT__DEBUG)/__/src || mkdir -p $(OBJDIR_LINUX_64_BIT__DEBUG)/__/src

after_linux_64_bit__debug: 

linux_64_bit__debug: before_linux_64_bit__debug out_linux_64_bit__debug after_linux_64_bit__debug

out_linux_64_bit__debug: before_linux_64_bit__debug $(OBJ_LINUX_64_BIT__DEBUG) $(DEP_LINUX_64_BIT__DEBUG)
	$(LD) $(LIBDIR_LINUX_64_BIT__DEBUG) -o $(OUT_LINUX_64_BIT__DEBUG) $(OBJ_LINUX_64_BIT__DEBUG)  $(LDFLAGS_LINUX_64_BIT__DEBUG) $(LIB_LINUX_64_BIT__DEBUG)

$(OBJDIR_LINUX_64_BIT__DEBUG)/__/src/txt_mouseinput.o: ../src/txt_mouseinput.c
	$(CC) $(CFLAGS_LINUX_64_BIT__DEBUG) $(INC_LINUX_64_BIT__DEBUG) -c ../src/txt_mouseinput.c -o $(OBJDIR_LINUX_64_BIT__DEBUG)/__/src/txt_mouseinput.o

$(OBJDIR_LINUX_64_BIT__DEBUG)/__/src/txt_keyinput.o: ../src/txt_keyinput.c
	$(CC) $(CFLAGS_LINUX_64_BIT__DEBUG) $(INC_LINUX_64_BIT__DEBUG) -c ../src/txt_keyinput.c -o $(OBJDIR_LINUX_64_BIT__DEBUG)/__/src/txt_keyinput.o

$(OBJDIR_LINUX_64_BIT__DEBUG)/__/src/txt_joyinput.o: ../src/txt_joyinput.c
	$(CC) $(CFLAGS_LINUX_64_BIT__DEBUG) $(INC_LINUX_64_BIT__DEBUG) -c ../src/txt_joyinput.c -o $(OBJDIR_LINUX_64_BIT__DEBUG)/__/src/txt_joyinput.o

$(OBJDIR_LINUX_64_BIT__DEBUG)/__/src/sound.o: ../src/sound.c
	$(CC) $(CFLAGS_LINUX_64_BIT__DEBUG) $(INC_LINUX_64_BIT__DEBUG) -c ../src/sound.c -o $(OBJDIR_LINUX_64_BIT__DEBUG)/__/src/sound.o

$(OBJDIR_LINUX_64_BIT__DEBUG)/__/src/prefapi.o: ../src/prefapi.c
	$(CC) $(CFLAGS_LINUX_64_BIT__DEBUG) $(INC_LINUX_64_BIT__DEBUG) -c ../src/prefapi.c -o $(OBJDIR_LINUX_64_BIT__DEBUG)/__/src/prefapi.o

$(OBJDIR_LINUX_64_BIT__DEBUG)/__/src/music.o: ../src/music.c
	$(CC) $(CFLAGS_LINUX_64_BIT__DEBUG) $(INC_LINUX_64_BIT__DEBUG) -c ../src/music.c -o $(OBJDIR_LINUX_64_BIT__DEBUG)/__/src/music.o

$(OBJDIR_LINUX_64_BIT__DEBUG)/__/src/main.o: ../src/main.c
	$(CC) $(CFLAGS_LINUX_64_BIT__DEBUG) $(INC_LINUX_64_BIT__DEBUG) -c ../src/main.c -o $(OBJDIR_LINUX_64_BIT__DEBUG)/__/src/main.o

$(OBJDIR_LINUX_64_BIT__DEBUG)/__/src/input.o: ../src/input.c
	$(CC) $(CFLAGS_LINUX_64_BIT__DEBUG) $(INC_LINUX_64_BIT__DEBUG) -c ../src/input.c -o $(OBJDIR_LINUX_64_BIT__DEBUG)/__/src/input.o

clean_linux_64_bit__debug: 
	rm -f $(OBJ_LINUX_64_BIT__DEBUG) $(OUT_LINUX_64_BIT__DEBUG)
	rm -rf x64/bin/Debug
	rm -rf $(OBJDIR_LINUX_64_BIT__DEBUG)/__/src

before_linux_64_bit__release: 
	test -d x64/bin/Release || mkdir -p x64/bin/Release
	test -d $(OBJDIR_LINUX_64_BIT__RELEASE)/__/src || mkdir -p $(OBJDIR_LINUX_64_BIT__RELEASE)/__/src

after_linux_64_bit__release: 

linux_64_bit__release: before_linux_64_bit__release out_linux_64_bit__release after_linux_64_bit__release

out_linux_64_bit__release: before_linux_64_bit__release $(OBJ_LINUX_64_BIT__RELEASE) $(DEP_LINUX_64_BIT__RELEASE)
	$(LD) $(LIBDIR_LINUX_64_BIT__RELEASE) -o $(OUT_LINUX_64_BIT__RELEASE) $(OBJ_LINUX_64_BIT__RELEASE)  $(LDFLAGS_LINUX_64_BIT__RELEASE) $(LIB_LINUX_64_BIT__RELEASE)

$(OBJDIR_LINUX_64_BIT__RELEASE)/__/src/txt_mouseinput.o: ../src/txt_mouseinput.c
	$(CC) $(CFLAGS_LINUX_64_BIT__RELEASE) $(INC_LINUX_64_BIT__RELEASE) -c ../src/txt_mouseinput.c -o $(OBJDIR_LINUX_64_BIT__RELEASE)/__/src/txt_mouseinput.o

$(OBJDIR_LINUX_64_BIT__RELEASE)/__/src/txt_keyinput.o: ../src/txt_keyinput.c
	$(CC) $(CFLAGS_LINUX_64_BIT__RELEASE) $(INC_LINUX_64_BIT__RELEASE) -c ../src/txt_keyinput.c -o $(OBJDIR_LINUX_64_BIT__RELEASE)/__/src/txt_keyinput.o

$(OBJDIR_LINUX_64_BIT__RELEASE)/__/src/txt_joyinput.o: ../src/txt_joyinput.c
	$(CC) $(CFLAGS_LINUX_64_BIT__RELEASE) $(INC_LINUX_64_BIT__RELEASE) -c ../src/txt_joyinput.c -o $(OBJDIR_LINUX_64_BIT__RELEASE)/__/src/txt_joyinput.o

$(OBJDIR_LINUX_64_BIT__RELEASE)/__/src/sound.o: ../src/sound.c
	$(CC) $(CFLAGS_LINUX_64_BIT__RELEASE) $(INC_LINUX_64_BIT__RELEASE) -c ../src/sound.c -o $(OBJDIR_LINUX_64_BIT__RELEASE)/__/src/sound.o

$(OBJDIR_LINUX_64_BIT__RELEASE)/__/src/prefapi.o: ../src/prefapi.c
	$(CC) $(CFLAGS_LINUX_64_BIT__RELEASE) $(INC_LINUX_64_BIT__RELEASE) -c ../src/prefapi.c -o $(OBJDIR_LINUX_64_BIT__RELEASE)/__/src/prefapi.o

$(OBJDIR_LINUX_64_BIT__RELEASE)/__/src/music.o: ../src/music.c
	$(CC) $(CFLAGS_LINUX_64_BIT__RELEASE) $(INC_LINUX_64_BIT__RELEASE) -c ../src/music.c -o $(OBJDIR_LINUX_64_BIT__RELEASE)/__/src/music.o

$(OBJDIR_LINUX_64_BIT__RELEASE)/__/src/main.o: ../src/main.c
	$(CC) $(CFLAGS_LINUX_64_BIT__RELEASE) $(INC_LINUX_64_BIT__RELEASE) -c ../src/main.c -o $(OBJDIR_LINUX_64_BIT__RELEASE)/__/src/main.o

$(OBJDIR_LINUX_64_BIT__RELEASE)/__/src/input.o: ../src/input.c
	$(CC) $(CFLAGS_LINUX_64_BIT__RELEASE) $(INC_LINUX_64_BIT__RELEASE) -c ../src/input.c -o $(OBJDIR_LINUX_64_BIT__RELEASE)/__/src/input.o

clean_linux_64_bit__release: 
	rm -f $(OBJ_LINUX_64_BIT__RELEASE) $(OUT_LINUX_64_BIT__RELEASE)
	rm -rf x64/bin/Release
	rm -rf $(OBJDIR_LINUX_64_BIT__RELEASE)/__/src

.PHONY: before_linux_64_bit__debug after_linux_64_bit__debug clean_linux_64_bit__debug before_linux_64_bit__release after_linux_64_bit__release clean_linux_64_bit__release

