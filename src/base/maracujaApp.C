#include "maracujaApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
maracujaApp::validParams()
{
  InputParameters params = MooseApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

maracujaApp::maracujaApp(InputParameters parameters) : MooseApp(parameters)
{
  maracujaApp::registerAll(_factory, _action_factory, _syntax);
}

maracujaApp::~maracujaApp() {}

void
maracujaApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAllObjects<maracujaApp>(f, af, s);
  Registry::registerObjectsTo(f, {"maracujaApp"});
  Registry::registerActionsTo(af, {"maracujaApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
maracujaApp::registerApps()
{
  registerApp(maracujaApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
maracujaApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  maracujaApp::registerAll(f, af, s);
}
extern "C" void
maracujaApp__registerApps()
{
  maracujaApp::registerApps();
}
