class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
     unordered_map<int,int>mp;
     set<int>st;
     for(int i = 0;i<nums.size();i++){
        if(st.find(nums[i])!=st.end()) return true;
        else st.insert(nums[i]);
     }
     return false;
    }
};