#pragma once
#include <vector>
using namespace std;

struct Synapse
{
	double weight;
	Synapse(double weight = 0) { this->weight = weight; }
};

class Neuron {
public:
	Neuron(unsigned int, unsigned int);

	void setWeight(unsigned int synapse, double weight) { synapses[synapse].weight = weight; }
	std::vector<Synapse> getSynapses() { return synapses; }
	void setOutput(double output) { this->output = output; }
	double getOutput() { return output; };

	void feedForward(std::vector<Neuron>);

private:
	unsigned int index;
	std::vector<Synapse> synapses;

	double output;
	double sumOutput;
};