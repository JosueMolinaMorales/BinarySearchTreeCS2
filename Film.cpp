/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Film.cpp
 * Author: Josue M.
 * 
 * Created on April 5, 2021, 7:18 PM
 */

#include "Film.h"
#include <iostream>
#include <iomanip>
#include <sstream>

Film::Film(){}

Film::Film(const std::string input) {
    //String to hold input to convert
    std::string stringConvert = "";
    
    //input stream
    std::istringstream inputStream(input);
    
    
    std::getline(inputStream, stringConvert, ',');
    rank = std::stoi(stringConvert);
    
    std::getline(inputStream, title, ',');
    std::getline(inputStream, studio, ',');
    
    std::getline(inputStream, stringConvert, ',');
    totalGross = std::stod(stringConvert);
    
    std::getline(inputStream, stringConvert, ',');
    totalTheaters = std::stoi(stringConvert);
    
    std::getline(inputStream, stringConvert, ',');
    openingGross = std::stod(stringConvert);
    
    std::getline(inputStream, stringConvert, ',');
    openingTheaters = std::stoi(stringConvert);
    
    std::getline(inputStream, openingDate, ',');
    
}

Film::Film(const Film& orig)
: rank(orig.rank), title(orig.title), studio(orig.studio), totalGross(orig.totalGross),
  totalTheaters(orig.totalTheaters), openingGross(orig.openingGross), 
  openingDate(orig.openingDate), openingTheaters(orig.openingTheaters)
{}

Film::~Film() {
}

int Film::getRank() const{
    return rank;
}

std::string Film::getTitle() const{
    return title;
}

std::string Film::getStudio() const{
    return studio;
}

double Film::getTotalGross() const{
    return totalGross;
}

int Film::getTotalTheaters() const{
    return totalTheaters;
}

int Film::getOpeningTheaters() const{
    return openingTheaters;
}

double Film::getOpeningGross() const{
    return openingGross;
}

std::string Film::getOpeningDate() const{
    return openingDate;
}

bool Film::operator< (const Film& rhs) const{
    return (this->title < rhs.title);
}

bool Film::operator> (const Film& rhs) const{
    return (this->title > rhs.title);
}

bool Film::operator== (const Film& rhs) const{
    return (this->title == rhs.title);
}

std::ostream& operator<< (std::ostream& out, Film& rhs){
    return out << std::left
            << std::setw(10) << rhs.getRank() 
            << std::setw(50) << rhs.getTitle()
            << std::setw(20) << rhs.getStudio()
            << std::setw(30) << rhs.formatNumber(rhs.getTotalGross())
            << std::setw(30) << rhs.formatNumber(rhs.getTotalTheaters())
            << std::setw(30) << rhs.formatNumber(rhs.getOpeningGross())
            << std::setw(30) << rhs.formatNumber(rhs.getOpeningTheaters())
            << std::setw(30) << rhs.getOpeningDate() << "\n";
    
}


std::string Film::formatNumber(double numberToFormat){

    // Declare an ostringstream variable

    std::ostringstream format;
    
    // Insert parameter into stringstream object
    //   formatted with decimal point and precision of 2
    format << std::setprecision(2) << std::showpoint << std::fixed << numberToFormat;



    // Convert stringstream to a string
    std::string formatCommas = format.str();



    // Are commas needed? (Comma needed when length >= 7)
    if (formatCommas.length() >= 7){

      // Get the starting position to start entering the commas
      int i = formatCommas.length()-6;

      // Insert comma every 3rd position from the last until the position is at 1 or less
      while (i >= 1){
        formatCommas.insert(i, 1, ',');
        i = i-3;
      }

    }



    // Return the number formatted as a string with commas added
    return formatCommas;

}
