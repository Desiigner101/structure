#include<stdio.h>
#include "header.h"

void display(stude s[],int size){
	int x;
	for(x=0; x<size; x++){
		printf("Name: %s\t",s[x].name);
		printf("Id Number: %d\t",s[x].idno);
		printf("Age: %d\t",s[x].age);
		printf("\n");
	}
	
	
}


void inputStudent(stude s[], int *size){
	char name[50];
	if(*size == 3)
		printf("Array is full.\n");
	else{
		scanf("%s",name);
		strcpy(s[*size].name,name);
		scanf("%d",&s[*size].idno);
		scanf("%d",&s[*size].age);
		(*size)++;
	}
	
}

