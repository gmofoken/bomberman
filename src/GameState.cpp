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

int GameState::readPlayerState(Player *p)
{
    Player p2;

    std::ifstream ifs("gamedata.dat");
    if (ifs.is_open())
    {
        {
            boost::archive::text_iarchive ia(ifs);
            ia >> p2;
        }
        (*p) = p2;
    }
    std::cout << "" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "**************************************" << std::endl;
    std::cout << "************* Debugging **************" << std::endl;
    std::cout << "p.xPos: " << p->getXPos() << std::endl;
    std::cout << "*************************************" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "" << std::endl;
    return (0);
}