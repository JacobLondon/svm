TARGET=svm
CXX=clang++
CXXFLAGS=-std=c++17 -march=native -pipe -O2

OBJ_FILES=types/object.o \
		  arg.o machine.o opcode.o \
		  main.o

.PHONY: clean

$(TARGET) : $(OBJ_FILES)
	$(CXX) -o $(TARGET) $(OBJ_FILES) $(CXXFLAGS)

clean:
	rm -rf $(TARGET) $(OBJ_FILES)
