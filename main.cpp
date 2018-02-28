#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "OrderBook.h"
using namespace std;


int main()
{
    OrderBook OB;
    OB.bids();
  /*  ifstream infile("22-12.txt");
    string line;
    int count=0;

    infile.seekg (0, infile.end);
    int length = infile.tellg();
    infile.seekg (0, infile.beg);
    cout<<length<<endl;

    while (getline(infile, line))
    {
        cout<<line<<endl;
        count++;
        if(count==10)
        {
            break;
        }
    }

*/

    return 0;
}
