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

bool solve(node*root, int mini, int maxi){
    if(root == NULL){
        return true;
    }

    if(root->data >= mini && root->data <= maxi){
        bool left = solve(root->left, mini, root->data);
        bool right = solve(root->left, root->data, maxi);
        return left && right;
    }else{
        return false;
    }
    
}


//{ Driver Code Starts


// Tree Node


// alternate sol

// } Driver Code Ends
// class Solution
// {
//     public:
//     void inorder(Node*root, vector<int> &path){
//         if(root == NULL){
//             return;
//         }
        
//         inorder(root->left, path);
//         path.push_back(root->data);
//         inorder(root->right, path);
//     }
//     bool isBST(Node* root) 
//     {
//         vector<int> path;
//         inorder(root, path);
        
//         // bool flag = true;
//         for(int i=0; i<path.size() - 1; i++){
//             if(path[i] >= path[i + 1]){
//                 return false;
//             }
//         }
        
//         return true;
//     }
// };





// void inorder(node *root, vector<int> &v)
// {
//     if(root==NULL)
//         return;

//     inorder(root->left, v);
//     v.push_back(root->data);
//     inorder(root->right, v);
// }


int main(){

}