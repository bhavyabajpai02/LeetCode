class Solution {
public:
    string multiply(string num1, string num2) {
        if( num1 == "0" or num2 == "0") return "0";
        int  n= num1.length(),m = num2.length();
        string s ="";
        int count =0;
        for(int i=n-1; i>=0 ; i--){
            string r ="";
                for(int l=0; l<count; l++)
                r+='0';
            int carry = 0;
            for(int j=m-1; j>=0 ; j--){
                int mul = ((num1[i]-'0') *(num2[j]-'0'));
                int sum = carry + mul;
                carry = sum/10;
                sum = sum%10;
                r+=( sum+'0');
            }
            if(carry){
                r += (carry+'0');
            }
            count++;
            if(s.empty())s = r;
            else{
                int d=0,f = 0, c=0;
                while(d<s.length() and f<r.length()){
                    int sum = (s[d]-'0') +(r[f]-'0') + c;
                    c = sum/10;
                    sum = sum%10;
                    s[d] = sum+'0';
                    d++;
                    f++;
                }
                while(d<s.length()){
                    int sum = (s[d]-'0')+c;
                    c = sum/10;
                    sum = sum%10;
                    s[d] = sum+'0';
                    d++;
                }
                while(f<r.length()){
                    int sum = (r[f]-'0')+c;
                    c = sum/10;
                    sum = sum%10;
                    s+=sum+'0';
                    f++;
                }
                if(c){
                    s += (c+'0');
                }
            }
        }
        reverse(s.begin(),s.end());
        return s; 
    }
};