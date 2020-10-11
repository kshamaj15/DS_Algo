// https://practice.geeksforgeeks.org/problems/merge-sort/1

#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &v, int s, int m, int e) {
    int n1 = m - s + 1; 
    int n2 = e - m; 
    // Create temp arrays  
    int left[n1], right[n2]; 
  
    // Copy data to temp arrays left[] and right[]  
    for(int i = 0; i < n1; i++) 
        left[i] = v[s + i]; 
    for(int j = 0; j < n2; j++) 
        right[j] = v[m + 1 + j]; 

    int i=0, j=0, k=s;
    while(i<n1 && j<n2){
        if(left[i] < right[j]) {
            v[k] = left[i];
            i++; k++;
        } else {
            v[k] = right[j];
            j++; k++;
        }
    }
    while(i<n1){
        v[k] = left[i];
        i++;k++;
    }
    while(j<n2){
        v[k] = right[j];
        j++;k++;
    }
}

void mergeSort(vector<int> &v, int s, int e) {
    int m = s + (e-s)/2;
    if(s < e) {
        mergeSort(v, s, m);
        mergeSort(v, m+1, e);
        merge(v, s, m, e);
    }
}

int main() {
    vector<int> v;
    while(1) {
        int temp;
        cin>>temp;
        if(temp != -1)
        v.push_back(temp);
        else
        break;
    }
    int n = v.size();
    mergeSort(v, 0, n-1);
    for(auto el:v)
    cout<<el<<" ";
    cout<<endl;
}