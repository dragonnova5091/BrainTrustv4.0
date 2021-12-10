#pragma once

#include <stdint.h>
#include <vector>

typedef struct Synapse
{
  int8_t weight;
  uint32_t postSID;
}Synapse;


typedef struct Neuron
{
  uint32_t id;
  std::vector<Synapse> synapses;
  uint32_t lastStepFired;
} Neuron;


Neuron* neuronCreate( uint32_t lsf);