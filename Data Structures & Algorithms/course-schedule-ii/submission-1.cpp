class Solution {
private:
bool cycle(int node,vector<int>&vis,vector<int>&path,vector<int>adj[]){
    vis[node]=1;
    path[node]=1;
    for(auto &it:adj[node]){
        if(!vis[it]){
            if(cycle(it,vis,path,adj)) return true;
        }
        else if(path[it]) return true;
    }

    path[node]=0;
    return false;
}
void toposort(int node,vector<int>adj[],vector<int>&vis,stack<int>&st){
    vis[node] =1;
    for(auto &it:adj[node]){
        if(!vis[it])toposort(it,adj,vis,st);
    }
    st.push(node);
}
public:
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>adj[numCourses];

        for(auto &it:prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        vector<int>vis(numCourses,0);
        vector<int>path(numCourses,0);
        for(int i =0;i<numCourses;i++){
            if(!vis[i]){
                if(cycle(i,vis,path,adj)) return{};
            }
        }
        stack<int>st;
        vector<int>vis1(numCourses,0);
        for(int i =0;i<numCourses;i++){
            if(!vis1[i]) toposort(i,adj,vis1,st);
        }
        vector<int>ans;
        while(!st.empty()){
            int temp = st.top();
            st.pop();
            ans.push_back(temp);
        }
        //reverse(ans.begin(),ans.end());
        return ans;
    }
};
