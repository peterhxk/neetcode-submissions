class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<pair<int,int>> dirs = {{1,0},{0,1}};
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> q;
        vector<vector<int>> visited(grid.size(),vector<int>(grid[0].size(),false));
        q.push({grid[0][0],0,0});
        while(!q.empty()){
            auto cur = q.top();
            q.pop();

            int cur_d = get<0>(cur);
            int cur_x = get<1>(cur);
            int cur_y = get<2>(cur);
            //cout<<"x: "<<cur_x<<" y: "<<cur_y<<" d: "<<cur_d<<endl;
            if (cur_x == grid.size()-1 && cur_y ==grid[0].size()-1){
                return cur_d;
            }
            visited[cur_x][cur_y] = true;

            for (auto dir : dirs){
                int dx = get<0>(dir); int dy = get<1>(dir);
                int new_x = cur_x+dx; int new_y = cur_y+dy;
                if (new_x<grid.size()&&new_y<grid[0].size()&&!visited[new_x][new_y]){
                    q.push({cur_d+grid[new_x][new_y],new_x,new_y});
                }
            }

        }
        return -1;
    }
};