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
        int savePlayerState(Player &p);
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
            ar & p.xPos;
            ar & p.yPos;
            // ar & p.pVAO;
            // ar & p.pVBO;
            // ar & p.pEBO;
            // ar & p.programID;
            // ar & p.pTextureId;
        }
    }
}

#endif