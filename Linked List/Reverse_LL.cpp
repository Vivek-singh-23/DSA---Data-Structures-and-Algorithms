#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

class Solution {
  public:
    // Function to reverse a linked list.
    struct Node* reverseList(struct Node* head) {
        
        if(head == NULL || head->next == NULL){
            return head;
        }
        
        Node*prev = NULL;
        Node*curr = head;
        Node*forward = NULL;
        
        while(curr != NULL){
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        
        
        return prev;
    }
};

int main(){

}