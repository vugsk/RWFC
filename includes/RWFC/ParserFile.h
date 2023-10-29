
#pragma once

#include "Config.h"

class ParserFileRead {
public:
    virtual ~ParserFileRead() = 0;

    virtual void read(str_c nameReadFile, str_c key, int& value) = 0; //* int
    virtual void read(str_c nameReadFile, str_c key, char_c* &value) = 0; //* str
    virtual void read(str_c nameReadFile, str_c key, float& value) = 0; //* float
    virtual void read(str_c nameReadFile, str_c key, double& value) = 0; //* double
    virtual void read(str_c nameReadFile, str_c key, bool& value) = 0; //* bool

    virtual void read(str_c nameReadFile, str_c key, vec_int& value) = 0; //* vector_int
    virtual void read(str_c nameReadFile, str_c key, vec_str& value) = 0; //* vector_str
    virtual void read(str_c nameReadFile, str_c key, vec_float& value) = 0; //* vector_float
    virtual void read(str_c nameReadFile, str_c key, vec_double& value) = 0; //* vector_double
    virtual void read(str_c nameReadFile, str_c key, vec_bool& value) = 0; //* vector_bool

};

class ParserFileWrite {
public:
    virtual ~ParserFileWrite() {}
    virtual void write(str_c key, int_c data) = 0; //* int
    virtual void write(str_c key, str_c data) = 0; //* str
    virtual void write(str_c key, float_c data) = 0; //* float
    virtual void write(str_c key, double_c data) = 0; //* double
    virtual void write(str_c key, bool_c data) = 0; //* bool

    virtual void write(str_c key, vec_int_c data) = 0; //* vector_int
    virtual void write(str_c key, vec_str_c data) = 0; //* vector_str
    virtual void write(str_c key, vec_float_c data) = 0; //* vector_float
    virtual void write(str_c key, vec_double_c data) = 0; //* vector_double
    virtual void write(str_c key, vec_bool_c data) = 0; //* vector_bool

    virtual void close(str_c nameWriteFile) = 0;
};