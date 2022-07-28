#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

int calculateHeight(struct Node *root)
{

    if (root == NULL)
    {
        return 0;
    }

    int lHeight = calculateHeight(root->left);
    int rHeight = calculateHeight(root->right);

    return max(lHeight , rHeight)+1;
}

/*
     7
    /  \
    4    6
   / \  / \
   1  2 3  9

*/

bool checkBalanceBinaryTree(struct Node *root){

    if(root==NULL){
        return true;
    }

    int lHeight = calculateHeight(root->left);
    int rHeight = calculateHeight(root->right);
    
    if(checkBalanceBinaryTree(root->left)==false){
        return false;
    }

    if(checkBalanceBinaryTree(root->right)==false){
        return false;
    }

    if(abs(lHeight - rHeight)<=1){
        return true;
    }
    else{
        return false;
    }

}

int main(){

    struct Node *root = new Node(7);
    root->left = new Node(4);
   // root->right = new Node(6);

    root->left->left = new Node(1);
    root->left->left->left = new Node(1);
   // root->left->right = new Node(2);

    // root->right->left = new Node(3);
    // root->right->right = new Node(9);

  // root->right->right->right = new Node(10);
  

   if(checkBalanceBinaryTree(root)){
       cout<<"Binary tree is balanced"<<endl;
   }
   else{
        cout<<"Binary tree is not balanced"<<endl;
   }

   
    return 0;
}