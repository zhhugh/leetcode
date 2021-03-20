cmake_minimum_required(VERSION 3.16)
project(leetcode)

set(CMAKE_CXX_STANDARD 14)

add_executable(leetcode main.cpp "LinkList/92_Reverse_Linked_List_II.cpp" BinarySearch/4_Median_of_Two_Sorted_Arrays.cpp BinarySearch/leetcode4Test.cpp Stack/150_Evaluate_Reverse_Polish_Notation.cpp)