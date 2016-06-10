#pragma once
#include "IDrawable.h"

class Bullet : public IDrawable {
private:
	int x;
	int y;

	int v_x;
	int v_y;

	int a_x;
	int a_y;

	int width;
	int height;
	int id;
	DrawablePriority priority;

public:
	Bullet();

	Bullet& addTexture( const char*, unsigned long = 0x00000000 );

	void draw();

	DrawablePriority getPriority();
	double getR();
	int getX();
	int getY();

	bool isCollision( Bullet& );

	Bullet& move();

	Bullet& setAcceleration( int, int );
	Bullet& setPosition( int, int );
	Bullet& setPriority( DrawablePriority );
	Bullet& setSize( int, int );
	Bullet& setVelocity( int, int );
};

