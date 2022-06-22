#include "header.h"

// Returns a new tree node 
struct TreeNode *newTreeNode(int freq, char item)
{
	struct TreeNode *node = (struct TreeNode *) malloc(sizeof(struct TreeNode));
	if (node == NULL)
	{
		printf("\n Memory overflow , When creating a new TreeNode");
	}
	else
	{
		node->item = item;
		node->freq = freq;
		node->left = NULL;
		node->right = NULL;
	}
	return node;
}

// Get a front element of queue
struct TreeNode *peek(struct PriorityQueue *q)
{
	if (isEmpty(q) == 1)
	{
		// When stack is empty
		return NULL;
	}
	else
	{
		return q->front->n;
	}
}

// Construct Huffman Code Tree
struct TreeNode *buildHuffmanCodes(char value[], int frequency[], int n)
{
	struct PriorityQueue *q = newPriorityQueue();
	struct TreeNode *root = NULL;
	struct TreeNode *n1 = NULL;
	struct TreeNode *n2 = NULL;
	// First add all elements into priority queue
	for (int i = 0; i < n; ++i)
	{
		root = newTreeNode(frequency[i], value[i]);
		enQueue(q, root);
	}
	printQdata(q);
	// Execute loop until the priority queue contains more than 1 node
	while (isSize(q) > 1)
	{
		// Get first smallest node  
		n1 = peek(q);
		//Remove a front element
		deQueue(q);
		// Get second smallest node
		n2 = peek(q);
		// Remove a front element
		deQueue(q);
		// Make new node using two smallest node
		root = newTreeNode(n1->freq + n2->freq, ' ');
		// Add new node into priority queue 
		enQueue(q, root);
		// Set left and right child
		root->left = n1;
		root->right = n2;
	}
	return root;
}

//void PrintTree(struct TreeNode* root, char tab[]){
//	char temp[10];
//	strcpy(temp,tab);
//	strcat(temp,"-");
//	if(root == NULL) return;
//	if(root != NULL){
//		if(root->item == '\n'){
//			printf("%s[%i]\n",temp,root->freq);	
//		}
//		else{
//			printf("%s%c[%i]\n",temp,root->item,root->freq);
//		}
//		PrintTree(root->left,temp);
//		PrintTree(root->right,temp);
//	}
//}


