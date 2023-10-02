/*
Завдання 2.
Користувач вводить чотиризначне число.
Необхідно змінити 1 і 2 цифри в цьому номері, а також 3 і 4 цифри.
Якщо користувач вводить нечотиризначне число, відобразіть повідомлення про помилку.
*/

#include <iostream>
using namespace std;

int main()
{
    int lucky;
    int arr[6];
    cout << "Enter 4-digit number" << endl;
    cin >> lucky;
    if (lucky > 999 && lucky < 10000) {
        // cout << "Entered 4-digit int: " << lucky << endl;
        for (int i = 3; i >= 0; i--) {
            arr[i] = lucky % 10;
            lucky /= 10;
        }

        int a = arr[0];
        arr[0] = arr[1];
        arr[1] = a;
        int b = arr[0];
        arr[2] = arr[3];
        arr[3] = b;
        int num = arr[0] * 1000 + arr[1] * 100 + arr[2] * 10 + arr[3];
        cout << num << endl;
    }
    else {
        cout << "\033[31mERROR!\033[0m" << endl;
        cout << "Entered not 4-digit" << endl;
    }

    return 0;
}