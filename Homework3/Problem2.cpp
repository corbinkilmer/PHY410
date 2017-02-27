#include <iostream>

int factorial(int number){
  if(number <= 1){
    return 1;
  }
  else{
    return number * factorial(number - 1);
  }
}

int main(){
  int i;
  std::cout << "Enter an integer to get it's factorial" << std::endl;
  std::cin >> i;
  if(i < 0){
    std::cout << "Choose a positive integer!" << std::endl;
  }
  else if(i >= 20){
    std::cout << "Choose an integer less than 20" << std::endl;
  }
  else{
      std::cout << "The factorial of i is:"  << factorial(i) << std::endl;
  }

  return 0;
}
