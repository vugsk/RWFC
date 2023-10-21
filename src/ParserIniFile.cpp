
#include "ParserIniFile.h"



template<typename T> T ParserIniFile::read_T(str_c key) {
    return pt.get<T>(key);
}

template<typename T, typename T2> T ParserIniFile::read_vec_T(str_c key) {
    T dataVector(read_T<int>(key + ".len"));

    for (int i = 0; i < dataVector.size(); i++) {
        dataVector[i] = read_T<T2>(key + ".key" + std::to_string(i));
    }

    return dataVector;
}

void ParserIniFile::read(str_c nameReadFile, str_c key, int& value) {
    ini_parser::read_ini(nameReadFile, pt);
    value = read_T<int>(key);
} //* int
void ParserIniFile::read(str_c nameReadFile, str_c key, str& value) {
    ini_parser::read_ini(nameReadFile, pt);
    value = read_T<str>(key);
}
void ParserIniFile::read(str_c nameReadFile, str_c key, float& value) {
    ini_parser::read_ini(nameReadFile, pt);
    value = read_T<float>(key);
} //* float
void ParserIniFile::read(str_c nameReadFile, str_c key, double& value) {
    ini_parser::read_ini(nameReadFile, pt);
    value = read_T<double>(key);
} //* double
void ParserIniFile::read(str_c nameReadFile, str_c key, bool& value) {
    ini_parser::read_ini(nameReadFile, pt);
    value = read_T<bool>(key);
} //* bool

void ParserIniFile::read(str_c nameReadFile, str_c key, vec_int& value) {
    ini_parser::read_ini(nameReadFile, pt);
    value = read_vec_T<vec_int, int>(key);
} //* vector_int
void ParserIniFile::read(str_c nameReadFile, str_c key, vec_str& value) {
    ini_parser::read_ini(nameReadFile, pt);
    value = read_vec_T<vec_str, str>(key);
} //* vector_str
void ParserIniFile::read(str_c nameReadFile, str_c key, vec_float& value) {
    ini_parser::read_ini(nameReadFile, pt);
    value = read_vec_T<vec_float, float>(key);
} //* vector_float
void ParserIniFile::read(str_c nameReadFile, str_c key, vec_double& value) {
    ini_parser::read_ini(nameReadFile, pt);
    value = read_vec_T<vec_double, double>(key);
} //* vector_double
void ParserIniFile::read(str_c nameReadFile, str_c key, vec_bool& value) {
    ini_parser::read_ini(nameReadFile, pt);
    value = read_vec_T<vec_bool, bool>(key);
} //* vector_bool


ParserIniFile::ParserIniFile() {}
ParserIniFile::~ParserIniFile() {}
