/*

Arrays with File Handing
Create a text file and store integer data in it. You have to read the data from the text file and store
it into two-dimensional array of 5x5, then calculate the row-wise sum of two dimensional which
you read from the text file and store the sum in third one dimensional array.



*/


#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

int main()
{
    int row = 5;
    int column = 5;
    
    int array[row][column];
    int total_array[row];

    fstream file;

    //file check in folder 
    file.open("datafile.txt", ios::in);

    int num, digit, total; 
    int counter = 0;

    // This will only accept digits from 0 to 9
    while (counter < 5) 
    { 
    int denominator = 10000;
    file >> num;


    for (int i = 0; i < row; i++)
    {
        digit = num / denominator;
        num = num % denominator;
        array[counter][i] = digit;
        denominator = denominator / 10;
    }

    counter = counter + 1;
    }

    file.close();

    for (int i = 0; i < row; i++)
    {
        total = 0;
        for (int j = 0; j < 5; j++)
        {
            total = total + array[i][j];
        }
        total_array[i] = total;
    }

    for (int i = 0; i < row; i ++)
    {
        cout << total_array[i] << " , ";
    }
    cout<<endl;

    return 0;
}
