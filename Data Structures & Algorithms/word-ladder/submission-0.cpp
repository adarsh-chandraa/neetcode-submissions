class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<int,string>>q;
        q.push({1,beginWord});
        set<string>st(wordList.begin(),wordList.end());
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int t = it.first;
            string s = it.second;
            if(s == endWord) return t;
            for(int i= 0;i<s.size();i++){
                string temp = s;
              for(int ch = 'a';ch<='z';ch++){
                 s[i] = ch;
                 if(st.find(s)!=st.end()){
                    q.push({t+1,s});
                    st.erase(s);
                 }
                s  = temp;
            }
            }
           
        }
        return 0;
    }
};
