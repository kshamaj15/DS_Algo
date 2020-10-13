// https://www.interviewbit.com/problems/maximum-absolute-difference/s
// time O(n)
// space O(1)

#include<bits/stdc++.h>
using namespace std;

int maxArr(vector<int> &A) {
    int minMinus = A[0]-1;
    int minPlus = A[0]+1;
    int maxMinus = A[0]-1;
    int maxPlus = A[0]+1;
    for(int i=1; i<A.size(); i++) {
        minMinus = minMinus < A[i] - i - 1 ? minMinus : A[i] - i - 1;
        minPlus = minPlus < A[i] + i + 1 ? minPlus : A[i] + i + 1;
        maxMinus = maxMinus > A[i] - i - 1 ? maxMinus : A[i] - i - 1;
        maxPlus = maxPlus > A[i] + i + 1 ? maxPlus : A[i] + i + 1;
    }
    return max(abs(minMinus - maxMinus), abs(maxMinus - maxPlus));
}


int main() {
    vector<int> A{0, 1, 1};
    cout<<maxArr(A)<<endl;
}
