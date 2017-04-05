/**
 * Source : 
 * http://practice.geeksforgeeks.org/problem-page.php?pid=1697
 */
#include <iostream>

using namespace std;

struct node {
    int value;
    int status;
    int region;
};

int main() {
    int t = 1;
    int n, m;
    int **a, **visited;
    int i, j;

    cout << "Enter Number of Rows : ";
    cin >> n;
    cout << endl;
    cout << "Enter Number of Columns: ";
    cin >> m;

    cout << endl;
    cout << "Enter Array Elements:" << endl;

    a = new int*[n];
    visited = new int*[n];

    for (i = 0; i < n; i++) {
        a[i] = new int[m];
        visited[i] = new int[m];
    }

    for (i = 0; i < n; i++) {
        cout << "Enter Element At Row " << i + 1 << " : " << endl;
        for (j = 0; j < m; j++) {
            cout << "a[" << i << "," << j << "] = ";
            cin >> a[i][j];
            visited[i][j] = 0;
        }
        cout << endl;
    }

    cout << endl;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            cout << a[i][j] << " ";
            if (a[i][j] == 1) {
                if (visited[i][j] == 0) {
                    visited[i][j] = 10 * i + j + 1;
                }

                int prev_row = i - 1;
                int next_row = i + 1;
                int prev_col = j - 1;
                int next_col = j + 1;

                if (next_row < n) {
                    if (prev_col >= 0) {
                        if (a[next_row][prev_col] == 1 && visited[next_row][prev_col] == 0) {
                            visited[next_row][prev_col] = visited[i][j];
                        }
                    }

                    if (a[next_row][j] == 1 && visited[next_row][j] == 0) {
                        visited[next_row][j] = visited[i][j];
                    }

                    if (next_col < m) {
                        if (a[next_row][next_col] == 1 && visited[next_row][next_col] == 0) {
                            visited[next_row][next_col] = visited[i][j];
                        }
                    }
                }

                if (next_col < m) {
                    if (a[i][next_col] == 1 && visited[i][next_col] == 0) {
                        visited[i][next_col] = visited[i][j];
                    }
                }
            }
        }
        cout << endl;
    }
    
    cout << "Region : " << endl;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            cout << visited[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
