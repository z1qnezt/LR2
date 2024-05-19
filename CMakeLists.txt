cmake_minimum_required(VERSION 3.21)
project(DecoratorPattern)

set(CMAKE_CXX_STANDARD 20)

# Настройка Google Test
enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Создание исполняемых файлов
add_executable(DecoratorPattern 
    Program.cpp 
    ConceptualExample.cpp 
    DynamicShapes.cpp 
    StaticShapes.cpp
)

add_executable(tests
    test.cpp
    # Исключаем ConceptualExample.cpp из компиляции для test.cpp
)

# Линковка библиотеки Google Test с тестовым исполняемым файлом
target_link_libraries(tests ${GTEST_LIBRARIES} pthread)

# Добавление тестов
add_test(NAME ConceptualExampleTest COMMAND tests)
