#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

#define windowW 1100
#define windowH 778
#define vaisseauW 178
#define vaisseauH 258

using namespace std;

class player
{
    public:
        //costructeur
        player();
        //proprietes
        sf::Texture vaisseauTX1;
        sf::Sprite vaisseau1;
        sf::Texture balleTX1;
        sf::Sprite balle1;
        sf::Clock ballsClock;
        int restartBallTimer;
        int ballesSpeed;
        vector<sf::Sprite> balles;

        //les methodes
        void gestiontVaisseau(string filePathPlayer1,sf::RenderWindow &win);
        void gestiontDeTirs(string filePathBalles1,sf::RenderWindow &win);
    protected:

    private:
};

#endif // PLAYER_H
