#pragma once

typedef int texture_t;

// �`��̃��C��
// ���l���������i��̍s�j�قǗD��x�������i��̃��C���j
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