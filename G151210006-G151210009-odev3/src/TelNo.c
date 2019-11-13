#include "TelNo.h"

char* tel(){
	char* elements = (char*)malloc(sizeof(char)*TEL_SIZE);
	char veri='0';
  	elements[0]=0+veri;
	elements[1]=5+veri;
	elements[2]=3+veri;
	int w=rand()%10;
	elements[3]=w+veri;
	for(int i =4;i<7;i++){
	int y=rand()%10;
	elements[i]=y+veri;
	}
	for(int i =7;i<11;i++){
	int y=rand()%10;
	elements[i]=y+veri;
	}
	elements[TEL_SIZE-1]='\0';
	return elements;
}
