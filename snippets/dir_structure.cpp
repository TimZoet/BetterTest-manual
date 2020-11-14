class UnitTest0 : public bt::UnitTest<UnitTest0, ...> { ... };
class UnitTest1 : public bt::UnitTest<UnitTest1, ...> { ... };

int main(int argc, char** argv)
{
    bt::run<UnitTest0, UnitTest1>(argc, argv, "mySuite");
}