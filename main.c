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

    test_getVectorValueV_emptyVector();
    test_setVectorValueV_emptyVector();
    test_pushBackV_emptyVector();
    test_pushBackV_fullVector();
    test_popBackV_notEmptyVector();
}

int main() {
    test();

    return 0;
}