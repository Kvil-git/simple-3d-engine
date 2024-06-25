#include <iostream>
#include <stdint.h>
#include <string>
#include <Windows.h>
using namespace std;

const char* brightnessCodes[17] = {
	"", "90m", "100m\033[30m", "30m", "37m", "97m", "37m", "97m", "90m", "100m\033[30m", "90m", "37m","97m","37m", "107m\033[90m", "107m\033[37m", "97m"
};

uint8_t brightnessCodeSymbols[17] = {
	32, 944, 946, 945, 944, 944, 945, 944, 946, 944, 987, 946, 946, 987, 944, 945, 987
};

void drawPixel(uint8_t brightness) {
	uint8_t index = brightness >> 4;
	cout << "\033[" << brightnessCodes[index] << brightnessCodeSymbols[index];
	cout << "\033[49m"; //set background back to default just in case
}


void fillRectangle(uint8_t brightness, int x, int y, uint8_t brightness_step = 5, bool gradient = 0) {
	uint8_t origBrightness = brightness;
	for (int b = 0; b < y; b++) {
		for (int a = 0; a < x; a++) {
			drawPixel(brightness);
			if (gradient) brightness+=brightness_step;
		} cout << "\n"; brightness = origBrightness;
	}cout << "\n\n\n\n\n";
}


int main() {
	uint8_t brightness = 0;

	fillRectangle(0, 100, 16, 3, true);

	
}