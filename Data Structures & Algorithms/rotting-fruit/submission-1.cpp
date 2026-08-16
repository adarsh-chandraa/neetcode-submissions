class Solution {
public:
   int dr[4] = {-1,0,+1,0};
   int dc[4] = {0,+1,0,-1};
   bool isvalid(int nr,int nc,int n,int m){
    return nr>=0 && nr<n && nc>=0 && nc<m;
   }
    int orangesRotting(vector<vector<int>>& grid) {
        int n =   grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,pair<int,int>>>q;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                vis[i][j] = grid[i][j];
                if(grid[i][j]==2) q.push({0,{i,j}});
            }
        }

        int tm = 0;
        while(!q.empty()){
         auto it = q.front();
         q.pop();
         int t = it.first;
         int r= it.second.first;
         int c = it.second.second;
         tm = max(t,tm);

         for(int i = 0;i<4;i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(isvalid(nr,nc,n,m) && vis[nr][nc]==1 && grid[nr][nc]==1){
                vis[nr][nc]=2;
                q.push({t+1,{nr,nc}});
            }
         }
        }
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(vis[i][j]==1) return -1;
            }
        }
        return tm;
    }
};
