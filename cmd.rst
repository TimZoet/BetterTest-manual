Command Line Arguments
======================

:code:`BetterTest` uses the :code:`ParserTongue` library for the parsing of command line arguments. Arguments can have a
short or long name, or both. Short names consist of a single dash followed by a single character, while long names
consist of two dashes and multiple characters. Lists of values can be assigned using either an equals sign followed by
comma separated values, or whitespace separated values. Below an alphabetical listing of all arguments.


:code:`--data : string`

Suite data format. Defaults to :code:`default`.

:code:`-f --failing : flag`

Run failing tests only. Also includes new tests.

:code:`--format : string`

Output format. Defaults to :code:`json`.

:code:`-m --multithreaded : flag`

Run tests in parallel. Requires exporter to support multithreading.

:code:`-o --outdir : path`

Directory to which all output files are written. Defaults to :code:`suiteName.dir`.

:code:`-u --unit : string[]`

List of name patterns. Only unit tests whose name matches one of the patterns is run. There are 4 formats a pattern can be in:

* :code:`*test*`: name contains test.
* :code:`*test`: name ends with test.
* :code:`test*`: name starts with test.
* :code:`test`: name is exactly test.

Examples
--------

Running all unit tests that start with :code:`abc` or :code:`def`, output to XML and run in parallel:

:code:`testapp -u=abc*,def* --format=xml -m`

The same settings, just in a slightly different format:

:code:`testapp -unit abc* def* --format xml --multithreaded`
