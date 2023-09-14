// Stack Complete Code
#include <stdio.h>
#include <iostream>
using namespace std;

class Stack {
  public: int top;
  int stackSize;
  int * stackArr;

  Stack(int stackSize) {
    this -> initializeStack(stackSize);
  }

  // private:
  void initializeStack(int stackSize) {
    this -> top = -1;
    this -> stackSize = stackSize;
    this -> stackArr = new int[this -> stackSize];
  }

  bool isFull() {
    return (stackSize - 1) == top;
  }

  bool isEmpty() {
    return top == -1;
  }

  void push(int item) {
    if (isFull()) return;
    stackArr[++top] = item;
    cout << "Prime Number Push in stack " << item << "\n";
  }

  int pop() {
    if (isEmpty()) return -1;
    return stackArr[top--];
  }
};

class PrimeNumberGenerator: Stack {

  public: PrimeNumberGenerator(int value): Stack(value) {
    generatePrimeNumber(value);
  }

  private: bool isPrime(int userValue) {
    int isComposite = 0;
    for (int j = 2; j <= userValue / 2; j++) {
      if (userValue % j == 0) {
        isComposite = 1;
      }
    }
    return (isComposite == 0);
  }

  void generatePrimeNumber(int numberOfPrimes) {
    int primeFound = 0;
    for (int i = 2;; i++) {
      if (isPrime(i)) {
        this -> push(i);
        primeFound++;
      }
      if (primeFound == numberOfPrimes) {
        break;
      }
    }
  }

  void reinitializeStack(int newQueueSize) {
    delete this -> stackArr;
    // this -> initializeQueue(newQueueSize);
    this -> initializeStack(newQueueSize);
  }

  int askUserForChoice() {
    int userChoice = 0;
    cout << "1 Yes \n";
    cout << "2 No \n";
    cout << "Are U want to Again Prime Number Again ";
    cin >> userChoice;
    return userChoice;
  }

  int getNumberOfPrimes() {
    int numberOfPrimesToGenerate = 0;
    cout << "Enter the number of prime numbers you want to generate: ";
    cin >> numberOfPrimesToGenerate;
    return numberOfPrimesToGenerate;
  }

  void regeneratePrimes(int numberOfPrimes) {
    reinitializeStack(numberOfPrimes);
    generatePrimeNumber(numberOfPrimes);
  }

  void displayTopPrime() {
    cout << "Prime Number Pop From stack: " << pop() << "\n";
  }

  void requestRegeneratePrime() {
    int numberOfPrimes = getNumberOfPrimes();
    regeneratePrimes(numberOfPrimes);
    displayTopPrime();
  }

  public: int consumerPrimeNumber() {
    if (this -> isEmpty()) {
      cout << "All Number Consumed \n";
      if (askUserForChoice() == 1) {
        requestRegeneratePrime();
        return false;
      }
      cout << "Program Terminated \n";
      abort();

    } else {
      displayTopPrime();
    }
  }
};

int main() {
  PrimeNumberGenerator primeNumbers(4);
  primeNumbers.consumerPrimeNumber();
  primeNumbers.consumerPrimeNumber();
  primeNumbers.consumerPrimeNumber();
  primeNumbers.consumerPrimeNumber();
  primeNumbers.consumerPrimeNumber();
  primeNumbers.consumerPrimeNumber();
  primeNumbers.consumerPrimeNumber();

  return 0;
}