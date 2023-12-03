// implement deleting element(s) from the file, replacing element(s), searching for elements, deleting elements, copying elements, sorting (by all types) + write the logic for auto-sorting elements (with the definition of the optimal algorithm in each case)
//

#include <iostream>
#include <fstream>

using namespace std;

void addArray() {

}

int main()
{
    char* char_file;
    ifstream ffile("text.txt", ios::in);

    int n = 100;
    char* buffer = new char[n + 1];
    buffer[n] = 0;

    while (!ffile.eof()) {
        ffile.getline(buffer, n, '\n');
    }


    int symbols = 100;

    for (int i = 0; !ffile.eof(); i++) {
        ffile.getline(char_file[i], symbols, '\n');
    }

    char tmp;


    ffile >> tmp;
    cout << tmp << endl;


    ffile.getline(buffer, n, '\n');
    cout << buffer << endl;

    ffile.getline(buffer, n, '\n');
    cout << buffer << endl;


}