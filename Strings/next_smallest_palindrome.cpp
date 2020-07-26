#include<bits/stdc++.h>
using namespace std;

string solve(string A) {
    if(A.size() == 1) {
        int n = stoi(A);
        if(n != 9) {
            n++;
            return to_string(n);
        }
        return "11";
    } else if(A.size() == 2) {
        int n = stoi(A);
        if(n%10 < n/10) {
            n = n + (n/10 - n%10);
            return to_string(n);
        } else if(n%10 == n/10 && n!=99) {
            n+=11;
        } else if(n%10 > n/10) {
            n+=10;
            n-=(n%10 - n/10);
        } else if(n == 99) {
            n = 101;
        }
        return to_string(n);
    }
    string half1 = A.substr(0, (A.size()-1)/2);
    string ans;
    string half2 = A.substr(A.size()/2+1, A.size()-1);
    string rhalf2 = half2;
    reverse(rhalf2.begin(), rhalf2.end());
    if(half1 > half2 || half2 > rhalf2) {
        ans = half1 + A.substr((A.size()-1)/2, 2-(A.size()%2)) + half2 ;
        // cout<<A.substr((A.size()-1)/2, 2-(A.size()%2))<<endl;

        string cpy = half1;
        reverse(half1.begin(), half1.end());
        return cpy + A.substr((A.size()-1)/2, 2-(A.size()%2)) + half1;
        // cout<<half1<<endl;
        // cout<<half2<<endl;
    } else {
        ans = half1 + A.substr((A.size()-1)/2, 2-(A.size()%2)) + half2 ;
        // cout<<A.substr((A.size()-1)/2, 2-(A.size()%2))<<endl;
        string cpy = half1;
        reverse(half1.begin(), half1.end());
        if(A.size()%2) {
            // cout<<"sa";
            int mid = (int)(A[A.size()/2])-48;
            // cout<<mid<<endl;
            // cout<<to_string(mid)<<endl;
            if(mid != 9) {
                mid++;
                return cpy + to_string(mid) + half1;
            }
            else {
                int h1 = stoi(half1);
                h1++;
                string copy = to_string(h1);
                reverse(copy.begin(), copy.end());
                if(copy.size() > half1.size())
                return to_string(h1) + copy;
                else
                return to_string(h1) + "0" + copy;
            }
        } else {
            int mid0 = (int)(A[A.size()/2-1])-48;
            int mid1 = (int)(A[A.size()/2])-48;
            if(mid1 == mid0 && mid1 !=9) {
                mid1++;
                mid0++;
            } else if(mid1 > mid0) {
                mid0++;
                mid1 = mid0;
            } else if(mid1 < mid0) {
                mid1 = mid0;
            } else if(mid1 == mid0 && mid1 == 9) {
                long long int h1 = stoi(half1);
                h1++;
                string copy = to_string(h1);
                reverse(copy.begin(), copy.end());
                return to_string(h1) + "00" + copy;
            }
            int mid = mid1 + mid0*10;
            return cpy + to_string(mid) + half1;
        }
    }
    return "0";
    
    
    // return ans;
}


int main (){
    //code
    // solve("43216");
    // solve("61423221")<<endl;
    cout<<solve("61423221")<<endl;
    cout<<solve("171152");
    return 0;
}
