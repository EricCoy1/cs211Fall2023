#include <iostream>
#include "queue.h"
using namespace std;

void Queue::queueError(string msg){
  cout << msg << endl;
}

Queue::Queue(){
  count = 0;
  front = 0;
  rear = -1;
}

bool Queue::isEmpty(){
  if(count == 0)
    return true;
  else 
    return false;
}

bool Queue::isFull(){
  if(count >= QUEUE_SIZE)
    return true;
  else
    return false;
}

void Queue::add(el_t e){
  if(isFull()){
    queueError("queue overflow");
  } else {
    ++rear;
    if((rear % QUEUE_SIZE) == 0){
      rear = 0;
    }
    el[rear] = e;
    count++;
    cout << "Element has been added.\n";
  }
}

el_t Queue::remove(){
  if(isEmpty()){
    queueError("Queue underflow");
  } else {
    el_t temp = el[front];
    front++;
    if((front % QUEUE_SIZE) == 0){
      front = 0;
    }
    count--;
    cout << "Front Element has been removed\n";
    return temp;
  }

}

ostream& operator<<(ostream& out, Queue& e){
  out << e.el[e.rear].oprd1 << " " << e.el[e.rear].oprt << " " << e.el[e.rear].oprd2 << endl;
  return out;
}

ostream& operator<<(ostream& out, el_t& e){
  out << e << endl;
  return out;
}


el_t Queue::getFront(){
  if(isEmpty() == true)
    queueError("Queue is empty");
  else {
    cout << "The front element is " << el[front] << endl;
    return el[front];
  }
}

void Queue::goToBack(){
  if(isEmpty() == true)
    queueError("Queue is empty");
  else {
    el_t toBack;
    toBack = remove();
    add(toBack);
    cout << "The front element has been moved to the rear.\n";
  }
  
    
}

int Queue::getSize(){
  return count;
}

void Queue::displayAll(){
  if(isEmpty() == true)
    cout << "[ empty ]\n";
  else 
    for(int i = 0; i < count; i++){
      cout << el[(front + i) % QUEUE_SIZE] << endl;
    }
}

void Queue::clearIt(){
  count = 0;
  front = 0;
  rear = -1;
}
