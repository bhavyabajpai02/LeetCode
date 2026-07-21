class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int r=1,l=0,res=0,n1,n2;
        if(bank.size() < 2){
            return 0;
        }
        while(r<bank.size()){
            n1= count(bank[l].begin(),bank[l].end(),'1');
            if(n1==0){
                l++;
                r++;
            }
            else{
                n2 =0;
                while(n2 == 0 and r<bank.size()){
                    n2 =count(bank[r].begin(),bank[r].end(),'1');
                    if(n2==0)
                    r++;
                } 
                if(r==bank.size()){
                    break;
                }
                res += (n1*n2);
                l=r;
                r++;
            }
        }
        // if(n1 !=0 and n2!=0){
        //     res +=(n1*n2);
        // }
        return res;
    }
};