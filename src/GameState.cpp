#include "GameState.hpp"

GameState::GameState() {
}

GameState::~GameState() {
}

void GameState::operator=(GameState *rhs){
}

int GameState::savePlayerState(Player &p)
{
    std::ofstream ofs("gamedata.dat");
    if (ofs.is_open())
    {
        {
            boost::archive::text_oarchive oa(ofs);
            oa << p;
        }
    }
    return (0);
}

int GameState::readPlayerState()
{
    Player p2;

    std::ifstream ifs("gamedata.dat");
    if (ifs.is_open())
    {
        {
            boost::archive::text_iarchive ia(ifs);
            ia >> p2;
        }
    }
    std::cout << "p2.xPos: " << p2.getXPos() << std::endl;
    return (0);
}