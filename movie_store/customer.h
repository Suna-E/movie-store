#pragma once
#include "utilities.h"

#define limit 8
#define customer_max 50

struct Customer
{
    std::string Name, PhoneNumber, Id;
    std::string CurrentlyRentedMovies[limit];
    std::vector<std::string> PreviouslyRentedMovies;
    std::map<std::string, int> rating;
};


//-------------------------utilities-----------------------------
// std::string generateId(); // done
// std::string deleteSpaces(std::string& str); // done
// bool checkPhoneNumber(std::string& PhoneNumber); // done
// bool checkPhoneNumberRegistered(Customer customers[], int customers_count, std::string& PhoneNumber); // done
// bool checkId(Customer customers[], int customers_count, std::string& id); // done
// int getCustomersCount(Customer customers[], int size_of_customers); // done
// bool isEmpty(Customer customers[], int customerIndex); // done
//-------------------------utilities-----------------------------

void listCustomers(Customer customers[], int customers_count); // done
void addNewCustomer(Customer customers[], int size_of_customers, int& customers_count); // done
