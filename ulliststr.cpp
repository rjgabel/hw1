#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

void ULListStr::push_back(const std::string& val) {
    if (empty()) {
        // list is empty
        Item* node = new Item();
        head_ = node;
        tail_ = node;
    } else if (tail_->last == ARRSIZE) {
        // No more space in the back of this node, make a new one
        Item* node = new Item();
        node->prev = tail_;
        tail_->next = node;
        tail_ = node;
    }
    tail_->val[tail_->last] = val;
    tail_->last++;
    size_++;
}

void ULListStr::pop_back() {
    if (empty()) {
        // list is empty, nothing to pop!
        return;
    }
    tail_->last--;
    size_--;
    if (empty()) {
        delete tail_;
        head_ = nullptr;
        tail_ = nullptr;
    } else if (tail_->last == 0) {
        Item* new_tail = tail_->prev;
        delete tail_;
        tail_ = new_tail;
        tail_->next = nullptr;
    }
}

void ULListStr::push_front(const std::string& val) {
    if (empty()) {
        // list is empty
        Item* node = new Item();
        head_ = node;
        tail_ = node;
        head_->first = ARRSIZE;
        head_->last = ARRSIZE;
    } else if (head_->first == 0) {
        // No more space in the front of this node, make a new one
        Item* node = new Item();
        node->next = head_;
        head_->prev = node;
        head_ = node;
        head_->first = ARRSIZE;
        head_->last = ARRSIZE;
    }
    head_->val[head_->first - 1] = val;
    head_->first--;
    size_++;
}

void ULListStr::pop_front() {
    if (empty()) {
        // list is empty, nothing to pop!
        return;
    }
    head_->first++;
    size_--;
    if (empty()) {
        delete head_;
        head_ = nullptr;
        tail_ = nullptr;
    } else if (head_->first == ARRSIZE) {
        Item* new_head = head_->next;
        delete head_;
        head_ = new_head;
        head_->prev = nullptr;
    }
}

std::string const& ULListStr::back() const {
    if (empty()) {
        throw std::invalid_argument("Bad location");
    }
    return tail_->val[tail_->last - 1];
}

std::string const& ULListStr::front() const {
    if (empty()) {
        throw std::invalid_argument("Bad location");
    }
    return head_->val[head_->first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const {
    if (loc >= size()) {
        return nullptr;
    }
    Item* node = head_;
    size_t index = head_->first;
    for (int i = 0; (size_t)i < loc; i++) {
        index++;
        if (index == ARRSIZE) {
            node = node->next;
            index = 0;
        }
    }
    return &node->val[index];
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
