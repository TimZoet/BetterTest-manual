A First Test
============

To create a new test, we must define a class deriving from :code:`bt::UnitTest`. This base class takes at least one
template parameter, namely the deriving class. Additionally we can pass any number of mixin classes. These mixin classes
provide the actual testing methods. In this example, we're going to use just the :code:`CompareMixin` class.

Tests are invoked through :code:`operator()`, so we have to override it. Inside of the function we're going to call 3 of
the methods provided by :code:`bt::CompareMixin` to perform the following comparisons: :code:`42 == 42`,
:code:`10 <= 20` and :code:`0 <= 200 <= 100`. Obviously, that last check will fail:

.. code-block:: cpp

    #include "bettertest/mixins/compare_mixin.h"
    #include "bettertest/tests/unit_test.h"

    class UnitTest01 : public bt::UnitTest<UnitTest01, 
                                           bt::CompareMixin>
    {
    public:
        void operator()() override
        {
            compareEQ(42, 42);
            compareLT(10, 20);
            compareBetween(0, 200, 100);
        }
    };

With that done, add the class to :code:`bt::run`:

.. code-block:: cpp

    int main(int argc, char** argv)
    {
        bt::run<UnitTest01>(argc, argv, "myFirstTestSuite");
        return 0;
    }

Multithreading
--------------

By default, it is assumed that each unit test can be run in parallel. Should that not be the case, for example because
multiple tests need exclusive access to the same resource, you can add a static member :code:`isParallel` to the class
definition. When the test suite is run in multithreaded mode, the tests that do not support this will run serially.

.. code-block:: cpp

    class UnitTest01 : public bt::UnitTest<UnitTest01, 
                                           bt::CompareMixin>
    {
    public:
        static constexpr bool isParallel = false;
    };
