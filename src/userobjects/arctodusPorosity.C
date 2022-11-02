#include "arctodusPorosity.h"

InputParameters
arctodusPorosity::validParams()
{
  InputParameters params = GeneralUserObject::validParams();
  params.addClassDescription(
      "arctodus Porosity base class. Override the virtual functions in your class.");
  return params;
}

arctodusPorosity::arctodusPorosity(const InputParameters & parameters) : GeneralUserObject(parameters) {}