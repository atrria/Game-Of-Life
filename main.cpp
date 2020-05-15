#include "functions.h"

int main()
{
	srand(time(NULL)); //seed
	ios::sync_with_stdio(false); //for faster std::cout
	int option=0, rowSize=27, collSize=52, gen=100; //default 25x50, 100 generations

	printStartBanner();
	chooseOption(option, rowSize, collSize, gen);

	vector<vector<char> > v=initArr(rowSize, collSize);
	vector<vector<char> > vNew=initArr(rowSize, collSize);

	waitAndClear();
	drawArr(v);
	printArr(v); //first gen

	lifeCycle(gen, v, vNew);

	printEndBanner();
	return 0;
}
