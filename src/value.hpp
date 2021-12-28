#pragma once
#include "common.hpp"
#include "base_array.hpp"

#include <iostream>

namespace ValueType
{
enum Any {
  VAL_BOOL,
  VAL_NIL,
  VAL_NUMBER
};
}

using Number = double;
struct Value {
  ValueType::Any m_type;
  union {
    bool boolean;
    double number;
  } data;

  void set_bool(bool value)
  {
    data.boolean = value;
  }

  void set_number(double value)
  {
    data.number = value;
  }

  void set_nil()
  {

  }

  bool as_bool()
  {
    return data.boolean;
  }

  double as_number()
  {
    return data.number;
  }

  void as_nil()
  {

  }

  template<typename T>
  T get()
  {

  }

  template<typename T>
  Value static make(T val)
  {

  }

  template<typename T>
  bool is_type()
  {

  };

#ifndef __INTELLISENSE__
  template<>
  bool get<bool>()
  {
    if (m_type != ValueType::VAL_BOOL) {

    }
    return data.boolean;
  }

  template<>
  Number get<Number>()
  {
    if (m_type != ValueType::VAL_NUMBER) {

    }
    return data.number;
  }

  template<>
  Value make<Number>(Number val)
  {
    Value v;
    v.m_type = ValueType::VAL_NUMBER;
    v.set_number(val);
    return v;
  }

  template<>
  Value make<bool>(bool val)
  {
    Value v;
    v.m_type = ValueType::VAL_BOOL;
    v.set_bool(val);
    return v;
  }


  template<>
  bool is_type<double>()
  {
    return true;
  }

  template<>
  bool is_type<bool>()
  {
    return true;
  }
#endif
  friend std::ostream& operator<<(std::ostream& output_stream, Value& value)
  {
    output_stream << value.as_number();
    return output_stream;
  }
};


using ValueArray = BaseArray<Value>;
