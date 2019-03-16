#include<iostream>
using namespace std;

struct wezel{
	int liczba;
	wezel *nastepny;
	wezel ();
};

wezel::wezel(){
	nastepny = 0;
}

struct lista{
	wezel *pierwszy;
	void dodajElement(int element);
	void wyswietl();
	lista();
};

lista::lista(){
	pierwszy = 0;
}

void lista::dodajElement(int element){
	wezel *nowy = new wezel;
	nowy->liczba = element;
	
	if(pierwszy==0){
		pierwszy = nowy;
	}else{
		wezel *wsk = pierwszy;
		while(wsk->nastepny){
			wsk = wsk->nastepny;
		}
		wsk->nastepny = nowy;
		nowy->nastepny = 0;
	}
}

void lista::wyswietl(){
	wezel *wsk = pierwszy;
	while(wsk){
		cout << "Liczba: " << wsk->liczba << endl;
		wsk = wsk->nastepny;
	}
}

int main(){
	
	lista *lista_jednokierunkowa = new lista;
	int liczba_elementow, element;
	cout << "Podaj liczbe elementow jaka chcesz dodac do listy: ";
	cin >> liczba_elementow;
	cout << "Podaj element jaki chcesz dodac do listy:" << endl;	
	for(int i=0; i<liczba_elementow; i++){
		cout << "- ";
		cin >> element;
		lista_jednokierunkowa->dodajElement(element);
	}	
	cout << "Twoja lista jednokierunkowa:" << endl;
	lista_jednokierunkowa->wyswietl();
	
	return 0;
}
