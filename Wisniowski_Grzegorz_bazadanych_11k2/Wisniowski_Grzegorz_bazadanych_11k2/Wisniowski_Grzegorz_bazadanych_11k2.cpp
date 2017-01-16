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
void wyszukajProdukt(float cena;
void wczytaj_z_pliku();
void zapisz_do_pliku();

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


	do {


		cout << "*~~~~BAZA PRODUKTOW~~~~*" << endl;
		cout << " 1 - wyswietl produkty\n 2 - dodaj produkt\n 3 - usun produkt\n 4 - edytuj produkt\n 5 - wczytaj dane z pliku\n 6 - wyjdz\n" << endl;

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
				cout << "Podaj ID produktu do usuniecia: ";
				cin >> id;
				usunProdukt(id);
			break;
		case 4:
			wyswietlProdukty();
				cout << "Podaj ID produktu do edycji: ";
				cin >> id;
				edytujProdukt(id);
			break;
		case 5:
			wczytaj_z_pliku();
			break;
		case 6:
			return 6;
		default:
			cout << "Wybierz opcje od 1 do 9!" << endl << endl;
		}

	} while (x != 6);


	return 0;
}

void wyswietlProdukty()
{
	for ( int i = 0; i < dane.size(); i++)
	{
		cout << "ID: " << dane[i].id << "\tNazwa: " << dane[i].name << "\tCena[PLN]: " << dane[i].price << "\t" << endl;
	}
	cout << endl;

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

	plik.open("dane.txt", ios::app);
	plik << new_product.id << "\t" << new_product.name << "\t" << new_product.price << "\n";
	plik.close();
}

void usunProdukt( int productID)
{
	if (dane.empty())
	{
		cout << "Baza jest pusta" << endl;
	}
	else
	{
		for (int i = 0; i < dane.size(); i++)
		{
			if (dane[i].id == productID)
			{
				dane.erase(dane.begin() + i);

				cout << "Produkt zostal usuniety" << endl << endl;
			}
			else
			{
				cout << "\nNie znaleziono produktu o podanym ID!\n" << endl;
			}
		}
	}
}

void edytujProdukt( int productID)
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
			if (dane[i].id == productID)
			{
				cout << "Podaj nowa nazwe produktu: ";
				cin >> dane[i].name;

				cout << "Podaj nowa cene produktu: ";
				cin >> dane[i].price;

				for (int i = 0; i < dane.size(); i++)
				{
					plik << dane[i].id << "\t" << dane[i].name << "\t" << dane[i].price << "\n";
				}
				plik.close();

				cout << endl << endl;
				return;
			}
		}
		cout << "\nNie znaleziono produktu o podanym ID!\n" << endl;
	}
}

void wczytaj_z_pliku()
{

	plik.open("dane.txt", ios::in);

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

		dane.push_back(new_product);
	}
	plik.close();
	cout << "wczytano dane z pliku" << endl << endl;
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
			while (!plik.eof())
			{
				for (int i = 0; i < dane.size(); i++)
				{
					plik >> dane[i].id >> "\t" >> dane[i].name >> "\t" >> dane[i].price >> "\n";
				}
			}
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