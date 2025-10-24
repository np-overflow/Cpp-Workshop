#include <iostream>

void printStuff(int x, int y) {
    for (int countRow = 0; countRow < y; ++countRow) { //to run the loop for each row until all rows done
        for (int countCol = 0; countCol < x; ++countCol) { //to run the loop for each * until all in a row done
            std::cout << "*";
        }
        std::cout << std::endl;   // flush each row
    }
}

int main() {
    int width, height;
    std::cout << "Enter width and height with a space in between: " << std::endl;
    std::cin >> width >> height;
    printStuff(width, height);
    return 0;
}

