#include "solution.h"
#include "uthash.h"

typedef struct {
    int value;
    UT_hash_handle hh;
} entry;

static void add(entry** map, int value) {
    entry* to_add = calloc(1, sizeof(entry));
    to_add->value = value;
    HASH_ADD_INT(*map, value, to_add);
}

static bool contains(entry** map, int value) {
    entry* e;
    HASH_FIND_INT(*map, &value, e);
    return e != NULL;
}

static void clear_map(entry** map) {
    entry* current;
    entry* tmp;
    HASH_ITER(hh, *map, current, tmp) {
        HASH_DEL(*map, current);
        free(current);
    }
}

bool checkIfExist(int* arr, int arrSize) {
    entry* map = NULL;

    for (size_t i = 0; (int) i < arrSize; ++i) {
        if (contains(&map, arr[i] * 2)) {
            clear_map(&map);
            return true;
        }
        if (arr[i] % 2 == 0) {
            if (contains(&map, arr[i] / 2)) {
                clear_map(&map);
                return true;
            }
        }

        add(&map, arr[i]);
    }

    clear_map(&map);
    return false;
}
