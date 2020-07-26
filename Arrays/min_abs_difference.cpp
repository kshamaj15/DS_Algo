#include<bits/stdc++.h>
using namespace std;

int maxArr(vector<int> &A) {
    int minMinus = A[0]-1;
    int minPlus = A[0]+1;
    int maxMinus = A[0]-1;
    int maxPlus = A[0]+1;
    for(int i=1; i<A.size(); i++) {
        cout<<minMinus<<" "<<maxMinus<<endl;
        cout<<minPlus<<" "<<maxPlus<<endl;
        minMinus = minMinus < A[i] - i - 1 ? minMinus : A[i] - i - 1;
        minPlus = minPlus < A[i] + i + 1 ? minPlus : A[i] + i + 1;
        maxMinus = maxMinus > A[i] - i - 1 ? maxMinus : A[i] - i - 1;
        maxPlus = maxPlus > A[i] + i + 1 ? maxPlus : A[i] + i + 1;
        // cout<<minMinus<<" "<<minPlus<<" "<<maxMinus<<" "<<maxPlus<<endl;
    }
        cout<<minMinus<<" "<<maxMinus<<endl;
        cout<<minPlus<<" "<<maxPlus<<endl;
    return max(abs(minMinus - maxMinus), abs(minPlus - maxPlus));
}


int main (){
    //code
    // vector<int> v{1, 3, -1};
    vector<int> v{2,2,2};
    cout<<maxArr(v);
    return 0;
}
