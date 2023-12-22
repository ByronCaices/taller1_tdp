FLAGS = -g
CXX = g++
CXXFLAGS = -Wall -std=c++11 -g

SRCDIR = src
TESTDIR = classtests
BINDIR = bin
OBJDIR = obj

all: main bin/testCar bin/testState bin/testStack bin/testOperation bin/testHeap bin/testMyString

main: obj/Car.o obj/Stack.o obj/Board.o obj/Operation.o src/main.cpp obj/State.o obj/Heap.o obj/MyString.o
	g++ ${FLAGS} obj/Car.o obj/Stack.o obj/Board.o obj/Operation.o obj/State.o obj/Heap.o obj/MyString.o src/main.cpp -o main 

bin/testHeap: obj/Car.o obj/Stack.o obj/State.o obj/Heap.o obj/Operation.o obj/MyString.o classtests/testHeap.cpp
	g++ ${FLAGS} obj/Car.o obj/Stack.o obj/State.o obj/Heap.o obj/Operation.o obj/MyString.o classtests/testHeap.cpp -o bin/testHeap

bin/testOperation: obj/State.o obj/Car.o obj/Board.o obj/Stack.o obj/Heap.o obj/Operation.o obj/MyString.o classtests/testOperation.cpp
	g++ ${FLAGS} obj/State.o obj/Car.o obj/Board.o obj/Stack.o obj/Heap.o obj/Operation.o obj/MyString.o classtests/testOperation.cpp -o bin/testOperation

bin/testStack: obj/State.o obj/Car.o obj/Board.o obj/Stack.o obj/Heap.o obj/Operation.o obj/MyString.o classtests/testStack.cpp
	g++ ${FLAGS} obj/State.o obj/Car.o obj/Board.o obj/Stack.o obj/Heap.o obj/Operation.o obj/MyString.o classtests/testStack.cpp -o bin/testStack

bin/testCar: obj/State.o obj/Car.o obj/Board.o obj/Stack.o obj/Heap.o obj/Operation.o obj/MyString.o classtests/testCar.cpp
	g++ ${FLAGS} obj/State.o obj/Car.o obj/Board.o obj/Stack.o obj/Heap.o obj/Operation.o obj/MyString.o classtests/testCar.cpp -o bin/testCar

bin/testState: obj/State.o obj/Car.o obj/Board.o obj/Stack.o obj/Heap.o obj/Operation.o obj/MyString.o classtests/testState.cpp
	g++ ${FLAGS} obj/State.o obj/Car.o obj/Board.o obj/Stack.o obj/Heap.o obj/Operation.o obj/MyString.o classtests/testState.cpp -o bin/testState

bin/testMyString: obj/State.o obj/Car.o obj/Board.o obj/Stack.o obj/Heap.o obj/Operation.o obj/MyString.o classtests/testMyString.cpp
	g++ ${FLAGS} obj/State.o obj/Car.o obj/Board.o obj/Stack.o obj/Heap.o obj/Operation.o obj/MyString.o classtests/testMyString.cpp -o bin/testMyString


# Reglas para compilar los archivos objeto
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR)/%.o: $(TESTDIR)/%.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regla para crear el directorio obj
$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -rf obj/*.o main bin/testHeap bin/testCar bin/testState bin/testStack bin/testOperation bin/testMyString

