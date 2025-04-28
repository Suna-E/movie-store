#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <thread>
#include <chrono>
#include <limits>
#include <sstream>
#include <map>
#include "Howard_Hinnant/include/date/date.h"
#include "customer.h"
#include "movie.h"
#include "admin.h"
using namespace date;
using namespace std::chrono; //pollutes the entire namespace for the program but it's ok, and way easier than dealing wi chrono and date types


void mainMenu(Customer customers[], int size_of_customers, movie movies[], int size_of_movies);

//-------------------------general----------------------------
void is_num(int& input);
void is_num(double& input);
bool yes_no();
//------------------------------------------------------------


//-------------------------Customers--------------------------
std::string generateId(); // done
std::string deleteSpaces(std::string& str); // done
bool checkPhoneNumber(std::string& PhoneNumber); // done
bool checkPhoneNumberRegistered(Customer customers[], int customers_count, std::string& PhoneNumber); // done
bool checkId(Customer customers[], int customers_count, std::string& id); // done
int getCustomersCount(Customer customers[], int size_of_customers); // done
bool isEmpty(Customer customers[], int customerIndex); // done
//-------------------------------------------------------------

//-------------------------Movies------------------------------
bool isCustomerFound(Customer customers[], int customers_count ,std::string& id); // done
int getCustomerIndex(Customer customers[], int customers_count, std::string& id); // done
bool isMovieFound(movie movies[], int movies_count, std::string& movieName); // done
int getMovieIndex(movie movies[], int movies_count, std::string& movieName); // done
bool isMovieRentedByCustomer(Customer customers[], int customers_count ,std::string& id, std::string& movieName); // done
bool isCurrentlyRentedEmpty(Customer customers[], int customerIndex); // done
int getMoviesCount(movie movies[], int size_of_movies); // done
//-------------------------------------------------------------
