// Kontenery
#include <vector>	// Tablica
#include <set>		// Zbiór
#include <map>		// Słownik

// Adaptery
#include <queue>	// Kolejka
#include <stack>	// Stos

#include <iostream>
#include <stdio.h>
#include <cstdlib>

#include "Slav.h"

#define REPORT_ADAPTERS showMeAdapterSizes(queueOfSlavs,stackOfSlavs)
#define REPORT_CONTAINERS showMeContainerSizes(vectorOfSlavs,setOfSlavs,mapOfSlavs)

using namespace std;


void showMeContainerSizes(vector <Slav *>, set <Slav *>, map <Slav *, Slav*>);
void showMeAdapterSizes(queue <Slav *>, stack <Slav *>);

void containers(Slav *, int);
void adapters(Slav *, int);

int main(int argc, char const *argv[])
{
	int n = 2 * atoi(argv[1]);
	Slav *slavs = new Slav[n];
	map<GENDER,vector<Slav*>> genderOfSlavs;
	vector<Slav*> man;
	vector<Slav*> woman;
	cout << "# Generated Slavs" << endl;
	for (int i = 0; i < n; ++i)
	{
		cout << slavs[i].description() << endl;
		if(slavs[i].getGender()==MAN) man.push_back(slavs+i);
		else woman.push_back(slavs+i);
	}

	genderOfSlavs[MAN]=man;
	genderOfSlavs[WOMAN]=woman;

	cout<<"WSZYSCY MEZCZYZNI:\n";
	for(int i=0; i<genderOfSlavs[MAN].size();++i)
	{
		cout<<(genderOfSlavs[MAN][i])->description()<<endl;;
	}

	cout<<"WSZYSTKIE KOBIETY:\n";
	for(int i=0; i<genderOfSlavs[WOMAN].size();++i)
	{
		cout<<(genderOfSlavs[WOMAN][i])->description()<<endl;
	}

	containers(slavs, n);
	adapters(slavs, n);

	delete [] slavs;
}

void containers(Slav * slavs, int n)
{
	vector <Slav *> vectorOfSlavs;
	set <Slav *> setOfSlavs;
	map <Slav *, Slav *> mapOfSlavs;
	
	printf("# Containers\n");
	REPORT_CONTAINERS;
	printf("## vector\n");

	// Umieść Słowian w losowej kolejności w wektorze.
	vectorOfSlavs.push_back(slavs);

	for(int i = 1 ; i < n ; ++i  )
		{
			int number = rand() % vectorOfSlavs.size();
			vectorOfSlavs.insert(vectorOfSlavs.begin() + number , &(slavs[i]));
		}
    //vector < Slav * >:: iterator it_vector0fSlavs = vectorOfSlavs.begin()

	for(auto it_vector0fSlavs = vectorOfSlavs.begin() ; it_vector0fSlavs != vectorOfSlavs.end() ; ++ it_vector0fSlavs)
		cout << (* it_vector0fSlavs)->description()<<endl;

	// Wykorzystując iterator i funkcję description(), wyświetl wszystkich Słowian w wektorze

		

	REPORT_CONTAINERS;
	printf("## set\n");

	set <Slav *>:: iterator it;
	pair<set <Slav *>:: iterator,bool> ret;

	for(int i = 0; i < vectorOfSlavs.size() ; ++i) setOfSlavs.insert(*(vectorOfSlavs.begin() + i));
    // Przenieś wszystkich Słowian z wektoru do zbioru.
 	

 	// wyswietlanie slowian
 	/* for(auto it_set0fSlavs = setOfSlavs.begin() ; it_set0fSlavs != setOfSlavs.end() ; ++ it_set0fSlavs)
		cout << (* it_set0fSlavs)->description()<<endl;
	*/

	
	
	REPORT_CONTAINERS;
	printf("## map\n");

	// Stwórz słownik tworzący pary Słowian, z tych znajdujących się w zbiorze, czyszcząc zbiór
	
	// Wykorzystując iterator, wyświetl wszystkie pary Słowian

	for( ;!setOfSlavs.empty() ; )
		{
			mapOfSlavs[* (setOfSlavs.begin())]  =  *(--setOfSlavs.end()) ;
			setOfSlavs.erase (setOfSlavs.begin());
			setOfSlavs.erase ( --setOfSlavs.end());
		}



	
	for( map < Slav * , Slav * >:: iterator it_map0fSlavs = mapOfSlavs.begin() ; it_map0fSlavs  != mapOfSlavs.end(); it_map0fSlavs++)

		{
			cout <<  it_map0fSlavs -> first -> description()<< " => " <<  it_map0fSlavs  -> second -> description() << endl;

		}


	REPORT_CONTAINERS;
}

void adapters(Slav * slavs, int n)
{
	queue <Slav *> queueOfSlavs;
	stack <Slav *> stackOfSlavs;

	printf("# Adapters\n");
	REPORT_ADAPTERS;
	printf("## queue\n");


	for(int i =0 ; i < n ; ++i)
	{
		queueOfSlavs.push(slavs +i);
	}
	// Umieść Słowian w kolejce.
	
	REPORT_ADAPTERS;

	printf("## stack\n");
	// Przenieś Słowian z kolejki do stosu.
	while(!queueOfSlavs.empty())
	{
		stackOfSlavs.push(queueOfSlavs.front());
		queueOfSlavs.pop();
	}
	REPORT_ADAPTERS;

	// Wyświetl Słowian zdejmowanych ze stosu.
	while(!stackOfSlavs.empty())
	{
		cout<<stackOfSlavs.top()->description()<<endl;
		stackOfSlavs.pop();
	}
	REPORT_ADAPTERS;
}

void showMeContainerSizes(vector <Slav *> vector, set <Slav *> set, map <Slav *, Slav*> map)
{
	printf("[vector_size = %lu, set_size = %lu, map_size = %lu, existingSlavs = %i]\n",
		vector.size(),
		set.size(),
		map.size(),
		Slav::counter());
}

void showMeAdapterSizes(queue <Slav *> queue, stack <Slav *> stack)
{
	printf("[queue_size = %lu, stack_size = %lu, existingSlavs = %i]\n",
		queue.size(),
		stack.size(),
		Slav::counter());

}
