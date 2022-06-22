#ifndef header_H
#define header_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <iostream>
using namespace std;


struct TreeNode
{
	int freq;
	char item;
	struct TreeNode *left;
	struct TreeNode *right;
};
struct QNode
{
	struct TreeNode *n;
	struct QNode *next;
	struct QNode *prev;
};
struct PriorityQueue
{
	struct QNode *front;
	struct QNode *rear;
	int size;
};
struct Hasil{
	char temp[100];
	int freq[100]={0};
};

struct encoding{
	char info;
	char value[255];
};

struct Trunk
{
    Trunk *prev;
    string str;
 
    Trunk(Trunk *prev, string str)
    {
        this->prev = prev;
        this->str = str;
    }
};

struct Node
{
    int data;
    Node *left, *right;
 
    Node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};
 
 

// Returns a new tree node 
struct TreeNode *newTreeNode(int freq, char item);

// Returns a new queue 
struct PriorityQueue *newPriorityQueue();

// Get a front element of queue
struct TreeNode *peek(struct PriorityQueue *q);

// Construct Huffman Code Tree
struct TreeNode *buildHuffmanCodes(char value[], int frequency[], int n);

void enQueue(struct PriorityQueue *q, struct TreeNode *auxiliary);

int isEmpty(struct PriorityQueue *q);

int isSize(struct PriorityQueue *q);

void deQueue(struct PriorityQueue *q);

void printQdata(struct PriorityQueue *q);

void PrintHuffman(struct TreeNode *node, char result[], int n, encoding tamp[]);

void end_file(struct TreeNode *node, char result[], int n , char str[], int i,char temp[]);

void dec_file(struct TreeNode *node, int n ,char temp[], char str[]);

void swap(int *xp, int *yp, char *xc, char *yc);

void selectionSort(int example[],char example2[], int n);

//void PrintTree(struct TreeNode* root, char tab[]);

void PrintArr(Hasil x);

void printArray(int arr[], int size);

void printTree(struct TreeNode *root, Trunk *prev, bool isLeft);

void DeleteDuplicate(char text[], int value[], char value2[]);

void MakeEncode(char Encode[255][255], char str[], encoding encode[], Hasil TotalValue);

void MakeDecode(char Encode[255][255], char str[],encoding encode[]);

char *input(char str[255]);

void menu();

#endif
