#include<bits/stdc++.h>
using namespace std;

int getValue(char c) {
    if(c=='r')
    return 1;
    else if(c == 'g')
    return 2;
    else
    return 3;
}

int solve(vector<string> &A) {
    bool r = false;
    bool g = false;
    bool b = false;
    int n = A.size();
    int m = A[0].size();
    // cout<<A[0][0];
    for(int i=0 ; i<n; i++) {
        // cout<<A[i][m-1]<<" ";
        if(A[i][m-1] == 'r')
        r = true;
        else if(A[i][m-1] == 'g')
        g = true;
        else if(A[i][m-1] == 'b')
        b = true;
    }
    int start = 0;
    int end = n-1;
    int i = 0;
    while(i<m) {
        end = n-1;
        int temp = A[0][i];
        while(temp != A[end][i] && end>=0) {
            if(getValue(temp) + getValue(A[end][i]) == 3 && b) {
                cout<<"a";
                cout<<(m-i)<<" "<<end<<" "<<n<<" "<<i<<endl;
                return (m-i)*max(end+1, n-end)/2;
            }
            else if(getValue(temp) + getValue(A[end][i]) == 4 && g) { 
                cout<<"b";
                cout<<(m-i)<<" "<<end<<" "<<n<<" "<<i<<endl;
                return (m-i)*max(end+1, n-end)/2;
            }
            else if(getValue(temp) + getValue(A[end][i]) == 5 && r) {
                cout<<"c";
                return (m-i)*max(end+1, n-end)/2;
            }
            else
            end--;
        }
        cout<<i << " "<<m <<endl;
        i++;
    }
    return 0;
}


int main (){
    //code
    // vector<string> v{"rrr", "rrr", "rrr", "rrr"};
    vector<string> v{"rbbbggrbrbrggrgr", "bgbrbbrgggrgrrrr", "rgbrrrbbgbbbrrrb", "bbgbrgrbbrgrrgbb", "ggbrbrrbggggrrgb", "bgbrbrggbgrrgbrg", "grbbbgrbgbbgbbgr", "rbgbgbrrgrgbgbbr", "gbgrrgbbrrbbgbbg", "brgrbbrrbrgbgbrb", "rbbrrrbgrbgrbbrg", "rrggrrbbbrgbgggg", "rrrrgbbrgbbgbbrg", "rgbgrrrrggbbrrgr", "ggbrbbbbgrrrbrbb", "gggggrgbrbrbrrgr"};
    cout<<solve(v);
    return 0;
}
