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

INC_LINUX_32_BIT__DEBUG = $(INC) -I/usr/include/SDL2 -I../include/textscreen/include
CFLAGS_LINUX_32_BIT__DEBUG = $(CFLAGS) -m32 -g
RESINC_LINUX_32_BIT__DEBUG = $(RESINC)
RCFLAGS_LINUX_32_BIT__DEBUG = $(RCFLAGS)
LIBDIR_LINUX_32_BIT__DEBUG = $(LIBDIR) -L/usr/lib32 -L../include/textscreen/liblinux/x86
LIB_LINUX_32_BIT__DEBUG = $(LIB) 
LDFLAGS_LINUX_32_BIT__DEBUG = $(LDFLAGS) -m32 -ltextscreen -lSDL2main -lSDL2
OBJDIR_LINUX_32_BIT__DEBUG = obj/Debug
DEP_LINUX_32_BIT__DEBUG = 
OUT_LINUX_32_BIT__DEBUG = bin/Debug/raptorsetup

INC_LINUX_32_BIT__RELEASE = $(INC) -I/usr/include/SDL2 -I../include/textscreen/include
CFLAGS_LINUX_32_BIT__RELEASE = $(CFLAGS) -O2 -m32
RESINC_LINUX_32_BIT__RELEASE = $(RESINC)
RCFLAGS_LINUX_32_BIT__RELEASE = $(RCFLAGS)
LIBDIR_LINUX_32_BIT__RELEASE = $(LIBDIR) -L/usr/lib32 -L../include/textscreen/liblinux/x86
LIB_LINUX_32_BIT__RELEASE = $(LIB) 
LDFLAGS_LINUX_32_BIT__RELEASE = $(LDFLAGS) -s -m32 -lSDL2main -lSDL2 -ltextscreen
OBJDIR_LINUX_32_BIT__RELEASE = obj/Release
DEP_LINUX_32_BIT__RELEASE = 
OUT_LINUX_32_BIT__RELEASE = bin/Release/raptorsetup

OBJ_LINUX_32_BIT__DEBUG = $(OBJDIR_LINUX_32_BIT__DEBUG)/__/src/txt_mouseinput.o $(OBJDIR_LINUX_32_BIT__DEBUG)/__/src/txt_keyinput.o $(OBJDIR_LINUX_32_BIT__DEBUG)/__/src/txt_joyinput.o $(OBJDIR_LINUX_32_BIT__DEBUG)/__/src/sound.o $(OBJDIR_LINUX_32_BIT__DEBUG)/__/src/prefapi.o $(OBJDIR_LINUX_32_BIT__DEBUG)/__/src/music.o $(OBJDIR_LINUX_32_BIT__DEBUG)/__/src/main.o $(OBJDIR_LINUX_32_BIT__DEBUG)/__/src/input.o

OBJ_LINUX_32_BIT__RELEASE = $(OBJDIR_LINUX_32_BIT__RELEASE)/__/src/txt_mouseinput.o $(OBJDIR_LINUX_32_BIT__RELEASE)/__/src/txt_keyinput.o $(OBJDIR_LINUX_32_BIT__RELEASE)/__/src/txt_joyinput.o $(OBJDIR_LINUX_32_BIT__RELEASE)/__/src/sound.o $(OBJDIR_LINUX_32_BIT__RELEASE)/__/src/prefapi.o $(OBJDIR_LINUX_32_BIT__RELEASE)/__/src/music.o $(OBJDIR_LINUX_32_BIT__RELEASE)/__/src/main.o $(OBJDIR_LINUX_32_BIT__RELEASE)/__/src/input.o

all: linux_32_bit__debug linux_32_bit__release

clean: clean_linux_32_bit__debug clean_linux_32_bit__release

before_linux_32_bit__debug: 
	test -d bin/Debug || mkdir -p bin/Debug
	test -d $(OBJDIR_LINUX_32_BIT__DEBUG)/__/src || mkdir -p $(OBJDIR_LINUX_32_BIT__DEBUG)/__/src

after_linux_32_bit__debug: 

linux_32_bit__debug: before_linux_32_bit__debug out_linux_32_bit__debug after_linux_32_bit__debug

out_linux_32_bit__debug: before_linux_32_bit__debug $(OBJ_LINUX_32_BIT__DEBUG) $(DEP_LINUX_32_BIT__DEBUG)
	$(LD) $(LIBDIR_LINUX_32_BIT__DEBUG) -o $(OUT_LINUX_32_BIT__DEBUG) $(OBJ_LINUX_32_BIT__DEBUG)  $(LDFLAGS_LINUX_32_BIT__DEBUG) $(LIB_LINUX_32_BIT__DEBUG)

$(OBJDIR_LINUX_32_BIT__DEBUG)/__/src/txt_mouseinput.o: ../src/txt_mouseinput.c
	$(CC) $(CFLAGS_LINUX_32_BIT__DEBUG) $(INC_LINUX_32_BIT__DEBUG) -c ../src/txt_mouseinput.c -o $(OBJDIR_LINUX_32_BIT__DEBUG)/__/src/txt_mouseinput.o

$(OBJDIR_LINUX_32_BIT__DEBUG)/__/src/txt_keyinput.o: ../src/txt_keyinput.c
	$(CC) $(CFLAGS_LINUX_32_BIT__DEBUG) $(INC_LINUX_32_BIT__DEBUG) -c ../src/txt_keyinput.c -o $(OBJDIR_LINUX_32_BIT__DEBUG)/__/src/txt_keyinput.o

$(OBJDIR_LINUX_32_BIT__DEBUG)/__/src/txt_joyinput.o: ../src/txt_joyinput.c
	$(CC) $(CFLAGS_LINUX_32_BIT__DEBUG) $(INC_LINUX_32_BIT__DEBUG) -c ../src/txt_joyinput.c -o $(OBJDIR_LINUX_32_BIT__DEBUG)/__/src/txt_joyinput.o

$(OBJDIR_LINUX_32_BIT__DEBUG)/__/src/sound.o: ../src/sound.c
	$(CC) $(CFLAGS_LINUX_32_BIT__DEBUG) $(INC_LINUX_32_BIT__DEBUG) -c ../src/sound.c -o $(OBJDIR_LINUX_32_BIT__DEBUG)/__/src/sound.o

$(OBJDIR_LINUX_32_BIT__DEBUG)/__/src/prefapi.o: ../src/prefapi.c
	$(CC) $(CFLAGS_LINUX_32_BIT__DEBUG) $(INC_LINUX_32_BIT__DEBUG) -c ../src/prefapi.c -o $(OBJDIR_LINUX_32_BIT__DEBUG)/__/src/prefapi.o

$(OBJDIR_LINUX_32_BIT__DEBUG)/__/src/music.o: ../src/music.c
	$(CC) $(CFLAGS_LINUX_32_BIT__DEBUG) $(INC_LINUX_32_BIT__DEBUG) -c ../src/music.c -o $(OBJDIR_LINUX_32_BIT__DEBUG)/__/src/music.o

$(OBJDIR_LINUX_32_BIT__DEBUG)/__/src/main.o: ../src/main.c
	$(CC) $(CFLAGS_LINUX_32_BIT__DEBUG) $(INC_LINUX_32_BIT__DEBUG) -c ../src/main.c -o $(OBJDIR_LINUX_32_BIT__DEBUG)/__/src/main.o

$(OBJDIR_LINUX_32_BIT__DEBUG)/__/src/input.o: ../src/input.c
	$(CC) $(CFLAGS_LINUX_32_BIT__DEBUG) $(INC_LINUX_32_BIT__DEBUG) -c ../src/input.c -o $(OBJDIR_LINUX_32_BIT__DEBUG)/__/src/input.o

clean_linux_32_bit__debug: 
	rm -f $(OBJ_LINUX_32_BIT__DEBUG) $(OUT_LINUX_32_BIT__DEBUG)
	rm -rf bin/Debug
	rm -rf $(OBJDIR_LINUX_32_BIT__DEBUG)/__/src

before_linux_32_bit__release: 
	test -d bin/Release || mkdir -p bin/Release
	test -d $(OBJDIR_LINUX_32_BIT__RELEASE)/__/src || mkdir -p $(OBJDIR_LINUX_32_BIT__RELEASE)/__/src

after_linux_32_bit__release: 

linux_32_bit__release: before_linux_32_bit__release out_linux_32_bit__release after_linux_32_bit__release

out_linux_32_bit__release: before_linux_32_bit__release $(OBJ_LINUX_32_BIT__RELEASE) $(DEP_LINUX_32_BIT__RELEASE)
	$(LD) $(LIBDIR_LINUX_32_BIT__RELEASE) -o $(OUT_LINUX_32_BIT__RELEASE) $(OBJ_LINUX_32_BIT__RELEASE)  $(LDFLAGS_LINUX_32_BIT__RELEASE) $(LIB_LINUX_32_BIT__RELEASE)

$(OBJDIR_LINUX_32_BIT__RELEASE)/__/src/txt_mouseinput.o: ../src/txt_mouseinput.c
	$(CC) $(CFLAGS_LINUX_32_BIT__RELEASE) $(INC_LINUX_32_BIT__RELEASE) -c ../src/txt_mouseinput.c -o $(OBJDIR_LINUX_32_BIT__RELEASE)/__/src/txt_mouseinput.o

$(OBJDIR_LINUX_32_BIT__RELEASE)/__/src/txt_keyinput.o: ../src/txt_keyinput.c
	$(CC) $(CFLAGS_LINUX_32_BIT__RELEASE) $(INC_LINUX_32_BIT__RELEASE) -c ../src/txt_keyinput.c -o $(OBJDIR_LINUX_32_BIT__RELEASE)/__/src/txt_keyinput.o

$(OBJDIR_LINUX_32_BIT__RELEASE)/__/src/txt_joyinput.o: ../src/txt_joyinput.c
	$(CC) $(CFLAGS_LINUX_32_BIT__RELEASE) $(INC_LINUX_32_BIT__RELEASE) -c ../src/txt_joyinput.c -o $(OBJDIR_LINUX_32_BIT__RELEASE)/__/src/txt_joyinput.o

$(OBJDIR_LINUX_32_BIT__RELEASE)/__/src/sound.o: ../src/sound.c
	$(CC) $(CFLAGS_LINUX_32_BIT__RELEASE) $(INC_LINUX_32_BIT__RELEASE) -c ../src/sound.c -o $(OBJDIR_LINUX_32_BIT__RELEASE)/__/src/sound.o

$(OBJDIR_LINUX_32_BIT__RELEASE)/__/src/prefapi.o: ../src/prefapi.c
	$(CC) $(CFLAGS_LINUX_32_BIT__RELEASE) $(INC_LINUX_32_BIT__RELEASE) -c ../src/prefapi.c -o $(OBJDIR_LINUX_32_BIT__RELEASE)/__/src/prefapi.o

$(OBJDIR_LINUX_32_BIT__RELEASE)/__/src/music.o: ../src/music.c
	$(CC) $(CFLAGS_LINUX_32_BIT__RELEASE) $(INC_LINUX_32_BIT__RELEASE) -c ../src/music.c -o $(OBJDIR_LINUX_32_BIT__RELEASE)/__/src/music.o

$(OBJDIR_LINUX_32_BIT__RELEASE)/__/src/main.o: ../src/main.c
	$(CC) $(CFLAGS_LINUX_32_BIT__RELEASE) $(INC_LINUX_32_BIT__RELEASE) -c ../src/main.c -o $(OBJDIR_LINUX_32_BIT__RELEASE)/__/src/main.o

$(OBJDIR_LINUX_32_BIT__RELEASE)/__/src/input.o: ../src/input.c
	$(CC) $(CFLAGS_LINUX_32_BIT__RELEASE) $(INC_LINUX_32_BIT__RELEASE) -c ../src/input.c -o $(OBJDIR_LINUX_32_BIT__RELEASE)/__/src/input.o

clean_linux_32_bit__release: 
	rm -f $(OBJ_LINUX_32_BIT__RELEASE) $(OUT_LINUX_32_BIT__RELEASE)
	rm -rf bin/Release
	rm -rf $(OBJDIR_LINUX_32_BIT__RELEASE)/__/src

.PHONY: before_linux_32_bit__debug after_linux_32_bit__debug clean_linux_32_bit__debug before_linux_32_bit__release after_linux_32_bit__release clean_linux_32_bit__release

