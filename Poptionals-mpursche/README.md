# Poptionals

Ready to work with smart pointers and optionals?

## Setup
Use this Guided Project template to create a new repository (see [GitHub-with-CLion](https://github.com/uvmcs120s2022/GitHub-with-CLion) repo for directions).
**Your repository must be named with the convention: Poptionals-netid**, where netid is your UVM NetID username.

Remember to commit and push frequently.

## Optionals
Recall from CS 124 that optionals are used when a variable may not have a value.

Here is the required syntax:
```cpp
// if you are running C++14
#include <experimental/optional>
using std::experimental::optional;
using std::experimental::nullopt;
using std::experimental::make_optional;

// if you are running C++17
#include <optional>
using std::optional;
using std::nullopt;
using std::make_optional;
```

To declare and use an optional:

```cpp
// Note: nullopt means that the optional does not hold an integer value.
optional<int> myOptInt = nullopt;
// Now put a value in the optional
myOptInt = make_optional<int>(42);
// Check to see if a value is there
if (myOptInt) {
    // Use an asterisk to access the value
    cout << "The number is " << *myOptInt << endl;
    // Use an asterisk to change the value
    *myOptInt = 8;
} else {
    cout << "There is no number" << endl;
}
// You can set an optional back to nullopt at any time
myOptInt = nullopt;
```

Note that you can use optionals with any data type (not just integers as in the example above).
This is because `optional` is a template class.

## Smart Pointers
In CS 124, we used C-style syntax for pointers. 
C++14 introduced smart pointers. 
The use cases are the same for both types of pointers (we want to allocate heap memory that will exist beyond the current scope).
The main benefit of smart pointers is that you do not need to manually deallocate them in your code.

Here is the required syntax:
```cpp
#include <memory>
```

To declare and use a smart pointer:

```cpp
// Note: nullptr means that the pointer does not hold a memory address.
unique_ptr<int> myIntPtr = nullptr;
// Now allocate space in heap memory and story the memory address in the pointer
myIntPtr = make_unique<int>(42);
// Check to see if the pointer is storing an address
if (myIntPtr) {
    // Use an asterisk to access the value in heap memory
    cout << "The number is " << *myIntPtr << endl;
    // Use an asterisk to change the value
    *myIntPtr = 8;
} else {
    cout << "There is no number" << endl;
}
// You can set a pointer back to nullptr at any time
myIntPtr = nullptr;
```

Besides unique pointers, which cannot be copied, there are also shared pointers.
You should use unique pointers unless you require shared pointers for some task.

```cpp
// Declare a shared pointer
shared_ptr<int> mySharedIntPtr = make_shared<int>(987);
// The following line compiles with shared pointers but not unique pointers.
shared_ptr<int> mySharedIntPtrCopy = mySharedIntPtr;
```

Note that you can use smart pointers with any data type (not just integers as in the examples above).
This is because `unique_ptr` and `shared_ptr` are template classes.

## Your Task
To get practice with this new syntax, follow the directions in the `main.cpp` comments to declare and initialize a variety of optionals and smart pointers.

## Tips for Success
* Use unique pointers wherever possible. There is only one section that requires a shared pointer.
* Your program should build/compile. Make sure that for sections asking you to write a function, that you declare it above the main funciton, call it in the main function, and define it after the main function.
* Don't confuse nullopt and nullptr. In the diagrams, nullopt will be an empty box with a question mark in the top left; nullptrs will be arrows running into a bar.

### Grading Rubric
- [ ] (1 pt) Good and consistent coding style.
- [ ] (1 pt) Section 1 is complete and correct.
- [ ] (1 pt) Section 2 is complete and correct.
- [ ] (2 pts) Section 3 is complete and correct.
- [ ] (2 pts) Section 4 is complete and correct.
- [ ] (2 pts) Section 5 is complete and correct.
- [ ] (2 pts) Section 6 is complete and correct.
- [ ] (2 pts) Section 7 is complete and correct.
- [ ] (2 pts) Section 8 is complete and correct.
- [ ] (2 pts) Section 9 is complete and correct.
- [ ] (3 pts) Section 10 is complete and correct.
