#include "utilities.h"


//-------------------------general----------------------------
void is_num(int& input) 
{
	while(true)
	{
		std::cin >> input;
		if (std::cin.fail()) 
		{
			std::cout << "Invalid input. Please try again: ";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else 
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return;
		}
	}
}
void is_num(double& input)
{
	while (true)
	{
		std::cin >> input;
		if (std::cin.fail())
		{
			std::cout << "Invalid input. Please try again: ";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else 
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return;
		}
	}
}
bool yes_no() 
{
	char ans;
	do 
	{
		std::cin >> ans;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (std::cin.fail()) 
		{
			std::cerr << "Input error occurred.\n";
			continue;
		}
		else if (!(ans == 'y' || ans == 'Y' || ans == 'n' || ans == 'N')) 
		{
			std::cout << "Invalid input, please enter a valid choice" << std::endl;
		}
	} while (std::cin.fail() || !(ans == 'y' || ans == 'Y' || ans == 'n' || ans == 'N'));
	
	if (ans == 'y' || ans == 'Y') 
	{
		return true;
	}
	else 
	{
		return false; //abort 
	}
}
//------------------------------------------------------------

//-------------------------Customers--------------------------
std::string generateId() // done
{
    std::string Id = "C#";
    srand(time(0)); // changes seed
    for (int i = 1; i <= 4; i++)
    {
        Id += std::to_string(rand() % 10); // generates number from 0 -> 9 and adds it
    }
    return Id;
}
std::string deleteSpaces(std::string& str) //done
{
    str.erase(remove(str.begin(),str.end(), ' '), str.end());
    return str;
}
bool checkPhoneNumber(std::string& PhoneNumber) // done
{
    PhoneNumber = deleteSpaces(PhoneNumber);
    
    if (PhoneNumber.length() >= 7 && PhoneNumber.length() <= 15)
    {
        for(const char& i : PhoneNumber)
        {
            if(!std::isdigit(i))
            {
                return false;
            }
        }
        return true;
    }
    else
    {
        return false;
    }
}
bool checkPhoneNumberRegistered(Customer customers[], int customers_count, std::string& PhoneNumber) // done
{
    for(int i = 0; i < customers_count; i++)
    {
        if((customers[i].PhoneNumber == PhoneNumber))
        {
            return true;
        }
    }
    return false;
}
bool checkId(Customer customers[], int customer_count, std::string& id) // done
{
    for(int i = 0; i < customer_count; i++)
    {
        if(customers[i].Id == id)
        {
            return true;
        }
    }
    return false;
}
int getCustomersCount(Customer customers[], int size_of_customers) // get customers count at the beginning of the program
{
    if(size_of_customers != 0)
    {
        int customers_count = 0;
        for(int i = 0; i < size_of_customers; i++){
            if(!customers[i].Name.empty())
            {
                customers_count++;
            }
        }
        return customers_count;
    }
    else
    {
        std::cout << "There are currently no customers on the system!, please add a customers first.\n";
    }
    
}
bool isEmpty(Customer customers[], int customerIndex) // done
{
    int count = 0;
    for(int i = 0; i < limit; i++)
    {
        if(customers[customerIndex].CurrentlyRentedMovies[i].empty()) count++; 
    } 
    if(count == limit)
    {
        return true;
    }
    return false;
}
//-------------------------------------------------------------


//-------------------------Movies------------------------------
bool isCustomerFound(Customer customers[], int customers_count, std::string& id) // done
{
    for(int i = 0; i < customers_count; i++)
    {
        if(customers[i].Id == id) return true;
    }
    return false;
}
int getCustomerIndex(Customer customers[], int customers_count, std::string& id) // done
{
    int customerIndex = 0;
    for(int i = 0; i < customers_count; i++)
    {
        if(customers[i].Id == id)
        {
            return customerIndex;
        }
        customerIndex++;
    }
}
bool isMovieFound(movie movies[], int movies_count, std::string& movieName) // done
{
    for(int i = 0; i < movies_count; i++)
    {
        if(movies[i].Name == movieName) return true;
    }
    return false;
} 
int getMovieIndex(movie movies[], int movies_count, std::string& movieName) // done
{
    int movieIndex = 0;
    for(int i = 0; i < movies_count; i++)
    {
        if(movies[i].Name == movieName)
        {
            return movieIndex;
        }
        movieIndex++;
    }
}
bool isMovieRentedByCustomer(Customer customers[], int customers_count ,std::string& id, std::string& movieName) // done
{
    int customerIndex = getCustomerIndex(customers, customers_count, id);
    for (int i = 0; i < limit; i++)
    {
        if(customers[customerIndex].CurrentlyRentedMovies[i] == movieName) return true;
    }
    
    return false;
}
bool isCurrentlyRentedEmpty(Customer customers[], int customerIndex) // done
{
    for(int i = 0; i < limit; i++)
    {
        if(customers[customerIndex].CurrentlyRentedMovies[i].empty()) return true; 
    } 
    
    return false;
}
int getMoviesCount(movie movies[], int size_of_movies) // done
{
    if(size_of_movies != 0)
    {
        int movies_count = 0;
        for (int i = 0; i < size_of_movies; i++)
        {
            if(!movies[i].Name.empty())
            {
                movies_count++;
            }
        }
        return movies_count;
    }
    else
    {
        std::cout << "There are currently no movies on the system!, please add a movie first.\n";
    }
}
//-------------------------------------------------------------


void mainMenu(Customer customers[], int size_of_customers, movie movies[], int size_of_movies) 
{ 
    int customers_count = getCustomersCount(customers, size_of_customers);
    int movies_count = getMoviesCount(movies, size_of_movies);
    bool valid = false,isDateChanged = false;
    int choice;
    std::string check;
    
    sys_days new_date, today;
    auto now = std::chrono::system_clock::now();
    today = floor<days>(now);
    year_month_day system_date = today;

    std::string menu[] = {
        "\n-----------------------------\n",
        "press  1: Rent a movie",
        "press  2: Rate a movie",
        "press  3: Edit a rating",
        "press  4: Return a movie",
        "press  5: List all customers",
        "press  6: Add a customer",
        "press  7: List all movies",
        "press  8: List rented movies",
        "press  9: List unrented movies",
        "press  10: List due accounts",
        "press  11: List top 10 rented movies",
        "press  12: List top 10 rated movies"
    };
    
    check = login();
    while (check=="user" || check=="admin") //infinite loop till log out or termination
    {
        if (isDateChanged) 
        {
            std::cout << "\n\ncurrent date: " << new_date;
        }
        else 
        {
            std::cout << "\n\ncurrent date: " << today;
        }
        
        for(std::string menu : menu)
        {
            std::cout << menu << '\n';
        }
        
        if(check=="user")
        {
            std::cout << "press  13: Log out\n"; // done
        }
        else if (check=="admin") 
        {
            std::cout << "press  13: Add a movie\n"; // done
            std::cout << "press  14: Delete a movie\n"; // done
            std::cout << "press  15: Delete a customer\n"; // done
            std::cout << "press  16: set date manually\n"; // done
            std::cout << "press  17: switch user account\n"; // done
        }
        std::cout << "press  0: Exit\n";
        std::cout << "\nat any point in time, if you wish to go back to main menu enter \"0\"\n";
        std::cout << "-----------------------------\n";
        while (!valid) 
        {
            std::cin >> choice;
            if ((std::cin.good() && choice <= 13 && choice > -1) || (std::cin.good() && check=="admin" && choice <= 17 && choice > -1)) 
            {
                valid = true;
            }
            else 
            {
                std::cerr << "Invalid choice. Please enter a valid choice: ";
                valid = false;
            }
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        switch (choice)
        {
        case 0: // exit
            return;
        case 1: // rent
            rent(customers, customers_count, movies, movies_count, system_date);
            std::this_thread::sleep_for(std::chrono::seconds(2));
            break;
        case 2: // rate
        {
            std::string movieName,id;
            std::transform(id.begin(), id.end(), id.begin(), toupper); // c# ---> C#
            std::transform(movieName.begin(), movieName.end(), movieName.begin(), tolower);
            
            do
            {
                std::cout << "Enter movie name: ";
                getline(std::cin, movieName);
                if(!isMovieFound(movies,movies_count,movieName))
                {
                    std::cout << "This film doesn't exist! please try again.\n";
                    continue;
                }
                std::cout << "Enter customer id: ";
                getline(std::cin, id);
                if(!isCustomerFound(customers,customers_count,id))
                {
                    std::cout << "Wrong ID! please try again.\n";
                }
            } while(!isCustomerFound(customers,customers_count,id) || !isMovieFound(movies,movies_count,movieName));

            bool done = rate(movies,movies_count,movieName, customers,customers_count,id);
            while (!done)
            {
                done = rate(movies,movies_count,movieName, customers,customers_count,id);
            }
            
            std::this_thread::sleep_for(std::chrono::seconds(2));
            break;
        }
        case 3: // edit rate
        {
            std::string movieName,id;
            std::transform(id.begin(), id.end(), id.begin(), toupper); // c# ---> C#
            std::transform(movieName.begin(), movieName.end(), movieName.begin(), tolower);
            
            do
            {
                std::cout << "Enter movie name: ";
                getline(std::cin, movieName);
                if(!isMovieFound(movies,movies_count,movieName))
                {
                    std::cout << "This film doesn't exist! please try again.\n";
                    continue;
                }
                std::cout << "Enter customer id: ";
                getline(std::cin, id);
                if(!isCustomerFound(customers,customers_count,id))
                {
                    std::cout << "Wrong ID! please try again.\n";
                }
            } while(!isCustomerFound(customers,customers_count,id) || !isMovieFound(movies,movies_count,movieName));

            bool done = editRating(movies,movies_count,movieName, customers,customers_count,id); 
            while(!done)
            {
                done = editRating(movies,movies_count,movieName, customers,customers_count,id);
            }
            std::this_thread::sleep_for(std::chrono::seconds(2));
            break;
        }
        case 4: // return a movie
        {
            std::string id;
            std::transform(id.begin(), id.end(), id.begin(), toupper);
            do
            {
                std::cout << "Enter customer id: ";
                getline(std::cin, id);
                if(!isCustomerFound(customers,customers_count,id))
                {
                    std::cout << "This customer doesn't exist! Please try again.\n";
                }
            } while(!isCustomerFound(customers,customers_count,id));
            returnMovie(customers,customers_count,id, movies, movies_count, isDateChanged, new_date);
            break;
        }            
        case 5: // list all customer
            listCustomers(customers, customers_count);
            break;
        case 6: // add new customer
            addNewCustomer(customers, size_of_customers, customers_count);
            std::this_thread::sleep_for(std::chrono::seconds(2));
            break;
        case 7: // list all movies
            ListMovies(movies, movies_count);
            break;
        case 8: // list rented
            listRented(movies, movies_count);
            break;
        case 9: // list unrented
            ListUnrented(movies, movies_count);
            break;
        case 10: // list due accounts
            ListDueAccounts(movies, movies_count, customers, customers_count, isDateChanged, new_date);
            break;
        case 11: // top 10 rented
            ListTopRented(movies, movies_count);
            break;
        case 12: // top 10 rated
            ListTopRated(movies, movies_count);
            break;
        case 13: // log out for user --- add new movie for admin.
        {
            if(check=="user")
            {
                check = login();
                std::this_thread::sleep_for(std::chrono::seconds(2));
            }
            else if (check=="admin")
            {
                addNewMovie(movies, size_of_movies, movies_count);
                std::this_thread::sleep_for(std::chrono::seconds(2));
            }
            break;
        }
        case 14: // delete movie
        {
            std::string movieName;
            std::transform(movieName.begin(), movieName.end(), movieName.begin(), tolower);
            do
            {
                std::cout << "Enter movie name: ";
                getline(std::cin, movieName);
                if(!isMovieFound(movies,movies_count,movieName))
                {
                    std::cout << "This film doesn't exist! please try again.\n";
                }
            } while(!isMovieFound(movies, movies_count, movieName));
            
            deleteMovie(movies, movies_count, movieName);
            std::this_thread::sleep_for(std::chrono::seconds(2));
            break;
        }
        case 15: // delete customer
        {
            std::string id;
            std::transform(id.begin(), id.end(), id.begin(), toupper);
            do
            {
                std::cout << "Enter customer id: ";
                getline(std::cin, id);
                if(!isCustomerFound(customers,customers_count,id))
                {
                    std::cout << "This customer doesn't exist! Please try again.\n";
                }
            } while(!isCustomerFound(customers,customers_count,id));
            
            deleteCustomer(customers, customers_count, id);
            std::this_thread::sleep_for(std::chrono::seconds(2));
            break;
        }
        case 16:
            isDateChanged = changeDate(new_date);
            std::this_thread::sleep_for(std::chrono::seconds(2));
            break;
        case 17: // logout for admin
            check = login();
            std::this_thread::sleep_for(std::chrono::seconds(2));
            break;
        default:
            std::cerr << "Validation error in the main menu function, please contact your IT provider\nexiting program in 2 seconds";
            std::this_thread::sleep_for(std::chrono::seconds(2));
            return;
        }
        valid = false; //allows you to retake input from usr
    }
}
