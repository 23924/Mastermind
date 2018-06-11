#include "Code.hpp"
#include <iostream>
#include <stdlib.h>
#include <time.h>


void Code::printCode()
{
    std::cout << "The code is ";
    for( int i = 0; i < 4; i++ )
    {
        std::cout << code[i] << " ";
    }
    std::cout << std::endl;
}

void Code::printGuess()
{
    std::cout << "The code guess is ";
    for( int i = 0; i < 4; i++ )
    {
        std::cout << guess[i] << " ";
    }
    std::cout << std::endl;
}

void Code::generateCode()
{
    srand( static_cast<unsigned int>(time(NULL)) ); // initialise random seed
    for(int i = 0; i < 4; i++)
    {
        randomNumber = rand() % 6 + 1; // give the randomNumber variable a random number between 1 and 6
        code[i] = randomNumber;
    }
}

void Code::insertCode()
{
    for( int i = 0; i < 4; )
    {
        std::cout << "Enter code number " << i + 1 << std::endl;
        std::cin >> code[i];
        if( code[i] > 0 && code[i] < 7 )
        {
            i++;
        }
        else
        {
            std::cout << "input invalid, try again" << std::endl;
        }
    }
}

void Code::insertGuess()
{
    for( int i = 0; i < 4; )
    {
        std::cout << "Enter code number " << i + 1 << std::endl;
        std::cin >> guess[i];
        if( guess[i] > 0 && guess[i] < 7 )
        {
            i++;
        }
        else
        {
            std::cout << "input invalid, try again" << std::endl;
        }
    }
}

int Code::checkGuess()
{
    int goodGuesses = 0;
    
    for(int i = 0; i < 4; i++)
    {
        if ( code[i] == guess[i] )
        {
            goodGuesses++;
        }
    }
    
    return goodGuesses;
}
