#include<bits/stdc++.h>
using namespace std;

int lengthOfLastWord(const string A) {
    int i = A.size()-1;
    int ans = 0;
    bool firstWord = false;
    while(i>=0 && (A[i] != ' ' || !firstWord)) {
        if(A[i] != ' ')
        firstWord = true;
        else
        ans = -1;
        cout<<A[i]<<endl;
        ans++;
        i--;
    }
    return ans;
}


int main (){
    //code

    cout<<lengthOfLastWord("Hello World     ");
    return 0;
}
