void UnitTest::operator()()
{
    std::vector<float> v;
    compareNE(v.size(), 0).fatal("Vector is empty");
    compareEQ(v[0], 10);
}