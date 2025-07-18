#include "payment.h"
#include "movie.h"
#include "admin.h" // contains system_date, cashRegister
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <thread>
#include <chrono>
#include "Howard_Hinnant/include/date/date.h"

extern date::sys_days system_date;

bool isDigit(std::string& str) // done
{
    for(const char& digit : str)
    {
        if(!std::isdigit(digit)) return false;
    }
    return true;
}

bool validateCCV(std::string& ccv) // done
{
    if(ccv.length() < 5 && ccv.length() > 2)
    {
        for(const char digit : ccv)
        {
            if(!std::isdigit(digit)) return false;
        }
        return true;
    }
    
    return false;
} 

//Luhn algorithm
bool validateCreditCard(std::string& creditCard) // done
{
    if(isDigit(creditCard) && (creditCard.length() == 16)) 
    {
        std::vector<int> creditCardNum;
        for(int i = 0; i < creditCard.length(); i++)
        {
            creditCardNum.push_back((creditCard[i] - '0')); // converts a char into int.
        }
        
        for(int i = creditCard.length() - 2; i >= 0; i -= 2)
        {
            int temp = creditCardNum[i];
            temp *= 2;
            if(temp > 9) temp = (temp % 10) + 1; // if its 10 or greater split it into two digits and add it ex(18) ---> 1 + 8 = 9.
            creditCardNum[i] = temp;
        }
    
        int total = 0;
    
        for(int num : creditCardNum)
        {
            total += num;
        }
    
        if(total % 10 == 0) return true;
    }

    return false;
}

bool isCreditCardRegistered(customer customers[], int customers_count, std::string& creditCard) // done
{
    if(!creditCard.empty())
    {
        for(int i = 0; i < customers_count; i++)
        {
            if(customers[i].creditcard.cardNumber == creditCard) return true;
        }
    }
    return false;
}

void addCreditCard(customer customers[], int customers_count, std::string& id) // done
{
    int customerIndex = getCustomerIndex(customers, customers_count, id);
    std::string card, ccv, date;
    do
    {
        std::cout << "Enter your credit card number: ";
        getline(std::cin, card);
        card = deleteSpaces(card);

        if(card == "0") return;
        if(!validateCreditCard(card))
        {
            std::cout << "Invalid credit card!\n";
            continue;
        }
        else if(isCreditCardRegistered(customers, customers_count, card))
        {
            std::cout << "This credit card is already registered!\n";
        }
    } while(!validateCreditCard(card) || isCreditCardRegistered(customers, customers_count, card));

    do
    {
        std::cout << "Enter CCV: ";
        getline(std::cin, ccv);
        ccv = deleteSpaces(ccv);
        
        if(ccv == "0") return;
        if(!validateCCV(ccv)) 
        {
            std::cout << "Invalid CCV!\n";
        }
    } while(!validateCCV(ccv));

    date::year y;
    date::month m;
    date::year_month yy_mm;
    date::year_month_day system = system_date; // conversion from sys_days to a year_month_day var (necessary)
    int y_val, m_val, year_int, century;
    char del;
    bool valid = false;
    year_int = system.year().operator int();
    century = year_int / 100;


    while(!valid)
    {
        std::cout << "Enter expiry date: yy/mm: ";
        getline(std::cin, date);
        date = deleteSpaces(date);

        if(date == "0") return;

        std::istringstream iss(date);
        if(iss >> y_val >> del >> m_val && (del == '/'))
        {
            y_val += (century * 100);
            y = date::year(y_val);
            m = date::month(m_val);
            if(m.ok() && y >= system.year())   //check if works
            {
                yy_mm = y / m;
            }
            else
            {
                std::cout << "Wrong date or format!\n";
                valid = false;
                continue;
            }
        }
        else
        {
            std::cout << "Wrong date or format!\n";
            valid = false;
            continue;
        }
    }

    customers[customerIndex].creditcard.cardNumber = card;
    customers[customerIndex].creditcard.ccv = ccv;
    customers[customerIndex].creditcard.yy_mm = yy_mm;
    std::cout << "Successfully added credit card\n\n";
}

void create_SC(customer cust[], int customers_count, std::string& id) 
{
    std::string passwrd, again;
    int Index = getCustomerIndex(cust, customers_count, id);
    if (!cust[Index].SC) 
    {
        cust[Index].SC = true;
        do
        {
            std::cout << "create a strong password (no spaces): ";
            getline(std::cin, passwrd);
        } while(passwrd.find(" ") != passwrd.npos); // continues asking if space is found
        if(passwrd == "0") return;

        do
        {
            std::cout << "re-enter the password: ";
            getline(std::cin, again);
        } while (passwrd != again);
        cust[Index].SC_passwrd = passwrd;
    }
    else 
    {
        std::cerr << "This account already has a SC card\n";
    }
}

void reset_SC_passwrd(customer cust[], int customers_count, std::string& id) {
    std::string passwrd, old_passwrd;
    int Index = getCustomerIndex(cust, customers_count, id);
    
    if (cust[Index].SC) 
    {
        std::cout << "enter previous password: ";
        getline(std::cin, old_passwrd);
        if(passwrd == "0") return;
        while (old_passwrd != cust[Index].SC_passwrd) 
        {
            if (old_passwrd == "0") return;
            std::cerr << "wrong password, try again";
            std::cout << "enter previous password: ";
            getline(std::cin, old_passwrd);
        }
        do
        {
            std::cout << "enter New password (no spaces): ";
            getline(std::cin, passwrd);
        } while (passwrd.find(" ") != passwrd.npos);
        if(passwrd == "0") return;
        
        cust[Index].SC_passwrd = passwrd;
        std::cout << "password changed successfully\n";
    }
    else 
    {
        std::cerr << "this account doesn't have a SC card, make one first\n";
    }
}

void charge_SC(customer cust[], int customers_count, std::string& id) {
    int Index = getCustomerIndex(cust, customers_count, id);
    double amount;

    std::cout << "enter amount you want to charge with: ";
    is_num(amount); // if 0 nothing will happen, and will go back to main menu
    if (amount == 0) {
        std::cout << "\ncanceling\n";
        std::this_thread::sleep_for(std::chrono::seconds(t));
        return;
    }
    cust[Index].SC_balance += amount;
    std::cout << "\nsuccessfully charged\n";
}

// if payment == true, cust[index].coins += generate_coins();
int generate_coins() // from 1 to 10
{
    int coins = 1;
    srand(time(0));
    coins += (rand() % 10);
    return coins;
}

double amount2pay(movie& mov, bool& damaged) 
{
    int fee_days = validateDue(mov);
    int price_days = mov.rentalDays;
    double amount = 0;
    if (mov.due)
    {
        amount = mov.price * price_days + mov.fee * fee_days;
    }
    else
    {
        amount = mov.price * price_days;
    }
    std::cout << "is movie damaged y/n? ";
    if (yes_no()) {
        amount += 500; //constant damage fee of 500 EGP
        damaged = true;
    }
    return amount;
}

bool pay(double& cashRegister, customer customers[], int customers_count, 
         std::string& id, movie& movie) 
{
    int customerIndex = getCustomerIndex(customers, customers_count, id);
    int ans;
    bool paid = false, damaged = false;
    std::string SC_password, ccv, date;
    
    double SC_amount, in_coins, creditCardFees;

    double amount = amount2pay(movie, damaged); //due status is set now
    SC_amount = amount * 0.9; //10% discount on all movies
    creditCardFees = amount * 0.05;  // credit card fees 5%

    in_coins = 50; //even if coins payment unavailable no problem, any movie costs 50 coins as long as it is not due
    do
    {
        std::cout << "\nYou have : " << customers[customerIndex].coins << " coins\n\n";
        std::cout << "\nSC balance : " << customers[customerIndex].SC_balance << " EGP\n\n"; // if doesn't have it will display zero
        
        std::cout << "1. in cash = " << amount 
                  << "$\n2. via credit card = " << amount + creditCardFees
                  << "$\n3. via SC card = " << SC_amount 
                  << "$\n4. redeem coins";

        if (movie.due || damaged) 
        {
            std::cout << "(unavailable)\n"; // for coins i mean
            std::cout << "\nconsidering that the movie is damaged a fine of 500 EGP will be added, and payment via SC and coins are unavailable\n\n"; // for coins i mean
        }
        else 
        {
            std::cout << " = " << in_coins << " coins\n"; // for coins
        }

        std::cout << "Enter choosen method: ";
        is_num(ans);
        if (ans == 0) return false;

        switch (ans)
        {
        case 1:
        {
            std::cout << "Opening cash register!\n";
            cashRegister += amount;
            paid = true;
            std::this_thread::sleep_for(std::chrono::seconds(t));
            std::cout << "thanks for choosing our store!\n";
            std::this_thread::sleep_for(std::chrono::seconds(t));
            return true;
        }
        case 2:
        {
            if (!customers[customerIndex].creditcard.cardNumber.empty())
            {
                std::cout << "Paying with: " << customers[customerIndex].creditcard.cardNumber << '\n';
                do
                {
                    std::cout << "Enter ccv: ";
                    getline(std::cin, ccv);
                    ccv = deleteSpaces(ccv);

                    if (ccv == "0") break;
                    if (customers[customerIndex].creditcard.ccv != ccv)
                    {
                        std::cout << "Wrong ccv!\n";
                    }
                } while (customers[customerIndex].creditcard.ccv != ccv);
                if (ccv == "0") break;

                date::year_month yy_mm;
                date::year y;
                date::month m;
                date::year_month_day system = system_date;
                int y_val, m_val, year_int, century;
                char del;
                year_int = system.year().operator int();
                century = year_int/100;

                do
                {
                    std::cout << "Enter expiry date: yy/mm: ";

                    getline(std::cin, date);
                    date = deleteSpaces(date);

                    if (date == "0") break;

                    std::istringstream iss(date);
                    if (iss >> y_val >> del >> m_val && del == '/')
                    {
                        y_val += (century * 100);
                        y = date::year(y_val);
                        m = date::month(m_val);
                        if (m.ok())
                        {
                            yy_mm = y / m;
                            if (yy_mm == customers[customerIndex].creditcard.yy_mm)
                            {
                                cashRegister += (amount + creditCardFees);
                                paid = true;
                                std::cout << "Transaction completed!\n\n";
                                std::cout << "Thanks for choosing our store!\n\n";
                                std::this_thread::sleep_for(std::chrono::seconds(t));
                                return true;
                            }
                            else
                            {
                                std::cout << "Wrong date or format!\n";
                            }
                        }
                        else
                        {
                            std::cout << "Wrong date or format!\n";
                        }
                    }
                } while (yy_mm != customers[customerIndex].creditcard.yy_mm);
                if (date == "0") break;
            }
            else
            {
                std::cout << "You don't have a credit card. Do you want to add one? (y/n): ";
                if (yes_no())
                {
                    addCreditCard(customers, customers_count, id);
                    if (customers[customerIndex].creditcard.cardNumber.empty())
                    {
                        break; // breaks from case. display the payments again
                    }
                    cashRegister += (amount + creditCardFees);
                    paid = true;
                    std::cout << "Transaction completed!\n\n";
                    std::cout << "Thanks for choosing our store!\n\n";
                    std::this_thread::sleep_for(std::chrono::seconds(t));
                    return true;
                }
                else
                {
                    std::cout << "\nchoose a different method to pay\n";
                }
            }
            break;
        }
        case 3:
        {
            if (!damaged) 
            {
                if (customers[customerIndex].SC)
                {
                    std::cout << "Enter password: ";
                    getline(std::cin, SC_password);

                    if (SC_password == "0") break;
                    while (customers[customerIndex].SC_passwrd != SC_password)
                    {
                        std::cerr << "wrong password try again: ";
                        getline(std::cin, SC_password);
                    }
                }
                else
                {
                    std::cout << "No SC card detected, would you like to make one y/n? ";
                    if (yes_no())
                    {
                        create_SC(customers, customers_count, id);
                        charge_SC(customers, customers_count, id);
                        std::cout << "\nSC card created successfully!\n\n";
                        std::this_thread::sleep_for(std::chrono::seconds(t));
                    }
                    else
                    {
                        std::cerr << "\nchoose a different method to pay\n";
                        break;
                    }
                }
                if (customers[customerIndex].SC_balance > SC_amount)
                {
                    customers[customerIndex].SC_balance -= SC_amount;
                    cashRegister += SC_amount;
                    paid = true; //not really necessary but what the heck,keep it just in case
                    std::cout << "\nTransaction completed!\n\n";
                    std::cout << "Thanks for choosing our store!\n\n";
                    std::this_thread::sleep_for(std::chrono::seconds(t));
                    return true;
                }
                else
                {
                    std::cerr << "\nnot enough balance in your SC card, use a different method\n\n";
                    std::this_thread::sleep_for(std::chrono::seconds(t));
                }
            }
            else {
                std::cerr << "\nmovie is due or damaged, paying via SC is unavailable\n";
                std::this_thread::sleep_for(std::chrono::seconds(t));
            }
            break;
        }
        case 4: //no need for extra safety
        {
            if (!movie.due && !damaged) 
            {
                if (customers[customerIndex].coins > in_coins)
                {
                    customers[customerIndex].coins -= in_coins;
                    paid = true;
                    std::cout << "\nTransaction completed!\n\n";
                    std::cout << "Thanks for choosing our store!\n\n";
                    std::this_thread::sleep_for(std::chrono::seconds(t));
                    return true;
                }
                else
                {
                    std::cout << "\nNot enough coins, use a different method\n\n";
                    std::this_thread::sleep_for(std::chrono::seconds(t));
                }
            }
            else {
                std::cerr << "\nmovie is due or damaged, paying with coins is unavailable\n";
                std::this_thread::sleep_for(std::chrono::seconds(t));
            }
            break;
        }
        default:
            std::cout << "\nInvalid choice!\n";
            std::this_thread::sleep_for(std::chrono::seconds(t));
            break;
        }
    } while (ans > 4 || ans <= -1 || !paid);
}