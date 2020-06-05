SRCDIR:=src
LIBDIRS:=-Llib/obj
LDFLAGS:=-lsudoku

.PHONY: all cleanall exe
all: $(OBJDIR) makelib makesrc makeut exe

makelib:
	@$(MAKE) -C lib

makesrc:
	@$(MAKE) -C src

makeut:
	@$(MAKE) -C unittests


#creates main application
exe:
	$(CC) $(CFLAGS) $(CXXFLAGS) $(LIBDIRS) -o $(OBJDIR)/sudoku.exe $(SRCDIR)/$(OBJDIR)/*.o $(LDFLAGS)

cleanall:
	@$(MAKE) clean -C lib
	@$(MAKE) clean -C src
	@$(MAKE) clean -C unittests

include MakeHelper/Makefile.extra
include MakeHelper/Makefile.submake