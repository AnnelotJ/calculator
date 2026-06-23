#include <iostream> 
#include <stdio.h>
#include <string.h>
#include <stack>
#include <queue>
#include <unordered_map>    
#include <string>


// Stack is where all the operators are stored 
// queue is where all the numbers are stored

std::stack<char> operatorStack;
std::queue<char> inputEnqueue;
std::unordered_map<char, int> operatorValuesMap =
    {
        {'*', 2},
        {'+', 1},
        {'-', 1},
        {'/', 2}
    };


void pushOperatorsToStack (char);
void pushNumbersToEnqueue (int); 
bool isHighPrecedence(char, char);
int calculation(std::queue<char>);

int main (){
    std::string inputStringCalculation; 

    printf("Please provide me a String to calculate?\n");
    std::getline(std::cin,inputStringCalculation);
    
    for (int i=0; i <inputStringCalculation.length(); i++){       
        if (inputStringCalculation[i] == '+' || inputStringCalculation[i] == '-' || inputStringCalculation[i] == '/' || inputStringCalculation[i] == '*' ){ 
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
                else if( operatorStack.top() == '-'){
                        if(isHighPrecedence(operatorStack.top(), inputStringCalculation[i]) == true){
                            inputEnqueue.push(operatorStack.top());
                            operatorStack.pop(); 
                            operatorStack.push(inputStringCalculation[i]);                     
                        }
                        else{
                            operatorStack.push(inputStringCalculation[i]);
                        }
                    } 
                else if( operatorStack.top() == '*'){
                        if (isHighPrecedence(operatorStack.top(), inputStringCalculation[i]) == true ){
                            inputEnqueue.push(operatorStack.top()); 
                            operatorStack.pop();
                            operatorStack.push(inputStringCalculation[i]);
                        }
                        else{
                            operatorStack.push(inputStringCalculation[i]);
                        }
                    } 
                else if( operatorStack.top() == '/'){
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

        else  {
            pushNumbersToEnqueue(inputStringCalculation[i]);
        }
    }
    // The last item must be added aswell
        while(!operatorStack.empty()){ 
            inputEnqueue.push(operatorStack.top()); 
            operatorStack.pop();
         }

    calculation(inputEnqueue);

    return 0;
}

int calculation(std::queue<char> calculationEnqueue){
    int answer; 

    std::queue<char> copy = calculationEnqueue;
       while (!copy.empty()) {
           std::cout << copy.front() << " ";
           copy.pop();
       }

    return 4;

}


bool isHighPrecedence (char operatorFromStack,char currentOperator){
    if ( operatorValuesMap[operatorFromStack] > operatorValuesMap[currentOperator]){
        return true;
    }
    else {
        return false;
    }
}

void pushOperatorsToStack (char inputOperators){
    operatorStack.push(inputOperators);

}

void pushNumbersToEnqueue (int inputNumber){
    inputEnqueue.push(inputNumber);
}
