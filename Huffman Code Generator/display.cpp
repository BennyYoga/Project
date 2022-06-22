#include "header.h"

// Print elements of queue
void printQdata(struct PriorityQueue *q)
{
	struct QNode *node = q->front;
	
	printf("\n\t  Queue Element \n");
	
	for(int i =0;i<15;i++){
		if(i==0)printf("\t %c",201);
		else if(i==14)printf("%c",187);
		else if (i==7)printf("%c",203);
		else printf("%c",205);	
	}
	printf("\n\t %c Freq %c Char %c\n ",186,186,186);
	
	
	for(int i =0;i<15;i++){
		if(i==0)printf("\t %c",204);
		else if(i==14)printf("%c",185);
		else if (i==7)printf("%c",206);
		else printf("%c",205);	
	}
	
	while (node != NULL)
	{
		printf("\n\t %c  %d   %c   %c  %c",186, node->n->freq,186,node->n->item,186);
		node = node->next;
	}
	
	printf("\n");
	
	for(int i =0;i<15;i++){
		if(i==0)printf("\t %c",200);
		else if(i==14)printf("%c",188);
		else if (i==7)printf("%c",202);
		else printf("%c",205);	
	}
}
// Display Huffman code
int x=0;
void PrintHuffman(struct TreeNode *node, char result[], int n, encoding tamp[])
{
	if (node == NULL)
	{
		return;
	}
	if (node->left == NULL && node->right == NULL)
	{
		result[n] = '\0';
		tamp[x].info = node->item;
		strcpy(tamp[x].value,result);
		printf("\n\t %c = %s", node->item, result);
		x+=1;
		return;
	}
	result[n] = '0';
	PrintHuffman(node->left, result, n + 1, tamp);
	result[n] = '1';
	PrintHuffman(node->right, result, n + 1, tamp);
}

void PrintArr(Hasil x){
	printf("\n\t Hasil Delete Duplicate = %s ", x.temp);
	printf("\n\t Frequensi hasil delete = ");
	for(int i=0;i<strlen(x.temp);i++){
		printf("%i ",x.freq[i]);
	}
}

/* Function to print an array */
void printArray(int arr[], int size)
{
	int i;
	for (i=0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

 
void showTrunks(Trunk *p)
{
    if (p == nullptr) {
        return;
    }
 
    showTrunks(p->prev);
    cout << p->str;
}
 
void printTree(struct TreeNode *root, Trunk *prev, bool isLeft)
{
    if (root == nullptr) {
        return;
    }
 
    string prev_str = "   ";
    Trunk *trunk = new Trunk(prev, prev_str);
 
    printTree(root->right, trunk, true);
 
    if (!prev) {
        trunk->str = "---";
    }
    else if (isLeft)
    {
        trunk->str = "1---";
        prev_str = "   |";
    }
    else {
        trunk->str = "0---";
        prev->str = prev_str;
    }
 
    showTrunks(trunk);
    cout << "|" << root->freq << "*" << root->item << endl;
 
    if (prev) {
        prev->str = prev_str;
    }
    trunk->str = "   |";
 
    printTree(root->left, trunk, false);
}


