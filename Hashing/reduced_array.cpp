#include<iostream>
#include<bits/stdc++.h> 
using namespace std;
int main () {
    int arr[10] = {41,5,78,3,22,54,1,4,30,9};
    int sortedArr[10];
    memcpy(sortedArr, arr, 10*sizeof(int));

    // make a sorted array
    sort(sortedArr, sortedArr + 10);
    unordered_map<int, int> map;
    int value = 0;

    // save [0,(n-1)] value in map
    for(auto i: sortedArr) {
        map[i] = value++;
    }
    
    // replace reduced value to array values
    for(auto j: arr) {
        j = map[j];
        cout << j << ", ";
    }
    return 0;
}