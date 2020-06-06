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
        
        ListNode *ptr = head;        //Pointer to move through Linked List
        
        unordered_set<ListNode*> set; //This is a set, implemented through hashing, similar
                                      // to HashSet in Java.
        
        while(ptr->next != NULL){   //Check if Linked List has an end.
            
            if(set.find(ptr) != set.end()) //Check if element(here, pointer) is present in
                return true;               // the set. If present, return true.
            
            set.insert(ptr);  //If not present, insert element in the set.
            
            ptr = ptr->next;  //Set pointer to next node.
        }
        
                        //If end of Linked List is present, while loop breaks, and we
        return false;   // return false.
    }
};