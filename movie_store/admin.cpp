﻿#include "admin.h"

std::string ADMIN = "admin";
std::string ADMIN_PSSWRD = "admin"; // very safe ;) __ i can see😂

std::string USER = "user";
std::string USER_PSSWRD = "user";

std::string checkCredentials(std::string& login, std::string& passwrd)
{
    if(login == ADMIN && passwrd == ADMIN_PSSWRD)
    {
        return "admin";
    }
    else if (login == USER && passwrd == USER_PSSWRD)
    {
        return "user";        
    }
    return "";
}

void deleteCustomer(Customer customers[], int size, std::string id)
{
    // Rahma
}

void deleteMovie(movie movies[], int size, std::string name)
{
    for(int i = 0; i<size; i++)
    {
        if(movies[i].Name == name)
        {
            movies[i].Name.clear();
            movies[i].CurrentRenter.clear();
            movies[i].AllRatings.clear();
            movies[i].rented = false;
            movies[i].price = 0;
            movies[i].fee = 0;
            movies[i].rating = 0;
            movies[i].RentedCount = 0;
            movies[i].DueDate = date::year(1000) / date::month(10) / date::day(10);
            movies[i].due = false;
            break;
        }
    }
}

int login()
{
    std::string login, passwrd;
    do
    {
        std::cout << "Enter username: ";
        getline(std::cin, login);
        if (login == "0") return 0;
        std::cout << "Enter password: ";
        getline(std::cin, passwrd);
        if (passwrd == "0") return 0;
        if(checkCredentials(login, passwrd) == "admin")
        {
            std::cout << "Welcome, " << login << "!\n";
            std::this_thread::sleep_for(std::chrono::seconds(2));
            return 1;
        }
        else if(checkCredentials(login, passwrd) == "user")
        {
            std::cout << "Welcome, " << login << "!\n";
            std::this_thread::sleep_for(std::chrono::seconds(2));
            return 2;
        }
        else
        {
            std::cout << "Wrong password or username\n";
        }
    } while(checkCredentials(login, passwrd) == "");
}

void ChangeDate() {

}