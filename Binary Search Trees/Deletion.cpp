#include<iostream>
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

node* Insert(node* &root, int d){
    if(root == NULL){
        root = new node(d);
        return root;
    }

    if(root->data < d){
        root->right = Insert(root->right, d);
    }

    if(root->data > d){
        root->left = Insert(root->left, d);
    }

    return root;
}


node* minVal(node*root){
    node*temp = root;
    while(temp->left != NULL){
        temp = temp -> left;
    }

    return temp;
}

node*deleteFromBST(node*root,int val){
    if(root == NULL){
        return NULL;
    }

    if(root->data == val){
        // node to be deleted has 0 child
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        // node to be deleted has 1 child

        if(root->left != NULL && root->right == NULL){
            node*temp = root->left;
            delete root;
            return temp;
        }


        if(root->left == NULL && root->right != NULL){
            node*temp = root->right;
            delete root;
            return temp;
        }

        // node to be deleted has 1 child
        if(root->left != NULL && root->right != NULL){
            int mini = minVal(root->right)->data;
            root->data = mini;
            root->right = deleteFromBST(root->right, mini);
            return root;
        }
    }
}

void takeInput(node*& root){
    int data;
    cin>>data;

    while(data != -1){
        root = Insert(root, data);
        cin>>data;
    }
}

int main(){

}
