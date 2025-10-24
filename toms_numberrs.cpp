#include <iostream>
#include <string>

bool isOdd(int num) {
    return num % 2 != 0;
}

int sumOfDigits(int num) { //sum the digits by taking the last digit every iteration and add to sum
    int sum = 0;
    while (num > 0) {
        sum += num % 10; //get the last digit
        num /= 10; //remove the last digit
    }
    return sum;
}

void printReaction(const std::string word, int times) {
    for (int i = 0; i < times; i++) {
        std::cout << word;
        if (i < times - 1) { //print space every time after a word until it's the last word
            std::cout << " "; 
        }
    }
    std::cout << std::endl;
}

bool tomHatesNumber(int num) { //to check for 67 and 41
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
    
    std::cout << "Enter a number: ";
    std::cin >> number;
    
    int digitSum = sumOfDigits(number);
    
    if (tomHatesNumber(number)) {
        printReaction("yuck", digitSum);
    } else {
        printReaction("yay", digitSum);
    }
    
    return 0;

}
