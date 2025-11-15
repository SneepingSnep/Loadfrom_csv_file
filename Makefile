#Global uses of variables
SRC = src/main.c
ALTSRC = src/mainwthrectangles.c
OBJ = $(SRC:.c=.o)
OBJALT = $(ALTSRC:.c=.o)
#/////////////////////////////////////////////////////////////////////////////////
#Here goes the Linux commad section
LINUXCC = gcc
#Find the flags for gcc these below are clang flags
LFLAGS = -Wall -Wextra -std=gnu23 -g -Iheaders
LINUXDELCMD = rm
# Source and object files
LINUXDEL =  ./src/bubble.o  ./src/main.o
LINUXOBJ1 = ./main
# Target executable
LINUXTARGET = mainl
LINUXTARGET1 = gol
LINUXCLEAN = cleanl
#Build
$(LINUXTARGET): $(OBJ)
	$(LINUXCC) $(LFLAGS) -o $@ $(OBJ)

$(LINUXTARGET1): $(LINUXOBJ1)
	$(LINUXOBJ1)

$(LINUXCLEAN):
	$(LINUXDELCMD) $(LINUXDEL)


#//////////////////////////////////////////////////////////////////////////////////
#Here goes windows command section


WINDOWSCC = clang
SIMPLEFLAGS = -Wall -I../raylib/include
RAYLIBFLAGS = -Wall -I../raylib/include -L../raylib/lib -lraylib -lmsvcrt  -lgdi32 -lwinmm 
WCFLAGS = -Wall -Wextra -std=gnu2y -g -Iheaders
ARGS = 15 people-with-age.csv youhavenopowerhere!!.txt
ARGSALT1 = 15
ARGSALT2 = 15 people-with-age.csv
ARGSALT3 = 15 people-with-age.csv out.csv
ARGSALT4 = 15 stdin out2.csv
WINDOWSDELCMD = del
# Source and object files
WINDOWSDEL =  .\src\main.o
WINDOWSOBJ1 = ./mainw.exe
WINDOSOBJALT = ./mainwalt.exe
# Target executable
WINDOWSTARGET = mainw
WINDOWSTARGETalt = mainwalt
WINDOWSTARGET1 = gow1
WINDOWSTARGET2 = gow2
WINDOWSTARGET3 = gow3
WINDOWSTARGET4 = gow4
WINDOWSTARGET1alt = gowalt
WINDOWSCLEAN = cleanw
#
#build

$(WINDOWSTARGETalt): $(OBJALT)
	$(WINDOWSCC) $(WCFLAGS) -o $@ $(OBJALT)
%.o: %.c
	$(WINDOWSCC) -c $(WCFLAGS) $< -o $@

$(WINDOWSTARGET): $(OBJ)
	$(WINDOWSCC) $(RAYLIBFLAGS) -o $@ $(OBJ)
%.o: %.c
	$(WINDOWSCC) -c $(RAYLIBFLAGS) $< -o $@

$(WINDOWSTARGET1alt): $(WINDOSOBJALT)
	$(WINDOSOBJALT)
$(WINDOWSTARGET1): $(WINDOWSOBJ1)
	$(WINDOWSOBJ1) $(ARGSALT1)
$(WINDOWSTARGET2): $(WINDOWSOBJ1)
	$(WINDOWSOBJ1) $(ARGSALT2)
$(WINDOWSTARGET3): $(WINDOWSOBJ1)
	$(WINDOWSOBJ1) $(ARGSALT3)
$(WINDOWSTARGET4): $(WINDOWSOBJ1)
	$(WINDOWSOBJ1) $(ARGSALT4)

$(WINDOWSCLEAN):
	$(WINDOWSDELCMD) $(WINDOWSDEL)


