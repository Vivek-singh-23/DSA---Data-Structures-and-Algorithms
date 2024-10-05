#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class node{
    public:
        int data;
        node*left;
        node*right;

    node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }    
};


node* InsertIntoBST(node* &root, int d){
    if(root == NULL){
        root = new node(d);
        return root;
    }

    if(d > root->data){
        root->right = InsertIntoBST(root->right, d);
    }else   {
        root->left = InsertIntoBST(root->left, d);
    }

    return root;
}

void takeInput(node* &root){
    int data;
    cin>>data;

    while(data != -1){
        root = InsertIntoBST(root, data);
        cin>>data;
    }
}

node* minValue(node*root){
    node*temp = root;
    while(temp->left != NULL){
        temp = temp -> left;
    }

    return temp;
}

node* maxValue(node*root){
    node*temp = root;
    while(temp->right != NULL){
        temp = temp->right;
    }

    return temp;
}


int main(){
    node*root = NULL;

    takeInput(root);
    
}