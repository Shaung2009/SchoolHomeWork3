/*
* Transform a sentance enteredby user with all
* four-letter words into love, and the word starts
* by a capital letter, then it should be replaced
* Love. Ask the user to use again or not.
*/
#include<iostream>
#include<string>
#include<cctype>

using namespace std;

const int LETTER_SIZE = 4;

void enterSentance(string&);
void replaceByLove(string&);
void outputSentance(const string&);
void cleanBuffer();

int main() {
	string sentance;
	char choice = 'y';

	while (choice == 'y' || choice == 'Y') {
		enterSentance(sentance);	//input sentance
		replaceByLove(sentance);	//replace 4 letters with love
		outputSentance(sentance);	//output result

		// ask user if he/she wants to user again
		cout << "Would you like to transform another sentance?(y/n)\n>";
		cin >> choice;
		cleanBuffer();				// clean buffer('\n')
		if (!(choice == 'y' || choice == 'Y' || choice == 'n' || choice == 'N')) {
			cout << "No letter 'y' or 'n' detected!\n";
			exit(1);
		}	
	}
	return 0;
}
/* User enter a sentance. */
void enterSentance(string& sentance) {
	cout << "Enter sentance: ";
	getline(cin, sentance);
}
/* Replacing all four-letters words to love-Love. */
void replaceByLove(string& sentance) {
	int sizeIsFour = 0;
	int start = -1;

	//read the sentence
	for (int i = 0; i < sentance.length(); i++) {
		if (isalpha(sentance[i])) {
			if (sizeIsFour == 0) {
				start = i; //mark the start of potential "love"
			}
			sizeIsFour++;
		}
		else {
			sizeIsFour = 0; //reset if non-letter found
		}

		//if we got four letters, transform it to "love"
		if (sizeIsFour == 4) {
			sentance.replace(start, LETTER_SIZE, (('A' <= sentance[start] && sentance[start] <= 'Z') ? "Love" : "love"));
			sizeIsFour = 0; //reset sizeIsFour after replacement
		}
	}
}
/* Output the sentance has been transformed. */
void outputSentance(const string& sentance) {
	cout << "Sentance after replaced by \"love\"s\n> ";
	cout << sentance << endl;
}
/* Clean buffer after cin.*/
void cleanBuffer() {
	while (cin.get() != '\n') {
		// just read and ignore character
	}
}