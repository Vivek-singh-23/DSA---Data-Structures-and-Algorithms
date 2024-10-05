#include<bits/stdc++.h>
using namespace std;

struct Node{
    public:
        int data;
        Node*next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }    
};

bool floyd(Node*head){
    if(head == NULL){
        return false;
    }

    Node* fast = head;
    Node* slow = head;

    while(slow != NULL && fast != NULL){
        fast = fast->next;
        if(fast->next != NULL){
            fast = fast->next;
        } 

        slow = slow->next;

        if(fast == slow){
            return true;
        }
    }

    return false;
}


int main(){

}