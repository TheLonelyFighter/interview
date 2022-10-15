#include<vector>
#include<iostream>
#include<algorithm>

int main()
{
    std::vector<int> v = {3,5,2,1,4};

    std::cout << "Initial vector" << std::endl;
    for (auto i : v)
        std::cout << i << std::endl;

    // sort the vector in descending order
    std::sort(v.begin(), v.end(), std::greater<int>());
    
    // reverse the vector
    std::reverse(v.begin(), v.end());
    
    std::cout << "After sort and reverse" << std::endl;
    for (auto i : v)
        std::cout << i << std::endl;
}