include Makefile.extra

SRCDIR:=src
LIBDIRS:=-Llib/obj
LDFLAGS:=-lsudoku
MAIN_APP:=true
PACKAGE_NAME:=sudokuapp
OBJ_DIR:=obj

.PHONY: all clean exe
all: mklib mksrc mkut exe

mklib:
	@$(MAKE) --no-print-directory -C lib/
mksrc:
	@$(MAKE) --no-print-directory -C src
mkut:
	@$(MAKE) --no-print-directory -C unittests

clean:
	@$(MAKE) --no-print-directory  clean -C lib
	@$(MAKE) --no-print-directory  clean -C src
	@$(MAKE) --no-print-directory  clean -C unittests
	$(RM) $(OBJ_DIR)/*.a $(OBJ_DIR)/*.o $(OBJ_DIR)/$(PACKAGE_NAME)

exe:$(OBJ_DIR)/$(PACKAGE_NAME)

$(OBJ_DIR)/$(PACKAGE_NAME): $(SRCDIR)/$(OBJ_DIR)/sudokumain
	$(CP) $(SRCDIR)/$(OBJ_DIR)/sudokumain $(OBJ_DIR)/$(PACKAGE_NAME)