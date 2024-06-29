#pragma once
#include <list>
#include <memory>

class MyList
{
private:
	std::shared_ptr< std::list<int> > pt; // a pointer to the real container
	std::list<int>::iterator left, right; // the position of slice is [left, right). 'left' is included, 'right' is excluded.

	std::list<int>::iterator forward(int pos) const{
		// count from 'left', find the element at position 'pos'.
		auto now = left;
		while(pos--) now++;
		return now;
	}

public:
	MyList(): pt(new std::list<int>()){
		left = pt->begin();
		right = pt->end();
		// Actually, left = right = pt->end(), because there is no element in the list.
	}

	MyList(std::initializer_list<int> init) : pt(std::make_shared<std::list<int>>(init)) {}

	MyList(std::shared_ptr<std::list<int>> sharedData, std::list<int>::iterator l, std::list<int>::iterator r) : pt(sharedData), left(l), right(r) {}

	void append(int value) {
		if(pt->size() == 0){
			pt->push_back(value);
			left = pt->begin();
			right = pt->end();
		}
		else{
			pt->insert(right, value);
			// right = pt->end();
		}
    }
	int& operator[](int pos){
		return *forward(pos); // access the element at the 'pos'
	}

	friend std::ostream& operator<<(std::ostream& os, const MyList& list);

	MyList operator() (int l, int r){
		return MyList(pt, forward(l), forward(r));
	}
};

std::ostream& operator<<(std::ostream& os, const MyList& list){
	os << '[';
    auto it = list.left;
	while(it != list.right){
		os << *it;
		it++;
		if(it != list.right) os << ',';
	}
    os << ']';
    return os;
}