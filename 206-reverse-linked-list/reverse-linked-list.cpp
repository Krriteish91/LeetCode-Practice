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
    ListNode* solve(ListNode* node, ListNode* prev){
        ListNode* next_node = node->next;
        node->next = prev;
        if(next_node == NULL) return node;

        return solve(next_node,node);
    }
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next == NULL) return head;
        return solve(head,NULL);
    }
};