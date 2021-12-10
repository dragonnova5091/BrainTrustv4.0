#pragma once


#include "neuron.h"
#include <map>

#define PAGE_SIZE 8
#define METADATAPAGE "./Storage/page0metadata.csv"
#define TMPPAGE "./Storage/tmp.csv"

using std::map;

int loadPage(map<uint32_t, Neuron*> theMap, uint32_t pageMin);
int clearPageFromMap(map<uint32_t, Neuron*>, uint32_t pageMin, uint32_t pageMax);
int clearMap(map<uint32_t, Neuron*>);
int createPage(map<uint32_t, Neuron*>, uint32_t firstID);
uint32_t getNewestId();