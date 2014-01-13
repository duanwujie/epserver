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
BHFLAGS	= -D__DEBUG_HANDLE_HEAD_ \
	  -D__DEBUG_DUMP__

#-D_BUILD_HOUSE_GMAE

# is debug? (for development)
CDEBUG  = -g -DDEBUG

# macro
CMACRO	= 
#-D_OLD_MAKEHOUSE_GAME


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
		\
		aes/aes_cbc.o \
		aes/aes_core.o \
		aes/AESEncrypt.o \
		aes/cbc128.o \
		\
		tar/tar.o \
        tar/xfuncs_printf.o \
        tar/llist.o \
        tar/verror_msg.o \
        tar/wfopen_input.o \
        tar/last_char_is.o \
        tar/messages.o \
        tar/xfunc_die.o \
        tar/default_error_retval.o \
        tar/wfopen.o \
        tar/perror_msg.o \
        tar/get_line_from_file.o \
        tar/procps.o \
        tar/xreadlink.o \
        tar/safe_strncpy.o \
        tar/get_header_tar.o \
        tar/copyfd.o \
        tar/find_list_entry.o \
        tar/header_verbose_list.o\
        tar/recursive_action.o \
        tar/init_handle.o \
        tar/header_list.o \
        tar/seek_by_read.o \
        tar/data_extract_all.o \
        tar/filter_accept_reject_list.o \
        tar/data_extract_to_stdout.o \
        tar/data_skip.o \
        tar/make_directory.o \
        tar/seek_by_jump.o \
        tar/filter_accept_all.o\
        tar/header_skip.o \
        tar/concat_subpath_file.o \
        tar/concat_path_file.o \
        tar/mode_string.o \
        tar/xfuncs.o \
        tar/full_write.o \
        tar/xatonum.o\
        tar/safe_write.o \
        tar/read_printf.o \
        tar/read.o \
        tar/bb_strtonum.o\
        tar/data_align.o \
        tar/safe_poll.o \
        tar/get_last_path_component.o\
        tar/platform.o \
        tar/xrealloc_vector.o \
        tar/bb_pwd.o\
        tar/appletlib.o\
		\
		content/LoginCheck.o \
		content/epManager.o \
		content/epSchool.o \
		content/epClassroom.o \
		content/epClass.o \
		content/epGroup.o \
		content/epPerson.o \
		content/epUser.o \
		content/epTeacher.o \
		content/epStudent.o \
		content/epWhiteBoard.o \
		content/epParents.o \
		content/epHeadmaster.o \
		\
		handler/HandleMessage.o \
		handler/HandleSystem.o \
		handler/HandleLogin.o \
		handler/HandleLogout.o \
		handler/HandleSetFunc.o \
		handler/HandleSetContent.o \
		handler/HandleGetClassList.o \
		handler/HandleGetGradeList.o \
		handler/HandleGetCourseList.o \
		handler/HandleGetStudentList.o \
		handler/HandleGetClassRoomList.o \
		handler/HandleGetStudentInfo.o \
		handler/HandleGetFuncList.o \
		handler/HandleGetTeacherInfo.o \
		handler/HandleStartClass.o \
		handler/HandleGetActiveStudentList.o \
		handler/HandleGetContent.o \
		\
		message/proto/protocol.pb.o

# binary
BIN	    = epServer

# where are include files kept
INC	    = -I. -I./includes -I./handler -I./content -I./message

# for Linker
LINK        = libs/libev.a libs/libglog.a libs/liblua52.so libs/libmysqlcppconn.so -lprotobuf
#LINK        = -lev -lglog -lmysqlcppconn -llua5.2
# rock..
all	: clean precompile_protobuf $(BIN)

precompile_protobuf	:
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
