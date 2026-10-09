#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(int a[], int n) {
 for (int i = 0; i < n - 1; i++) {
 bool swapped = false;
 for (int j = 0; j < n - i - 1; j++) {
 if (a[j] > a[j + 1]) {
 swap(a[j], a[j + 1]);
 swapped = true;
 }
 }
 if (!swapped) break;
 }
}
void selectionSort(int a[], int n) {
 for (int i = 0; i < n - 1; i++) {
 int minIndex = i;
 for (int j = i + 1; j < n; j++) {
 if (a[j] < a[minIndex]) minIndex = j;
 }
 swap(a[i], a[minIndex]);
 }
}
void insertionSort(int a[], int n) {
 for (int i = 1; i < n; i++) {
 int key = a[i];
 int j = i - 1;
 while (j >= 0 && a[j] > key) {
 a[j + 1] = a[j];
 j--;
 }
 a[j + 1] = key;
 }
}
void merge(int a[], int l, int m, int r) {
 vector<int> temp;
 int i = l, j = m + 1;
 while (i <= m && j <= r)
 temp.push_back(a[i] <= a[j] ? a[i++] : a[j++]);
 while (i <= m) temp.push_back(a[i++]);
 while (j <= r) temp.push_back(a[j++]);
 for (int k = 0; k < (int)temp.size(); k++)
 a[l + k] = temp[k];
}
void mergeSort(int a[], int l, int r) {
 if (l >= r) return;
 int m = l + (r - l) / 2;
 mergeSort(a, l, m);
 mergeSort(a, m + 1, r);
 merge(a, l, m, r);
}
int partitionArray(int a[], int low, int high) {
 int pivot = a[high];
 int i = low - 1;
 for (int j = low; j < high; j++) {
 if (a[j] <= pivot) {
 i++;
 swap(a[i], a[j]);
 }
 }
 swap(a[i + 1], a[high]);
 return i + 1;
}
void quickSort(int a[], int low, int high) {
 if (low < high) {
 int p = partitionArray(a, low, high);
 quickSort(a, low, p - 1);
 quickSort(a, p + 1, high);
 }
}
int main() {
 int a1[] = {64, 34, 25, 12, 22, 11, 90, 45, 78, 3};
 int n = sizeof(a1) / sizeof(a1[0]);
 int a2[10], a3[10], a4[10], a5[10];
 copy(a1, a1 + n, a2); bubbleSort(a2, n);
 copy(a1, a1 + n, a3); selectionSort(a3, n);
 copy(a1, a1 + n, a4); insertionSort(a4, n);
 copy(a1, a1 + n, a5); mergeSort(a5, 0, n - 1);
 cout << "Bubble Sort: "; for (int x : a2) cout << x << " "; cout << endl;
 cout << "Selection Sort: "; for (int x : a3) cout << x << " "; cout << endl;
 cout << "Insertion Sort: "; for (int x : a4) cout << x << " "; cout << endl;
 cout << "Merge Sort: "; for (int x : a5) cout << x << " "; cout << endl;
 quickSort(a1, 0, n - 1);
 cout << "Quick Sort: "; for (int x : a1) cout << x << " ";
}