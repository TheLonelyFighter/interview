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
    std::string result = "";

    // Efficient solution, time = O(n), space = O(1)
    for (int rowNum = 0; rowNum < rows; rowNum++)
    {
        int i = rowNum;
        bool up = true;
        // Iterate i till s.length() - 1
        while (i < string_size)
        {
 
            result += string[i];
 
            // Check is rowNum is 0 or n - 1
            if (rowNum == 0 || rowNum == rows - 1)
            {
                i += (2 * rows - 2);
            }
            else
            {
                if (up)
                {
                    i += (2 * (rows - rowNum) - 2);
                }
                else
                {
                    i += rowNum * 2;
                }
                up ^= true;
            }
        }
    }
    std::cout<<result<<std::endl;

    return 0;

    //intuitive, inefficient solution, time = O(n^2), space = O(n^2)
    for (int i = 0; i < rows; i++) 
        for (int j = 0; j < columns; j++) 
            m[i][j] = ' ';

    index = 0;
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