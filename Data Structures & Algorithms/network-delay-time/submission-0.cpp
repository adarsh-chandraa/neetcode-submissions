class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
        >pq;
        vector<pair<int,int>>adj[n+1];
        for(int i= 0;i<times.size();i++){
                adj[times[i][0]].push_back({times[i][1],times[i][2]});
    
        }
        vector<int>dist(n+1,1e9);
        dist[k]=0;
        pq.push({0,k});
        while(!pq.empty()){
            auto it  = pq.top();
            int wt = it.first;
            int node = it.second;
            pq.pop();
            if(wt>dist[node])continue;

            for(auto &it:adj[node]){
                int adjwt = it.second;
                int adjnode = it.first;
                if(adjwt+wt<dist[adjnode]){
                    dist[adjnode] = wt+adjwt;
                    pq.push({dist[adjnode],adjnode});
                }
            }
        }
        int ans = 0;
        for(int i = 1;i<dist.size();i++){
            if(dist[i] ==1e9) return -1;
            ans = max(dist[i],ans);
        }
        return ans;
    }
};
