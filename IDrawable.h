#pragma once

typedef int texture_t;

// 描画のレイヤ
// 数値が小さい（上の行）ほど優先度が高い（上のレイヤ）
enum DrawablePriority {
	TOP,
	PROMPT,
	ENEMY_BULLET,
	PLAYER_BULLET,
	PLAYER,
	ENEMY,
};

class IDrawable {
public:
	virtual DrawablePriority getPriority() = 0;
	virtual void draw() = 0;
};