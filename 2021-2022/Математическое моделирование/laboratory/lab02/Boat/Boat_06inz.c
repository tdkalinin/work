/* Initialization */
#include "Boat_model.h"
#include "Boat_11mix.h"
#include "Boat_12jac.h"
#if defined(__cplusplus)
extern "C" {
#endif

void Boat_functionInitialEquations_0(DATA *data, threadData_t *threadData);
extern void Boat_eqFunction_16(DATA *data, threadData_t *threadData);


/*
equation index: 2
type: SIMPLE_ASSIGN
ro = x1
*/
void Boat_eqFunction_2(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2};
  data->localData[0]->realVars[0] /* ro STATE(1) */ = data->simulationInfo->realParameter[3] /* x1 PARAM */;
  TRACE_POP
}

/*
equation index: 3
type: SIMPLE_ASSIGN
ylod = ro * sin(phi)
*/
void Boat_eqFunction_3(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3};
  data->localData[0]->realVars[11] /* ylod variable */ = (data->localData[0]->realVars[0] /* ro STATE(1) */) * (sin(data->simulationInfo->realParameter[1] /* phi PARAM */));
  TRACE_POP
}

/*
equation index: 4
type: SIMPLE_ASSIGN
xlod = ro * cos(phi)
*/
void Boat_eqFunction_4(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,4};
  data->localData[0]->realVars[9] /* xlod variable */ = (data->localData[0]->realVars[0] /* ro STATE(1) */) * (cos(data->simulationInfo->realParameter[1] /* phi PARAM */));
  TRACE_POP
}
extern void Boat_eqFunction_15(DATA *data, threadData_t *threadData);


/*
equation index: 6
type: SIMPLE_ASSIGN
theta = 0.0
*/
void Boat_eqFunction_6(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,6};
  data->localData[0]->realVars[1] /* theta STATE(1) */ = 0.0;
  TRACE_POP
}

/*
equation index: 7
type: SIMPLE_ASSIGN
ykat = ro * sin(theta)
*/
void Boat_eqFunction_7(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,7};
  data->localData[0]->realVars[10] /* ykat variable */ = (data->localData[0]->realVars[0] /* ro STATE(1) */) * (sin(data->localData[0]->realVars[1] /* theta STATE(1) */));
  TRACE_POP
}

/*
equation index: 8
type: SIMPLE_ASSIGN
xkat = ro * cos(theta)
*/
void Boat_eqFunction_8(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,8};
  data->localData[0]->realVars[8] /* xkat variable */ = (data->localData[0]->realVars[0] /* ro STATE(1) */) * (cos(data->localData[0]->realVars[1] /* theta STATE(1) */));
  TRACE_POP
}
OMC_DISABLE_OPT
void Boat_functionInitialEquations_0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  Boat_eqFunction_16(data, threadData);
  Boat_eqFunction_2(data, threadData);
  Boat_eqFunction_3(data, threadData);
  Boat_eqFunction_4(data, threadData);
  Boat_eqFunction_15(data, threadData);
  Boat_eqFunction_6(data, threadData);
  Boat_eqFunction_7(data, threadData);
  Boat_eqFunction_8(data, threadData);
  TRACE_POP
}

int Boat_functionInitialEquations(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->discreteCall = 1;
  Boat_functionInitialEquations_0(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
  TRACE_POP
  return 0;
}

/* No Boat_functionInitialEquations_lambda0 function */

int Boat_functionRemovedInitialEquations(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int *equationIndexes = NULL;
  double res = 0.0;

  
  TRACE_POP
  return 0;
}


#if defined(__cplusplus)
}
#endif

