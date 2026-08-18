class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(auto &it:nums){
            mp[it]++;
        }
        vector<pair<int,int>> v(mp.begin(), mp.end());
        sort(v.begin(),v.end(),[](auto &a,auto &b){
            if(a.second == b.second) return a.first < b.first;
        return a.second > b.second;
        });
        int i = 1;
        vector<int>ans;
        for(auto &it:v){
            ans.push_back(it.first);
            if(i==k)break;
            i++;
        }
        return ans;
    }
};
