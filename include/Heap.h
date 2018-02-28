#ifndef HEAP_H
#define HEAP_H
#include <vector>

struct bid{
float price;
float size;
int num_orders;

bid(){}
bid(float p, float s, int n): price(p), size(s), num_orders(n){}

bool operator < (bid& b)
{
    return price < b.price;
}
bool operator > (bid& b)
{
    return price > b.price;
}
};

class Heap {

private:
  std:: vector<bid> storage;
  void bubbleUp();
  void bubbleDown();
  void swap(int child, int parent);
  int getLeftChild(int parent);
  int getRightChild(int parent);
  int getParent(int child);

public:
  Heap();
  void insert(bid);
  bid remove();
  int getSize();
  bid getMax ();

};


#endif // HEAP_H
