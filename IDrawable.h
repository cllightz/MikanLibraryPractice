#pragma once

typedef int texture_t;

// 描画のレイヤ
// 数値が小さい（上の行）ほど優先度が高い（上のレイヤ）
enum DrawablePriority {
	top,
	prompt,
	player,
};

class IDrawable {
public:
	virtual DrawablePriority getPriority() = 0;
	virtual void draw() = 0;
};