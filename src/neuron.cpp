
#include "../includes/neuron.h"
#include "../includes/paging.h"

Neuron* neuronCreate(uint32_t lsf)
{
	Neuron* pNeuron = new Neuron;

	uint32_t id = getNewestId();
	pNeuron->id = id;
	pNeuron->lastStepFired = lsf;


	return pNeuron;

}