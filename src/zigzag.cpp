#include<iostream>

/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
(you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R

And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:
*/

int main () {
    char string[] = "PAYPALISHIRING";
    const uint rows = 5;
    const uint string_size = sizeof(string) / sizeof(char);
    const uint columns = 1000; 
    char m[rows][columns];

    int j = 2;
    int index = 0;
    for(int i = 0; i < rows; i++) {

        std::cout << string[i];
        
        index  =  j * (rows - 1) * i;
        if (index < string_size) {
            std::cout << string[index];
            j++;
        }
    }

    return 0;

    for (int i = 0; i < rows; i++) 
        for (int j = 0; j < columns; j++) 
            m[i][j] = ' ';

    int index = 0;
    for (int i = 0; i < columns; ++i) {
        for (int j = 0; j < rows; ++j) {
            if (index < string_size) {
                    m[j][i] = string[index];
                    index++;
            } else break;
        }
        for (int k = rows - 2; k > 0; --k) {
            if (index < string_size) {
                m[k][i + 1] = string[index];
                index++;
                i++;
            }
            else break;
        }
        // for (int i = 0; i < rows; ++i) {
        //     for (int j = 0; j < columns; ++j) 
        //         std::cout << m[i][j];
        // std::cout << std::endl;
        // }

        //  std::cout << std::endl << "*************" << std::endl;
        
    }


    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) 
            if (m[i][j] != ' ')
                std::cout << m[i][j];
    }
        
    return 0;
}