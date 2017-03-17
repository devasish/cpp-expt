#include <iostream>

using namespace std;

int main() {
    int t = 1;
    int n, m;
    int **a, **visited;
    int i, j;
    
//    cin >> t;
    cin >> n;
    cin >> m;
    
    a = new int*[n];
    visited = new int*[n];
    
    for (i = 0; i < n; i++) {
        a[i] = new int[m];
        visited = new int[m];
    }
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            cin >> a[i][j];
            visited[i][j] = 0;
        }
    }
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (a[i][j] == 1 && visited[i][j] == 0) {
                
            }
        }
    }
    
    return 0;
}
