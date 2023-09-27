#include <iostream>
#include <windows.h>

using namespace std;

int main() {
	
	// SETTINGS
	cout << "Enter game scale:" << endl;
	int scale;
	cin >> scale;

	cout << "Entered value is: " << scale << endl;
	//cout << rows[scale][scale] << endl;

	// CORE

	int arr[10][10];

	for (int i = 0; i < scale; i++)
	{
		for (int j = 0; j < scale; j++) {
			arr[i][j] = rand() % 100;

			cout << arr[i][j] << " ";
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