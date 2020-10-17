// https://www.interviewbit.com/problems/power-of-two-integers/
// time worst case: O(sqrt(n)*log(n))
// space: O(1)

#include<bits/stdc++.h>
using namespace std;

int isPower(int A) 
{
    if(A==1)
    return 1;
    for(int i=2;i<=sqrt(A);i++)
    {
        long long int num=1;
        while(true)
        {
            num=num*i;
            if(num==A)
            return 1;
            
            else if(num>A)
            break;
        }
    }
    
    return 0;
}

int main() {
    int n;
    cin>>n;
    cout<<isPower(n);
}