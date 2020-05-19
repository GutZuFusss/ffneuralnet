#pragma once
#include "Neuron.h"

class NNetwork {
public:
	NNetwork(const std::vector<unsigned int> &);
	void printInfo();

	void setWeight(unsigned int layer, unsigned int neuron, unsigned int synapse, double weight) { layers[layer][neuron].setWeight(synapse, weight); }
	std::vector<double> getOutput();

	void feedForward(const std::vector<double> &);

private:
	std::vector<Layer> layers;
};
