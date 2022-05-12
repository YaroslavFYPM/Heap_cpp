#include "heap.h"

using namespace std;


void check_copy_constructor(Heap heap)
{
	cout << heap;
}

int main() {
    Heap *heap1 = NULL;
    Heap *heap2 = NULL;
    Heap *heap3 = NULL;

    try {
        heap1 = new Heap(-1);
    } catch (const Heap::heap_error& ex) {
        if (ex == Heap::INVALID_ARGUMENT)
            cout << "Test_0\t->\tPASSED" << endl;
        else 
            cout << "Test_0\t->\tFAILED" << endl;
    } catch (...) {
        cout << "Test_0\t->\tFAILED" << endl;
    }

    try {
        heap1 = new Heap(3);
    } catch(...) {
        cout << "Test_1\t->\tFAILED" << endl;
    }
    cout << "Test_1\t->\tPASSED" << endl;

    try {
        heap2 = new Heap();
        heap3 = new Heap();
    } catch(...) {
        cout << "Test_2\t->\tFAILED" << endl;
    }
    cout << "Test_2\t->\tPASSED" << endl;

	try {
		heap1->get_min();
	} catch (const Heap::heap_error& ex) {
		if (ex == Heap::HEAP_EMPTY)
			cout << "Test_3\t->\tPASSED" << endl;
		else
			cout << "Test_3\t->\tFAILED" << endl;
	} catch (...) {
		cout << "Test_3\t->\tFAILED" << endl;
	}

	try {
		heap1->extract_min();
	} catch (const Heap::heap_error& ex) {
		if (ex == Heap::HEAP_EMPTY)
			cout << "Test_4\t->\tPASSED" << endl;
		else
			cout << "Test_4\t->\tFAILED" << endl;
	} catch (...) {
		cout << "Test_4\t->\tFAILED" << endl;
	}

    Node node1 = {2, 2};
	try {
		heap1->add(node1);
	} catch (...) {
		cout << "Test_5\t->\tFAILED" << endl;
	}
	cout << "Test_5\t->\tPASSED" << endl;

    Node node2 = {1, 1};
	try {
		heap1->add(node2);
	} catch (...) {
		cout << "Test_6\t->\tFAILED" << endl;
	}
	cout << "Test_6\t->\tPASSED" << endl;

    Node node3 = {3, 3};
	try {
		heap1->add(node3);
	} catch (...) {
		cout << "Test_7\t->\tFAILED" << endl;
	}
	cout << "Test_7\t->\tPASSED" << endl;

    Node node4 = {4, 4};
	try {
		heap1->add(node4);
	} catch (const Heap::heap_error &ex) {
		if (ex == Heap::HEAP_OVERFLOW)
			cout << "Test_8\t->\tPASSED" << endl;
		else
			cout << "Test_8\t->\tFAILED" << endl;
	} catch (...) {
		cout << "Test_8\t->\tFAILED" << endl;
	}

	try {
		*heap2 = *heap1;
	} catch (...) {
		cout << "Test_9\t->\tFAILED" << endl;
	}
	cout << "Test_9\t->\tPASSED" << endl;

    cout << *heap1;
    cout << *heap2;

    check_copy_constructor(*heap1);
    check_copy_constructor(*heap2);

	try {
		if ((heap2->get_min().value != 1) || (heap2->get_min().key != 1))
			cout << "Test_10\t->\tFAILED" << endl;
	} catch (...) {
		cout << "Test_10\t->\tFAILED" << endl;
	}
	cout << "Test_10\t->\tPASSED" << endl;

	try {
        Node node = heap2->extract_min();
		if ((node.value != 1) || (node.key != 1))
			cout << "Test_11\t->\tFAILED" << endl;
	} catch (...) {
		cout << "Test_11\t->\tFAILED" << endl;
	}
	cout << "Test_11\t->\tPASSED" << endl;

	try {
        Node node = heap2->extract_min();
		if ((node.value != 2) || (node.key != 2))
			cout << "Test_12\t->\tFAILED" << endl;
	} catch (...) {
		cout << "Test_12\t->\tFAILED" << endl;
	}
	cout << "Test_12\t->\tPASSED" << endl;

	try {
        Node node = heap2->extract_min();
		if ((node.value != 3) || (node.key != 3))
			cout << "Test_13\t->\tFAILED" << endl;
	} catch (...) {
		cout << "Test_13\t->\tFAILED" << endl;
	}
	cout << "Test_13\t->\tPASSED" << endl;

	try {
		heap2->extract_min();
	} catch (const Heap::heap_error &ex) {
        if (ex == Heap::HEAP_EMPTY)
			cout << "Test_14\t->\tPASSED" << endl;
		else
			cout << "Test_14\t->\tFAILED" << endl;
	} catch (...) {
		cout << "Test_14\t->\tFAILED" << endl;
	}

    try {
        heap3->add({1, 1});
        heap3->add({4, 4});
        heap3->add({6, 6});
        heap3->add({3, 3});
        heap3->add({2, 2});
        heap3->add({5, 5});
        heap3->add({7, 7});
        heap3->add({8, 8});

        for (int i = 1; i < 9; ++i) {
            if (heap3->extract_min().value != i) {
                cout << "Test_15\t->\tFAILED" << endl;
                break;
            }
        } 

        if (heap3->get_size() == 0) {
            cout << "Test_15\t->\tPASSED" << endl;
        }
    } catch(...) {
        cout << "Test_15\t->\tFAILED" << endl;
    }

    delete heap1;
    delete heap2;
    delete heap3;
    return 0;
}

