#include <string_view>

namespace _types_internal {

template <typename T> 
constexpr std::string_view type_name();

template <>
constexpr std::string_view type_name<void>() {
    return "void";
}    


template <typename T>
constexpr std::string_view wrapped_type_name()  {
#ifdef __clang__
    return __PRETTY_FUNCTION__;
#elif defined(__GNUC__)
    return __PRETTY_FUNCTION__;
#elif defined(_MSC_VER)
    return __FUNCSIG__;
#endif
}

using dummy = void;

constexpr auto wrapped_type_name_prefix_length() { 
    return wrapped_type_name<dummy>().find(type_name<dummy>()); 
}

constexpr auto wrapped_type_name_suffix_length() { 
    return wrapped_type_name<dummy>().length() 
        - wrapped_type_name_prefix_length() 
        - type_name<dummy>().length();
}

template <typename T>
constexpr std::string_view type_name() {
    constexpr auto wrapped_name = wrapped_type_name<T>();
    constexpr auto prefix_length = wrapped_type_name_prefix_length();
    constexpr auto suffix_length = wrapped_type_name_suffix_length();
    constexpr auto type_name_length = wrapped_name.length() - prefix_length - suffix_length;
    return wrapped_name.substr(prefix_length, type_name_length);
}

}

#define type(x) _types_internal::type_name<decltype(x)>()
