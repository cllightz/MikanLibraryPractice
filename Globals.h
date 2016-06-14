#pragma once

enum TextureId {
	TEXTURE_XCHU,
	TEXTURE_BULLET,
};

class Globals {
private:
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

	const char TEXTURES[2][16] = { "xchu.png", "bullet.png" };
};
