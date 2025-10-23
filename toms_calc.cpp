/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

void calcUI() {
    std::cout << "Hello! Please select an option."<<"\n";
    std::cout << "1. Plus"<<"\n";
    std::cout << "2. Minus"<<"\n";
    std::cout << "3. Multiply"<<"\n";
    std::cout << "4. Divide"<<"\n";
}

int calcFuncs(int option, int num1, int num2) {
    switch(option) {
        case 1:
            std::cout << "The sum of " << num1 << " and " << num2 << " is " << num1 + num2;
            break;
        case 2:
            std::cout << "The result of " << num1 << " minus " << num2 << " is " << num1 - num2;
            break;
        case 3:
            std::cout << "The result of " << num1 << " times " << num2 << " is " << num1 * num2;
            break;
        case 4:
            std::cout << "The result of " << num1 << " divided by " << num2 << " is " << num1 / num2;
            break;
    }
    return 0;
}

int main()
{
	while (true){
	    int option {5};
	    calcUI();
	    std::cout << "Enter the option you would like to choose: ";
	    std::cin >> option;
	    if (1 <= option && option <= 4){
	        int num1, num2;
	        std::cout << "Enter the two numbers you want to use in your calculations with a space in between: ";
	        std::cin >> num1 >> num2;
	        calcFuncs(option, num1, num2);
	        break;
	    }
	    else{
	        std::cout << "Invalid option.\n";
	    }
	
    }
    return 0;
}