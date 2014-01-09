CPP=ccache g++ 
CC=ccache gcc
CFLAGS=-Wall -O0 -Werror -g
LINKS	= -lpthread -lrt -lev -lglog -lmysqlcppconn -lgtest

OBJS	= \
		  gtest_main.o \
		  AESEnrypt_unittest.o \
		  ../AESEncrypt.o \
		  aes_core.o \
		  aes_cbc.o \
		  cbc128.o

#Evloop_unittest.o \

EXE=test.out

VPATH		 = ./../

PWD=`pwd`


#LD_LIBRARY_PATH
INC=-I.\
	-I./../\
	-I$(PWD)/googletest-read-only/include
	#-I$(HOME)/Downloads/gtest-1.6.0/include
	

LIB=-L.\
	-L$(PWD)/googletest-read-only/lib/.libs
	#-L$(HOME)/Downloads/gtest-1.6.0/lib/.libs

all:clean $(EXE)

$(EXE):$(OBJS)
		 $(CPP) $(CFLAGS) $(LIB) $(OBJS) -o $@ $(LINKS)

%.o:%.cc
		 $(CPP) $(CFLAGS) $(INC) -c $< -o $@

%.o:%.cpp
		 $(CPP) $(CFLAGS) $(INC) -c $< -o $@

%.o:%.c
		 $(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	rm -rf $(OBJS) 
	rm -rf $(EXE) 
	rm -rf core*
	rm -rf logs
	rm -f .lock
