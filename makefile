.DEFAULT_GOAL := all

#quando adicionar uma nova dependencia não esqueça de atualizar aqui!
OBJECTS=build/WordsList.o 

build/WordsList.o: src/WordsList.cpp include/WordsList.h 
	g++ -Iinclude src/WordsList.cpp -c -o build/WordsList.o

#para adicionar novas regras apenas siga o formato
#build/usuario.o: src/usuario.cpp include/usuario.h
#	g++ -Iinclude src/usuario.cpp -c

objects: $(OBJECTS)

Forca: objects src/Forca.cpp
	g++ -Wall -fsanitize=address -Iinclude $(OBJECTS) src/Forca.cpp -o build/Forca

clean:
	rm build/*.o build/Forca

all: Forca

run:
	./build/Forca
