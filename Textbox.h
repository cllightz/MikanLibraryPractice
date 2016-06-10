#pragma once
#include "IDrawable.h"

class Textbox : public IDrawable {
private:
	int x;
	int y;
	int id;
	const char* text;
	DrawablePriority priority;

public:
	Textbox();
	
	void draw();

	DrawablePriority getPriority();

	Textbox& setFont( const char*, int, unsigned );
	Textbox& setPosition( int, int );
	Textbox& setPriority( DrawablePriority );
	Textbox& setText( const char* );
};

