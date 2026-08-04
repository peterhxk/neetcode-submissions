class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        map<pair<int,int>, vector<tuple<int,int,int>>> m;

        for (int i = 0; i< points.size(); i++){
            for (int j = i+1; j<points.size(); j++){
                auto point1 = points[i];
                int x1 = point1[0]; int y1 = point1[1];
                auto point2 = points[j];
                int x2 = point2[0]; int y2 = point2[1];
                m[{x1,y1}].push_back({x2,y2,abs(x2-x1)+abs(y2-y1)});
                m[{x2,y2}].push_back({x1,y1,abs(x2-x1)+abs(y2-y1)});
            }
        }
        set<vector<int>> visited;
        priority_queue<tuple<int, int, int>, vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> q;
        int total = 0;
        q.push({0, points[0][0], points[0][1]});
        while (!q.empty()){
            auto cur = q.top();
            q.pop();
            int dist = get<0>(cur); int i = get<1>(cur); int j = get<2>(cur);
            
            if (visited.count({i,j})){
                continue;
            }
            //cout << "i: "<<i<<" j: "<<j<<endl;
            visited.insert({i,j});
            //cout<< dist << endl;
            total += dist;
            for (auto [i2, j2, dist]: m[{i,j}]){
                q.push({dist, i2, j2});
            }
        }    
        return total;    
    }
};
