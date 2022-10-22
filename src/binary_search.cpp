#include<iostream>

int main() {
    
    int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int target = 5;
    int left = 0;
    int right = sizeof(array)/sizeof(array[0]) - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (array[mid] == target) {
            std::cout << "Found target at index: " << mid << std::endl;
            return 0;
        }
        else if (array[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    std::cout << "Hello" << std::endl;
    return 0;
}