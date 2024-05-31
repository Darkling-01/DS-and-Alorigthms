#define CHAPTER_1_HPP
#ifndef CHAPTER_1_HPP

#include <vector>
using std::vector;


// Question 1.15

template<typename comparable>
const Object& findMax(const vector<comparable>& comp){
	int maxIndex = 0;
	for(int i = 0; i < comparable.size(); ++i){
	   if(cmp[maxIndex] < cmp[i])
	      maxIndex = i; 
	}
	return cmp[maxIndex];
}





#endif
