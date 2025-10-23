#include <iostream>
using namespace std;

bool isOdd(int num) {
    return num % 2 != 0;
}

int sumOfDigits(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

void printReaction(string word, int times) {
    for (int i = 0; i < times; i++) {
        cout << word;
        if (i < times - 1) {
            cout << " ";
        }
    }
    cout << endl;
}

bool tomHatesNumber(int num) {
    switch (num) {
        case 67:
        case 41:
            return true;
        default:
            return isOdd(num);
    }
}

int main() {
    int number;
    
    cout << "Enter a number: ";
    cin >> number;
    
    int digitSum = sumOfDigits(number);
    
    if (tomHatesNumber(number)) {
        printReaction("yuck", digitSum);
    } else {
        printReaction("yay", digitSum);
    }
    
    return 0;
}