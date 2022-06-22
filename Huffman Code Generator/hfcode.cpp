#include "header.h"

void selectionSort(int example[],char example2[], int n){
	int i, j, min_idx;

	// One by one move boundary of unsorted subarray
	for (i = 0; i < n-1; i++)
	{
		// Find the minimum element in unsorted array
		min_idx = i;
		for (j = i+1; j < n; j++)
		if (example[j] < example[min_idx])
			min_idx = j;

		// Swap the found minimum element with the first element
		swap(&example[min_idx], &example[i],&example2[min_idx], &example2[i]);
	}
}

void DeleteDuplicate(char text[], int value[], char value2[]){
	
  	strcpy(value2,text);
	int length= strlen(value2);
 	for(int i=0; i<length; i++){
	    char ch = value2[i];
	    for(int j=i+1; j<length; ){  
			if(value2[i] == value2[j]){
				for(int k=j; k<length; k++){
					value2[k] = value2[k+1];
				}
				length--;
			}
			else {
				j++;
			}
		} 
	}
	
	for(int i = 0;i<strlen(value2);i++){
		for(int j=0;j<strlen(text);j++){
			if(value2[i] == text[j]){
				value[i]+=1;
			}
		}
	}
}

char *input(char str[255]){
	
	int pil;
	FILE *fptr;
	char fname[25];
	
	printf("\t 1. Input Data\n");
	printf("\t 2. Input File\n");

		do{
			ulang:
			printf("\t Masukkan Pilihan	: ");
			scanf("%i",&pil);
			switch(pil){
				case 1:{
					printf("\t Masukkan Kata/Kalimat  :  ");
			  		fflush(stdin);gets(str);
		//			scanf("%s",&str);
			  		printf("\t Input Selesai Silahkan Lanjutkan\n");	
					return str;
					break;
				}
				case 2:{
					printf("\t Masukkan Nama File	: ");
					fflush(stdin);gets(fname);
					char temp;
					
					if ((fptr = fopen(fname,"rt")) == NULL){
		      			printf("\t File kosong\n\n");
		      			return str;
		   			}
		   			else{
						fgets (str, 255, fptr);
						fclose(fptr);
						printf("\t File Berhasil diinput");
						return str;
					}
					break;
				}
				default:{
					printf("\tPilihan Anda Salah \n\n");
					getch();
					break;
				}
			}
		}while(pil != 1 || pil != 2);
}

void end_file(struct TreeNode *node, char result[], int n , char str[], int i, char temp[]){
	if (node == NULL)
	{
		return;
	}
	if (node->left == NULL && node->right == NULL)
	{
		if(str[i] == node->item){
			result[n] = '\0';
			strcat(temp,result);
			printf("%s",result);
			return;
		}
	}
	result[n] = '0';
	end_file(node->left, result, n + 1, str, i, temp);
	result[n] = '1';
	end_file(node->right, result, n + 1, str, i, temp);
}

void dec_file(struct TreeNode *node,int n, char tamp[], char str[]){
	if (node == NULL)
	{
		return;
	}
		for(int j = 0;j<=1;j++){
			if(tamp[j] == '0'){
				node = node->left;
			}else{
				node = node->right;
			}
			j++;
		}
	printf("%s",str);	
}



