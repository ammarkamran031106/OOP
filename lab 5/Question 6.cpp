/*Write a program that uses composition to implement a game engine. A game engine is madeup of
several components. For example:
a) Graphics rendering engine
b) Input handler
c) Physics engine
You don’t have to write the logicforhow these individual components work.*/
#include <iostream>
#include <string>

using namespace std;


class GraphicsEngine {
public:
    void renderGraphics() {
        cout << "Rendering graphics..." << endl;
    }
};


class InputHandler {
public:
    void handleInput() {
        cout << "Handling input..." << endl;
    }
};

// Physics Engine Class
class PhysicsEngine {
public:
    void updatePhysics() {
        cout << "Updating physics..." << endl;
    }
};


class GameEngine {
private:
    GraphicsEngine graphics; 
    InputHandler input;       
    PhysicsEngine physics;    

public:
    
    void runGame() {
        cout << "Starting the game engine..." << endl;
        
        
        graphics.renderGraphics();
        input.handleInput();          
        physics.updatePhysics();      
        
        cout << "Game engine loop completed!" << endl;
    }
};

int main() {
    // Create a GameEngine object, which automatically includes the other components
    GameEngine gameEngine;

    // Run the game engine, which will use its components
    gameEngine.runGame();
    
    return 0;
}
