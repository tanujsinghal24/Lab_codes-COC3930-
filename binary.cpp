#include<iostream>
using namespace std;
struct node{
	int data;
	node* left;
	node* right;
};
class bst{
public:
	node* root;
	bst(){
		root=NULL;
	}
	void create_bst(){
		int temp,n;
		cout<<"Enter number of values:";
		cin>>n;
		cout<<"Enter values:";
		for(int i=0;i<n;i++){
			cin>>temp;
			root=insert_in_bst(root,temp);
			// print_tree(root);
			cout<<endl;
			// print_in_tree(root);
			// cout<<endl;

			
			// cout<<root->left->data<<"  ";
			// root=root>left;
			// cout<<root->left->data<<"  ";
			// root=root>left;

		}
		// cout<<root->left->data<<"  ";
		// 	root=root->left;
		// 	cout<<root->left->data<<"  ";
		// 	root=root->left;
	}
	node* insert_in_bst(node* curr_root,int t){
		if(curr_root==NULL){
			cout<<"Inserting data\n";
			curr_root=new node;
			curr_root->data=t;
			curr_root->left=NULL;
			curr_root->right=NULL;
			// cout<<"done";
			return curr_root;
		}
		else{
			if(curr_root->data > t){
				cout<<"going left of curr_root:"<<curr_root->data<<" \n";
				curr_root->left=insert_in_bst(curr_root->left,t);
			}
			else if(curr_root->data < t){
				cout<<"going right of curr_root:"<<curr_root->data<<" \n";
				curr_root->right=insert_in_bst(curr_root->right,t);
			}
		}
		return curr_root;
	}
	void print_tree(node* curr_root){
		if(curr_root==NULL){
			// cout<<"here";
			return;
		}
		cout<<curr_root->data<<"  ";
		print_tree(curr_root->left);
		print_tree(curr_root->right);

	}
	void print_in_tree(node* curr_root){
		if(curr_root==NULL){
			return;
		}
		print_in_tree(curr_root->left);
		cout<<curr_root->data<<"  ";
		print_in_tree(curr_root->right);

	}
	void print_post_tree(node* curr_root){
		if(curr_root==NULL){
			return;
		}
		print_post_tree(curr_root->left);
		print_post_tree(curr_root->right);
		cout<<curr_root->data<<"  ";

	}
	int height(node* curr_root){
		if(curr_root==NULL){
			return 0;
		}
		int hl=height(curr_root->left);
		int hr=height(curr_root->right);
		return max(hl,hr)+1;
	}
};
int main(){
	bst tree;
	tree.create_bst();
	cout<<"tree height:"<<tree.height(tree.root)<<endl;
	cout<<"tree inorder:";tree.print_in_tree(tree.root);cout<<endl;
	cout<<"tree pre order:";tree.print_tree(tree.root);cout<<endl;
	cout<<"tree post order:";tree.print_post_tree(tree.root);cout<<endl;
}