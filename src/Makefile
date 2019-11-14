TARGET=svm
CXX=clang++

OBJ_FILES=types/object.o \
		  arg.o machine.o opcode.o \
		  main.o

.PHONY: clean

$(TARGET) : $(OBJ_FILES)
	$(CXX) -o $(TARGET) $(OBJ_FILES)

clean:
	rm -rf $(TARGET) $(OBJ_FILES)
