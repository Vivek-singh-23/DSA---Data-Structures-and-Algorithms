#include<iostream>
#include<queue>
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


node* InsertIntoBST(node* &root, int d){
    if(root == NULL){
        root = new node(d);
        return root;
    }

    if(d > root->data){
        root->right = InsertIntoBST(root->right, d);
    }else   {
        root->left = InsertIntoBST(root->left, d);
    }

    return root;
}

void takeInput(node* &root){
    int data;
    cin>>data;

    while(data != -1){
        root = InsertIntoBST(root, data);
        cin>>data;
    }
}


void levelOrder(node* root){
    queue<node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node*temp = q.front();
        q.pop();

        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }

            if(temp-> right){
                q.push(temp->right);
            }
        }
    }
}

// alternate LOT

// void level(node*root){
//     vector<vector<int>> output;
//     queue<node*>q;
//     q.push(root);

//     while(!q.empty()){
//         int size = q.size();
//         vector<int> inner;
//         for(int i=0 ; i<size ; i++){
//             node*temp = q.front();
//             q.pop();

//          
//             inner[i] = root->data;
//             if(root->left){
//                 level(root->left);
//             }

//             if(root->right){
//                 level(root->right);
//             }
//         }
//         output.push_back(inner);
//     }

// }

int main(){

    node*root = NULL;
    cout<<"enter the data"<<endl;
    takeInput(root);        

    levelOrder(root);
    return 0;
}