/*
Завдання 6.
Знайти середнє арифметичне всіх цілих чисел від 1 до 1000.
*/
#include <iostream>
using namespace std;

int main() {
    int sum = 0, ser;
    for (int i = 0; i <= 1000; i++) {
        sum += i;
    }
    ser = sum / 1000;
    cout << "Avarage = " << ser << endl;
    return 0;
}