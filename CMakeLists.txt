cmake_minimum_required(VERSION 3.16)
project(leetcode)

set(CMAKE_CXX_STANDARD 14)

add_executable(leetcode main.cpp "LinkList/92_Reverse_Linked_List_II.cpp" BinarySearch/4_Median_of_Two_Sorted_Arrays.cpp BinarySearch/leetcode4Test.cpp Stack/150_Evaluate_Reverse_Polish_Notation.cpp Tree/814_Binary_Tree_Pruning.cpp Tree/669_Trim_a_Binary_Search_Tree.cpp Tree/1325_Delete_Leaves_With_a_Given_Value.cpp Tree/112_Path_Sum.cpp Tree/113_Path_Sum_II.cpp Tree/437_Path_Sum_III.cpp Tree/129_Sum_Root_to_Leaf_Numbers.cpp array/73_Set_Matrix_Zeroes.cpp)