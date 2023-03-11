#include "json_object.cpp"
using namespace json;
int main() {
  json_object a;
  json_object a1{5};
  json_object a2{"222"};
  vector<json_object> vec{json_object("111"), json_object(1), json_object(1.14514)};
}
