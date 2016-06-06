#include "Bullet.h"
#include <Mikan.h>

Bullet::Bullet() {
	x = 0;
	y = 0;
	v_x = 0;
	v_y = 0;
	a_x = 0;
	a_y = 0;
	width = 0;
	height = 0;
	id = 0;
	priority = top;
}

Bullet& Bullet::addTexture( Globals& globals, const char* filename, unsigned long transparent_color ) {
	MikanDraw->CreateTexture( globals.FONT_NUM++, filename, transparent_color );
	return *this;
}

void Bullet::draw() {
	MikanDraw->DrawTexture( id, x, y, 0, 0, width, height );
}

DrawablePriority Bullet::getPriority() {
	return priority;
}

int Bullet::getX() {
	return x;
}

int Bullet::getY() {
	return y;
}



Bullet& Bullet::move() {
	x += v_x;
	y += v_y;
	return *this;
}

Bullet& Bullet::setAcceleration( int A_X, int A_Y ) {
	a_x = A_X;
	a_y = A_Y;
	return *this;
}

Bullet& Bullet::setPosition( int X, int Y ) {
	x = X;
	y = Y;
	return *this;
}

Bullet& Bullet::setPriority( DrawablePriority p ) {
	priority = p;
	return *this;
}

Bullet& Bullet::setSize( int w, int h ) {
	width = w;
	height = h;
	return *this;
}

Bullet& Bullet::setVelocity( int V_X, int V_Y ) {
	v_x = V_X;
	v_y = V_Y;
	return *this;
}