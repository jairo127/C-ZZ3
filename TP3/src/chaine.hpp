#ifndef __ZZ3_CPP3_CHAINE__
#define __ZZ3_CPP3_CHAINE__

#include <string>
#include <sstream>
#include <cstdarg>
#include "exception.hpp"
#include "demangle.hpp"

template <typename T>
std::string chaine(T obj) {
    throw ExceptionChaine(obj);
}

template <typename T>
std::string sstream_convertion(T obj) {
    std::stringstream ss;
    ss << std::to_string(obj);
    return ss.str();
}

template <> std::string chaine<int>(int obj) { return sstream_convertion(obj); }
template <> std::string chaine<double>(double obj) { return sstream_convertion(obj); }
template <> std::string chaine<std::string>(std::string obj) { return obj; }

template <typename T, typename... Types>
std::string chaine(T obj, Types... args) {
    return chaine(obj) + " " + chaine(args...);
}

template <typename T, size_t... Is>
std::string chaine_t(const T & t, std::index_sequence<Is...>) {
    return chaine(std::get<Is>(t)...);
}

template <typename... Args>
std::string chaine(const std::tuple<Args...> & t) {
    return chaine_t(t, std::make_index_sequence<sizeof... (Args)>());
}

#endif