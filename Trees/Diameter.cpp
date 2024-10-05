#include<iostream>
#include<algorithm>
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

node* buildtree(node* root){
    cout << "Enter the data" << endl;
    int data;
    cin >> data;

    root = new node(data);
    if(data == -1){
        return NULL;
    }

    cout << "Enter data for left of " << data << endl;
    root->left = buildtree(root->left);

    cout << "Enter data for right of " << data << endl;
    root->right = buildtree(root->right);
    return root;
}

pair<int,int> diameter(node* root){
    if(root == NULL){
        pair<int,int> p = make_pair(0,0);
        return p;
    }

    pair<int,int> left = diameter(root->left); 
    pair<int,int> right = diameter(root->right);

    int op1 = left.first;
    int op2 = right.first;
    int op3 = right.second + left.second + 1;

    pair<int,int> ans;
    ans.first = max(op1, max(op2,op3));
    ans.second = max(left.second,right.second) + 1;

    return ans;
}

void print(pair<int,int> &ans){
    cout << ans.first << endl;
}

int main(){
    node* root = NULL;
    root = buildtree(root);

    pair<int,int> result = diameter(root);
    print(result);

    return 0;
}
