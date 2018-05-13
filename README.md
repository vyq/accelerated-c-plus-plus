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
- 3-6: g++ shows a division by zero warning at compile time and throws a floating point exception at run time
- 4-2: The code will not work as the types for both arguments in `max()` need to be the same. Change `int maxlen` to `string:size_type maxlen`
- 4-8: The return type of `f()` is an array. Example:
  ```cpp
  int* f() {
    return new int[2] {1, 2};
  }

  int main() {
    int n = 0;
    
    double d = f()[n];

    // Outputs 1
    std::cout << d << std::endl;

    return 0;
  }
  ```
- 5-2: Execution time in seconds (average of 3 runs):
Records|vector|list
-|-|-
10|0.0006430576667|0.000637815
1000|0.04035813333|0.02703803333
10000|0.518863|0.1394713333

# takeaway

- `std::cout << "hello world" << std::endl` writes `hello world` to the standard output stream as a [side effect](https://en.wikipedia.org/wiki/Side_effect_(computer_science))
- `<<` is [left-associative](https://en.wikipedia.org/wiki/Operator_associativity)
- Reading from the standard input stream [flushes](http://www.cplusplus.com/reference/ostream/flush-free/) the output buffer
- `std::cin >> v` reads non-whitespace characters from the standard input stream into `v`
- Use `{}` when initializing variables to prevent conversions that lose information. Example: `int i = 1.2;` truncates `0.2` and saves `1` to `i`, while `int i {1.2};` throws an error
- A loop [invariant](https://en.wikipedia.org/wiki/Invariant_(mathematics)) is a property that is true at the start and end of a loop
- `std::string::size_type` is a type used to store the size of a [string](http://www.cplusplus.com/reference/string/string/)
- Loop invariants are expressed more clearly using `[0, rows)` asymmetric ranges
- Time complexity of [`sort()`](http://www.cplusplus.com/reference/algorithm/sort/) is nlog(n)
- Different methods for computing [quartiles](https://en.wikipedia.org/wiki/Quartile) yield different results
- A prefix `&` is an address-of operator. Example: `foo = &bar` stores the address of variable `bar` in `foo`
- A suffix `*` is a declarator operator. Example: `int* foo = &bar` stores the address of integer `bar` in [pointer](http://www.cplusplus.com/doc/tutorial/pointers/) `foo`
- A prefix `*` is a [dereference operator](https://en.wikipedia.org/wiki/Dereference_operator). Example: `baz = *foo` assigns the value pointed to by `foo` to `baz`
- A suffix `&` is a declarator operator. Example: `for (auto& x: v)` loops through `v` and references each element using `x`. Calling by reference is faster than `for (auto x: v)` as it avoids the overhead of copying each element when calling by value
- `nullptr` is a null pointer that represents no object is available
- A [lvalue](https://en.wikipedia.org/wiki/Value_(computer_science)) is a value that has an address in memory, while a rvalue does not persist beyond the expression that uses it
- [`inline`](https://en.wikipedia.org/wiki/Inline_function) suggests that the compiler replace a function call with the function code
- Use `->` to access struct members through a pointer. Example:
  ```cpp
  struct Vector {
    int size;
    int* elements;
  };

  Vector v;
  v.size = 2;
  Vector* pointer = &v;

  // Outputs 2
  std::cout << pointer->size << std::endl;
  ```
- An advantage of the `vector` data structure is fast random access. A disadvantage is that it is expensive to add or delete elements that are not at the end of the `vector`
- `()` is required as `.` has higher precedence than `*` in `(*iterator).name`. `*iterator.name` would throw a compilation error as `iterator` does not have a member `name`. The [syntactic sugar](https://en.wikipedia.org/wiki/Syntactic_sugar) `iterator->name` can be used as an abbreviation
- `iterator = vector.erase(iterator)` invalidates all iterators after the element that was erased and makes `iterator` refer to the element after the erased element
- `vector.push_back(element)` invalidates all iterators referring to `vector`
- A [class](https://en.wikipedia.org/wiki/Class_(computer_programming)) is a template for creating objects, providing initial values for [state](https://en.wikipedia.org/wiki/State_(computer_science)), and implementing behaviors
- A [handle](https://en.wikipedia.org/wiki/Handle_(computing)) is a fixed size reference to dynamically sized resources
- Use [initialization lists](https://isocpp.org/wiki/faq/ctors#init-lists) when initializing member objects for performance

# to-do

- Read page 143 exercise 5-2 of Accelerated C++
- Read page 50 section 2.3.3 of The C++ Programming Language
