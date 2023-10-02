/*
Завдання 3. Користувач вводить з клавіатури 7 цілих чисел.
Напишіть програму, яка визначає максимум з цих 7 чисел
(Підказка - рішення повинно бути простим).
*/

#include <iostream>
using namespace std;

int main()
{
    int arr[7];
    for (int i = 0; i < 7; i++) {
        cout << "Enter " << i + 1 << "-number." << endl;
        cin >> arr[i];
    }
    for (int j = 1; j < 8; j++) {
        if (arr[0] < arr[j])
            arr[0] = arr[j];
    }
    cout << "Max number is: " << arr[0] << endl;
    return 0;
}