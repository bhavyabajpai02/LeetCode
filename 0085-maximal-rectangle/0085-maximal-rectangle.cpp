class Solution {
public:
    vector<int>prevSmall(vector<int>&v){
        stack<int>st;
        vector<int>res(v.size());
        for(int i = 0 ; i<v.size(); i++){
            while(!st.empty() and v[st.top()] >= v[i]){
                st.pop();
            }
            if(st.empty()) res[i] = -1;
            else{
                res[i] = st.top();
            }
            st.push(i);
        }
        return res;
    }
    vector<int>nextSmall(vector<int>&v){
        stack<int>st;
        vector<int>res(v.size());
        for(int i = v.size()-1 ; i>=0; i--){
            while(!st.empty() and v[st.top()] >= v[i]){
                st.pop();
            }
            if(st.empty()) res[i] = v.size();
            else{
                res[i] = st.top();
            }
            st.push(i);
        }
        return res;
    }
    int largestArea(vector<int> v){
        vector<int>prev = prevSmall(v);
        vector<int>next = nextSmall(v);
        // for(int i:prev){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        // for(int i:next){
        //     cout<<i<<" ";
        // }
        int maxarea = 0;
        for(int i = 0; i<v.size(); i++){
            int l = v[i];
            int b = next[i]-prev[i]-1;
            maxarea = max(maxarea,l*b);
        }
        // cout<<maxarea<<endl;
        return maxarea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int>v;
        int i=0,one = 0,maxone = 0;
        for(int j= 0; j<matrix[0].size(); j++){
            if(matrix[i][j] == '1'){
                one++;
            }else{
                maxone = max(maxone,one);
                one = 0;
            }
            // cout<<matrix[i][j]<<endl;
            v.push_back(matrix[i][j]-'0');
        }
        maxone = max(one,maxone);
        // for(auto i:v){
        //         cout<<i<<" ";
        //     }
        //     cout<<endl;
        int area = maxone;
        for(int i =1 ; i<matrix.size(); i++){
            for(int j = 0 ; j< matrix[0].size() ; j++){
                if(matrix[i][j] == '0'){
                    v[j] = 0;
                }
                else{
                    v[j] +=( matrix[i][j]-'0'); 
                }
            }
            // for(auto i:v){
            //     cout<<i<<" ";
            // }
            // cout<<endl;
            area = max(area,largestArea(v));

        }
        return area;
    }
};