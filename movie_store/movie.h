#pragma once
#include "utilities.h"
#define movies_max 100


struct movie {
    std::string Name, CurrentRenter;
    double rating, price, fee; //renting price and fee are per day
    int RentedCount;
    bool rented = false, due = false;
    std::vector<int> AllRatings;
    date::year_month_day DueDate = year(1000)/month(10)/day(10);
};

//-------------------------utilities-----------------------------
// bool isCustomerFound(Customer customers[], int customers_count ,std::string& id); // done
// int getCustomerIndex(Customer customers[], int customers_count, std::string& id); // done
// bool isMovieFound(movie movies[], int movies_count, std::string& movieName); // done
// int getMovieIndex(movie movies[], int movies_count, std::string& movieName); // done
// bool isMovieRentedByCustomer(Customer customers[], int customers_count ,std::string& id, std::string& movieName); // done
// bool isCurrentlyRentedEmpty(Customer customers[], int customerIndex); // done
// int getMoviesCount(movie movies[], int size_of_movies); // done
//-------------------------utilities-----------------------------


void ListMovies(movie movies[],int movies_count); // done
void listRented(movie movies[], int movies_count); // done 
int ListUnrented(movie movies[], int movies_count); // done

bool rate(movie movies[], int movies_count, std::string& movieName, 
    Customer customers[], int customers_count ,std::string& id); // done

bool editRating(movie movies[], int movies_count, std::string& movieName,
    Customer customers[], int customers_count, std::string& id); // done

void rent(Customer customers[], int customers_count, movie movies[], int movies_count, year_month_day system_date);
void returnMovie(Customer customers[], int customers_count, std::string& id, movie movies[], int movies_count, 
    bool isDateChanged, sys_days new_date);

int validate_due(movie& movie, bool isDateChanged, sys_days new_date); // done
void ListDueAccounts(movie movies[],int movies_count, Customer customers[], int customers_count, 
    bool isDateChanged, sys_days new_date); //done

    
void ListTopRated(movie arr[], const int& mov_count);

void ListTopRented(movie arr[], const int& mov_count);


// void MainMenu(Customer customers[], int size_of_customers, movie movies[], int size_of_movies); // almost done