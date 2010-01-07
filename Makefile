CC=g++
LIB_OBJ=Player.o Node.o Move.o Game.o GameState.o AbstractGameFactory.o InvalidMoveException.o GameNotStartedException.o NoMoveAvailableException.o InvalidPlayerException.o UnknownGameException.o GameStrategy.o
CPPFLAGS=-O3 -pedantic

all: library

library: $(LIB_OBJ)

Player.o: Player.hpp Player.cpp

Node.o: Node.hpp Node.cpp

Move.o: Move.hpp Move.cpp

Game.o: Game.hpp Game.cpp

GameState.o: GameState.hpp GameState.cpp

AbstractGameFactory.o: AbstractGameFactory.hpp AbstractGameFactory.cpp

InvalidMoveException.o: InvalidMoveException.hpp InvalidMoveException.cpp

GameNotStartedException.o: GameNotStartedException.hpp GameNotStartedException.cpp 

NoMoveAvailableException.o: NoMoveAvailableException.hpp NoMoveAvailableException.cpp

InvalidPlayerException.o: InvalidPlayerException.hpp InvalidPlayerException.cpp

UnknownGameException.o: UnknownGameException.hpp UnknownGameException.cpp

GameStrategy.o: GameStrategy.hpp GameStrategy.cpp

basic_tests: $(LIB_OBJ) basic_tests.cpp
	$(CC) $(CPPFLAGS) -o basic_tests basic_tests.cpp $(LIB_OBJ)

game_tree_tests: $(LIB_OBJ) game_tree_tests.cpp
	$(CC) $(CPPFLAGS) -o game_tree_tests game_tree_tests.cpp $(LIB_OBJ)

game_strategy_tests: $(LIB_OBJ) game_strategy_tests.cpp
	$(CC) $(CPPFLAGS) -o game_strategy_tests game_strategy_tests.cpp $(LIB_OBJ)


run_test: basic_tests game_tree_tests game_strategy_tests
	./basic_tests ; ./game_tree_tests ; ./game_strategy_tests


clean:
	rm *.o basic_tests game_tree_tests game_strategy_tests

