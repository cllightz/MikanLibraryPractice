#pragma once
#include "Bullet.h"
#include "IDrawable.h"

class Character : public IDrawable {
private:
	int x;
	int y;

	int v_x;
	int v_y;

	int width;
	int height;
	int id;
	DrawablePriority priority;

public:
	Character();

	Character& addTexture( const char*, unsigned long = 0x00000000 );
	
	void draw();

	DrawablePriority getPriority();
	double getR();
	int getX();
	int getY();

	bool isCollision( Bullet& );

	Character& move();

	Character& setPosition( int, int );
	Character& setPriority( DrawablePriority );
	Character& setSize( int, int );
	Character& setVelocity( int, int );
};

