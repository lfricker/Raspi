#include "ObjectFollower.h"
#include <stdio.h>

using namespace std;

// USB Dongle 192.168.1.2
// Handy Wlan 192.168.43.100

int main(void)
{
	int lowH = 0;
	int highH = 8;
	int lowS = 119;
	int highS = 255;
	int lowV = 122;
	int highV = 255;

	ObjectFollower* deamonHunter = new ObjectFollower(lowH, highH, lowS, highS, lowV, highV);
	deamonHunter->goHunting();
	
	delete deamonHunter;
	return 0;
}