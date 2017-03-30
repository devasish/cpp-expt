/**
 * Source : 
 * http://practice.geeksforgeeks.org/problem-page.php?pid=1697
 */
#include <iostream>

using namespace std;

struct node {
    int value;
    int visited;
    int region;
};

void pr(node **a, int n, int m) {
    int i, j;
    cout << endl << "Matrix is : " << endl;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            cout << a[i][j].value << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << endl << "Region map : " << endl;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            cout << a[i][j].region << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void neighbour(node **a, int n, int m, int i, int j) {
    if (a[i][j].value == 1) {
        if (a[i][j].visited == 0) {
            a[i][j].visited = 1;
        }

        int prev_row = i - 1;
        int next_row = i + 1;
        int prev_col = j - 1;
        int next_col = j + 1;
        int x, y;
        for (x = prev_row; x <= next_row; x++) {
            for (y = prev_col; y <= next_col; y++) {
                if (x == i && y == j)
                    continue;

                if (x >= 0 & x < n & y >= 0 && y < m) {
                    if (a[x][y].value == 1 && a[x][y].visited == 0) {
                        a[x][y].region = a[i][j].region;
                        neighbour(a, n, m, x, y);
                    }
                }
            }
        }
    }
}

int main() {
    int t = 1;
    int n, m;
    node **a;
    int i, j;

    cout << "Enter Number of Rows : ";
    cin >> n;
    cout << endl;
    cout << "Enter Number of Columns: ";
    cin >> m;

    cout << endl;
    cout << "Enter Array Elements:" << endl;

    a = new node*[n];


    for (i = 0; i < n; i++) {
        a[i] = new node[m];
    }

    for (i = 0; i < n; i++) {
        cout << "Enter Element At Row " << i + 1 << " : " << endl;
        for (j = 0; j < m; j++) {
            cout << "a[" << i << "," << j << "] = ";
            cin >> a[i][j].value;
            a[i][j].region = 0;
            a[i][j].visited = 0;
        }
        cout << endl;
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (a[i][j].value == 1 && a[i][j].visited == 0) {
                a[i][j].region = i * 10 + j + 1;
                neighbour(a, n, m, i, j);
            }

        }
    }

    pr(a, n, m);

    return 0;
}
