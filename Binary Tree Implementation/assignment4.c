#include<stdio.h>
#include<stdlib.h>

#include "assignment4.h"

//performes inorder traversal and stores median value
int inOrderTraversal(BTnode_t* root, int median_index, int* i, int* median_value);

//function that calculates the size of a binary tree
int get_size(BTnode_t* root);

float eval_arithmetic_expression(BTnode_t* root) {

	//exit program if root is NULL
	if(root == NULL)
	{
		printf("ERROR: invalid binary tree\n");
		exit(-1);
	}

	//return root value if the node is a leaf
	if(root->left == NULL && root->right == NULL)
		return root->value;

	//use switch statments to perform arithmetic for each case
	switch(root->value)
	{

		case PLUS:
		return eval_arithmetic_expression(root->left) + eval_arithmetic_expression(root->right);

		case MINUS:
		return eval_arithmetic_expression(root->left) - eval_arithmetic_expression(root->right);

		case MULT:
		return eval_arithmetic_expression(root->left) * eval_arithmetic_expression(root->right);

		case DIV:
		return eval_arithmetic_expression(root->left) / eval_arithmetic_expression(root->right);

	}

	return -1;

}

int get_max(BST_t* tree) {

	int max = tree->root->value; //set temp max as root value
	BTnode_t* current = tree->root; //store the current root pointer


	//while right child exists, set max to right child value
	while(tree->root->right)
	{
		tree->root = tree->root->right;
		max = tree->root->value;
	}

	tree->root = current;//reset original root

	return max;
}


int get_median(BST_t* tree) {

	//get size of tree
	int n = get_size(tree->root);

	//calculate median index
	int median_index = n/2;


	int i =0; // used as counter of index
	int median_value = 0;//initialze median value to 0

	median_value = inOrderTraversal(tree->root, median_index, &i, &median_value);

	return median_value;
}


int get_size(BTnode_t* root)
{
	if(root == NULL)
		return 0;
	else
		return get_size(root->left) + get_size(root->right) + 1;
}


int inOrderTraversal(BTnode_t* root, int median_index, int* i, int* median_value)
{
	if(root == NULL)
	{
		//do nothing
	}
	else
	{
		//recursivley iterate through left subtree
		inOrderTraversal(root->left, median_index, i, median_value);

		//if the index is equal to median index, store the root value in median index
		if(*i == median_index)
			*median_value = root->value;
		*i = *i +1; 
		
		//recursivley iterate through left subtree
		inOrderTraversal(root->right, median_index, i, median_value);
	}

	return *median_value;

}
