#include "utilities.h"

Customer cust[] =
{
    {"Alice Thompson", "555-123-1000", "C001", {"Inception", "The Matrix", "Avatar"}, {"Titanic", "The Dark Knight", "The Godfather"}},
    {"Bob Martin", "555-123-1001", "C002", {"Avengers", "Spiderman", "", "", ""}, {"Iron Man", "Black Panther"}, {{"Avengers", 10}, {"Spiderman", 8}}},
    {"Charlie Davis", "555-123-1002", "C003", {"The Lion King", "Frozen", "Moana", "", ""}, {"Aladdin", "Beauty and the Beast", "Mulan"}, {{"The Lion King", 9}, {"Frozen", 7}}},
    {"Diana Clark", "555-123-1003", "C004", {"Titanic", "The Dark Knight", "Inception", "Avatar", ""}, {"The Matrix", "Jurassic Park"}, {{"Titanic", 10}, {"Inception", 9}, {"The Dark Knight", 9}}},
    {"Edward Lewis", "555-123-1004", "C005", {"Iron Man", "Black Panther", "Doctor Strange", "", ""}, {"The Lion King", "Finding Nemo"}, {{"Iron Man", 8}, {"Black Panther", 9}}},
    {"Fiona Baker", "555-123-1005", "C006", {"The Godfather", "The Shawshank Redemption", "Pulp Fiction", "", ""}, {"The Godfather", "Pulp Fiction", "The Shawshank Redemption"}, {{"The Godfather", 10}, {"Pulp Fiction", 9}}},
    {"George Allen", "555-123-1006", "C007", {"Star Wars", "The Lord of the Rings", "The Hobbit", "", ""}, {"Star Wars", "The Matrix"}, {{"Star Wars", 8}, {"Lord of the Rings", 9}}},
    {"Hannah Evans", "555-123-1007", "C008", {"Jurassic Park", "King Kong", "Jaws", "", ""}, {"Jurassic Park", "King Kong", "The Meg"}, {{"Jurassic Park", 9}, {"King Kong", 7}}},
    {"Isaac Wilson", "555-123-1008", "C009", {"The Dark Knight Rises", "Interstellar", "Inception", "", ""}, {"Inception", "Interstellar", "The Prestige"}, {{"The Dark Knight Rises", 8}, {"Interstellar", 10}}},
    {"Julia Scott", "555-123-1009", "C010", {"Beauty and the Beast", "Frozen", "Aladdin", "Coco", ""}, {"The Jungle Book", "Frozen", "Moana"}, {{"Beauty and the Beast", 9}, {"Frozen", 8}}}
};
Customer c[10] = {"loai", "1212121212", "1234", {"movie1", "movie2"}};
movie m[10] = {"movie1", "loai", 3, 100, 10, 12, true, false, {}, 2025_y/5/12};

int main()
{
    mainMenu(c,10,m,10);


    // int count = 1, ans, index=0;
    // int i[] = {7,0,0,0,0,0,0,1};
    // for(int j : i)
    // {
    //     if(j != 0)
    //     {
    //         std::cout << count << ':' << j << '\n';
    //         count++;
    //     }
    // }
    // std::cout << count << '\n';
    // std::cin >> ans;
    // std::cout << "--------------------------\n";
    // count = 1;
    // for(int j : i)
    // {
    //     if(j != 0)
    //     {
    //         std::cout << count << ':' << j << '\n';
    //         if(ans == count)
    //         {
    //             std::cout << ans << ':' << j << '\n';
    //             break;
    //         }
    //         count++;
    //     }
    //     index++;
    // }
    
    // std::cout << i[index] << '\n';
}