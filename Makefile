SRCDIR:=src
LIBDIRS:=-Llib/obj
LDFLAGS:=-lsudoku
MAIN_APP:=true

.PHONY: all cleanall exe
all: $(OBJDIR) mklib mksrc mkut exe

mklib:
	@$(MAKE) --no-print-directory -C lib

mksrc:
	@$(MAKE) --no-print-directory -C src

mkut:
	@$(MAKE) --no-print-directory -C unittests

cleanall:
	@$(MAKE) --no-print-directory  clean -C lib
	@$(MAKE) --no-print-directory  clean -C src
	@$(MAKE) --no-print-directory  clean -C unittests

include MakeHelper/Makefile.extra
include MakeHelper/Makefile.submake