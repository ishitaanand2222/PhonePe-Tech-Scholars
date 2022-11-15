#include "../crio/cpp/ds/ListNode/ListNode.hpp"
/*
Definition for ListNode
class ListNode {
public:
    int val;
    ListNode* next;
    ListNode() {}
    ListNode(int x) {
        val = x;
        next = NULL;
    }
};
*/

//O(2n) : A less optimized approach can be to first find len and then calculate len-k+1 node and delete
//Another O(2n) approach can be to reverse the list and delete the kth node


//Single pass solution O(n):
ListNode* deleteKthToLast(ListNode* head , int k) {
    ListNode* fast = head, *slow = head;
    for(int i=0;i<k;i++)
    {
        fast = fast->next;
    }
    if(!fast)
        return head->next;
    
    while(fast->next != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;
    
    return head;
}
