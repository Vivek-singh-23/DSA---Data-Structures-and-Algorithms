#include<bits/stdc++.h>
using namespace std;


struct Node {
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

class Solution{
    public:
    
    int getMiddle(Node *head)
    {   
        
        if(head == NULL){
            return 0;
        }
        
        if(head->next == NULL ){
            return head->data;
        }
        
        
        Node*fast = head;
        Node*slow = head;
        
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        
        return slow->data;
    }
};
