#include "Textbox.h"
#include <Mikan.h>

Textbox::Textbox() {
	x = 0;
	y = 0;
	id = 0;
	text = "";
}

void Textbox::draw() {
	MikanDraw->Printf( id, x, y, text );
}

DrawablePriority Textbox::getPriority() {
	return priority;
}

Textbox& Textbox::setFont( Globals globals, const char* fontname, int size, unsigned color ) {
	MikanDraw->CreateFont( globals.FONT_NUM++, fontname, size, color );
	return *this;
}

Textbox& Textbox::setPosition( int X, int Y ) {
	x = X;
	y = Y;
	return *this;
}

Textbox& Textbox::setPriority( DrawablePriority p ) {
	priority = p;
	return *this;
}

Textbox& Textbox::setText( const char* s ) {
	text = s;
	return *this;
}