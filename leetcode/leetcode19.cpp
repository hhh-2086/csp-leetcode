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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode nullnode(0,head);//指向头部
        int location=0;
        ListNode* p = head;
        while(location!=n){
            p = p->next;
            location++;
        }
        if(p==NULL){
            return head->next;
        }
        ListNode* q = &nullnode;
        while(p!=NULL){
            p = p->next;
            q = q->next;
        }
        q->next = q->next->next;

        return head;
    }
};

// 递归可以得到更短时间
class Solution {
public:
    int cur=0;
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       if(!head) return NULL;
       head->next = removeNthFromEnd(head->next,n);
       cur++;
       if(n==cur) return head->next;
       return head;
    }
};