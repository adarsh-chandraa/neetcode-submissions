class Solution {
public:
int dr[4] = {-1,0,+1,0};
int dc[4] = {0,+1,0,-1};
bool isvalid(int r,int c,int n,int m){
    return r>=0 && c>=0 && r<n && c<m;
}
void dfs(int r ,int c,vector<vector<int>>&vis,vector<vector<char>>& board,int n,int m){
    vis[r][c]=1;
    for(int i = 0;i<4;i++){
           int nr = r+dr[i];
           int nc = c+dc[i];
        if(isvalid(nr,nc,n,m) && !vis[nr][nc] && board[nr][nc]=='O')dfs(nr,nc,vis,board,n,m);
    }
}
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(i== 0 || j==0 || i==n-1 || j==m-1){
                    if(board[i][j]=='O' && vis[i][j]==0){
                        cout<<i<<" "<<j;
                        dfs(i,j,vis,board,n,m);
                    }
                }
            }
        }
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(vis[i][j]==0 && board[i][j]=='O'){
                    board[i][j] ='X';
                }
            }
        }
    }
};
