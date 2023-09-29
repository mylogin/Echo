#ifndef ECHO_H
#define ECHO_H

#include <type_traits>
#include <utility>
#include <tuple>
#include <string>

namespace echo {

const char* delimiter = ", ";
const char* arr_quotes[] = {"[", "]"};
const char* cont_quotes[] = {"{", "}"};
const char* tuple_quotes[] = {"(", ")"};
const char* pair_quotes[] = {"<", ">"};

template<typename, typename = void>
constexpr bool is_iterable{};
 
template<typename T>
constexpr bool is_iterable<T, std::void_t<
    decltype(std::declval<T>().begin()),
    decltype(std::declval<T>().end())>
> = true;

std::string to_str(bool p) {
    return p ? "true" : "false";
}

std::string to_str(const std::string& p) {
    return '"' + p + '"';
}

std::string to_str(const char* p) {
    return to_str(std::string(p));
}

std::string to_str(char p) {
    return "'" + std::string(1, p) + "'";
}

template<typename T, std::enable_if_t<std::is_arithmetic_v<T>, bool> = true>
std::string to_str(T p) {
    return std::to_string(p);
}

template <typename T, size_t N>
std::string to_str(const T (&p)[N]);

template <typename A, typename B>
std::string to_str(const std::pair<A, B>& p);

template<typename T, size_t... N>
std::string to_str_tuple(const T& p, std::index_sequence<N...>);

template<typename... T>
std::string to_str(const std::tuple<T...>& p);

template<typename T, std::enable_if_t<is_iterable<T>, bool> = true>
std::string to_str(const T& p);

template <typename T, size_t N>
std::string to_str(const T (&p)[N]) {
    std::string res = arr_quotes[0];
    for(size_t i = 0; i < N; i++) {
        if (i) {
            res += delimiter;
        }
        res += to_str(p[i]);
    }
    res += arr_quotes[1];
    return res;
}

template <typename A, typename B>
std::string to_str(const std::pair<A, B>& p) {
    return pair_quotes[0] + to_str(p.first) + delimiter + to_str(p.second) + pair_quotes[1];
}

template<typename T, size_t... N>
std::string to_str_tuple(const T& p, std::index_sequence<N...>) {
    return tuple_quotes[0] + ((to_str(std::get<N>(p)) + (N == sizeof...(N) - 1 ? std::string() : delimiter)) + ...) + tuple_quotes[1];
}

template<typename... T>
std::string to_str(const std::tuple<T...>& p) {
    return to_str_tuple(p, std::make_index_sequence<sizeof...(T)>{});
}

template<typename T, std::enable_if_t<is_iterable<T>, bool>>
std::string to_str(const T& p) {
    bool first = true;
    std::string res = cont_quotes[0];
    for (const auto &x : p) {
        if (!first) {
            res += delimiter;
        }
        first = false;
        res += to_str(x);
    }
    res += cont_quotes[1];
    return res;
}

template<typename... T>
std::string str(const T&... p) {
    std::string s;
    size_t size = sizeof...(p);
    size_t i = 0;
    (s.append(to_str(p) + (++i == size ? std::string() : delimiter)), ...);
    return s;
}

}

#endif