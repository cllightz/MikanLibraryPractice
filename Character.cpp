#include <Mikan.h>
#include "Character.h"
#include "Globals.h"

Character::Character() {
	x = 0;
	y = 0;
	v_x = 0;
	v_y = 0;
	width = 0;
	height = 0;
	id = 0;
	priority = top;
}

Character& Character::addTexture( const char* filename, unsigned long transparent_color ) {
	MikanDraw->CreateTexture( Globals::getInstance().generateNewTextureId(), filename, transparent_color );
	return *this;
}

void Character::draw() {
	MikanDraw->DrawTexture( id, x, y, 0, 0, width, height );
}

DrawablePriority Character::getPriority() {
	return priority;
}

double Character::getR() {
	return width < height ? width / 2.0 : height / 2.0;
}

int Character::getX() {
	return x;
}

int Character::getY() {
	return y;
}

bool Character::isCollision( Bullet& arg ) {
	double x2 = pow( getX() - arg.getX(), 2.0 );
	double y2 = pow( getY() - arg.getY(), 2.0 );
	return pow( x2 + y2, 0.5 ) < getR() + arg.getR();
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