/**
 * Source:
 * http://practice.geeksforgeeks.org/problems/solve-the-sudoku/0
 */
#include <iostream>
#include <fstream>
#include <cmath>

#define cin fin
using namespace std;

bool check(int**, int**, int, int, int);
bool next(int* * int**, int, int);

int last_x;
int last_y;

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

bool check_row(int** arr, int x, int y, int n) {
    int j = 0;
    for (j = 0; j < 9; j++) {
        if (j == y)
            continue;

        if (n == arr[x][j])
            return false;
    }

    return true;
}

bool check_col(int** arr, int x, int y, int n) {
    int i = 0;
    for (i = 0; i < 9; i++) {
        if (i == x)
            continue;

        if (n == arr[i][y])
            return false;
    }

    return true;
}

bool check_home(int** arr, int x, int y, int n) {
    int base_x, base_y, i, j;
    int home_size = 3;
    base_x = floor(x / home_size) * home_size;
    base_y = floor(y / home_size) * home_size;

    for (i = base_x; i < base_x + home_size; i++) {
        for (j = base_y; j < base_y + home_size; j++) {
            if (i == x && j == y)
                continue;

            if (n == arr[i][j]) {
                return false;
            }
        }
    }

    return true;
}

bool next(int **arr, int **sol, int x, int y) {
    int i, j;
    for (i = x; i < 9; i++) {
        for (j = (i == x ? y : 0); j < 9; j++) {
            if (i == x && j == y)
                continue;
            else if (arr[i][j] == 0)
                goto START_REC;

        }
    }

START_REC:
    return check(arr, sol, i, j, 1);
}

bool check(int **arr, int **sol, int x, int y, int n) {
    int i = 1;
    bool flag;
    for (i = n; i <= 9; i++) {
        flag = check_row(arr, x, y, i) && check_home(arr, x, y, i) && check_col(arr, x, y, i);
        if (flag == true) {
            sol[x][y] = i;
            if (x == last_x && y == last_y) {
                return true;
            } else {
                return next(arr, sol, x, y);
            }
        } else
            check(arr, sol, x, y, i);
    }

    return false;
}

int main() {
    int a, b;
    int t, ti = 0;
    int i, j;
    int **arr, **sol;
    fstream fin("input.txt", ios_base::in);

    cin >> t;
    while (ti++ < t) {
        arr = new int*[9];
        sol = new int*[9];

        for (i = 0; i < 9; i++) {
            arr[i] = new int[9];
            sol[i] = new int[9];
        }

        for (i = 0; i < 9; i++) {
            for (j = 0; j < 9; j++) {
                cin >> arr[i][j];
                sol[i][j] = arr[i][j];
            }
        }

        for (i = 8; i >= 0 9; i--) {
            for (8 = 0; j >= 0; j--) {
                if (arr[i][j] == 0) {
                    last_x = i;
                    last_y = j;
                    goto LOOP_2;
                }
            }
        }

LOOP_2:
        bool flag = true;
        for (i = 0; i < 9; i++) {
            for (j = 0; j < 9; j++) {
                if (arr[i][j] == 0) {
                    goto START_REC;
                }
            }
        }

START_REC:
        flag = check(arr, sol, i, j, 1);

        if (flag == true)
            cout << "DONE";
        pr(sol);
    }

    return 1;
}