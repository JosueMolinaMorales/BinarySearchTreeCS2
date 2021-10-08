/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Film.h
 * Author: Josue M.
 *
 * Created on April 5, 2021, 7:18 PM
 */

#ifndef FILM_H
#define FILM_H

#include <ostream>


class Film {
public:
    Film();
    
    /**
     * Constructor for the Film class. Parses a string and creates and object
     * @param input string containing all information for a film object
     */
    Film(const std::string input);
    
    /**
     * Copy Constructor
     * @param orig original Film object to copy
     */
    Film(const Film& orig);
    
    virtual ~Film();
    
    //methods
    /**
     * Return the rank of the movie
     * @return the rank
     */
    int getRank() const;
    
    /**
     * Returns the title of the film
     * @return the title
     */
    std::string getTitle() const;
    
    /**
     * return the studio of the film
     * @return the studio
     */
    std::string getStudio() const;
    
    /**
     * returns the total gross of the film
     * @return the total gross
     */
    double getTotalGross() const;
    
    /**
     * returns the total theaters of the film
     * @return total theaters
     */
    int getTotalTheaters() const;
    
    /**
     * Gets the opening gross of the Film
     * @return opening gross of the film
     */
    double getOpeningGross() const;
    
    /**
     * returns the number of opening theaters of the film
     * @return opening theaters
     */
    int getOpeningTheaters() const;
    
    /**
     * returns the opening date of the film
     * @return opening date
     */
    std::string getOpeningDate() const;
    
    //overloaded operators
    
    /**
     * The film title will determine if a film is less than, equal to, or
     * greater than another film
     * @param rhs the other film 
     * @return true is this film is less than rhs, false otherwise
     */
    bool operator<(const Film& rhs) const;
    
    /**
     * The film title will determine if a film is less than, equal to, or
     * greater than another film
     * @param rhs
     * @return True if this Film is greater than rhs, false otherwise
     */
    bool operator>(const Film& rhs) const;
    
    /**
     * The film title will determine if a film is less than, equal to, or
     * greater than another film
     * @param rhs
     * @return True if Films are equal, false otherwise
     */
    bool operator==(const Film& rhs) const;
    
    /**
     * Displays the state of the object
     * @param out ostream operator
     * @param rhs Film object to display
     */
    friend std::ostream& operator<<(std::ostream& out, Film& rhs);
    
    
    
    
private:
    /*Rank of the Film*/
    int rank;
    
    /*Title of the Film*/
    std::string title; 
    
    /*Studio of the Film*/
    std::string studio;
    
    /*Total Gross of the Film*/
    double totalGross;
    
    /*Total Theaters of the Film*/
    int totalTheaters;
    
    /*Opening Gross of the Film*/
    double openingGross;
    
    /*Opening Theaters of the Film*/
    int openingTheaters;
    
    /*Opening Date of the Film*/
    std::string openingDate;
    
    /**
     * Helper function that takes in a number and converts it to a formatted
     * string containing commas
     * Credit: Professor Woods.
     * @param numberToFormat number to format
     * @return number formatted with commas
     */
    std::string formatNumber(double numberToFormat);
};

#endif /* FILM_H */

