/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        stack<int> s;
        ListNode* slow = head;
        ListNode* fast = head->next;
        int ret=0;
        while (fast != nullptr && fast->next != nullptr){

            s.push(slow->val);
            fast = fast->next->next;
            slow = slow->next;
        }
        s.push(slow->val);
        slow = slow->next;
        while (slow != nullptr){
            ret = max(ret, s.top()+slow->val);
            slow = slow->next;
            s.pop();
        }
        return ret;
        
    }
};