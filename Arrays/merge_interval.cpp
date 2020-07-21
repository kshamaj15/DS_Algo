#include<bits/stdc++.h>
using namespace std;

struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
  };

vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
    vector<Interval> inter;
    for(auto el: intervals) {
        if(newInterval.start >= el.start && newInterval.end <= el.end) {
            inter.push_back(el);
        } else if (newInterval.start >= el.start && newInterval.end >= el.end) {
            Interval temp;
            temp.start = el.start;
            temp.end = newInterval.end;
            inter.push_back(temp);
        } else if (newInterval.start <= el.start && newInterval.end <= el.end) {
            Interval temp;
            temp.start = newInterval.start;
            temp.end = el.end;
            inter.push_back(temp);
        }
    }
    return inter;
}


int main (){
    
    vector<Interval> intervals;

    //code
    return 0;
}
