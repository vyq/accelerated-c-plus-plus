# accelerated-c-plus-plus
Learn C++

# exercises

- 0-1: `3 + 4;` evaluates to 7 and has no side effects
- 0-5: It is not a valid program as `main()` is not enclosed in braces
- 0-6: It is a valid program as `main()` is enclosed in matching braces
- 0-7: It is a valid program as the comment delimiters are correct
- 0-8: It is a valid program as the comment syntax is correct
- 0-9: `int main() {}` is the shortest valid program
- 1-1: The definitions are valid as `hello` is defined before it is used by `message`
- 1-2: The definitions are valid as `exclam` is defined before it is used by `message`
- 1-3: It is a valid program that outputs:
  ```
  a string
  another string
  ```
- 1-4: It is a valid program, regardless of changing `}}` to `};}`
- 1-5: It is not a valid program as `x` in `std::cout << x << std::endl;` is not defined
- 1-6: It stores the second name in the buffer, assigns it to `name` when `std::cin >> name` is executed again, and prints the second name to standard output
- 2-6: The code outputs:
  ```
  1
  2
  3
  4
  5
  6
  7
  8
  9
  10
  ```
- 2-10: `std::` specifies that the `cout` object and `endl` function are referenced from the [C++ Standard Library](https://en.wikipedia.org/wiki/C%2B%2B_Standard_Library)
- 3-1: All values in an ordered range are required for computing the [median](https://en.wikipedia.org/wiki/Median). If we discard a value before reading all values, the median may be a value that we discarded. Example:
  ```cpp
  vector<int> v {2, 3};

  // Discard 2
  v.erase(v.begin());

  v.push_back(1);
  sort(v.begin(), v.end());

  // Median of {1, 2, 3} is 2, though 2 has been discarded
  copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
  ```

# to-do

- Read page 62 chapter 3 of Accelerated C++
- Read page 42 section 2.2.3 of The C++ Programming Language

# takeaway

- `std::cout << "hello world" << std::endl` writes `hello world` to standard output as a [side effect](https://en.wikipedia.org/wiki/Side_effect_(computer_science))
- `<<` is [left-associative](https://en.wikipedia.org/wiki/Operator_associativity)
- Reading from standard input [flushes](http://www.cplusplus.com/reference/ostream/flush-free/) the output buffer
- `std::cin >> v` reads non-whitespace characters from standard input into `v`
- Use `{}` when initializing variables to prevent conversions that lose information
- `int i = 1.2;` truncates `0.2` and saves `1` to `i`, while `int i {1.2};` throws an error
- A loop [invariant](https://en.wikipedia.org/wiki/Invariant_(mathematics)) is a property that is true at the start and end of a loop
- `std::string::size_type` is a type used to store the size of a [string](http://www.cplusplus.com/reference/string/string/)
- Loop invariants are expressed more clearly using asymmetric ranges, e.g. [0, rows)
- Time complexity of [`sort()`](http://www.cplusplus.com/reference/algorithm/sort/) is nlog(n)
- Different methods for computing [quartiles](https://en.wikipedia.org/wiki/Quartile) yield different results
