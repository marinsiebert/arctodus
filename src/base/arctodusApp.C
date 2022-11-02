#include "arctodusApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
arctodusApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  return params;
}

arctodusApp::arctodusApp(InputParameters parameters) : MooseApp(parameters)
{
  arctodusApp::registerAll(_factory, _action_factory, _syntax);
}

arctodusApp::~arctodusApp() {}

void
arctodusApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAll(f, af, syntax);
  Registry::registerObjectsTo(f, {"arctodusApp"});
  Registry::registerActionsTo(af, {"arctodusApp"});
  /* register custom execute flags, action syntax, etc. here */
}

void
arctodusApp::registerApps()
{
  registerApp(arctodusApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
arctodusApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  arctodusApp::registerAll(f, af, s);
}
extern "C" void
arctodusApp__registerApps()
{
  arctodusApp::registerApps();
}
