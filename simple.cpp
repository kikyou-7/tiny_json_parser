#include <iostream>
#include <type_traits>
#include <string>
using std::cout;
using std::string;
enum  TYPE : int { T_NULL, T_BOOL, T_INT, T_DOUBLE, T_STRING, T_LIST, T_DICT };

template <typename T>
constexpr TYPE get_tpye() {
  if constexpr (std::is_same_v<T, bool>){
    return TYPE::T_BOOL;
  } else if constexpr (std::is_same_v<T, int>) {
    return TYPE::T_INT;
  }
  return TYPE::T_DOUBLE;
}

int main() {
  cout << "1234" << '\n';
  cout << get_tpye<int>() << '\n';
  cout << get_tpye<const string>() << '\n';
  cout << get_tpye<bool>() << '\n';
  cout << get_tpye<double>() << '\n';
}
