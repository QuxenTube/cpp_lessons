// Create triangles and sandclock

#include <iostream>
using namespace std;

int main() {

	for (int i = 0; i <= 10; i++)
	{
		for (int j = 0; j <= 10; j++)
		{
			if (j == 0 || i == j || i == 10) {
				cout << "*";
			}
			else {
				cout << " ";
			}
		}
		cout << "\n";
	}

	cout << "\n";
	cout << "-------------------------------------";
	cout << "\n";
	cout << "\n";

	for (int i = 0; i <= 10; i++)
	{
		for (int j = 0; j <= 10; j++)
		{
			if (j == 10 || i == 10-j || i == 10) {
				cout << "*";
			}
			else {
				cout << " ";
			}
		}
		cout << "\n";
	}

	cout << "\n";
	cout << "-------------------------------------";
	cout << "\n";
	cout << "\n";

	for (int i = 0; i <= 10; i++)
	{
		for (int j = 0; j <= 10; j++)
		{
			if (i == 0 || i == 10 || i == j || i == 10 - j) {
				cout << "*";
			} else {
				cout << " ";
			}
		}
		cout << "\n";
	}

}