#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include <fstream>
#include "Player.hpp"
#include "Bomberman.hpp"
#include "boost/archive/text_oarchive.hpp"
#include "boost/archive/text_iarchive.hpp"

class GameState {
    public:
        GameState();
        ~GameState();
        int readPlayerState();        
        int savePlayerState(Player p);
        void operator=(GameState *rhs);
        bool isEmpty(std::ifstream &ifs);

    private:
};

namespace boost
{
    namespace serialization
    {
        template <class archive>
        void serialize(archive &ar, Player &p, const unsigned int version)
        {
            GLuint x = p.getXPos();
            GLuint y = p.getYPos();

            ar << x;
            ar << y;
        }
    }
}

#endif