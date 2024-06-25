#include <iostream>
#include <stdint.h>
#include <string>
#include <Windows.h>
using namespace std;

std::string buffer;
//precomputed ansi color codes for drawPixel function
const char* brightnessCodes[16] = {
	"30m", "90m", "100m\033[30m", "37m", "97m", "37m", "90m", "100m\033[30m", "90m", "37m", "47m\033[30m", "97m","37m", "107m\033[90m", "107m\033[37m", "97m"
};
//precomputed ascii symbols for drawPixel function
uint8_t brightnessCodeSymbols[16] = {
	945, 944, 946, 944, 944, 945, 946, 944, 987, 946, 944, 946, 987, 945, 945, 987
};

void eraseLines(int amount = 1) {
	if (amount > 0) {
		std::cout << "\x1b[2K";
		for (int i = 0; i < amount; i++) std::cout << "\x1b[1A" << "\x1b[2K";
		std::cout << "\r";
	}
}

int countBufferLines() {
	int linecount = 0;
	for (int i = 0; i < buffer.length() - 1; i++) {
		if (buffer[i] == '\n') linecount++;
	} return linecount;
}

void clearConsole() {
	eraseLines(countBufferLines());
}

void drawPixel(uint8_t brightness) {
	uint8_t index = brightness >> 4; //both arrays have indices between [0..15] because uint8_t values are between [0..255]
	buffer += "\033["; buffer += brightnessCodes[index]; buffer+= brightnessCodeSymbols[index]; //mix between a color and an ascii symbol gives a different brigthened output on screen
	buffer += "\033[0m"; //set background back to default just in case
}

void fillRectangle(uint8_t brightness, int x, int y, uint8_t brightness_step = 5, bool gradient = 0) {
	uint8_t origBrightness = brightness;
	for (int b = 0; b < y; b++) {
		for (int a = 0; a < x; a++) {
			drawPixel(brightness);
			if (gradient) brightness+=brightness_step;
		} buffer+="\n"; brightness = origBrightness;
	} buffer+= "\n\n\n\n\n";
}


int main() {
	uint8_t brightness = 0;
	/*
	for (int i = 0; i < 100; i++) {
		fillRectangle(i, 171, 20, 3, true);
		cout << buffer;
		clearConsole();
		buffer.clear();
	}
	*/
	fillRectangle(0, 171, 7, 3, true);
	cout << buffer <<"\n\n\n";
	eraseLines(4);
	cout << countBufferLines() << "\n" << buffer;

	
}