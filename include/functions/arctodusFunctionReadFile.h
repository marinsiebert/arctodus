#pragma once

#include "Function.h"

class arctodusFunctionReadFile : public Function
{
public:
  static InputParameters validParams();
  arctodusFunctionReadFile(const InputParameters & parameters);
  virtual Real value(Real t, const Point & pt) const override;

protected:
  const std::string _file;
  std::vector<Real> _time;
  std::vector<Real> _value;

private:
  void readFile();
};