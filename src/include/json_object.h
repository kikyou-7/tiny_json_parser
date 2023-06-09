#pragma once
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <variant>
#include <vector>

namespace json {

enum class TYPE : int { T_NULL, T_BOOL, T_INT, T_DOUBLE, T_STR, T_LIST, T_DICT };

using std::string;
using std::unordered_map;
using std::variant;
using std::vector;

class json_object;

// json对象的类型  对应了7种枚举类型

using bool_t = bool;
using int_t = int;
using double_t = double;
using str_t = string;

using list_t = vector<json_object>;
using dict_t = unordered_map<str_t, json_object>;

// 是否是int/bool/double
template <typename T>
constexpr bool is_basic_type() {
  return std::is_same_v<T, int> || std::is_same_v<T, double> || std::is_same_v<T, bool>;
}

template <typename T>
constexpr TYPE get_type() {
  if constexpr (std::is_same_v<T, bool>) {
    return TYPE::T_BOOL;
  } else if constexpr (std::is_same_v<T, int>) {
    return TYPE::T_INT;
  }
  return TYPE::T_DOUBLE;
}

class json_object {
 public:
  using val_t = variant<bool_t, int_t, double_t, str_t, list_t, dict_t>;
  // 默认保存null_t类型
  json_object();

  template <typename T, typename = std::enable_if_t<is_basic_type<T>()>>
  json_object(T value) : type_(get_type<T>()), value_(value) {}

  json_object(list_t value);
  json_object(dict_t value);
  json_object(str_t value);

 private:
  TYPE type_{};
  val_t value_;
};
}  // namespace json_parser