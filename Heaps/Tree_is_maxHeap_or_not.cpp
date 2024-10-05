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
int countnodes(node*root ){
    if(root == NULL){
        return 0;
    }

    int ans = 1 + countnodes(root->left) + countnodes(root->right);
    return ans;
}

bool CBT(node*root, int index, int cnt){
    if(root == NULL){
        return true;
    }

    if(index >= cnt){
        return false;
    }
    else{
        bool left = CBT(root->left, 2*index + 1, cnt);
        bool right = CBT(root->right, 2*index + 2, cnt);

        return(left && right);
    }
}

bool ismaxOrder(node*root){
    if(root->left == NULL && root->right == NULL){
        return true;
    }

    if(root->right == NULL){
        return (root->data > root->left->data);
    }
    else{
        bool left = ismaxOrder(root->left);
        bool right = ismaxOrder(root->right);

        return (left && right && (root->data > root->left->data && root->data > root->right->data));
    }

}

bool isHeap(node*root){
    int index = 0;
    int totalcount = countnodes(root);
    if(CBT(root, index, totalcount) && ismaxOrder(root)){
        return true;
    }else{
        return false;
    }
}