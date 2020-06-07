#include<bits/stdc++.h>
using namespace std;

string simplifyPath(string A) {
    stack<string> stk;
    string ans = "";
    string temp = "";
    for(int i=1; i<A.length(); i++) {
        if(A[i] != '.' && A[i] != '/') {
            temp = temp + A[i];
        } else if(A[i] == '/') {
            if(temp != "")
            stk.push(temp);
            temp = "";
        } else if(A[i] == '.') {
            if(A[i+1] == '.') {
                if(!stk.empty())
                stk.pop();
            }
        }
        if(i == A.size()-1 && temp != "")
        stk.push(temp);
    }
    if(stk.empty())
    ans = "/";
    while (!stk.empty()) {
        ans = "/" + stk.top() + ans;
        stk.pop();
    }
    return ans;
}

int main() {
    string a = "/home//foo/";
    // string a = "/cbj/vfb/dyj/../../hjq/./unc/./cmv/./axj/../pzg/svs/oja/./rlc/vyr/cqq/../omk/viy/kyb/../ygr/mbx/nom/yvh/./../././lyg/qjv/./lwm/.././.././xga/krs/../xkl/wtj/nml/dal/hat/alw/jvo/./../xts/nul/yfe/upg/zhy/nzo/dtp/nqt/hqk/./../ref/gms/zhp/./bpp/jis/ccc/bmn/iip/nfv/../vbk/ugr/gpd/uez/./bqt/zqy/../vuf/ltg/mxm/../lvr/vef/../wpp/./rbc/xii/pkf/jsx/././xwo";
    string f = simplifyPath(a);
    cout << f;
}

