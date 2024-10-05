#include<iostream>
#include<vector>
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

node* Insert(node*&root, int d){
    
    if(root == NULL){
        root = new node(d);
        return root;
    }

    if(root->data > d){
        root->left = Insert(root->left, d);
    }

    
    if(root->data < d){
        root->right = Insert(root->right, d);
    }

    return root;


}

void Input(node*&root){
    
    int data;
    cin>>data;

    while(data != -1){
        root = Insert(root, data);
        cin>>data;
    }
}

node*solve(vector<int> pre, int mini, int maxi, int &i){
    if(i >= pre.size()){
        return NULL;
    }

    if(pre[i] < mini || pre[i] > maxi){
        return NULL;
    }
    
    node*root = new node(pre[i]);
    i++;

    root->left = solve(pre,mini, root->data, i);
    root->right = solve(pre, root->data, maxi, i);
    
    return root;

}

node*preOrder(vector<int>pre ){
    int mini = INT_MIN;
    int maxi = INT_MAX;
    int i = 0;

    solve(pre, mini, maxi, i);
}