#include "libs\data_structures\vector\vector.h"
#include "libs\data_structures\vector\vectorVoid.h"

void test() {
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
    test_popBack_notEmptyVector();
    test_atVector_notEmptyVector();
    test_atVector_requestToLastElement();
    test_back_oneElementInVector();
    test_front_oneElementInVector();
}

int main() {
    test();

    vectorVoid v = {
            0,
            3,
            6,
            sizeof(int)
    };

    return 0;
}