#include <bits/stdc++.h>
using namespace std;
void merge(vector<int>& arr,int l, int h) {
    int m = (l + h) / 2;
    vector<int> arr1;
    vector<int> arr2;
    for (int i = l; i <= m; i++) {
        arr1.push_back(arr[i]);
    }
    for (int i = m + 1; i <= h; i++) {
        arr2.push_back(arr[i]);
    }
    int i = 0, j = 0, k =l;
    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] < arr2[j]) {
            arr[k++] = arr1[i++];
        } else {
            arr[k++] = arr2[j++];
        }
    }
    while (i < arr1.size()) {
        arr[k++] = arr1[i++];
    }
    while (j < arr2.size()) {
        arr[k++] = arr2[j++];
    }
}
void mergeSort(vector<int>& arr, int l, int h) {
    if (l >= h) return;
    int m = (l + h) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, h);
    merge(arr, l, h);
}
int main(){
    vector<int>arr={5,2,4,3};
    mergeSort(arr,0,arr.size()-1);
    for (int x : arr) cout << x << " ";
    return 0;
}
