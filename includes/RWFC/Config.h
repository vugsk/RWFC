
#pragma once

#include <string>
#include <vector>

#include <nlohmann/json.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>

using std::string;
using std::vector;
using nlohmann::json;

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
typedef const string str_c;
typedef       string str;

typedef const vector<char*>  vec_str_c;
typedef       vector<char_c*>vec_str;
typedef const vector<int>    vec_int_c;
typedef       vector<int>    vec_int;
typedef const vector<float>  vec_float_c;
typedef       vector<float>  vec_float;
typedef const vector<double> vec_double_c;
typedef       vector<double> vec_double;
typedef const vector<bool>   vec_bool_c;
typedef       vector<bool>   vec_bool;

