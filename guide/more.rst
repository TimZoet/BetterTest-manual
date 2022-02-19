More Details
============

The name of a test is determined automatically from the class name. Any namespaces are prepended without :code:`::`. In
case you wish to explicitly specify the name, which can be useful when e.g. the class or namespace names are subject to
change, this can be done by specifying a static class member:

.. code-block:: cpp

    class UnitTest : public bt::UnitTest<UnitTest, ...>
    {
    public:
        static constexpr const char* name = "CustomName";
        ...
    };

The methods of all built-in mixin classes return an object of type :code:`CheckResult`. This object can be used to
supply extra information when a check failed or even terminate the entire test. Termination is sometimes required, for
example to prevent out-of-bounds access or dereferencing null pointers:

.. code-block:: cpp

    void UnitTest::operator()()
    {
        std::vector<float> v;
        compareNE(v.size(), 0).fatal("Vector is empty");
        compareEQ(v[0], 10);
    }
