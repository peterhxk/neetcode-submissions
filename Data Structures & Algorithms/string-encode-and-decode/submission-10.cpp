class Solution {
public:

    string encode(vector<string>& strs) {
        string ret;
        for (string str: strs){
            int size = str.size();
            ret += to_string(size);
            ret += "#";
            ret += str;
        }
        cout << ret << endl;
        return ret;
    }

    vector<string> decode(string s) {
        vector<string> ret;
        string size;
        int i = 0;
        while (i < s.size()){
            cout << "before" << i << endl;
            char c = s[i];
            cout << c << endl;
            if (c == '#'){
                int len = stoi(size);
                string str = s.substr(i+1, len);
                i += len;
                ret.push_back(str);
                size = "";
            }else{
                size += c;
            }
            i++;

        }
        return ret;
    }
};
