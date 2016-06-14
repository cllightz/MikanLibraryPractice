#include "Textbox.h"
#include <Mikan.h>
#include "Globals.h"

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

Textbox& Textbox::setFont( const char* fontname, int size, unsigned color ) {
	MikanDraw->CreateFont( 0, fontname, size, color );
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