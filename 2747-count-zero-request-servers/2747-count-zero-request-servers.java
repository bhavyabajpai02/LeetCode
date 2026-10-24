class Solution {
    public int[] countServers(int n, int[][] logs, int x, int[] queries) {
        int Q = queries.length;
        int[] answer = new int[Q];
        int[][] sortedQueries = new int [Q][2];
        for(int i = 0 ; i<Q; i++){
            sortedQueries[i][0] = i;
            sortedQueries[i][1] = queries[i];
        }

        Arrays.sort(logs,(a,b) -> a[1]- b[1]);
        Arrays.sort(sortedQueries,(a,b) -> a[1]- b[1]);
        int start = 0; 
        int end= 0;
        Map<Integer,Integer> freqMap = new HashMap<>();
        for(int[] query :sortedQueries){
            int ind = query[0];
            int max = query[1];
            int min = max-x;
            while(end < logs.length && logs[end][1] <= max){
                freqMap.put(logs[end][0] , freqMap.getOrDefault(logs[end][0],0) +1);
                end++;
            }

            while(start <end  && logs[start][1] < min){
                freqMap.put(logs[start][0], freqMap.get(logs[start][0]) -1);
                if(freqMap.get(logs[start][0]) == 0){
                    freqMap.remove(logs[start][0]);
                }
                start += 1; 
            }
            answer[ind] = n- freqMap.size();
        }
        return answer;
    }
}