/**
 * A naive recursive Solution of 0/1 KnapSack problem
 * Time complexity of this naive solution is Big-Oh(2^n)
 */
#include <iostream>
using namespace std;

#define CAPACITY 20

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
 * Naive Solution - Calculate max capacity
 */ 
int knap_sack(int W, int wt[], int val[], int n) {
    //Base case
    if (W == 0 || n == 0)
        return 0;

    // If Weight of nth item is more than knapsack capacity W
    // then it can't be included in the optimal solution
    if (wt[n - 1] > W)
        return knap_sack(W, wt, val, n - 1);
    
    //Return the maximum of two cases
    // (1) nth item included
    // (2) nth item not included
    else
        return max(val[n - 1] + knap_sack(W - wt[n - 1], wt, val, n - 1), knap_sack(W, wt, val, n - 1));

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