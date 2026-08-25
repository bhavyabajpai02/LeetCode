class DSU{
    int size;
    int[] parent;
    DSU(int size){
        this.size = size;
        parent = new int[size+1];
        for(int i=0 ; i<size ; i++){
            parent[i] = i;
        }
    }
    // Fot finding Ultimate Parent
    int find(int u){
        if(parent[u] == u) return u;
        return  parent[u]=find(parent[u]);
    }

    void union(int u,int v){
        int p1 = find(u);
        int p2 = find(v);
        if(p1 != p2){
            parent[p2] = p1;
        }
    }
    boolean isConnected(int u,int v){
        int p1 = find(u);
        int p2 = find(v);
        return p1 == p2;
    }
}
class Solution {
    public int[] findRedundantConnection(int[][] edges) {
        int n = edges.length;
        DSU d = new DSU(n);
        for(int i=0; i<n ; i++){
            if (d.isConnected(edges[i][0], edges[i][1])) {
                return new int[]{edges[i][0], edges[i][1]};
            }

            // Otherwise connect them
            d.union(edges[i][0], edges[i][1]);
            d.union(edges[i][0],edges[i][1]);
        }
        return new int[] {-1,-1};
    }
}