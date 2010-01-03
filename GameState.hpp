/*
 * GameState.hpp
 * Author: Michal Kolodziejski
 */

#ifndef GAMESTATE_H_
#define GAMESTATE_H_

#include <list>
#include <boost/shared_ptr.hpp>
#include "Game.hpp"
#include "Player.hpp"
#include "Node.hpp"

namespace library {

	class GameState {
	public:
		GameState();
		GameState(const GameState &);
		virtual ~GameState();

		GameState& operator= (const GameState&);

	protected:
		Game game_;
		std::list<Player> players_;
		boost::shared_ptr<Node> actualNode_;
		int nextPlayerIndex_;
	};

}

#endif /* GAMESTATE_H_ */
