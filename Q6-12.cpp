/* Testing for class BoxOfProduce. */
#include<iostream>
#include<cstdlib>
#include<string>
#include<fstream>
#include<time.h>
using namespace std;

class BoxOfProduce {
public:
	void setProduct(string productName, const int& numberProduct);
	string getProduct(int numberProduct) const;

	void displayProduct() const;
private:
	string product[3];			// Inside is product which will be send to user.
};

class ListOfProduce {
public:
	void setProduct(string productName, const int& numberProduct);
	string getProduct(int numberProduct) const;

	void displayProduct() const;
private:
	string product[5];
};

void selectRandomItems(const ListOfProduce&, BoxOfProduce&);
int generateRandomNumbers(const int& max, const int& min);

int main() {
	ifstream inputFile("inputData.txt");
	if (!inputFile.is_open()) {				//Incase the file open is failed.
		cout << "File open is failed!\n";
		exit(1);
	}

	srand(time(0));								//set random seed

	BoxOfProduce userProductList;
	ListOfProduce productList;
	string product;
	int i = 0;

	cout << "Product list(all):\n";
	while (getline(inputFile, product, '\n')) {
		productList.setProduct(product, i);
		i++;
	}
	cout << endl;

	productList.displayProduct();
	selectRandomItems(productList, userProductList);

	/*Exchanging content inside the box. */
	char choice;
	while(1) {
		int numList, numBox;
		userProductList.displayProduct();
		cout << "Would you like to exchange the content in your box(y(yes), n(no))?\n";
		cin >> choice;
		if (choice == 'n') {	// break the loop as user do not want to do change. 
			break;
		}
		else if (choice != 'y') {
			cerr << "Enter format wrong!\n";
			exit(1);
		}
		cout << "Enter number of box and number of product\n> ";
		cin >> numBox >> numList;
		if (0 > numBox || numBox > 2 || 0 > numList || numList > 4) {
			cerr << "Enter format wrong!\n";
			exit(1);
		}
		userProductList.setProduct(productList.getProduct(numList), numBox);	//Changing content in the box
	} 

	return 0;
}

/*Constructor for box*/
void BoxOfProduce::setProduct(string productName, const int& numberProduct) { product[numberProduct] = productName; }
/* Get content of box by the given number of box. */
string BoxOfProduce::getProduct(int numberProduct) const { return product[numberProduct]; }
/* show content of box. */
void BoxOfProduce::displayProduct() const {
	for (int i = 0; i < 3; i++) {
		cout << "Box" << i << ": " << product[i] << endl;
	}
}

/*Constructor for list*/
void ListOfProduce::setProduct(string productName, const int& numberProduct) { product[numberProduct] = productName; }
/* Get content of list by the given number of list. */
string ListOfProduce::getProduct(int numberProduct) const { return product[numberProduct]; }
/* show list of fruit or vegetable. */
void ListOfProduce::displayProduct()const {
	for (int i = 0; i < 5; i++) {
		cout << "List" << i << ": " << product[i] << endl;
	}
}

/* Select three items from the list to the box randomly. */
void selectRandomItems(const ListOfProduce& list, BoxOfProduce& box) {
	for (int i = 0; i < 3; i++) {
		box.setProduct(list.getProduct(generateRandomNumbers(4, 0)), i);
	}
}
/* Generate random numbers between the given max and min numbers. */
int generateRandomNumbers(const int& max, const int& min) {
	return rand() % (max - min + 1) + min;
}