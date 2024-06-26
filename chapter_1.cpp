#include <iostream>
#include <string>
#include <climits>
#include <cmath>
#include <vector>

using std::vector;
using std::string;


// Question 1.1

/*
Write a program to solve the selection problem.
Let k = N/2. 

NOTES: Here N represents total number of elements in the array.
k is the position of the element you're trying to find.
K = N/2 is finding the element in the middle(median) of the list or array.

*/


// rearrange the elements of an array smaller to greater..
int partition(int arr[], int l, int r){
   int x = arr[r];    // pivot element just holds value not index
   int L = 1; 

   for(int i = L; i <= r; i++){   // use '<=' to include element index r-1
      if(arr[i] < x){
	  std::swap(arr[L], arr[i]); 
	  L++;	// increment element
	}
    }
  
    std::swap(arr[L], arr[r]);  // move pivot to final place
    return L;
}

// left <= k <= right
int select(int arr[], int l, int r, int k){
    if(l == r){   // if array has only one element
      return arr[l];
    }
   
    int index = partition(arr, l, r);
    // in the final sorting postion
    if(k == index){
       return arr[k];
    } 
    else if(k < index){
       return select(arr, l, index - 1, k);
    }
    else{
       return select(arr, index + 1, r, k);
    }

}


int main(){

   int arr[] = {10, 4, 5, 8, 6, 11, 26};
   int n = sizeof(arr) / sizeof(arr[0]);
   int k = 3;

   std::cout << select(arr, 0, n - 1, k) << std::endl;

   return 0;
}

// ------------------------------------------------------------------
// ------------------------------------------------------------------
//Question 1.2


/*
Write a program to solve the word puzzle problem


*/

// index is the current position
bool findWord(int col, int row, const vector<vector<string>>& grid, const string& word, int index, vector<vector<bool>>& visited){
    
    if(index == word.length())
        return true;

    // grid.size() ensures number of rows
    // grid[0].size() ensures number of columns, [0] access the first row
    if(col < 0 || row < 0 || row >= grid.size() || col >= grid[0].size() || visited[row][col])
        return false;

    if(grid[row][col] != word[index])
        return false;

    visited[row][col] = true;
    // recursion
    bool found = findWord(col-1, row, grid, word, index+1, visited) || // left
                 findWord(col+1, row, grid, word, index+1, visited) || // right
                 findWord(col, row-1, grid, word, index+1, visited) || // up
                 findWord(col, row+1, grid, word, index+1, visited); // down

    visited[row][col] = false;

    return found;



}

void search(const vector<char>& grid, const vector<string>& word){
   
    int rows = grid.size();
    if(rows == 0) return false;
    int cols = grid[0].size();

    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    for(int row = 0; row < rows; ++row){
        for(int col = 0; col < cols; ++col){
           if(findWord(col, row, grid, word, 0, visited))
                return true;
        }
    }

    return false;


}


int main(){

   vector<string> words = {"dad", "to", "bad", "bat", "tap"};

   vector<char> grid = {{'d', 'b', 'w'}, 
                        {'a', 't', 'e'}, 
                        {'d', 'p', 'o'}}; 

   string words = "dad";

   vector<vector<char>> grid = {{'d', 'b', 'w'},
                                {'a', 't', 'e'},
                                {'d', 'p', 'o'}};

    if(search(grid, words))
        std::cout << "Words found\n";
    else
        std::cout << "word(s) not found\n";


   return 0;
}


// ------------------------------------------------------------------
// ------------------------------------------------------------------
// question 1.13


/*

Design a class template, Collection, that stores a collection of objcets(in an array),
along with the current size of the collection. Provide public function isEmpty, makeEmpty,
insert, remove, and contains. Contains(x) returns true if and only if an object that is
equal to x is present in the collection.


*/


template<typename Objects>
class Collection{
    Objects *array;   // pointer dynamically allocate array
    int currentSize;
    int capacity;

public:
    // Constructor
    Collection(int capacity) : capacity(capacity){
        array = new Objects[capacity];
    }
    // deconstructor to avoid memory leakage
    ~Collection(){
        delete[] array;
    }

    // checks if collection is empty
    bool isEmpty()const {
        return currentSize == 0;
    }

    int makeEmpty(){
        return currentSize = 0;
    }

    void insert(const Objects& n){
        if(currentSize < capacity)
           array[currentSize++] = n;
        else
           std::cout << "Collection is full to enter another element" << std::endl;
    }

    void remove(int index){
        for(int i = 0; i < currentSize; ++i){
            if(array[i] == index){
             for(int j = i; j < currentSize - 1; ++j){
              array[j] = array[j+1];
              }
            }
        }

        currentSize--;
    }
    // return true if object is equal to x
    bool contains(int x){
        for(int i = 0; i < currentSize; ++i){
           if(array[i] == x){
              return true;
           }
        }
        return false;
    }


    void print() {
     std::cout << "Collection contents: " << std::endl;
     for(int i = 0; i < currentSize; ++i){
           std::cout << array[i] << std::endl;
        }

    }

};


int main(){
    Collection<int> Collection(6);

    Collection.insert(1);
    Collection.insert(3);
    Collection.insert(4);
    Collection.insert(55);
    Collection.insert(23);
    Collection.insert(9);

    Collection.remove(3);
    Collection.print();

    int x = 5;
    bool isContain = Collection.contains(x);
    if(isContain)
        std::cout << "Value contains: " << x << std::endl;
    else
        std::cout << "No value is found" << std::endl;
    return 0;
}


// ------------------------------------------------------------------
// ------------------------------------------------------------------
// question 1.15


/*
Define a Rectangle class that provides getLength and getWidth. Using the findMax
routine. Write a main that creates an array of Rectangle and finds the largest Rectangle
first on the basis of area and then on the basic of perimeter.

*/


class Rectangle{

private:
    double length;
    double width;

public:

    explicit Rectangle(double l = 0.0, double w = 0.0) : length(l), width(w){}

    double getLength() const{
        return length;
    }   

    double getWidth() const{
        return width;
    }   
    // returning the area and perimeter using basic formulas
    double getArea() const{
        return width * length;
    }   

    double getPerimeter() const{
        return 2 * (width * length);
    }   


};
// overloarding the less than operator
// will compare the left hand side with the right hand side
template<typename Object>
bool operator<(const Rectangle& rhs) const{
        if(getArea() != rhs.getArea())
           return (getArea() < rhs.getArea());
        else
           return (getPerimeter < rhs.getPerimeter());
}



int main(){
    Rectangle r;
    // specify array here
    vector<Rectangle> arr = {Rectangle{8, 4}, Rectangle{12, 5}};
    findMax(arr);
    
    return 0;
}


