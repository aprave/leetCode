/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// 2nd from behind is the 3rd from the head -- two pass implementation should be trivial

// Assume there are N nodes in the list.
// Say you have 2 pointers, one pointer is already at the nth position, then you run your slow pointer from the head
// slow pointer has to traverse N nodes whereas the fast pointer has to traverse N-n nodes, once your slow pointe reaches the nth node, fast should be at the last node as long as there are no cycles in your linked list.

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode *slow, *fast;
    struct ListNode *dummy = (struct ListNode *) malloc(sizeof(struct ListNode));
    int i = 0;
    dummy->next = head;
    slow = dummy, fast = dummy; 
    while(i<n){ 
        fast = fast->next;
        i++;
    }
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next;
    }
    if(slow && slow->next)
        slow->next = slow->next->next;
    else
        slow = slow->next;
    
    return dummy->next;
}