include ../Makefile.extra

LIBNAME:=sudoku

OBJ_DIR:=obj
ALGO_OBJ_DIR:=$(OBJ_DIR)/SolveAlgorithm
ALGODIR:=SolveAlgorithm

LIB:=$(OBJ_DIR)/lib$(LIBNAME).a 

INCLUDES:= \
	./../include \
	./../include/SolveAlgorithm

CXXFLAGS+=$(addprefix -I,$(INCLUDES))

SRC:=\
	SudokuCoord.cpp \
	SudokuPuzzle.cpp \
	SudokuSolver.cpp \
	$(ALGODIR)/IterativeBacktrack.cpp \
	$(ALGODIR)/NakedOnes.cpp

COMMON_HEADERS:=\
	../include/SudokuCommonTypes.h \
	../include/AlgorithmInterface.h

OBJ:=$(SRC:%.cpp=$(OBJ_DIR)/%.o)

.PHONY: make_lib
make_lib: $(OBJ_DIR) $(LIB)

#make the library
$(LIB): $(OBJ)
	$(AR) $@ $(OBJ)

$(OBJ): $(OBJ_DIR)/%.o: %.cpp ../include/%.h
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
	mkdir -p $(ALGO_OBJ_DIR)

.PHONY: clean
clean:
	$(RM) -r *.o $(OBJ_DIR)/*.o $(OBJ_DIR)/*.a