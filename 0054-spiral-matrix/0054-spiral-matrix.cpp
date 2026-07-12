class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>res;
        int count = 0,row = matrix.size(),col= matrix[0].size(),startrow=0 , endrow = matrix.size()-1,startcol = 0, endcol = matrix[0].size()-1;
        int  total =  row*col;
        while(count< total){
            for(int i=startcol; i<=endcol and count<total ; i++){
                res.push_back(matrix[startrow][i]);
                count++;
            }
            startrow++;
            for(int i = startrow ; i<=endrow and count<total ; i++){
                res.push_back(matrix[i][endcol]);
                count++;
            }
            endcol--;
            for(int i= endcol ; i>=startcol and count<total; i--){
                res.push_back(matrix[endrow][i]);
                count++;
            }
            endrow--;
            for(int i = endrow; i>=startrow and count<total ; i--){
                res.push_back(matrix[i][startcol]);
                count++;
            }
            startcol++;
        }
        return res;
    }
};