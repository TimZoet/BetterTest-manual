Custom
======

To implement a new output format, you must do 3 things:

1. Create a class implementing the :code:`bt::IImporter` interface.
2. Create a class implementing the :code:`bt::IExporter` interface.
3. Register these classes in your test application.

There are no restrictions on how you can store the data. Everything can be put in a single file neatly organized in
separate files. All methods should be thread safe. BetterTest makes no effort to take care of this, leaving it up to you
entirely. The only guarantee is that the importer is constructed and destroyed before the exporter is constructed. They
will never exist at the same time.

Below follows a short description of each of the 3 steps. However, it is probably best to look at the existing output
libraries. You will see that it's not that difficult.

Importer
--------

The importer has the responsibility of reading any pre-existing suite data and test states from disk. Note that this
does not include the much more detailed test results. Import should take place in the :code:`readSuite` method.

Exporter
--------

The exporter has the responsibility of writing suite data and test results to disk. Writing the suite data is done in
the :code:`writeSuite` method, just after all tests have completed. Writing the test results is done per test through
the :code:`writeUnitTestResults` method. Other tests might still be running while a test's results are being written.

Registration
------------

Registration of a new output format is simple. Just call the :code:`bt::registerOutputFormat` function before calling
:code:`bt::run`. This function takes a template parameter for the importer and exporter type, respectively. The string
parameter is the name that can be passed to the :code:`--format` command line argument to select the desired output
format.

.. code-block:: cpp

    class MyImporter : public bt::IImporter { ... };
    class MyExporter : public bt::IExporter { ... };

    int main(...)
    {
        // Application can now be launched with --format=myFormat.
        bt::registerOutputFormat<MyImporter, MyExporter>("myFormat");

        bt::run<...>(...);
    }
