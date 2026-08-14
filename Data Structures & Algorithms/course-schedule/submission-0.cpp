class Solution {
    bool detectcycle(int      node,vector<int>&vis,vector<int>&path,vector<int>adj[]){
        vis[node] = 1;
        path[node]=1;
       for(auto &it:adj[node]){
        if(!vis[it]){
            if(detectcycle(it,vis,path,adj)) return true;
        }
        else if(path[it]) return true;
       }

        path[node] = 0;
        return false;
    }
public:
    bool canFinish(int numCourses , vector<vector<int>>& prerequisites) {
       vector<int>adj[numCourses];
       for(auto &it:prerequisites){
        adj[it[1]].push_back(it[0]);
       } 
       vector<int>vis(numCourses ,0);
       vector<int>path(numCourses ,0);
       for(int i = 0;i<numCourses ;i++){
          
          if(!vis[i]){
            if(detectcycle(i,vis,path,adj))return false;
          }

       }
       return true;
}
};
