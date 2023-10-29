
#pragma once

#include <string>
#include <vector>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>

using namespace boost::property_tree;

#define DEBUG false

#define FORMAT_JSON ".json"
#define FORMAT_INI  ".ini"

#if DEBUG 
    #define DEBUG_PATH_FILE_JSON       "test_files/testJSON"
    #define DEBUG_PATH_FILE_JSON_WRITE "test_files/testWriteJSON"
    #define DEBUG_PATH_FILE_INI        "test_files/testIni.ini"
#endif

typedef const char   char_c;
typedef const int    int_c;
typedef const bool   bool_c;
typedef const float  float_c;
typedef const double double_c;
typedef const std::string str_c;
typedef       std::string str;

typedef const std::vector<char*>  vec_str_c;
typedef       std::vector<char_c*>vec_str;
typedef const std::vector<int>    vec_int_c;
typedef       std::vector<int>    vec_int;
typedef const std::vector<float>  vec_float_c;
typedef       std::vector<float>  vec_float;
typedef const std::vector<double> vec_double_c;
typedef       std::vector<double> vec_double;
typedef const std::vector<bool>   vec_bool_c;
typedef       std::vector<bool>   vec_bool;

