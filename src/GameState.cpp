#include "GameState.hpp"

GameState::GameState() {
}

GameState::~GameState() {
}

void GameState::operator=(GameState *rhs){
}

int GameState::savePlayerState(Player p)
{
    std::ofstream ofs("gamedata.txt");
    {
        boost::archive::text_oarchive oa(ofs);
        oa << p;
    }
    return (0);
}

int GameState::readPlayerState()
{
    Player p2;

    // std::ifstream ifs("gamedata.txt", std::ios::binary);
    // ifs.read((char *)&p2, sizeof(p2));
    // std::cout << "" << std::endl << std::endl;
    // std::cout << p2.getXPos() << std::endl;
    // ifs.close();
    return (0);
}