#include <iostream>
#include "StateMachine.hpp"
#include "Code.hpp"
#include "ObjectDeclerations.hpp"
#include "GlobalVariables.hpp"

// intro
void Statemachine::processIntro()
{
    std::cout << "Welcome to Mastermind!" << std::endl;
    std::cout << "The point in this game is to guess the code, containing 4 numbers of 1 to 6." << std::endl;
    std::cout << "After every guess you will be told how many numbers were correct" << std::endl;
    std::cout << "" << std::endl;
    GameState = GameStates::MAIN_MENU;
}

// main menu
void Statemachine::processMainMenu()
{
    std::cout << "MAIN MENU:" << std::endl;
    mainMenu = true; // set mainMenu to true to enter the main menu loop
    
    while( mainMenu ) // enter main menu loop
    {
        std::cout << "Enter 1 to generate a random code" << std::endl;
        std::cout << "Enter 2 to put in a code yourself" << std::endl;
        std::cin >> mainMenuChoice;
        
        switch( mainMenuChoice )
        {
            case 1:
                myCode.generateCode();
                std::cout << "Code set" << std::endl;
                mainMenu = false;
                break;
                
            case 2:
                // insert a code
                myCode.insertCode();
                std::cout << "Code set" << std::endl;
                mainMenu = false;
                break;
                
            default:
                std::cout << "Choice invalid, try again" << std::endl;
                break;
        }
    }
    GameState = GameStates::PLAYING;
}

// playing
void Statemachine::processPlaying()
{
    std::cout << "Good luck cracking the code!" << std::endl << std::endl;
    attempt = 1;
    playing = true; // set playing to true to enter the playing loop
    while( playing )
    {
        std::cout << std::endl;
        std::cout << "Starting attempt number " << attempt << ":" << std::endl;
        myCode.insertGuess();
        myCode.printGuess();
        std::cout << "You had " << myCode.checkGuess() << " correct number(s)" << std::endl; // print how many numbers were guessed correct
        if( myCode.checkGuess() == 4 )
        {
            playing = false;
        }
        attempt++;
    }
    GameState = GameStates::CODECRACKED;

}

// code cracked
void Statemachine::proccesCodeCracked()
{
    std::cout << "Congratulations, you cracked the code!" << std::endl;
    std::cout << "This took you " << attempt << " attempts" << std::endl;
    std::cout << "" << std::endl;
    endGameChoiceValid = false;
    while( !endGameChoiceValid )
    {
        std::cout << "Enter 1 to play again" << std::endl;
        std::cout << "Enter 2 to exit the game" << std::endl;
        std::cin >> endGameChoice;
        switch( endGameChoice )
        {
            case 1:
                GameState = GameStates::MAIN_MENU;
                std::cout << "" << std::endl; // seperate the input from the endGameChoice and the main menu message with a blank line
                endGameChoiceValid = true;
                break;
            case 2:
                GameState = GameStates::EXIT;
                endGameChoiceValid = true;
                break;
            default:
                std::cout << "Input invalid, try again" << std::endl;
        }
    }
}


// exit
void Statemachine::processExit()
{
    std::cout << "" << std::endl;
    std::cout << "EXITING GAME" << std::endl;
    std::cout << "" << std::endl;
    game = false;
}
