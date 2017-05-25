#include <iostream>
using namespace std;

void pr(int arr[], int len) {
    int i = 0; 
    
    for (i = 0; i < len; i++) {
        cout << arr[i] << "\t";
    }
    cout << endl;
}

void pr_h(int arr[], int len, int highlight_1, int highlight_2) {
    int i = 0; 
    
    for (i = 0; i < len; i++) {
        if (i == highlight_1 || i == highlight_2)
            cout << "(" << arr[i] << ")" << "\t";
        else
            cout << arr[i] << "\t";
    }
    cout << endl;
}

void swap(int arr[], int x, int y) {
    int temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
}

void selection_sort(int arr[], int len) {
    int i, j, sel, min;
    
     cout << "Input Array : " << endl;
     pr(arr, len);
    
    for (i = 0; i < len; i++) {
        min = arr[i];
        sel = i;
        for (j = i + 1; j < len; j++) {
            if (min > arr[j]) {
                sel = j;
                min = arr[j];
            }
        }
        if (sel != i)
            swap(arr, i, sel);
        
        cout << endl << "Pass " << i + 1 << " : ";
        pr_h(arr, len, i, sel);
    }
    
    cout << "Sorted Array : " << endl;
    pr(arr, len);
}

int main() {
//    int arr[]   = {10, 3, 5, 12, 8};
    int arr[]   = {1000, 100, 99, 98, 50, 233, 12, 90, 112, 97, 95};
    int len     = sizeof(arr) / sizeof(int);
   
    selection_sort(arr, len);
    
    return 1;
}