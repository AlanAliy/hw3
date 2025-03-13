#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  int m_; 
  std::vector<T> data_;
  PComparator comp_;

  size_t findParent(size_t indx) const;
  size_t findChild (size_t indx, size_t childnum) const;

};

// Add implementation of member functions here


// We will start top() for you to handle the case of 
// calling top on an empty heap

template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap() {}; //no dynamic mommory, not needed



template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int mVal, PComparator c)
  : m_(mVal), comp_(c)
  {
    if (m_< 2) {
      throw std::invalid_argument("must be at least 2ary heap");
    }
  }




template <typename T, typename PComparator>
size_t Heap<T,PComparator>::findChild(size_t indx, size_t childnum) const {
 return m_ * indx + childnum;

}

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::findParent(size_t indx) const {
  return (indx - 1) / m_; //formula for parent
}




template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const {
  return data_.empty();
}

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const {
  return data_.size();
}




template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    throw std::underflow_error("Heap is Empty");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return data_.front();

}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    throw std::underflow_error("Heap is Empty");
  }
  std::swap(data_.front(), data_.back());
  data_.pop_back(); //swapped elements and popped most valuable, need to heapify

  if (empty()) { return;}

  size_t indx = 0;
  size_t size = data_.size();

  while (true) {
    size_t most_value = indx;

    for(int n = 1; n<=m_; n++) { 
      size_t child_indx = findChild(indx, n);
      if ((child_indx < size) && comp_(data_[child_indx], data_[most_value])) {
        most_value = child_indx;
      }
    }

    if (most_value == indx) {
      break;  //most value is already at top
    }

    std::swap(data_[indx], data_[most_value]);
    indx = most_value;

  }
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item){
  data_.push_back(item);
  size_t indx = data_.size() - 1; //last item for just added member

  while (indx > 0) {
    size_t parent_indx = findParent(indx);

    if (comp_(data_[indx], data_[parent_indx])) {
      std::swap(data_[indx], data_[parent_indx]);
      indx = parent_indx;
    }
    else {break;}
  }

}


#endif

