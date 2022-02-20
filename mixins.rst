Mixins
======

.. toctree::
    :maxdepth: 3
    :titlesonly:
    :hidden:

    mixins/compare
    mixins/exception
    mixins/custom

All testing methods are provided through mixin classes. :code:`BetterTest` comes with a number of these classes, and
adding more yourself is easy (see :doc:`mixins/custom`).

Early Termination
-----------------

All built-in mixins return an object with an :code:`info`, :code:`warning` and :code:`fatal` method from their check
methods. If a check failed, calling these will print an error message and/or terminate without running the remainder of
the test. This is useful for providing more informative error messages. Also, if for example a nullptr check fails,
further inspection of the object it was supposed to point to can't be done and the test should just end then and there.

.. code-block:: cpp

    class MyUnitTest : public bt::UnitTest<MyUnitTest, bt::CompareMixin>
    {
    public:
        void operator()() override
        {
            // someFunc could return a nullptr instead of a valid object.
            auto* someObj = someFunc(...);
            compareNE(someObj, nullptr).fatal("someObj was null, cannot continue test.");

            // Would fail horribly if someObj were null.
            compareEQ(someObj->someVar, 10);
        }
    };

Output
------

All built-in mixins generate their results in the same format. How these results are stored on disk will depend on the
output format that is used. For that, please refer to :doc:`output`.
