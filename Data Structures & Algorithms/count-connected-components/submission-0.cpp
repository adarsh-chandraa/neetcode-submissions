class DisjointSet{
    public:
    vector<int>parent,size,rank;
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1);
        rank.resize(n+1,0);
        for(int i = 0;i<n;i++){
            parent[i]=i;
        }
    }

    int findpar(int node){
        if(parent[node]==node) return node;
        return parent[node]= findpar(parent[node]);
    }

    void unionByRank(int u,int v){
        int ulp_u= findpar(u);
        int ulp_v = findpar(v);
        if(ulp_u==ulp_v) return;
        else if(rank[ulp_u] > rank[ulp_v]){
             parent[ulp_v] = ulp_u;
             rank[ulp_v] = ulp_u;
        }
        else if(rank[ulp_u] < rank[ulp_v]){
             parent[ulp_u] = ulp_v;
             rank[ulp_u] = ulp_v;
        }
        else{
            parent[ulp_v] = ulp_u;
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
    int countComponents(int n, vector<vector<int>>& edges) {
         DisjointSet ds(n);
         for(int i = 0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            ds.unionBySize(u,v);

         }
        int cnt = 0;
         for(int i = 0;i<n;i++){
            if(ds.parent[i]==i) cnt++;
         }
         return cnt;
    }
};
