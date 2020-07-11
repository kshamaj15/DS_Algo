#include<iostream>
#include<vector>
using namespace std;

void repeatedNumber(const vector<int> &A) {
    int n = A.size();
    int idealSum = n*(n+1)/2;
    int idealSqSum = n*(n+1)*(2*n+1)/6;
    int realSum = 0;
    int realSqSum = 0;
    for(auto el: A) {
        realSum += el;
        realSqSum += el*el;
    }
    int sDiff = idealSum - realSum;
    int sqDiff = idealSqSum - realSqSum;
    int numAdd = sqDiff/sDiff;
    int a = (numAdd + sDiff)/2;
    int b = (numAdd - sDiff)/2;
    cout<<sDiff<<endl;
    cout<<sqDiff<<endl;
    cout<<a<<endl;
    cout<<b<<endl;
}

void repeatedNumber1(const vector<int> &A) {
    int sDiff = 0;
    int sqDiff = 0;
    for(int i=0; i<A.size(); i++) {
        int s1 = (i+1) - A[i];
        sDiff += s1;
        int s2 = (i+1)*(i+1) - A[i]*A[i];
        sqDiff += s2;
    }
    
    int numAdd = sqDiff/sDiff;
    int a = (numAdd + sDiff)/2;
    int b = (numAdd - sDiff)/2;
    cout<<sDiff<<endl;
    cout<<sqDiff<<endl;
    cout<<a<<endl;
    cout<<b<<endl;
}

int main() {
    vector<int> a({1, 2, 5, 3, 3});
    repeatedNumber(a);
    repeatedNumber1(a);
    return 0;
}
