#include "enemy.h"
#define enemyW 200
#define enemyH 265

enemy::enemy()
{
    srand((unsigned int)time(0));
    enemyPushClockRestart = 1000;
    enemyIncrementeSpeed = 10000;
    enemyMoveSpeed = 7;
    //configuration des sprites
    for(size_t i(0);i<enemies.size();i++){
        enemies[i].vaisseau.setTexture(enemieTX);
        enemies[i].vaisseau.setTextureRect(sf::IntRect(enemyW,enemyH*i,enemyW,enemyH));
        enemies[i].vaisseau.scale(0.5,0.5);
        enemies[i].balle.setTexture(enemieTX);
        enemies[i].balle.setTextureRect(sf::IntRect(0,enemyH*i,enemyW,enemyH));
        enemies[i].balle.setPosition(enemies[i].vaisseau.getPosition().x,enemies[i].vaisseau.getPosition().y);
    }
}

void enemy::gestionEnemies(string filePathEnemy,sf::RenderWindow& win){
    //chargement des textures
    enemieTX.loadFromFile(filePathEnemy);

    if(enemyPushClock.getElapsedTime().asMilliseconds()>=enemyPushClockRestart){
        //push
        tabEnemies.push_back(enemies[rand()%12].vaisseau);
        //position aleatoire sur x
        int posX=rand()%windowW;
        posX = (posX<100)?100:posX;
        posX = (posX>(windowW-200))?(windowW-200):posX;
        tabEnemies[tabEnemies.size()-1].setPosition(posX,-265);
        cout<<posX<<endl;
        cout<<"tabEnemies.size(): "<<tabEnemies.size()<<endl<<endl;
        enemyPushClock.restart();
    }
    //enemyIncrementeSpeed
    if(clock.getElapsedTime().asMilliseconds()>=enemyIncrementeSpeed){
        enemyMoveSpeed++;
        clock.restart();
    }
    for(size_t i(0);i<tabEnemies.size();i++){
        //deplacement
        tabEnemies[i].move(0,enemyMoveSpeed);
        //affichage
        win.draw(tabEnemies[i]);
        //ceux qui depassent
        if(tabEnemies[i].getPosition().y>=windowH)tabEnemies.erase(tabEnemies.begin()+i);
    }
}

void enemy::gestionDeTirs(){

}
