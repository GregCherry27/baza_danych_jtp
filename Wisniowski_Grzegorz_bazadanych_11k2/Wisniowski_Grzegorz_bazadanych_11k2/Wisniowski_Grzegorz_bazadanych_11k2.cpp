// Wisniowski_Grzegorz_bazadanych_11k2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

void wyswietlProdukty();
void dodajProdukt();
void usunProdukt(int productID);
void edytujProdukt(int productID);
void wyszukajProdukt(int id);
void wyszukajProdukt(string nazwa);
void wyszukajProdukt(float cena);
void wczytaj_z_pliku();
void zapisz_do_pliku();
void dodaj_do_piku();

 int ID = 0;

struct Produkt
{
	 int id;
	string name;
	float price;

};

vector<Produkt> dane;
fstream plik;

int main()
{
	int x;
	int id;
	char wybor;
	string nazwa;
	float cena;

	do {


		cout << "*~~~~BAZA PRODUKTOW~~~~*" << endl;
		cout << " [1] - wyswietl produkty\n [2] - dodaj produkt\n [3] - usun produkt\n [4] - edytuj produkt\n [5] - wczytaj dane z pliku\n [6] - zapisz baze do pliku\n [7] - dodaj produkt do pliku\n [8] - wyszukaj produkt\n [9] - wyjdz\n" << endl;

		cin >> x;
		system("cls");

		cout << endl;

		switch (x)
		{
		case 1:
			cout << "Aktualnie w bazie: " << endl;
			wyswietlProdukty();
			break;
		case 2:
			cout << "Dodawanie produktu: " << endl;
			dodajProdukt();
			break;
		case 3:
			wyswietlProdukty();
			if (dane.empty())
			{

			}
			else
			{
				cout << "Podaj ID produktu do usuniecia: ";
				cin >> id;
				usunProdukt(id);
			}
			break;
		case 4:
			wyswietlProdukty();
			if (dane.empty())
			{

			}
			else
			{
				cout << "Podaj ID produktu do edycji: ";
				cin >> id;
				edytujProdukt(id);
			}
			break;
		case 5:
			wczytaj_z_pliku();
			break;
		case 6:
			zapisz_do_pliku();
			break;
		case 7:
			dodaj_do_piku();
			break;
		case 8:
				if (dane.empty())
				{
					cout << "Baza jest pusta" << endl << endl;
				}
				else
				{
					cout << "wybierz kryterium wyszukwiania: i - ID | n - nazwa | c - cena\n";
					cin >> wybor;
					if (wybor == 'i')
					{
						cout << "podaj ID produktu ktorego szukasz: ";
						cin >> id;
						cout << endl;
						wyszukajProdukt(id);
					}
					else if (wybor == 'n')
					{
						cout << "podaj nazwe produktu ktorego szukasz: ";
						cin >> nazwa;
						cout << endl;
						wyszukajProdukt(nazwa);
					}
					else if (wybor == 'c')
					{
						cout << "podaj cene produktu ktorego szukasz: ";
						cin >> cena;
						cout << endl;
						wyszukajProdukt(cena);
					}
					else if (wybor != 'i' || wybor != 'n' || wybor != 'c')
					{
						cout << "nie wybrales wlasciwie kryterium" << endl;
					}
				}
			break;
		case 9:
			return 9;
		default:
			cout << "Wybierz opcje od 1 do 9!" << endl << endl;
		}

	} while (x != 9);


	return 0;
}

void wyswietlProdukty()
{
	if (dane.empty())
	{
		cout << "Baza jest pusta" << endl << endl;
	}
	else
	{
		for (int i = 0; i < dane.size(); i++)
		{
			cout << "ID: " << dane[i].id << "\tNazwa: " << dane[i].name << "\tCena[PLN]: " << dane[i].price << "\t" << endl;
		}
		cout << endl;
	}

}

void dodajProdukt()
{
	Produkt new_product;

	cout << "Podaj nazwe produktu: ";
	cin >> new_product.name;

	cout << "Podaj cene produktu: ";
	cin >> new_product.price;
	cout << endl << endl;

	new_product.id = ID;
	ID++;

	dane.push_back(new_product);

	/*plik.open("dane.txt", ios::app);
	plik << new_product.id << "\t" << new_product.name << "\t" << new_product.price << "\n";
	plik.close();*/
}

void usunProdukt( int productID)
{
		for (int i = 0; i < dane.size(); i++)
		{
			if (dane[i].id == productID)
			{
				dane.erase(dane.begin() + i);

				cout << "Produkt zostal usuniety" << endl << endl;
				return;
			}
		}

		cout << "\nNie znaleziono produktu o podanym ID!\n" << endl;
}

void edytujProdukt( int productID)
{
	//int f = dane.size();
	if (dane.empty())
	{
		cout << "Baza jest pusta" << endl << endl;
		return;
	}
	else if(!dane.empty())
	{
		for (int i = 0; i < dane.size(); i++)
		{
			if (dane[i].id == productID)
			{
				cout << "Podaj nowa nazwe produktu: ";
				cin >> dane[i].name;

				cout << "Podaj nowa cene produktu: ";
				cin >> dane[i].price;

				cout << endl << endl;
			}
		}
	}
}

void wczytaj_z_pliku()
{
	plik.open("plik.txt", ios::in);

	if (plik.good())
	{
		while (!plik.eof())
		{
			int a;
			string b;
			float c;

			plik >> a >> b >> c;
			
				Produkt new_product;
				new_product.id = a;
				new_product.name = b;
				new_product.price = c;

				new_product.id = ID;
				ID++;

				dane.push_back(new_product);
		}
		plik.close();
		cout << "wczytano dane z pliku" << endl << endl;
	}
	else
	{
		cout << "Brak pliku!" << endl << endl;
	}
}

void zapisz_do_pliku()
{
	if (dane.empty())
	{
		cout << "Baza jest pusta" << endl << endl;
		return;
	}
	else
	{
		plik.open("plik.txt", ios::out);
		plik.close();

		plik.open("plik.txt", ios::app);

		for (int i = 0; i < dane.size(); i++)
		{
			plik << "\n" << dane[i].id << "\t" << dane[i].name << "\t" << dane[i].price;
		}
		plik.close();
	}
}

void wyszukajProdukt(int id)
{
	if (dane.empty())
	{
		cout << "Baza jest pusta" << endl << endl;
		return;
	}
	else
	{
		for (int i = 0; i < dane.size(); i++)
		{
			if (dane[i].id == id)
			{
				cout << "ID: " << dane[i].id << "\tNazwa: " << dane[i].name << "\tCena[PLN]: " << dane[i].price << "\t" << endl;
			}
		}
	}
}
	

void wyszukajProdukt(string nazwa)
{
	if (dane.empty())
	{
		cout << "Baza jest pusta" << endl << endl;
		return;
	}
	else
	{
		for (int i = 0; i < dane.size(); i++)
		{
			if (dane[i].name == nazwa)
			{
				cout << "ID: " << dane[i].id << "\tNazwa: " << dane[i].name << "\tCena[PLN]: " << dane[i].price << "\t" << endl;
			}
		}
	}
}

void wyszukajProdukt(float cena)
{
	if (dane.empty())
	{
		cout << "Baza jest pusta" << endl << endl;
		return;
	}
	else
	{
		for (int i = 0; i < dane.size(); i++)
		{
			if (dane[i].price == cena)
			{
				cout << "ID: " << dane[i].id << "\tNazwa: " << dane[i].name << "\tCena[PLN]: " << dane[i].price << "\t" << endl;
			}
		}
	}
}

void dodaj_do_piku()
{
	Produkt new_product;

	new_product.id = ID;
	ID++;

	cout << "Podaj nazwe produktu: ";
	cin >> new_product.name;

	cout << "Podaj cene produktu: ";
	cin >> new_product.price;
	cout << endl << endl;

	

	plik.open("plik.txt", ios::app);
	plik << "\n" << new_product.id << "\t" << new_product.name << "\t" << new_product.price;
	plik.close();
}