class Solution {
    bool isvalid(int nr,int nc,int n,int m){
        return nr>=0 && nc>=0 && nr<n&& nc<m;
    }
public:
    int swimInWater(vector<vector<int>>& grid) {
              priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
              int dr[] = {-1,0,+1,0};
              int dc[] = {0,+1,0,-1};
        int n = grid.size();
        int m = grid[0].size();
        pq.push({grid[0][0],{0,0}});
        vector<vector<int>>vis(n,vector<int>(m,0));
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int t = it.first;
            int r = it.second.first;
            int c = it.second.second;
            if(r==n-1 && c == m-1 ) return t;
            for(int i = 0;i<4;i++){
                int nr = r+dr[i];
                int nc = c+dc[i];
                if(isvalid(nr,nc,n,m) && !vis[nr][nc]){
                    pq.push({max(t,grid[nr][nc]),{nr,nc}});
                    vis[nr][nc]=1;
                }
            }
        }
        return -1;
    }
};
