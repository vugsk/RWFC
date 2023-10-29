
#pragma once

#include "Config.h"
#include "ParserFile.h"


class ParserIniFile : public ParserFileRead {
private:
    ptree pt;

    template<typename T> 
    T read_T(str_c key);
    
    template<typename T, typename T2> 
    T read_vec_T(str_c key);

public:
    ParserIniFile(const ParserIniFile &)            = delete;
    ParserIniFile(ParserIniFile &&)                 = delete;
    ParserIniFile &operator=(const ParserIniFile &) = delete;
    ParserIniFile &operator=(ParserIniFile &&)      = delete;
    
    ParserIniFile();
    ~ParserIniFile() override;

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

};
