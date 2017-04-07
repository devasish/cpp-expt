/**
 * Source:
 * http://practice.geeksforgeeks.org/problems/travelling-salesman-problem/0
 */
#include <iostream>
#include <fstream>
#include <cmath>

//#define cin fin
#define SUDOKU_SIZE 9
using namespace std;

int last_x;
int last_y;
int ct_rec = 0;

struct cord {
    int x;
    int y;
};

bool check(int** arr, int** sol, int x, int y, int n);
cord next(int**, int**, int, int);

void pr(int **arr) {
    int i, j;
    cout << endl << "Array : " << endl;
    for (i = 0; i < SUDOKU_SIZE; i++) {
        for (j = 0; j < SUDOKU_SIZE; j++) {
            cout << arr[i][j] << " ";
            if ((j + 1) % (int) sqrt(SUDOKU_SIZE) == 0)
                cout << "|";
        }
        if ((i + 1) % (int) sqrt(SUDOKU_SIZE) == 0)
            cout << endl << "------+------+------+";;
        cout << endl;
    }
}

bool check_row(int** arr, int x, int y, int n) {
    int j = 0;
    for (j = 0; j < SUDOKU_SIZE; j++) {
        if (j == y)
            continue;

        if (n == arr[x][j])
            return false;
    }

    return true;
}

bool check_col(int** arr, int x, int y, int n) {
    int i = 0;
    for (i = 0; i < SUDOKU_SIZE; i++) {
        if (i == x)
            continue;

        if (n == arr[i][y])
            return false;
    }

    return true;
}

bool check_home(int** arr, int x, int y, int n) {
    int base_x, base_y, i, j;
    int home_size = (int) sqrt(SUDOKU_SIZE);
    base_x = (int) floor(x / home_size) * home_size;
    base_y = (int) floor(y / home_size) * home_size;

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

cord next(int **arr, int **sol, int x, int y) {
    int i, j;
    cord next_cord;
    for (i = x; i < SUDOKU_SIZE; i++) {
        for (j = (i == x ? y : 0); j < SUDOKU_SIZE; j++) {
            if (i == x && j == y)
                continue;
            else if (arr[i][j] == 0)
                goto START_REC;

        }
    }

START_REC:
    next_cord.x = i;
    next_cord.y = j;
    return next_cord;
}

/**
 * Validate each entry recursively
 * @param arr
 * @param sol
 * @param x
 * @param y
 * @param n
 * @return 
 */
bool check(int **arr, int **sol, int x, int y, int n) {
    int i, k;
    bool flag, flag2;
    cord next_cord;
    ct_rec++;
    for (i = n; i <= SUDOKU_SIZE; i++) {
        flag = check_row(sol, x, y, i) && check_home(sol, x, y, i) && check_col(sol, x, y, i);

        //        cout << endl << "Flag : " << flag << " Value :" << i << " Position: " << x << y << endl;

        if (flag == true) {
            sol[x][y] = i;
            if (x == last_x && y == last_y) {
                return true;
            } else {
                next_cord = next(arr, sol, x, y);
                //                cin >> k;
                //                pr(sol);
                flag2 = check(arr, sol, next_cord.x, next_cord.y, 1);
                if (flag2 == true)
                    return true;
            }
        }
    }
    sol[x][y] = 0;

    return false;
}

int main() {
    int a, b;
    int t, ti = 0;
    int i, j;
    int **arr, **sol;
    fstream fin("input_9.txt", ios_base::in);

    fin >> t;
    while (ti++ < t) {
        arr = new int*[SUDOKU_SIZE];
        sol = new int*[SUDOKU_SIZE];

        for (i = 0; i < SUDOKU_SIZE; i++) {
            arr[i] = new int[SUDOKU_SIZE];
            sol[i] = new int[SUDOKU_SIZE];
        }

        for (i = 0; i < SUDOKU_SIZE; i++) {
            for (j = 0; j < SUDOKU_SIZE; j++) {
                fin >> arr[i][j];
                sol[i][j] = arr[i][j];
            }
        }

        for (i = SUDOKU_SIZE - 1; i >= 0; i--) {
            for (j = SUDOKU_SIZE - 1; j >= 0; j--) {
                if (arr[i][j] == 0) {
                    last_x = i;
                    last_y = j;
                    goto LOOP_2;
                }
            }
        }

LOOP_2:

        pr(arr);
        bool flag = true;
        for (i = 0; i < SUDOKU_SIZE; i++) {
            for (j = 0; j < SUDOKU_SIZE; j++) {
                if (arr[i][j] == 0) {
                    goto START_REC;
                }
            }
        }

START_REC:
        cout << "Start: " << i << j << endl << "End : " << last_x << last_y << endl;
        flag = check(arr, sol, i, j, 1);

        if (flag == true)
            cout << "DONE" << " Recursion Count : " << ct_rec;
        pr(sol);
    }

    return 1;
}
