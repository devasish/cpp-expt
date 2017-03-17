/**
 * Source :
 * http://www.practice.geeksforgeeks.org/problem-page.php?pid=1704
 */

#include <iostream>
#include <cmath>
using namespace std;

int g(int a, int b, int c, int n) {
    if (n == 1 || n == 2)
        return 1;

    return (a * g(a, b, c, n - 1) + b * g(a, b, c, n - 2) + c);
}

int in_limit(int p) {
    if (p < 1)
        return 1;
    else if (p > (pow(10, 7) + 7))
        return pow(10, 7) + 7;
    else 
        return p;
}

int main() {
    int x;
    int a, b, c, n, m;
    int *arr;

    cin >> x;
    if (x < 1)
        x = 1;
    else if (x > 100)
        x = 100;


    arr = new int[x];

    for (int j = 0; j < x; j++) {
        cin >> a;
        a = in_limit(a);

        cin >> b;
        b = in_limit(b);

        cin >> c;
        c = in_limit(c);

        cin >> n;
        n = in_limit(n);

        cin >> m;
        m = in_limit(m);

        arr[j] = g(a, b, c, n) % m;
    }

    for (int i = 0; i < x; i++) {
        cout << arr[i] << endl;
    }

    delete [] arr;

    return 1;
}