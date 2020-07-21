#include<bits/stdc++.h>
using namespace std;

int findMedian(vector<vector<int> > &m) {
    int r = m.size();
    int c = m[0].size();
    int min = INT_MAX, max = INT_MIN; 
    for (int i=0; i<r; i++) 
    { 
        // Finding the minimum element 
        if (m[i][0] < min) 
            min = m[i][0]; 
  
        // Finding the maximum element 
        if (m[i][c-1] > max) 
            max = m[i][c-1]; 
    } 
    cout<<min<<" "<<max<<endl;
    int desired = (r * c + 1) / 2; 
    while (min < max) 
    { 
        int mid = min + (max - min) / 2; 
        int place = 0; 
  
        // Find count of elements smaller than mid 
        for (int i = 0; i < r; ++i) {
            place = place + upper_bound(m[i].begin(), m[i].end(), mid) - m[i].begin();
            cout<<place<<" "<<upper_bound(m[i].begin(), m[i].end(), mid)- m[i].begin()<<" "<<mid<<endl;
        }   
        if (place < desired) 
            min = mid + 1; 
        else
            max = mid; 
    } 
    return min; 
}

int main (){
    //code
    vector<vector<int>> A{ {1,3,5}, {2,6,9}, {1,2,9} };
    cout<<findMedian(A);
    return 0;
}
