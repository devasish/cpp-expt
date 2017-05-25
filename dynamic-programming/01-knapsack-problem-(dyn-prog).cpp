/**
 * A Dynamic Programming Solution of 0/1 KnapSack problem
 * Time complexity of this naive solution is Big-Oh(nW) 
 * where n is number of items and W is the capacity of knapsack
 */
#include <iostream>
using namespace std;

#define CAPACITY 10

/**
 * Helper function 
 * @param int a
 * @param int b
 * @return 
 */
int max(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}

/**
 * Dynamic Programming Solution - Calculate max capacity
 */
int knap_sack(int W, int wt[], int val[], int n) {
    int i, w;
    int k[n + 1][W + 1];
    
    cout <<  "\t";
    for (w = 0; w <= W; w++)
        cout << w << "\t";
    cout << endl;
    
    
    for (i = 0; i <= n; i++) {
        cout << wt[i] << "(" << val[i] << ")\t";
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                k[i][w] = 0;
            else if (wt[i - 1] <= w)
                k[i][w] = max(val[i - 1] + k[i - 1][w - wt[i - 1]], k[i - 1][w]);
            else
                k[i][w] = k[i - 1][w];
            
            cout << k[i][w] << "\t";
        }
        cout << endl;
    }

    return k[n][W];
}

/**
 * Driver Function
 */
int main() {
    int wt[] = {2, 4, 6, 3};
    int val[] = {5, 2, 3, 7};

    int n = sizeof (wt) / sizeof (int);
    
    cout << knap_sack(CAPACITY, wt, val, n);

    return 1;
}