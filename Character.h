#pragma once
#include "Globals.h"
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

	Character& addTexture( Globals&, const char*, unsigned long = 0x00000000 );
	
	void draw();

	DrawablePriority getPriority();
	int getX();
	int getY();

	Character& move();

	Character& setPosition( int, int );
	Character& setPriority( DrawablePriority );
	Character& setSize( int, int );
	Character& setVelocity( int, int );
};

