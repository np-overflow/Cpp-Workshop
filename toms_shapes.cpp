/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

void printStuff(int x, int y) {
	for (int count = {1}; count <= y; ++count) {
		for (int i = 0; i <= x; ++i) {
			std::cout << "*";
		}
		std::cout << "\n";
	}

}


int main()
{
	int width, height;
	std::cout << "Enter width and height with a space in between: ";
	std::cin >> width >> height;
	printStuff(width, height);
    return 0;
}