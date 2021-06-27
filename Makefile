#***********************************************#
# Define macro "PRINTING" as follows:		#
# NONE    - printing is disabled		#
# COMPACT - for basic information printing	#
# FULL    - thorough printing			#
#***********************************************#
CC	= g++

DATE	= `date +%d%m%Y-%H%M`

#MACROFLAGS += -DNONE=0 -DCOMPACT=1 -DFULL=2
#MACROFLAGS += -DPRINTING=FULL

ifeq ($(CC),icc)
	CFLAGS	= -O3
else ifeq ($(CC),g++)
	CFLAGS	= -O3 -Wno-unused-result
endif

#CFLAGS	+= $(MACROFLAGS)
CFLAGS	+= -fopenmp
#CFLAGS	+= -g
#CFLAGS	+= -std=c++0x
#CFLAGS	+= -static
#CFLAGS	+= -pg
#CFLAGS	+= -Wall

ROOT		= $(CURDIR)
SRCDIR		= $(ROOT)/src
HPPDIR		= $(ROOT)/hpp
OBJDIR		= $(ROOT)/obj

CHECK_CC := $(shell which $(CC))
ifeq ($(CHECK_CC),)
	$(error No $(CC) found!)
endif

.PHONY: all clean dirs

all: dirs prj2SDD

dirs:
	mkdir -p $(OBJDIR)

prj2SDD: $(OBJDIR)/load_input.o $(OBJDIR)/main.o $(OBJDIR)/prjDD.o $(OBJDIR)/prjDDrow.o $(OBJDIR)/prjS.o $(OBJDIR)/prjSDD.o
	$(CC) $(OBJDIR)/load_input.o $(OBJDIR)/main.o $(OBJDIR)/prjDD.o $(OBJDIR)/prjDDrow.o $(OBJDIR)/prjS.o $(OBJDIR)/prjSDD.o $(CFLAGS) -o prj2SDD

$(OBJDIR)/load_input.o: $(SRCDIR)/load_input.cpp
	$(CC) -c $(SRCDIR)/load_input.cpp $(CFLAGS) -o $(OBJDIR)/load_input.o 
	
$(OBJDIR)/main.o: $(SRCDIR)/main.cpp
	$(CC) -c $(SRCDIR)/main.cpp $(CFLAGS) -o $(OBJDIR)/main.o

$(OBJDIR)/prjDD.o: $(SRCDIR)/prjDD.cpp
	$(CC) -c $(SRCDIR)/prjDD.cpp $(CFLAGS) -o $(OBJDIR)/prjDD.o 

$(OBJDIR)/prjDDrow.o: $(SRCDIR)/prjDDrow.cpp
	$(CC) -c $(SRCDIR)/prjDDrow.cpp $(CFLAGS) -o $(OBJDIR)/prjDDrow.o

$(OBJDIR)/prjS.o: $(SRCDIR)/prjS.cpp
	$(CC) -c $(SRCDIR)/prjS.cpp $(CFLAGS) -o $(OBJDIR)/prjS.o

$(OBJDIR)/prjSDD.o: $(SRCDIR)/prjSDD.cpp
	$(CC) -c $(SRCDIR)/prjSDD.cpp $(CFLAGS) -o $(OBJDIR)/prjSDD.o

$(OBJDIR)/aux.o: $(SRCDIR)/aux.cpp
	$(CC) -c $(SRCDIR)/aux.cpp $(CFLAGS) -o $(OBJDIR)/aux.o

clean:
	rm -rf *~ $(SRCDIR)/*~ $(OBJDIR) prj2SDD
