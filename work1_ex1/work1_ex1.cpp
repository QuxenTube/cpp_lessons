/*
Завдання 1.
Користувач вводить з клавіатури шестизначне ціле число.
Напишіть програму, яка визначає, чи пощастить введеному числу (Lucky - шестизначне число, в якому сума перших 3 цифр дорівнює сумі других трьох цифр).
Якщо користувач ввів нешестизначне число, з'являється повідомлення про помилку.
*/

#include <iostream>
using namespace std;

int main()
{
    int lucky;
    int arr[6];
    cout << "Enter 6-digit number" << endl;
    cin >> lucky;
    if (lucky > 99999 && lucky < 1000000) {
        // cout << "Entered 6-digit int: " << lucky << endl;
        for (int i = 5; i >= 0; i--) {
            arr[i] = lucky % 10;
            lucky /= 10;
        }
        int a = arr[0] + arr[1] + arr[2];
        int b = arr[3] + arr[4] + arr[5];
        if (a == b) {
            cout << "You lucky!!!" << endl;
        }
        else {
            cout << "You not lucky :(" << endl;
        }
    }
    else {
        cout << "\033[31mERROR!\033[0m" << endl;
        cout << "Entered not 6-digit" << endl;
    }

    return 0;
}