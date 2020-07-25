#include<bits/stdc++.h>
using namespace std;

int perfectPeak(vector<int> &A) {
    int ans;
    vector<int> max;
    vector<int> min;
    int ma = A[0];
    int mi = A[A.size()-1];
    for(int i=0; i<A.size(); i++) {
        ma = ma > A[i] ? ma : A[i];
        max.push_back(ma);
        cout<<i<<" "<<ma<<endl;
    }
    cout<<endl;
    for(int i=A.size()-1; i>=0; i--) {
        mi = mi < A[i] ? mi : A[i];
        min.push_back(mi);
        cout<<i<<" "<<mi<<endl;
    }
    for(int i=1; i<A.size()-1; i++) {
        cout<<i<<" "<<max[i-1]<<" "<<min[A.size() - i - 2]<<endl;
        if(A[i]>max[i-1] && A[i]<min[A.size()  - i - 2]) 
        return 1;
    }
    return 0;
}


int main (){
    //code
    vector<int> v{5, 1, 4, 3, 6, 8, 10, 7, 9};
    cout<<perfectPeak(v);
    return 0;
}
