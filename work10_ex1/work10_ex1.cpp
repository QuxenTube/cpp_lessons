// Sorting char array
#include <iostream>
using namespace std;

int main()
{

    const int len = 100; //length of char array
	char array[len];
    cout << "Enter line: \n";

	cin.getline(array, len);

    cout << "\n\n";
    cout << "Sorted to:";
    cout << "\n\n\n";


    for (int j = 0; j < strlen(array)-1; j++) {
        for (int i = 0; i < strlen(array)-1; i++) {

            if (int(array[i]) > int(array[i+1])) {
                swap(array[i], array[i + 1]);
            }
        }
    }


    for (int i = 0; i <= strlen(array); i++) {
        cout << array[i];
    }

}