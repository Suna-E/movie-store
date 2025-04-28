#include "customer.h"

// //-------------------------utilities-----------------------------
// std::string generateId() // done
// {
//     std::string Id = "C#";
//     srand(time(0)); // changes seed
//     for (int i = 1; i <= 4; i++)
//     {
//         Id += std::to_string(rand() % 10); // generates number from 0 -> 9 and adds it
//     }
//     return Id;
// }
// std::string deleteSpaces(std::string& str) //done
// {
//     str.erase(remove(str.begin(),str.end(), ' '), str.end());
//     return str;
// }
// bool checkPhoneNumber(std::string& PhoneNumber) // done
// {
//     PhoneNumber = deleteSpaces(PhoneNumber);
    
//     if (PhoneNumber.length() >= 7 && PhoneNumber.length() <= 15)
//     {
//         for(const char& i : PhoneNumber)
//         {
//             if(!std::isdigit(i))
//             {
//                 return false;
//             }
//         }
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }
// bool checkPhoneNumberRegistered(Customer customers[], int customers_count, std::string& PhoneNumber) // done
// {
//     for(int i = 0; i < customers_count; i++)
//     {
//         if((customers[i].PhoneNumber == PhoneNumber))
//         {
//             return true;
//         }
//     }
//     return false;
// }
// bool checkId(Customer customers[], int customer_count, std::string& id) // done
// {
//     for(int i = 0; i < customer_count; i++)
//     {
//         if(customers[i].Id == id)
//         {
//             return true;
//         }
//     }
//     return false;
// }
// int getCustomersCount(Customer customers[], int size_of_customers) // get customers count at the beginning of the program
// {
//     if(size_of_customers != 0)
//     {
//         int customers_count = 0;
//         for(int i = 0; i < size_of_customers; i++){
//             if(!customers[i].Name.empty())
//             {
//                 customers_count++;
//             }
//         }
//         return customers_count;
//     }
//     else
//     {
//         std::cout << "There are currently no customers on the system!, please add a customers first.\n";
//     }
    
// }
// bool isEmpty(Customer customers[], int customerIndex) // done
// {
//     int count = 0;
//     for(int i = 0; i < limit; i++)
//     {
//         if(customers[customerIndex].CurrentlyRentedMovies[i].empty()) count++; 
//     } 
//     if(count == limit)
//     {
//         return true;
//     }
//     return false;
// }
// //-------------------------utilities-----------------------------

void addNewCustomer(Customer customers[], int size_of_customers, int& customers_count) // done
{
    std::string name, phonenum, id;
    std::cout << "Enter Customer name: ";
    getline(std::cin, name);
    std::transform(name.begin(), name.end(), name.begin(), tolower);
    
    do 
    {
        std::cout << "Enter Customer phone: +";
        getline(std::cin, phonenum);
        
        if(!checkPhoneNumber(phonenum))
        {
            std::cout << "Invalid phone number!\n";
        }
        else if (checkPhoneNumberRegistered(customers, customers_count, phonenum))
        {
            std::cout << "This phone number is already registered!\n";
        }

    } while(!checkPhoneNumber(phonenum) && !checkPhoneNumberRegistered(customers, customers_count, phonenum));
    
    do
    {
        std::this_thread::sleep_for(std::chrono::seconds(1)); // ---> sleep for 1 sec.
        id = generateId();

    } while(checkId(customers, customers_count, id));


    for(int i = 0; i < size_of_customers; i++){
        if(customers[i].Name.empty())
        {
            customers[i].Name = name;
            customers[i].PhoneNumber = phonenum;
            customers[i].Id = id;
            customers_count++;
            break;
        }   
    }
    std::cout << "Successfully added " << name << '\n';
}
void listCustomers(Customer customers[], int customers_count) // done
{
    if(customers_count !=0)
    {
        int num = 1;
        std::cout << "\n-----------------------------\n\n";
        for (int i = 0; i < customers_count; i++)
        {
            std::cout << num << ".\n";
            std::cout << "Name: " << customers[i].Name << '\n';
            std::cout << "Customer ID: " << customers[i].Id << '\n';
            std::cout << "Phone Number: " << customers[i].PhoneNumber << '\n';

            if(!(isEmpty(customers, i)))
            {
                std::cout << "Currently Renting: ";
                for (std::string j : customers[i].CurrentlyRentedMovies)
                {
                    if (!j.empty()) 
                    { 
                        std::cout << j << " ";
                    }
                }
            }
            else
            {
                std::cout << "Currently Renting: none\n";
            }
            std::cout << "\n";
    
            if (!customers[i].PreviouslyRentedMovies.size() == 0)
            {
                std::cout << "has rented: ";
    
                for (std::string j : customers[i].PreviouslyRentedMovies)
                {
                    if (!j.empty())
                    {
                        std::cout << j << " ";
                    }
                }
                std::cout << "\n";
            }
            std::cout << "\n";
            num++;
        }
        std::cout << "-----------------------------\n";
    }
    else
    {
        std::cout << "There are currently no customers on the system!, please add a customer first.\n";
    }
}
