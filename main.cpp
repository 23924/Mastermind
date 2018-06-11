#include "Code.hpp"
#include "StateMachine.hpp"
#include "ObjectDeclerations.hpp"
#include "GlobalVariables.hpp"

int main()
{
    
    GameState = GameStates::INTRO; // make the GameState intro so the program starts with intro
    
    game = true;
    
    while( game )
    {
    
        switch( GameState ) // handle the different game states
        {
            case GameStates::INTRO:
                Statemachine.processIntro();
                break;
            case GameStates::MAIN_MENU:
                Statemachine.processMainMenu();
                break;
            case GameStates::PLAYING:
//                myCode.printCode(); // for testing, remove later
                Statemachine.processPlaying();
                break;
            case GameStates::CODECRACKED:
                Statemachine.proccesCodeCracked();
                break;
            case GameStates::EXIT:
                Statemachine.processExit();
                break;
        }
    }
}
