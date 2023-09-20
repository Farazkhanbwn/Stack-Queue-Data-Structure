// Completed Prime Number Generator Queu
#include <stdio.h>
#include <iostream>
using namespace std;

class PrimeNumberGenerator {
  public: int * primeNumberArray;
  int front;
  int rear;
  int primeFound;
  int userChoice;

  PrimeNumberGenerator(int value) {
    initializeQueue(value);
    generatePrimeNumber(value);
  }

  private: void initializeQueue(int queueSize) {
    this -> primeNumberArray = new int[queueSize];
    this -> front = 0;
    this -> rear = 0;
    this -> primeFound = 0;
    this -> userChoice = 0;
  }

  bool isPrime(int userValue) {
    int isComposite = 0;
    for (int j = 2; j <= userValue / 2; j++) {
      if (userValue % j == 0) {
        isComposite = 1;
      }
    }
    return (isComposite == 0);
  }

  void generatePrimeNumber(int numberOfPrimes) {
    for (int i = 2;; i++) {
      if (isPrime(i)) {
        primeFound++;
        primeNumberArray[rear++] = i;
      }
      if (primeFound == numberOfPrimes) {
        break;
      }
    }
  }

  void reinitializeQueue(int newQueueSize) {
    delete primeNumberArray;
    this -> initializeQueue(newQueueSize);
  }

  int askUserForChoice() {
    cout << "1 Yes \n";
    cout << "2 No \n";
    cout << "Are U want to Again Prime Number Again ";
    cin >> userChoice;
    return userChoice;
  }

  void requestRegeneratePrime() {
    int numberOfPrimesToGenerate = 0;
    cout << "Enter the number of prime numbers you want to generate: ";
    cin >> numberOfPrimesToGenerate;
    reinitializeQueue(numberOfPrimesToGenerate);
    generatePrimeNumber(numberOfPrimesToGenerate);
    cout << "Prime Number is : " << primeNumberArray[front++] << "\n";
  }

  public: int consumerPrimeNumber() {
    if (front == rear) { //when both zero they dont run becasue first generate all number then we can call consumerPrime call
      cout << "All Number Consumed \n";

      if (askUserForChoice() == 1) {
        requestRegeneratePrime();
        return false;
      }
      cout << "Program Terminated \n";
      abort();

    } else {
      cout << "Prime Number is : " << primeNumberArray[front++] << "\n";
    }
  }
};

int main() {
  // Write C++ code here
  PrimeNumberGenerator pg(5);
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