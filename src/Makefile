TARGET=svm
CXX=clang++

OBJ_FILES=arg.o machine.o object.o svm.o \
		  main.o

.PHONY: clean

$(TARGET) : $(OBJ_FILES)
	$(CXX) -o $(TARGET) $(OBJ_FILES)

clean:
	rm -rf $(TARGET) $(OBJ_FILES)
