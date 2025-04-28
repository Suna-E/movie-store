#pragma once
#include "utilities.h"

std::string checkCredentials(std::string& login, std::string& passwrd); // done
void deleteCustomer(Customer customers[], int& customers_count, std::string& id); // done
void deleteMovie(movie movies[], int& movies_count, std::string& movieName); // done
std::string login(); // done
void addNewMovie(movie movies[], int size_of_movies, int& movies_count); // done
bool changeDate(sys_days& new_date); // done