#include "OrderBook.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;

OrderBook::OrderBook()
{

}


OrderBook::~OrderBook()
{
    //dtor
}

 float OrderBook:: max_bid(){
    return bid_tree.getMax().price;

}
bool OrderBook:: convert_to_bid (string line)
{
    cout<<"Convert to Bid"<<endl;
    size_t found = line.find_first_of ('[');
    cout<<"Found "<<found<<endl;
    size_t start, end;
    float p, s;
    int n;
    if(found!=string::npos)
    {
           start = line.find_first_of ('"',found);
           cout<<"Start "<<start<<endl;
           if(start!=string::npos)
           {
               end =line.find_first_of ('"',start+1);
               cout<<"End "<<end<<endl;
               if(end!=string::npos)
               {
                   string price = line.substr (start+1,end-start-1);
                   cout<<price<<endl;
                   p = atof(price.c_str());
                   cout<<p<<endl;


               }

           }
           start = line.find_first_of ('"',end+1);
           cout<<"Start "<<start<<endl;
           if(start!=string::npos)
           {
               end =line.find_first_of ('"',start+1);
               cout<<"End "<<end<<endl;
               if(end!=string::npos)
               {
                   string size = line.substr (start+1,end-start-1);
                   cout<<size<<endl;
                   s = atof(size.c_str());

               }

           }
           start = line.find_first_of ("0123456789",end+1);
           cout<<"Start "<<start<<endl;
           if(start!=string::npos)
           {
               end =line.find_first_of (" ]",start+1);
               cout<<"End "<<end<<endl;
               if(end!=string::npos)
               {
                   string num_orders = line.substr (start,end-start);
                   cout<<num_orders<<endl;
                   n = atoi(num_orders.c_str());
                   bid B (p,s,n);
                   bid_tree.insert(B);
                   return true;

               }

           }

    }
    return false;
}
void OrderBook:: bids(){
 ifstream infile("Example.txt");
    string line;

    while (getline(infile, line))
    {

        size_t found = line.find("bids");
        if(found!=string::npos)
         {
            break;
        }


    }
     while (getline(infile, line))
     {
         cout<<line<<endl;
         bool converted = convert_to_bid (line);
         if (!converted)
         {
             break;
         }
     }



    }
