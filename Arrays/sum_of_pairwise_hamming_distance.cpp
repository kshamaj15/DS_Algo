#include<bits/stdc++.h>
using namespace std;

int hammingDistance(const vector<int> &B) {
    int sum = 0;
    vector<int> A = B;
    for(int i=0; i<A.size();i++) {
        for(int j=i+1; j<A.size(); j++) {
            // cout<<"a ";
            cout<<A[i]<<" "<<A[j]<<endl;
            int a = A[i];
            int b = A[j];
            while(a != 0 && b != 0) {
                if(a%2 != b%2) {
                    sum++;
                    cout<<a<<", "<<b<<endl;
                }
                
                a = a/2;
                b = b/2;
            }
        }
    }
    return 2*sum;
}


int main (){
    //code
    vector<int> v{2,4,6};
    cout<<hammingDistance(v);
    return 0;
}
