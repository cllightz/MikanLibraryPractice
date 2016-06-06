#include "DrawableQueue.h"

DrawableQueue::DrawableQueue() {
	q = StablePriorityQueue();
}

// �I�u�W�F�N�g1�̒ǉ�
void DrawableQueue::push( IDrawable* obj ) {
	q.push( std::pair<IDrawable*, unsigned>( obj, q.size() ) );
}

// �I�u�W�F�N�g�̃R���N�V�����̈ꊇ�ǉ�
void DrawableQueue::push( std::vector<IDrawable*> v ) {
	for each ( IDrawable* obj in v ) {
		q.push( std::make_pair( obj, q.size() ) );
	}
}

// �L���[���̃I�u�W�F�N�g�̕`��
void DrawableQueue::draw() {
	while ( !q.empty() ) {
		std::pair<IDrawable*, unsigned> p = q.top();
		p.first->draw();
		q.pop();
	}
}