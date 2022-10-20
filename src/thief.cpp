#include<iostream>
#include<vector>

int main () {
    // {100,120, 100, 90}
    // {100,      120,       100,     50}
    // {100,       90,         90,      100}
    // { 6, 7, 1, 3, 8, 2, 4 }

    std::vector<int> houses =  {6, 7, 2};

    if (houses.size() == 0) {
        std::cout << "0" << std::endl;
        return 0;
    }
    else if (houses.size() == 1) {
        std::cout << houses[0] << std::endl;
        return 0;
    }

    int J2 = 0;
    int J1 = houses[0];;
    int J0 = 0;
     
    for (int i = 1; i < houses.size(); i++)  {   
     
        J2 = std::max(J1, J0 + houses[i]);
        J0 = J1;
        J1 = J2;

        std::cout << "Current max: " << J2 << std::endl;

        }

    std::cout << "Max cash: " <<  J2 << std::endl;

    return 0;
}