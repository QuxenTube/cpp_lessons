#include <iostream>
using namespace std;

int main() {
    int arr[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            arr[i][j] = rand() % 15;
            if (arr[i][j] == 7) {
                arr[i][j] = 3;
                arr[i - 1][j - 1] = 1;
                arr[i - 1][j] = 1;
                arr[i - 1][j + 1] = 1;
                arr[i][j - 1] = 1;
                arr[i][j + 1] = 1;
                arr[i + 1][j - 1] = 1;
                arr[i + 1][j] = 1;
                arr[i + 1][j + 1] = 1;
            }
            cout << arr[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}