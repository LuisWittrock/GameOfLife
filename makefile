all:
	g++ -c src/main.cpp -I/include
	g++ main.o -o GameOfLife -L/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
	rm main.o