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
// 顺序遍历
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL){
            return head;
        }
        ListNode re(0,head);
        ListNode* p;
        p = &re;
        ListNode* q = p->next;
        ListNode* r = head->next;
        while(q!=NULL && r!=NULL){
            q->next = r->next;
            r->next = p->next;
            p->next = r;

            p = q;
            q = p->next;
            if(q==NULL || q->next==NULL)
                break;
            r = q->next;
        }
        return re.next;
    }
};

// 递归
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* next = head->next;
        head->next = next->next;
        next->next = head;

        head->next = swapPairs(head->next);
        return next;
    }
};