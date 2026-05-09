#include <iostream> 
#include <stdio.h>
#include <string.h>
#include <stack>

std::stack<int> numberStack;

void pushNumbersToStack (char);

int main (){
    std::string inputStringCalculation; 

    printf("Please provide me a String to calculate?\n");
    std::getline(std::cin,inputStringCalculation);
    
    for (int i=0; i <inputStringCalculation.length(); i++){
        pushNumbersToStack(inputStringCalculation[i]);
    }
    while (!numberStack.empty()) {
    std::cout << numberStack.top() << " ";
    numberStack.pop();
}

    return 0;
}

void pushNumbersToStack (char inputNumber){
    numberStack.push(inputNumber);

}