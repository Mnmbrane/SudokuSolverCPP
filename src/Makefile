
SRC:=\
	Source.cpp \
	SudokuUtilChecker.cpp

OBJS:=$(addprefix $(SRCBINDIR)/, $(patsubst %.cpp, %.o, $(wildcard *.cpp)))

sudoku.o: $(OBJS)
	$(CC) $(CFLAGS) -I$(INCLUDEDIR) -o $(SRCBINDIR)/sudoku.o $(OBJS)

$(SRCBINDIR)/%.o: %.cpp
	$(CC) $(CFLAGS) -I$(INCLUDEDIR) -c $< -o $@

.PHONY: clean
clean:
	rm -rf *.o $(SRCBINDIR)/*.o