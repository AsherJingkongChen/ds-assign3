# Data Structure course - assign3

### [Home page](https://github.com/AsherJingkongChen/ds-assign3)

### Internal libraries

- Array of sorted arrays: Myself, advised from [my data structure teacher](https://ah.nccu.edu.tw/scholar?id=7326&locale=en-US)

### External libraries

- B-Tree: GitHub, forked from [Kronuz/cpp-btree](https://github.com/Kronuz/cpp-btree) to [AsherJingkongChen/cpp-btree](https://github.com/AsherJingkongChen/cpp-btree)
  - class name: `btree::set`
  - test file name: `btree`

- Hash Table: GNU libstdc++: [documentation](https://gcc.gnu.org/onlinedocs/gcc-12.2.0/libstdc++/api/a08942.html)
  - class name: `std::unordered_set`
  - test file name: `hashtable`

- Skip List: GitHub, forked from [razmikTovmas/skip_list](https://github.com/razmikTovmas/skip_list) to [AsherJingkongChen/skip_list](https://github.com/AsherJingkongChen/skip_list)
  - class name: `skip_list::skip_list`
  - test file name: `skiplist`

- Treap: GitHub, forked from [ruofeidu/DuAlgorithm](https://github.com/ruofeidu/DuAlgorithm) to [AsherJingkongChen/DuAlgorithm](https://github.com/AsherJingkongChen/DuAlgorithm)
  - class name: `Treap`
  - test file name: `treap`

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
|   |-- skiplist.cpp
|   `-- treap.cpp
|-- img/
|-- log/
|   |-- build.sh.log
|   |-- run.sh.log
|   `-- summary.sh.log
|-- onepass.sh*
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
|           `-- summary.csv
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
        `-- plot_summary.cpp

15 directories, 46 files
 105K used in 15 directories, 46 files

```

### File structure (only third-party)

```
third-party/
|-- BTree/
|   |-- LICENSE
|   |-- README.md
|   `-- btree/
|       |-- btree.h
|       |-- map.h
|       `-- set.h
|-- Skiplist/
|   |-- CMakeLists.txt
|   |-- Doxyfile
|   |-- LICENSE
|   |-- README.md
|   |-- build/
|   |-- examples/
|   |   |-- CMakeLists.txt
|   |   `-- Example.cxx
|   `-- include/
|       |-- _skip_list.hpp
|       |-- internal/
|       |   |-- _sl_impl.hpp
|       |   `-- sl_impl.hpp
|       `-- skip_list.hpp
`-- Treap/
    |-- Bash/
    |   |-- 10th_line.sh
    |   |-- gifit.sh
    |   |-- git.sh
    |   |-- transpose_file.sh
    |   |-- valid_phone_number.sh
    |   `-- word_frequency.sh
    |-- Cmd/
    |   `-- PictureViewer.reg
    |-- Cpp/
    |   |-- ArrayInPlace.h
    |   |-- BST.out
    |   |-- BinaryTreeMisc.h
    |   |-- BinaryTreeOrders.h
    |   |-- BitsManipulation.h
    |   |-- CIO.h
    |   |-- Cpp.sln
    |   |-- Cpp.vcxproj
    |   |-- Cpp.vcxproj.filters
    |   |-- CppOO.h
    |   |-- DPCounts.h
    |   |-- DPEditDistance.h
    |   |-- DPKnapsack.h
    |   |-- DPLCS.h
    |   |-- DPLIS.h
    |   |-- DPLinear.h
    |   |-- DPNumbers.h
    |   |-- DPStock.h
    |   |-- DPTree.h
    |   |-- DuConfig.cpp
    |   |-- DuConfig.h
    |   |-- DuTimer.cpp
    |   |-- DuTimer.h
    |   |-- DuUtils.cpp
    |   |-- DuUtils.h
    |   |-- GameGo.h
    |   |-- GameNQueen.h
    |   |-- GameNim.h
    |   |-- GameRock.h
    |   |-- GameSudoku.h
    |   |-- GameTheory.h
    |   |-- GameTicTacToe.h
    |   |-- Geo3D.h
    |   |-- GeoLines.h
    |   |-- GeoPoints.h
    |   |-- GeoPolygons.h
    |   |-- GeoRect.h
    |   |-- GraphBipartite.h
    |   |-- GraphDijkstra.h
    |   |-- GraphFloyd.h
    |   |-- GraphKruskal.h
    |   |-- GraphMisc.h
    |   |-- GraphNetworkFlow.h
    |   |-- GraphPrim.h
    |   |-- GraphTopologicalSort.h
    |   |-- Grids.h
    |   |-- GridsInPlace.h
    |   |-- HPMisc.h
    |   |-- HashCustomized.h
    |   |-- HashSets.h
    |   |-- Heaps.h
    |   |-- Intervals.h
    |   |-- LCA.h
    |   |-- LFUCache.h
    |   |-- LRUCache.h
    |   |-- LinkedLists.h
    |   |-- MathCount.h
    |   |-- MathDeduction.h
    |   |-- MathMatrix.h
    |   |-- MathMisc.h
    |   |-- MathMods.h
    |   |-- MathNumbers.h
    |   |-- MathPermutation.h
    |   |-- MathPrime.h
    |   |-- MathRandom.h
    |   |-- MathSampling.h
    |   |-- Octree.h
    |   |-- PatternAbstractFactory.h
    |   |-- PatternFactory.h
    |   |-- PatternRAII.h
    |   |-- PatternSingleton.h
    |   |-- PointIntervalTree.h
    |   |-- QuadTrees.h
    |   |-- RMQ.h
    |   |-- RedBlackTree.h
    |   |-- STLAlgorithms.h
    |   |-- STLLinear.h
    |   |-- STLSort.h
    |   |-- Scanning.h
    |   |-- SearchBBFS.h
    |   |-- SearchBFS.h
    |   |-- SearchBinary.h
    |   |-- SearchDFS.h
    |   |-- SearchGrid.h
    |   |-- SegmentTreeX2.h
    |   |-- SegmentTrees.h
    |   |-- SharedPointers.h
    |   |-- SimulationNum2Word.h
    |   |-- SortBubble.h
    |   |-- SortBucket.h
    |   |-- SortCount.h
    |   |-- SortInsert.h
    |   |-- SortMerge.h
    |   |-- SortMisc.h
    |   |-- SortQuick.h
    |   |-- SortTiny.h
    |   |-- StringCTricks.h
    |   |-- StringKMP.h
    |   |-- StringMisc.h
    |   |-- StringRabinKarp.h
    |   |-- StringSTL.h
    |   |-- StringSuffixArrays.h
    |   |-- Treaps.h
    |   |-- Tries.h
    |   |-- Twitter.h
    |   |-- UnionSets.h
    |   |-- bigint.h
    |   |-- binarysearchtrees.h
    |   |-- common.h
    |   |-- cpp11.h
    |   |-- cpp14.h
    |   |-- cpp17.h
    |   |-- cppwired.h
    |   |-- dirent.h
    |   |-- dpgrid.h
    |   |-- fraction.h
    |   |-- glm/
    |   |   |-- CMakeLists.txt
    |   |   |-- common.hpp
    |   |   |-- detail/
    |   |   |   |-- _features.hpp
    |   |   |   |-- _fixes.hpp
    |   |   |   |-- _noise.hpp
    |   |   |   |-- _swizzle.hpp
    |   |   |   |-- _swizzle_func.hpp
    |   |   |   |-- _vectorize.hpp
    |   |   |   |-- dummy.cpp
    |   |   |   |-- func_common.hpp
    |   |   |   |-- func_common.inl
    |   |   |   |-- func_common_simd.inl
    |   |   |   |-- func_exponential.hpp
    |   |   |   |-- func_exponential.inl
    |   |   |   |-- func_exponential_simd.inl
    |   |   |   |-- func_geometric.hpp
    |   |   |   |-- func_geometric.inl
    |   |   |   |-- func_geometric_simd.inl
    |   |   |   |-- func_integer.hpp
    |   |   |   |-- func_integer.inl
    |   |   |   |-- func_integer_simd.inl
    |   |   |   |-- func_matrix.hpp
    |   |   |   |-- func_matrix.inl
    |   |   |   |-- func_matrix_simd.inl
    |   |   |   |-- func_packing.hpp
    |   |   |   |-- func_packing.inl
    |   |   |   |-- func_packing_simd.inl
    |   |   |   |-- func_trigonometric.hpp
    |   |   |   |-- func_trigonometric.inl
    |   |   |   |-- func_trigonometric_simd.inl
    |   |   |   |-- func_vector_relational.hpp
    |   |   |   |-- func_vector_relational.inl
    |   |   |   |-- func_vector_relational_simd.inl
    |   |   |   |-- glm.cpp
    |   |   |   |-- precision.hpp
    |   |   |   |-- setup.hpp
    |   |   |   |-- type_float.hpp
    |   |   |   |-- type_gentype.hpp
    |   |   |   |-- type_gentype.inl
    |   |   |   |-- type_half.hpp
    |   |   |   |-- type_half.inl
    |   |   |   |-- type_int.hpp
    |   |   |   |-- type_mat.hpp
    |   |   |   |-- type_mat.inl
    |   |   |   |-- type_mat2x2.hpp
    |   |   |   |-- type_mat2x2.inl
    |   |   |   |-- type_mat2x3.hpp
    |   |   |   |-- type_mat2x3.inl
    |   |   |   |-- type_mat2x4.hpp
    |   |   |   |-- type_mat2x4.inl
    |   |   |   |-- type_mat3x2.hpp
    |   |   |   |-- type_mat3x2.inl
    |   |   |   |-- type_mat3x3.hpp
    |   |   |   |-- type_mat3x3.inl
    |   |   |   |-- type_mat3x4.hpp
    |   |   |   |-- type_mat3x4.inl
    |   |   |   |-- type_mat4x2.hpp
    |   |   |   |-- type_mat4x2.inl
    |   |   |   |-- type_mat4x3.hpp
    |   |   |   |-- type_mat4x3.inl
    |   |   |   |-- type_mat4x4.hpp
    |   |   |   |-- type_mat4x4.inl
    |   |   |   |-- type_mat4x4_simd.inl
    |   |   |   |-- type_vec.hpp
    |   |   |   |-- type_vec.inl
    |   |   |   |-- type_vec1.hpp
    |   |   |   |-- type_vec1.inl
    |   |   |   |-- type_vec2.hpp
    |   |   |   |-- type_vec2.inl
    |   |   |   |-- type_vec3.hpp
    |   |   |   |-- type_vec3.inl
    |   |   |   |-- type_vec4.hpp
    |   |   |   |-- type_vec4.inl
    |   |   |   `-- type_vec4_simd.inl
    |   |   |-- exponential.hpp
    |   |   |-- ext.hpp
    |   |   |-- fwd.hpp
    |   |   |-- geometric.hpp
    |   |   |-- glm.hpp
    |   |   |-- gtc/
    |   |   |   |-- bitfield.hpp
    |   |   |   |-- bitfield.inl
    |   |   |   |-- color_encoding.inl
    |   |   |   |-- color_space.hpp
    |   |   |   |-- color_space.inl
    |   |   |   |-- constants.hpp
    |   |   |   |-- constants.inl
    |   |   |   |-- epsilon.hpp
    |   |   |   |-- epsilon.inl
    |   |   |   |-- functions.hpp
    |   |   |   |-- functions.inl
    |   |   |   |-- integer.hpp
    |   |   |   |-- integer.inl
    |   |   |   |-- matrix_access.hpp
    |   |   |   |-- matrix_access.inl
    |   |   |   |-- matrix_integer.hpp
    |   |   |   |-- matrix_inverse.hpp
    |   |   |   |-- matrix_inverse.inl
    |   |   |   |-- matrix_transform.hpp
    |   |   |   |-- matrix_transform.inl
    |   |   |   |-- noise.hpp
    |   |   |   |-- noise.inl
    |   |   |   |-- packing.hpp
    |   |   |   |-- packing.inl
    |   |   |   |-- quaternion.hpp
    |   |   |   |-- quaternion.inl
    |   |   |   |-- quaternion_simd.inl
    |   |   |   |-- random.hpp
    |   |   |   |-- random.inl
    |   |   |   |-- reciprocal.hpp
    |   |   |   |-- reciprocal.inl
    |   |   |   |-- round.hpp
    |   |   |   |-- round.inl
    |   |   |   |-- type_aligned.hpp
    |   |   |   |-- type_precision.hpp
    |   |   |   |-- type_precision.inl
    |   |   |   |-- type_ptr.hpp
    |   |   |   |-- type_ptr.inl
    |   |   |   |-- ulp.hpp
    |   |   |   |-- ulp.inl
    |   |   |   |-- vec1.hpp
    |   |   |   `-- vec1.inl
    |   |   |-- gtx/
    |   |   |   |-- associated_min_max.hpp
    |   |   |   |-- associated_min_max.inl
    |   |   |   |-- bit.hpp
    |   |   |   |-- bit.inl
    |   |   |   |-- closest_point.hpp
    |   |   |   |-- closest_point.inl
    |   |   |   |-- color_space.hpp
    |   |   |   |-- color_space.inl
    |   |   |   |-- color_space_YCoCg.hpp
    |   |   |   |-- color_space_YCoCg.inl
    |   |   |   |-- common.hpp
    |   |   |   |-- common.inl
    |   |   |   |-- compatibility.hpp
    |   |   |   |-- compatibility.inl
    |   |   |   |-- component_wise.hpp
    |   |   |   |-- component_wise.inl
    |   |   |   |-- dual_quaternion.hpp
    |   |   |   |-- dual_quaternion.inl
    |   |   |   |-- euler_angles.hpp
    |   |   |   |-- euler_angles.inl
    |   |   |   |-- extend.hpp
    |   |   |   |-- extend.inl
    |   |   |   |-- extended_min_max.hpp
    |   |   |   |-- extended_min_max.inl
    |   |   |   |-- fast_exponential.hpp
    |   |   |   |-- fast_exponential.inl
    |   |   |   |-- fast_square_root.hpp
    |   |   |   |-- fast_square_root.inl
    |   |   |   |-- fast_trigonometry.hpp
    |   |   |   |-- fast_trigonometry.inl
    |   |   |   |-- float_notmalize.inl
    |   |   |   |-- gradient_paint.hpp
    |   |   |   |-- gradient_paint.inl
    |   |   |   |-- handed_coordinate_space.hpp
    |   |   |   |-- handed_coordinate_space.inl
    |   |   |   |-- hash.hpp
    |   |   |   |-- hash.inl
    |   |   |   |-- integer.hpp
    |   |   |   |-- integer.inl
    |   |   |   |-- intersect.hpp
    |   |   |   |-- intersect.inl
    |   |   |   |-- io.hpp
    |   |   |   |-- io.inl
    |   |   |   |-- log_base.hpp
    |   |   |   |-- log_base.inl
    |   |   |   |-- matrix_cross_product.hpp
    |   |   |   |-- matrix_cross_product.inl
    |   |   |   |-- matrix_decompose.hpp
    |   |   |   |-- matrix_decompose.inl
    |   |   |   |-- matrix_interpolation.hpp
    |   |   |   |-- matrix_interpolation.inl
    |   |   |   |-- matrix_major_storage.hpp
    |   |   |   |-- matrix_major_storage.inl
    |   |   |   |-- matrix_operation.hpp
    |   |   |   |-- matrix_operation.inl
    |   |   |   |-- matrix_query.hpp
    |   |   |   |-- matrix_query.inl
    |   |   |   |-- matrix_transform_2d.hpp
    |   |   |   |-- matrix_transform_2d.inl
    |   |   |   |-- mixed_product.hpp
    |   |   |   |-- mixed_product.inl
    |   |   |   |-- norm.hpp
    |   |   |   |-- norm.inl
    |   |   |   |-- normal.hpp
    |   |   |   |-- normal.inl
    |   |   |   |-- normalize_dot.hpp
    |   |   |   |-- normalize_dot.inl
    |   |   |   |-- number_precision.hpp
    |   |   |   |-- number_precision.inl
    |   |   |   |-- optimum_pow.hpp
    |   |   |   |-- optimum_pow.inl
    |   |   |   |-- orthonormalize.hpp
    |   |   |   |-- orthonormalize.inl
    |   |   |   |-- perpendicular.hpp
    |   |   |   |-- perpendicular.inl
    |   |   |   |-- polar_coordinates.hpp
    |   |   |   |-- polar_coordinates.inl
    |   |   |   |-- projection.hpp
    |   |   |   |-- projection.inl
    |   |   |   |-- quaternion.hpp
    |   |   |   |-- quaternion.inl
    |   |   |   |-- range.hpp
    |   |   |   |-- raw_data.hpp
    |   |   |   |-- raw_data.inl
    |   |   |   |-- rotate_normalized_axis.hpp
    |   |   |   |-- rotate_normalized_axis.inl
    |   |   |   |-- rotate_vector.hpp
    |   |   |   |-- rotate_vector.inl
    |   |   |   |-- scalar_multiplication.hpp
    |   |   |   |-- scalar_relational.hpp
    |   |   |   |-- scalar_relational.inl
    |   |   |   |-- spline.hpp
    |   |   |   |-- spline.inl
    |   |   |   |-- std_based_type.hpp
    |   |   |   |-- std_based_type.inl
    |   |   |   |-- string_cast.hpp
    |   |   |   |-- string_cast.inl
    |   |   |   |-- transform.hpp
    |   |   |   |-- transform.inl
    |   |   |   |-- transform2.hpp
    |   |   |   |-- transform2.inl
    |   |   |   |-- type_aligned.hpp
    |   |   |   |-- type_aligned.inl
    |   |   |   |-- type_trait.hpp
    |   |   |   |-- type_trait.inl
    |   |   |   |-- vector_angle.hpp
    |   |   |   |-- vector_angle.inl
    |   |   |   |-- vector_query.hpp
    |   |   |   |-- vector_query.inl
    |   |   |   |-- wrap.hpp
    |   |   |   `-- wrap.inl
    |   |   |-- integer.hpp
    |   |   |-- mat2x2.hpp
    |   |   |-- mat2x3.hpp
    |   |   |-- mat2x4.hpp
    |   |   |-- mat3x2.hpp
    |   |   |-- mat3x3.hpp
    |   |   |-- mat3x4.hpp
    |   |   |-- mat4x2.hpp
    |   |   |-- mat4x3.hpp
    |   |   |-- mat4x4.hpp
    |   |   |-- matrix.hpp
    |   |   |-- packing.hpp
    |   |   |-- simd/
    |   |   |   |-- common.h
    |   |   |   |-- exponential.h
    |   |   |   |-- geometric.h
    |   |   |   |-- integer.h
    |   |   |   |-- matrix.h
    |   |   |   |-- packing.h
    |   |   |   |-- platform.h
    |   |   |   |-- trigonometric.h
    |   |   |   `-- vector_relational.h
    |   |   |-- trigonometric.hpp
    |   |   |-- vec2.hpp
    |   |   |-- vec3.hpp
    |   |   |-- vec4.hpp
    |   |   `-- vector_relational.hpp
    |   |-- greedy.h
    |   |-- hashmaps.h
    |   |-- main.cpp
    |   |-- multisets.h
    |   |-- palindrome.h
    |   |-- queues.h
    |   |-- rsq.h
    |   |-- stacks.h
    |   |-- stringtricks.h
    |   `-- times.h
    |-- JavaScript/
    |   |-- MersenneTwister.js
    |   |-- UnionSets.js
    |   |-- es6_arrow_function.js
    |   |-- es6_map_reduce.js
    |   |-- es6_object_oriented.js
    |   `-- regexp.js
    |-- Matlab/
    |   |-- affine_transformation.m
    |   |-- blend_dist.m
    |   |-- blend_map.m
    |   |-- colorIndentify.m
    |   |-- computeFeature.m
    |   |-- display_sift_features.m
    |   |-- do_test.m
    |   |-- edge_detector.m
    |   |-- edge_detector_advanced.m
    |   |-- em.m
    |   |-- emtest.m
    |   |-- emtest_total.m
    |   |-- encoding.m
    |   |-- energy.m
    |   |-- expansion.m
    |   |-- find_best_match.m
    |   |-- find_matches.m
    |   |-- find_matches_rgb.m
    |   |-- gauss.m
    |   |-- getVocab.m
    |   |-- get_ssd_slow.m
    |   |-- get_unfilled_neighbors.m
    |   |-- gothrough.m
    |   |-- gradient_magnitude_direction.m
    |   |-- image_gradient.m
    |   |-- init_filter_bank.m
    |   |-- init_stereo.m
    |   |-- initialize.m
    |   |-- interpolate_gradients.m
    |   |-- kmeans.m
    |   |-- lab2rgb.m
    |   |-- line_fitting.m
    |   |-- line_fitting_total.m
    |   |-- line_fitting_w.m
    |   |-- mosaic.m
    |   |-- p1.m
    |   |-- p2.m
    |   |-- potts_cost.m
    |   |-- ps3.m
    |   |-- ps5.m
    |   |-- random_pick.m
    |   |-- ransac.m
    |   |-- readdata.m
    |   |-- show_3_best.m
    |   |-- smooth_image.m
    |   |-- stereo.m
    |   |-- stitch.m
    |   |-- stitch_average.m
    |   |-- stitch_blend.m
    |   |-- swap.m
    |   |-- test.m
    |   |-- test_gradient_magnitude_direction.m
    |   |-- test_image_gradient.m
    |   |-- test_normalized_cut_points.m
    |   |-- test_smooth_image.m
    |   |-- texture_synth.m
    |   |-- trainSVM.m
    |   |-- translate100.m
    |   |-- trs.m
    |   `-- unary_cost.m
    |-- OpenCppSolution.cmd
    |-- PHP/
    |   `-- wordpress.php
    |-- Python/
    |   |-- BinaryTree.py
    |   |-- Games.py
    |   |-- GeoRect.py
    |   |-- GraphBipartite.py
    |   |-- GraphDijkstra.py
    |   |-- GraphFloyd.py
    |   |-- GraphMisc.py
    |   |-- GraphPrim.py
    |   |-- GraphTopologicalSort.py
    |   |-- HashMap.py
    |   |-- HashSet.py
    |   |-- LinkedList.py
    |   |-- MathNumbers.py
    |   |-- Palindrome.py
    |   |-- PythonOS.py
    |   |-- PythonSyntax.py
    |   |-- Queues.py
    |   |-- Scanning.py
    |   |-- SearchBFS.py
    |   |-- SearchBinary.py
    |   |-- SearchDFS.py
    |   |-- SortBubble.py
    |   |-- SortBucket.py
    |   |-- SortMerge.py
    |   |-- SortQuick.py
    |   |-- StringMisc.py
    |   |-- Treap.py
    |   |-- Trie.h.py
    |   `-- smir.txt
    |-- README.md
    |-- SQL/
    |   |-- Joins.sql
    |   |-- Select.sql
    |   `-- Sort.sql
    `-- Writing/
        `-- WritingTips.md

22 directories, 508 files
 2.4M used in 22 directories, 508 files

```
