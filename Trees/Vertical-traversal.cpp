#include<queue>
#include<vector>
#include<iostream>
#include<unordered_map>
#include<map>
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

    
    cout<<"Enter the data for left of"<<data<<endl;
    root->left = buildTree(root->left);

    cout<<"Enter the data for right of"<<data<<endl;
    root->right = buildTree(root->right);

    return root;

}
vector<int> vertical(node*root){
    vector<int> ans;
    if(root == NULL ){
        return ans;
    }
    map<int,map<int,vector<int>>> nodes;
    queue<pair<node*,pair<int,int>>> q;

    q.push(make_pair(root,make_pair(0,0)));
    while(!q.empty()){
        pair<node*,pair<int,int>> temp = q.front();
        q.pop();

        node* front = temp.first;
        int hd = temp.second.first;
        int lvl = temp.second.second;

        nodes[hd][lvl].push_back(front->data);

        if(front->left){
            q.push(make_pair(front->left, make_pair(hd-1,lvl+1)));
        }

        if(front->right){
            q.push(make_pair(front->right, make_pair(hd+1,lvl+1)));
        }
    }

    for(auto i: nodes){
        for(auto j:i.second){
            for(auto k:j.second){
                ans.push_back(k);
            }
        }
    }

    return ans;
}


// code works without lvl variable


// vector<int> verticalOrder(Node *root)
//     {
//         vector<int> ans;
//         if(root == NULL){
//             return ans;
//         }
    
//         map<int, vector<int>> mp;
//         queue<pair<Node*, int>> q;
    
//         q.push(make_pair(root, 0));
    
//         while(!q.empty()){
//             pair<Node*,int> temp = q.front();
//             q.pop();
    
    
//             Node* front = temp.first;
//             int hd = temp.second;
//             // int lvl = temp.second.second;
    
//             mp[hd].push_back(front->data);
    
//             if(front->left){
//                 q.push(make_pair(front->left,hd - 1));
//             }
    
//             if(front->right){
//                 q.push(make_pair(front->right, hd + 1));
//             }   
//         }
    
//         for(auto i:mp){
//             for(auto j:i.second){
//                 ans.push_back(j);
//             }
//         }
//         return ans;
//     }