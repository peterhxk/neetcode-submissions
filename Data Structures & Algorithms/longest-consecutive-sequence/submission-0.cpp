class Node{
public:
    Node* parent;
    int rank;
    int count;
    Node(){
        count = 1;
        rank = 0;
        parent = this;
    }
};
class Solution {
public:
    Node* find(Node* p1){
        Node* cur = p1;
        while (cur != cur->parent){
            cur->parent = cur->parent->parent;
            cur = cur->parent;
        }
        return cur;
    }
    void uni(Node* n1, Node* n2){
        Node* p1 = find(n1);
        Node* p2 = find(n2);
        if (p1 == p2){
            return;
        }
        else if (p1->rank < p2->rank){
            p1->parent = p2;
            p2->count += p1->count;
        }
        else if(p2->rank < p1->rank){
            p2->parent = p1;
            p1->count += p2->count;
        }
        else{
            p1->parent = p2;
            p2->rank++;
            p2->count += p1->count;
        }
    }
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, Node*> m;
        for (int i = 0; i< nums.size(); i++){
            int num = nums[i];
            if (m.count(num)){
                continue;
            }
            m[num] = new Node();
            
            if (m.count(num+1)){
                //cout << "uni: "<<num <<" "<<num+1<<endl;
                uni(m[num], m[num+1]);
                Node* test = find(m[num+1]);
                //cout<< "count" << test->count <<endl;
            }
            if (m.count(num-1)){
                //cout << "uni: "<<num <<" "<<num-1<<endl;

                uni(m[num],m[num-1]);
                Node* test = find(m[num-1]);
                //cout<< "count" << test->count <<endl;
            }
        }
        int ret = 0;
        for (auto [_, node]: m){
            ret = max(ret, node->count);
        }
        return ret;
    }
};
