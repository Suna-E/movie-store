#include "admin.h"

std::string ADMIN = "admin";
std::string ADMIN_PSSWRD = "admin"; // very safe ;) __ i can see😂

std::string USER = "user";
std::string USER_PSSWRD = "user";

std::string checkCredentials(std::string& login, std::string& passwrd) // done
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

void deleteCustomer(Customer customers[], int& customers_count, std::string& id) // done
{
    if(customers_count != 0)
    {
        for (int i = 0; i < customers_count; i++) 
        {
            if (customers[i].Id == id) 
            {
                if(i < customers_count-1)
                {
                    customers[i].Name = customers[customers_count-1].Name;
                    customers[i].PhoneNumber = customers[customers_count-1].PhoneNumber;
                    customers[i].Id = customers[customers_count-1].Id;
                    customers[i].PreviouslyRentedMovies = customers[customers_count-1].PreviouslyRentedMovies;
                    for(int j = 0; j < limit; j++)
                    {
                        customers[i].CurrentlyRentedMovies[j] = customers[customers_count-1].CurrentlyRentedMovies[j];
                    }
                    
                    customers[customers_count-1].Name.clear();
                    customers[customers_count-1].Id.clear();
                    customers[customers_count-1].PhoneNumber.clear();
                    customers[customers_count-1].PreviouslyRentedMovies.clear();
                    for(int j = 0; j < limit; j++)
                    {
                        customers[customers_count-1].CurrentlyRentedMovies[j].clear();
                    }
                    customers_count--;
                }
                else if (i == customers_count-1)
                {
                    customers[i].Name.clear();
                    customers[i].Id.clear();
                    customers[i].PhoneNumber.clear();
                    customers[i].PreviouslyRentedMovies.clear();
                    for(int j = 0; j < limit; j++)
                    {
                        customers[i].CurrentlyRentedMovies[j].clear();
                    }
                    customers_count--;
                }
                else
                {
                    std::cout << "Error in the customer array, please contact your IT provider\n";
                    break;
                }
                std::cout << "Customer with ID: " << id << " deleted successfully.\n";
                break;
            }
        }
    }
    else
    {
        std::cout << "There are currently no customers on the system!, please add a customer first.\n";
    }
}

void deleteMovie(movie movies[], int& movies_count, std::string& movieName) // done
{
    if(movies_count != 0)
    {
        for(int i = 0; i < movies_count; i++)
        {
            if(movies[i].Name == movieName)
            {
                if (i < movies_count - 1) 
                {
                    movies[i].Name = movies[movies_count - 1].Name;
                    movies[i].CurrentRenter = movies[movies_count - 1].CurrentRenter;
                    movies[i].AllRatings = movies[movies_count - 1].AllRatings;
                    movies[i].rented = movies[movies_count - 1].rented;
                    movies[i].price = movies[movies_count - 1].price;
                    movies[i].fee = movies[movies_count - 1].fee;
                    movies[i].rating = movies[movies_count - 1].rating;
                    movies[i].RentedCount = movies[movies_count - 1].RentedCount;
                    movies[i].DueDate = movies[movies_count - 1].DueDate;
                    movies[i].due = movies[movies_count - 1].due;
                    //----------------
                    movies[movies_count - 1].Name.clear();
                    movies[movies_count - 1].CurrentRenter.clear();
                    movies[movies_count - 1].AllRatings.clear();
                    movies[movies_count - 1].rented = false;
                    movies[movies_count - 1].price = 0;
                    movies[movies_count - 1].fee = 0;
                    movies[movies_count - 1].rating = 0;
                    movies[movies_count - 1].RentedCount = 0;
                    movies[movies_count - 1].DueDate = date::year(1000) / date::month(10) / date::day(10);
                    movies[movies_count - 1].due = false;
                    movies_count--;
                }
                else if (i == movies_count - 1) 
                {
                    movies[i].Name.clear();
                    movies[i].CurrentRenter.clear();
                    movies[i].AllRatings.clear();
                    movies[i].rented = false;
                    movies[i].price = 0;
                    movies[i].fee = 0;
                    movies[i].rating = 0;
                    movies[i].RentedCount = 0;
                    movies[i].DueDate = date::year(1000) / date::month(10) / date::day(10); //default state for empty, not an actual thing in the language i just decided that
                    movies[i].due = false;
                    movies_count--;
                }
                else 
                {
                    std::cerr << "Error in the movies array, please contact your IT provider";
                    break;
                }
                std::cout << "Movie : "<< movieName << " deleted successfully\n";
                break;
            }
        }
    }
    else
    {
        std::cout << "There are currently no movies on the system!, please add a movie first.\n";
    }
}

std::string login() // done
{
    std::string login, passwrd;
    do
    {
        std::cout << "Enter username: ";
        std::getline(std::cin, login);
        if (login == "0") return "";
        
        std::cout << "Enter password: ";
        std::getline(std::cin, passwrd);
        if (passwrd == "0") return "";
        
        if(checkCredentials(login, passwrd) == "admin")
        {
            std::cout << "Welcome, " << login << "!\n";
            return "admin";
        }
        else if(checkCredentials(login, passwrd) == "user")
        {
            std::cout << "Welcome, " << login << "!\n";
            return "user";
        }
        else
        {
            std::cout << "Wrong password or username\n";
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    } while(checkCredentials(login, passwrd) == "");
}

void addNewMovie(movie movies[], int size_of_movies, int& movies_count) // done
{
    std::string movieName;
    double price, fee;
    do
    {
        std::cout << "Enter movie name: ";
        getline(std::cin, movieName);
        std::transform(movieName.begin(), movieName.end(), movieName.begin(), tolower);
        if(isMovieFound(movies,movies_count,movieName))
        {
            std::cout << "This film is already exist!\n";
            continue;
        }
        std::cout << "\nEnter movie price per day(EGP) : ";
        is_num(price);
        std::cout << "\nEnter due fees per day (EGP) : ";
        is_num(fee);
    } while(isMovieFound(movies,movies_count,movieName));
    
    for(int i = 0; i < size_of_movies; i++)
    {
        if(movies[i].Name.empty())
        {
            movies[i].Name = movieName;
            movies[i].price = price;
            movies[i].fee = fee;
            movies_count++;
            break;
        }
    }
    std::cout << "Successfully added: " << movieName << '\n';
}

// to do while debugging: fix this shitty double enter
// in main menu add,   bool isDateChanged, and sys_days new_date 
bool changeDate(sys_days& new_date) // done
{
    int y, m, d;
    char delimiter1, delimiter2;
    std::string entered_date;
    std::cout << "do you wish to set date manually y/n?: ";
    if (yes_no()) 
    {
        while (true) //infinite loop till broken by return
        {
            std::cout << "specify date in this exact format yyyy/mm/dd : ";
            getline(std::cin, entered_date);
            //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin.clear();
            if (entered_date == "0") return false; //aborts and exits to main menu
            
            std::istringstream iss(entered_date);
            if (iss >> y >> delimiter1 >> m >> delimiter2 >> d && y >= 2025 && delimiter1 == '/' && delimiter2 == '/') 
            {
                new_date = year(y) / month(m) / day(d); //converts date::year_month_day to sys_days, thnx to sir Howard Hinnant
                return true;
            }
            else 
            {
                std::cerr << "wrong format or invalid date, please try again\n";
            }
        }
    }
    else 
    {
        return false; //aborting
    }
}