class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
       vector<int>pre;
       vector<int>suff(nums.size(),1);
       int p = 1;
       int s = 1;
       int n = nums.size();
       for(int i = 0;i<nums.size();i++){
        if(i==0){
         pre.push_back(1);
         
        }
        else {
            p = p * nums[i-1];
            pre.push_back(p);
            s = s*nums[n-i];
            suff[n-1-i] = s;
        }
       }
       vector<int> result;
       for(int i = 0;i<n;i++){
           int v = pre[i]*suff[i];
           result.push_back(v);
       }
       return result;
    }
};
