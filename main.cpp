#include <fstream>
#include <list>
#include <iostream>
#include <string>
using namespace std;

// Declarations
void fillList(list<char> &thelist, string toadd);
void printlist(list<char> &thelist, ostream &out);
void removecharacter(list<char> &thelist, char toremove);
void reverselist(list<char> &thelist, ostream &out);
void isPalindrome(list<char> &thelist, ostream &out);

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	// String to store, vowels to remove, and list to keep it in
	string linein;
	string vowelsToRemove = "aeiouAEIOU";
	list<char> thelist;

	//file input loop
	while (true)
	{
		// Grab a line. Should we quit?
		getline(fin, linein);
		if (linein == "END")
			break;

		// Parse string to list
		fillList(thelist, linein);

		// Remove each char
		for (string::iterator it = vowelsToRemove.begin(); it != vowelsToRemove.end(); it++)
		{
			removecharacter(thelist, *it);
		}

		// Print it to file output
		printlist(thelist, fout);
		isPalindrome(thelist, fout);
		fout << endl;
		fout << "The reversed list is: ";
		fout << endl;
		reverselist(thelist, fout);
		fout << endl << endl;

		// Reset the list to start over
		thelist.clear();
	}


	fin.close();
	fout.close();
	return 0;
}


void fillList(list<char> &thelist, string toadd)
{
	int size = toadd.length();
	for (int i = 0; i < size; i++) {
		thelist.push_back(toadd[i]);
	}
}


void removecharacter(list<char> &theList, char toremove)
{
	theList.remove(toremove);
}


void printlist(list<char> &thelist, ostream &out)
{
	for (list<char>::iterator it = thelist.begin(); it != thelist.end(); it++)
	{
		out << "[" << *it << "] -> ";
	}
	out << "0 ";

}
void reverselist(list<char> &thelist, ostream &out) {
	list<char> templist;
	for (list<char>::iterator it = thelist.begin(); it != thelist.end(); it++) {
		if (it != thelist.end()) {
			templist.push_front(*it);
		}
	}
	for (list<char>::iterator it = templist.begin(); it != templist.end(); it++) {
		out << "[" << *it << "] -> ";
	}
	out << "0";
}
void isPalindrome(list<char> &thelist, ostream &out) {

	bool palindrome = true;
	
	list<char> templist;
	for (list<char>::iterator it = thelist.begin(); it != thelist.end(); it++) {
		if (it != thelist.end()) {
			templist.push_front(*it);
		}
	}
	
	int index1 = 0;
	int index2 = 0;


	for (list<char>::iterator it = thelist.begin(); it != thelist.end(); it++) {
		if (palindrome == false) {
			break;
		}
		for (list<char>::iterator iter = templist.begin(); iter != templist.end(); iter++) {
			if (index1 == index2) {
				if(it != thelist.end() && iter != templist.end()){
					if (tolower(*it) != tolower(*iter)) {
						palindrome = false;
						break;
					}
				}
			}
			index2++;
		}
		index2 = 0;
		index1++;
	}
	
	if (palindrome == false) {
		out << "Not a palindrome";
	}
	if (palindrome == true) {
		out << "Palindrome";
	}
