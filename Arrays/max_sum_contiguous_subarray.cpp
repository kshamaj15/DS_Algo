#include<iostream>
#include<vector>
using namespace std;

int maxSubArray(const vector<int> &A) {
    int sum = A[0];
    int finalSum = A[0];
    for(int i=1; i<A.size(); i++) {
        if(sum < 0) {
            sum = A[i];
            finalSum = finalSum > sum ? finalSum : sum;
        } else {
            sum += A[i];
            finalSum = finalSum > sum ? finalSum : sum;
            cout<<i<<" "<<sum<<" "<<finalSum<<endl;
        }
    }
    return finalSum;
}


int main() {
    vector<int> a({-163, -20});
    int b;
    b = maxSubArray(a);
    cout<<b;
    return 0;
}