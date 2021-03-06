// FindDupChars.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

/*

is based on the program that I saw the day before in a mock google interview. code given is as follows.

bool HasPairWithSum(const vector<int> data, int sum){

	unordered_set<int> comp; //complements
	for (int value:data){
		if(comp.find(value)!=comp.end)
			return true;
		comp.add(sum-value); //he was wrong here, it's suppose to be "insert"
	}
	return false:

}


What follows is what I initially thought to do.

*/


bool foundNoDupChars(string targetString) { //returns true if no dups are found, as the name suggests. If a dup is found, returns false.

	if (targetString.length() > 26) //check to see if there are too many letters, making it impossible for there not to be a repeating value
		return false;
	
	if (targetString.length() == 0) //check to see if an empty string, if empty return true
		return true;

	unordered_set<int> comp;
	for (int i = 0; i < targetString.length(); i++) { //test each char in the string one by one

		/*
		so this next bit is complcated. I'm sure you can read though it, but I'll comment on it to prove I know what it does.
		first we have targetString.at(i) gets the char in the string we're currently looking at.
		Putting an (int) on the front casts it into an int, partucallry the int value of that letter in ascii

		we take that value, and see if its already in the unordered_set. If it is, comp.find() will return something other than comp.end()
		*/

		if (comp.find((int)targetString.at(i)) != comp.end()) { 
			return false;
		}
		comp.insert((int)targetString.at(i)); //if we didn't find this value in the unordered_set, we add it to the unordered set.

	} //if we make it though without hitting a return to this point, then no dups where found
	return true;


}

void printResults(string targetString) { //instead of rewriting this code over and over in the main, I made it a function I can call over and over.

	cout << "We find that the string '" + targetString + "' "; //list the string we're testing so the user can see for themselves if the string has repeating chars
	if (foundNoDupChars(targetString)) { //test the string
		cout << " has no repeating chars: returned true!\n"; //let the user a postive result was found

	}
	else {
		cout << " does have repeating chars: returned false!\n"; //let the user know a negitive result was found

	}
}

int main()
{
    //std::cout << "Hello World!\n"; 

	string testString_01 = "cat"; //a simple test that should return true
	string testString_02 = ""; //tests an empty string edge case
	string testString_03 = "abcdefghijklmnopqrstuvwxyz"; //tests the entrie alphabit, tests one side of high end edge case...
	string testString_04 = "abcdefghijklmnopqrstuvwxyzzzz"; //... and this is the entire aplhabit with some more letters testing the other side of the high end edge case
	string testString_05 = "door"; //a simple test that should return false

	printResults(testString_01);
	printResults(testString_02);
	printResults(testString_03);
	printResults(testString_04);
	printResults(testString_05);

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
