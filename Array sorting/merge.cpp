#include<iostream>
#include<vector>
using namespace std;
void merge(int arr[], int l, int m, int r);
void printArray(int A[], int size);
void mergeSort(int arr[], int l, int r);

int main() 
{ 
    int arr[] = {12, 11, 13, 5, 6, 7}; 
    int arr_size = sizeof(arr)/sizeof(arr[0]); 
  
    printf("Given array is \n"); 
    printArray(arr, arr_size); 
  
    mergeSort(arr, 0, arr_size - 1); 
  
    printf("\nSorted array is \n"); 
    printArray(arr, arr_size); 
    return 0; 
} 

/* UTILITY FUNCTIONS */
/* Function to print an array */
void printArray(int A[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", A[i]); 
    printf("\n"); 
}

// Merges two subarrays of arr[]. 
// First subarray is arr[l..m] 
// Second subarray is arr[m+1..r] 
void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    /* create temp arrays */
    int L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 

/* l is for left index and r is right index of the 
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = l+(r-l)/2; 
  
        // Sort first and second halves 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    } 
}




// void merge(vector<int> arr, int l, int m, int r);
// void divide(vector<int> arr, int l, int r);
 
// int main() {
//     vector<int> unSortedList = {4,7,2,6,2,0,1,9}; //avg case
//     //  vector<int> unSortedList = {0, 1, 2, 2, 4, 6, 7, 9}; //best case
//     // vector<int> unSortedList = {9,7,6,4,2,2,1,0}; // worst case
//     int l = 0, r = unSortedList.size() -1;
//         divide(unSortedList, l, r);

//     for(int i=0; i < unSortedList.size(); i++) {
//         cout << unSortedList[i] << " ";
//     }
//     return 0;
// }

// void divide(vector<int> arr, int l, int r) {
//     if (l < r) {
//         int m = l + (r-l)/2;
//         divide(arr, l, m);
//         divide(arr, m+1, r);
//         merge(arr, l, m, r);
//     }
// }

// void merge(vector<int> arr, int l, int m, int r) {
//         // cout << "index" << l << " " << m << " " << r << endl;

//     // create temporary array for left and right array
//     int n1 = m - l + 1;
//     int n2 = r - m;

//     // cout << " n " <<n1<<" "<<n2 << " ";

//     vector<int> L(n1);
//     vector<int> R(n2);

//     for(int i=0; i<n1; i++) {
//         L.push_back(arr[l+i]);
//         // cout<< arr[l+i];
//     }

//     for(int i=0; i<n2; i++) {
//         R.push_back(arr[m+1+i]);
//         // cout<< arr[1+i+m];
//     }

//     // merge L and R and save sorted array in arr
//     int li = 0, ri = 0;
//     if (l+1 != r) {
//         for(int i=0; i<= r-l; i++) {
//         if (n1 > 0) {
//             if (L[li] < R[ri]) {
//             arr[l+i] = L[li];
//             li++;
//         }
//         else {
//             arr[l+i] = R[ri];
//             ri++;
//         }
//         } else {
//             arr[l+i] = R[i];
//         }
//         // cout << arr[l+i] << " ";
//     }
//     }
    
    
//     cout<< endl;
// }


