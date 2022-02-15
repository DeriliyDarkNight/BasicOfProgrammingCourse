add_library(data_structures
        bitset/bitset.c unordered_array_set/unordered_array_set.c vector/vector.c vector/vector.h matrix/matrix.c matrix/matrix.h)

target_link_libraries (data_structures algorithms)