/* Simulate POSTNET , let user enter number and digits to decode and encode. */
#include<iostream>
#include<math.h>
#include<string>
using namespace std;

const int TOTAL_DIGIT = 25;     //25 digits
const int GROUP_OF_FIVE = 5;    //five groups

class ZipCode {
public:
    // Input zipcode as 5-numbers or 25-digits(0's, 1's) string
    ZipCode(int);
    ZipCode(string);

    int outputAsNumber() const;    // encode => string -> numbers
    string outputAsString() const;    // decode => numbers -> string
private:
    int zipCodeInNumbers;
    string zipCodeInString;

    int value[GROUP_OF_FIVE] = { 7, 4, 2, 1, 0 };
    string decoder(int&) const;
};

int main() {
    int number;
    string digits;

    cout << "Decoder, enter five digit number\n> ";
    cin >> number;
    ZipCode testForNumber = ZipCode(number);
    cout << "Number after decoding:\n> " << testForNumber.outputAsString() << endl << endl;

    cout << "Encoder, enter 25 digits number consist of 1's 0's\n> ";
    cin >> digits;
    ZipCode testForString = ZipCode(digits);
    cout << "String after encoding:\n> " << testForString.outputAsNumber() << endl;

    return 0;
}

//Constructors
ZipCode::ZipCode(int number) : zipCodeInNumbers(number) {}
ZipCode::ZipCode(string digits) : zipCodeInString(digits) {}

/* Transform zip code entered as string to number. */
int ZipCode::outputAsNumber() const {
    int decode = 0, toAdd = 0;

    for (int i = 0, k = 1; i < TOTAL_DIGIT; i += 5, k++) {
        for (int j = 0; j < GROUP_OF_FIVE; j++) {
            if (zipCodeInString[i + j] == '1') {
                toAdd += value[j];
            }
            if (toAdd == 11) {
                toAdd = 0;
            }
        }
        decode += toAdd * pow(10, GROUP_OF_FIVE - k);
        toAdd = 0;
    }
    return decode;
}

/* Transform zip code entered as number to string. */
string ZipCode::outputAsString() const {
    string result;
    int digits[GROUP_OF_FIVE];
    int temp = zipCodeInNumbers;

    //saperate the number into five numbers, storing them in digits[]
    for (int i = GROUP_OF_FIVE - 1; i >= 0; i--) {
        digits[i] = temp % 10;
        temp /= 10;
    }

    //concatenate the string
    for (int i = 0; i < GROUP_OF_FIVE; i++) {
        result += decoder(digits[i]);
    }
    return result;
}

/* Corresponding five digits group to the number. */
string ZipCode::decoder(int& digit) const {
    // POSTNET zip code rule
    const string encoding[10] = {
        "11000", // 0
        "00011", // 1
        "00101", // 2
        "00110", // 3
        "01001", // 4
        "01010", // 5
        "01100", // 6
        "10001", // 7
        "10010", // 8
        "10100"  // 9
    };

    return encoding[digit];
}
