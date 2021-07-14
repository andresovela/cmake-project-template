# C project template with CMake

## Testing

- Make a copy of `tests/example/` for the new module to test.
- Rename `test_example.c` to `test_{module_name}.c`.
- Delete `test_example_runner.c`.
- Execute `ruby external/unity/auto/generate_test_runner.rb tests/{module}/test_{module}.c tests/{module}/test_{module}._runner.c` to create a new runner for your tests.
