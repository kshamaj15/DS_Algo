
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct Node {
        int time;
        int x;
        int y;
    };
    int orangesRotting(vector<vector<int>>& grid) {
        queue<Node> q;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 2) {
                    struct Node n = {1, i, j};
                    q.push(n);
                }
            }
        }
        int time = 2;
        int ans;
        while(!q.empty()) {
            struct Node n = q.front();
            q.pop();
            
            if(n.x > 0 && grid[n.x-1][n.y] == 1) { // up
                struct Node m = {time, n.x-1, n.y};
                grid[n.x-1][n.y] = 2;
                ans = n.time;
                q.push(m);
            }
            if(n.y < grid[0].size() -1 && grid[n.x][n.y+1] == 1) { // right
                struct Node m = {time, n.x, n.y+1};
                grid[n.x][n.y+1] = 2;
                ans = n.time;
                q.push(m);
            }
            if(n.x < grid.size() - 1 && grid[n.x+1][n.y] == 1) { // down
                struct Node m = {time, n.x+1, n.y};
                grid[n.x+1][n.y] = 2;
                ans = n.time;
                q.push(m);
            }
            if(n.y > 0 && grid[n.x][n.y-1] == 1) { // left
                struct Node m = {time, n.x, n.y-1};
                grid[n.x][n.y-1] = 2;
                ans = n.time;
                q.push(m);
            }
            time++;
        }
        
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 1) {
                    cout<<i<<j<<endl;
                    return -1;
                }
            }
        }
        
        return ans;
    }
};

int main() {
    int n = 3,m = 3;;
    // cin>>n>>m;
    vector<vector<int>> grid(n, vector<int>(m, -1));
    grid = {
        {0,1,2},
        {0,1,2},
        {2,1,1}
    };
    // for(int i=0; i<n; i++)
    // for(int j=0; j<m; j++)
    // cin>>grid[i][j];
    Solution obj;
    cout << obj.orangesRotting(grid) << endl;
}