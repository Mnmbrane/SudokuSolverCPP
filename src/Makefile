include ../Makefile.extra

PACKAGE_NAME:=sudokumain
OBJ_DIR=obj

EXEC:=$(OBJ_DIR)/$(PACKAGE_NAME)

INCLUDES:= \
	-I../include

LDFLAGS:= \
	-L../lib/obj

LDLIBS:= \
	-lsudoku

CXXFLAGS+= \
	$(INCLUDES)

SRC:= \
	main.cpp

OBJ:=$(SRC:%.cpp=%.o)

$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $(EXEC) $(OBJ) $(LDLIBS)

.PHONY: clean
clean:
	$(RM) -r $(OBJ_DIR)/*.o $(OBJ_DIR)/*.a $(EXEC)