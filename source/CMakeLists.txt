# ---------------------------------------------------------------------------
# Executables
#   add_executable() creates a program from one or more source files.
#   The first argument is the name of the program, followed by the .cpp files.
# ---------------------------------------------------------------------------

# our main "Hello, World!" program
add_executable(helloworld helloworld.cpp)

# our test program that uses doctest to run unit tests
add_executable(tests tests.cpp)

# ---------------------------------------------------------------------------
# Register tests with ctest
#   add_test() tells CMake's test runner (ctest) about our test executable.
#   NAME   - a label shown in the test output
#   COMMAND - the executable to run
#   ctest considers a test passed if the executable returns exit code 0.
# ---------------------------------------------------------------------------
add_test(NAME doctest COMMAND tests)

# Uncomment the following lines for the flip_coin exercise
#add_executable(flip_coin flip_coin.cpp)
