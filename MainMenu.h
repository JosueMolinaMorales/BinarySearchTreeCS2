/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MainMenu.h
 * Author: Josue M
 *
 * Created on April 8, 2021, 3:53 PM
 */

#ifndef MAINMENU_H
#define MAINMENU_H
#include <iostream>

class MainMenu {
public:
    /**
     * Runs the main menu, asks the user to enter a choice
     * @return the choice the user entered
     */
    std::string runMainMenu();
    
    /**
     * Runs the Report sub menu, asks the user to enter a choice
     * @return the choice the user entered
     */
    std::string reportSubMenu();
    
    /**
     * Runs the Database sub menu, asks the user to enter a choice
     * @return returns the choice of the user
     */
    std::string databaseSubMenu();
};

#endif /* MAINMENU_H */

