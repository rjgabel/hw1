/* Write your test code for the ULListStr in this file */

#include "ulliststr.h"
#include <iostream>
using namespace std;

void test(bool condition) {
    if (!condition) {
        std::cout << "Test failed\n";
        exit(1);
    }
}

int main(int argc, char* argv[]) {
    const std::string astley[28] = {
        "We're",    "no",  "strangers", "to",           "love", "You",
        "know",     "the", "rules",     "and",          "so",   "do",
        "I",        "A",   "full",      "commitment's", "what", "I'm",
        "thinking", "of",  "You",       "wouldn't",     "get",  "this",
        "from",     "any", "other",     "guy"};
    ULListStr* list = new ULListStr();
    test(list->size() == 0);
    test(list->empty());
    for (int i = 0; i < 28; i++) {
        list->push_back(astley[i]);
        test(list->size() - 1 == (size_t)i);
        test(list->back() == astley[i]);
        test(list->front() == astley[0]);
    }
    for (int i = 0; i < 28; i++) {
        test(list->get(i) == astley[i]);
    }
    for (int i = 27; i >= 0; i--) {
        test(list->size() - 1 == (size_t)i);
        test(list->back() == astley[i]);
        test(list->front() == astley[0]);
        list->pop_back();
    }
    test(list->size() == 0);
    test(list->empty());
    for (int i = 0; i < 28; i++) {
        list->push_front(astley[27 - i]);
        test(list->size() - 1 == (size_t)i);
        test(list->front() == astley[27 - i]);
        test(list->back() == astley[27]);
    }
    for (int i = 0; i < 28; i++) {
        test(list->get(i) == astley[i]);
    }
    for (int i = 27; i >= 0; i--) {
        test(list->size() - 1 == (size_t)i);
        test(list->front() == astley[27 - i]);
        test(list->back() == astley[27]);
        list->pop_front();
    }
    test(list->size() == 0);
    test(list->empty());
    delete list;
    std::cout << "Tests successful\n";
    return 0;
}
