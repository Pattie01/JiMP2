#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstring>
using namespace std;

int main(){
	int wybor;
	char szachownica[5][5] = {{'A','B','C','D','E'},{'F','G','H','I','K'},{'L','M','N','O','P'},{'Q','R','S','T','U'},{'V','W','X','Y','Z'}}; 
	bool znaleziona = false;
	cout << "-----------MENU-----------" << endl;
	cout << "0 - Odszyfruj wiadomosc" << endl << "1 - Zaszyfruj wiadomosc" << endl ;
	cout << endl << "Twoj wybor: ";
	cin >> wybor;
	
	cout << endl << "Szachownica Polibiusza" << endl; 
	for(int i=0; i<5; ++i){
		for(int j=0; j<5; ++j){
			cout << setw(2)<< szachownica[i][j];
		}
		cout << endl;
	}
	
	switch(wybor){
		case 0:
			{
			ifstream szyfr("zaszyfrowana_wiadomosc.txt");
			ofstream wiadomosc("odszyfrowana_wiadomosc.txt", ios_base::in | ios_base::app);
			char linijka[256];
			
			if(!szyfr) cout << "Nie mozna otworzyc pliku!" << endl;
			if(!wiadomosc) cout << "Nie mozna otworzyc pliku do zapisu!" << endl;
			
			cout << endl << "---Wiadomosc odszyfrowana---" << endl;
			while(!szyfr.eof()){
				szyfr.getline(linijka,256);
				for(int i=0; i<strlen(linijka);i++){
					for(int j=0; j<5; ++j){
						for(int k=0; k<5; ++k){
							if(linijka[i]==('0'+j+1) && linijka[i+1]==('0'+k+1)){  
							cout << szachownica[j][k];
							wiadomosc << szachownica[j][k];
							}
						}
					}
					if(linijka[i]==' ' && linijka[i+1]==' '){	
						cout << " ";
						wiadomosc << " ";
					}
				}
				cout << endl;
				wiadomosc << endl;
			}

			wiadomosc.close();
			szyfr.close();			
		}			
		break;
		
		case 1: {
			ifstream wiadomosc("wiadomosc.txt");
			ofstream szyfr("zaszyfrowana_wiadomosc.txt", ios_base::in | ios_base::app);
			char linijka[256];
			
			if(!wiadomosc) cout << "Nie mozna otworzyc pliku!" << endl;
			if(!szyfr) cout << "Nie mozna otworzyc pliku do zapisu!" << endl;
			
			cout << endl << "---Wiadomosc zaszyfrowana przy uzyciu szachownicy Polibiusza---" << endl;
			
			while(!wiadomosc.eof()){
				wiadomosc.getline(linijka,256);
				for(int i=0; i<strlen(linijka); ++i){
					if(linijka[i]=='J'){
						linijka[i]='I';
					}
					for(int j=0; j<5; ++j){
						for(int k=0; k<5; ++k){
							if(linijka[i]==szachownica[j][k]){
								cout << j+1 << k+1 <<" ";
								szyfr << j+1 << k+1 << " ";
 							}
						}
					}
					if(linijka[i]==' '){
						cout << " ";
						szyfr <<" ";
					}
				}
				cout << endl;
				szyfr << '\n';
			}
			
			wiadomosc.close();
			szyfr.close();
		}
		break;
		
		default:
			cout << "Blednie wybrana opcja z menu!"<< endl; 
	}
	return 0;
}
