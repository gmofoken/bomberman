#include "PowerUp.hpp"

PowerUp::PowerUp(){

}

PowerUp::~PowerUp(){

}

void PowerUp::Fire(){
    
}

void PowerUp::CollideFire(int var){
    if (var == 1){
        //Bomb::Radius(1);
        //remove object
    }
    PowerUp::~PowerUp();       
}

void PowerUp::FireDown(){

}

void PowerUp::CollideFireDown(int var){
    if (var == 1){
        //Bomb::Radius(-1);
        //remove object
    }
    PowerUp::~PowerUp();  
}

void PowerUp::OneUp(){
    
}

void PowerUp::CollideOneUp(int var){
    if (var == 1){
        //Life::Life(1);
        //remove object
    }
    PowerUp::~PowerUp();  
}

void PowerUp::RemoveObject(){
    
}