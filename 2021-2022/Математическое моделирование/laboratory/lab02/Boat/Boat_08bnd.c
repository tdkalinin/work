/* update bound parameters and variable attributes (start, nominal, min, max) */
#include "Boat_model.h"
#if defined(__cplusplus)
extern "C" {
#endif

OMC_DISABLE_OPT
int Boat_updateBoundVariableAttributes(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  /* min ******************************************************** */
  
  infoStreamPrint(LOG_INIT, 1, "updating min-values");
  if (ACTIVE_STREAM(LOG_INIT)) messageClose(LOG_INIT);
  
  /* max ******************************************************** */
  
  infoStreamPrint(LOG_INIT, 1, "updating max-values");
  if (ACTIVE_STREAM(LOG_INIT)) messageClose(LOG_INIT);
  
  /* nominal **************************************************** */
  
  infoStreamPrint(LOG_INIT, 1, "updating nominal-values");
  if (ACTIVE_STREAM(LOG_INIT)) messageClose(LOG_INIT);
  
  /* start ****************************************************** */
  infoStreamPrint(LOG_INIT, 1, "updating primary start-values");
  if (ACTIVE_STREAM(LOG_INIT)) messageClose(LOG_INIT);
  
  TRACE_POP
  return 0;
}

void Boat_updateBoundParameters_0(DATA *data, threadData_t *threadData);

/*
equation index: 17
type: SIMPLE_ASSIGN
$cse3 = cos(phi)
*/
OMC_DISABLE_OPT
static void Boat_eqFunction_17(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,17};
  data->localData[0]->realVars[6] /* $cse3 variable */ = cos(data->simulationInfo->realParameter[1] /* phi PARAM */);
  TRACE_POP
}

/*
equation index: 18
type: SIMPLE_ASSIGN
$cse4 = sin(phi)
*/
OMC_DISABLE_OPT
static void Boat_eqFunction_18(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,18};
  data->localData[0]->realVars[7] /* $cse4 variable */ = sin(data->simulationInfo->realParameter[1] /* phi PARAM */);
  TRACE_POP
}
OMC_DISABLE_OPT
void Boat_updateBoundParameters_0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  Boat_eqFunction_17(data, threadData);
  Boat_eqFunction_18(data, threadData);
  TRACE_POP
}
OMC_DISABLE_OPT
int Boat_updateBoundParameters(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  Boat_updateBoundParameters_0(data, threadData);
  TRACE_POP
  return 0;
}

#if defined(__cplusplus)
}
#endif

