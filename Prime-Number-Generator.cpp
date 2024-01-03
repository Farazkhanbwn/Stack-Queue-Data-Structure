@@ -0,0 +1,102 @@
#include <stdio.h>
#include <iostream>
using namespace std;

class primeNumberGenerator {
  public: int *array;
  int front = -1;
  int rear = -1;
  int checkNumber = 0;
  int choice = 0;
  int count = 0;
  primeNumberGenerator(int value) {
    generatePrimeNumber(value);
  }
    
    // int isEmptyArray(){
    //     if(front == rear){
    //         return 0;
    //     }
    // }
    
  int generatePrimeNumber(int input) {
      this->array = new int[input];
    if (input == 1) {
        rear++;
      array[rear] = 2;
      if(front == -1){
            front = rear;
        }
    }
    for (int i = 2; i <= input * input; i++) {
      if (checkNumber == input) {
        return false;
      }
      int isPrime = 0;
      for (int j = 2; j <= i / 2; j++) {
        if (i % j == 0) {
          isPrime = 1;
        }
      }
      if (isPrime == 0) {
          rear++;
        // cout << "Prime number is = " << i << "\n";
        array[rear] = i;
        checkNumber++;
        if(front == -1){
            front = rear;
        }
      }
    }
  };

  int consumerPrimeNumber() {
    if (array[front] == 0) {
        
      cout << "All Number Consumed \n";
      
      cout << "1 Yes \n";
      cout << "2 No \n";
      cout << "Are U want to Again Prime Number Again ";
      cin >> choice;
    //   cout << "Type of choice is : " << typeid(choice).name() << "\n";
      if(choice == 1)
      {
          cout << "How Much Number You want to Create : ";
          cin >> count;
          delete this->array;
          front = -1;
          rear = -1;
            checkNumber = 0;
            choice = 0;
          generatePrimeNumber(count);
      }
      else
      {
          return false;
      }
    } 
    else 
    {
      cout << "value in array : " << array[front] << "\n";
      front++;
    }
  }
};

int main() {
  // Write C++ code here
  primeNumberGenerator pg(5);
  pg.consumerPrimeNumber();
  pg.consumerPrimeNumber();
  pg.consumerPrimeNumber();
  pg.consumerPrimeNumber();
  pg.consumerPrimeNumber();
  pg.consumerPrimeNumber();
  
  pg.consumerPrimeNumber();
  pg.consumerPrimeNumber();
  pg.consumerPrimeNumber();

  return 0;
}