class Solution {
    boolean checkValid(char a){
        return (Character.isAlphabetic(a) || (a>='0' && a<='9')) ;
    }
    public boolean isPalindrome(String s) {
        int left = 0, right = s.length()-1;
        while(left < right){
            while(left < right && !checkValid(s.charAt(left))) left++;
            while(left < right && !checkValid(s.charAt(right))) right--;
            char a = s.charAt(left);
            char b = s.charAt(right);
            if(Character.isAlphabetic(a)){
                a = Character.toLowerCase(a);
            }
            if(Character.isAlphabetic(b)){
                b = Character.toLowerCase(b);
            }
            if(a != b) return false;
            left++;
            right--;
        }
        return true;
    }
}