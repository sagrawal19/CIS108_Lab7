#include "Song.h"
#include<fstream>
#include<string>
#include <sstream>
#include <vector> 
#include <map>
#include <algorithm>

//create an instance or object of structure
song::songDetail s;  
string FileName = "SongDatabase.txt";
string sArrGenre[] = { "Blues",
		"Country",
		"Electronic",
		"Folk",
		"HipHop",
		"Jazz",
		"Latin",
		"Pop",
		"Rock"};

// Function to Display the Menu
void song::displayMenu() 
{
	cout << " add : Add a new song to the music database\n save : Save the music database \n list : List the songs in the music database \n total: Display Total number of songs \n info: Get song Information for given song number \n help : Display this menu  \n exit : Exit the program  \n sort : Sort the songs "<< endl;
}

//function to sort the songs in the database based on Title
bool sortSongsTitle(const song::songDetail& x, const song::songDetail& y)
{
	string s1 = x.title;
	string s2 = y.title;
	return s1.compare(s2) < 0;
}

//function to sort the songs in the database on Artist
bool sortSongsArtist(const song::songDetail& x, const song::songDetail& y)
{
	string s1 = x.artist;
	string s2 = y.artist;
	return s1.compare(s2) < 0;
}

//function to sort the songs in the database on Released Year
bool sortSongsYear(const song::songDetail& x, const song::songDetail& y)
{ 
	return x.releasedYear < y.releasedYear; 	
}

void openInputFile(ifstream &inFile, string inFileName)
{
	//Open the file
	inFile.open(inFileName);

	//Input validation
	if (!inFile)
	{
		//cout << "Error to open file." << endl;
		//cout << endl;
		return;
	}
}

//This method get the genre from enum based on input string value
song::songDetail::Genre getGenreFromString(const std::string sGenre) {
	std::map< std::string, song::songDetail::Genre > mpGenre;
	mpGenre["Blues"] = s.Blues;
	mpGenre["Country"] = s.Country;
	mpGenre["Electronic"] = s.Electronic;
	mpGenre["Folk"] = s.Folk;
	mpGenre["HipHop"] = s.HipHop;
	mpGenre["Jazz"] = s.Jazz;
	mpGenre["Latin"] = s.Latin;
	mpGenre["Pop"] = s.Pop;
	mpGenre["Rock"] = s.Rock;

	auto x = mpGenre.find(sGenre);
	//if (x != std::end(mpGenre)) {
		return x->second;
	//}
	//throw std::invalid_argument(sGenre);
}

//Function to add the song
void song::add()
{
	string sTrackNumber = "";
	string sReleasedYear = "";
	string sGenre = "";
	//Take input from user 
	cout << "Enter the song title: ";
	cin.getline(s.title, 64);
	cout << "Enter artist: ";
	cin.getline(s.artist, 32);
	cout << "Enter album name: ";
	cin.getline(s.album, 64);
	cout << "Enter track#: ";
	getline(cin,sTrackNumber);
	s.trackNumber = std::stoi(sTrackNumber);
	cout << "Enter year: ";
	getline(cin, sReleasedYear);
	s.releasedYear = std::stoi(sReleasedYear);
	bool cGenre = true;
	do {
		cout << "Enter genre (Blues, Country, Electronic, Folk, HipHop, Jazz, Latin, Pop, Rock):";
		getline(cin, sGenre);
		cGenre = std::find(std::begin(sArrGenre), std::end(sArrGenre), sGenre) != std::end(sArrGenre);
		if (!cGenre) {
			cout << "Wrong Genre input. Please try again" << endl;
		}
	} while (!cGenre);
	//s.musicGenre = (song::songDetail::Genre)Enum.Parse(typeof(song::songDetail::Genre), sGenre,true);
	//s.musicGenre = s.Rock;
	s.musicGenre = getGenreFromString(sGenre);
	
}


// Function to List the number of song
void song::list()
{
	//song::songDetail arr[8];
	//Vector to contain all the songs that needs to be written to the file
	vector<song::songDetail> vSong;
	//A temp structure to hold the data when read from file
	song::songDetail tempSong;
	string sGenre = "";
	
	// Read data in file
	ifstream inFile;
	openInputFile(inFile, FileName);
	int count = 0;
	string line;
	string data;
	while (std::getline(inFile, line)) 
	{
		std::istringstream iss(line); // read one by one line
		//Adding song to the vector
		iss >> tempSong.title >> tempSong.artist >> tempSong.album >> tempSong.trackNumber >> tempSong.releasedYear >> sGenre;
		tempSong.musicGenre = static_cast<song::songDetail::Genre>(std::stoi(sGenre));
		vSong.push_back(tempSong);
		count++;
	}
	// Close input file
	inFile.close();
	cout << "There are "<< count <<" songs in the database" << endl;
	for (int i = 0; i < count ; i++)
	{
		cout << "Song #" << (i+1) <<": " << endl;
		cout << "   " << "Title:" << vSong[i].title << endl;
		cout << "   " << "Artist:" << vSong[i].artist << endl;
		cout << "   " << "Album:" << vSong[i].album << endl;
		cout << "   " << "Track#:" << vSong[i].trackNumber << endl;
		cout << "   " << "Year:" << vSong[i].releasedYear << endl;		
		//cout << "   " << "Genre:" << static_cast<song::songDetail::Genre>(vSong[i].musicGenre) << endl;
		cout << "   " << "Genre:" << sArrGenre[vSong[i].musicGenre] << endl;
		cout << endl;
	}
}

//function to sort the songs in the databse using user preference
void song::sort()
{
	int iPref;
	string sPref;
	cout << "Please select your preference by entering the number from below options" << endl;
	cout << " 1.Sort by song title \n 2.Sort by artist  \n 3.Sort by release year "<< endl;
	getline(cin, sPref);
	iPref = std::stoi(sPref);
	
	//Vector to contain all the songs that needs to be written to the file
	vector<song::songDetail> vSong;
	//A temp structure to hold the data when read from file
	song::songDetail tempSong;
	string sGenre = "";

	// Read data in file
	ifstream inFile;
	openInputFile(inFile, FileName);
	int count = 0;
	string line;
	string data;
	while (std::getline(inFile, line))
	{
		std::istringstream iss(line); // read one by one line
		//Adding song to the vector
		iss >> tempSong.title >> tempSong.artist >> tempSong.album >> tempSong.trackNumber >> tempSong.releasedYear >> sGenre;
		tempSong.musicGenre = static_cast<song::songDetail::Genre>(std::stoi(sGenre));
		vSong.push_back(tempSong);
		count++;
	}
	// Close input file
	inFile.close();
	cout << "There are " << count << " songs in the database" << endl;

	//sort the result in the vector based on user preferance
	if (iPref == 1)
		std::sort(vSong.begin(), vSong.end(), sortSongsTitle);
	else if (iPref == 2)
		std::sort(vSong.begin(), vSong.end(), sortSongsArtist);
	else if (iPref == 3)
		std::sort(vSong.begin(), vSong.end(), sortSongsYear);

	for (int i = 0; i < count; i++)
	{
		cout << "Song #" << (i + 1) << ": " << endl;
		cout << "   " << "Title:" << vSong[i].title << endl;
		cout << "   " << "Artist:" << vSong[i].artist << endl;
		cout << "   " << "Album:" << vSong[i].album << endl;
		cout << "   " << "Track#:" << vSong[i].trackNumber << endl;
		cout << "   " << "Year:" << vSong[i].releasedYear << endl;
		//cout << "   " << "Genre:" << static_cast<song::songDetail::Genre>(vSong[i].musicGenre) << endl;
		cout << "   " << "Genre:" << sArrGenre[vSong[i].musicGenre] << endl;
		cout << endl;
	}
	
}

//Function to Save the Song
void song::save()
{
	//Vector to contain all the songs that needs to be written to the file
	vector<song::songDetail> vSong;
	//A temp structure to hold the data when read from file
	song::songDetail tempSong;
	string sGenre = "";

	ifstream inFile;

	// Call function to read data in file
	openInputFile(inFile, FileName);
	int count = 0;
	string line;
	string data;
	while (std::getline(inFile, line))
	{
		std::istringstream iss(line);
		//Adding song to the vector
		iss >> tempSong.title >> tempSong.artist >> tempSong.album >> tempSong.trackNumber >> tempSong.releasedYear >> sGenre;
		tempSong.musicGenre = static_cast<song::songDetail::Genre>(std::stoi(sGenre));
		
		vSong.push_back(tempSong);
		count++;
	}
	
	// Close input file
	inFile.close();

	//Add the new song to the end of vector
	vSong.push_back(s);
	count++;

	//Finally write the content of vector to the file
	ofstream myFile;
	myFile.open(FileName);
	
	if (myFile.is_open())
	{
		for (int i = 0; i < vSong.size();i++)
		{
			myFile << vSong[i].title << " ";
			myFile << vSong[i].artist << " ";
			myFile << vSong[i].album << " ";
			myFile << vSong[i].trackNumber << "  ";
			myFile << vSong[i].releasedYear << "  ";
			myFile << vSong[i].musicGenre;
			myFile << "\n";
		}
			myFile.close();
	}	
}

// Function to Get Help 

void song::help()
{
	displayMenu();
}

//Function to Get the Total Number of Song

int song::getTotalSong()
{
	ifstream inFile;
	// Call function to read data in file
	openInputFile(inFile, FileName);
	int count = 0;
	string line;

	//Read the data and increment the count to get the total songs
	while (std::getline(inFile, line))
	{
		count++;
	}
	// Close input file
	inFile.close();
	return count;
}


// Function to Get the information about song

void song::getsongInformation(int songNum)
{
	song::songDetail arrInfo[1];
	string sGenre;
	ifstream inFile;
	// Call function to read data in file
	openInputFile(inFile, FileName);
	int count = 0;
	string line;

	//Read the data and increment the count to get the total songs
	while (std::getline(inFile, line))
	{
		count++;
		if (songNum == count) {
			std::istringstream iss(line);
			iss >> arrInfo[0].title >> arrInfo[0].artist >> arrInfo[0].album >> arrInfo[0].trackNumber >> arrInfo[0].releasedYear >> sGenre;
			
			cout << "Song #" << count << ": " << endl;
			cout << "   " << "Title:" << arrInfo[0].title << endl;
			cout << "   " << "Artist:" << arrInfo[0].artist << endl;
			cout << "   " << "Album:" << arrInfo[0].album << endl;
			cout << "   " << "Track#:" << arrInfo[0].trackNumber << endl;
			cout << "   " << "Year:" << arrInfo[0].releasedYear << endl;
			cout << "   " << "Genre:" << sArrGenre[std::stoi(sGenre)] << endl;
			cout << endl;
			break;
		}

	}
	// Close input file
	inFile.close();
}