/*
**    Ali Tüzün g151210006-2C
**    Tuğçe Şahin g151210009-2C
**    since 22.04.2018
**    Hocam txtleri aynı dosyadan okuyoruz.
**
**
*/

#include "Kisi.h"
#include <string.h>
int main(){
  while(1){
    int secim;
    int turetmesayisi;
    printf("1-Random Kisi Olustur\n");
    printf("2-Uretilmis Dosyayi Kontrol Et\n");
    printf("3-Cikis\n");
    scanf("%d",&secim);
    if(secim==1){
    printf("Kac Random Kisi olusturulsun?\n");
    scanf("%d",&turetmesayisi);
  int i=0;
  srand((unsigned)time(NULL));
  FILE *f = fopen("randomkisi.txt", "w");//olusturulan random kisiler bu klasore yazılıyor
  if (f == NULL)
  {
      printf("Error opening file!\n");
      exit(1);
  }

  /* print some text */
  User kisi;
  for(i=0;i<turetmesayisi;i++)
  {
    kisi=KisiBilgileriUret();//tanımladıgımız structdan nesne olusturup özelliklerini txtye yazdırıyoruz
    fprintf(f,"%s %s %d %s (%s) \n",kisi->TcNo,kisi->RastgeleKisi,kisi->KisiYas,kisi->TelNo,kisi->ImeiNo);
  }
    printf("Olusturulan Kisiler randomkisi.txt klasorune yazildi\n\n");
  fclose(f);
  free(kisi->TcNo);//Malloc kullandıgımız nesneleri boşaltip cop olmasini engelliyoruz
  free(kisi->RastgeleKisi);
  free(kisi->ImeiNo);
  free(kisi->TelNo);
  free(kisi);
}
    if(secim==2){
      int gecerli=0,gecersiz=0,gecerlimei=0,gecersizimei=0;
      char dest[12];
      memset(dest, '\0', sizeof(dest));
      FILE *fp;
      size_t bufsize = MAXCHAR-1;
      ssize_t nread;
      int satir=0;
      char* str=(char*)malloc(sizeof(char)*MAXCHAR);
      char* filename = "kisiler.txt";//kontrol yapıalcak klasoru burada
      char *c1="(";
      char *c2=")";
      char *target = NULL;
      char *start, *end;
      fp = fopen(filename, "r");
      if (fp == NULL){
      printf("Could not open file %s",filename);
      //return 1;
      }
      while ((nread = getline(&str,&bufsize,fp)) != -1){
        strncpy(dest, str, 11);//Txt içerisinde ilk 11 hane her zaman tc olacağı için
        if(kontrol(dest)==1)//kontrol ediyoruz true ise gecerli sayisi artıyor aksı halde gecersiz artıyor.
        {
            gecerli++;
        }
        else
        {
            gecersiz++;
        }
        start=strstr(str,c1);
        start += strlen( c1 );
                if ( end = strstr( start, c2 ) )
                {
                    target = ( char * )malloc( end - start + 1 );
                    memcpy( target, start, end - start );
                    target[end - start] = '\0';
                }//"(",")" arasını almak için bu işlemi uyguladık
        if(kontrolimei(target)==1)
        {
          gecerlimei++;
        }
        else{
          gecersizimei++;
        }
        satir++;
        free(target);//malloc la ayırdıgımız alanı boşaltıyoruz.
      }
      printf("\nT.C Kontrol\n");
      printf("%d Gecerli\n",gecerli );
      printf("%d Gecersiz\n\n",gecersiz );
      printf("IMEI Kontrol\n");
      printf("%d Gecerli\n",gecerlimei );
      printf("%d Gecersiz\n\n",gecersizimei );
      free(str);
    }
    if(secim==3){
      exit(0);
    }
  }
}
