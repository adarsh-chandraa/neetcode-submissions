class Solution {
public:

    string encode(vector<string>& strs) {
        string s = "";
        for(string it:strs){
           
            s = s + it;
             s = s+ '~';
        }
        return s;
    }

    vector<string> decode(string s) {
        vector<string>ans;
        string v = "";
        for(int i = 0;i<s.size();i++){
            if(s[i]=='~'){
                ans.push_back(v);
                v = "";
            }
            else {
                v = v+s[i];
            }
        }
        return ans;
    }
};
