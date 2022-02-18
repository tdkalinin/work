/* Main Simulation File */

#if defined(__cplusplus)
extern "C" {
#endif

#include "Boat_model.h"
#include "simulation/solver/events.h"

#define prefixedName_performSimulation Boat_performSimulation
#define prefixedName_updateContinuousSystem Boat_updateContinuousSystem
#include <simulation/solver/perform_simulation.c.inc>

#define prefixedName_performQSSSimulation Boat_performQSSSimulation
#include <simulation/solver/perform_qss_simulation.c.inc>


/* dummy VARINFO and FILEINFO */
const FILE_INFO dummyFILE_INFO = omc_dummyFileInfo;
const VAR_INFO dummyVAR_INFO = omc_dummyVarInfo;

int Boat_input_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int Boat_input_function_init(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int Boat_input_function_updateStartValues(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int Boat_inputNames(DATA *data, char ** names){
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int Boat_data_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  TRACE_POP
  return 0;
}

int Boat_dataReconciliationInputNames(DATA *data, char ** names){
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int Boat_output_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int Boat_setc_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}


/*
equation index: 9
type: SIMPLE_ASSIGN
$cse1 = cos(theta)
*/
void Boat_eqFunction_9(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,9};
  data->localData[0]->realVars[4] /* $cse1 variable */ = cos(data->localData[0]->realVars[1] /* theta STATE(1) */);
  TRACE_POP
}
/*
equation index: 10
type: SIMPLE_ASSIGN
$cse2 = sin(theta)
*/
void Boat_eqFunction_10(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,10};
  data->localData[0]->realVars[5] /* $cse2 variable */ = sin(data->localData[0]->realVars[1] /* theta STATE(1) */);
  TRACE_POP
}
/*
equation index: 11
type: SIMPLE_ASSIGN
ylod = ro * $cse4
*/
void Boat_eqFunction_11(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,11};
  data->localData[0]->realVars[11] /* ylod variable */ = (data->localData[0]->realVars[0] /* ro STATE(1) */) * (data->localData[0]->realVars[7] /* $cse4 variable */);
  TRACE_POP
}
/*
equation index: 12
type: SIMPLE_ASSIGN
xlod = ro * $cse3
*/
void Boat_eqFunction_12(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,12};
  data->localData[0]->realVars[9] /* xlod variable */ = (data->localData[0]->realVars[0] /* ro STATE(1) */) * (data->localData[0]->realVars[6] /* $cse3 variable */);
  TRACE_POP
}
/*
equation index: 13
type: SIMPLE_ASSIGN
ykat = ro * $cse2
*/
void Boat_eqFunction_13(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,13};
  data->localData[0]->realVars[10] /* ykat variable */ = (data->localData[0]->realVars[0] /* ro STATE(1) */) * (data->localData[0]->realVars[5] /* $cse2 variable */);
  TRACE_POP
}
/*
equation index: 14
type: SIMPLE_ASSIGN
xkat = ro * $cse1
*/
void Boat_eqFunction_14(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,14};
  data->localData[0]->realVars[8] /* xkat variable */ = (data->localData[0]->realVars[0] /* ro STATE(1) */) * (data->localData[0]->realVars[4] /* $cse1 variable */);
  TRACE_POP
}
/*
equation index: 15
type: SIMPLE_ASSIGN
$DER.theta = 4.182104733265296 * v / ro
*/
void Boat_eqFunction_15(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,15};
  data->localData[0]->realVars[3] /* der(theta) STATE_DER */ = DIVISION_SIM((4.182104733265296) * (data->simulationInfo->realParameter[2] /* v PARAM */),data->localData[0]->realVars[0] /* ro STATE(1) */,"ro",equationIndexes);
  TRACE_POP
}
/*
equation index: 16
type: SIMPLE_ASSIGN
$DER.ro = v
*/
void Boat_eqFunction_16(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,16};
  data->localData[0]->realVars[2] /* der(ro) STATE_DER */ = data->simulationInfo->realParameter[2] /* v PARAM */;
  TRACE_POP
}

OMC_DISABLE_OPT
int Boat_functionDAE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  int equationIndexes[1] = {0};
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_DAE);
#endif

  data->simulationInfo->needToIterate = 0;
  data->simulationInfo->discreteCall = 1;
  Boat_functionLocalKnownVars(data, threadData);
  Boat_eqFunction_9(data, threadData);

  Boat_eqFunction_10(data, threadData);

  Boat_eqFunction_11(data, threadData);

  Boat_eqFunction_12(data, threadData);

  Boat_eqFunction_13(data, threadData);

  Boat_eqFunction_14(data, threadData);

  Boat_eqFunction_15(data, threadData);

  Boat_eqFunction_16(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_DAE);
#endif
  TRACE_POP
  return 0;
}


int Boat_functionLocalKnownVars(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}


/* forwarded equations */
extern void Boat_eqFunction_15(DATA* data, threadData_t *threadData);
extern void Boat_eqFunction_16(DATA* data, threadData_t *threadData);

static void functionODE_system0(DATA *data, threadData_t *threadData)
{
  Boat_eqFunction_15(data, threadData);
  threadData->lastEquationSolved = 15;
  Boat_eqFunction_16(data, threadData);
  threadData->lastEquationSolved = 16;
}

int Boat_functionODE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_FUNCTION_ODE);
#endif

  
  data->simulationInfo->callStatistics.functionODE++;
  
  Boat_functionLocalKnownVars(data, threadData);
  functionODE_system0(data, threadData);

#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_FUNCTION_ODE);
#endif

  TRACE_POP
  return 0;
}

/* forward the main in the simulation runtime */
extern int _main_SimulationRuntime(int argc, char**argv, DATA *data, threadData_t *threadData);

#include "Boat_12jac.h"
#include "Boat_13opt.h"

struct OpenModelicaGeneratedFunctionCallbacks Boat_callback = {
   (int (*)(DATA *, threadData_t *, void *)) Boat_performSimulation,    /* performSimulation */
   (int (*)(DATA *, threadData_t *, void *)) Boat_performQSSSimulation,    /* performQSSSimulation */
   Boat_updateContinuousSystem,    /* updateContinuousSystem */
   Boat_callExternalObjectDestructors,    /* callExternalObjectDestructors */
   NULL,    /* initialNonLinearSystem */
   NULL,    /* initialLinearSystem */
   NULL,    /* initialMixedSystem */
   #if !defined(OMC_NO_STATESELECTION)
   Boat_initializeStateSets,
   #else
   NULL,
   #endif    /* initializeStateSets */
   Boat_initializeDAEmodeData,
   Boat_functionODE,
   Boat_functionAlgebraics,
   Boat_functionDAE,
   Boat_functionLocalKnownVars,
   Boat_input_function,
   Boat_input_function_init,
   Boat_input_function_updateStartValues,
   Boat_data_function,
   Boat_output_function,
   Boat_setc_function,
   Boat_function_storeDelayed,
   Boat_function_storeSpatialDistribution,
   Boat_function_initSpatialDistribution,
   Boat_updateBoundVariableAttributes,
   Boat_functionInitialEquations,
   1, /* useHomotopy - 0: local homotopy (equidistant lambda), 1: global homotopy (equidistant lambda), 2: new global homotopy approach (adaptive lambda), 3: new local homotopy approach (adaptive lambda)*/
   NULL,
   Boat_functionRemovedInitialEquations,
   Boat_updateBoundParameters,
   Boat_checkForAsserts,
   Boat_function_ZeroCrossingsEquations,
   Boat_function_ZeroCrossings,
   Boat_function_updateRelations,
   Boat_zeroCrossingDescription,
   Boat_relationDescription,
   Boat_function_initSample,
   Boat_INDEX_JAC_A,
   Boat_INDEX_JAC_B,
   Boat_INDEX_JAC_C,
   Boat_INDEX_JAC_D,
   Boat_INDEX_JAC_F,
   Boat_initialAnalyticJacobianA,
   Boat_initialAnalyticJacobianB,
   Boat_initialAnalyticJacobianC,
   Boat_initialAnalyticJacobianD,
   Boat_initialAnalyticJacobianF,
   Boat_functionJacA_column,
   Boat_functionJacB_column,
   Boat_functionJacC_column,
   Boat_functionJacD_column,
   Boat_functionJacF_column,
   Boat_linear_model_frame,
   Boat_linear_model_datarecovery_frame,
   Boat_mayer,
   Boat_lagrange,
   Boat_pickUpBoundsForInputsInOptimization,
   Boat_setInputData,
   Boat_getTimeGrid,
   Boat_symbolicInlineSystem,
   Boat_function_initSynchronous,
   Boat_function_updateSynchronous,
   Boat_function_equationsSynchronous,
   Boat_inputNames,
   Boat_dataReconciliationInputNames,
   NULL,
   NULL,
   NULL,
   -1

};

#define _OMC_LIT_RESOURCE_0_name_data "Boat"
#define _OMC_LIT_RESOURCE_0_dir_data "C:/Users/TIMUR/work/2021-2022/Математическое моделирование/laboratory/lab02"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_0_name,4,_OMC_LIT_RESOURCE_0_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_0_dir,102,_OMC_LIT_RESOURCE_0_dir_data);

#define _OMC_LIT_RESOURCE_1_name_data "Complex"
#define _OMC_LIT_RESOURCE_1_dir_data "C:/Program Files/OpenModelica1.18.1-64bit/lib/omlibrary"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_1_name,7,_OMC_LIT_RESOURCE_1_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_1_dir,55,_OMC_LIT_RESOURCE_1_dir_data);

#define _OMC_LIT_RESOURCE_2_name_data "Modelica"
#define _OMC_LIT_RESOURCE_2_dir_data "C:/Program Files/OpenModelica1.18.1-64bit/lib/omlibrary/Modelica 4.0.0"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_2_name,8,_OMC_LIT_RESOURCE_2_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_2_dir,70,_OMC_LIT_RESOURCE_2_dir_data);

#define _OMC_LIT_RESOURCE_3_name_data "ModelicaReference"
#define _OMC_LIT_RESOURCE_3_dir_data "C:/Program Files/OpenModelica1.18.1-64bit/lib/omlibrary/ModelicaReference"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_3_name,17,_OMC_LIT_RESOURCE_3_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_3_dir,73,_OMC_LIT_RESOURCE_3_dir_data);

#define _OMC_LIT_RESOURCE_4_name_data "ModelicaServices"
#define _OMC_LIT_RESOURCE_4_dir_data "C:/Program Files/OpenModelica1.18.1-64bit/lib/omlibrary/ModelicaServices 4.0.0"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_4_name,16,_OMC_LIT_RESOURCE_4_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_4_dir,78,_OMC_LIT_RESOURCE_4_dir_data);

static const MMC_DEFSTRUCTLIT(_OMC_LIT_RESOURCES,10,MMC_ARRAY_TAG) {MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_0_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_0_dir), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_1_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_1_dir), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_2_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_2_dir), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_3_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_3_dir), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_4_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_4_dir)}};
void Boat_setupDataStruc(DATA *data, threadData_t *threadData)
{
  assertStreamPrint(threadData,0!=data, "Error while initialize Data");
  threadData->localRoots[LOCAL_ROOT_SIMULATION_DATA] = data;
  data->callback = &Boat_callback;
  OpenModelica_updateUriMapping(threadData, MMC_REFSTRUCTLIT(_OMC_LIT_RESOURCES));
  data->modelData->modelName = "Boat";
  data->modelData->modelFilePrefix = "Boat";
  data->modelData->resultFileName = NULL;
  data->modelData->modelDir = "C:/Users/TIMUR/work/2021-2022/Математическое моделирование/laboratory/lab02";
  data->modelData->modelGUID = "{e72936e7-4b2e-4f69-918f-18ce3f8fa8f7}";
  #if defined(OPENMODELICA_XML_FROM_FILE_AT_RUNTIME)
  data->modelData->initXMLData = NULL;
  data->modelData->modelDataXml.infoXMLData = NULL;
  #else
  #if defined(_MSC_VER) /* handle joke compilers */
  {
  /* for MSVC we encode a string like char x[] = {'a', 'b', 'c', '\0'} */
  /* because the string constant limit is 65535 bytes */
  static const char contents_init[] =
    #include "Boat_init.c"
    ;
  static const char contents_info[] =
    #include "Boat_info.c"
    ;
    data->modelData->initXMLData = contents_init;
    data->modelData->modelDataXml.infoXMLData = contents_info;
  }
  #else /* handle real compilers */
  data->modelData->initXMLData =
  #include "Boat_init.c"
    ;
  data->modelData->modelDataXml.infoXMLData =
  #include "Boat_info.c"
    ;
  #endif /* defined(_MSC_VER) */
  #endif /* defined(OPENMODELICA_XML_FROM_FILE_AT_RUNTIME) */
  data->modelData->runTestsuite = 0;
  
  data->modelData->nStates = 2;
  data->modelData->nVariablesReal = 12;
  data->modelData->nDiscreteReal = 0;
  data->modelData->nVariablesInteger = 0;
  data->modelData->nVariablesBoolean = 0;
  data->modelData->nVariablesString = 0;
  data->modelData->nParametersReal = 5;
  data->modelData->nParametersInteger = 0;
  data->modelData->nParametersBoolean = 0;
  data->modelData->nParametersString = 0;
  data->modelData->nInputVars = 0;
  data->modelData->nOutputVars = 0;
  
  data->modelData->nAliasReal = 0;
  data->modelData->nAliasInteger = 0;
  data->modelData->nAliasBoolean = 0;
  data->modelData->nAliasString = 0;
  
  data->modelData->nZeroCrossings = 0;
  data->modelData->nSamples = 0;
  data->modelData->nRelations = 0;
  data->modelData->nMathEvents = 0;
  data->modelData->nExtObjs = 0;
  
  data->modelData->modelDataXml.fileName = "Boat_info.json";
  data->modelData->modelDataXml.modelInfoXmlLength = 0;
  data->modelData->modelDataXml.nFunctions = 0;
  data->modelData->modelDataXml.nProfileBlocks = 0;
  data->modelData->modelDataXml.nEquations = 19;
  data->modelData->nMixedSystems = 0;
  data->modelData->nLinearSystems = 0;
  data->modelData->nNonLinearSystems = 0;
  data->modelData->nStateSets = 0;
  data->modelData->nJacobians = 5;
  data->modelData->nOptimizeConstraints = 0;
  data->modelData->nOptimizeFinalConstraints = 0;
  
  data->modelData->nDelayExpressions = 0;
  
  data->modelData->nClocks = 0;
  data->modelData->nSubClocks = 0;
  
  data->modelData->nSpatialDistributions = 0;
  
  data->modelData->nSensitivityVars = 0;
  data->modelData->nSensitivityParamVars = 0;
  data->modelData->nSetcVars = 0;
  data->modelData->ndataReconVars = 0;
  data->modelData->linearizationDumpLanguage =
  OMC_LINEARIZE_DUMP_LANGUAGE_MODELICA;
}

static int rml_execution_failed()
{
  fflush(NULL);
  fprintf(stderr, "Execution failed!\n");
  fflush(NULL);
  return 1;
}

#if defined(threadData)
#undef threadData
#endif
/* call the simulation runtime main from our main! */
int main(int argc, char**argv)
{
  int res;
  DATA data;
  MODEL_DATA modelData;
  SIMULATION_INFO simInfo;
  data.modelData = &modelData;
  data.simulationInfo = &simInfo;
  measure_time_flag = 0;
  compiledInDAEMode = 0;
  compiledWithSymSolver = 0;
  MMC_INIT(0);
  omc_alloc_interface.init();
  {
    MMC_TRY_TOP()
  
    MMC_TRY_STACK()
  
    Boat_setupDataStruc(&data, threadData);
    res = _main_SimulationRuntime(argc, argv, &data, threadData);
    
    MMC_ELSE()
    rml_execution_failed();
    fprintf(stderr, "Stack overflow detected and was not caught.\nSend us a bug report at https://trac.openmodelica.org/OpenModelica/newticket\n    Include the following trace:\n");
    printStacktraceMessages();
    fflush(NULL);
    return 1;
    MMC_CATCH_STACK()
    
    MMC_CATCH_TOP(return rml_execution_failed());
  }

  fflush(NULL);
  EXIT(res);
  return res;
}

#ifdef __cplusplus
}
#endif


