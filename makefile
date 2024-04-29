Tum: derleme calistirma

derleme:
	gcc -I ./include/ -o ./lib/itki.o -c ./src/Bitki.c
	gcc -I ./include/ -o ./lib/Bocek.o -c ./src/Bocek.c
	gcc -I ./include/ -o ./lib/Pire.o -c ./src/Pire.c
	gcc -I ./include/ -o ./lib/Sinek.o -c ./src/Sinek.c
	gcc -I ./include/ -o ./lib/Habitat.o -c ./src/Habitat.c
	gcc -I ./include/ -o ./lib/Canli.o -c ./src/Canli.c
	gcc -I ./include/ -o ./bin/Test ./lib/itki.o ./lib/Bocek.o ./lib/Pire.o ./lib/Sinek.o ./lib/Habitat.o ./lib/Canli.o ./src/Test.c

calistirma:
	./bin/Test ./doc/Veri.txt