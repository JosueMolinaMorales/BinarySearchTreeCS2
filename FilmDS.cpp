/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FilmDS.cpp
 * Author: twist
 * 
 * Created on April 12, 2021, 3:30 PM
 */

#include "FilmDS.h"
#include <iomanip>
#include <algorithm>

int FilmDS::searchRank = 0;
std::string FilmDS::searchString = "";
bool FilmDS::found = false;

void displayHeader(){
    std::cout << std::left << std::setw(10) << "Rank" << std::setw(50) << "Title" 
            << std::setw(20) << "Studio" <<  std::setw(30) <<"Total Gross ($)"   
            << std::setw(30) <<"Total Theaters" << std::setw(30) << "Opening Gross ($)" 
            << std::setw(30) << "Opening Theaters" <<  std::setw(30) <<"Opening Date" << std::endl;
}

void displayByTitle(Film& aFilm){
    std::cout << aFilm;
}

void displayByRank(Film& aFilm){
    if(aFilm.getRank() == FilmDS::searchRank){
        std::cout << aFilm;
    }
}

void searchForTitle(Film& aFilm){
    std::string lowerSearchString = FilmDS::searchString;
    std::string lowerTitle = aFilm.getTitle();
    std::transform(lowerSearchString.begin(), lowerSearchString.end(), lowerSearchString.begin(), ::tolower);
    std::transform(lowerTitle.begin(), lowerTitle.end(), lowerTitle.begin(), ::tolower);
    
    if(lowerSearchString == lowerTitle){
        std::cout << aFilm;
        FilmDS::found = true;
    }
    
}

void searchForStudio(Film& aFilm){
    if(aFilm.getStudio() == FilmDS::searchString){
        std::cout << aFilm;
        FilmDS::found = true;
    }
}

void searchByMonth(Film& aFilm){
    if(aFilm.getOpeningDate().find(FilmDS::searchString) != std::string::npos){
        std::cout << aFilm;
        FilmDS::found = true;
    }
}

void searchForKeyword(Film& aFilm){
    if(aFilm.getTitle().find(FilmDS::searchString) != std::string::npos){
        std::cout << aFilm;
        FilmDS::found = true;
    }
}

FilmDS::FilmDS() {
}

void FilmDS::add(const Film& aFilm){
    filmBST.add(aFilm);
}

void FilmDS::orderByRank() const{
    displayHeader();
    for(int i = 1; i <= 100; i++){
        searchRank = i;
        filmBST.inorderTraverse(displayByRank);
    }
}

void FilmDS::orderByTitle() const{
    displayHeader();
    filmBST.inorderTraverse(displayByTitle);
}

void FilmDS::searchByTitle(std::string title) const{
    searchString = title;
    found = false;
    
    filmBST.inorderTraverse(searchForTitle);
    if(!found){
        std::cout << title << " was not found in data." << std::endl;
    }else{
        displayHeader();
    }
}

void FilmDS::searchByKeyword(std::string keyword) const{
    searchString = keyword;
    found = false;
    
    std::cout << "Results for Keyword: " << keyword << std::endl;
    
    filmBST.inorderTraverse(searchForKeyword);
    if(!found){
        std::cout << keyword << " was not found in data." << std::endl;
    }else{
        displayHeader();
    }
}

void FilmDS::searchByStudio(std::string studio) const{
    searchString = studio;
    found = false;
    
    filmBST.inorderTraverse(searchForStudio);
    if(!found){
        std::cout << studio << " was not found in data." << std::endl;
    }else{
        displayHeader();
    }
}

void FilmDS::searchByMonthOfRelease(std::string month) const{
    searchString = month;
    found = false;
    
    filmBST.inorderTraverse(searchByMonth);
    if(!found){
        std::cout << "No movie in data has a release month of " << month << std::endl;
    }else{
        displayHeader();
    }
}

