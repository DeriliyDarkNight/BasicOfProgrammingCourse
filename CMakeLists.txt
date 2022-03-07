cmake_minimum_required(VERSION 3.17)
project(untitled6 C)

set(CMAKE_C_STANDARD 11)

add_executable(untitled6 main.c libs/string/string_.c libs/string/string_.h)

add_library(str libs/string/string_.h libs/string/string_.c
         # string / tasks / digitToStartTransform . h
         # string / tasks / reverseWords . h
         # string / tasks / replaceDigitsBySpaces . h
         # ...
         # < файл с решением задачи >
         # ...
         # string / tasks / hasPairOfWordsWithEqualLetterSet . h
         # string / tasks / printWordsNonEqualLastWord . h
        libs/string/tasck/tascs1.h libs/string/tasck/tasks2.h libs/string/tasck/tasks3.h libs/string/tasck/task4.h libs/string/tasck/task5.h)

# описываем, что для запуска project потребуется сборка tasks
target_link_libraries (untitled6 str)

add_subdirectory(libs)
target_link_libraries(untitled6 data_structures)
target_link_libraries(untitled6 algorithms)