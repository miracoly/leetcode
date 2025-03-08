#include <criterion/criterion.h>
#include "solution.h"  // Your header file with MyLinkedList, Node, and function declarations

Test(MyLinkedList, constructor) {
    MyLinkedList* linkedList = myLinkedListCreate();
    cr_assert_not_null(linkedList);
}

// --------------------------------------------------------
// TestCase1 replicates the sequence of calls/tests from:
// ["MyLinkedList","addAtHead","addAtHead","addAtHead","addAtIndex","deleteAtIndex",
//  "addAtHead","addAtTail","get","addAtHead","addAtIndex","addAtHead"]
// [[],[7],[2],[1],[3,0],[2],[6],[4],[4],[4],[5,0],[6]]
// Expected intermediate checks and final "get" result.
// --------------------------------------------------------
Test(MyLinkedList, testCase1) {
    MyLinkedList* linkedList = myLinkedListCreate();
    cr_assert_not_null(linkedList);

    // addAtHead(7) -> [7]
    myLinkedListAddAtHead(linkedList, 7);
    cr_assert_eq(myLinkedListGet(linkedList, 0), 7);

    // addAtHead(2) -> [2, 7]
    myLinkedListAddAtHead(linkedList, 2);
    cr_assert_eq(myLinkedListGet(linkedList, 0), 2);
    cr_assert_eq(myLinkedListGet(linkedList, 1), 7);

    // addAtHead(1) -> [1, 2, 7]
    myLinkedListAddAtHead(linkedList, 1);
    cr_assert_eq(myLinkedListGet(linkedList, 0), 1);
    cr_assert_eq(myLinkedListGet(linkedList, 1), 2);
    cr_assert_eq(myLinkedListGet(linkedList, 2), 7);

    // addAtIndex(3,0) -> [1, 2, 7, 0]
    myLinkedListAddAtIndex(linkedList, 3, 0);
    cr_assert_eq(myLinkedListGet(linkedList, 0), 1);
    cr_assert_eq(myLinkedListGet(linkedList, 1), 2);
    cr_assert_eq(myLinkedListGet(linkedList, 2), 7);
    cr_assert_eq(myLinkedListGet(linkedList, 3), 0);

    // deleteAtIndex(2) -> remove the element at index 2 (which is '7') => [1, 2, 0]
    myLinkedListDeleteAtIndex(linkedList, 2);
    cr_assert_eq(myLinkedListGet(linkedList, 0), 1);
    cr_assert_eq(myLinkedListGet(linkedList, 1), 2);
    cr_assert_eq(myLinkedListGet(linkedList, 2), 0);

    // addAtHead(6) -> [6, 1, 2, 0]
    myLinkedListAddAtHead(linkedList, 6);
    cr_assert_eq(myLinkedListGet(linkedList, 0), 6);
    cr_assert_eq(myLinkedListGet(linkedList, 1), 1);
    cr_assert_eq(myLinkedListGet(linkedList, 2), 2);
    cr_assert_eq(myLinkedListGet(linkedList, 3), 0);

    // addAtTail(4) -> [6, 1, 2, 0, 4]
    myLinkedListAddAtTail(linkedList, 4);
    cr_assert_eq(myLinkedListGet(linkedList, 0), 6);
    cr_assert_eq(myLinkedListGet(linkedList, 1), 1);
    cr_assert_eq(myLinkedListGet(linkedList, 2), 2);
    cr_assert_eq(myLinkedListGet(linkedList, 3), 0);
    cr_assert_eq(myLinkedListGet(linkedList, 4), 4);

    // get(4) -> should be 4
    cr_assert_eq(myLinkedListGet(linkedList, 4), 4);

    // addAtHead(4) -> [4, 6, 1, 2, 0, 4]
    myLinkedListAddAtHead(linkedList, 4);
    cr_assert_eq(myLinkedListGet(linkedList, 0), 4);
    cr_assert_eq(myLinkedListGet(linkedList, 1), 6);
    cr_assert_eq(myLinkedListGet(linkedList, 2), 1);
    cr_assert_eq(myLinkedListGet(linkedList, 3), 2);
    cr_assert_eq(myLinkedListGet(linkedList, 4), 0);
    cr_assert_eq(myLinkedListGet(linkedList, 5), 4);

    // addAtIndex(5, 0) -> [4, 6, 1, 2, 0, 0, 4]
    myLinkedListAddAtIndex(linkedList, 5, 0);
    cr_assert_eq(myLinkedListGet(linkedList, 0), 4);
    cr_assert_eq(myLinkedListGet(linkedList, 1), 6);
    cr_assert_eq(myLinkedListGet(linkedList, 2), 1);
    cr_assert_eq(myLinkedListGet(linkedList, 3), 2);
    cr_assert_eq(myLinkedListGet(linkedList, 4), 0);
    cr_assert_eq(myLinkedListGet(linkedList, 5), 0);
    cr_assert_eq(myLinkedListGet(linkedList, 6), 4);

    // addAtHead(6) -> [6, 4, 6, 1, 2, 0, 0, 4]
    myLinkedListAddAtHead(linkedList, 6);
    cr_assert_eq(myLinkedListGet(linkedList, 0), 6);
    cr_assert_eq(myLinkedListGet(linkedList, 1), 4);
    cr_assert_eq(myLinkedListGet(linkedList, 2), 6);
    cr_assert_eq(myLinkedListGet(linkedList, 3), 1);
    cr_assert_eq(myLinkedListGet(linkedList, 4), 2);
    cr_assert_eq(myLinkedListGet(linkedList, 5), 0);
    cr_assert_eq(myLinkedListGet(linkedList, 6), 0);
    cr_assert_eq(myLinkedListGet(linkedList, 7), 4);

    // Clean up
    myLinkedListFree(linkedList);
}

// --------------------------------------------------------
// TestCase2 replicates the sequence of calls/tests from:
// ["MyLinkedList","addAtHead","addAtTail","addAtIndex","get","deleteAtIndex","get"]
// [[],[1],[3],[1,2],[1],[0],[0]]
// Expected: [null,null,null,null,2,null,2]
// --------------------------------------------------------
Test(MyLinkedList, testCase2) {
    MyLinkedList* linkedList = myLinkedListCreate();
    cr_assert_not_null(linkedList);

    // addAtHead(1) -> [1]
    myLinkedListAddAtHead(linkedList, 1);
    cr_assert_eq(myLinkedListGet(linkedList, 0), 1);

    // addAtTail(3) -> [1, 3]
    myLinkedListAddAtTail(linkedList, 3);
    cr_assert_eq(myLinkedListGet(linkedList, 0), 1);
    cr_assert_eq(myLinkedListGet(linkedList, 1), 3);

    // addAtIndex(1, 2) -> insert '2' before index 1 -> [1, 2, 3]
    myLinkedListAddAtIndex(linkedList, 1, 2);
    cr_assert_eq(myLinkedListGet(linkedList, 0), 1);
    cr_assert_eq(myLinkedListGet(linkedList, 1), 2);
    cr_assert_eq(myLinkedListGet(linkedList, 2), 3);

    // get(1) -> 2
    cr_assert_eq(myLinkedListGet(linkedList, 1), 2);

    // deleteAtIndex(0) -> delete element at index 0 (the '1') -> [2, 3]
    myLinkedListDeleteAtIndex(linkedList, 0);
    cr_assert_eq(myLinkedListGet(linkedList, 0), 2);
    cr_assert_eq(myLinkedListGet(linkedList, 1), 3);

    // get(0) -> 2
    cr_assert_eq(myLinkedListGet(linkedList, 0), 2);

    // Clean up
    myLinkedListFree(linkedList);
}
