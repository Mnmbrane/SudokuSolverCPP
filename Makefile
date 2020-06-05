SRCDIR:=src
LIBDIRS:=-Llib/obj
LDFLAGS:=-lsudoku

.PHONY: all cleanall exe
all: $(OBJDIR) mklib mksrc mkut

mklib:
	@$(MAKE) --no-print-directory -C lib

mksrc:
	@$(MAKE) --no-print-directory -C src

mkut:
	@$(MAKE) --no-print-directory -C unittests


#creates main application
exe:
	$(CC) $(CFLAGS) $(CXXFLAGS) $(LIBDIRS) -o $(OBJDIR)/sudoku.exe $(SRCDIR)/$(OBJDIR)/*.o $(LDFLAGS)

cleanall:
	@$(MAKE) clean -C lib
	@$(MAKE) clean -C src
	@$(MAKE) clean -C unittests

include MakeHelper/Makefile.extra
include MakeHelper/Makefile.submake