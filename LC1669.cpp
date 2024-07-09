#include<iostream>
using namespace std;

    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* temp = list1;
        ListNode* t = new ListNode;
        int idx=0;
        while(temp){
            if(idx==a-1){
                t = temp->next;
                idx++;
                while(idx<=b){
                    idx++;
                    t = t->next;
                }
                temp->next = list2;
                while(temp&&temp->next){
                    temp = temp->next;
                }
                temp->next = t;
            }
            temp = temp->next;
            idx++;
        }
        return list1;
    }