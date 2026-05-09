#include <iostream> 
#include <stdio.h>
#include <string.h>
#include <stack>
#include <queue>
#include <unordered_map>


std::stack<char> operatorStack;
std::queue<int> inputEnqueue;
std::unordered_map<char, int> operatorValuesMap =
    {
        {'*', 42},
        {'+', 43},
        {'-', 45},
        {'/', 47}
    };


void pushOperatorsToStack (char);
void pushNumbersToEnqueue (char); 
bool isHighPrecedence(char, char);

int main (){
    std::string inputStringCalculation; 

    printf("Please provide me a String to calculate?\n");
    std::getline(std::cin,inputStringCalculation);
    
    for (int i=0; i <inputStringCalculation.length(); i++){

        if (inputStringCalculation[i] == '+' || inputStringCalculation[i] == '-' || inputStringCalculation[i] == '/' || inputStringCalculation[i] == '*' ){
            // Look at what the current stack is. 
            if (operatorStack.size() == 0){
                operatorStack.push(inputStringCalculation[i]);
            }
            else {
                if( operatorStack.top() == '+'){
                    if (isHighPrecedence(operatorStack.top(), inputStringCalculation[i]) == true){
                        inputEnqueue.push(operatorStack.top()); 
                        operatorStack.pop();
                        operatorStack.push(inputStringCalculation[i]);
                    }
                    else {
                        operatorStack.push(inputStringCalculation[i]);
                    }
                } 
                if( operatorStack.top() == '-'){
                    std::cout << "hello I <3 you";
                    if(isHighPrecedence(operatorStack.top(), inputStringCalculation[i]) == true){
                         std::cout << "\n";
                        std::cout << operatorStack.top();
                        inputEnqueue.push(operatorStack.top());
                        operatorStack.pop(); 
                         std::cout << "\n";
                        std::cout << inputStringCalculation;
                        operatorStack.push(inputStringCalculation[i]);
                        std::cout << operatorStack.top(); 
                        std::cout << "\n";
                        
                    }
                    else{
                        operatorStack.push(inputStringCalculation[i]);
                    }

                } 
                if( operatorStack.top() == '*'){
                    if (isHighPrecedence(operatorStack.top(), inputStringCalculation[i]) == true ){
                        inputEnqueue.push(operatorStack.top()); 
                        operatorStack.pop();
                        operatorStack.push(inputStringCalculation[i]);
                    }
                    else{
                        operatorStack.push(inputStringCalculation[i]);
                    }

                } 
                if( operatorStack.top() == '/'){
                    if (isHighPrecedence(operatorStack.top(), inputStringCalculation[i]) == true ){ 
                        inputEnqueue.push(operatorStack.top()); 
                        operatorStack.pop();
                        operatorStack.push(inputStringCalculation[i]);
                    }
                    else {
                        operatorStack.push(inputStringCalculation[i]);
                    }
                } 
            }
        }
        pushNumbersToEnqueue(i);
    }
            std::queue<int> copy = inputEnqueue;
            while (!copy.empty()) {
                std::cout << copy.front() << " ";
                copy.pop();
            }
            std::cout << "\n";
            

    return 0;
}


bool isHighPrecedence (char operatorFromStack,char currentOperator){

    if ( operatorValuesMap[operatorFromStack] > operatorValuesMap[currentOperator]){
        // Stack is higher than current 
        return true;
    }
    else {
        return false;
    }

}

void pushOperatorsToStack (char inputOperators){
    operatorStack.push(inputOperators);

}

void pushNumbersToEnqueue (char inputNumber){
    inputEnqueue.push(inputNumber);
}
