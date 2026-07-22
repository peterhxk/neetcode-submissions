class Solution {
public:
    int find(int i, vector<int>& parent){
        while (i != parent[i]){
            parent[i]=parent[parent[i]];
            i = parent[i];
        }
        return i;
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> parent(n);
        vector<int> rank(n);
        for (int i = 0; i<n; i++){
            parent[i]=i;
        }
        for (auto edge: edges){
            int a = edge[0];
            int b = edge[1];
            int pa = find(a, parent);
            int pb = find(b, parent);
            if (rank[pa]<rank[pb]){
                parent[pa]=pb;
            }
            else if(rank[pb]<rank[pa]){
                parent[pb]=pa;
            }
            else{
                parent[pa]=pb;
                rank[pb]++;
            }
        }
        int ret = 0;
        unordered_set<int> parents;
        for (auto node: parent){
            int p = find(node,parent);
            //cout<<"node: "<<node<<" parent: "<<p<<endl;
            if (!parents.count(p)){
                parents.insert(p);
                ret++;
            }
        }
        return ret;
    }
};