/*
 * GameStrategy.hpp
 * Author: Michal Kolodziejski
 */

#ifndef GAMESTRATEGY_HPP_
#define GAMESTRATEGY_HPP_

#include <list>
#include <boost/shared_ptr.hpp>
#include "GameState.hpp"
#include "AbstractGameFactory.hpp"
#include "GameNotStartedException.hpp"
#include "InvalidMoveException.hpp"
#include "NoMoveAvailableException.hpp"
#include "InvalidPlayerException.hpp"
#include "UnknownGameException.hpp"
#include "FileAccessException.hpp"
#include "GameFactoryInitializationException.hpp"

namespace library {

    /**
     * Class representing strategy of the game. It is able to "learn" good and bad moves of the game
     * in order to give hints (suggestions) about next move. It's designed for games with small game
     * tree as it holds entire game tree in the memory.
     * @author Michał Kołodziejski
     */
    class GameStrategy {
    public:
        /**
         * Creates a game strategy
         */
        GameStrategy();

        /**
         * Copies a game strategy
         * @param gameStrategy a game strategy to be copied
         */
        GameStrategy(const GameStrategy& gameStrategy);

        /**
         * Destroys the game strategy
         */
        virtual ~GameStrategy();

        GameStrategy& operator= (const GameStrategy&);



        /* library functions */

        /**
         * Initializes library with game factory. It's required to load/save the game.
         * @param gameFactory a game factory
         */
        void initialize(const boost::shared_ptr<AbstractGameFactory>& gameFactory);

        /**
         * Starts the game with two players.
         * @param game a game to be started
         * @param player1 a first player
         * @param player2 a second player
         */
        void startGame(const boost::shared_ptr<Game>& game, const boost::shared_ptr<Player>& player1, const boost::shared_ptr<Player>& player2);

        /**
         * Starts the game once again.
         * @throw UnknownGameException thrown if no game was started before
         */
        void startGame() throw(UnknownGameException);

        /**
         * Finds the best next move. <br/>
         * <i>NOTE:</i> if the game strategy hasn't learnt much yet, it may return not the best move
         * as it hasn't got enough amount of knowledge. After having passed all available tree routes it assures to return
         * the best available move.
         * @return the best available move
         * @throw GameNotStartedException thrown if game hasn't been started
         * @throw NoMoveAvailableException thrown if there is no move available from the current node
         */
        boost::shared_ptr<Move> findBestMove() throw(GameNotStartedException, NoMoveAvailableException);

        /**
         * Performs move in the game.
         * @param move a move to be performed
         * @throw GameNotStartedException thrown if game hasn't been started
         * @throw InvalidMoveException thrown if the given move is not available from the current node
         */
        void move(const boost::shared_ptr<Move>& move) throw(GameNotStartedException, InvalidMoveException);

        /**
         * Ends the game. Updates game tree with the knowledge about the finished game.
         * @param winner a winner of the game
         * @throw GameNotStartedException thrown if game hasn't been started
         */
        void endOfGame(const boost::shared_ptr<Player>& winner) throw(GameNotStartedException);

        /**
         * Ends the game. Updates game tree with the knowledge about the finished game.
         * @throw GameNotStartedException thrown if game hasn't been started
         */
        void endOfGame() throw(GameNotStartedException);

        /**
         * Saves the game to the given file. It uses game factory, so initialize() method must be called before this method.
         * @param filePath a path to the file in which the game is to be saved
         * @throw FileAccessException thrown if a problem with access to the file occurs
         * @throw GameFactoryInitializationException thrown if initialize() method hasn't been called before
         */
        void saveGame(const std::string& filePath) throw(FileAccessException, GameFactoryInitializationException);

        /**
         * Loads the game from the given file. It uses game factory, so initialize() method must be called before this method.
         * @param filePath a path to the file from which the game is to be loaded
         * @throw FileAccessException thrown if a problem with access to the file occurs
         * @throw GameFactoryInitializationException thrown if initialize() method hasn't been called before
         */
        void loadGame(const std::string& filePath) throw(FileAccessException, GameFactoryInitializationException);

        /**
         * Returns current game
         * @return current game
         */
        boost::shared_ptr<Game> getCurrentGame() const {
            return this->gameState_.getGame();
        }

        /**
         * Returns currently available moves
         * @return currently available moves
         * @throw GameNotStartedException thrown if game hasn't been started
         */
        std::list<boost::shared_ptr<Move> > getAvailableMoves() const throw (GameNotStartedException){
            if(gameState_.getCurrentNode().get() == 0)
                throw GameNotStartedException();
            return gameState_.getCurrentNode()->getAvailableMoves();
        }

    private:
        /* private helper methods */
        bool updateNodeValue(boost::shared_ptr<Node> node, bool maximizingNode);
        void updateDownTheTree(boost::shared_ptr<Node> node, int value);

    private:
        /**
         * Game factory
         */
        boost::shared_ptr<AbstractGameFactory> gameFactory_;

        /**
         * State of the game
         */
        GameState gameState_;

        /**
         * Flag saying if game state has already been initialized
         */
        bool gameStateInitialized_;
    };

}

#endif /* GAMESTRATEGY_HPP_ */
