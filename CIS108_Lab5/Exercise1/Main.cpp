#include<iostream>
#include<conio.h>
#include<string>
#include "Song.h"
using namespace std;

int main()
{
	string choice;
	bool sAdd = false;
	try
	{
		song::displayMenu();
		do
		{
			cout << ">";
			getline(cin, choice);
			//choice is add, call add function. Choice is save, call save function, choice is list call list function
			if (choice == "add")
			{
				int totalsong = song::getTotalSong();
				if (totalsong == 8) {
					cout << "No more space in the database" << endl;
					//throw;
				}
				else {
					song::add();
					sAdd = true;
				}
				continue;
				//call add function
			}
			else if (choice == "list")
			{
				song::list();
				continue;
				// list the song by calling list function
			}
			else if (choice == "sort")
			{
				song::sort();
				continue;
				// sort the song by calling sort function
			}
			else if (choice == "save")
			{
				if (sAdd) {
					song::save();
					cout << "The song has been saved" << endl;
					sAdd = false;
				}
				else {
					//Song is not added yet, give error message
					cout << "Please add a song first" << endl;
				}
				continue;
				// save the user input to the file by calling Save function
			}
			else if (choice == "total")
			{
				int totalsong = song::getTotalSong();
				if (totalsong == 0) {
					cout << "There are no songs in the database" << endl;
				} 
				else if (totalsong == 1) {
					cout << "There are " << totalsong << " song in the database" << endl;
				} else {
				cout << "There are " << totalsong << " songs in the database" << endl;
				}
				continue;
				// save the user input to the file by calling Save function
			}
			else if (choice == "info")
			{
				string songnum = "";
				cout << "Enter the song number:";
				getline(cin, songnum);
				song::getsongInformation(std::stoi(songnum));
				continue;
				// save the user input to the file by calling Save function
			}
			else if (choice == "help")
			{
				song::help();
				continue;
				// get help by calling help function
			}
			else if(choice!= "exit") {
				//For exit, we don't want to show this message
				cout << "Invalid input.Please select a valid choice" << endl;
				continue;
			}
		} while (choice != "exit");
	} catch (...)
	{
		cout << "Ran out of room in the file(up to 8 songs)" << endl;
	}
	
	return 0;

}
