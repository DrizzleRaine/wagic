#ifndef _PRICELIST_H_
#define _PRICELIST_H_

#include<string>
#include "../include/MTGDefinitions.h"
#include "../include/MTGDeck.h"
#include <stdio.h>

class MTGAllCards;

class PriceList{
 private:
  MTGAllCards * collection;
  string filename;
  map<int,int> prices;
 public:
  PriceList(const char * file, MTGAllCards * _collection);
  ~PriceList();
  int save();
  int getPrice(int cardId);
  int setPrice(int cardId, int price);

};

#endif
