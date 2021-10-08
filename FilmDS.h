/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FilmDS.h
 * Author: twist
 *
 * Created on April 12, 2021, 3:30 PM
 */

#ifndef FILMDS_H
#define FILMDS_H
#include "BinarySearchTree.h"
#include "Film.h"

class FilmDS {
public:
    FilmDS();
    
    //methods
    
    /**
     * Adds a film object to the Binary Search Tree
     * @param aFilm Film object to add
     */
    void add(const Film& aFilm);
    
    /**
     * Displays the film in order by rank
     */
    void orderByRank() const;
    
    /**
     * Displays the film in order by title
     */
    void orderByTitle() const;
    
    /**
     * Searches for a title and display the title if found, else display
     * that the title was not found
     * @param title the title to find
     */
    void searchByTitle(std::string title) const;
    
    /**
     * Searches for a film that contains the keyword, if none of the films contain
     * that keyword displays that the keyword was not found
     * @param keyword keyword to search for
     */
    void searchByKeyword(std::string keyword) const;
    
    /**
     * Searches the films and prints the films that contain a specific studio, if no film is found
     * for that studio, a message is displayed
     * @param studio studio to search for
     */
    void searchByStudio(std::string studio) const;
    
    /**
     * Searches the films and prints the films that were released in a specific month
     * @param month month to search for
     */
    void searchByMonthOfRelease(std::string month) const;
    
    /*Static variable that will contain the rank that the BST needs to find*/
    static int searchRank;
    
    /*Static variable that will contain a specific string to search for (studio, title, etc)*/
    static std::string searchString;
    
    /*Static variable that will contain true if something was found, false otherwise*/
    static bool found;
private:
    /*BinarySearchTree that will contain all film objects*/
    BinarySearchTree<Film> filmBST;
    
};

#endif /* FILMDS_H */

