#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest"
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
//1.8
int gcd(int a, int b)
{
    
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
    
    REQUIRE(gcd(2, 4) == 2);
    REQUIRE(gcd(9, 6) == 3);
    REQUIRE(gcd(3, 7) == 1);
 
    
    REQUIRE(gcd(0, 5) == 5);
    REQUIRE(gcd(7, 0) == 7);
 
    
    REQUIRE(gcd(-4, 2) == 2);
    REQUIRE(gcd(9, -3) == 3);
 
    
    REQUIRE(gcd(6, 6) == 6);
 
    
    REQUIRE(gcd(48, 18) == 6);
    REQUIRE(gcd(100, 75) == 25);
}
//1.9
float fract(float x)
{
    
    return x - static_cast<float>(static_cast<int>(x));
}
 
TEST_CASE("describe_fract")
{
    
    REQUIRE(fract(7.24f) == doctest::Approx(0.24f).epsilon(0.001f));
 
    
    REQUIRE(fract(3.0f) == doctest::Approx(0.0f).epsilon(0.001f));
 
    
    REQUIRE(fract(0.5f) == doctest::Approx(0.5f).epsilon(0.001f));
 
    
    REQUIRE(fract(-2.75f) == doctest::Approx(-0.75f).epsilon(0.001f));
 
    
    REQUIRE(fract(1.1f)  == doctest::Approx(0.1f).epsilon(0.001f));
    REQUIRE(fract(99.9f) == doctest::Approx(0.9f).epsilon(0.001f));
}
//1.10
double cylinder_volume(double radius, double height)
{
    return std::numbers::pi * radius * radius * height;
}
 
double cylinder_surface(double radius, double height)
{
    return 2.0 * std::numbers::pi * radius * (radius + height);
}
 
TEST_CASE("describe_cylinder")
{
    
    REQUIRE(cylinder_volume(1.0, 1.0)  == doctest::Approx(3.14159265).epsilon(0.0001));
    REQUIRE(cylinder_surface(1.0, 1.0) == doctest::Approx(12.5663706).epsilon(0.0001));
 
    
    REQUIRE(cylinder_volume(3.0, 0.0)  == doctest::Approx(0.0).epsilon(0.0001));
    REQUIRE(cylinder_surface(3.0, 0.0) == doctest::Approx(2.0 * std::numbers::pi * 9.0).epsilon(0.0001));
 
    
    REQUIRE(cylinder_volume(0.0, 5.0)  == doctest::Approx(0.0).epsilon(0.0001));
    REQUIRE(cylinder_surface(0.0, 5.0) == doctest::Approx(0.0).epsilon(0.0001));
 
    
    REQUIRE(cylinder_volume(2.0, 5.0)  == doctest::Approx(62.8318530).epsilon(0.0001));
    REQUIRE(cylinder_surface(2.0, 5.0) == doctest::Approx(87.9645943).epsilon(0.0001));
}
//1.11
bool is_prime(int n)
{
    if (n <= 1) {
        return false;   
    }
    if (n <= 3) {
        return true;    
    }
    if (n % 2 == 0) {
        return false;   
    }
    
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}
 
TEST_CASE("describe_is_prime")
{
    
    REQUIRE(is_prime(0)  == false);
    REQUIRE(is_prime(1)  == false);
    REQUIRE(is_prime(-7) == false);
 
    
    REQUIRE(is_prime(2)  == true);
    REQUIRE(is_prime(3)  == true);
 
    
    REQUIRE(is_prime(4)  == false);
    REQUIRE(is_prime(100) == false);
 
    
    REQUIRE(is_prime(5)  == true);
    REQUIRE(is_prime(6)  == false);
 
    
    REQUIRE(is_prime(7)   == true);
    REQUIRE(is_prime(11)  == true);
    REQUIRE(is_prime(13)  == true);
    REQUIRE(is_prime(97)  == true);
    REQUIRE(is_prime(101) == true);
 
    
    REQUIRE(is_prime(9)   == false); 
    REQUIRE(is_prime(15)  == false); 
    REQUIRE(is_prime(49)  == false); 
    REQUIRE(is_prime(91)  == false); 
}
int main(int argc, char* argv[])
{
    doctest::Context ctx;
    ctx.applyCommandLine(argc, argv);
    return ctx.run();

}