class Solution {
public:
    int candy(vector<int>& ratings) {
        if(ratings.size() == 0) return 0;
        // int candy = 1 ;
        // 1st approach by using extra space O(n)
        // vector<int>candy(ratings.size(),1);
        // for(int i=1 ; i<ratings.size(); i++){
        //     if(ratings[i] > ratings[i-1]){
        //         candy[i] = candy[i-1]+1;
        //     }
        //     else if(ratings[i]< ratings[i-1]){
        //         candy[i-1] = candy[i]+1;
        //     }
        // }
        // for(int i=ratings.size()-2 ; i>=0 ; i--){
        //     if(ratings[i] > ratings[i+1]){
        //         candy[i] = max(candy[i],candy[i+1]+1);
        //     }
        //     else if(ratings[i]< ratings[i+1]){
        //         candy[i+1] = max(candy[i+1],candy[i]+1);
        //     }
        // }
        // int res = accumulate(candy.begin(),candy.end(),0);
        // return res;
        
        // 2nd approach
            int res =1;
            int up=0,down =0, peak =0;
            int i=1;
            while(i<ratings.size()){
                if(ratings[i]>ratings[i-1]){
                    up++;
                    peak = up;
                    down = 0;
                    res += up+1;
                }
                else if(ratings[i] == ratings[i-1]){
                    up = down = peak = 0;
                    res++;
                }
                else{
                    down++;
                    up=0;
                    res += down;
                    if(down>peak){
                        res++;
                    }
                }
                i++;
            }
            return res;
        // TRIALS
        // int candiesL=1,cR =1, n= ratings.size(),k=3;
        // bool check = false;
        // for(int i=1; i<n; i++){
        //     // if(ratings[i-1]>=ratings[i] ){
        //     //     k = 3;
        //     // }      
        //     // else k+=1;
        //     if(ratings[i]> ratings[i-1] and !check ){
        //         check = true;
        //         candiesL +=2;
        //     }
        //     else if(ratings[i] > ratings[i-1] and check){
        //         candiesL +=k;
        //         k+=1;
                
        //     }
        //     else if(ratings[i] < ratings[i-1] and !check){
        //         k=3;
        //         candiesL +=2;
        //     }

        //     else {
        //         k=3;
        //         check = false;
        //         candiesL++;
        //     }      
        //     cout<<candiesL<<" ";
        //     cout<<k<<" "<<endl; 
            
        // }
        // check = false;
        // for(int i=n-2; i>=0;i--){
        //     if(ratings[i]> ratings[i+1] and !check){
        //         check = true;
        //         cR +=2;
        //     }
        //     else if(ratings[i] > ratings[i+1] and check){
        //         cR +=3;
        //     }
        //     else if(ratings[i] < ratings[i+1] and !check){
        //         cR += 2;
        //     }
        //     else {
        //         check = false;
        //         cR++;
        //     }            
        // }
        // cout<<cR<<" "<<candiesL;
        // return max(cR,candiesL);

        // int i=1,left =1, n= ratings.size(),k,l;
        // while(i<n){
        //     if(ratings[i-1] == ratings[i]) {
        //         left++;
        //         i++;
        //         continue;
        //     }
        //     k=1;
        //     while(i<n and ratings[i-1] < ratings[i]){
        //         // check = true;
        //         left += k;
        //         k++;
        //         i++;
        //     }
        //     if( i<n and ratings[i-1] > ratings[i] and ((i-2>=0 and ratings[i-1] == ratings[i-2]) or i-1 == 0)){
        //         l=2;
        //     }
        //     else{
        //         // check = true;
        //         l=1;
        //     }
        //     while(i<n and ratings[i-1] > ratings[i]){
        //         left+=l;
        //         i++;
        //         l++;
        //     }
        //     left = left - min(k,l);
        // }
        // i = n-2;
        // while(i>=0){
        //     k=2;
        //     if(ratings[i+1] == ratings[i]) {
        //         right++;
        //         i--;
        //         continue;
        //     }
        //     while(i>=0 and ratings[i+1] < ratings[i]){
        //         // check = true;
        //         right += k;
        //         k++;
        //         i--;
        //     }
        //     if( i>=0 and ratings[i+1] > ratings[i] and ((i+2<n and ratings[i+1] == ratings[i+2]) or i+1 == n-1)){
        //         l=2;
        //     }
        //     else{
        //         // check = true;
        //         l=1;
        //     }
        //     while(i>=0 and ratings[i+1] > ratings[i]){
        //         right+=l;
        //         i--;
        //         l++;
        //     }
        // }
        // return max(left,right);
        // return left;
    }
};