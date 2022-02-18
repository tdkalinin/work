/* Algebraic */
#include "Boat_model.h"

#ifdef __cplusplus
extern "C" {
#endif


/* forwarded equations */
extern void Boat_eqFunction_9(DATA* data, threadData_t *threadData);
extern void Boat_eqFunction_10(DATA* data, threadData_t *threadData);
extern void Boat_eqFunction_11(DATA* data, threadData_t *threadData);
extern void Boat_eqFunction_12(DATA* data, threadData_t *threadData);
extern void Boat_eqFunction_13(DATA* data, threadData_t *threadData);
extern void Boat_eqFunction_14(DATA* data, threadData_t *threadData);

static void functionAlg_system0(DATA *data, threadData_t *threadData)
{
  Boat_eqFunction_9(data, threadData);
  threadData->lastEquationSolved = 9;
  Boat_eqFunction_10(data, threadData);
  threadData->lastEquationSolved = 10;
  Boat_eqFunction_11(data, threadData);
  threadData->lastEquationSolved = 11;
  Boat_eqFunction_12(data, threadData);
  threadData->lastEquationSolved = 12;
  Boat_eqFunction_13(data, threadData);
  threadData->lastEquationSolved = 13;
  Boat_eqFunction_14(data, threadData);
  threadData->lastEquationSolved = 14;
}
/* for continuous time variables */
int Boat_functionAlgebraics(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_ALGEBRAICS);
#endif
  data->simulationInfo->callStatistics.functionAlgebraics++;

  functionAlg_system0(data, threadData);

  Boat_function_savePreSynchronous(data, threadData);
  
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_ALGEBRAICS);
#endif

  TRACE_POP
  return 0;
}

#ifdef __cplusplus
}
#endif
