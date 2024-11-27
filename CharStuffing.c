#include <stdio.h>
#include <string.h>
int main(){
	char ip[100], op[100];
	int i, ln, j;
	
	printf("\n Enter a text: ");
	gets(ip);
	
	for(i=0, j=0; ip[i]!='\0'; i++, j++){
		op[j]= ip[i];
		if(strncmp(ip+i, "FLAG", 4)==0){
			op[j]='\0';
			strcat(op, "ESC FLAG");
			i=i+3; 
			j=j+7;
		}
		if(strncmp(ip+i, "ESC", 3)==0){
			op[j]='\0';
			strcat(op, "ESC ESC");
			i=i+2;
			j=j+6;
		}
	}
	op[j]= '\0';
	printf("\n Output is: FLAG %s FLAG", op);
}
