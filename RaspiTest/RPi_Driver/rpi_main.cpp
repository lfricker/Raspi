#include "ObjectFollower.h"
#include <stdio.h>

using namespace std;

int main(void)
{
	//define the filter-parameters for OpenCV to look for a red object
	int lowH = 0;
	int highH = 8;
	int lowS = 119;
	int highS = 255;
	int lowV = 122;
	int highV = 255;

	ObjectFollower* redDotHunter = new ObjectFollower(lowH, highH, lowS, highS, lowV, highV);
	redDotHunter->goHunting();
	
	delete redDotHunter;
	return 0;
}