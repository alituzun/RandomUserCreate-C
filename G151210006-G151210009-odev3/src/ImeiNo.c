#include "ImeiNo.h"
char* imei(){
	char *elements= malloc(sizeof(char)*IMEI_SIZE);
	char veri='0';
	int toplam1=0,toplam2=0,toplam3=0,mod=0,ara1=0,ara2=0,mod1=0;
	for(int i=2;i<=12;i++){
	int y=rand()%9+1;
	int z=rand()%10;
	elements[0]=(y+veri);
	elements[i]=(z+veri);
	toplam1+=z;
	i++;
}
	for(int k=1;k<=13;k++){
	int z=rand()%10;
	elements[k]=(z+veri);
	int w=z*2;
	if(w>=10){
	mod=w%10;
	ara1=mod+1;
	toplam2=toplam2+ara1;
}
	else{
	toplam3=toplam3+w;
}
	k++;
}
	ara2=toplam1+toplam2+toplam3+(elements[0]-veri);
	mod1=ara2%10;
	if(mod1==0){
	elements[14]=(0+veri);
}
	else{
	elements[14]=((10-mod1)+veri);
}
elements[15]='\0';
		return elements;
}
int kontrolimei(char *target){
	char veri='0';
	int i=0,checksum=0, sum=0, len=14,num=0;
	char *imei= malloc(sizeof(char)*IMEI_SIZE);
	memset(imei, '\0', sizeof(imei));
	strcpy(imei, target);
	for(i=0;i<len;i++){
	    num=((imei[i]-veri)%10);
	    //imei[i]-=num;
	    //imei[len-1-i]/=10;
	    if(i%2 != 0){
	        num = num*2;
	        if(num>=10)
	            num=(num%10 + 1);
	    }
	    sum+=num;
	}
	if(imei[0]=0)
	{
		return 0;
	}
	if(sum%10==0){
		checksum=0;
	}
	else{
	checksum = (10 - (sum%10));
}
	if(imei[14]==(checksum+veri)){
	    return 1;
	  }
	else{
		return 0;
	}
}
