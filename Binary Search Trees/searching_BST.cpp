#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node*left;
        node*right;

    node(int d) {   
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

    if(d > root->data){
       root->right =  Insert(root->right, d);
    }

    if(d < root->data){
       root->left =  Insert(root->left, d);
    }

    return root;
}

// bool search(node*root, int d){
//     if(root == NULL){
//         return false;
//     }

//     if(root->data == d){
//         return true;
//     }

//     if(d > root->data){
//         search(root->right, d);
//     }

//     if(d < root->data){
//         search(root->left, d);
//     }
// }


// iterative way is more efficient
bool search(node*root, int d){
    node*temp = root;

    while(temp != NULL){
        if(temp->data == d){
            return true;
        }

        if(temp->data > d){
            temp = temp->left;
        }

        if(temp->data < d){
            temp = temp->right;
        }
    }
    return false;
}

void TakeInput(node* &root){
    int data;
    cin>>data;

    while(data != -1){
        root = Insert(root, data);
        cin>>data;
    }
}

int main(){
    node*root = NULL;
}