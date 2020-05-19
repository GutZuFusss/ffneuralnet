#include <iostream>
#include <time.h>
#include <vector>
#include "NNetwork.h"

int main(int argc, char** argv)
{
	srand(time(NULL)); // switch to c++11's random library

	std::vector<unsigned int> structure = {2, 4, 1};
	NNetwork net(structure);
	std::vector<double> inputs(structure[0], 1);

	printf("inputs: ");
	for(int i = 0; i < inputs.size(); i++)
		printf("%f, ", inputs[i]);
	printf("\n\n\n");
	net.feedForward(inputs);
	net.printInfo();
	system("pause");
}
