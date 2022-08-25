#include "enemy.h"//player.h est inclut dans enemy.h

int main()
{
    sf::RenderWindow window(sf::VideoMode(windowW, windowH), "SFML works!");
    window.setFramerateLimit(60);
    sf::Event event;

    player Player;
    enemy Enemy;
    //game loop
    while (window.isOpen()){
        while (window.pollEvent(event)){
            switch(event.type){
                case sf::Event::Closed: window.close();
                case sf::Event::Resized: window.setSize(sf::Vector2u(windowW,windowH));
                                         window.setPosition(sf::Vector2i(200,0));
            default:continue;
            }
        }
        window.clear();
        //fonctions
        Player.gestiontVaisseau("Sprites\\vaisseaux1.png",window);//deux barres car '\' estune carastere speciale => echapement
        Player.gestiontDeTirs("Sprites\\balles1.png",window);

        Enemy.gestionEnemies("Sprites\\enemies.png",window);
        Enemy.gestionDeTirs();
        //affichage
        window.draw(Player.vaisseau1);
        window.display();
    }
    return 0;
}
