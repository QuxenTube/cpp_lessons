/*
Завдання 4.
Напишіть програму, яка обчислює суму цілих чисел від a до 500 (значення a вводиться з клавіатури).
*/
#include <iostream>
using namespace std;

int main() {
    int sum = 0;
    int a;
    cout << "Enter number less than 500 to find sum:" << endl;
    cin >> a;
    if (a <= 500) {
        for (a < 500; a++;) {
            sum += a;
        }
        cout << "Sum is: " << sum << endl;
    }
    else {
        cout << "\033[31mERROR!\033[0m" << endl;
        cout << "Number bigger than 500" << endl;
    }
    return 0;
}