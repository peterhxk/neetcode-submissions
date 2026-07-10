class Solution {
public:
    int characterReplacement(string s, int k) {
        int i = 0; int j = 0;
        unordered_map<int, int> m;
        //multiset<int, greater<int>> q;
        int max_freq = 0;
        int max_len = 0;
        int cur_len = 0;
        while (j < s.size()){
            char cur = s[j];
            cur_len++;
            //cout<<m.count(cur-'a')<<endl;
            //if (m.count(cur-'a')){
                //cout<<"removing "<<m[cur-'a']<<endl;
                //q.erase(q.find(m[cur-'a']));
            //}
            m[cur-'a'] += 1;
            max_freq = max(max_freq, m[cur-'a']);
            //q.insert(m[cur-'a']);
            //cout<<"cur_char: "<< cur << endl;
            //cout<<"top: " << *q.begin()<<endl;
            //cout<<"cur_len: "<< cur_len<< endl;
            //while (*q.begin()+k < cur_len){
            while (max_freq+k < cur_len){
                //int prev_freq = m[s[i]-'a'];
                //q.erase(q.find(prev_freq));
                //q.insert(prev_freq-1);
                m[s[i]-'a']--;
                i++;
                cur_len--;
            }
            max_len = max(max_len, cur_len);
            j++;
            //cout<<"top2: " << *q.begin()<<endl;

        }
        int ret = min((int)s.size(), max_len);
        return ret;
    }
};
