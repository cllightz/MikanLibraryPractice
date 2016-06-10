#include "Globals.h"6

void Globals::initialize() {
	textureNum = 0;
	fontNum = 0;
}

unsigned Globals::generateNewTextureId() {
	unsigned res = textureNum;
	textureNum++;
	return res;
}

unsigned Globals::generateNewFontId() {
	unsigned res = fontNum;
	textureNum++;
	return res;
}
