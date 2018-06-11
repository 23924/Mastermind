#pragma once

enum class GameStates {INTRO, MAIN_MENU, PLAYING, CODECRACKED, EXIT}; // Create enum with gamestates

class Statemachine
{
public:
// Viarable declerations
    int mainMenuChoice;
    int endGameChoice;
    bool endGameChoiceValid;
    int attempt;
    bool mainMenu;
    bool playing;



// Function declerations
    void processIntro();
    void processMainMenu();
    void processPlaying();
    void processExit();
    void proccesCodeCracked();
};


