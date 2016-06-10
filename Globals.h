#pragma once

class Globals {
private:
	unsigned textureNum;
	unsigned fontNum;
	Globals() = default;
	~Globals() = default;

public:
	Globals( const Globals& ) = delete;
	Globals& operator=( const Globals& ) = delete;
	Globals( Globals&& ) = delete;
	Globals& operator=( Globals&& ) = delete;

	static Globals& getInstance() {
		static Globals inst;
		return inst;
	}

	void initialize();

	unsigned generateNewTextureId();
	unsigned generateNewFontId();
};
