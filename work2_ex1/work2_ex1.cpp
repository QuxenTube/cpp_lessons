// Create triangles and sandclock

#include <iostream>
using namespace std;

int main() {

	int a = 10;
	
	cout << "Enter triangles scale:" << endl;
	cin >> a;
	cout << "\033[2K\033[A\033[2K\033[A\033[2K";

	int w = a, h = a;

	for (int i = 0; i <= w; i++)
	{
		for (int j = 0; j <= h; j++)
		{
			if (j == 0 || i == j || i == h) {
				cout << "*";
			}
			else {
				cout << " ";
			}
		}
		cout << "\n";
	}

	cout << "\n";
	cout << "-------------------------------------" << "\n";
	cout << "\n";

	for (int i = 0; i <= w; i++)
	{
		for (int j = 0; j <= h; j++)
		{
			if (j == w || i == w - j || i == h) {
				cout << "*";
			}
			else {
				cout << " ";
			}
		}
		cout << "\n";
	}

	cout << "\n";	
	cout << "-------------------------------------" << "\n";
	cout << "\n";

	for (int i = 0; i <= w; i++)
	{
		for (int j = 0; j <= h; j++)
		{
			if (i == 0 || i == h || i == j || i == w - j) {
				cout << "*";
			} else {
				cout << " ";
			}
		}
		cout << "\n";
	}

}