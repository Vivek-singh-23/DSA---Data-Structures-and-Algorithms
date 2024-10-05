#include<iostream>
#include<climits>
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

void takeInput(node*& root){
    int data;
    cin>>data;

    while(data != -1){
        root = Insert(root, data);
        cin>>data;
    }
}

node* LCA(node*root, node* n1, node* n2){
    if(root == NULL){
        return NULL;
    }

    if(root->data < n1->data  && root->data < n2->data ){
        return LCA(root->right, n1, n2);
    }

    if(root->data > n1->data  && root->data > n2->data ){
        return LCA(root->left, n1, n2);
    }

    return root;
}

// iterative approach
// node* LCA(node*root, node* n1, node* n2){
//     while(root != NULL){
//         if(root->data < n1->data  && root->data < n2->data ){
//             root = root->left;
//         }

//         else if(root->data > n1->data  && root->data > n2->data ){
//             root = root->right;
//         }
//         else{
//             return root;
//         }
    
//     }
// }

int main(){

}