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


node*buildTree(node*root){
    cout<<"Enter the data"<<endl;
    int data;
    cin>>data;

    if(data == -1){
        return NULL;
    }

    root = new node(data);

    cout<<"Entere the data for left of "<<data<<endl;
    root->left = buildTree(root->left);

    cout<<"Entere the data for right of "<<data<<endl;
    root->right = buildTree(root->right);


    return root;
}


node*lca(node*root,int n1, int n2){
    if(root == NULL){
        return NULL;
    }

    if(root->data == n1 || root->data == n2){
        return root;
    }


    node*leftAns = lca(root->left,n1,n2);
    node*rightAns = lca(root->right,n1,n2);

    if(leftAns != NULL && rightAns != NULL){
        return root;
    } 
    else if(leftAns == NULL && rightAns != NULL){
        return rightAns;
    }
    else if(leftAns != NULL && rightAns == NULL){
        return leftAns;
    }else{
        return NULL;
    }

}


// Alternative code


// class Solution
//{    public:
    //Function to return the lowest common ancestor in a Binary Tree.
//     Node* lca(Node* root ,int n1 ,int n2 )
//     {
//        if(root == NULL ){
//            return NULL;
//        }
       
//        if(root->data == n1 || root->data == n2){
//            return root;
//        }
       
//        Node* leftAns = lca(root->left, n1, n2);
//        Node* rightAns = lca(root->right, n1, n2);
       
//        if(rightAns != NULL && leftAns != NULL){
//            return root;
//        }
//        else if(leftAns != NULL && rightAns == NULL){
//            return leftAns;
//        }
//        else if(leftAns == NULL && rightAns != NULL){
//            return rightAns;
//        }else{
//            return NULL;
//        }
//     }
// };