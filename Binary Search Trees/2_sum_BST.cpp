#include<iostream>
#include<vector>
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


void inorder(node* root,vector<int>&path){
    if(root == NULL){
        return;
    }

    inorder(root->left, path);
    path.push_back(root->data);
    inorder(root->right, path);

}

bool sum(node*root, vector<int> path, int k){
    vector<int> path;
    inorder(root, path);

    int i=0;
    int j=path.size() - 1;

    int s = path[i] + path[j]; 
    while(i < j){
        if(s == k){
            return true;
        }else if(s > k){
            j--;
        }else{
            i++;
        }
    }
    return false;
}

int main(){
    node*root = NULL;
    cout<<"Enter the data"<<endl;
    Input(root);
    

}