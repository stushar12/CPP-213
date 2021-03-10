#include<bits/stdc++.h>
using namespace std;


struct Node 
{
	int data; 
	Node* left;
	Node* right;
};

Node* GetNewNode(int data) 
{
	Node* newNode = new Node();
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

Node* Insert(Node* root,int data) 
{
	if(root == NULL)                                      // empty tree
    {                                           
		root = GetNewNode(data);
	}
	
	else if(data <= root->data)                         // if data to be inserted start lesser, insert inorder left subtree. 
    {
		root->left = Insert(root->left,data);
	}
	
	else                                                // else, insert inorder right subtree. 
    {
		root->right = Insert(root->right,data);
	}
	return root;
}


int transform_sum_tree(Node* root)
{
    if(root==NULL)
    return 0;
    
    int a=transform_sum_tree(root->left);
    int b=transform_sum_tree(root->right);
    
    int x=root->data;
    root->data=a+b;
    
    return a+b+x;
}

void inorder(Node *root)
{
    if(root==NULL)
        return;
        else
        {
            inorder(root->left);
            cout<<root->data<<" ";
            inorder(root->right);
        }
}

int main() 
{
	Node* root = NULL;  			// Creating an empty tree
	root = Insert(root,15);	
	root = Insert(root,10);	
	root = Insert(root,20);
	root = Insert(root,8);
	root = Insert(root,12);
	root = Insert(root,17);
	root = Insert(root,25);

    cout<<"Before transformation "<<endl;
    inorder(root);
    cout<<endl;
    transform_sum_tree(root);
    cout<<"After transformation "<<endl;
    inorder(root);

}