#include<iostream>
#include<vector>
#include <stack>
using namespace std;

int largestRectangleUnderSkyline(vector<int> arr) {
  int n = arr.size();
  stack<int> s1;
  stack<int> s2;
  vector<int> pse(n);
  vector<int> nse(n);
  
  for(int i=0; i<n; i++) {
    if(s1.empty()) {
      pse[i] = -1;
    } else if(arr[s1.top()] < arr[i]) {
      pse[i] = s1.top();
    } else {
      while(!s1.empty() && arr[s1.top()] >= arr[i]) {
        s1.pop();
      }
      if(s1.empty()) {
        pse[i] = -1;
      } else if(arr[s1.top()] < arr[i]) {
        pse[i] = s1.top();
      }
    }
    s1.push(i);
  }

  for(int i=n-1; i>=0; i--) {
    if(s2.empty()) {
      nse[i] = n;
    } else if(arr[s2.top()] < arr[i]) {
      nse[i] = s2.top();
    } else {
      while(!s2.empty() && arr[s2.top()] >= arr[i]) {
        s2.pop();
      }
      if(s2.empty()) {
        nse[i] = n;
      } else if(arr[s2.top()] < arr[i]) {
        nse[i] = s2.top();
      }
    }
    s2.push(i);
  }

  int ans = 0;

  for(int i=0; i<n; i++) {
    int temp = arr[i] * (nse[i]-pse[i]-1); 
    ans = max(ans, temp);
  }

  return ans;
  
}

int main() {
    vector<int> v = {1, 3, 3, 2, 4, 1, 5, 3, 2};
    cout<<largestRectangleUnderSkyline(v);
}