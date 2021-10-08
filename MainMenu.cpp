/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MainMenu.cpp
 * Author: twist
 * 
 * Created on April 8, 2021, 3:53 PM
 */

#include "MainMenu.h"
#include <iostream>
#include <iomanip>

using namespace std;

string MainMenu::runMainMenu(){
    string choice;
    
    cout << setw(20) << "MAIN MENU " << endl;
    cout << "A - About the Application" << endl;
    cout << "R - Reports" << endl;
    cout << "S - Search the Database" << endl;
    cout << "X - Exit the Program" << endl;
    
    cout << "Enter Selection -> ";
    cin >> choice;
    
    return choice;
}

string MainMenu::reportSubMenu(){
    string choice;
    
    cout << setw(20) << "REPORTS MENU" << endl;
    cout << "T - Order by Film Title Report" << endl;
    cout << "R - Order by Rank report" << endl;
    cout << "X - Return to Main Menu" << endl;
    
    cout << "Enter Selection -> ";
    cin >> choice;
    
    return choice;
}

string MainMenu::databaseSubMenu(){
    string choice;
    
    cout << setw(20) << "SEARCH MENU" << endl;
    cout << "T - Search by Title" << endl;
    cout << "K - Search by Keyword" << endl;
    cout << "S - Search by Studio" << endl;
    cout << "M - Search by Month of Release" << endl;
    cout << "X - Return to Main Menu" << endl;
    
    cout << "Enter Selection -> ";
    cin >> choice;
    
    return choice;
}

