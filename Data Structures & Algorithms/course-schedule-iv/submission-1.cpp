class Solution {
public:

    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<bool>> m(numCourses, vector<bool>(numCourses, false));

        for (auto prereq: prerequisites){
            int child = prereq[0]; int parent = prereq[1];
            m[parent][child] = true;
        }

        for (int i =0; i<numCourses; i++){
            for (int j=0; j<numCourses; j++){
                for (int k=0; k<numCourses; k++){
                    if (m[i][k]&&m[k][j]){
                        m[i][j] = true;
                    }
                }
            }
        }
        vector<bool> ret;
        for (auto query:queries){
            ret.push_back(m[query[1]][query[0]]);
        }
        return ret;


    }
};