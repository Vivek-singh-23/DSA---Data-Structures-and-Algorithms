#include<bits/stdc++.h>
using namespace std;
struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    };

class Solution
{
    public:
    struct node *reverseIt (struct node *head, int k)
    { 
        if(head == NULL){
            return head;
        }
        
        // step1 reverse first k nodes
        node* prev = NULL;
        node* curr = head;
        node* forward = NULL;
        int cnt = 0;
        
        while(curr != NULL && cnt<k){
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
            cnt++;
        }
        
        // step 2 Add solution of recursion at head
        if(forward != NULL){
            head->next = reverseIt(forward, k);
        }
        
        return prev;
    }
};
