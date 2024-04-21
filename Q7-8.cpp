/* Generate a histogram by some input student grades. */
#include<iostream>
#include<string>
#include<algorithm>	// to use max_element()
#include<vector>	// to use vectors
using namespace std;

int main() {
	vector<int> studentGrades;
	int grade, highestGrade;

	cout << "Enter all student's grade(minimun is 0), stops by enter -1.\n> ";
	cin >> grade;
	while (grade != -1) {				//stops as the enter value is -1
		if (grade < 0) {
			cerr << "Please enter grades greater than or equal to 0!\n";
			exit(1);
		}
		studentGrades.push_back(grade);
		cin >> grade;
	}
	highestGrade = *max_element(studentGrades.begin(), studentGrades.end());

	/* Generate histogram. */
	int i, j;
	int numElements = studentGrades.size();	//find the numbers of element in studentGrades
	for (i = highestGrade; i >= 0; i--) {
		cout.width(2);
		cout << i << " | ";
		//Generate x & ' '
		for (j = 0; j < numElements; j++) {
			cout.width(2);
			if (studentGrades[j] >= i) {
				cout << 'X';
			}
			else {
				cout << " ";
			}
		}
		cout << endl;
	}
	//generate remaind parts
	cout << "--------------------------------------" << endl;
	cout << "     ";
	for (i = 0; i < numElements; i++) {
		cout.width(2);
		cout << studentGrades[i];
	}

	return 0;
}