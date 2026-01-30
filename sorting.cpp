#include <iostream>
using namespace std;
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        int minIdx = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[minIdx])
                minIdx = j;
        }
        swap(arr[i], arr[minIdx]);
    }
}
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[m + 1 + i];
    
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }
    
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
//type 2 
#include <bits/stdc++.h>
using namespace std;
void merge(vector<int>&arr,int l,int m,int h){
    vector<int>left;
    vector<int>right;
    for(int i=l;i<=m;i++){
        left.push_back(arr[i]);
    }
    for(int i=m+1;i<=h;i++){
        right.push_back(arr[i]);
    }
    int i=0,j=0,k=l;
    while(i<left.size() && j<right.size()){
        if(left[i]<=right[j])arr[k++]=left[i++];
        else arr[k++]=right[j++];
    }
    while(i<left.size())arr[k++]=left[i++];
    while(j<right.size())arr[k++]=right[j++];
}
void mergesort(int l,int h,vector<int>&arr){
    if(l<h){
        int m=(l+h)/2;
        mergesort(l,m,arr);
        mergesort(m+1,h,arr);
        merge(arr,l,m,h);
    }
}
int main(){
    vector<int>arr={2,8,7,5,6};
    mergesort(0,4,arr);
    for(auto x:arr)cout<<x<<" ";
    return 0;
}
/////
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
void cyclicSort(int arr[], int n) {
    int i = 0;
    while (i < n) {
        if (arr[i] != arr[arr[i] - 1]) {
            swap(arr[i], arr[arr[i] - 1]);
        } else {
            i++;
        }
    }
}



