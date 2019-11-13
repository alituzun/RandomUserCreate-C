#include "TcNo.h"
char* tc(){

	char *elements= malloc(sizeof(char)*TC_SIZE);
	char veri='0';
	int ara1=0,ara2=0,ara3=0,ara4=0;
	int c=rand()%9+1;
	elements[0]=c+veri;
	int d=rand()%9+1;
	elements[8]=d+veri;
	for(int i=2;i<7;i++){
		int a=rand()%10;
		elements[i]=a+veri;
		ara1+=a;
		i++;
	}
	for(int k=1;k<8;k++){
		int b=rand()%10;
		elements[k]=b+veri;
		ara2+=b;
		k++;
	}
	ara3=(ara1*7)+(c*7)+(d*7)-ara2;
	elements[9]=(ara3%10)+veri;
	for(int l=0;l<10;l++){
		ara4+=(elements[l]-veri);
	}
	elements[10]=(ara4%10)+veri;
	elements[11]='\0';
	return elements;
}
int kontrol(char dest[]){
	char girtc[11];
	strcpy(girtc,dest);
	char veri='0';
		int toplam = 0; int toplam2 = 0; int toplam3 = 0,len;
		len=strlen(girtc);
	   if(len==11){
			 if(girtc[0]==0){
				 return 0;
			 }
		 	for(int i=0;i<10;i++){
				toplam+=girtc[i]-veri;
			//	printf("%d\n",toplam );
					if(i%2==0)
					{
						if(i!=10)
						{
							toplam2+=girtc[i]-veri;
						}
					}
					else{
						if(i!=9)
						{
							toplam3+=girtc[i]-veri;
						}
					}
			}
	 }
	 else{
		 return 0;
	 }
	 if((((toplam2*7)-toplam3)%10)==(girtc[9]-veri))
	 {
		 if((toplam%10)==(girtc[10]-veri)){
			return 1;
		}
			else{
			return 0;
		}
	 }
	 else{
		 return 0;
	 }
}
