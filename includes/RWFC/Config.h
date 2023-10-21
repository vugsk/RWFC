
#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <stack>

#include <nlohmann/json.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>

using std::string;
using std::vector;
using std::stack;
using std::pair;
using nlohmann::json;
using std::ifstream;
using std::ofstream;

using namespace boost::property_tree;

#define DEBUG false

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

typedef const vector<str>    vec_str_c;
typedef       vector<string> vec_str;
typedef const vector<int>    vec_int_c;
typedef       vector<int>    vec_int;
typedef const vector<float>  vec_float_c;
typedef       vector<float>  vec_float;
typedef const vector<double> vec_double_c;
typedef       vector<double> vec_double;
typedef const vector<bool>   vec_bool_c;
typedef       vector<bool>   vec_bool;


#define FORMAT_JSON ".json"
#define FORMAT_INI  ".ini"

#define TYPE_INT(typeData)    (typeid(typeData) == typeid(int))
#define TYPE_STRING(typeData) (typeid(typeData) == typeid(str))
#define TYPE_CHAR(typeData)   (typeid(typeData) == typeid(char))

template<typename T> inline int type(T type_data) {
    if      (TYPE_INT(type_data))         return 0;
    else if (TYPE_STRING(type_data))      return 1;
    else if (TYPE_CHAR(type_data))        return 2;
    else                                  return -1;
}
