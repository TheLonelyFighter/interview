#include<iostream>
#include<vector>


/* Problem proposed during Rapyuta's programming interview. 

There are N houses built in a line, each of which contains some value in it.
A thief is going to steal the maximal value of these houses, 
but he can’t steal in two adjacent houses because 
the owner of the stolen houses will tell his two neighbors left and right sides. 
The task is to find what is the maximum stolen value.

Input: hval[] = {6, 7, 1, 3, 8, 2, 4}
Output: 19
Explanation: The thief will steal 6, 1, 8 and 4 from the house.

Input: hval[] = {5, 3, 4, 11, 2}
Output: 16
Explanation: Thief will steal 5 and 11
*/
int main () {
    // {100,120, 100, 90}
    // {100,      120,       100,     50}
    // {100,       90,         90,      100}
    // {5, 3, 4, 11, 2}
    // { 6, 7, 1, 3, 8, 2, 4 }

    std::vector<int> houses =  { 6, 7, 1, 3, 8, 2, 4 };

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