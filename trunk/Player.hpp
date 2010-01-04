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

    class Player {
    public:
        Player();
        Player(const Player&);
        virtual ~Player();

        Player& operator=(const Player&);
        friend bool operator==(const Player&, const Player&);
        friend bool operator!=(const Player&, const Player&);

        /**
         * Returns player's name
         */
        std::string getName() const {
            return name_;
        }

        /**
         * Returns information if player is starting player
         */
        bool isStartingPlayer() const {
            return startingPlayer_;
        }

        /**
         * Sets player's name
         */
        void setName(std::string name) {
            this->name_ = name;
        }

        /**
         * Sets starting flag
         */
        void setStartingPlayer(bool startingPlayer) {
            this->startingPlayer_ = startingPlayer;
        }

    private:
        std::string name_;
        bool startingPlayer_;
    };

}

#endif /* PLAYER_H_ */
