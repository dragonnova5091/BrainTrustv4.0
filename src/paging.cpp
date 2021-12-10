
#include "../includes/paging.h"

#include <string>
#include <fstream>
#include <iostream>

int loadPage(map<uint32_t, Neuron*> theMap, uint32_t pageMin)
{
  char pagename[32];

  sprintf_s(pagename, "../Storage/%d-%d.csv", pageMin, pageMin + PAGE_SIZE);

  std::fstream page;
  std::string filestr;

  page.open(pagename, std::ios::in);

  if (!page.is_open())
  {
    fprintf(stderr, "BAD PAGE");
  }

  while (!page.eof())
  {
    page >> filestr;
    std::cout << filestr;
  }

  return 0;
  
}


uint32_t getNewestId()
{
  
  std::ifstream page;
  std::ofstream tmp;
  std::string filestr;
  uint32_t id;
  char tmpstr[13];

  page.open(METADATAPAGE);
  tmp.open(TMPPAGE, std::ios::out);

  page >> filestr;

  filestr.erase(0, 3);

  id = std::stoi(filestr);

  sprintf_s(tmpstr, "id,%d\n", id + 1);
  filestr = tmpstr;

  tmp << filestr;
  
  while (page >> filestr)
  {
    filestr.push_back('\n');
    tmp << filestr;
  }

  page.close();
  tmp.close();

  page.open(TMPPAGE);
  tmp.open(METADATAPAGE, std::ios::out);

  while (page >> filestr)
  {
    filestr.push_back('\n');
    tmp << filestr;
  }


  page.close();
  tmp.close();



  return id;
}


int clearMap(map<uint32_t, Neuron*> theMap)
{
  std::map<uint32_t, Neuron*>::iterator it = theMap.begin();

  uint32_t min = it->first;

  min = min - (min % PAGE_SIZE);

  clearPageFromMap(theMap, min, min + PAGE_SIZE);


  return 0;
}

int clearPageFromMap(map<uint32_t, Neuron*>, uint32_t pageMin, uint32_t pageMax)
{
  return 0;
}