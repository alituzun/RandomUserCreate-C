#include "RandomKisi.h"

char* _rastgeleKisiUret()
{
  FILE *fp;
  size_t bufsize = MAXCHAR-1;
  ssize_t nread;
  int satir=0,i=0;
  satir=rand()%3000;
  char* str=(char*)malloc(sizeof(char)*MAXCHAR);
  char* filename = "random_isimler.txt";
    fp = fopen(filename, "r");
    if (fp == NULL){
        printf("Could not open file %s",filename);
        //return 1;
    }

    while ((nread = getline(&str,&bufsize,fp)) != -1){
          if(satir==i) break;
          i++;
          //printf( "%s ", str);
    }
    fclose(fp);
    for(i=0;str[i]!='\n';i++);
    str[i]='\0';
  return str;
}
