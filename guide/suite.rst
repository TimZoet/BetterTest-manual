Creating a Test Suite
=====================

A test suite corresponds directly to an executable. This executable should be linked to the :code:`bettertest` library:

.. code-block:: cmake

    add_executable(suite main.cpp)

    find_package(bettertest REQUIRED)
    target_link_libraries(suite PUBLIC bettertest::bettertest)

Inside of :code:`main`, a call to :code:`bt::run` will start the tests. This function takes as parameters the command
line arguments and the name of the test suite. Also needed is the list of tests that are (potentially) run. These must
be provided as template parameters:

.. code-block:: cpp

    #include "bettertest/run.h"

    int main(int argc, char** argv)
    {
        bt::run<...>(argc, argv, "myFirstTestSuite");
        return 0;
    }
