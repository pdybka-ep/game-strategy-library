/*
 * Player.hpp
 * Author: Michal Kolodziejski
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include <string>

namespace library {

    class Player;
    bool operator==(const Player&, const Player&);
    bool operator!=(const Player&, const Player&);

    /**
     * Class representing a single player
     * @author Michał Kołodziejski
     */
    class Player {
    public:
        /**
         * Creates a player
         */
        Player();

        /**
         * Creates a player as a copy of an argument
         * @param player a player to be copied
         */
        Player(const Player& player);

        /**
         * Destroys the player
         */
        virtual ~Player();

        Player& operator=(const Player&);
        friend bool operator==(const Player&, const Player&);
        friend bool operator!=(const Player&, const Player&);

        /**
         * Returns player's name
         * @return player's name
         */
        std::string getName() const {
            return name_;
        }

        /**
         * Returns information if player is starting player
         * @return <code>true</code> if player is starting player, <code>false</code> otherwise
         */
        bool isStartingPlayer() const {
            return startingPlayer_;
        }

        /**
         * Sets player's name
         * @param name a name to be set
         */
        void setName(const std::string& name) {
            this->name_ = name;
        }

        /**
         * Sets starting flag
         * @param startingPlayer a flag to be set
         */
        void setStartingPlayer(bool startingPlayer) {
            this->startingPlayer_ = startingPlayer;
        }

    protected:
        /**
         * Player's name
         */
        std::string name_;

        /**
         * Flag if player is starting player
         */
        bool startingPlayer_;
    };

}

#endif /* PLAYER_H_ */
