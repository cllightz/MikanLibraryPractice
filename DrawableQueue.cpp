#include "DrawableQueue.h"

DrawableQueue::DrawableQueue() {
	q = StablePriorityQueue();
}

// オブジェクト1つの追加
void DrawableQueue::push( IDrawable* obj ) {
	q.push( std::pair<IDrawable*, unsigned>( obj, q.size() ) );
}

// オブジェクトのコレクションの一括追加
void DrawableQueue::push( std::vector<IDrawable*> v ) {
	for each ( IDrawable* obj in v ) {
		q.push( std::make_pair( obj, q.size() ) );
	}
}

// キュー内のオブジェクトの描画
void DrawableQueue::draw() {
	while ( !q.empty() ) {
		std::pair<IDrawable*, unsigned> p = q.top();
		p.first->draw();
		q.pop();
	}
}