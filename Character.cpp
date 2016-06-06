#include <Mikan.h>
#include "Character.h"

Character::Character() {
	x = 0;
	y = 0;
	width = 0;
	height = 0;
	id = 0;
	priority = top;
}

Character Character::addTexture( Globals globals, const char* filename, unsigned long transparent_color ) {
	MikanDraw->CreateTexture( globals.FONT_NUM++, filename, transparent_color );
	return *this;
}

void Character::draw() {
	MikanDraw->DrawTexture( id, x, y, 0, 0, width, height );
}

DrawablePriority Character::getPriority() {
	return priority;
}

int Character::getX() {
	return x;
}

int Character::getY() {
	return y;
}

Character& Character::move() {
	x += v_x;
	y += v_y;
	return *this;
}

Character& Character::setPosition( int X, int Y ) {
	x = X;
	y = Y;
	return *this;
}

Character& Character::setPriority( DrawablePriority p ) {
	priority = p;
	return *this;
}

Character& Character::setSize( int w, int h ) {
	width = w;
	height = h;
	return *this;
}

Character& Character::setVelocity( int V_X, int V_Y ) {
	v_x = V_X;
	v_y = V_Y;
	return *this;
}