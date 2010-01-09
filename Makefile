CC=g++
LIB_OBJ=Player.o Node.o Move.o Game.o GameState.o AbstractGameFactory.o InvalidMoveException.o GameNotStartedException.o NoMoveAvailableException.o InvalidPlayerException.o UnknownGameException.o FileAccessException.o GameFactoryInitializationException.o GameStrategy.o
CPPFLAGS=-O3 -pedantic
AR=ar
LIBS=-lgame_strategy -L.



all: libgame_strategy.a

libgame_strategy.a: $(LIB_OBJ)
	$(AR) rv $@ $?

doc: $(LIB_OBJ)
	doxygen doxygen.conf


############### object files ###############

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

GameFactoryInitializationException.o: GameFactoryInitializationException.hpp GameFactoryInitializationException.cpp

FileAccessException.o: FileAccessException.hpp FileAccessException.cpp

GameStrategy.o: GameStrategy.hpp GameStrategy.cpp



############### tests ###############

run_test: basic_tests game_tree_tests game_strategy_tests
	./basic_tests ; ./game_tree_tests ; ./game_strategy_tests
	
	
basic_tests: libgame_strategy.a basic_tests.cpp
	$(CC) $(CPPFLAGS) -o basic_tests basic_tests.cpp $(LIBS)

game_tree_tests: libgame_strategy.a game_tree_tests.cpp
	$(CC) $(CPPFLAGS) -o game_tree_tests game_tree_tests.cpp $(LIBS)

game_strategy_tests: libgame_strategy.a game_strategy_tests.cpp
	$(CC) $(CPPFLAGS) -o game_strategy_tests game_strategy_tests.cpp $(LIBS)



############### clean ###############

clean:
	rm *.o libgame_strategy.a basic_tests game_tree_tests game_strategy_tests

