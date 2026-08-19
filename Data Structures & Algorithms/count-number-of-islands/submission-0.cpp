class DisjointSet {
    public:
    vector<int>par;
    vector<int>rank,size;
    DisjointSet(int n){
        par.resize(n+1,0);
        rank.resize(n+1,0);
        size.resize(n+1);
        for(int i = 0;i<= n;i++){
            par[i] = i;
            size[i] = 1;
        }
    }
    int findpar(int n){
        if(par[n] == n) return n;
        return par[n] = findpar(par[n]);
    }
    void  unionByRank(int u,int v){
        int ulp_u = findpar(u);
        int ulp_v = findpar(v);
        if(ulp_u==ulp_v) return;
        if(rank[ulp_u] > rank[ulp_v]){
            par[ulp_v] = ulp_u;    
        }
        else if(rank[ulp_u] < rank[ulp_v]){
            par[ulp_u] = ulp_v;    
        }
        else {
            rank[ulp_u]++;
            par[ulp_v] = ulp_u;
        }
    }
      void unionBySize(int u,int v){
        int ulp_u= findpar(u);
        int ulp_v = findpar(v);
        if(ulp_u==ulp_v) return;
        if(size[ulp_u]<size[ulp_v]){
            par[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            par[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        } 
    }

};
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        DisjointSet ds(n*m);
        int dr[] = {-1,0,+1,0};
        int dc[] = {0,+1,+0,-1};
        for(int i = 0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='0')continue;
                for(int k = 0;k<4;k++){
                    int nr = i +dr[k];
                    int nc = j + dc[k];
                    if( nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]=='1'){
                    int val1 = i*m+j;
                    int val2 = nr*m+nc;
                    if(ds.findpar(val1) != ds.findpar(val2)){
                        ds.unionBySize(val1,val2);
                    }
                    else continue;
                    }
                }
            }
        }

        int ans = 0;
        for(int i = 0;i<n*m;i++){
        if(ds.par[i]==i && grid[i/m][i%m]=='1')ans++;
        }
        return ans;
    }
};
