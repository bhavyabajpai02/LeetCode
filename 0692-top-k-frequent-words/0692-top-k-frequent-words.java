class Solution {
    public List<String> topKFrequent(String[] words, int k) {
        // ArrayList<ArrayList<Integer>> a = new ArrayList<>();
        HashMap<String,Integer> mp = new HashMap();
        for(int i=0 ; i<words.length; i++){
            mp.put(words[i], mp.getOrDefault(words[i],0)+1);
        }
        PriorityQueue<String> pq = new PriorityQueue<>((a,b) ->{
            if(!mp.get(a).equals(mp.get(b))){
                return mp.get(a) - mp.get(b);
            }
            // else if(mp.get(a) == )
            return b.compareTo(a);
        });
        for(String a: mp.keySet()){
            pq.offer(a);
            if(pq.size()>k) pq.poll();
        }
        ArrayList<String>a = new ArrayList<>();
        while(!pq.isEmpty()){
            a.add(0,pq.poll());
        }
        return a;
    }
}