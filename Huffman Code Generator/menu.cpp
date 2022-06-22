#include "header.h"

void menu(){
		char pil;
		
		int x ;
		char result[255], temp[255];
		Hasil TotalValue;
		encoding encode[255];
	  	char str[100];
	  	char s[100] = "";
	  	char Encode[255][255];
		TreeNode *root;
		
		
	do{
		
		system("cls");
		
		printf("\t%c",201);
		for(int i=0; i<39;i++){
			printf("%c",205);
		}
		printf("%c\n",187);
		printf("\t%c 		Huffman Code 		%c\n",186,186);
		printf("\t%c",204);
		for(int i=0; i<39;i++){
			printf("%c",205);
		}
		printf("%c\n",185);
		
		printf("\t%c 					%c\n",186,186);
		printf("\t%c *Lakukan Secara Berurutan		%c\n",186,186);
		printf("\t%c 					%c\n",186,186);
		printf("\t%c 1. Input Teks				%c\n",186,186);
		printf("\t%c 2. Delete Duplicate & Sort Teks	%c\n",186,186);
		printf("\t%c 3. Queue Element			%c\n",186,186);
		printf("\t%c 4. Tree of Huffman			%c\n",186,186);
		printf("\t%c 5. Encode & Decode			%c\n",186,186);
		printf("\t%c 6. Keluar Program			%c\n",186,186);
		printf("\t%c 					%c\n",186,186);
		
		printf("\t%c",200);
		for(int i=0; i<39;i++){
			printf("%c",205);
		}
		printf("%c\n",188);
		
		printf("\t  Masukkan Pilihan	: ");		
		scanf("%i",&pil);fflush(stdin);
		
		switch(pil){
			case 1:{
				ZeroMemory(&str, sizeof(str));fflush(stdin);
				ZeroMemory(&TotalValue, sizeof(TotalValue));fflush(stdin);	
					
				TreeNode *root;
				strcpy(str,input(str));
				getch();
				
				DeleteDuplicate(str,TotalValue.freq,TotalValue.temp);
				x = strlen(TotalValue.temp);
				selectionSort(TotalValue.freq,TotalValue.temp,x);
				
				break;
			}
			case 2:{
				printf("\n\tTeks	: %s\n",str);
				
				printf("\n\tNot sorted array:");
				PrintArr(TotalValue);
				
				printf("\n\n\tSorted array:");
				PrintArr(TotalValue);
				getch();
				break;
			}
			case 3:{
				x = strlen(TotalValue.temp);
				result[x + 1];
				root = buildHuffmanCodes(TotalValue.temp, TotalValue.freq, x);
				getch();
				break;
			}
			case 4:{
				printf("\n\t Tree Of Huffman Code\n\n");
				printTree(root,nullptr,false);
				printf("\n\n\t Huffman Code\n");
				PrintHuffman(root, result, 0, encode);
				getch();
				break;
			}
			case 5:{
				printf("\n\t Encode String \n\t ");
				for(int i=0;i<strlen(str);i++){
					end_file(root,result,0,str, i, temp);
				}
				printf("\n\n\t Decode to String \n\t ");	
				dec_file(root,0,temp, str);
				getch();
				break;
			}
			case 6:{
				
				break;
			}
			default:{
				printf("\tPilihan Salah");
				getch();
				break;
			}
			
		}
	}while(pil != 6);
}