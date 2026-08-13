class Solution {
    void backtrack(int o , int c, int n , StringBuffer s, ArrayList<String> a){
        if(s.length()  == n*2){
            a.add(s.toString());
            return;
        }
        if(o<n) {
            s.append('(');
            backtrack(o+1,c,n,s,a);
            s.deleteCharAt(s.length()-1);
        }
        if(c<o) {
            s.append(')');
            backtrack(o,c+1,n,s,a);
            s.deleteCharAt(s.length()-1);
        }
    }
    public List<String> generateParenthesis(int n) {
        StringBuffer s = new StringBuffer();
        ArrayList<String> a = new ArrayList<>();
        backtrack(0,0,n,s,a);
        return a;
    }
}