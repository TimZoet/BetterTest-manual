int main()
{
    bt::registerExporter<SomeExporterClass>();
    bt::registerImporter<SomeImporterClass>();

    bt::run<...>(...);
}