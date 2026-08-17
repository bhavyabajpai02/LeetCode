class Solution {
    public int garbageCollection(String[] garbage, int[] travel) {
        int n = garbage.length, time = 0;
        int[] prefix = new int[n];
        prefix[0] = 0;
        for(int i = 1 ; i<n ; i++){
            prefix[i] = prefix[i-1]+travel[i-1];
        }
        int lastM =0 , lastP = 0 , lastG = 0;
        for(int i = 0 ; i< n ; i++){
            for(char c: garbage[i].toCharArray()){
                time++;
                if(c == ('G')) lastG = i;
                else if(c==('P')) lastP = i;
                else if(c==('M')) lastM = i;
            }
        }
        time += prefix[lastG]+prefix[lastM]+prefix[lastP];
        return time;
    }
}