/*
Bubble Sort
*/

#include <iostream>
using namespace std;

int main()
{
    
    const int size_x = 50;
    const int size_y = 50;

    int array[size_x][size_y];

    for (int x = 0; x < size_x; x++) {
        for (int y = 0; y < size_y; y++) {
            array[x][y] = rand() % 1000;
            cout << array[x][y] << " ";
        }
        cout << endl;
    }

    cout  << "\n\n";
    cout << "Sorted to:";
    cout << "\n\n\n";

    for (int j = 0; j < (sizeof(array) / sizeof(int)); j++) {
        for (int i = 0; i < (sizeof(array) / sizeof(int))-1;) {
            int x1 = i / size_x;
            int y1 = i % size_y;

            i++;

            int x2 = i / size_x;
            int y2 = i % size_y;


            if (array[x1][y1] > array[x2][y2]) {
                swap(array[x1][y1], array[x2][y2]);
            }
        }
    }

    for (int x = 0; x < size_x; x++) {
        for (int y = 0; y < size_y; y++) {
            cout << array[x][y] << " ";
        }
        cout << endl;
    }

}