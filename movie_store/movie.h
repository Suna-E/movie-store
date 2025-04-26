#pragma once
#include "customer.h"
#define movies_max 100



struct movie {
    std::string Name, CurrentRenter;
    double rating = 0, price, fee; //renting price and fee are per day
    int RentedCount = 0;
    bool rented = false, due = false;
    std::vector<int> AllRatings;
    date::year_month_day DueDate;
};


// movie movies[movies_max];
// int movies_count = getMoviesCount(); //put it in main


//-------------------------utilities-----------------------------
bool isCustomerFound(Customer customers[], int num_of_customers ,std::string& id);
int getCustomerNum(Customer customers[], int number_of_customers, std::string& id);
bool isMovieFound(movie movies[], int num_of_movies, std::string& movieName);
int getMovieNum(movie movies[], int num_of_movies, std::string& movieName);
bool isMovieRentedByCustomer(Customer customers[], int num_of_customers ,std::string& id, std::string& movieName);
bool isFull(Customer customers[], int customerNum);
int getMoviesCount(movie movies[], int size);
//-------------------------utilities-----------------------------


void ListMovies(movie movies[],int num_of_movies);
void listRented(movie movies[], int num_of_movies);
int ListUnrented(movie movies[], int movies_count);

bool rate(movie movies[], int num_of_movies, std::string& movieName, Customer customers[], int num_of_customers ,std::string& id);
bool editRating(movie movies[],int num_of_movies,std::string& movieName, Customer customers[],int num_of_customers,std::string& id);

void rent(Customer customers[],int num_of_customers, movie movies[], int num_of_movies);

int validate_due(movie& movie); //to do
void ListDueAccounts(movie(&mov)[movies_max], Customer cust[]);

void MainMenu(Customer customers[], int num_of_customers, movie movies[], int num_of_movies); 
