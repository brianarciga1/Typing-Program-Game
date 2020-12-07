CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(CMAKE_CXX_STANDARD 11)

ADD_SUBDIRECTORY(googletest)

ADD_EXECUTABLE(TypingTest
    main.cpp
    Composite/src/init.cpp
    Composite/src/Word.cpp
    Composite/src/Passage.cpp
    Composite/src/TypingTest.cpp
)

ADD_EXECUTABLE(test
    tests/unit_test.cpp
    Composite/src/init.cpp
    Composite/src/Word.cpp
    Composite/src/Passage.cpp
    Composite/src/TypingTest.cpp
)

TARGET_LINK_LIBRARIES(test ncurses)
TARGET_LINK_LIBRARIES(TypingTest ncurses)
TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)