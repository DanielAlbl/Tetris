SOURCE = callbacks.cpp \
         event.cpp \
         game.cpp \
         main.cpp \
         util.cpp \
         shape.cpp \
         square.cpp \
         twoXtwo.cpp \
         ohhJesus.cpp \
         chode.cpp \
         dick.cpp \
         lhDick.cpp \
         bentDick.cpp \
         lhBentDick.cpp

OBJS = $(SOURCE:.cpp=.o)

#GNU C/C++ Compiler
GCC = g++

# GNU C/C++ Linker
LINK = g++

# Compiler flags
CFLAGS = -Wall -O3 -std=c++11 -I. 
CXXFLAGS = $(CFLAGS)

# Fill in special libraries needed here
LIBS = -lglut -lGL -lGLU -lpthread

.PHONY: clean

# Targets include all, clean, debug, tar

all : tetris

tetris: $(OBJS)
	$(LINK) -o $@ $^ $(LIBS)

clean:
	rm -rf *.o *.d core tetris

debug: CXXFLAGS = -DDEBUG -g -std=c++11
debug: tetris

tar: clean
	tar zcvf tetris.tgz $(SOURCE) *.h Makefile

help:
	@echo "	make main  - same as make all"
	@echo "	make all   - builds the main target"
	@echo "	make       - same as make all"
	@echo "	make clean - remove .o .d core main"
	@echo "	make debug - make all with -g and -DDEBUG"
	@echo "	make tar   - make a tarball of .cpp and .h files"
	@echo "	make help  - this message"

-include $(SOURCE:.cpp=.d)

%.d: %.cpp
	@set -e; /usr/bin/rm -rf $@;$(GCC) -MM $< $(CXXFLAGS) > $@

