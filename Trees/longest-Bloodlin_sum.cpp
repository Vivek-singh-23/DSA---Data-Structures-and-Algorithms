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

void solve(node*root,int len,int sum,int &maxLen,int &maxSum){
    if(root == NULL){
        return;
    }

    if(root->left == NULL && root->right == NULL){
        sum = sum + root->data;
        if(len > maxLen){
                maxLen = len;
                maxSum = sum;
            }
            else if(len == maxLen){ // Corrected comparison
                maxSum = max(sum,maxSum);
            }
            
        return;
    }

    sum = sum + root->data;
    solve(root->left,len + 1,sum,maxLen,maxSum);
    solve(root->right,len + 1,sum,maxLen,maxSum);
}

int sumOfLongRootToLeafPath(node *root){
    if(root == NULL){
        return 0;
    }

    int len = 0;
    int maxLen = 0;

    int sum = 0;
    int maxSum = 0;

    solve(root,len,sum,maxLen,maxSum);

    return maxSum;
}


// Alternate solution


// class Solution {
// public:
//     void solve(Node* root, pair<vector<int>, int>& mp, vector<int>& path) {
//         if (root == NULL) {
//             return;
//         }
//          path.push_back(root->data);
//         if (root->left == NULL && root->right == NULL) {
//             if (mp.first.size() < path.size()) {
//                 mp.first = path;
//                 mp.second = path.size();
//             }
//             else if (mp.first.size() == path.size()) {
//                 if (sumOfVector(path) > sumOfVector(mp.first)) {
//                     mp.first = path;
//                     mp.second = path.size();
//                 }
//             }
//         }

       
//         solve(root->left, mp, path);
//         solve(root->right, mp, path);

//         path.pop_back();
//     }

//     int sumOfVector(const vector<int>& vec) {
//         int sum = 0;
//         for (int i = 0; i < vec.size(); i++) {
//             sum += vec[i];
//         }
//         return sum;
//     }

//     int sumOfLongRootToLeafPath(Node* root) {
//         if (root == NULL) {
//             return 0; // or any meaningful value indicating the absence of a path
//         }
//         vector<int> path;
//         pair<vector<int>, int> mp;
//         solve(root, mp, path);
//         int sum = 0;
//         for (int i = 0; i < mp.first.size(); i++) {
//             sum += mp.first[i];
//         }
//         return sum;
//     }
// };