#include<iostream>

int main() {

    int array1[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int array2[8] = {0, 1, 2, 3, 4, 5, 6, 7};
    int final[20];

    int final_size = (sizeof(array1) + sizeof(array2)) / sizeof(int);
    int array1_size = sizeof(array1) / sizeof(int);
    int array2_size = sizeof(array2) / sizeof(int);

    std::cout << final_size << std::endl;

    int j = 0;
    int k = 0;
    
    for (int i = 0; i < final_size; i++) {
        if (j < array1_size && array1[j] < array2[k]) {
            final[i] = array1[j];
            j++;
        } else if (k < array2_size && array1[j] >= array2[k]) {
            final[i] = array2[k];
            k++;
        }
        else if (j == array1_size) {
            final[i] = array2[k];
            k++;
        }
        else if (k == array2_size) {
            final[i] = array1[j];
            j++;
        }
    }

    for (auto& i : final) {
        std::cout << i << std::endl;
    }

    return 0;
}