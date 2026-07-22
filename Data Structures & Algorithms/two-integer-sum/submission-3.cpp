class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        for(int i = 0; i < nums.size(); i++){
            int v = target - nums[i];
            if(mp.count(v)) return {mp[v], i};
            else mp[nums[i]] = i;
        }
        return {-1,-1};
    }
};
