# type

Just adds one function `type()`. All it does is get a human-readable version of the type of it's argument.

### example usage
```cpp
int main() {
    int i = 0;
    int& x = i;
    int&& y = std::move(x);

    std::cout << type(i) << '\n';   // prints "int"
    std::cout << type(x) << '\n';   // prints "int&"
    std::cout << type(y) << '\n';   // prints "int&&"
}
```
