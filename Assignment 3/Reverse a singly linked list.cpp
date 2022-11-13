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
ListNode* reverseLinkedList(ListNode *head) {
	ListNode* prev = NULL, *curr = head;
	while(curr != NULL)
	{
		ListNode* temp = curr->next;
		curr->next = prev;
		prev = curr;
		curr = temp;
	}
	return prev;
}