class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        vector<pair<int,int>> direction = {{0,1},{1,0}, {-1,0}, {0, -1}};

        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> q;
        map<pair<int,int>,int> shortest;
        q.push({grid[0][0], 0, 0});
        while (!q.empty()){
            auto cur = q.top();
            q.pop();
            int dist = get<0>(cur); int i = get<1>(cur); int j = get<2>(cur);
            //cout<<"dist: "<<dist<<endl;
            if (shortest.count({i,j})){
                continue;
            }
            if (i == grid.size()-1 && j == grid[0].size()-1){
                return dist;
            }
            shortest[{i,j}] = dist;
            for (auto [dx, dy]: direction){
                if (i+dx<grid.size() && j+dy<grid[0].size()&&i+dx>=0&&j+dy>=0){
                    //cout<<"push: "<<max(dist,grid[i+dx][j+dy])<<endl;
                    q.push({max(dist,grid[i+dx][j+dy]), i+dx, j+dy});
                }
            }

        }
    }
};
