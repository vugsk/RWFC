
#pragma once

#include "ParserFile.h"

#include <nlohmann/json.hpp>
using nlohmann::json;

class ParserJsonFile : public ParserFileRead, public ParserFileWrite {
private:
    json _dataWrite,
         _dataRead;
    
    const json readInFile(str_c nameReadFile);
    
    template<typename T> 
    T read_T(str_c key, json data=nullptr, bool_c test=false) ;
    
    template<typename T> 
    void write_T(T data, str_c key);

public:
    ParserJsonFile(const ParserJsonFile &)            = delete;
    ParserJsonFile(ParserJsonFile &&)                 = delete;
    ParserJsonFile &operator=(const ParserJsonFile &) = delete;
    ParserJsonFile &operator=(ParserJsonFile &&)      = delete;

    ParserJsonFile();
    ~ParserJsonFile() override;
    
    void read(str_c nameReadFile, str_c key, int& value) override; //* int
    void read(str_c nameReadFile, str_c key, char_c* &value) override; //* str
    void read(str_c nameReadFile, str_c key, float& value) override; //* float
    void read(str_c nameReadFile, str_c key, double& value) override; //* double
    void read(str_c nameReadFile, str_c key, bool& value) override; //* bool

    void read(str_c nameReadFile, str_c key, vec_int& value) override; //* vector_int
    void read(str_c nameReadFile, str_c key, vec_str& value) override; //* vector_str
    void read(str_c nameReadFile, str_c key, vec_float& value) override; //* vector_float
    void read(str_c nameReadFile, str_c key, vec_double& value) override; //* vector_double
    void read(str_c nameReadFile, str_c key, vec_bool& value) override; //* vector_bool


    void write(str_c key, int_c data) override; //* int
    void write(str_c key, str_c data) override; //* str
    void write(str_c key, float_c data) override; //* float
    void write(str_c key, double_c data) override; //* double
    void write(str_c key, bool_c data) override; //* bool

    void write(str_c key, vec_int_c data) override; //* vector_int
    void write(str_c key, vec_str_c data) override; //* vector_str
    void write(str_c key, vec_float_c data) override; //* vector_float
    void write(str_c key, vec_double_c data) override; //* vector_double
    void write(str_c key, vec_bool_c data) override; //* vector_bool

    void close(str_c nameWriteFile) override;

};
