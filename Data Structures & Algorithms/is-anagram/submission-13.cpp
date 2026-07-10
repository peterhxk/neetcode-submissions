class Solution {
public:
    void load(string str, unordered_map<char, int>& m){
            for (char c : str){
                m[c]+=1;
            }
        }
    bool isAnagram(string s, string t) {
        unordered_map<char, int> m1;
        unordered_map<char, int> m2;
        
        load(s, m1);
        load(t, m2);
        if (m1.size() != m2.size()){
            return false;
        }
        for (auto[k,v] : m1){
            std::cout << k << v << '\n';
            if (m1[k] != m2[k]){
                return false;
            }
        }
        return true;
    }
};
