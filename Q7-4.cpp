#include<iostream>
using namespace std;

class HotDogStand {
public:
	HotDogStand(int id, int sold);
	void JustSold();
	void AlreadySold();
	int getHotDogSold() const;
	static int getTotalHotDogSold();
	void outputStandInfo() const;
	void outputStandSold() const;
private:
	int standId;
	int hotDogSold;
	static int totalHotDogSold;
};

int HotDogStand::totalHotDogSold = 0;	//initialize static variable outside the class

//system("PAUSE");
int main() {
	HotDogStand stand1 = HotDogStand(1, 10);
	HotDogStand stand2 = HotDogStand(2, 20);
	HotDogStand stand3 = HotDogStand(3, 30);
	
	stand1.outputStandInfo();
	stand1.JustSold();
	stand1.outputStandSold();

	stand2.outputStandInfo();
	stand2.JustSold();
	stand2.JustSold();
	stand2.outputStandSold();

	stand3.outputStandInfo();
	stand3.JustSold();
	stand3.JustSold();
	stand3.JustSold();
	stand3.outputStandSold();

	cout << "Total Hot Dogs sold by all stands: " << HotDogStand::getTotalHotDogSold() << endl;

	return 0;
}

/* Constructor(only need one by the question). */
//AleadySold() make hot dog sold before calculate could be add to totalSold.
HotDogStand::HotDogStand(int id, int sold) :standId(id), hotDogSold(sold) { AlreadySold(); }

/* Each time sold hot dog, increase the stand sold and total stand sold. */
void HotDogStand::JustSold() {
	cout << "SOLD\n";
	hotDogSold++;
	totalHotDogSold++;
}
/* Hotdogs already been sold added to total sold by all stands. */
void HotDogStand::AlreadySold() {
	totalHotDogSold += hotDogSold;
}
/* Get hot dog sold by the stand. */
int HotDogStand::getHotDogSold() const {
	return hotDogSold;
}
/* Get total hot dog sold by all stands. */
int HotDogStand::getTotalHotDogSold() {
	return totalHotDogSold;
}
/* Output Id and hot dogs which have been sold already. */
void HotDogStand::outputStandInfo() const {
	cout << "Stand id: " << standId << "\nStand sold: " << hotDogSold << endl;
}
/* Output total hot dog sold by one stand. */
void HotDogStand::outputStandSold() const {
	cout << "Hot Dogs sold by Stand"  << standId << ": " << hotDogSold << endl << endl;
}