#include "ObjectFollower.h"
#include <stdio.h>

using namespace std;

int main(void)
{
	//define the filter-parameters for OpenCV to look for a red object
	hsvFilter_t redObjectFilter;
	redObjectFilter.lowH = 0;
	redObjectFilter.highH = 8;
	redObjectFilter.lowS = 119;
	redObjectFilter.highS = 255;
	redObjectFilter.lowV = 122;
	redObjectFilter.highV = 255;

	ObjectFollower* redDotHunter = new ObjectFollower(redObjectFilter);
	redDotHunter->goHunting();
	
	delete redDotHunter;
	return 0;
}