Compare Mixin
=============

The :code:`bt::CompareMixin` class provides a number of methods to compare (ranges of) values. It provides the usual
comparison function: equality (:code:`compareEQ`), less than (:code:`compareLT`), greater or equal (:code:`compareGE`),
near equality (:code:`compareClose`), etc.

.. code-block:: cpp

    class MyUnitTest : public bt::UnitTest<MyUnitTest, bt::CompareMixin>
    {
    public:
        void operator()() override
        {
            std::ofstream f("temp.txt");
            compareTrue(std::filesystem::exists("temp.txt"));

            std::vector<int32_t> list = {1, 2, 3};
            compareEQ(list.size(), 3);

            compareLT(list[0], list[1]);
            compareLT(list[1], list[2]);
            compareBetween(1, list[1], 3);
        }
    };
