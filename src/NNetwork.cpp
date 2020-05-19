#include "NNetwork.h"

NNetwork::NNetwork(const std::vector<unsigned int> &networkStructure)
{
	// build our neural network's layers
	for(unsigned int l = 0; l < networkStructure.size(); l++)
	{
		layers.push_back(Layer());

		// now populate layer with neurons (and add synapses to the neurons)
		unsigned int neededSynapses = (l == networkStructure.size() - 1) ? 0 : networkStructure[l + 1]; // don't need any synapses for the output layer
		for(unsigned int n = 0; n < networkStructure[l]; n++)
			layers[l].push_back(Neuron(n, neededSynapses));
	}
}

std::vector<double> NNetwork::getOutput()
{
	std::vector<double> output;
	Layer& layer = layers.back();
	for(unsigned int n = 0; n < layer.size(); n++)
		output.push_back(layer[n].getOutput());

	return output;
}

void NNetwork::feedForward(const std::vector<double> &inputs)
{
	// first of all update the outputs
	for(unsigned int i = 0; i < inputs.size(); i++)
		layers[0][i].setOutput(inputs[i]);

	// then feed everything through
	for(unsigned int l = 1; l < layers.size(); l++) {
		Layer& layer = layers[l];
		for(unsigned int n = 0; n < layer.size(); n++)
			layer[n].feedForward(layers[l - 1]);
	}
}
