#include "Neuron.h"

Neuron::Neuron(unsigned int index, unsigned int numSynapses)
{
	this->index = index;
	for (unsigned int i = 0; i < numSynapses; i++)
		synapses.push_back(Synapse(randWeight()));

	output = 0.0;
	sumOutput = 0.0;
}

void Neuron::feedForward(const Layer &prevLayer)
{
	sumOutput = 0.0;

	// add up our outputs
	for(unsigned int n = 0; n < prevLayer.size(); n++)
		sumOutput += prevLayer[n].output * prevLayer[n].synapses[index].weight;

	output = activationFunction(sumOutput); // apply out activation function to the sum of the outputs
}

double Neuron::activationFunction(double t)
{
	// using a leaky relu function for now (sigmoid as suggested in the paper seems to heavy for my toaster)
	return t > 0 ? t : t / 100;
}
