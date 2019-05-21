#pragma once

class CVozlisce
{
public:
	char znak;
	int pon;
	CVozlisce *levi;
	CVozlisce *desni;


	CVozlisce(char z, int p);
	CVozlisce(char z, int p, CVozlisce *l, CVozlisce *d);
	~CVozlisce(void);
};
