class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        int n = triangle.size();
        int []temp = new int[n];
        for(int j = 0 ; j<n; j++ ){
            temp[j] = triangle.get(n-1).get(j);
        }
        for(int i=n-2 ; i>=0 ; i--){
            for(int j = 0 ; j <=i ; j++){
                temp[j] = triangle.get(i).get(j)+ Math.min(temp[j],temp[j+1]);
            }
        }
        return temp[0];
    }
}