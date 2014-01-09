#
# makefile
#

# set src, dst directory and flags for protobuf
PROTOC      = protoc
PBFLAGS     = --cpp_out
PBSRC       = ./proto
PBDST       = ./message

# which c plus plus compiler
CPP     = ccache g++

# which c compiler
CC      = ccache cc

# options for compiler
CFLAGS  = -Wall -Werror

# flags of buildhouse
BHFLAGS	= 
#-D_BUILD_HOUSE_GMAE

# is debug? (for development)
CDEBUG  = -g -DDEBUG

# macro
CMACRO	= 
#-D_OLD_MAKEHOUSE_GAME


#AES128  module
AESOBJS =aes128/aesCore.o \
		 aes128/aesCbc.o \
		 aes128/cbc128.o \
		 aes128/AESEncrypt.o

#bzip2 module
BZIPOBJS=bzip2/blocksort.o \
		 bzip2/bzlib.o \
		 bzip2/compress.o \
		 bzip2/crctable.o \
		 bzip2/decompress.o\
		 bzip2/huffman.o \
		 bzip2/randtable.o



# objects
OBJS    = 	main.o \
		Config.o \
		SendTask.o \
		database.o \
		Evloop.o \
		Sock.o \
		Single.o \
		ThreadPool.o \
		RecvTask.o \
		AuthTask.o \
		ProcessManager.o \
		$(AESOBJS) \
		$(BZIPOBJS) \
		content/LoginCheck.o \
		content/epManager.o \
		content/epClass.o \
		content/epClassroom.o \
		content/epPerson.o \
		content/epTeacher.o \
		content/epStudent.o \
		\
		handler/HandleMessage.o \
		handler/HandleLogin.o




# binary
BIN	    = epServer

# where are include files kept
INC	    = -I. -I./includes -I./handler -I./content

# for Linker
LINK        = libs/libev.a libs/libglog.a libs/liblua52.so libs/libmysqlcppconn.so
#LINK        = -lev -lglog -lmysqlcppconn -llua5.2
# rock..
all	: clean precompile_protobuf $(BIN)

precompile_protobuf:
	$(PROTOC) $(PBFLAGS)=$(PBDST) $(PBSRC)/*

# how to compiling programs
$(BIN):$(OBJS)
#	$(CPP) $(CFLAGS) $(CDEBUG) -o $@ $(OBJS)
	$(CPP) $(CFLAGS) $(CDEBUG) $(BHFLAGS) $(CMACRO) -o $@ $(OBJS) $(LINK)
%.o:%.cpp
	$(CPP) $(CFLAGS) $(CDEBUG) $(BHFLAGS) $(CMACRO) $(INC) -o $@ -c $<
%.o:%.cc
	$(CPP) $(CFLAGS) $(CDEBUG) $(BHFLAGS) $(CMACRO) $(INC) -o $@ -c $<
%.o:%.c
	$(CC)  $(CFLAGS) $(CDEBUG) $(BHFLAGS) $(CMACRO) $(INC) -o $@ -c $<

.PHONY: clean

clean:
	-rm -rf $(OBJS) $(BIN) *~ logs .lock
