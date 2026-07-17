class Solution {
public:
    int rec(int i,int j,int m , int n , vector<vector<int>>&mp){
        if(i>m or j>n) return 0;
        if(i == m and j == n){
            return 1;
        }
        if(mp[i][j] != -1){
            return mp[i][j];
        }
        int right = rec(i,j+1,m,n,mp); 
        int left = rec(i+1,j,m,n,mp); 
        mp[i][j] = right+left;
        return mp[i][j];
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>mp(m+1,vector<int>(n+1,-1));
        
        return rec(0,0,m-1,n-1,mp);
    }
};