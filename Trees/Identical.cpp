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

node* buildTree(node*root){
    cout<<"enter data for root node"<<endl;
    int data;
    cin>>data;

    root = new node(data);

    if(data == -1){
        return NULL;
    }

    cout<<"enter data for left of "<<data<<endl;
    root->left = buildTree(root->left);

    cout<<"enter data for right of "<<data<<endl;
    root->right = buildTree(root->right);

    return root;
}

bool identical(node*root1, node*root2){
    if(root1 == NULL && root2 == NULL){
        return true;
    }

    if(root1 == NULL && root2 != NULL){
        return false;
    }

    if(root1 != NULL && root2 == NULL){
        return false;
    }

    bool left = identical(root1->left, root2->left);
    bool right = identical(root1->right, root2->right);

    bool curr = (root1->data == root2->data);

    if(left && right && curr){
        return true;
    }else{
        return false;
    }

}
int main(){
    
    node*root1 = NULL;
    root1 = buildTree(root1);

    node*root2 = NULL;
    root2 = buildTree(root2);

    cout<<identical(root1,root2);
}

// 1 3 7 -1 -1  11 -1 -1 5 17 -1 -1 -1