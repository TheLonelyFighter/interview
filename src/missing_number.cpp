#include<iostream>

bool a[200002];

int main() 
{   
    int n = 2;
    int element;
    std::cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        std::cin >> element;
        a[element]++;
    }

    for (int i = 1; i <= n; i++)
    {   
        if (a[i] == false) {
            std::cout << i;
            return 0;
        }
        //std::cout << a[i] << " ";
    }
    return 0;
}