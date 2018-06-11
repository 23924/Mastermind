#pragma once

class Code
{
public:
// variables
    int randomNumber;
private:
    int code[4]; // array containing the code numbers
    int guess[4]; // array containing the guesses of the code
public:
// functions
    void printCode();
    void generateCode();
    void insertCode();
    
    void insertGuess();
    void printGuess();
    
    int checkGuess();
};

