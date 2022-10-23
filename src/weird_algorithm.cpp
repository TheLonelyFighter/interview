#include<iostream>

int main() {
// 3→10→5→16→8→4→2→1
    long long n;
    std::cin >> n;


    if (n == 1) {
        std::cout << n << " ";
        return 0;
    }
        do 
            {
                std::cout << n;
                if (n !=1) std::cout <<   " ";
                if (n % 2 == 0)
                    n = n / 2;
                else 
                    n = n * 3 + 1;      
            } while (n != 1);
        
        std::cout << '1';

    
    return 0;
}