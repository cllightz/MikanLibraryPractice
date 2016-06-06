#pragma once
#include "Globals.h"
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

	Textbox& setFont( Globals, const char*, int, unsigned );
	Textbox& setPosition( int, int );
	Textbox& setPriority( DrawablePriority );
	Textbox& setText( const char* );
};

