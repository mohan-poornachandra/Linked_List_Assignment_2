#include<iostream> 
using namespace std;


    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* t1 = head;
        ListNode* t2 =head;
        ListNode* temp = head;
        int idx=1;
        while(temp){
            if(idx==k) t1 = temp;
            if(idx>k) t2 = t2->next;
            temp = temp->next;
            idx++;
        }
        int a= t1->val;
        t1->val = t2->val;
        t2->val = a;
        return head;
    }