#include<bits/stdc++.h>
using namespace std;

vector<string> fullJustify(vector<string> &A, int B) {
    vector<string> ans;
    int i=0;
    int numOfWords = 0;
    while(i<A.size()) {
        int s = B;
        string temp = A[i];
        numOfWords = 1;
        i++;
        while((temp.size() + A[i].size() + 1)<= B) {
            temp = temp + ' ' + A[i];
            numOfWords++;
            i++;
        }
        int l = temp.size();
        string temp1 = "";
        for(int i = 0; i<temp.size()-1; i++) { 
            temp1 = temp1+temp[i];
            if(temp[i] == ' ' && temp[i+1] != i) {
                int x = (B-l)/numOfWords;
                while(x--)
                temp1 += ' ';
            }
        }
        temp1 += temp[temp.size()-1];
        int y = (B-l)%numOfWords;
        while(y--)
            temp1 += ' ';
        ans.push_back(temp1);
    }
    return ans;
}


int main (){
    //code
    vector<string> v{"glu", "muskzjyen", "ahxkp", "t", "djmgzzyh", "jzudvh", "raji", "vmipiz", "sg", "rv", "mekoexzfmq", "fsrihvdnt", "yvnppem", "gidia", "fxjlzekp", "uvdaj", "ua", "pzagn", "bjffryz", "nkdd", "osrownxj", "fvluvpdj", "kkrpr", "khp", "eef", "aogrl", "gqfwfnaen", "qhujt", "vabjsmj", "ji", "f", "opihimudj", "awi", "jyjlyfavbg", "tqxupaaknt", "dvqxay", "ny", "ezxsvmqk", "ncsckq", "nzlce", "cxzdirg", "dnmaxql", "bhrgyuyc", "qtqt", "yka", "wkjriv", "xyfoxfcqzb", "fttsfs", "m"};
    vector<string> ans;
    ans = fullJustify(v, 144);
    for(auto str: ans) {
        cout<<str<<endl;
    }
    return 0;
}
