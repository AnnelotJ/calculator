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
std::queue<int> inputEnqueue;
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
int calculation(std::queue<int>);

int main (){
    std::string inputStringCalculation; 

    printf("Please provide me a String to calculate?\n");
    std::getline(std::cin,inputStringCalculation);
    std::cout<<"\n";
    
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

            pushNumbersToEnqueue(inputStringCalculation[i] - '0');
        }
    }
        while(!operatorStack.empty()){ 
            inputEnqueue.push(operatorStack.top()); 
            operatorStack.pop();
         }

    std::cout<<calculation(inputEnqueue) << "\n";


    return 0;
}

int calculation(std::queue<int> calculationEnqueue){

    int answer;
    std::stack<int>numStack; 

    while(!calculationEnqueue.empty()){ 
        if (calculationEnqueue.front()>= 0 && calculationEnqueue.front() <= 9){
            numStack.push(calculationEnqueue.front());
            calculationEnqueue.pop();
            
        }   
        else {     
            int secondNum = numStack.top() ; 
            numStack.pop(); 
            int firstNum = numStack.top() ; 
            numStack.pop(); 

            int calculationOperator = calculationEnqueue.front(); 
            calculationEnqueue.pop(); 

            int tmpAns;
                
                switch (calculationOperator){
                case 43:
                    tmpAns = firstNum + secondNum;
                    numStack.push(tmpAns);
                    break;
                case 45: 
                    tmpAns = firstNum - secondNum;
                    numStack.push(tmpAns);
                    break;
                case 42 :
                    tmpAns = firstNum * secondNum;
                    numStack.push(tmpAns);
                    break;
                case 47:
                    tmpAns = firstNum / secondNum;
                    numStack.push(tmpAns);
                    break;
            
                }

        }
    }
    answer = numStack.top(); 
    numStack.pop();
    return answer;

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
