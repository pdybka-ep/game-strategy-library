CC=g++

all: library

library: Player.o Node.o Move.o Game.o GameState.o AbstractGameFactory.o InvalidMoveException.o GameNotStartedException.o NoMoveAvailableException.o GameStrategy.o

Player.o: Player.hpp Player.cpp

Node.o: Node.hpp Node.cpp

Move.o: Move.hpp Move.cpp

Game.o: Game.hpp Game.cpp

GameState.o: GameState.hpp GameState.cpp

AbstractGameFactory.o: AbstractGameFactory.hpp AbstractGameFactory.cpp

GameStrategy.o: GameStrategy.hpp GameStrategy.cpp

GameNotStartedException.o: GameNotStartedException.hpp GameNotStartedException.cpp 

InvalidMoveException.o: InvalidMoveException.hpp InvalidMoveException.cpp

NoMoveAvailableException.o: NoMoveAvailableException.hpp NoMoveAvailableException.cpp

clean:
	rm *.o