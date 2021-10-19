#ifndef __ZZ3_CPP3_EXCEPTION__
#define __ZZ3_CPP3_EXCEPTION__

#include <exception>
#include <string>
#include "demangle.hpp"

class ExceptionChaine : public std::exception {
    private:
        std::string error_type;
        std::string error_msg;

    public:
        template <typename T>
        explicit ExceptionChaine(T obj) : 
            error_type(demangle(typeid(obj).name())),
            error_msg("Conversion en chaine impossible pour '"+error_type+"'")
        {}

        ~ExceptionChaine() throw () {}

        const char* what() const throw () {
            return error_msg.c_str();
        }
};

#endif