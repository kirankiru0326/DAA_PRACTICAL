#include <iostream>
using namespace std;
int linearSearch(int a[], int n, int key) {
 for (int i = 0; i < n; i++)
 if (a[i] == key) return i;
 return -1;
}
int binarySearch(int a[], int n, int key) {
 int low = 0, high = n - 1;
 while (low <= high) {
 int mid = low + (high - low) / 2;
 if (a[mid] == key) return mid;
 if (a[mid] < key) low = mid + 1;
 else high = mid - 1;
 }
 return -1;
}
int main() {
 int a[] = {10, 25, 7, 40, 15, 30};
 int n = sizeof(a) / sizeof(a[0]);
 int key = 40;
 cout << "Linear Search: " << linearSearch(a, n, key) << endl;
 int b[] = {5, 10, 15, 20, 25, 30, 35, 40};
 int m = sizeof(b) / sizeof(b[0]);
 cout << "Binary Search: " << binarySearch(b, m, 30);
}