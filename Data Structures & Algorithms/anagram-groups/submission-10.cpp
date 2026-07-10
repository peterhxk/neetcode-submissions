class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> m;
        for (string str: strs){
            vector<int> a(26);
            for (char c : str){
                a[c-'a']++;
                //cout << c-'a' << endl;
            }
            string b;
            for (int i=0; i< a.size();i++){
                b += to_string(a[i]);
                b += '|';
            }
            //cout << b << endl;
            m[b].push_back(str);
        }
        vector<vector<string>> ret;
        for (auto&[k, v]: m){
            ret.push_back(v);
        }
        return ret;
    }
};
