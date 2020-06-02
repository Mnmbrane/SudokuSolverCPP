.PHONY: all cleanall exe
all: $(OBJDIR) makelib makesrc makeut

makelib:
	@$(MAKE) -C lib

makesrc:
	@$(MAKE) -C src

makeut:
	@$(MAKE) -C unittests


$(OBJDIR):
	mkdir -p obj

cleanall:
	@$(MAKE) clean -C lib
	@$(MAKE) clean -C src
	@$(MAKE) clean -C unittests

SRCDIR:=src
LIBDIRS:=-Llib/obj
LDFLAGS:=-lsudoku
include MakeHelper/Makefile.extra
include MakeHelper/Makefile.submake