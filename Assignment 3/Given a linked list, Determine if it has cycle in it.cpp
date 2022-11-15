#include "../crio/cpp/ds/ListNode/ListNode.hpp"
/*
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

class LinkedListCycle {
public:
    string linkedListCycle(ListNode* head) {
        if(!head)
            return "false";
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast->next!= NULL and fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
            {
                return "true";
            }
        }
        return "false";
    }
};