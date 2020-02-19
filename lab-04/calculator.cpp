#include <iostream>
#include <stack>
#include <string>
std::stack<std::string> reverseStack(std::stack<std::string> myStack){
  std::stack<std::string> flippedStack;
  while (!myStack.empty()) {
    flippedStack.push(myStack.top());
    myStack.pop();
  }


  return flippedStack;
}

std::stack<std::string> fillStack(){
  std::stack<std::string> myStack;
  std::string input;
  std::cout << "Enter an equation to evaluate: ";
  std::getline(std::cin,input);

  for(int i = 0 ; i <= input.size() ; i++ ){
    if (input[i] != ' ' && input[i] != '\0'){
      if (isdigit(input[i])){
        int j = i;
        std::string number;
        bool isNumber = true;

        while(isNumber){
          number+=input[j];
          
          if (!isdigit(input[j+1])){
            isNumber = false;
          }
          else{
            j++;
            i++;
          }
        }


        myStack.push(number);
      }
      else{
        std::string op;
        op = input[i];
        myStack.push(op);

      }
      
    }

  }  

  //Now we need to reverse stack so it will appear like user input when being popped
  std::stack<std::string> properStack = reverseStack(myStack);
  return properStack;
}

int main () {
  std::stack<std::string> inputStack = fillStack();


  while (!inputStack.empty()) {
    std::cout << inputStack.top();
      inputStack.pop();
  }
  std::cout << std::endl;
  return 0;
}
