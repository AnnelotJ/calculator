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

int main (){
    std::string inputStringCalculation; 

    printf("Please provide me a String to calculate?\n");
    std::getline(std::cin,inputStringCalculation);
    
    for (int i=0; i <inputStringCalculation.length(); i++){
        
        if (inputStringCalculation[i] == '+' || inputStringCalculation[i] == '-' || inputStringCalculation[i] == '/' || inputStringCalculation[i] == '*' ){
            
            if (operatorStack.size() == 0){
                operatorStack.push(inputStringCalculation[i]);
            }
            else if (operatorStack.size()>0){
                std::cout<<"2345678";
                if( operatorStack.top() == '+'){
                        if (isHighPrecedence(operatorStack.top(), inputStringCalculation[i]) == true){
                            std::cout<<"dbsfjhsfjbs";
                            inputEnqueue.push(operatorStack.top()); 
                            operatorStack.pop();
                            operatorStack.push(inputStringCalculation[i]);
                        }
                        else {
                            operatorStack.push(inputStringCalculation[i]);
                        }
                    } 
                else if( operatorStack.top() == '-'){
                    std::cout<<"swh3194bsdf";
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
                
                    // I want to see what the current stack is and how it is organised
                    // std::cout<<"the stack is as follows:\n";
                    // std::stack<char> copeOperatorStack = operatorStack; 
                    // while (!copeOperatorStack.empty()){
                    //     std::cout<< copeOperatorStack.top() << "\n"; 
                    //     copeOperatorStack.pop();
                    // }
                    // std::cout<<"'\n";
            }
        }
        else if (inputStringCalculation[i] >= '0' && inputStringCalculation[i]<='9'){
            pushNumbersToEnqueue(inputStringCalculation[i]-'0');
            
        }
        //  std::cout<<"--------------------------------------------";
        //     std::cout << "\nThe queue is as followed: \n";
        //     std::queue<int> copy = inputEnqueue;
        //     while (!copy.empty()) {
        //         std::cout << copy.front() << " ";
        //         copy.pop();
        //     }
        //     std::cout << "\n";

        // // I want to see what the current stack is and how it is organised
        //         std::cout<<"the stack is as follows:\n";
        //         std::stack<char> copeOperatorStack = operatorStack; 
        //         while (!copeOperatorStack.empty()){
        //             std::cout<< copeOperatorStack.top() << " "; 
        //             copeOperatorStack.pop();
        //         }
        //         std::cout<<"\n";
        //         std::cout<<"------------------------------------------\n";
    }
            std::cout<<"......................................................";
            std::cout << "\nThe final queue is as followed: \n";
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
