#include "Bullet.h"
#include <cmath>
#include <Mikan.h>
#include "Globals.h"

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
	priority = TOP;
}

Bullet& Bullet::addTexture( unsigned argId, unsigned long transparent_color ) {
	MikanDraw->CreateTexture( argId, Globals::getInstance().TEXTURES[argId], transparent_color );
	return *this;
}

void Bullet::draw() {
	MikanDraw->DrawTexture( id, x, y, width * (int)type, 0, width, height );
}

DrawablePriority Bullet::getPriority() {
	return priority;
}

double Bullet::getR() {
	return width < height ? width / 2.0 : height / 2.0;
}

int Bullet::getX() {
	return x;
}

int Bullet::getY() {
	return y;
}

bool Bullet::isCollision( Bullet& arg ) {
	double x2 = pow( getX() - arg.getX(), 2.0 );
	double y2 = pow( getY() - arg.getY(), 2.0 );
	return pow( x2 + y2, 0.5 ) < getR() + arg.getR();
}

bool Bullet::isDisappeared() {
	if ( y <= -MikanWindow->GetDesktopHeight() && v_y <= 0 && a_y <= 0 ) {
		return true;
	}

	if ( y >= +MikanWindow->GetDesktopHeight() && v_y >= 0 && a_y >= 0 ) {
		return true;
	}

	if ( x <= -MikanWindow->GetDesktopWidth() && v_x <= 0 && a_x <= 0 ) {
		return true;
	}

	if ( x >= +MikanWindow->GetDesktopWidth() && v_x >= 0 && a_x >= 0 ) {
		return true;
	}

	return false;
}

Bullet& Bullet::move() {
	this->v_x += this->a_x;
	this->v_y += this->a_y;
	this->x += this->v_x;
	this->y += this->v_y;
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

Bullet& Bullet::setType( BulletType argType ) {
	type = argType;
	return *this;
}

Bullet& Bullet::setVelocity( int V_X, int V_Y ) {
	v_x = V_X;
	v_y = V_Y;
	return *this;
}