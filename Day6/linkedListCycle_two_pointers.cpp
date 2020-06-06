/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL) return false;  //if head is null, there will never be a loop
        
        ListNode *sp = head;        //slow pointer: moves one step at a time
        ListNode *fp = head->next;  //fast pointer: moves two steps at a time
        
        while(fp != NULL && fp->next != NULL){  //check if fast pointer reaches the end of the
                                                // linked list.
            
            if(fp == sp)        //if slow pointer is equal to fast pointer, that is, they are 
                return true;    // on the same node, we got our loop.
            
            fp = fp->next->next; //Fast pointer moves 2 steps ahead
            sp = sp->next;       //Slow pointer moves 1 step ahead
        }
        
                        //If end of linked list is reached, there is no loop, and we
        return false;   // return false.
    }
};