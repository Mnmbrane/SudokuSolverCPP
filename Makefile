CC:=gcc
CFLAGS:=-Wall -g
INCLUDEDIR:=${CURDIR}/include
OBJDIR:=${CURDIR}/bin
SRCDIR:=${CURDIR}/src
SRCBINDIR:=$(SRCDIR)/bin

subsystem:
	@mkdir -p $(OBJDIR) $(SRCBINDIR)
	@$(MAKE) -C src
	ar -rcs $(OBJDIR)/sudoku.a $(SRCBINDIR)/sudoku.o

.PHONY: clean
clean:
	@rm -rf $(OBJDIR)/*.o $(OBJDIR)/*.a
	@$(MAKE) clean -C src

export CC
export INCLUDEDIR
export OBJDIR
export LIBDIR
export SRCBINDIR