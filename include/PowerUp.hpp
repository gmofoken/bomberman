
#ifndef POWERUP_HPP
#define POWERUP_HPP

class PowerUp
{
    public:
        PowerUp();
        ~PowerUp();

        void    OneUp();
        void    Fire();
        void    FireDown();
        void    CollideOneUp(int var);
        void    CollideFire(int var);
        void    CollideFireDown(int var);
        void    RemoveObject();

    private:
};

#endif