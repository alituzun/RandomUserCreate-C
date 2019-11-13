#ifndef KISI_H
#define KISI_H
#include "Kisi.h"
#include "TelNo.h"
#include "ImeiNo.h"
#include "RandomKisi.h"
#include "TcNo.h"
#include "stdlib.h"
#include "time.h"

struct Kisi
{
    int KisiYas;
    char* TcNo;
    char* ImeiNo;
    char* RastgeleKisi;
    char* TelNo;
};

typedef struct Kisi* User;

User  KisiBilgileriUret();
#endif
