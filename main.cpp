/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * @file:   main.cpp
 * @author: Josue M.
 *
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include "MainMenu.h"
#include "Film.h"
#include "FilmDS.h"

using namespace std;

/**
 * Creates a menu object that displays the options to the user and
 * returns the users choice. Based of their choice, it will go into an if statement
 * and perform the action the user requested. If a choice requires a submenu, the submenu method
 * of the Menu object will be called and will show the user more options in that submenu and will return the 
 * choice of the user. Continues until the user exits the menu
 * @param filmData Data Store that will be used to perform the operations
 */
void runMainMenu(FilmDS& filmData);

/**
 * Reads the file "Films2017.csv" creates a film object and adds it
 * to filmData
 * @param filmData Film Data Store stores the film objects
 */
void readFile(FilmDS& filmData);

int main() {
    FilmDS filmData;
    
 
    //read data
    readFile(filmData);
    
    //open menu
    runMainMenu(filmData);
    
    return 0;
}

void readFile(FilmDS& filmData){
    ifstream inFS;
    string filename = "Films2017.csv";
    string input = "";
    
    inFS.open(filename);
    
    if(!inFS.is_open()){
        cout << "Error opening file. Program terminating.";
        exit(1);
    }
    
    getline(inFS, input);
    while(!inFS.eof()){
        Film aFilm(input);
        filmData.add(aFilm);
        getline(inFS, input);
        //cout << aFilm;
    }    
}

void runMainMenu(FilmDS& filmData){
    MainMenu menu;
    
    string userChoice = ""; //where the users choice for most responses will go
    string searchInput = ""; //where the users search inquiry is stored
    int month = 0; // holds the int value the user entered
    string months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    
    //call the menu for the first time
    userChoice = menu.runMainMenu();
    cin.ignore(); //get rid of the enter key from input stream, will be seen again
    
    while(tolower(userChoice[0]) != 'x'){
        if(userChoice == "A" or userChoice == "a"){ // about option
            cout << endl;
            cout << "===========================================================" << endl;
            cout << "This film application houses the top 100 films of 2017" << endl;
            cout << "You will be able to order the films by title, or by rank. " << endl;
            cout << "You will also be able to search through the films and find a movie by: \nTitle, " <<
                    "Keyword, Studio, and Month of Release." << endl;
            cout << "Thank you for using this application!" << endl;
            cout << "===========================================================" << endl;
            
        }else if(userChoice == "R" or userChoice == "r"){ //Report sub menu 
            
            userChoice = menu.reportSubMenu();
            cin.ignore();
            
            while(tolower(userChoice[0]) != 'x'){
                if(userChoice == "T" or userChoice == "t"){ //Display by title
                    filmData.orderByTitle();
                }else if(userChoice == "R" or userChoice == "r"){ //display by rank
                    filmData.orderByRank();
                }else{
                    cout << "---ERROR: Please enter a valid choice---" << endl;
                }
                userChoice = menu.reportSubMenu();
                cin.ignore();
                
            }//end inner while
            
        }else if(userChoice == "S" or userChoice == "s"){ //Search database sub menu
            
            userChoice = menu.databaseSubMenu();
            cin.ignore();
            
            while(tolower(userChoice[0]) != 'x'){
                if(userChoice == "T" or userChoice == "t"){ //Search by title
                    cout << "Enter a title: ";
                    getline(cin, searchInput);
                    filmData.searchByTitle(searchInput);
                    
                }else if(userChoice == "K" or userChoice == "k"){ //Search by keyword
                    cout << "Enter keywords (if more than one, comma separate. Ex: key,word,search): ";
                    getline(cin, searchInput);
                    
                    stringstream keywords(searchInput);

                    while(getline(keywords, searchInput, ',')){
                        filmData.searchByKeyword(searchInput);
                    }
                    
                    
                }else if(userChoice == "S" or userChoice == "s"){ //Search by studio
                    cout << "Enter a studio: ";
                    getline(cin, searchInput);
                    filmData.searchByStudio(searchInput);
                    
                }else if(userChoice == "M" or userChoice == "m"){ //search by month 
                    
                    cout << "1. Jan, 2. Feb, 3. Mar, 4. Apr, 5. May, 6. Jun, "
                            << "7. Jul, 8. Aug, 9. Sep, 10. Oct, 11. Nov, 12. Dec" << endl;
                    cout << "Enter a month: ";
                    cin >> month;
                    
                    while(month < 1 or month > 12){
                        cout << "Error: Please enter a number between 1 and 12: ";
                        cin >> month;
                    }
                    
                    searchInput = months[month-1];
                    
                    
                    filmData.searchByMonthOfRelease(searchInput);
                    
                }else{
                    cout << "---ERROR: Please enter a valid choice---" << endl;
                }//end if 
                
                userChoice = menu.databaseSubMenu();
                cin.ignore();
                
            }//end inner while
        }else{
            cout << "---ERROR: Please enter a valid choice---" << endl;
        }//end outer if
      
        userChoice = menu.runMainMenu();
        cin.ignore();
       
    }//end outer while
    
}

/*
     //Testing Film Class
    string pracFilm = "1,Star Wars: The Last Jedi,BV,596006158,4232,220009584,4232,15-Dec";
    Film testFilm(pracFilm);
    cout << testFilm;
    
    string pracFilm2 = "2,Beauty and the Beast (2017),BV,504014165,4210,174750616,4210,17-Mar";
    Film testFilm2(pracFilm2);
    cout << testFilm2;
    
    if(testFilm > testFilm2){
        cout << testFilm.getTitle() << " is greater than " << testFilm2.getTitle() << endl;
    }
    if(testFilm2 < testFilm){
        cout << testFilm2.getTitle() << " is less than " << testFilm.getTitle() << endl;
    }
    
    Film testFilmCopy(testFilm2);
    
    if(testFilm2 == testFilmCopy){
        cout << "Films are the same" << endl;
    }
 
 */



