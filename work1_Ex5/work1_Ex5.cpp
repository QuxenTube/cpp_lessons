/*
Завдання 5. 
Напишіть програму, яка запитує два цілих числа x і y, а потім обчислює і виводить значення x в степінь y.
*/
#include <iostream>
using namespace std;

int main() {
    int x, y, t = 1;
    cout << "Enter 2 numbers:" << endl;
    cin >> x;
    cin >> y;
    for (int i = 0; i <= y; i++) {
        t = t*x;
    }
    cout << "x ^ y = " << t << endl;
    return 0;
}