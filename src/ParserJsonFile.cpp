
#include "ParserJsonFile.h"


const json ParserJsonFile::readInFile(str_c nameReadFile) {
    ifstream file(nameReadFile + FORMAT_JSON);
    _dataRead = json::parse(file);
    file.close();
    return _dataRead;
}

template<typename T> T ParserJsonFile::read_T(str_c key, json data) {
    static str num;

    for (auto& [keys, values]: data.items()) {
        if (keys == key) break;

        if (keys == num) {
            _dataRead.erase(num);
            continue;
        }

        if (values.is_object()) {
            num = keys;
            return read_T<T>(key, values);
        }

        else {
            return read_T<T>(key, _dataRead);
        }
    }
    
    return data[key];
}



void ParserJsonFile::read(str_c nameReadFile, str_c key, int& value) {
    value = read_T<int>(key, readInFile(nameReadFile));
    _dataRead = nullptr;
}

void ParserJsonFile::read(str_c nameReadFile, str_c key, str& value) {
    value = read_T<str>(key, readInFile(nameReadFile));
    _dataRead = nullptr;
}

void ParserJsonFile::read(str_c nameReadFile, str_c key, float& value) {
    value = read_T<float>(key, readInFile(nameReadFile));
    _dataRead = nullptr;
}

void ParserJsonFile::read(str_c nameReadFile, str_c key, double& value) {
    value = read_T<double>(key, readInFile(nameReadFile));
    _dataRead = nullptr;
}

void ParserJsonFile::read(str_c nameReadFile, str_c key, bool& value) {
    value = read_T<bool>(key, readInFile(nameReadFile));
    _dataRead = nullptr;
}

void ParserJsonFile::read(str_c nameReadFile, str_c key, vector<int>& value) {    
    value = read_T<vector<int>>(key, readInFile(nameReadFile));
    _dataRead = nullptr;
}

void ParserJsonFile::read(str_c nameReadFile, str_c key, vector<str>& value) {
    value = read_T<vector<str>>(key, readInFile(nameReadFile));
    _dataRead = nullptr;
}

void ParserJsonFile::read(str_c nameReadFile, str_c key, vector<float>& value) {
    value = read_T<vector<float>>(key, readInFile(nameReadFile));
    _dataRead = nullptr;
}

void ParserJsonFile::read(str_c nameReadFile, str_c key, vector<double>& value) {
    value = read_T<vector<double>>(key, readInFile(nameReadFile));
    _dataRead = nullptr;
}

void ParserJsonFile::read(str_c nameReadFile, str_c key, vector<bool>& value) {
    value = read_T<vector<bool>>(key, readInFile(nameReadFile));
    _dataRead = nullptr;
}



template<typename T> 
void ParserJsonFile::write_T(T data, str_c key) { _dataWrite[key] = data; }

void ParserJsonFile::write(str_c key, int_c data) {
    write_T(data, key);
}
void ParserJsonFile::write(str_c key, str_c data) {
    write_T(data, key);
}
void ParserJsonFile::write(str_c key, float_c data) {
    write_T(data, key);
}
void ParserJsonFile::write(str_c key, double_c data) {
    write_T(data, key);
}
void ParserJsonFile::write(str_c key, bool_c data) {
    write_T(data, key);
}
void ParserJsonFile::write(str_c key, vec_int_c data) {
    write_T(data, key);
}
void ParserJsonFile::write(str_c key, vec_str_c data) {
    write_T(data, key);
}
void ParserJsonFile::write(str_c key, vec_float_c data) {
    write_T(data, key);
}
void ParserJsonFile::write(str_c key, vec_double_c data) {
    write_T(data, key);
}
void ParserJsonFile::write(str_c key, vec_bool_c data) {
    write_T(data, key);
}


void ParserJsonFile::close(str_c nameWriteFile) {
    ofstream file(nameWriteFile + FORMAT_JSON);
    file << _dataWrite.dump(4);
    file.close();
}


ParserJsonFile::ParserJsonFile() {}
ParserJsonFile::~ParserJsonFile() {
    _dataWrite.clear(); 
    _dataRead.clear(); 
}