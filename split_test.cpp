#include "split.h"
#include <vector>

Node* make_linked_list(std::vector<int> arr) {
    Node* list = nullptr;
    for (int i = (int)arr.size() - 1; i >= 0; i--) {
        Node* node = new Node(arr[i], list);
        list = node;
    }
    return list;
}

void destroy_linked_list(Node* list) {
    while (list) {
        Node* next = list->next;
        delete list;
        list = next;
    }
}

bool are_lists_equal(Node* list_a, Node* list_b) {
    if (!list_a && !list_b) {
        // two empty lists are equal
        return true;
    } else if (!list_a || !list_b) {
        // one list is empty, the other isn't, they are not equal
        return false;
    } else {
        return (list_a->value == list_b->value) &&
               are_lists_equal(list_a->next, list_b->next);
    }
}

bool test_list(std::vector<int> in_vect, std::vector<int> correct_odds_vect,
               std::vector<int> correct_evens_vect) {
    Node* in = make_linked_list(in_vect);
    Node* odds = nullptr;
    Node* evens = nullptr;
    Node* correct_odds = make_linked_list(correct_odds_vect);
    Node* correct_evens = make_linked_list(correct_evens_vect);
    split(in, odds, evens);
    bool success = in == nullptr && are_lists_equal(odds, correct_odds) &&
                   are_lists_equal(evens, correct_evens);
    destroy_linked_list(odds);
    destroy_linked_list(evens);
    destroy_linked_list(correct_odds);
    destroy_linked_list(correct_evens);
    return success;
}

int main() {
    Node* list_a = make_linked_list({1, 2, 3, 4, 5});
    if (!are_lists_equal(list_a, list_a)) {
        destroy_linked_list(list_a);
        return 1;
    }
    destroy_linked_list(list_a);

    list_a = make_linked_list({});
    if (!are_lists_equal(list_a, nullptr)) {
        destroy_linked_list(list_a);
        return 1;
    }
    destroy_linked_list(list_a);

    if (!test_list({1, 2, 3, 4, 5}, {1, 3, 5}, {2, 4}) ||
        !test_list({1, 3, 5}, {1, 3, 5}, {}) ||
        !test_list({2, 4}, {}, {2, 4}) || !test_list({}, {}, {}) ||
        test_list({}, {2}, {})) {
        return 1;
    }
}
