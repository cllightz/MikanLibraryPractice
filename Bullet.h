#pragma once
#include "IDrawable.h"

enum BulletType {
	BULLET_RED,
	BULLET_ORANGE,
	BULLET_YELLOW,
	BULLET_GREEN,
	BULLET_BLUE,
};

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

	BulletType type;

public:
	Bullet();

	Bullet& addTexture( unsigned, unsigned long = 0x00000000 );

	void draw();

	DrawablePriority getPriority();
	double getR();
	int getX();
	int getY();

	bool isCollision( Bullet& );
	bool isDisappeared();

	Bullet& move();

	Bullet& setAcceleration( int, int );
	Bullet& setPosition( int, int );
	Bullet& setPriority( DrawablePriority );
	Bullet& setSize( int, int );
	Bullet& setType( BulletType );
	Bullet& setVelocity( int, int );
};

