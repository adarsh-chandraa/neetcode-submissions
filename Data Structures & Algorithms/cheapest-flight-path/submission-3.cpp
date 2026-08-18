class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>>adj[n];
        for(auto &it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int>dist(n,1e9);
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{src,0}});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int step = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            if(step > k) continue;
            for(auto &it:adj[node]){
                int adjnode = it.first;
                int adjwt = it.second;
                if(adjwt+ cost <dist[adjnode] && step<=k){
                    dist[adjnode] = adjwt + cost;
                    q.push({step+1,{adjnode,adjwt+cost}});
                }
            }
        }
        if(dist[dst] ==1e9) return -1;
        return dist[dst];
    }
};