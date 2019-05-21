// haffman.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Koda.h"
#include "Vozlisce.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void LSD (CVozlisce* v, string kod, vector <CKoda> &lol){
	if (v!=NULL){
		LSD(v->levi, kod+"0", lol);
		if (v->levi==NULL && v->desni==NULL){
			CKoda i(v->znak,kod);
			lol.push_back(i);
		}
		LSD(v->desni, kod+"1", lol);
	}

}



int _tmain(int argc, _TCHAR* argv[])
{
	cout << "vpisi besedilo : " << endl;
	string a;
	getline(cin, a);
	string b;
	b=a;

	vector<CVozlisce*> list;
	
	string m;

	for (int i=0; i<b.size(); i++){
		if (m.find(b[i])==string::npos)
			m+=b[i];
	}
	int* h;
		h=new int [m.size()];

	for (int i=0; i<m.size(); i++){
		int st=0;
		while (b.find(m[i])!=string::npos){
			st++;
			b.erase(b.find(m[i]),1);
		}
		h[i]=st;
	}
	for (int i=0; i<m.size(); i++){
		CVozlisce* al; (m[i], h[i], NULL, NULL);
		al=new CVozlisce (m[i],h[i],NULL,NULL) ;
		list.push_back (al);
	}

	while (list.size()>1){
		//dolocim v1
		CVozlisce* v1;
			v1=new CVozlisce (list[0]->znak,list[0]->pon,list[0]->levi,list[0]->desni) ;
			
		int j=0;
		for (int i=0; i<list.size(); i++)
			if (list[i]->pon<v1->pon){
				v1->pon=list[i]->pon;
				v1->znak=list[i]->znak;
				v1->desni=list[i]->desni;
				v1->levi=list[i]->levi;
				j=i;
			}
		list.erase(list.begin()+j);
		//dolocim v2
		j=0;
		CVozlisce* v2;
			v2=new CVozlisce (list[0]->znak,list[0]->pon,list[0]->levi,list[0]->desni) ;
			
		for (int i=0; i<list.size(); i++)
			if (list[i]->pon<v2->pon){
				v2->pon=list[i]->pon;
				v2->znak=list[i]->znak;
				v2->desni=list[i]->desni;
				v2->levi=list[i]->levi;
				j=i;
			}
		list.erase(list.begin()+j);
		//
		CVozlisce* h;
			h=new CVozlisce ('*',(v1->pon+v2->pon),v1,v2) ;
			h->znak='*';
			h->pon=(v1->pon+v2->pon);
			h->levi=v1;
			h->desni=v2;
		
		list.push_back(h);

	}

	vector <CKoda> kod;
	string v;
	LSD(list[0], v, kod );


	cout << "znaki so: " << m << endl;
	cout << "koda za vsak posamicen znak je: " << endl;
	for (int i=0; i<kod.size(); i++){
		cout << kod[i].zn << " " << kod[i].koda << endl;
	}
	cout << "zakodirano  besedilo pa izgleda: " << endl;
	for (int i=0; i<a.size(); i++){
		for (int j=0; j<kod.size(); j++){
			if (a[i]==kod[j].zn)
				cout << kod[j].koda;
		}
	}





	cin.ignore();
	cin.get();
	return 0;
}

