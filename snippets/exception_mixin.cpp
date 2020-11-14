// Expect any kind of exception.
expectThrow(callable);
// Expect a specific exception.
expectThrow<MyExceptionClass>(callable);
// Expect one of a number of exceptions.
expectThrow<E0, E1, E2>(callable);

// Should not throw.
expectNoThrow(callable);