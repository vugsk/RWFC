
#include "ParserJsonFile.h"

#include <stack>

namespace {
    std::stack<str> st_key;
    std::stack<json> st_data;
}

const json ParserJsonFile::readInFile(str_c nameReadFile)
{
    std::ifstream file(nameReadFile + FORMAT_JSON);
    _dataRead = json::parse(file);
    file.close();
    return _dataRead;
}

template<typename T> 
T ParserJsonFile::read_T(str_c key, json data, bool_c test)
{
    if (!test) st_data.push(data);

    for (auto& [keys, values]: data.items())
    {
        if (keys == key) break;

        if (keys != key && st_data.top().size() != 0 
            && !values.is_object())
        {
            st_data.top().erase(keys);
            continue;
        }

        if (values.is_object())
        {
            st_key.push(keys);
            return read_T<T>(key, values);
        }
        else
        {
            return read_T<T>(key, _dataRead);
        }

    }

    if (st_data.top().is_object() && st_data.top().empty())
    {
        st_data.pop();
        st_data.top().erase(st_key.top());
        st_key.pop();
        return read_T<T>(key, st_data.top(), true);
    }
    
    return data[key];
}

void ParserJsonFile::read(str_c nameReadFile, str_c key, int& value)
{
    value = read_T<int>(key, readInFile(nameReadFile));
    _dataRead = nullptr;
}

void ParserJsonFile::read(str_c nameReadFile, str_c key, char_c* &value)
{
    value = read_T<str>(key, readInFile(nameReadFile)).c_str();
    _dataRead = nullptr;
}

void ParserJsonFile::read(str_c nameReadFile, str_c key, float& value)
{
    value = read_T<float>(key, readInFile(nameReadFile));
    _dataRead = nullptr;
}

void ParserJsonFile::read(str_c nameReadFile, str_c key, double& value)
{
    value = read_T<double>(key, readInFile(nameReadFile));
    _dataRead = nullptr;
}

void ParserJsonFile::read(str_c nameReadFile, str_c key, bool& value)
{
    value = read_T<bool>(key, readInFile(nameReadFile));
    _dataRead = nullptr;
}

void ParserJsonFile::read(str_c nameReadFile, str_c key, vec_int& value)
{    
    value = read_T<vec_int>(key, readInFile(nameReadFile));
    _dataRead = nullptr;
}

void ParserJsonFile::read(str_c nameReadFile, str_c key, vec_str& value)
{

    std::vector<str> op = read_T<std::vector<str>>(key, readInFile(nameReadFile));

    for (int i = 0; i < op.size(); i++) {
        value.push_back(op[i].c_str());
    }

    _dataRead = nullptr;
}

void ParserJsonFile::read(str_c nameReadFile, str_c key, vec_float& value)
{
    value = read_T<vec_float>(key, readInFile(nameReadFile));
    _dataRead = nullptr;
}

void ParserJsonFile::read(str_c nameReadFile, str_c key, vec_double& value)
{
    value = read_T<vec_double>(key, readInFile(nameReadFile));
    _dataRead = nullptr;
}

void ParserJsonFile::read(str_c nameReadFile, str_c key, vec_bool& value)
{
    value = read_T<vec_bool>(key, readInFile(nameReadFile));
    _dataRead = nullptr;
}



template<typename T> 
void ParserJsonFile::write_T(T data, str_c key) { _dataWrite[key] = data; }

void ParserJsonFile::write(str_c key, int_c data)
{
    write_T(data, key);
}
void ParserJsonFile::write(str_c key, str_c data)
{
    write_T(data, key);
}
void ParserJsonFile::write(str_c key, float_c data)
{
    write_T(data, key);
}
void ParserJsonFile::write(str_c key, double_c data)
{
    write_T(data, key);
}
void ParserJsonFile::write(str_c key, bool_c data)
{
    write_T(data, key);
}
void ParserJsonFile::write(str_c key, vec_int_c data)
{
    write_T(data, key);
}
void ParserJsonFile::write(str_c key, vec_str_c data)
{
    write_T(data, key);
}
void ParserJsonFile::write(str_c key, vec_float_c data)
{
    write_T(data, key);
}
void ParserJsonFile::write(str_c key, vec_double_c data)
{
    write_T(data, key);
}
void ParserJsonFile::write(str_c key, vec_bool_c data)
{
    write_T(data, key);
}


void ParserJsonFile::close(str_c nameWriteFile)
{
    std::ofstream file(nameWriteFile + FORMAT_JSON);
    file << _dataWrite.dump(4);
    file.close();
}


ParserJsonFile::ParserJsonFile() {}
ParserJsonFile::~ParserJsonFile() {
    _dataWrite.clear(); 
    _dataRead.clear(); 
}