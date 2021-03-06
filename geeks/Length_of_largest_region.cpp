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


int neighbour(node **a, int n, int m, int i, int j) {
    int region_size = 1;
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
                        region_size += neighbour(a, n, m, x, y);
                    }
                }
            }
        }
    }

    return region_size;
}

int main() {
    int n, m, max_region_size = 0, region_size;
    node **a;
    int i, j, t, ti = 0;
    int *output;

    cin >> t;
    output = new int[t];
    while (ti < t) {
        max_region_size = 0;
        region_size = 0;
        cin >> n;
        cin >> m;

        a = new node*[n];
        for (i = 0; i < n; i++) {
            a[i] = new node[m];
        }

        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                cin >> a[i][j].value;
                a[i][j].region = 0;
                a[i][j].visited = 0;
            }
        }

        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                if (a[i][j].value == 1 && a[i][j].visited == 0) {
                    a[i][j].region = i * 10 + j + 1;
                    region_size = neighbour(a, n, m, i, j);
                    if (region_size > max_region_size)
                        max_region_size = region_size;
                }
            }
        }

        output[ti] = max_region_size;
        ti++;
    }
    
    for (i =0; i < t; i++) {
        cout << output[i] << endl;
    }
    return 0;
}
