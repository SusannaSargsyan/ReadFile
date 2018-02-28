#ifndef ORDERBOOK_H
#define ORDERBOOK_H
#include "Heap.h"
#include <string>
using namespace std;


class OrderBook
{
    public:
        OrderBook();
        virtual ~OrderBook();
        void bids();
        void asks();
        float max_bid();
        float min_ask();


    protected:

    private:
        Heap  bid_tree;
        Heap  ask_tree;
        bool  convert_to_bid (string line);

};

#endif // ORDERBOOK_H
