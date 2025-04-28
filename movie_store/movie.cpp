#include "movie.h"


// //-------------------------utilities-----------------------------
// bool isCustomerFound(Customer customers[], int customers_count, std::string& id) // done
// {
//     for(int i = 0; i < customers_count; i++)
//     {
//         if(customers[i].Id == id) return true;
//     }
//     return false;
// }
// int getCustomerIndex(Customer customers[], int customers_count, std::string& id) // done
// {
//     int customerIndex = 0;
//     for(int i = 0; i < customers_count; i++)
//     {
//         if(customers[i].Id == id)
//         {
//             return customerIndex;
//         }
//         customerIndex++;
//     }
// }
// bool isMovieFound(movie movies[], int movies_count, std::string& movieName) // done
// {
//     for(int i = 0; i < movies_count; i++)
//     {
//         if(movies[i].Name == movieName) return true;
//     }
//     return false;
// } 
// int getMovieIndex(movie movies[], int movies_count, std::string& movieName) // done
// {
//     int movieIndex = 0;
//     for(int i = 0; i < movies_count; i++)
//     {
//         if(movies[i].Name == movieName)
//         {
//             return movieIndex;
//         }
//         movieIndex++;
//     }
// }
// bool isMovieRentedByCustomer(Customer customers[], int customers_count ,std::string& id, std::string& movieName) // done
// {
//     int customerIndex = getCustomerIndex(customers, customers_count, id);
//     for (int i = 0; i < limit; i++)
//     {
//         if(customers[customerIndex].CurrentlyRentedMovies[i] == movieName) return true;
//     }
    
//     return false;
// }
// bool isCurrentlyRentedEmpty(Customer customers[], int customerIndex) // done
// {
//     for(int i = 0; i < limit; i++)
//     {
//         if(customers[customerIndex].CurrentlyRentedMovies[i].empty()) return true; 
//     } 
    
//     return false;
// }
// int getMoviesCount(movie movies[], int size_of_movies) // done
// {
//     if(size_of_movies != 0)
//     {
//         int movies_count = 0;
//         for (int i = 0; i < size_of_movies; i++)
//         {
//             if(!movies[i].Name.empty())
//             {
//                 movies_count++;
//             }
//         }
//         return movies_count;
//     }
//     else
//     {
//         std::cout << "There are currently no movies on the system!, please add a movie first.\n";
//     }
// }
// //-------------------------utilities-----------------------------


void ListMovies(movie movies[], int movies_count) // done
{
    if(movies_count != 0)
    {
        int MovieNum = 1;
        std::cout << "\n-----------------------------\n";
        for (int i = 0; i < movies_count; i++) 
        {
            std::cout << MovieNum << ". " << movies[i].Name << '\n';
            std::cout << "\tprice: " << movies[i].price << " EGP" << '\n';
            std::cout << "\trented: " << movies[i].RentedCount << " times" << '\n';
            if (movies[i].AllRatings.empty()) 
            {
            std::cout << "\trating: has not been rated yet\n";
            }
            else 
            {
                std::cout << "\trating:" << movies[i].rating << '\n';
            }
            if (movies[i].rented) 
            {
                std::cout << "\trented status: " << "rented\n";
            }
            else
            {
                std::cout << "\trented status: " << "not rented\n";
            }
            std::cout << '\n';
            MovieNum++;
        }
        std::cout << "-----------------------------\n";
    }
    else
    {
        std::cout << "There are currently no movies on the system!, please add a movie first.\n";
    }
}

void listRented(movie movies[], int movies_count) // done
{
    if(movies_count != 0)
    {
        int movieNum = 1;
        std::cout << "\n-----------------------------\n";
        for (int i=0; i < movies_count; i++)
        {
            if(movies[i].rented)
            {
                std::cout << movieNum << ". \n";
                std::cout << "Movie name: " << movies[i].Name << '\n';
                std::cout << "Rented by :" << movies[i].CurrentRenter << '\n';
                movieNum++;
            }
        }
        if(movieNum == 1) std::cout << "There are no rented movies at the moment!\n";
        std::cout << "-----------------------------\n";
    }
    else
    {
        std::cout << "There are currently no movies on the system!, please add a movie first.\n";
    }
}

int ListUnrented(movie movies[], int movies_count) // done
{
    int MovieNum = 1;
    if (movies_count != 0)
    {
        std::cout << "\n-----------------------------\n";
        for (int i = 0; i < movies_count; i++)
        {
            if (!movies[i].rented)
            {
                std::cout << MovieNum << ". " << movies[i].Name << '\n';
                MovieNum++;
            }
        }
        if (MovieNum == 1) //meaning there are movies on the system but no movies were displayed, aka they are all rented 
        { 
            std::cerr << "There are currently no available movies to rent.\n";
        }
        std::cout << "-----------------------------\n";
    }
    else 
    {
        std::cerr << "there are currently no movies on the system!, please add a movie first.\n";
    }
    return MovieNum;
}


bool rate(movie movies[], int movies_count, std::string& movieName, 
            Customer customers[], int customers_count ,std::string& id) // done
{
    int customerIndex = getCustomerIndex(customers, customers_count, id);
    
    if (isMovieRentedByCustomer(customers, customers_count, id, movieName))
    {
        if(!customers[customerIndex].rating.count(movieName))
        {
            int rating = 0, a = 0, b = 0, c = 0, d = 0, e = 0;
            int movieIndex = getMovieIndex(movies, movies_count, movieName);
            std::cout << "\n\nRating: " << movieName << "\n\n";
            std::cout << "1: *\n" <<
                         "2: **\n" <<
                         "3: ***\n" <<
                         "4: ****\n" <<
                         "5: *****\n\n";
            
            std::cout << "Pick a rating from above: ";
            std::cin >> rating;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            
            switch (rating)
            {
            case 1:
                movies[movieIndex].AllRatings.push_back(1);
                customers[customerIndex].rating.insert({movieName, 1}); 
                break;                    
            case 2:
                movies[movieIndex].AllRatings.push_back(2);
                customers[customerIndex].rating.insert({movieName, 2});  
                break;                    
            case 3:
                movies[movieIndex].AllRatings.push_back(3);
                customers[customerIndex].rating.insert({movieName, 3}); 
                break;                    
            case 4:
                movies[movieIndex].AllRatings.push_back(4);
                customers[customerIndex].rating.insert({movieName, 4}); 
                break;                    
            case 5:
                movies[movieIndex].AllRatings.push_back(5);
                customers[customerIndex].rating.insert({movieName, 5}); 
                break;
            
            default:
                std::cout << "Wrong rating! please pick a rating from above!\n";
                std::this_thread::sleep_for(std::chrono::seconds(2));
                return false;
            }
            if (!movies[movieIndex].AllRatings.empty())
            {
                for (int i : movies[movieIndex].AllRatings)
                {
                    switch (i)
                    {
                    case 1:
                        a++;
                        break;
                    case 2:
                        b++;
                        break;
                    case 3:
                        c++;
                        break;
                    case 4:
                        d++;
                        break;
                    case 5:
                        e++;
                        break;
                    default:
                        std::cerr << "Error in the ratings vector or the calcrating function, please contact your IT provider\n";
                        break;
                    }
                }
                movies[movieIndex].rating = (a * 1 + b * 2 + c * 3 + d * 4 + e * 5) / (a + b + c + d + e);
            }
            else
            {
                movies[movieIndex].rating = rating;
                return true; //for main menu
            }
        } 
        else
        {
            std::cout << "This movie is already rated! Please edit your rating.\n";
            return true;    
        }
    } 
    else 
    {
        std::cout << "This movie isn't rented by the customer! Rent it please before rating it.\n";
        return true; // for main menu
    }
    std::cout << "Thanks for your rating!\n";
    return true; // for main menu
}

bool editRating(movie movies[], int movies_count, std::string& movieName,
                Customer customers[], int customers_count, std::string& id) // done
{
    int customerIndex = getCustomerIndex(customers, customers_count, id);
    
    if (isMovieRentedByCustomer(customers, customers_count, id, movieName))
    {
        if(customers[customerIndex].rating.count(movieName))
        {
            int rating = 0;
            int movieIndex = getMovieIndex(movies, movies_count, movieName);
            std::cout << "\n\nRating: " << movieName << "\n\n";    
            std::cout << "1: *\n" <<
                         "2: **\n" <<
                         "3: ***\n" <<
                         "4: ****\n" <<
                         "5: *****\n\n";
            
            std::cout << "Pick a rating from above: ";
            std::cin >> rating;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (rating >= 1 && rating <= 5)
            {
                //update allRatings vector
                for(int i = 0; i < movies[movieIndex].AllRatings.size(); i++)
                {
                    if (movies[movieIndex].AllRatings[i] == customers[customerIndex].rating.at(movieName))
                    {
                        movies[movieIndex].AllRatings[i] = rating;
                        break;
                    }
                }
                customers[customerIndex].rating.at(movieName) = rating;
                std::cout << "Thanks for your rating!\n"; 
                return true; // for main menu
            }
            else
            {
                std::cout << "Wrong rating! please pick a rating from above!\n";
                std::this_thread::sleep_for(std::chrono::seconds(2));
                return false; // for main menu
            }
        }
        else
        {
            std::cout << "This movie isn't rated before please rate it!\n";
            return true;
        }
    }
    else
    {
        std::cout << "This movie isn't rented by the customer! Rent it please before rating it.\n";
        return true; // for main menu
    }
}


void rent(Customer customers[], int customers_count, movie movies[], int movies_count, year_month_day system_date)
{
    bool repeat = true, date_good = false;
    int selected, customerIndex, match = 1;
    std::string name, id, entered_date;
    int y, m, d;
    char delimiter1, delimiter2;

    std::cout << "\n\n";
    int unrented_movies_count = ListUnrented(movies, movies_count);
    if(unrented_movies_count == 1) return;

    do
    {
        std::cout << "Enter customer id: ";
        std::getline(std::cin, id);
        if (id == "0") return; //exit to main menu, note:the user will be notified at the begining of the program that entering 0 takes you back to main menu
        std::cin.clear();
        // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::transform(id.begin(), id.end(), id.begin(), toupper); // c# ---> C#
        if (isCustomerFound(customers, customers_count, id))
        {
            customerIndex = getCustomerIndex(customers, customers_count, id);
            name = customers[customerIndex].Name;
        }
        else
        {
            std::cerr << "Wrong id, please try again\n";
            std::this_thread::sleep_for(std::chrono::seconds(2));
        }
    } while (!isCustomerFound(customers, customers_count, id));

    std::cout << "Pick a movie number: ";
    while (repeat)
    {
        std::cin >> selected;
        if (selected == 0) return; //exit to main menu, note:the user will be notified at the begining of the program that entering 0 takes you back to main menu
        if (std::cin.good() && selected < unrented_movies_count && selected > 0) 
        {
            repeat = false;
        }
        else 
        {
            std::cerr << "Invalid choice. Please select a valid movie number: ";
            repeat = true;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    for (int i = 0; i < movies_count; i++)
    {
        if ((!movies[i].rented) && (match == selected))
        {
            std::cout << "movie: " << movies[i].Name << '\n';
            std::cout << "\tprice per day: " << movies[i].price << " EGP\n";
            std::cout << "\toverdue fee per day: " << movies[i].fee << " EGP\n";
            std::cout << "\tmovie rating:" << movies[i].rating << '\n';
            std::cout << "\thas been rented: " << movies[i].RentedCount << " times\n\n";
            std::cout << "Today is: " << system_date << '\n';
            while (!date_good)/*incomplete fail safe*/ 
            {
                std::cout << "specify due date in this exact format yyyy/mm/dd : ";
                getline(std::cin, entered_date);
                //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin.clear();
                if (entered_date == "0") return; //aborts and exits to main menu

                std::istringstream iss(entered_date);
                if (iss >> y >> delimiter1 >> m >> delimiter2 >> d && y >= 2025 && delimiter1 == '/' && delimiter2 == '/')
                {
                    movies[i].DueDate = year(y) / month(m) / day(d);
                    if(movies[i].DueDate > system_date)
                    {
                        date_good = true;
                    }
                    else
                    {
                        std::cerr << "entered due date is invalid, please try again\n";
                        date_good = false;
                    }
                }
                else
                {
                    std::cerr << "entered due date is invalid, please try again\n";
                    date_good = false;
                }
            }
            if (isCurrentlyRentedEmpty(customers, customerIndex))
            {
                for (int k = 0; k < limit; k++)
                {
                    if (customers[customerIndex].CurrentlyRentedMovies[k].empty())
                    {
                        customers[customerIndex].CurrentlyRentedMovies[k] = movies[i].Name;
                        movies[i].rented = true;
                        movies[i].RentedCount++;
                        movies[i].CurrentRenter = name;
                        return; // returns to main menu;
                    }
                }            
            }
            else
            {
                std::cout << "You have reached your renting limit! return one or more movies!\n";
                return;
            }
        }
        else if (!movies[i].rented) //but match doesnt = selected
        {
            match++;
        }
    }
}

void returnMovie(Customer customers[], int customers_count, std::string& id, movie movies[], int movies_count, 
    bool isDateChanged, sys_days new_date) // done
{
    int num = 1, movieIndex, ans, cash, diff, index = 0;
    std::string movieName;
    int customerIndex = getCustomerIndex(customers, customers_count, id);

    for (std::string movie : customers[customerIndex].CurrentlyRentedMovies)
    {
        if(!movie.empty())
        {
            std::cout << num << ". " << movie << '\n';
            num++;
        }
    }
    do
    {
        std::cout << "Enter number of the movie you wish to return: ";
        is_num(ans);
        if ((ans < num) && (ans > 0))
        {
            num = 1; // to get the choice(movie name) where the customer choose and the index in the array.
            for (std::string movie : customers[customerIndex].CurrentlyRentedMovies)
            {
                if(!movie.empty())
                {
                    if(ans == num)
                    {
                        movieName = movie;
                        break;
                    }
                    num++;
                }
                index++;
            }

            movieIndex = getMovieIndex(movies, movies_count, movieName);
            diff = validate_due(movies[movieIndex], isDateChanged, new_date);
            if (movies[movieIndex].due)
            {
                cash = movies[movieIndex].price + movies[movieIndex].fee * diff;
                std::cout << "considering that the movie is due: " << diff << " days, the amount to pay is: " << cash << " EGP.\n";
            }
            else 
            {
                cash = movies[movieIndex].price;
                std::cout << "amount to pay is: " << cash << " EGP.\n";
            }
            std::cout << "(this is in an italian accent)\n";
            std::cout << "pay up or else? y/n: ";
            if (yes_no()) 
            {
                // std::cout << "Good boy\n"; 
                std::cout << "Transaction completed.\n"; 
            }
            else 
            {
                std::cout << "you have a beautiful family, it'd be a shame if anything happens to them.\nyou sure you still don't want to pay up? y/n: ";
                if (yes_no()) 
                {
                    std::cout << "Smart lad, say hi to your family for me\n";
                }
                else 
                {
                    std::cout << "Remember that it was YOU who made this choice\n";
                    return;
                }
            }
            movies[movieIndex].rented = false;
            movies[movieIndex].CurrentRenter.clear();
            movies[movieIndex].due = false;
            movies[movieIndex].DueDate = date::year(3000) / date::month(10) / date::day(10);
            customers[customerIndex].CurrentlyRentedMovies[index].clear();
            customers[customerIndex].PreviouslyRentedMovies.push_back(movies[movieIndex].Name);
    
            std::cout << "Would you like to rate the movie? y/n: ";
            if (yes_no()) 
            {
                bool check = rate(movies, movies_count, movieName, customers, customers_count, id);
                
                while (!check)
                {
                    check = rate(movies, movies_count, movieName, customers, customers_count, id);
                }
            }
            else 
            {
                return; //back to main menu
            }
        }
        else 
        {
            std::cerr << "Invalid choice, please try again\n";
        }
    } while(!(ans < num) || !(ans > 0));
}

void ListTopRated(movie arr[], const int& mov_count) { //usinng insertion sort, listing top 10 rated
    movie copied[movies_max];
    std::copy(arr, arr + mov_count, copied);
    for (int i = 1; i < mov_count; i++) 
    {
        movie key = copied[i];
        int j = i - 1;
        while (j >= 0 && copied[j].rating < key.rating) 
        {
            copied[j + 1] = copied[j];
            j--;
        }
        copied[j+1] = key;
    }
    for (int k = 0; k < 10;k++) 
    {
        int num = 0;
        std::cout << num << ". " << copied[k].Name;
        num++;
    }
}

void ListTopRented(movie arr[], const int& mov_count) { //usinng insertion sort, listing top 10 rented
    movie copied[movies_max];
    std::copy(arr, arr + mov_count, copied);
    for (int i = 1; i < mov_count; i++) 
    {
        movie key = copied[i];
        int j = i - 1;
        while (j >= 0 && copied[j].RentedCount < key.RentedCount) 
        {
            copied[j + 1] = copied[j];
            j--;
        }
        copied[j + 1] = key;
    }
    for (int k = 0; k < 10;k++) 
    {
        int num = 0;
        std::cout << num << ". " << copied[k].Name;
        num++;
    }
}


int validate_due(movie& movie, bool isDateChanged, sys_days new_date) // done
{
    auto now = std::chrono::system_clock::now(); // return current system date
    sys_days today;
    if (isDateChanged) 
    {
        today = new_date;
    }
    else 
    {
        today = floor<days>(now);
    }
    sys_days due = movie.DueDate;
    
    auto today_n = today.time_since_epoch(); // diff in days from 1970 to present for ex. 20205d, (d) for days
    int today_int = today_n.count(); // convert it to int --> 20205d --> 20205
    
    auto due_n = due.time_since_epoch();
    int due_int = due_n.count();
    int diff=0;
    
    if (today > due) 
    {
        movie.due = true;
        diff = today_int - due_int;
        return diff;
    }
    else 
    {
        movie.due = false;
        return 0;
    }
}

 void ListDueAccounts(movie movies[],int movies_count, Customer customers[], int customers_count, 
                        bool isDateChanged, sys_days new_date) // done
{ //note for when u r debugging dummy, it updates the accounts right before listing them, no earlier
    int num = 1;
    std::cout << "\n-----------------------------\n";   
    for (int i = 0; i < movies_count; i++) 
    {
        int days_due = validate_due(movies[i], isDateChanged, new_date);
        if (movies[i].due == true)
        {
            for (int j = 0; j < customers_count; j++)
            {
                if (movies[i].CurrentRenter == customers[j].Name)
                {
                    std::cout << num << ". " << customers[j].Name << '\n';
                    std::cout << "id: " << customers[j].Id << '\n';
                    std::cout << "phone number: " << customers[j].PhoneNumber << '\n';
                    std::cout << "due movie: " << movies[i].Name << '\n';
                    std::cout << "movie was due: " << days_due << " days ago.\n";
                    std::cout << "due fees up till now: " << days_due * movies[i].fee << "\n\n";
                }
            }
            num++;
        }
    }
    if(num == 1) std::cout << "There are no due accounts!\n";
    std::cout << "-----------------------------\n";
}




// void MainMenu(Customer customers[], int size_of_customers, movie movies[], int size_of_movies) 
// { 
//     int customers_count = getCustomersCount(customers, size_of_customers);
//     int movies_count = getMoviesCount(movies, size_of_movies);
//     bool valid = false,isDateChanged = false;
//     int choice;
//     std::string check;
    
//     sys_days new_date, today;
//     auto now = std::chrono::system_clock::now();
//     today = floor<days>(now);
//     year_month_day system_date = today;

//     std::string menu[] = {
//         "\n-----------------------------\n",
//         "press  1: Rent a movie",
//         "press  2: Rate a movie",
//         "press  3: Edit a rating",
//         "press  4: Return a movie",
//         "press  5: List all customers",
//         "press  6: Add a customer",
//         "press  7: List all movies",
//         "press  8: List rented movies",
//         "press  9: List unrented movies",
//         "press  10: List due accounts",
//         "press  11: List top 10 rented movies",
//         "press  12: List top 10 rated movies"
//     };
//     const int menuSize = sizeof(menu)/sizeof(menu[0]);
    
//     check = login();
//     while (check=="user" || check=="admin") //infinite loop till log out or termination
//     {
//         if (isDateChanged) 
//         {
//             std::cout << "\n\ncurrent date: " << new_date;
//         }
//         else 
//         {
//             std::cout << "\n\ncurrent date: " << today;
//         }
        
//         for(int i = 0; i < menuSize; i++)
//         {
//             std::cout << menu[i] << '\n';
//         }
        
//         if(check=="user")
//         {
//             std::cout << "press  13: Log out\n"; // done
//         }
//         else if (check=="admin") 
//         {
//             std::cout << "press  13: Add a movie\n"; // done
//             std::cout << "press  14: Delete a movie\n"; // done
//             std::cout << "press  15: Delete a customer\n"; // done
//             std::cout << "press  16: set date manually\n"; // done
//             std::cout << "press  17: switch user account\n"; // done
//         }
//         std::cout << "press  0: Exit\n";
//         std::cout << "\nat any point in time, if you wish to go back to main menu enter \"0\"\n";
//         std::cout << "-----------------------------\n";
//         while (!valid) 
//         {
//             std::cin >> choice;
//             if ((std::cin.good() && choice <= 13 && choice > -1) || (std::cin.good() && check=="admin" && choice <= 17 && choice > -1)) 
//             {
//                 valid = true;
//             }
//             else 
//             {
//                 std::cerr << "Invalid choice. Please enter a valid choice: ";
//                 valid = false;
//             }
//             std::cin.clear();
//             std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//         }

//         switch (choice)
//         {
//         case 0: // exit
//             return;
//         case 1: // rent
//             rent(customers, customers_count, movies, movies_count, system_date);
//             std::this_thread::sleep_for(std::chrono::seconds(2));
//             break;
//         case 2: // rate
//         {
//             std::string movieName,id;
//             std::transform(id.begin(), id.end(), id.begin(), toupper); // c# ---> C#
//             std::transform(movieName.begin(), movieName.end(), movieName.begin(), tolower);
            
//             do
//             {
//                 std::cout << "Enter movie name: ";
//                 getline(std::cin, movieName);
//                 if(!isMovieFound(movies,movies_count,movieName))
//                 {
//                     std::cout << "This film doesn't exist! please try again.\n";
//                     continue;
//                 }
//                 std::cout << "Enter customer id: ";
//                 getline(std::cin, id);
//                 if(!isCustomerFound(customers,customers_count,id))
//                 {
//                     std::cout << "Wrong ID! please try again.\n";
//                 }
//             } while(!isCustomerFound(customers,customers_count,id) || !isMovieFound(movies,movies_count,movieName));

//             bool done = rate(movies,movies_count,movieName, customers,customers_count,id);
//             while (!done)
//             {
//                 done = rate(movies,movies_count,movieName, customers,customers_count,id);
//             }
            
//             std::this_thread::sleep_for(std::chrono::seconds(2));
//             break;
//         }
//         case 3: // edit rate
//         {
//             std::string movieName,id;
//             std::transform(id.begin(), id.end(), id.begin(), toupper); // c# ---> C#
//             std::transform(movieName.begin(), movieName.end(), movieName.begin(), tolower);
            
//             do
//             {
//                 std::cout << "Enter movie name: ";
//                 getline(std::cin, movieName);
//                 if(!isMovieFound(movies,movies_count,movieName))
//                 {
//                     std::cout << "This film doesn't exist! please try again.\n";
//                     continue;
//                 }
//                 std::cout << "Enter customer id: ";
//                 getline(std::cin, id);
//                 if(!isCustomerFound(customers,customers_count,id))
//                 {
//                     std::cout << "Wrong ID! please try again.\n";
//                 }
//             } while(!isCustomerFound(customers,customers_count,id) || !isMovieFound(movies,movies_count,movieName));

//             bool done = editRating(movies,movies_count,movieName, customers,customers_count,id); 
//             while(!done)
//             {
//                 done = editRating(movies,movies_count,movieName, customers,customers_count,id);
//             }
//             std::this_thread::sleep_for(std::chrono::seconds(2));
//             break;
//         }
//         case 4: // return a movie
//         {
//             std::string id;
//             std::transform(id.begin(), id.end(), id.begin(), toupper);
//             do
//             {
//                 std::cout << "Enter customer id: ";
//                 getline(std::cin, id);
//                 if(!isCustomerFound(customers,customers_count,id))
//                 {
//                     std::cout << "This customer doesn't exist! Please try again.\n";
//                 }
//             } while(!isCustomerFound(customers,customers_count,id));
//             returnMovie(customers,customers_count,id, movies, movies_count, isDateChanged, new_date);
//             break;
//         }            
//         case 5: // list all customer
//             listCustomers(customers, customers_count);
//             break;
//         case 6: // add new customer
//             addNewCustomer(customers, size_of_customers, customers_count);
//             std::this_thread::sleep_for(std::chrono::seconds(2));
//             break;
//         case 7: // list all movies
//             ListMovies(movies, movies_count);
//             break;
//         case 8: // list rented
//             listRented(movies, movies_count);
//             break;
//         case 9: // list unrented
//             ListUnrented(movies, movies_count);
//             break;
//         case 10: // list due accounts
//             ListDueAccounts(movies, movies_count, customers, customers_count, isDateChanged, new_date);
//             break;
//         case 11: // top 10 rented
//             ListTopRented(movies, movies_count);
//             break;
//         case 12: // top 10 rated
//             ListTopRated(movies, movies_count);
//             break;
//         case 13: // log out for user --- add new movie for admin.
//         {
//             if(check=="user")
//             {
//                 check = login();
//                 std::this_thread::sleep_for(std::chrono::seconds(2));
//             }
//             else if (check=="admin")
//             {
//                 addNewMovie(movies, size_of_movies, movies_count);
//                 std::this_thread::sleep_for(std::chrono::seconds(2));
//             }
//             break;
//         }
//         case 14: // delete movie
//         {
//             std::string movieName;
//             std::transform(movieName.begin(), movieName.end(), movieName.begin(), tolower);
//             do
//             {
//                 std::cout << "Enter movie name: ";
//                 getline(std::cin, movieName);
//                 if(!isMovieFound(movies,movies_count,movieName))
//                 {
//                     std::cout << "This film doesn't exist! please try again.\n";
//                 }
//             } while(!isMovieFound(movies, movies_count, movieName));
            
//             deleteMovie(movies, movies_count, movieName);
//             std::this_thread::sleep_for(std::chrono::seconds(2));
//             break;
//         }
//         case 15: // delete customer
//         {
//             std::string id;
//             std::transform(id.begin(), id.end(), id.begin(), toupper);
//             do
//             {
//                 std::cout << "Enter customer id: ";
//                 getline(std::cin, id);
//                 if(!isCustomerFound(customers,customers_count,id))
//                 {
//                     std::cout << "This customer doesn't exist! Please try again.\n";
//                 }
//             } while(!isCustomerFound(customers,customers_count,id));
            
//             deleteCustomer(customers, customers_count, id);
//             std::this_thread::sleep_for(std::chrono::seconds(2));
//             break;
//         }
//         case 16:
//             isDateChanged = ChangeDate(new_date);
//             std::this_thread::sleep_for(std::chrono::seconds(2));
//             break;
//         case 17: // logout for admin
//             check = login();
//             std::this_thread::sleep_for(std::chrono::seconds(2));
//             break;
//         default:
//             std::cerr << "Validation error in the main menu function, please contact your IT provider\nexiting program in 2 seconds";
//             std::this_thread::sleep_for(std::chrono::seconds(2));
//             return;
//         }
//         valid = false; //allows you to retake input from usr
//     }
// }
