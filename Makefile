include Makefile.extra

SRCDIR:=src
LIBDIRS:=lib
UTDIR:=unittests
PACKAGE_NAME:=sudokuapp
OBJ_DIR:=obj

.PHONY: all clean exe
all: mklib mksrc mkut exe

mklib:
	@$(MAKE) --no-print-directory -C $(LIBDIRS)
mksrc:
	@$(MAKE) --no-print-directory -C $(SRCDIR)
mkut:
	@$(MAKE) --no-print-directory -C $(UTDIR)

clean:
	@$(MAKE) --no-print-directory clean -C $(LIBDIRS)
	@$(MAKE) --no-print-directory clean -C $(SRCDIR)
	@$(MAKE) --no-print-directory clean -C $(UTDIR)
	$(RM) $(OBJ_DIR)/*.a $(OBJ_DIR)/*.o $(OBJ_DIR)/$(PACKAGE_NAME)

exe:$(OBJ_DIR) $(OBJ_DIR)/$(PACKAGE_NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/$(PACKAGE_NAME): $(SRCDIR)/$(OBJ_DIR)/sudokumain
	$(CP) $(SRCDIR)/$(OBJ_DIR)/sudokumain $(OBJ_DIR)/$(PACKAGE_NAME)