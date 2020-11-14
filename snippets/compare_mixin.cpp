// val == true, val == false
compareTrue(val);
compareFalse(val);

// ==, !=, <, >, <=, >=
compareEQ(lhs, rhs);
compareNE(lhs, rhs);
compareLT(lhs, rhs);
compareGT(lhs, rhs);
compareLE(lhs, rhs);
compareGE(lhs, rhs);

// lower <= val <= upper
// Boolean template params determine inclusiveness of bounds.
compareBetween<true, false>(val, lower, upper);

// abs(lhs - rhs) < abs(lhs|rhs) * fraction.
// Fraction of lhs, rhs, or max.
// Fraction/percentage/absolute value.
compareClose(lhs, rhs, 0.001);

// String comparisons.
...