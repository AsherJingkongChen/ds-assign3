# Data Structure course - assign3

### [Home page](https://github.com/AsherJingkongChen/ds-assign3)

### Prerequisites

- GNU C++ Compiler
- timeout command (or GNU gtimeout)
- Python 3
- Matplotlib for python

### Internal libraries

- Array of sorted arrays: Myself, advised from [my data structure teacher](https://ah.nccu.edu.tw/scholar?id=7326&locale=en-US)
  - test file name: `test/*/array_of_sorted_arrays.cpp`
  - source file name: `src/array_of_sorted_arrays.cpp`

- general: Myself
  - test file name: `test/general/general.hpp`

- shell scripts: Myself

### External libraries

- B-Tree: GitHub, forked from [Kronuz/cpp-btree](https://github.com/Kronuz/cpp-btree) to [AsherJingkongChen/cpp-btree](https://github.com/AsherJingkongChen/cpp-btree)
  - class name: `btree::set`
  - test file name: `test/*/btree.cpp`

- Hash Table: GNU libstdc++: [documentation](https://gcc.gnu.org/onlinedocs/gcc-12.2.0/libstdc++/api/a08942.html)
  - class name: `std::unordered_set`
  - test file name: `test/*/hashtable.cpp`

- Skip List: GitHub, forked from [razmikTovmas/skip_list](https://github.com/razmikTovmas/skip_list) to [AsherJingkongChen/skip_list](https://github.com/AsherJingkongChen/skip_list)
  - class name: `skip_list::skip_list`
  - test file name: `test/*/skiplist.cpp`

- Treap: GitHub, forked from [ruofeidu/DuAlgorithm](https://github.com/ruofeidu/DuAlgorithm) to [AsherJingkongChen/DuAlgorithm](https://github.com/AsherJingkongChen/DuAlgorithm)
  - class name: `Treap`
  - test file name: `test/*/treap.cpp`

### File structure (excluding third-party)

```
./
|-- README.md
|-- build.sh*
|-- clear.sh*
|-- config.sh*
|-- doc/
|   `-- HW3_2022.docx
|-- example/
|   |-- array_of_sorted_arrays.cpp
|   |-- btree.cpp
|   |-- hashtable.cpp
|   |-- hashtable_rehash.cpp
|   |-- skiplist.cpp
|   `-- treap.cpp
|-- misc/
|   |-- cache_miss_rate_insert_18.log
|   |-- cache_miss_rate_search_18.log
|   |-- example_workflow.log
|   |-- hashtable_rehash.log
|   |-- insert_peak_memory.log
|   |-- skiplist_10.log
|   `-- skiplist_20.log
|-- output/
|   `-- test/
|       |-- insert/
|       |   |-- array_of_sorted_arrays.log
|       |   |-- btree.log
|       |   |-- hashtable.log
|       |   |-- skiplist.log
|       |   `-- treap.log
|       |-- search/
|       |   |-- array_of_sorted_arrays.log
|       |   |-- btree.log
|       |   |-- hashtable.log
|       |   |-- skiplist.log
|       |   `-- treap.log
|       `-- summary/
|           |-- insert_large.png
|           |-- insert_small.png
|           |-- prediction_insert.csv
|           |-- prediction_search.csv
|           |-- search_large.png
|           |-- search_small.png
|           `-- summary.csv
|-- res/
|   |-- insert_large.png
|   |-- insert_small.png
|   |-- insert_yscale_linear.png
|   |-- prediction_insert.csv
|   |-- prediction_search.csv
|   |-- search_large.png
|   |-- search_small.png
|   |-- search_yscale_linear.png
|   `-- summary.csv
|-- run.sh*
|-- src/
|   |-- array_of_sorted_arrays.hpp
|   `-- sorted_array.hpp
|-- summary.sh*
`-- test/
    |-- general/
    |   |-- check_main.hpp
    |   |-- conversion_for_2_power_of.hpp
    |   |-- csv_row.hpp
    |   |-- general.hpp
    |   |-- timer.hpp
    |   `-- uniform_random_number_generator.hpp
    |-- insert/
    |   |-- array_of_sorted_arrays.cpp
    |   |-- btree.cpp
    |   |-- hashtable.cpp
    |   |-- skiplist.cpp
    |   `-- treap.cpp
    |-- search/
    |   |-- array_of_sorted_arrays.cpp
    |   |-- btree.cpp
    |   |-- hashtable.cpp
    |   |-- skiplist.cpp
    |   `-- treap.cpp
    `-- summary/
        `-- plot_summary.py

15 directories, 65 files
 2.1M used in 15 directories, 65 files
```

### File structure (only used files from third-party)

```
third-party/
|-- BTree/
|   `-- btree/
|       `-- set.h
|-- Skiplist/
|   `-- include/
|       |-- internal/
|       |   `-- sl_impl.hpp
|       `-- skip_list.hpp
`-- Treap/
    `-- Cpp/
        `-- Treaps.h
```