#include<iostream>
using namespace std;


    ListNode* deleteMiddle(ListNode* head) {
        //This is the same question as LC876. 
        if(head->next == NULL) return NULL;
        ListNode* fast = head;
        ListNode* slow = head;
        //slow should be one node before the deleting node!
        //So, in case of even, we have to place slow at 1st middle.
        //We need so many coz, slow should be a node before middle and it takes these conditions in odd case
        while(fast&&fast->next->next&&fast->next->next&&fast->next->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = slow->next->next;
        return head;

    }