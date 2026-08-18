class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {

        vector<pair<int,int>> adj[n];

        for(auto &it : flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        vector<int> dist(n, 1e9);

        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>
        > pq;
        dist[src] = 0;
        pq.push({0, {0, src}});

        while(!pq.empty()) {

            auto it = pq.top();
            pq.pop();

            int step = it.first;
            int cost = it.second.first;
            int node = it.second.second;

            if(step >k )
                continue;
          
            for(auto &edge : adj[node]) {

                int adjnode = edge.first;
                int adjwt = edge.second;

                if(cost + adjwt < dist[adjnode] && step<=k) {

                    dist[adjnode] = cost + adjwt;

                    pq.push({step+1,{ dist[adjnode] , adjnode}});
                }
            }
        }

        if(dist[dst]==1e9)return -1;
        return dist[dst];
    }
};