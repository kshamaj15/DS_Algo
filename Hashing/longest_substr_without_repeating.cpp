#include<bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string str) {
        int n = str.size(); 
    int NO_OF_CHARS = 256;
    int res = 0; // result 
  
    // last index of all characters is initialized 
    // as -1 
    vector<int> lastIndex(NO_OF_CHARS, -1); 
  
    // Initialize start of current window 
    int i = 0; 
  
    // Move end of current window 
    for (int j = 0; j < n; j++) { 
  
        // Find the last index of str[j] 
        // Update i (starting index of current window) 
        // as maximum of current value of i and last 
        // index plus 1 
        i = max(i, lastIndex[str[j]] + 1); 
        // i = lastIndex[str[j]] + 1; 
  
        // Update result if we get a larger window 
        res = max(res, j - i + 1); 
  
        // Update last index of j. 
        lastIndex[str[j]] = j; 
    }
    return res;
}

int myFunction(string str) {
    unordered_map<char, int> map;
    int start = 0, end = 0;
    int fs, se;
    int mx = 0;
    for(int i=0; i<str.size(); i++) {
        if(map[str[i]] >= start) {
            start = map[str[i]];
        }
        map[str[i]] = i+1;
        end++;
        mx = max(mx, end-start);
    }
    return mx;
}


int main (){
    //code
    cout<<lengthOfLongestSubstring("rujdfrhdhh");
    cout<<endl;
    cout<<myFunction("rujdfrhdhh");
    return 0;
}
