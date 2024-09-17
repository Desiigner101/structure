#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	stude s[3];
	int choice;
	int ctr=0;
	//printf("%s",s[1].name);
	do{
		printf("1 - Add Student\n");
		printf("2 - Display\n");
		printf("3 - Exit\n");
		printf("Enter choice: ");
		scanf("%d",&choice);
		
		switch(choice){
			case 1:
					inputStudent(s,&ctr);
					break;
			case 2:
					display(s,ctr);
					break;
		}
	}while(choice !=3);
	
	return 0;
}
