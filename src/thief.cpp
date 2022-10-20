#include<iostream>
#include<vector>

int main () {
    // {100,120, 100, 90}
    // {100,      120,       100,     50}
    // {100,       90,         90,      100}

    std::vector<int> houses =  {100,120, 100, 90, 1000, 1000};

    int max = 0;
    int J3 = 0;
    int J2 = 0;
    int J1 = 0;

     
    J1 = houses[0];
    J2 = std::max(J1, houses[1]);

    for (int i = 2; i < houses.size(); i++)  {   
     
        J3 = std::max(J2, J1 + houses[i]);
        J1 = J2;
        J2 = J3;

        std::cout << "Current max: " << J3 << std::endl;

        }

    std::cout << "Max cash: " <<  J3 << std::endl;

    return 0;
}