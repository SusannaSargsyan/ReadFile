#include "Heap.h"


Heap :: Heap()
{

}


int Heap:: getSize()
{
  return storage.size();
}


void Heap::swap(int child, int parent) {
  bid temp;
  temp = storage[child];
  storage[child] = storage[parent];
  storage[parent] = temp;
}


int Heap:: getParent(int child) {
  if (child % 2 == 0)
	return (child /2 ) -1;
  else
	return child/2;

}


int Heap:: getLeftChild(int parent){
  return 2*parent +1;
}


int Heap:: getRightChild(int parent){
  return 2 * parent + 2;
}


void Heap:: insert(bid value) {

  storage.push_back(value);
  bubbleUp();

}


  void Heap :: bubbleUp() {
  int child = storage.size() - 1;
  int parent = getParent(child);

  while (storage[child] > storage[parent] && child >=0 && parent >= 0) {

	swap(child, parent);
	child = parent;
	parent = getParent(child);

  }


}



bid Heap:: remove() {
  int child = storage.size()  - 1;
  swap(child, 0);

  bid value = storage.back();
  storage.pop_back();

  bubbleDown();

  return value;


}



void Heap:: bubbleDown() {
  int parent = 0;

  while (1) {
	int left = getLeftChild(parent);
	int right = getRightChild(parent);
	int length = storage.size();
	int largest = parent;

	if (left < length && storage[left] > storage[largest])
	  largest = left;

	if (right < length && storage[right] > storage[largest])
	  largest = right;

	if (largest != parent) {
	  swap(largest, parent);
	  parent = largest;
	}
	else
	  break;


  }

}


bid Heap:: getMax(){
    return storage[0];
}
