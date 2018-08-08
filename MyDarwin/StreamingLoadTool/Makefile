# Copyright (c) 1999 Apple Computer, Inc.  All rights reserved.
#  

NAME = StreamingLoadTool
C++ = g++
CC = gcc
LINK = g++
CCFLAGS += $(COMPILER_FLAGS) $(INCLUDE_FLAG) -g -Wall
LIBS = $(CORE_LINK_LIBS)  ../CommonUtilitiesLib/x64/libCommonUtilitiesLib.a -lpthread

#OPTIMIZATION
CCFLAGS += -O3 -fno-rtti

# EACH DIRECTORY WITH HEADERS MUST BE APPENDED IN THIS MANNER TO THE CCFLAGS

CCFLAGS += -I.
CCFLAGS += -I..
CCFLAGS += -I../OSMemoryLib
CCFLAGS += -I../RTSPClientLib
CCFLAGS += -I../CommonUtilitiesLib
CCFLAGS += -I../MyDarwin/PrefsSourceLib
CCFLAGS += -I../RTPMetaInfoLib
CCFLAGS += -I../MyDarwin/APICommonCode
CCFLAGS += -I../MyDarwin/APIStubLib
CCFLAGS += -I../MyDarwin/RTCPUtilitiesLib

# EACH DIRECTORY WITH A STATIC LIBRARY MUST BE APPENDED IN THIS MANNER TO THE LINKOPTS

#LINKOPTS = -L../CommonUtilitiesLib

C++FLAGS = $(CCFLAGS)

CFILES = 

CPPFILES = 	StreamingLoadTool.cpp \
                        ../SafeStdLib/InternalStdLib.cpp \
			ClientSocket.cpp \
			RTSPClient.cpp \
			ClientSession.cpp \
			../MyDarwin/PrefsSourceLib/FilePrefsSource.cpp \
			../MyDarwin/APICommonCode/SDPSourceInfo.cpp \
			../MyDarwin/APICommonCode/SourceInfo.cpp \
			RTPMetaInfoPacket.cpp \
			../OSMemoryLib/OSMemory.cpp \
			../MyDarwin/RTCPUtilitiesLib/RTCPPacket.cpp
	

# CCFLAGS += $(foreach dir,$(HDRS),-I$(dir))

DEFINES = -D__PTHREADS_MUTEXES__ -D__PTHREADS__ -DCOMMON_UTILITIES_LIB

all: StreamingLoadTool

StreamingLoadTool: $(CFILES:.c=.o) $(CPPFILES:.cpp=.o)
	$(LINK) -o $@ $(CFILES:.c=.o) *.o  $(COMPILER_FLAGS) $(LINKOPTS) $(LIBS) 

install: StreamingLoadTool

clean:
	rm -f $(CFILES:.c=.o) *.o

.SUFFIXES: .cpp .c .o

.cpp.o:
	$(C++) -c $(DEFINES) $(C++FLAGS) $*.cpp

.c.o:
	$(CC) -c -o $*.o $(DEFINES) $(CCFLAGS) $*.c

