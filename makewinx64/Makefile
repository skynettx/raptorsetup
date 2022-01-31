WORKDIR = %cd%

CC = gcc.exe
CXX = g++.exe
AR = ar.exe
LD = g++.exe
WINDRES = windres.exe

INC = 
CFLAGS = -Wall
RESINC = 
LIBDIR = 
LIB = 
LDFLAGS = 

INC_WIN_64_BIT__DEBUG = $(INC) -I..\include\SDL2-devel-2.0.14-mingw\SDL2-2.0.14\x86_64-w64-mingw32\include\SDL2 -I..\include\textscreen\include
CFLAGS_WIN_64_BIT__DEBUG = $(CFLAGS) -m64 -g
RESINC_WIN_64_BIT__DEBUG = $(RESINC)
RCFLAGS_WIN_64_BIT__DEBUG = $(RCFLAGS)
LIBDIR_WIN_64_BIT__DEBUG = $(LIBDIR) -L..\include\SDL2-devel-2.0.14-mingw\SDL2-2.0.14\x86_64-w64-mingw32\lib -L..\include\textscreen\libwin\x64
LIB_WIN_64_BIT__DEBUG = $(LIB) 
LDFLAGS_WIN_64_BIT__DEBUG = $(LDFLAGS) -m64 -lmingw32 -ltextscreen -lSDL2main -lSDL2 -lgdi32
OBJDIR_WIN_64_BIT__DEBUG = x64\\obj\\Debug
DEP_WIN_64_BIT__DEBUG = 
OUT_WIN_64_BIT__DEBUG = x64\\bin\\Debug\\raptorsetup.exe

INC_WIN_64_BIT__RELEASE = $(INC) -I..\include\textscreen\include -I..\include\SDL2-devel-2.0.14-mingw\SDL2-2.0.14\x86_64-w64-mingw32\include\SDL2
CFLAGS_WIN_64_BIT__RELEASE = $(CFLAGS) -O2 -m64
RESINC_WIN_64_BIT__RELEASE = $(RESINC)
RCFLAGS_WIN_64_BIT__RELEASE = $(RCFLAGS)
LIBDIR_WIN_64_BIT__RELEASE = $(LIBDIR) -L..\include\SDL2-devel-2.0.14-mingw\SDL2-2.0.14\x86_64-w64-mingw32\lib -L..\include\textscreen\libwin\x64
LIB_WIN_64_BIT__RELEASE = $(LIB) 
LDFLAGS_WIN_64_BIT__RELEASE = $(LDFLAGS) -s -m64 -lmingw32 -ltextscreen -lSDL2main -lSDL2 -lgdi32
OBJDIR_WIN_64_BIT__RELEASE = x64\\obj\\Release
DEP_WIN_64_BIT__RELEASE = 
OUT_WIN_64_BIT__RELEASE = x64\\bin\\Release\\raptorsetup.exe

OBJ_WIN_64_BIT__DEBUG = $(OBJDIR_WIN_64_BIT__DEBUG)\\__\\src\\txt_mouseinput.o $(OBJDIR_WIN_64_BIT__DEBUG)\\__\\src\\txt_keyinput.o $(OBJDIR_WIN_64_BIT__DEBUG)\\__\\src\\txt_joyinput.o $(OBJDIR_WIN_64_BIT__DEBUG)\\__\\src\\sound.o $(OBJDIR_WIN_64_BIT__DEBUG)\\__\\src\\prefapi.o $(OBJDIR_WIN_64_BIT__DEBUG)\\__\\src\\music.o $(OBJDIR_WIN_64_BIT__DEBUG)\\__\\src\\main.o $(OBJDIR_WIN_64_BIT__DEBUG)\\__\\src\\input.o

OBJ_WIN_64_BIT__RELEASE = $(OBJDIR_WIN_64_BIT__RELEASE)\\__\\src\\txt_mouseinput.o $(OBJDIR_WIN_64_BIT__RELEASE)\\__\\src\\txt_keyinput.o $(OBJDIR_WIN_64_BIT__RELEASE)\\__\\src\\txt_joyinput.o $(OBJDIR_WIN_64_BIT__RELEASE)\\__\\src\\sound.o $(OBJDIR_WIN_64_BIT__RELEASE)\\__\\src\\prefapi.o $(OBJDIR_WIN_64_BIT__RELEASE)\\__\\src\\music.o $(OBJDIR_WIN_64_BIT__RELEASE)\\__\\src\\main.o $(OBJDIR_WIN_64_BIT__RELEASE)\\__\\src\\input.o

all: win_64_bit__debug win_64_bit__release

clean: clean_win_64_bit__debug clean_win_64_bit__release

before_win_64_bit__debug: 
	cmd /c if not exist x64\\bin\\Debug md x64\\bin\\Debug
	cmd /c if not exist $(OBJDIR_WIN_64_BIT__DEBUG)\\__\\src md $(OBJDIR_WIN_64_BIT__DEBUG)\\__\\src

after_win_64_bit__debug: 

win_64_bit__debug: before_win_64_bit__debug out_win_64_bit__debug after_win_64_bit__debug

out_win_64_bit__debug: before_win_64_bit__debug $(OBJ_WIN_64_BIT__DEBUG) $(DEP_WIN_64_BIT__DEBUG)
	$(LD) $(LIBDIR_WIN_64_BIT__DEBUG) -o $(OUT_WIN_64_BIT__DEBUG) $(OBJ_WIN_64_BIT__DEBUG)  $(LDFLAGS_WIN_64_BIT__DEBUG) -mwindows $(LIB_WIN_64_BIT__DEBUG)

$(OBJDIR_WIN_64_BIT__DEBUG)\\__\\src\\txt_mouseinput.o: ..\\src\\txt_mouseinput.c
	$(CC) $(CFLAGS_WIN_64_BIT__DEBUG) $(INC_WIN_64_BIT__DEBUG) -c ..\\src\\txt_mouseinput.c -o $(OBJDIR_WIN_64_BIT__DEBUG)\\__\\src\\txt_mouseinput.o

$(OBJDIR_WIN_64_BIT__DEBUG)\\__\\src\\txt_keyinput.o: ..\\src\\txt_keyinput.c
	$(CC) $(CFLAGS_WIN_64_BIT__DEBUG) $(INC_WIN_64_BIT__DEBUG) -c ..\\src\\txt_keyinput.c -o $(OBJDIR_WIN_64_BIT__DEBUG)\\__\\src\\txt_keyinput.o

$(OBJDIR_WIN_64_BIT__DEBUG)\\__\\src\\txt_joyinput.o: ..\\src\\txt_joyinput.c
	$(CC) $(CFLAGS_WIN_64_BIT__DEBUG) $(INC_WIN_64_BIT__DEBUG) -c ..\\src\\txt_joyinput.c -o $(OBJDIR_WIN_64_BIT__DEBUG)\\__\\src\\txt_joyinput.o

$(OBJDIR_WIN_64_BIT__DEBUG)\\__\\src\\sound.o: ..\\src\\sound.c
	$(CC) $(CFLAGS_WIN_64_BIT__DEBUG) $(INC_WIN_64_BIT__DEBUG) -c ..\\src\\sound.c -o $(OBJDIR_WIN_64_BIT__DEBUG)\\__\\src\\sound.o

$(OBJDIR_WIN_64_BIT__DEBUG)\\__\\src\\prefapi.o: ..\\src\\prefapi.c
	$(CC) $(CFLAGS_WIN_64_BIT__DEBUG) $(INC_WIN_64_BIT__DEBUG) -c ..\\src\\prefapi.c -o $(OBJDIR_WIN_64_BIT__DEBUG)\\__\\src\\prefapi.o

$(OBJDIR_WIN_64_BIT__DEBUG)\\__\\src\\music.o: ..\\src\\music.c
	$(CC) $(CFLAGS_WIN_64_BIT__DEBUG) $(INC_WIN_64_BIT__DEBUG) -c ..\\src\\music.c -o $(OBJDIR_WIN_64_BIT__DEBUG)\\__\\src\\music.o

$(OBJDIR_WIN_64_BIT__DEBUG)\\__\\src\\main.o: ..\\src\\main.c
	$(CC) $(CFLAGS_WIN_64_BIT__DEBUG) $(INC_WIN_64_BIT__DEBUG) -c ..\\src\\main.c -o $(OBJDIR_WIN_64_BIT__DEBUG)\\__\\src\\main.o

$(OBJDIR_WIN_64_BIT__DEBUG)\\__\\src\\input.o: ..\\src\\input.c
	$(CC) $(CFLAGS_WIN_64_BIT__DEBUG) $(INC_WIN_64_BIT__DEBUG) -c ..\\src\\input.c -o $(OBJDIR_WIN_64_BIT__DEBUG)\\__\\src\\input.o

clean_win_64_bit__debug: 
	cmd /c del /f $(OBJ_WIN_64_BIT__DEBUG) $(OUT_WIN_64_BIT__DEBUG)
	cmd /c rd x64\\bin\\Debug
	cmd /c rd $(OBJDIR_WIN_64_BIT__DEBUG)\\__\\src

before_win_64_bit__release: 
	cmd /c if not exist x64\\bin\\Release md x64\\bin\\Release
	cmd /c if not exist $(OBJDIR_WIN_64_BIT__RELEASE)\\__\\src md $(OBJDIR_WIN_64_BIT__RELEASE)\\__\\src

after_win_64_bit__release: 

win_64_bit__release: before_win_64_bit__release out_win_64_bit__release after_win_64_bit__release

out_win_64_bit__release: before_win_64_bit__release $(OBJ_WIN_64_BIT__RELEASE) $(DEP_WIN_64_BIT__RELEASE)
	$(LD) $(LIBDIR_WIN_64_BIT__RELEASE) -o $(OUT_WIN_64_BIT__RELEASE) $(OBJ_WIN_64_BIT__RELEASE)  $(LDFLAGS_WIN_64_BIT__RELEASE) -mwindows $(LIB_WIN_64_BIT__RELEASE)

$(OBJDIR_WIN_64_BIT__RELEASE)\\__\\src\\txt_mouseinput.o: ..\\src\\txt_mouseinput.c
	$(CC) $(CFLAGS_WIN_64_BIT__RELEASE) $(INC_WIN_64_BIT__RELEASE) -c ..\\src\\txt_mouseinput.c -o $(OBJDIR_WIN_64_BIT__RELEASE)\\__\\src\\txt_mouseinput.o

$(OBJDIR_WIN_64_BIT__RELEASE)\\__\\src\\txt_keyinput.o: ..\\src\\txt_keyinput.c
	$(CC) $(CFLAGS_WIN_64_BIT__RELEASE) $(INC_WIN_64_BIT__RELEASE) -c ..\\src\\txt_keyinput.c -o $(OBJDIR_WIN_64_BIT__RELEASE)\\__\\src\\txt_keyinput.o

$(OBJDIR_WIN_64_BIT__RELEASE)\\__\\src\\txt_joyinput.o: ..\\src\\txt_joyinput.c
	$(CC) $(CFLAGS_WIN_64_BIT__RELEASE) $(INC_WIN_64_BIT__RELEASE) -c ..\\src\\txt_joyinput.c -o $(OBJDIR_WIN_64_BIT__RELEASE)\\__\\src\\txt_joyinput.o

$(OBJDIR_WIN_64_BIT__RELEASE)\\__\\src\\sound.o: ..\\src\\sound.c
	$(CC) $(CFLAGS_WIN_64_BIT__RELEASE) $(INC_WIN_64_BIT__RELEASE) -c ..\\src\\sound.c -o $(OBJDIR_WIN_64_BIT__RELEASE)\\__\\src\\sound.o

$(OBJDIR_WIN_64_BIT__RELEASE)\\__\\src\\prefapi.o: ..\\src\\prefapi.c
	$(CC) $(CFLAGS_WIN_64_BIT__RELEASE) $(INC_WIN_64_BIT__RELEASE) -c ..\\src\\prefapi.c -o $(OBJDIR_WIN_64_BIT__RELEASE)\\__\\src\\prefapi.o

$(OBJDIR_WIN_64_BIT__RELEASE)\\__\\src\\music.o: ..\\src\\music.c
	$(CC) $(CFLAGS_WIN_64_BIT__RELEASE) $(INC_WIN_64_BIT__RELEASE) -c ..\\src\\music.c -o $(OBJDIR_WIN_64_BIT__RELEASE)\\__\\src\\music.o

$(OBJDIR_WIN_64_BIT__RELEASE)\\__\\src\\main.o: ..\\src\\main.c
	$(CC) $(CFLAGS_WIN_64_BIT__RELEASE) $(INC_WIN_64_BIT__RELEASE) -c ..\\src\\main.c -o $(OBJDIR_WIN_64_BIT__RELEASE)\\__\\src\\main.o

$(OBJDIR_WIN_64_BIT__RELEASE)\\__\\src\\input.o: ..\\src\\input.c
	$(CC) $(CFLAGS_WIN_64_BIT__RELEASE) $(INC_WIN_64_BIT__RELEASE) -c ..\\src\\input.c -o $(OBJDIR_WIN_64_BIT__RELEASE)\\__\\src\\input.o

clean_win_64_bit__release: 
	cmd /c del /f $(OBJ_WIN_64_BIT__RELEASE) $(OUT_WIN_64_BIT__RELEASE)
	cmd /c rd x64\\bin\\Release
	cmd /c rd $(OBJDIR_WIN_64_BIT__RELEASE)\\__\\src

.PHONY: before_win_64_bit__debug after_win_64_bit__debug clean_win_64_bit__debug before_win_64_bit__release after_win_64_bit__release clean_win_64_bit__release

