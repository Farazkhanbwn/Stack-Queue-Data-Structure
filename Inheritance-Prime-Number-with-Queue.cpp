// Online C++ compiler to run C++ program online
#include <stdio.h>
#include <iostream>
using namespace std;

class Queue {
  public: int front;
  int rear;
  int queueSize;
  int * queueArray;

  void initializeQueue(int queueSize) {
    this -> queueSize = queueSize;
    this -> front = 0;
    this -> rear = 0;
    this -> queueArray = new int[this -> queueSize];
  }

  bool isEmptyQueue() {
    return front == rear;
  }

  bool isFullQueue() {
    return rear == queueSize;
  }

  // Check Queue Size
  int itemsRemainingInQueue() {
    return rear - front;
  }

  // Insertion
  int enQueue(int data) {
    if (isFullQueue()) {
      cout << "Queue Already full \n";
      return 0;
    }
    queueArray[rear++] = data;
  }

  // Deletion
  int deQueue() {
    if (isEmptyQueue()) {
      printf("Queue is Empty");
      return 0;
    }
    return queueArray[front++];
  }

  void reInitializeQueue(int queueSize) {
    delete queueArray;
    this -> initializeQueue(queueSize);
  }
};

class PrimeNumberGenerator: public Queue {

  public: PrimeNumberGenerator(int value) {
    this -> initializeQueue(value);
    generatePrimeNumber(value);
  }

  private: bool isPrime(int n) {
    if (n == 1 || n == 0) return false;
    for (int i = 2; i < n; i++) {
      if (n % i == 0) return false;
    }
    return true;
  }

  void generatePrimeNumber(int primeNoGeneratedCount) {
    int count = 0;
    for (int i = 1;; i++) {
      if (isPrime(i)) {
        this -> enQueue(i);
        count++;
      }
      if (count == primeNoGeneratedCount) break;
    }
  }
  bool isAllPrimeNoConsumed() {
    return front == queueSize;
  }

  public:

    void requestRegeneratePrimeNumber() {
      int getNewPrimeNoGeneratedCount;
      cout << "Enter new count to generate prime number: ";
      cin >> getNewPrimeNoGeneratedCount;
      {
        this -> reInitializeQueue(getNewPrimeNoGeneratedCount);
        this -> generatePrimeNumber(getNewPrimeNoGeneratedCount);

      };
    };

  void consumePrimeNumber() {
    if (this -> isAllPrimeNoConsumed()) {
      cout << "All numbers are consumed. \n";
      this -> requestRegeneratePrimeNumber();
      cout << "Consumed Prime No. is: " << this -> deQueue() << "\n";
      //   cout << "Item Remaining in Queue  = " << itemsRemainingInQueue() << "\n";
      return;
    }
    // cout << "Item Remaining in Queue  = " << itemsRemainingInQueue() << "\n";
    cout << "Consumed Prime No. is: " << this -> deQueue() << "\n";
  };
};

int main() {
  // Write C++ code here
  PrimeNumberGenerator pg(2);
  pg.consumePrimeNumber();
  pg.consumePrimeNumber();
  pg.consumePrimeNumber();
  pg.consumePrimeNumber();
  pg.consumePrimeNumber();
  pg.consumePrimeNumber();

  return 0;
}