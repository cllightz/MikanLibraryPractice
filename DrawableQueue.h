#pragma once
#include <queue>
#include <vector>
#include "IDrawable.h"

class DrawableQueue {
private:
	// �D��x�t���L���[��Compare
	struct less_drawable_priority {
		bool operator()( IDrawable* x, IDrawable* y ) const {
			return x->getPriority() < y->getPriority();
		}
	};

	// ����ɂ��邽�߂�Compare
	template<typename T, typename Compare>
	struct stable_compare {
		bool operator()( const std::pair<T, unsigned>& x, const std::pair<T, unsigned>& y ) const {
			if ( comp_( x.first, y.first ) ) { return true; }
			if ( comp_( y.first, x.first ) ) { return false; }
			return x.second > y.second;
		}

		Compare comp_;
	};

	// ����D��x�t���L���[
	template<typename T, typename Compare>
	struct stable_priority_queue_helper {
		typedef std::pair<T, unsigned> value_type;
		typedef std::vector<value_type> container_type;
		typedef stable_compare<T, Compare> compare_type;
		typedef std::priority_queue<value_type, container_type, compare_type> stable_priority_queue;
	};

	// �`�悷��I�u�W�F�N�g�̈���D��x�t���L���[
	using StablePriorityQueue = stable_priority_queue_helper<IDrawable*, less_drawable_priority>::stable_priority_queue;
	StablePriorityQueue q;

public:
	DrawableQueue();
	void push( IDrawable* );
	void push( std::vector<IDrawable*> );
	void draw();
};