#include "Neuron.h"

Neuron::Neuron(unsigned int index, unsigned int numSynapses)
{
	this->index = index;
	for (unsigned int i = 0; i < numSynapses; i++)
		synapses.push_back(Synapse(randWeight()));

	output = 0.0;
	sumOutput = 0.0;
}

void Neuron::feedForward(const Layer &)
{
	// todo
}
