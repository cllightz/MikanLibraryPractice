#pragma once

typedef int texture_t;

// �`��̃��C��
// ���l���������i��̍s�j�قǗD��x�������i��̃��C���j
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