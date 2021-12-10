

#include "../includes/neuron.h"
#include "../includes/paging.h"

#include <stdio.h>
#include <stdlib.h>
#include <map>

int main()
{
  std::map<uint32_t, Neuron*> theMap;

  Neuron* neuronPtr;
  uint32_t stepCounter = 0;

  neuronPtr = neuronCreate(stepCounter);



  //if (clearMap(theMap) == -1)
  //{
   // return -1;
  //


  return EXIT_SUCCESS;
}