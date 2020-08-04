#include<bits/stdc++.h>
using namespace std;

void getAll(vector<string> &ans, int n, string &str, string &A, vector<string> &hashTable) {
    if(n==A.size()) {
        ans.push_back(str);
    }
    int digit = (int)A[n] - 48;
    for(int i=0; i<hashTable[digit].size(); i++) {
        str[n] = hashTable[digit][i];
        n++;
        getAll(ans, n, str, A, hashTable);
        n--;
    }
}

vector<string> letterCombinations(string A) {
    vector<string> hashTable{"0", "1", "abc", "def", "ghi", "jkl", 
                               "mno", "pqrs", "tuv", "wxyz"}; 
    vector<string> ans;
    string str = A;
    getAll(ans, 0, str, A, hashTable);
    return ans;
}


int main (){
    //code
    string a = "23";
    vector<string> ans;
    ans = letterCombinations(a);
    for(auto el: ans)
    cout<<el<<" ";
    return 0;
}
