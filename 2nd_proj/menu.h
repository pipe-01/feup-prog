#include "constants.h"
#include <iostream>
#include <fstream>
#include <limits>

using namespace std;

class Menu
{
private:
    bool menu;
    bool rules;
    bool play;
    bool winners;
    bool leave;
    std::string mazeFile;
    std::string winnersFile;
public:
    Menu(bool rule, bool playgame, bool win, bool exits)
    {
        menu = true;
        rules = rule;
        play = playgame;
        winners = win;
        leave = exits;
    }
    /**
     * @brief Prints beggining banner
     * 
     */
    void printMenuBanner();
    /**
     * @brief waits till user presses enter button
     * 
     */
    void wait();
    /**
     * @brief prints when player exist the game
     * 
     */
    void printExit();
    /**
     * @brief prints when invalid input
     * 
     */
    void printInvalidChar();
    /**
     * @brief prints if robots win
     * 
     */
    void printRobotVictory();
    /**
     * @brief prints if player wins
     * 
     */
    void printHumanVictory();
    /**
     * @brief draws menu and returns input
     * 
     */
    void draw_menu();
    /**
     * @brief prints when games begin
     * 
     */
    void printBeginGame();
    /**
     * @brief prints fileName
     * 
     * @param fileName 
     */
    void printFile(string fileName);
    /**
     * @brief Checks if buffer is clean
     * 
     * @return true 
     * @return false 
     */
    bool checkBuffer();
    /**
     * @brief Set the Rules object
     * 
     * @param sentence 
     */
    void setRules(bool sentence);
    /**
     * @brief Set the Play object
     * 
     * @param sentence 
     */
    void setPlay(bool sentence);
    /**
     * @brief Set the Exit object
     * 
     * @param sentence 
     */
    void setExit(bool sentence);
    /**
     * @brief Set the Winners object
     * 
     * @param sentence 
     */
    void setWinners(bool sentence);
    /**
     * @brief Get the State object
     * 
     * @return true 
     * @return false 
     */
    bool getState();
    /**
     * @brief Get the Rules object
     * 
     * @return true 
     * @return false 
     */
    bool getRules();
    /**
     * @brief Get the Play object
     * 
     * @return true 
     * @return false 
     */
    bool getPlay();
    /**
     * @brief Get the Winners object
     * 
     * @return true 
     * @return false 
     */
    bool getWinners();
    /**
     * @brief checks if file exists
     * 
     * @param f 
     * @return true 
     * @return false 
     */
    bool fileExists(const std::string &f);
    /**
     * @brief Get the Exit object
     * 
     * @return true 
     * @return false 
     */
    bool getExit();
    /**
     * @brief Set the State object
     * 
     * @param sentence 
     */
    void setState(bool sentence);
    /**
     * @brief Gets input from user and checks if such file exists
     * 
     * @return true 
     * @return false 
     */
    bool readGame();
    /**
     * @brief prints when showing winners
     * 
     */
    void printWinnersBanner();
    /**
     * @brief Get the Maze File object
     * 
     * @return std::string 
     */
    std::string getMazeFile();
    /**
     * @brief Get the Winners File object
     * 
     * @return std::string 
     */
    std::string getWinnersFile();

};