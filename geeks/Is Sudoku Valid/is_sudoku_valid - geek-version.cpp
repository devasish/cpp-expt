/**
 * Source:
 * http://practice.geeksforgeeks.org/problems/is-sudoku-valid/0
 */
#include <iostream>
#include <fstream>
#include <cmath>

//#define cin fin
using namespace std;

void pr(int **arr) {
    int i, j;
    cout << endl << "Array : " << endl;
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

bool check_row(int** arr, int x, int y) {
    int j = 0;
    for (j = 0; j < 9; j++) {
        if (j == y)
            continue;

        if (arr[x][y] == arr[x][j])
            return false;
    }

    return true;
}

bool check_col(int** arr, int x, int y) {
    int i = 0;
    for (i = 0; i < 9; i++) {
        if (i == x)
            continue;

        if (arr[x][y] == arr[i][y])
            return false;
    }

    return true;
}

bool check_home(int** arr, int x, int y) {
    int base_x, base_y, i, j;
    int home_size = 3;
    base_x = floor(x / home_size) * home_size;
    base_y = floor(y / home_size) * home_size;

    for (i = base_x; i < base_x + home_size; i++) {
        for (j = base_y; j < base_y + home_size; j++) {
            if (i == x && j == y)
                continue;

            if (arr[x][y] == arr[i][j]) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    int a, b;
    int t, ti = 0;
    int i, j;
    int **arr;
    fstream fin("input.txt", ios_base::in);

    cin >> t;
    while (ti++ < t) {
        arr = new int*[9];
        for (i = 0; i < 9; i++) {
            arr[i] = new int[9];
        }

        for (i = 0; i < 9; i++) {
            for (j = 0; j < 9; j++) {
                cin >> arr[i][j];
            }
        }

        bool flag = true;
        for (i = 0; i < 9; i++) {
            for (j = 0; j < 9; j++) {
                if (arr[i][j] == 0) {
                    continue;
                }

                flag = flag && check_row(arr, i, j) && check_home(arr, i, j) && check_col(arr, i, j);
            }
        }

        if (flag)
            cout << 1;
        else
            cout << 0;

        cout << endl;
    }

    return 1;
}