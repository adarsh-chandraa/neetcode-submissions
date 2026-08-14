class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st(nums.begin(),nums.end());
        int ans = 0;
        for(auto &it:st){
            if(!st.count(it-1)){
            int next = it+1;
            int temp = 1;
            while(st.count(next)){
                temp++;
                next++;
            }
            
            ans = max(ans,temp);
            }
        }
        return ans;
    }
};
