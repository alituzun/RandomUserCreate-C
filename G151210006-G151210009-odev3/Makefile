hepsi: derle calistir

derle:
		gcc -I ./include/ -o ./lib/TelNo.o -c ./src/TelNo.c
		gcc -I ./include/ -o ./lib/ImeiNo.o -c ./src/ImeiNo.c
		gcc -I ./include/ -o ./lib/RandomKisi.o -c ./src/RandomKisi.c
		gcc -I ./include/ -o ./lib/TcNo.o -c ./src/TcNo.c
		gcc -I ./include/ -o ./lib/Kisi.o -c ./src/Kisi.c
		gcc -I ./include/ -o ./bin/Test ./lib/Kisi.o ./lib/TcNo.o ./lib/RandomKisi.o ./lib/TelNo.o ./lib/ImeiNo.o ./src/Test.c

calistir:
		./bin/Test
