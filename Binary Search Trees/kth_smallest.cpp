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

class Solution {
  public:
    int solve(node* root, int K, int &i){
        if(root == NULL){
            return -1;
        }
        
        int left = solve(root->left, K, i);
        
        if(left != -1){
            return left;
        }
        
        i++;
        if(i == K){
            return root->data;
        }
        
        return solve(root->right, K, i);
    }
    int KthSmallestElement(node *root, int K) {
        int i = 0;
        int ans = solve(root, K, i);
        return ans;
    }
};