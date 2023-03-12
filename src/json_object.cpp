#include "include/json_object.h"
using namespace json;

json_object::json_object() : type_(TYPE::T_NULL), value_() {}
json_object::json_object(list_t value) : type_(TYPE::T_LIST), value_(std::move(value)) {}
json_object::json_object(dict_t value) : type_(TYPE::T_DICT), value_(std::move(value)) {}
json_object::json_object(str_t value) : type_(TYPE::T_STR), value_(std::move(value)) {}