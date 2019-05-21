#include "StdAfx.h"
#include "Vozlisce.h"

CVozlisce::CVozlisce(char z, int p)
{
	pon = p;
	znak = z;
	levi = NULL;
	desni = NULL;
}

CVozlisce::CVozlisce(char z, int p, CVozlisce *l, CVozlisce *d){
	znak=z;
	pon=p;
	levi=l;
	desni=d;
}

CVozlisce::~CVozlisce(void)
{
}
