class Solution {
    public String removeKdigits(String num, int k) {
        StringBuilder s = new StringBuilder();
        for(int i=0 ; i<num.length()  ; i++){
            while(!s.isEmpty() && s.charAt(s.length()-1) > num.charAt(i) && k>0){
                s.deleteCharAt(s.length()-1);
                k--;
            } 
            s.append(num.charAt(i));
        }
        while(!s.isEmpty() && k>0){
            s.deleteCharAt(s.length()-1);
            k--;
        }
        int index = 0;
        // if(s.length()>1)
        while(index<s.length() &&s.charAt(index) == '0'){
            index++;
        }
        return index == s.length() ?"0":s.substring(index);
    }
}