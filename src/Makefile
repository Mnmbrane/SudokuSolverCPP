include ../Makefile.extra

PACKAGE_NAME:=sudokumain
OBJ_DIR=obj

EXEC:=$(OBJ_DIR)/$(PACKAGE_NAME)

INCLUDES:= \
	../include

LDFLAGS:= \
	-L../lib/obj

LDLIBS:= \
	-lsudoku

CXXFLAGS+= \
	$(addprefix -I,$(INCLUDES)) \
	$(LDFLAGS)

SRC:=\

MAINOBJ:=$(OBJ_DIR)/main.o
OBJ:=$(SRC:%.cpp=$(OBJ_DIR)/%.o)

.PHONY: make_src
make_src: $(OBJ_DIR) $(EXEC)

$(EXEC): $(OBJ_DIR) $(OBJ) $(MAINOBJ)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(MAINOBJ) $(OBJ) $(LDLIBS)

#No header file for main
$(MAINOBJ): $(OBJ_DIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(OBJ): $(OBJ_DIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

.PHONY: clean
clean:
	$(RM) *.o $(OBJ_DIR)/*.o $(OBJ_DIR)/*.a $(EXEC)