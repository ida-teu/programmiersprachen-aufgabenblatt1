#define DOCTEST_CONFIG_IMPLEMENT
#include <doctest>
#include <numbers>   
#include <cmath>     


// returns the value clamped between lower and upper bounds
int clamp(int value, int lower, int upper)
{
  if (value < lower) {
    return lower;
  }
  if (value > upper) {
    return upper;
  }
  return value;
}

// returns the largest of three integers
int max_of_three(int a, int b, int c)
{
  if (a >= b && a >= c) {
    return a;
  }
  if (b >= c) {
    return b;
  }
  return c;
}

TEST_CASE("clamp")
{
  // normal cases: value within bounds stays unchanged
  SUBCASE("value inside range is unchanged")
  {
    CHECK(clamp(5, 0, 10) == 5);
    CHECK(clamp(0, -5, 5) == 0);
  }

  // value below lower bound gets clamped up
  SUBCASE("value below range is clamped to lower bound")
  {
    CHECK(clamp(-3, 0, 10) == 0);
    CHECK(clamp(-100, -50, 50) == -50);
  }

  // value above upper bound gets clamped down
  SUBCASE("value above range is clamped to upper bound")
  {
    CHECK(clamp(15, 0, 10) == 10);
    CHECK(clamp(999, -50, 50) == 50);
  }

  // boundary cases: value exactly at the bounds
  SUBCASE("value exactly at bounds stays unchanged")
  {
    CHECK(clamp(0, 0, 10) == 0);
    CHECK(clamp(10, 0, 10) == 10);
  }

  // boundary cases: value one step outside the bounds
  SUBCASE("value just outside bounds gets clamped")
  {
    CHECK(clamp(-1, 0, 10) == 0);
    CHECK(clamp(11, 0, 10) == 10);
  }
}

TEST_CASE("max_of_three")
{
  // normal case: all values are distinct
  SUBCASE("distinct values")
  {
    CHECK(max_of_three(1, 2, 3) == 3);
    CHECK(max_of_three(3, 1, 2) == 3);
    CHECK(max_of_three(2, 3, 1) == 3);
  }

  // the maximum can appear in any argument position
  SUBCASE("maximum in each position")
  {
    CHECK(max_of_three(10, 5, 3) == 10);
    CHECK(max_of_three(5, 10, 3) == 10);
    CHECK(max_of_three(5, 3, 10) == 10);
  }

  // boundary cases: some or all values are equal
  SUBCASE("equal values")
  {
    CHECK(max_of_three(7, 7, 7) == 7);
    CHECK(max_of_three(5, 5, 3) == 5);
    CHECK(max_of_three(5, 3, 5) == 5);
    CHECK(max_of_three(3, 5, 5) == 5);
  }

  // works with negative numbers
  SUBCASE("negative values")
  {
    CHECK(max_of_three(-1, -2, -3) == -1);
    CHECK(max_of_three(-10, 0, -5) == 0);
  }
}

int main(int argc, char* argv[])
{
  doctest::Context ctx;
  ctx.applyCommandLine(argc, argv);
  return ctx.run();
}
int gcd(int a, int b)
{
    // Vorzeichen ignorieren, damit gcd(−4, 2) == 2
    a = std::abs(a);
    b = std::abs(b);
    while (b != 0) {
        int remainder = a % b;
        a = b;
        b = remainder;
    }
    return a;
}
 
TEST_CASE("describe_gcd")
{
    // Vom Aufgabenblatt vorgegebene Tests
    REQUIRE(gcd(2, 4) == 2);
    REQUIRE(gcd(9, 6) == 3);
    REQUIRE(gcd(3, 7) == 1);
 
    // Sonderfälle: einer der Werte ist 0
    REQUIRE(gcd(0, 5) == 5);
    REQUIRE(gcd(7, 0) == 7);
 
    // Negative Zahlen
    REQUIRE(gcd(-4, 2) == 2);
    REQUIRE(gcd(9, -3) == 3);
 
    // Gleiche Zahlen
    REQUIRE(gcd(6, 6) == 6);
 
    // Zufällige Normalfälle
    REQUIRE(gcd(48, 18) == 6);
    REQUIRE(gcd(100, 75) == 25);
}