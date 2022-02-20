Output
======

.. toctree::
    :maxdepth: 3
    :titlesonly:
    :hidden:

    output/json
    output/xml
    output/alexandria
    output/custom

Out of the box :code:`BetterTest` supports exporting your test results as JSON or XML. There is also experimental
support for writing to a Sqlite database using the `Alexandria`_ library. Furthermore, you can define your own classes
to support wholly different formats.

.. _Alexandria: https://github.com/TimZoet/Alexandria

If you linked your test executable to the :code:`bettertest::bettertest` target, all exporters that ship with the
package and were enabled during CMake configuration are automatically linked in. Alternatively, you could link only to
the :code:`bettertest::core` target, plus whichever format(s) you wish to use. For example, :code:`bettertest::json`. If
you don't need a format, this can help speed up compilation:

.. code-block:: cmake

    add_executable(suite main.cpp)

    find_package(bettertest REQUIRED)
    target_link_libraries(suite PUBLIC bettertest::core bettertest::json)

Suite Data
----------

The :code:`bt::SuiteData` class describes the main properties of a test suite. Below an abridged version of the class:

.. code-block:: cpp

    struct SuiteData
    {
        std::string dateCreated;
        std::string dateLastRun;
        std::string name;
        bool        passing;
        size_t      runIndex;
        std::string version;
    };

When a test suite runs for the first time, i.e. no suite file could be found in the output directory, a new
:code:`bt::SuiteData` is created. If the test suite already ran one or more times, the suite file is imported.

Unit Test Data
--------------

The :code:`bt::TestData` class describes the main properties of a single test. Naturally, a test suite can contain one
or more tests. Below an abridged version of the class:

.. code-block:: cpp

    struct TestData
    {
        std::string dateCreated;
        std::string dateLastRun;
        std::string name;
        bool        passing;
    };

When a test runs for the first time, i.e. no test with the same name could be found in the suite file, a new
:code:`bt::TestData` is created and added to the list.

Result Data
-----------

A single unit test inherits from one or more mixin classes. For each mixin, results are collected separately. All
built-in mixins generate their results in the same format.

Mixins record a list of :code:`bt::Result` objects, one for each check that was performed. A single result contains a
:code:`status` code, as well as the :code:`location` in the source code from which the call was done. In case of failure
an :code:`error` message is available. In addition to the results list, the successes and failures are aggregated in the
:code:`total`, :code:`successes`, :code:`failures` and :code:`exceptions` variables. Again, some excerpts:

.. code-block:: cpp

    enum class result_t : uint32_t
    {
        failure   = 0,
        success   = 1,
        exception = 2
    };

    struct Result
    {
        result_t             status;
        std::source_location location;
        std::string          error;
    };

    struct IMixin
    {
        size_t total      = 0;
        size_t successes  = 0;
        size_t failures   = 0;
        size_t exceptions = 0;

        std::vector<Result> results;
    };
