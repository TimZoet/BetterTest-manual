Exception Mixin
===============

The :code:`bt::ExceptionMixin` class provides a number of methods to assert that code does or does not throw.

.. code-block:: cpp

    class MyUnitTest : public bt::UnitTest<MyUnitTest, bt::ExceptionMixin>
    {
    public:
        void operator()() override
        {
            std::vector<int32_t> list = {1, 2, 3};

            expectNoThrow([&]{
                list.at(0);
                list.at(1);
                list.at(2);
            });

            expectThrow([&]{
                list.at(3);
            });
        }
    };
