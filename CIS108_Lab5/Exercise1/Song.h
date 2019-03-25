#include <iostream>
#include<stdlib.h>
#include<fstream>
using namespace std;
namespace song
{
	struct songDetail
	{
		char title[64];
		char artist[32];
		char album[64];
		int trackNumber;
		int releasedYear;
		enum  Genre {Blues, Country, Electronic, Folk, HipHop, Jazz, Latin, Pop, Rock} musicGenre;
	};

	void add();
	void list();
	void sort();
	void help();
	void save();
	int getTotalSong();
	int song::getTotalSong();
	void getsongInformation(int num);
	void displayMenu();
}

