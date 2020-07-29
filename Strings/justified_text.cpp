#include<bits/stdc++.h>
using namespace std;

vector<string> fullJustify(vector<string> &A, int B) {
     vector<string> ans;
    int i=0;
    int numOfWords = 0;
    bool islastLine = false;
    while(i<A.size()) {
        cout<<i<<" "<<A.size()<<endl;
        int s = B;
        string temp = A[i];
        numOfWords = 1;
        i++;
        if(i == A.size()) {
            islastLine = true;
        }
        while((temp.size() + A[i].size() + 1)<= B) {
            temp = temp + ' ' + A[i];
            numOfWords++;
            i++;
            // cout<<i<<" "<<A.size()<<endl;
            if(i == A.size()) {
                islastLine = true;
            }
            
        }
        if(!islastLine){
            int l = temp.size();
            string temp1 = "";
            int len = B;
            for(int i = 0; i<temp.size()-1; i++) { 
            temp1 = temp1+temp[i];
            if(temp[i] == ' ' && temp[i+1] != i) {
                int x = (len-l)/numOfWords;
                while(x--)
                temp1 += ' ';
                if((len-l)%numOfWords != 0) {
                    temp1 += ' ';
                    len--;
                }
            }
        }
        temp1 += temp[temp.size()-1];
        int y = (len-l)%numOfWords;
        while(y--)
            temp1 += ' ';
        ans.push_back(temp1);
        cout<<temp1.size()<<" ";
        }
        else {
            while(B>temp.size())
            temp += ' ';
            ans.push_back(temp);
            cout<<temp.size()<<endl;
        }
    }
    // cout<<endl;
    // cout<<"kshama       ";
    return ans;
}


int main (){
    //code
    // vector<string> v{"glu", "muskzjyen", "ahxkp", "t", "djmgzzyh", "jzudvh", "raji", "vmipiz", "sg", "rv", "mekoexzfmq", "fsrihvdnt", "yvnppem", "gidia", "fxjlzekp", "uvdaj", "ua", "pzagn", "bjffryz", "nkdd", "osrownxj", "fvluvpdj", "kkrpr", "khp", "eef", "aogrl", "gqfwfnaen", "qhujt", "vabjsmj", "ji", "f", "opihimudj", "awi", "jyjlyfavbg", "tqxupaaknt", "dvqxay", "ny", "ezxsvmqk", "ncsckq", "nzlce", "cxzdirg", "dnmaxql", "bhrgyuyc", "qtqt", "yka", "wkjriv", "xyfoxfcqzb", "fttsfs", "m"};
    // vector<string> v{"tv", "izln", "dkq", "ypbbix", "k", "xoojn", "xju", "xfe", "aysz", "agkfhvtqkt", "rsklvgn", "kedzohp", "lqzz", "hivu", "gtxrjj", "nz", "ysoatq", "n", "ote", "xuctw", "vlvgmfzm", "zlpmp", "oe", "kayhyihc", "yvsllceili", "osqkjjvydc", "p", "zxqrgyvnic", "ebxhww", "pyjdlt", "ruwl", "lnlt", "ddzf", "jicwez", "mcrj", "unbej", "on", "thivo", "sbzxsxvm", "jj", "lacb", "qfsopsmeq", "ial", "tifiuf", "uybh", "pcbufc", "nccdldzs", "pbsofijlmp", "ehdcxkgbi", "wu", "gvnzmw", "czonuzrls", "blg", "y", "qbdgiwboi", "wpeupcwz", "fxnbh", "sybikok", "ukuztzdqk", "oowhjnhol", "s", "kvmtoutvf", "ilh", "q", "tclbqcdbz", "oglfrq", "cwtucyecf", "am", "kflhesgk", "xnxpogj", "nx", "hwfb", "htmf", "xawcimlx", "hhivdgf", "uk", "evtsczh"};
    // vector<string> v{"tv","evtsczh"};
    vector<string> v{"juaphhhx", "i", "yqwcqwhz", "gbvlxgxqui", "ykpskmlbz", "sx", "noiejtchsf", "fvhavveg", "nf", "dzgpvqivig", "qmavb", "expme", "bxzqmpyexv", "jem", "xfdlieqlxk", "kpcatlxpwd", "vjyy", "azaxloqgdr", "pdewzh", "rthu", "hifukmc", "jlndt", "vv", "mpjqpeyj", "uuygpvyafz", "adjjtvofs", "bmupkh", "effip", "mdxewb", "opgsaovkiq", "jdmnp", "ixnm", "ihothmxm", "jybwoxq", "epsdpkbir", "xuhsljble", "lwtsbpgr", "cqhlom", "udhljevtzs", "n", "bbbdwhg", "ojkvndpnwx", "wsxcgqzf", "tfjsemc", "qdtbeh", "ilx", "fiicvj", "pfe", "igqgr", "sdo", "gid", "qxttqlqai", "msvpuigb", "mx", "qaxmqzft", "bh", "hwtlm", "h", "uw", "dbo", "nw", "fblocjnqe", "ptaq", "sjliea"};
    vector<string> ans;
    // cout<<v.size();
    ans = fullJustify(v, 313);
    for(auto str: ans) {
        cout<<str<<endl;
    }
    return 0;
}
