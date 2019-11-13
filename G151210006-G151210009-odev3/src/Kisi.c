#include "Kisi.h"
int YasUret()
{
		int yas=0;
		yas=rand()%100+1;
		return yas;
}

User KisiBilgileriUret(){

	 	User this;
		this=(User)malloc(sizeof(struct Kisi));
		//this->RastgeleKisi=malloc(sizeof(char)*250);
		//this->TelNo=malloc(sizeof(char)*11);
		this->KisiYas=YasUret();
		this->RastgeleKisi=_rastgeleKisiUret();
		//this->RastgeleKisi=RndmKisiOlustur();
		this->TelNo=tel();
		this->TcNo=tc();
		this->ImeiNo=imei();
		return this;
}
