class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](vector<int>&a,vector<int>&b){
            if(a[0]==b[0]) return a[1]<b[1];
           return a[0]<b[0];
        });
         
         int prev = -1;
         int cnt  = 0;
         for(int i = 0;i<intervals.size();i++){
            if(prev == -1){
                prev = intervals[i][1];
                continue;
            }
            int curr = intervals[i][0];
            if(prev>curr){
                cnt++;
                prev = min(prev,intervals[i][1]);
            }
            else prev = intervals[i][1];
         }
        return cnt;
    }
};
