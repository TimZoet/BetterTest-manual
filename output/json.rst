JSON
====

The built-in JSON output format is a multi-file format. The :code:`bt::SuiteData` and list of :code:`bt::TestData`
objects are stored in a root `.json` file, while individual test results are stored in separate files in subfolders.

JSON is the default output format. Enabling it explicitly can be done by passing the :code:`json` value to the
:code:`--format` command line argument.

Directory Structure
-------------------

By default, all output files are placed in a subfolder named :code:`suiteName.dir` next to the executable. At the root
of the output folder, a suite file named :code:`suite.json` is created. This file contains some general information about the test suite and a list of all tests, with some additional information per test.

For each unit test, a folder with the test's name is created. Inside of this folder, each time the suite is run (and the
test is not filtered out) a file named :code:`unit_########.json` is generated. This file contains all test results. The
index is padded to 8 digits to allow easy lexicographical sorting of filenames.

As an example, running the program below several times:

.. code-block:: cpp

    class UnitTest0 : public bt::UnitTest<UnitTest0, ...> { ... };
    class UnitTest1 : public bt::UnitTest<UnitTest1, ...> { ... };

    int main(int argc, char** argv)
    {
        bt::run<UnitTest0, UnitTest1>(argc, argv, "mySuite");
    }

\.\.\. should result in the following output files:

.. code-block::

    |   suite.exe
    |
    \---mySuite.dir
        |   suite.json
        |
        +---UnitTest0
        |       unit_00000000.json
        |       unit_00000001.json
        |       unit_00000002.json
        |
        \---UnitTest1
                unit_00000000.json
                unit_00000001.json
                unit_00000002.json

Suite File
----------

The :code:`suite.json` file has the following structure:

.. code-block::

    {
        "suite":
        {
            "dateCreated": string,
            "dateLastRun": string,
            "name":        string,
            "passing":     bool,
            "runIndex":    int,
            "version":     string,
        }
        "unitTests":
        [
            {
                "dateCreated": string,
                "dateLastRun": string,
                "name":        string,
                "passing":     bool
            },
            ...
        ]
    }

Unit Test File
--------------

Each :code:`unit_#.json` file has the following structure:

.. code-block::

    {
        "compare":
        {
            "results":
            [
                {
                    "location":
                    {
                        "column": int,
                        "file":   path,
                        "line":   int
                    },
                    "status": "success" | "failure" | "exception",
                    "error":  string
                }
            ],
            "stats":
            {
                "total":     int,
                "failure":   int,
                "success":   int,
                "exception": int,
            }
        },
        "exception"
        {
            ...
        },
        ...
    }
