class ZigzagIterator {
public:
    int i; 
    vector<int> v;
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        i = 0; int i1 = 0; int i2 =0;
        while (i<v1.size()+v2.size()){
            if (i%2==0){
                if (i1>=v1.size()){
                    v.push_back(v2[i2]);
                    i2++;
                }
                else {
                    v.push_back(v1[i1]);
                    i1++;
                }
            } else{
                if (i2>=v2.size()){
                    v.push_back(v1[i1]);
                    i1++;
                } else {
                    v.push_back(v2[i2]);
                    i2++;
                }
            }
            i++;
        }
        i = 0;
    }

    int next() {
        return v[i++];
    }

    bool hasNext() {
        return i<v.size();
        
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
