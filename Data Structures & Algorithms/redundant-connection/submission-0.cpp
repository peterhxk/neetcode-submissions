class Solution {
public:
    vector<int> parents;
    vector<int> rank;

    int find(int node){
        while (node != parents[node]){
            parents[node] = parents[parents[node]];
            node = parents[node];
        }
        return node;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int l = edges.size()+1;
        parents = vector<int>(l);
        rank = vector<int>(l);
        
        for (int i = 0; i<l; i++){
            parents[i]=i;
            rank[i]=0;
        }
        vector<int> ret;
        for (vector<int> edge: edges){
            int a = edge[0];
            int b = edge[1];
            int p1 = find(a);
            int p2 = find(b);
            if (p1 == p2){
                ret = {a,b};
            }
            else{
                if (rank[p1]>rank[p2]){
                    parents[p2]=p1;
                }
                else if(rank[p2]>rank[p1]){
                    parents[p1]=p2;
                }
                else{
                    parents[p2]=p1;
                    rank[p1]++;
                }
            }
        }
        return ret;

    }
};
