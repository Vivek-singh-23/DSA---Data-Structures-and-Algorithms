#include<bits/stdc++.h>
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

node*minVal(node*root){
    node*temp = root;
    while(temp->left != NULL){
        temp = temp->left;
    }

    return temp;
}


node*maxVal(node*root){
    node*temp = root;
    while(temp->left != NULL){
        temp = temp->right;
    }

    return temp;
}


bool search(node*root, int d){
    if(root == NULL){
        return false;
    }

    if(root->data == d){
        return true;
    }

    if(d > root->data){
        return search(root->right, d);
    }

    if(d < root->data){
        return search(root->left, d);
    }
}


node* Insert(node* &root, int data){
    if(root == NULL){
        root = new node(data);
        return root;
    }

    if(data > root->data){
        root->right = Insert(root->right, data);
    }

    if(data < root->data){
        root->left = Insert(root->left, data);
    }

    return root;
}

void takeInput(node* root){
    int data;
    cin>>data;

    if(data != -1){
        root = Insert(root, data);
        cin>>data;
    }
}

int main(){

}