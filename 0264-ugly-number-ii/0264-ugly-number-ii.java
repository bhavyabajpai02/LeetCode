class Solution {
    
    public int nthUglyNumber(int n) {
        PriorityQueue<Long> pq = new PriorityQueue<>();
        HashSet<Long> st = new HashSet<>();
        pq.offer(1L);
        st.add(1L);
        long curr = 1;
        for(int i = 0; i<n ; i++){
            curr = pq.poll();
            if(!st.contains(curr*2)){
                pq.offer(curr*2);
                st.add(curr*2);
            }
            if(!st.contains(curr*3)){
                pq.offer(curr*3);
                st.add(curr*3);
            }
            if(!st.contains(curr*5)){
                pq.offer(curr*5);
                st.add(curr*5);
            }
        }
        return (int)curr;
    }
}