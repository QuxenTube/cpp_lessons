#include <iostream>
#include <windows.h>

using namespace std;


void create(int scale) {
			constexpr size_t rows = scale;
			return 0;
}

int main() {

	
	// SETTINGS

	//const int scale = 1;
	
	cout << "Enter game scale:" << endl;
	int scale;
	cin >> scale;
	//create(scale);

	int w;
	int h;
	//constexpr size_t scale = 20;
	cin >> h;
	//cin >> constexpr size_t scale;

	cout << "Entered value is: " << scale << endl;
	cout << "Entered value is: " << h << endl;

	// CORE

	int arr[scale][scale];

	for (int i = 0; i < scale; i++)
	{
		for (int j = 0; j < scale; j++) {
			arr[i][j] = rand() % 100;

			cout << arr[i][j];
		}
		cout << endl;
	}


	// GUI

	cout << "\033[31m" << "Game started:" << "\033[0m";
	Sleep(1200);
	//cout << "\033[2K";


	/*
	Sleep(2000);
	cout << "\033[1G" << "\033[100X";
	*/

	return 0;
}