#include "NNetwork.h"

NNetwork::NNetwork(const std::vector<unsigned int> &networkStructure)
{
	// build our neural network
	for(unsigned int l = 0; l < networkStructure.size(); l++)
	{
		layers.push_back(Layer());

		// now populate layer with neurons (and add synapses to the neurons)
		unsigned int neededSynapses = (l == networkStructure.size() - 1) ? 0 : networkStructure[l + 1]; // don't need any synapses for the output layer
		for (unsigned int n = 0; n < networkStructure[l]; n++)
			layers[l].push_back(Neuron(n, neededSynapses));
	}
}

std::vector<double> NNetwork::getOutput()
{
	// todo
}

void NNetwork::feedForward(const std::vector<double> &inputs)
{
	// todo
}
