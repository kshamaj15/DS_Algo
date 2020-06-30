#include<bits/stdc++.h>
using namespace std;

int isPalindrome(string sl) {
    transform(sl.begin(), sl.end(), sl.begin(), ::tolower);
    int ans = 1;
    int start = 0, end = sl.length()-1;
    while(end-start > 1) {
        if(isalnum(sl[start]) && isalnum(sl[end]) && (sl[start] == sl[end])) {
            start++;
            end--;
        } else if(!isalnum(sl[start]) && isalnum(sl[end])) {
            start++;
        } else if(isalnum(sl[start]) && !isalnum(sl[end])) {
            end--;
        } else if(!isalnum(sl[start]) && !isalnum(sl[end])) {
            end--;
            start++;
        } if(isalnum(sl[start]) && isalnum(sl[end]) && (sl[start] != sl[end])) {
            ans = 0;
            break;
        }
    }
    return ans;
}

int main() {
    cout<<isPalindrome("A man, a plan, a canal: Panama");
    return 0;
}