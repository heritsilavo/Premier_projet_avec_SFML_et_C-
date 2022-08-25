#include "player.h"

player::player()
{
    restartBallTimer=100;
    ballesSpeed=7;
}

void player::gestiontVaisseau(string filePathPlayer1,sf::RenderWindow &win){
    vaisseauTX1.loadFromFile(filePathPlayer1);
    vaisseau1.setTexture(vaisseauTX1);
    vaisseau1.setPosition(sf::Mouse::getPosition(win).x-vaisseauW/2,(windowH-vaisseauH));
    if(vaisseau1.getPosition().x<=0){
        vaisseau1.setPosition(0,vaisseau1.getPosition().y);
    }
    if(vaisseau1.getPosition().x>=(windowW-vaisseauW)){
        vaisseau1.setPosition((windowW-vaisseauW),vaisseau1.getPosition().y);
    }
}

void player::gestiontDeTirs(string filePathBalles1,sf::RenderWindow &win){
    balleTX1.loadFromFile(filePathBalles1);
    balle1.setTexture(balleTX1);
    balle1.setPosition(vaisseau1.getPosition().x+(vaisseauW/2.15),vaisseau1.getPosition().y);

    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        if(ballsClock.getElapsedTime().asMilliseconds()>=restartBallTimer){
            balles.push_back(balle1);
            ballsClock.restart();
        }
    }
    //moves
    for(size_t i(0);i<balles.size();i++){
        balles[i].move(0,-ballesSpeed);
    }
    //effacer ceux qui depassent la fenetre
    for(size_t i(0);i<balles.size();i++){
        if(balles[i].getPosition().y<=10){
            balles.erase(balles.begin()+i);
        }
    }
    //affichage
    for(size_t i(0);i<balles.size();i++){
        win.draw(balles[i]);
    }
}
