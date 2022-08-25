#ifndef ENEMY_H
#define ENEMY_H

#include "player.h"
#include <array>
#include <ctime>

class enemy
{
    public:
        //condtructeurs
        enemy();

        //variable
        sf::Texture enemieTX;
        struct Enem{
            sf::Sprite vaisseau;
            sf::Sprite balle;
        };
        array<Enem, 12> enemies;
        vector<sf::Sprite> tabEnemies;
        sf::Clock enemyPushClock;
        sf::Clock clock;
        int enemyIncrementeSpeed;
        int enemyPushClockRestart;
        int enemyMoveSpeed;

        //methodes
        void gestionEnemies(string filePathEnemy,sf::RenderWindow& win);
        void gestionDeTirs();
    protected:

    private:
};

#endif // ENEMY_H
