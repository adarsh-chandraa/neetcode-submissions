class DisjointSet
{
     public:
        vector<int> parent, rank, size;
        DisjointSet(int n)
        {
            rank.resize(n + 1, 0);
            parent.resize(n + 1);
            size.resize(n + 1);
            for (int i = 0; i <= n; i++)
            {
                parent[i] = i;
                size[i] = 1;
            }
    }
    int findpar(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=findpar(parent[node]);
    }
    void unionByRank(int u,int v){
        int ulp_u= findpar(u);
        int ulp_v = findpar(v);
        if(ulp_u==ulp_v) return;
        if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u]=ulp_v;
        }
        else if(rank[ulp_v]<rank[ulp_u]){
            parent[ulp_v]=ulp_u;
        }
        else{
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        } 
    }
    void unionBySize(int u,int v){
        int ulp_u= findpar(u);
        int ulp_v = findpar(v);
        if(ulp_u==ulp_v) return;
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        } 
    }
};
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
           int n = grid.size();
        int m = grid[0].size();
        DisjointSet ds(n*m);
        int dr[] = {-1,0,+1,0};
        int dc[] = {0,+1,+0,-1};
        for(int i = 0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]== 0)continue;
                for(int k = 0;k<4;k++){
                    int nr = i +dr[k];
                    int nc = j + dc[k];
                    if( nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1){
                    int val1 = i*m+j;
                    int val2 = nr*m+nc;
                    
                        ds.unionBySize(val1,val2);
                    }
                    
                }
            }
        }
        int ans = 0;
        for(int i = 0;i<n*m;i++){
            if(ds.parent[i]==i && grid[i/m][i%m]==1) ans = max(ans,ds.size[i]);
        }
        return ans;
    }
};
