include ../Makefile.extra

LIBNAME:=sudoku

OBJ_DIR:=obj

INCLUDES:= \
	-I./../include

CXXFLAGS+=$(INCLUDES)

SRC:=\
	SudokuUtilChecker.cpp

OBJ:=$(SRC:%.cpp=%.o)

#make the library
$(OBJ_DIR)/lib$(LIBNAME).a: $(OBJ)
	$(AR) $@ $(OBJ)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

.PHONY: clean
clean:
	$(RM) -r *.o $(OBJ_DIR)/*.o $(OBJ_DIR)/*.a