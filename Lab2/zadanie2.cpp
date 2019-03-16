#include<iostream>
#include<iomanip> 	
using namespace std;

void uzupelnij(int **tab, int rozmiar){
	for(int i=0; i<rozmiar; ++i){
		for(int j=0; j<rozmiar; ++j){
			tab[i][j]=i*rozmiar+(j+1);
		}
	}
}

void wypisz(int **tab, int rozmiar){
	for(int i=0; i<rozmiar; ++i){
		for(int j=0; j<rozmiar; ++j){
			cout << setw(2) << tab[i][j] << "  ";
		}
		cout << endl;
	}
}

int main(){
	int wymiar;
	cout << "Podaj wymiar tablicy: ";
	cin >> wymiar;

	int **tab = new int *[wymiar];
	for(int i=0; i<wymiar; ++i){
		tab[i] = new int [wymiar];
	}
	
	uzupelnij(tab,wymiar);
	wypisz(tab,wymiar);

	for(int i=0; i<wymiar; ++i){
		delete [] tab[i];
	}
	delete [] tab;		
	return 0;
}
