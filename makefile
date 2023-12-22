FLAGS = -g
CXX = g++
CXXFLAGS = -Wall -std=c++11 -g

SRCDIR = src
TESTDIR = classtests
BINDIR = bin
OBJDIR = obj

all: main bin/testRH bin/testAuto bin/testEstado bin/testVector bin/testOperacion bin/testHeap bin/testVectorString

main: obj/Car.o obj/Stack.o obj/Tablero.o obj/Operacion.o main.cpp obj/State.o obj/Heap.o obj/MyString.o
	g++ ${FLAGS} obj/Car.o obj/Stack.o obj/Tablero.o obj/Operacion.o obj/State.o obj/Heap.o obj/MyString.o main.cpp -o main 

bin/testHeap: obj/Car.o obj/Stack.o obj/State.o obj/Heap.o obj/Operacion.o obj/MyString.o testdir/testHeap.cpp
	g++ ${FLAGS} obj/Car.o obj/Stack.o obj/State.o obj/Heap.o obj/Operacion.o obj/MyString.o testdir/testHeap.cpp -o bin/testHeap

bin/testRH: obj/State.o obj/Car.o obj/Tablero.o obj/Stack.o obj/Heap.o obj/Operacion.o obj/MyString.o testdir/testRH.cpp
	g++ ${FLAGS} obj/State.o obj/Car.o obj/Tablero.o obj/Stack.o obj/Heap.o obj/Operacion.o obj/MyString.o testdir/testRH.cpp -o bin/testRH

bin/testOperacion: obj/State.o obj/Car.o obj/Tablero.o obj/Stack.o obj/Heap.o obj/Operacion.o obj/MyString.o testdir/testOperacion.cpp
	g++ ${FLAGS} obj/State.o obj/Car.o obj/Tablero.o obj/Stack.o obj/Heap.o obj/Operacion.o obj/MyString.o testdir/testOperacion.cpp -o bin/testOperacion

bin/testVector: obj/State.o obj/Car.o obj/Tablero.o obj/Stack.o obj/Heap.o obj/Operacion.o obj/MyString.o testdir/testVector.cpp
	g++ ${FLAGS} obj/State.o obj/Car.o obj/Tablero.o obj/Stack.o obj/Heap.o obj/Operacion.o obj/MyString.o testdir/testVector.cpp -o bin/testVector

bin/testAuto: obj/State.o obj/Car.o obj/Tablero.o obj/Stack.o obj/Heap.o obj/Operacion.o obj/MyString.o testdir/testAuto.cpp
	g++ ${FLAGS} obj/State.o obj/Car.o obj/Tablero.o obj/Stack.o obj/Heap.o obj/Operacion.o obj/MyString.o testdir/testAuto.cpp -o bin/testAuto

bin/testEstado: obj/State.o obj/Car.o obj/Tablero.o obj/Stack.o obj/Heap.o obj/Operacion.o obj/MyString.o testdir/testEstado.cpp
	g++ ${FLAGS} obj/State.o obj/Car.o obj/Tablero.o obj/Stack.o obj/Heap.o obj/Operacion.o obj/MyString.o testdir/testEstado.cpp -o bin/testEstado

bin/testVectorString: obj/State.o obj/Car.o obj/Tablero.o obj/Stack.o obj/Heap.o obj/Operacion.o obj/MyString.o testdir/testVectorString.cpp
	g++ ${FLAGS} obj/State.o obj/Car.o obj/Tablero.o obj/Stack.o obj/Heap.o obj/Operacion.o obj/MyString.o testdir/testVectorString.cpp -o bin/testVectorString


# Reglas para compilar los archivos objeto
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR)/%.o: $(TESTDIR)/%.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regla para crear el directorio obj
$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -rf obj/*.o main bin/testHeap bin/testRH bin/testAuto bin/testEstado bin/testVector bin/testOperacion bin/testVectorString

