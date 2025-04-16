/* update bound parameters and variable attributes (start, nominal, min, max) */
#include "Reference_1_model.h"
#if defined(__cplusplus)
extern "C" {
#endif


/*
equation index: 748
type: SIMPLE_ASSIGN
$START.controlCold.PI.I.y = controlCold.PI.I.y_start
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_748(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,748};
  data->modelData->realVarsData[1].attribute /* controlCold.PI.I.y STATE(1) */.start = data->simulationInfo->realParameter[63] /* controlCold.PI.I.y_start PARAM */;
    data->localData[0]->realVars[1] /* controlCold.PI.I.y STATE(1) */ = data->modelData->realVarsData[1].attribute /* controlCold.PI.I.y STATE(1) */.start;
    infoStreamPrint(LOG_INIT_V, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[1].info /* controlCold.PI.I.y */.name, (modelica_real) data->localData[0]->realVars[1] /* controlCold.PI.I.y STATE(1) */);
  TRACE_POP
}

/*
equation index: 749
type: SIMPLE_ASSIGN
$START.receiver.h_out = receiver.h_0
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_749(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,749};
  data->modelData->realVarsData[131].attribute /* receiver.h_out variable */.start = data->simulationInfo->realParameter[233] /* receiver.h_0 PARAM */;
    data->localData[0]->realVars[131] /* receiver.h_out variable */ = data->modelData->realVarsData[131].attribute /* receiver.h_out variable */.start;
    infoStreamPrint(LOG_INIT_V, 0, "updated start value: %s(start=%g)", data->modelData->realVarsData[131].info /* receiver.h_out */.name, (modelica_real) data->localData[0]->realVars[131] /* receiver.h_out variable */);
  TRACE_POP
}
OMC_DISABLE_OPT
int Reference_1_updateBoundVariableAttributes(DATA *data, threadData_t *threadData)
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
  Reference_1_eqFunction_748(data, threadData);

  Reference_1_eqFunction_749(data, threadData);
  if (ACTIVE_STREAM(LOG_INIT)) messageClose(LOG_INIT);
  
  TRACE_POP
  return 0;
}

void Reference_1_updateBoundParameters_0(DATA *data, threadData_t *threadData);

/*
equation index: 757
type: SIMPLE_ASSIGN
wea.wtab.tableName = "weather"
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_757(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,757};
  data->simulationInfo->stringParameter[20] /* wea.wtab.tableName PARAM */ = _OMC_LIT52;
  TRACE_POP
}

/*
equation index: 758
type: SIMPLE_ASSIGN
wea.file = wea_file_sch
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_758(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,758};
  data->simulationInfo->stringParameter[16] /* wea.file PARAM */ = data->simulationInfo->stringParameter[22] /* wea_file_sch PARAM */;
  TRACE_POP
}

/*
equation index: 759
type: SIMPLE_ASSIGN
wea.file_act = SolarTherm.Models.Sources.Weather.weatherFileChecker(wea.file)
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_759(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,759};
  data->simulationInfo->stringParameter[17] /* wea.file_act PARAM */ = omc_SolarTherm_Models_Sources_Weather_weatherFileChecker(threadData, data->simulationInfo->stringParameter[16] /* wea.file PARAM */);
  TRACE_POP
}

/*
equation index: 760
type: SIMPLE_ASSIGN
wea.wtab.fileName = wea.file_act
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_760(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,760};
  data->simulationInfo->stringParameter[19] /* wea.wtab.fileName PARAM */ = data->simulationInfo->stringParameter[17] /* wea.file_act PARAM */;
  TRACE_POP
}

/*
equation index: 771
type: SIMPLE_ASSIGN
wea.wtab.tableID = Modelica.Blocks.Types.ExternalCombiTable1D.constructor(wea.wtab.tableName, if wea.wtab.fileName <> "NoName" and not Modelica.Utilities.Strings.isEmpty(wea.wtab.fileName) then wea.wtab.fileName else "NoName", {{}}, {wea.wtab.columns[1], wea.wtab.columns[2], wea.wtab.columns[3], wea.wtab.columns[4], wea.wtab.columns[5], wea.wtab.columns[6], wea.wtab.columns[7], wea.wtab.columns[8]}, Modelica.Blocks.Types.Smoothness.ContinuousDerivative, wea.wtab.extrapolation, wea.wtab.verboseRead)
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_771(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,771};
  integer_array tmp1;
  array_alloc_scalar_integer_array(&tmp1, 8, (modelica_integer)data->simulationInfo->integerParameter[80] /* wea.wtab.columns[1] PARAM */, (modelica_integer)data->simulationInfo->integerParameter[81] /* wea.wtab.columns[2] PARAM */, (modelica_integer)data->simulationInfo->integerParameter[82] /* wea.wtab.columns[3] PARAM */, (modelica_integer)data->simulationInfo->integerParameter[83] /* wea.wtab.columns[4] PARAM */, (modelica_integer)data->simulationInfo->integerParameter[84] /* wea.wtab.columns[5] PARAM */, (modelica_integer)data->simulationInfo->integerParameter[85] /* wea.wtab.columns[6] PARAM */, (modelica_integer)data->simulationInfo->integerParameter[86] /* wea.wtab.columns[7] PARAM */, (modelica_integer)data->simulationInfo->integerParameter[87] /* wea.wtab.columns[8] PARAM */);
  data->simulationInfo->extObjs[4] = omc_Modelica_Blocks_Types_ExternalCombiTable1D_constructor(threadData, data->simulationInfo->stringParameter[20] /* wea.wtab.tableName PARAM */, (((!stringEqual(data->simulationInfo->stringParameter[19] /* wea.wtab.fileName PARAM */, _OMC_LIT53)) && (!omc_Modelica_Utilities_Strings_isEmpty(threadData, data->simulationInfo->stringParameter[19] /* wea.wtab.fileName PARAM */)))?data->simulationInfo->stringParameter[19] /* wea.wtab.fileName PARAM */:_OMC_LIT53), _OMC_LIT54, tmp1, 2, data->simulationInfo->integerParameter[88] /* wea.wtab.extrapolation PARAM */, data->simulationInfo->booleanParameter[44] /* wea.wtab.verboseRead PARAM */);
  TRACE_POP
}

/*
equation index: 772
type: SIMPLE_ASSIGN
data.table.tableName = "data"
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_772(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,772};
  data->simulationInfo->stringParameter[2] /* data.table.tableName PARAM */ = _OMC_LIT55;
  TRACE_POP
}

/*
equation index: 773
type: SIMPLE_ASSIGN
data.file = wea_file
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_773(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,773};
  data->simulationInfo->stringParameter[0] /* data.file PARAM */ = data->simulationInfo->stringParameter[21] /* wea_file PARAM */;
  TRACE_POP
}

/*
equation index: 774
type: SIMPLE_ASSIGN
data.table.fileName = data.file
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_774(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,774};
  data->simulationInfo->stringParameter[1] /* data.table.fileName PARAM */ = data->simulationInfo->stringParameter[0] /* data.file PARAM */;
  TRACE_POP
}

/*
equation index: 788
type: SIMPLE_ASSIGN
data.table.shiftTime = data.table.startTime
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_788(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,788};
  data->simulationInfo->realParameter[119] /* data.table.shiftTime PARAM */ = data->simulationInfo->realParameter[120] /* data.table.startTime PARAM */;
  TRACE_POP
}

/*
equation index: 789
type: SIMPLE_ASSIGN
data.table.tableID = Modelica.Blocks.Types.ExternalCombiTimeTable.constructor(data.table.tableName, if data.table.fileName <> "NoName" and not Modelica.Utilities.Strings.isEmpty(data.table.fileName) then data.table.fileName else "NoName", {{}}, data.table.startTime, {data.table.columns[1], data.table.columns[2], data.table.columns[3], data.table.columns[4], data.table.columns[5], data.table.columns[6], data.table.columns[7], data.table.columns[8], data.table.columns[9], data.table.columns[10]}, Modelica.Blocks.Types.Smoothness.ContinuousDerivative, data.table.extrapolation, data.table.shiftTime, Modelica.Blocks.Types.TimeEvents.NoTimeEvents, data.table.verboseRead)
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_789(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,789};
  integer_array tmp3;
  array_alloc_scalar_integer_array(&tmp3, 10, (modelica_integer)data->simulationInfo->integerParameter[6] /* data.table.columns[1] PARAM */, (modelica_integer)data->simulationInfo->integerParameter[7] /* data.table.columns[2] PARAM */, (modelica_integer)data->simulationInfo->integerParameter[8] /* data.table.columns[3] PARAM */, (modelica_integer)data->simulationInfo->integerParameter[9] /* data.table.columns[4] PARAM */, (modelica_integer)data->simulationInfo->integerParameter[10] /* data.table.columns[5] PARAM */, (modelica_integer)data->simulationInfo->integerParameter[11] /* data.table.columns[6] PARAM */, (modelica_integer)data->simulationInfo->integerParameter[12] /* data.table.columns[7] PARAM */, (modelica_integer)data->simulationInfo->integerParameter[13] /* data.table.columns[8] PARAM */, (modelica_integer)data->simulationInfo->integerParameter[14] /* data.table.columns[9] PARAM */, (modelica_integer)data->simulationInfo->integerParameter[15] /* data.table.columns[10] PARAM */);
  data->simulationInfo->extObjs[0] = omc_Modelica_Blocks_Types_ExternalCombiTimeTable_constructor(threadData, data->simulationInfo->stringParameter[2] /* data.table.tableName PARAM */, (((!stringEqual(data->simulationInfo->stringParameter[1] /* data.table.fileName PARAM */, _OMC_LIT53)) && (!omc_Modelica_Utilities_Strings_isEmpty(threadData, data->simulationInfo->stringParameter[1] /* data.table.fileName PARAM */)))?data->simulationInfo->stringParameter[1] /* data.table.fileName PARAM */:_OMC_LIT53), _OMC_LIT54, data->simulationInfo->realParameter[120] /* data.table.startTime PARAM */, tmp3, 2, data->simulationInfo->integerParameter[16] /* data.table.extrapolation PARAM */, data->simulationInfo->realParameter[119] /* data.table.shiftTime PARAM */, 3, data->simulationInfo->booleanParameter[8] /* data.table.verboseRead PARAM */);
  TRACE_POP
}

/*
equation index: 790
type: SIMPLE_ASSIGN
heliostatField.optical.file = opt_file
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_790(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,790};
  data->simulationInfo->stringParameter[3] /* heliostatField.optical.file PARAM */ = data->simulationInfo->stringParameter[6] /* opt_file PARAM */;
  TRACE_POP
}

/*
equation index: 791
type: SIMPLE_ASSIGN
heliostatField.optical.nu_table.fileName = heliostatField.optical.file
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_791(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,791};
  data->simulationInfo->stringParameter[4] /* heliostatField.optical.nu_table.fileName PARAM */ = data->simulationInfo->stringParameter[3] /* heliostatField.optical.file PARAM */;
  TRACE_POP
}

/*
equation index: 792
type: SIMPLE_ASSIGN
heliostatField.optical.nu_table.tableID = Modelica.Blocks.Types.ExternalCombiTable2D.constructor(heliostatField.optical.nu_table.tableName, if heliostatField.optical.nu_table.fileName <> "NoName" and not Modelica.Utilities.Strings.isEmpty(heliostatField.optical.nu_table.fileName) then heliostatField.optical.nu_table.fileName else "NoName", {{}}, Modelica.Blocks.Types.Smoothness.ContinuousDerivative, heliostatField.optical.nu_table.extrapolation, heliostatField.optical.nu_table.verboseRead)
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_792(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,792};
  data->simulationInfo->extObjs[1] = omc_Modelica_Blocks_Types_ExternalCombiTable2D_constructor(threadData, data->simulationInfo->stringParameter[5] /* heliostatField.optical.nu_table.tableName PARAM */, (((!stringEqual(data->simulationInfo->stringParameter[4] /* heliostatField.optical.nu_table.fileName PARAM */, _OMC_LIT53)) && (!omc_Modelica_Utilities_Strings_isEmpty(threadData, data->simulationInfo->stringParameter[4] /* heliostatField.optical.nu_table.fileName PARAM */)))?data->simulationInfo->stringParameter[4] /* heliostatField.optical.nu_table.fileName PARAM */:_OMC_LIT53), _OMC_LIT54, 2, data->simulationInfo->integerParameter[23] /* heliostatField.optical.nu_table.extrapolation PARAM */, data->simulationInfo->booleanParameter[13] /* heliostatField.optical.nu_table.verboseRead PARAM */);
  TRACE_POP
}

/*
equation index: 793
type: SIMPLE_ASSIGN
prices.fileName = pri_file
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_793(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,793};
  data->simulationInfo->stringParameter[8] /* prices.fileName PARAM */ = data->simulationInfo->stringParameter[7] /* pri_file PARAM */;
  TRACE_POP
}

/*
equation index: 794
type: SIMPLE_ASSIGN
prices.shiftTime = prices.startTime
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_794(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,794};
  data->simulationInfo->realParameter[211] /* prices.shiftTime PARAM */ = data->simulationInfo->realParameter[212] /* prices.startTime PARAM */;
  TRACE_POP
}

/*
equation index: 795
type: SIMPLE_ASSIGN
prices.tableID = Modelica.Blocks.Types.ExternalCombiTimeTable.constructor(prices.tableName, if prices.fileName <> "NoName" and not Modelica.Utilities.Strings.isEmpty(prices.fileName) then prices.fileName else "NoName", {{}}, prices.startTime, {prices.columns[1]}, Modelica.Blocks.Types.Smoothness.ConstantSegments, prices.extrapolation, prices.shiftTime, Modelica.Blocks.Types.TimeEvents.Always, prices.verboseRead)
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_795(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,795};
  integer_array tmp6;
  array_alloc_scalar_integer_array(&tmp6, 1, (modelica_integer)data->simulationInfo->integerParameter[26] /* prices.columns[1] PARAM */);
  data->simulationInfo->extObjs[2] = omc_Modelica_Blocks_Types_ExternalCombiTimeTable_constructor(threadData, data->simulationInfo->stringParameter[9] /* prices.tableName PARAM */, (((!stringEqual(data->simulationInfo->stringParameter[8] /* prices.fileName PARAM */, _OMC_LIT53)) && (!omc_Modelica_Utilities_Strings_isEmpty(threadData, data->simulationInfo->stringParameter[8] /* prices.fileName PARAM */)))?data->simulationInfo->stringParameter[8] /* prices.fileName PARAM */:_OMC_LIT53), _OMC_LIT54, data->simulationInfo->realParameter[212] /* prices.startTime PARAM */, tmp6, 3, data->simulationInfo->integerParameter[27] /* prices.extrapolation PARAM */, data->simulationInfo->realParameter[211] /* prices.shiftTime PARAM */, 1, data->simulationInfo->booleanParameter[22] /* prices.verboseRead PARAM */);
  TRACE_POP
}

/*
equation index: 796
type: SIMPLE_ASSIGN
sch_fixed.daily[1].table.tableName = sch_fixed.daily[1].name
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_796(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,796};
  data->simulationInfo->stringParameter[14] /* sch_fixed.daily[1].table.tableName PARAM */ = data->simulationInfo->stringParameter[12] /* sch_fixed.daily[1].name PARAM */;
  TRACE_POP
}

/*
equation index: 797
type: SIMPLE_ASSIGN
sch_fixed.file = sch_file
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_797(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,797};
  data->simulationInfo->stringParameter[15] /* sch_fixed.file PARAM */ = data->simulationInfo->stringParameter[10] /* sch_file PARAM */;
  TRACE_POP
}

/*
equation index: 798
type: SIMPLE_ASSIGN
sch_fixed.daily[1].file = sch_fixed.file
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_798(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,798};
  data->simulationInfo->stringParameter[11] /* sch_fixed.daily[1].file PARAM */ = data->simulationInfo->stringParameter[15] /* sch_fixed.file PARAM */;
  TRACE_POP
}

/*
equation index: 799
type: SIMPLE_ASSIGN
sch_fixed.daily[1].table.fileName = sch_fixed.daily[1].file
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_799(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,799};
  data->simulationInfo->stringParameter[13] /* sch_fixed.daily[1].table.fileName PARAM */ = data->simulationInfo->stringParameter[11] /* sch_fixed.daily[1].file PARAM */;
  TRACE_POP
}

/*
equation index: 800
type: SIMPLE_ASSIGN
sch_fixed.daily[1].table.tableID = Modelica.Blocks.Types.ExternalCombiTable1D.constructor(sch_fixed.daily[1].table.tableName, if sch_fixed.daily[1].table.fileName <> "NoName" and not Modelica.Utilities.Strings.isEmpty(sch_fixed.daily[1].table.fileName) then sch_fixed.daily[1].table.fileName else "NoName", {{}}, {sch_fixed.daily[1].table.columns[1]}, Modelica.Blocks.Types.Smoothness.ConstantSegments, sch_fixed.daily[1].table.extrapolation, sch_fixed.daily[1].table.verboseRead)
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_800(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,800};
  integer_array tmp8;
  array_alloc_scalar_integer_array(&tmp8, 1, (modelica_integer)data->simulationInfo->integerParameter[32] /* sch_fixed.daily[1].table.columns[1] PARAM */);
  data->simulationInfo->extObjs[3] = omc_Modelica_Blocks_Types_ExternalCombiTable1D_constructor(threadData, data->simulationInfo->stringParameter[14] /* sch_fixed.daily[1].table.tableName PARAM */, (((!stringEqual(data->simulationInfo->stringParameter[13] /* sch_fixed.daily[1].table.fileName PARAM */, _OMC_LIT53)) && (!omc_Modelica_Utilities_Strings_isEmpty(threadData, data->simulationInfo->stringParameter[13] /* sch_fixed.daily[1].table.fileName PARAM */)))?data->simulationInfo->stringParameter[13] /* sch_fixed.daily[1].table.fileName PARAM */:_OMC_LIT53), _OMC_LIT54, tmp8, 3, data->simulationInfo->integerParameter[33] /* sch_fixed.daily[1].table.extrapolation PARAM */, data->simulationInfo->booleanParameter[27] /* sch_fixed.daily[1].table.verboseRead PARAM */);
  TRACE_POP
}

/*
equation index: 801
type: SIMPLE_ASSIGN
market.price.price = market.price.price_annual
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_801(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,801};
  data->simulationInfo->realParameter[169] /* market.price.price PARAM */ = data->simulationInfo->realParameter[170] /* market.price.price_annual PARAM */;
  TRACE_POP
}

/*
equation index: 802
type: SIMPLE_ASSIGN
controlCold.T_ref = T_hot_set
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_802(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,802};
  data->simulationInfo->realParameter[79] /* controlCold.T_ref PARAM */ = data->simulationInfo->realParameter[38] /* T_hot_set PARAM */;
  TRACE_POP
}

/*
equation index: 803
type: SIMPLE_ASSIGN
controlCold.feedback.u1 = controlCold.T_ref
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_803(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,803};
  data->simulationInfo->realParameter[84] /* controlCold.feedback.u1 PARAM */ = data->simulationInfo->realParameter[79] /* controlCold.T_ref PARAM */;
  TRACE_POP
}

/*
equation index: 804
type: SIMPLE_ASSIGN
controlCold.T_ref_input.y = controlCold.T_ref
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_804(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,804};
  data->simulationInfo->realParameter[80] /* controlCold.T_ref_input.y PARAM */ = data->simulationInfo->realParameter[79] /* controlCold.T_ref PARAM */;
  TRACE_POP
}

/*
equation index: 805
type: SIMPLE_ASSIGN
sch_fixed.month.map[12] = sch_fixed.mmap[12]
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_805(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,805};
  data->simulationInfo->integerParameter[59] /* sch_fixed.month.map[12] PARAM */ = data->simulationInfo->integerParameter[47] /* sch_fixed.mmap[12] PARAM */;
  TRACE_POP
}

/*
equation index: 806
type: SIMPLE_ASSIGN
sch_fixed.month.map[11] = sch_fixed.mmap[11]
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_806(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,806};
  data->simulationInfo->integerParameter[58] /* sch_fixed.month.map[11] PARAM */ = data->simulationInfo->integerParameter[46] /* sch_fixed.mmap[11] PARAM */;
  TRACE_POP
}

/*
equation index: 807
type: SIMPLE_ASSIGN
sch_fixed.month.map[10] = sch_fixed.mmap[10]
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_807(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,807};
  data->simulationInfo->integerParameter[57] /* sch_fixed.month.map[10] PARAM */ = data->simulationInfo->integerParameter[45] /* sch_fixed.mmap[10] PARAM */;
  TRACE_POP
}

/*
equation index: 808
type: SIMPLE_ASSIGN
sch_fixed.month.map[9] = sch_fixed.mmap[9]
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_808(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,808};
  data->simulationInfo->integerParameter[56] /* sch_fixed.month.map[9] PARAM */ = data->simulationInfo->integerParameter[44] /* sch_fixed.mmap[9] PARAM */;
  TRACE_POP
}

/*
equation index: 809
type: SIMPLE_ASSIGN
sch_fixed.month.map[8] = sch_fixed.mmap[8]
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_809(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,809};
  data->simulationInfo->integerParameter[55] /* sch_fixed.month.map[8] PARAM */ = data->simulationInfo->integerParameter[43] /* sch_fixed.mmap[8] PARAM */;
  TRACE_POP
}

/*
equation index: 810
type: SIMPLE_ASSIGN
sch_fixed.month.map[7] = sch_fixed.mmap[7]
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_810(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,810};
  data->simulationInfo->integerParameter[54] /* sch_fixed.month.map[7] PARAM */ = data->simulationInfo->integerParameter[42] /* sch_fixed.mmap[7] PARAM */;
  TRACE_POP
}

/*
equation index: 811
type: SIMPLE_ASSIGN
sch_fixed.month.map[6] = sch_fixed.mmap[6]
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_811(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,811};
  data->simulationInfo->integerParameter[53] /* sch_fixed.month.map[6] PARAM */ = data->simulationInfo->integerParameter[41] /* sch_fixed.mmap[6] PARAM */;
  TRACE_POP
}

/*
equation index: 812
type: SIMPLE_ASSIGN
sch_fixed.month.map[5] = sch_fixed.mmap[5]
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_812(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,812};
  data->simulationInfo->integerParameter[52] /* sch_fixed.month.map[5] PARAM */ = data->simulationInfo->integerParameter[40] /* sch_fixed.mmap[5] PARAM */;
  TRACE_POP
}

/*
equation index: 813
type: SIMPLE_ASSIGN
sch_fixed.month.map[4] = sch_fixed.mmap[4]
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_813(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,813};
  data->simulationInfo->integerParameter[51] /* sch_fixed.month.map[4] PARAM */ = data->simulationInfo->integerParameter[39] /* sch_fixed.mmap[4] PARAM */;
  TRACE_POP
}

/*
equation index: 814
type: SIMPLE_ASSIGN
sch_fixed.month.map[3] = sch_fixed.mmap[3]
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_814(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,814};
  data->simulationInfo->integerParameter[50] /* sch_fixed.month.map[3] PARAM */ = data->simulationInfo->integerParameter[38] /* sch_fixed.mmap[3] PARAM */;
  TRACE_POP
}

/*
equation index: 815
type: SIMPLE_ASSIGN
sch_fixed.month.map[2] = sch_fixed.mmap[2]
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_815(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,815};
  data->simulationInfo->integerParameter[49] /* sch_fixed.month.map[2] PARAM */ = data->simulationInfo->integerParameter[37] /* sch_fixed.mmap[2] PARAM */;
  TRACE_POP
}

/*
equation index: 816
type: SIMPLE_ASSIGN
sch_fixed.month.map[1] = sch_fixed.mmap[1]
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_816(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,816};
  data->simulationInfo->integerParameter[48] /* sch_fixed.month.map[1] PARAM */ = data->simulationInfo->integerParameter[36] /* sch_fixed.mmap[1] PARAM */;
  TRACE_POP
}

/*
equation index: 817
type: SIMPLE_ASSIGN
sch_fixed.week[1].map[7] = sch_fixed.wmap[1,7]
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_817(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,817};
  data->simulationInfo->integerParameter[68] /* sch_fixed.week[1].map[7] PARAM */ = data->simulationInfo->integerParameter[75] /* sch_fixed.wmap[1,7] PARAM */;
  TRACE_POP
}

/*
equation index: 818
type: SIMPLE_ASSIGN
sch_fixed.week[1].map[6] = sch_fixed.wmap[1,6]
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_818(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,818};
  data->simulationInfo->integerParameter[67] /* sch_fixed.week[1].map[6] PARAM */ = data->simulationInfo->integerParameter[74] /* sch_fixed.wmap[1,6] PARAM */;
  TRACE_POP
}

/*
equation index: 819
type: SIMPLE_ASSIGN
sch_fixed.week[1].map[5] = sch_fixed.wmap[1,5]
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_819(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,819};
  data->simulationInfo->integerParameter[66] /* sch_fixed.week[1].map[5] PARAM */ = data->simulationInfo->integerParameter[73] /* sch_fixed.wmap[1,5] PARAM */;
  TRACE_POP
}

/*
equation index: 820
type: SIMPLE_ASSIGN
sch_fixed.week[1].map[4] = sch_fixed.wmap[1,4]
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_820(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,820};
  data->simulationInfo->integerParameter[65] /* sch_fixed.week[1].map[4] PARAM */ = data->simulationInfo->integerParameter[72] /* sch_fixed.wmap[1,4] PARAM */;
  TRACE_POP
}

/*
equation index: 821
type: SIMPLE_ASSIGN
sch_fixed.week[1].map[3] = sch_fixed.wmap[1,3]
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_821(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,821};
  data->simulationInfo->integerParameter[64] /* sch_fixed.week[1].map[3] PARAM */ = data->simulationInfo->integerParameter[71] /* sch_fixed.wmap[1,3] PARAM */;
  TRACE_POP
}

/*
equation index: 822
type: SIMPLE_ASSIGN
sch_fixed.week[1].map[2] = sch_fixed.wmap[1,2]
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_822(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,822};
  data->simulationInfo->integerParameter[63] /* sch_fixed.week[1].map[2] PARAM */ = data->simulationInfo->integerParameter[70] /* sch_fixed.wmap[1,2] PARAM */;
  TRACE_POP
}

/*
equation index: 823
type: SIMPLE_ASSIGN
sch_fixed.week[1].map[1] = sch_fixed.wmap[1,1]
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_823(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,823};
  data->simulationInfo->integerParameter[62] /* sch_fixed.week[1].map[1] PARAM */ = data->simulationInfo->integerParameter[69] /* sch_fixed.wmap[1,1] PARAM */;
  TRACE_POP
}

/*
equation index: 824
type: SIMPLE_ASSIGN
sch_fixed.daily[1].table.u_max = Modelica.Blocks.Tables.Internal.getTable1DAbscissaUmax(sch_fixed.daily[1].table.tableID)
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_824(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,824};
  data->simulationInfo->realParameter[240] /* sch_fixed.daily[1].table.u_max PARAM */ = omc_Modelica_Blocks_Tables_Internal_getTable1DAbscissaUmax(threadData, data->simulationInfo->extObjs[3]);
  TRACE_POP
}

/*
equation index: 825
type: SIMPLE_ASSIGN
sch_fixed.daily[1].table.u_min = Modelica.Blocks.Tables.Internal.getTable1DAbscissaUmin(sch_fixed.daily[1].table.tableID)
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_825(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,825};
  data->simulationInfo->realParameter[241] /* sch_fixed.daily[1].table.u_min PARAM */ = omc_Modelica_Blocks_Tables_Internal_getTable1DAbscissaUmin(threadData, data->simulationInfo->extObjs[3]);
  TRACE_POP
}

/*
equation index: 831
type: SIMPLE_ASSIGN
prices.p_offset[1] = prices.offset[1]
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_831(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,831};
  data->simulationInfo->realParameter[210] /* prices.p_offset[1] PARAM */ = data->simulationInfo->realParameter[209] /* prices.offset[1] PARAM */;
  TRACE_POP
}

/*
equation index: 832
type: SIMPLE_ASSIGN
prices.t_maxScaled = Modelica.Blocks.Tables.Internal.getTimeTableTmax(prices.tableID)
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_832(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,832};
  data->simulationInfo->realParameter[214] /* prices.t_maxScaled PARAM */ = omc_Modelica_Blocks_Tables_Internal_getTimeTableTmax(threadData, data->simulationInfo->extObjs[2]);
  TRACE_POP
}

/*
equation index: 833
type: SIMPLE_ASSIGN
prices.t_minScaled = Modelica.Blocks.Tables.Internal.getTimeTableTmin(prices.tableID)
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_833(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,833};
  data->simulationInfo->realParameter[216] /* prices.t_minScaled PARAM */ = omc_Modelica_Blocks_Tables_Internal_getTimeTableTmin(threadData, data->simulationInfo->extObjs[2]);
  TRACE_POP
}

/*
equation index: 834
type: SIMPLE_ASSIGN
prices.t_max = prices.t_maxScaled
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_834(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,834};
  data->simulationInfo->realParameter[213] /* prices.t_max PARAM */ = data->simulationInfo->realParameter[214] /* prices.t_maxScaled PARAM */;
  TRACE_POP
}

/*
equation index: 835
type: SIMPLE_ASSIGN
prices.t_min = prices.t_minScaled
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_835(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,835};
  data->simulationInfo->realParameter[215] /* prices.t_min PARAM */ = data->simulationInfo->realParameter[216] /* prices.t_minScaled PARAM */;
  TRACE_POP
}

/*
equation index: 843
type: SIMPLE_ASSIGN
powerBlock.h_out_ref = powerBlock.state_out_ref.h
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_843(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,843};
  data->simulationInfo->realParameter[191] /* powerBlock.h_out_ref PARAM */ = data->simulationInfo->realParameter[199] /* powerBlock.state_out_ref.h PARAM */;
  TRACE_POP
}

/*
equation index: 845
type: SIMPLE_ASSIGN
powerBlock.h_in_ref = powerBlock.state_in_ref.h
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_845(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,845};
  data->simulationInfo->realParameter[190] /* powerBlock.h_in_ref PARAM */ = data->simulationInfo->realParameter[197] /* powerBlock.state_in_ref.h PARAM */;
  TRACE_POP
}

/*
equation index: 848
type: SIMPLE_ASSIGN
Q_flow_des = P_gross / eff_blk
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_848(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,848};
  data->simulationInfo->realParameter[31] /* Q_flow_des PARAM */ = DIVISION_SIM(data->simulationInfo->realParameter[27] /* P_gross PARAM */,data->simulationInfo->realParameter[126] /* eff_blk PARAM */,"eff_blk",equationIndexes);
  TRACE_POP
}

/*
equation index: 849
type: SIMPLE_ASSIGN
powerBlock.Q_flow_ref = Q_flow_des
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_849(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,849};
  data->simulationInfo->realParameter[180] /* powerBlock.Q_flow_ref PARAM */ = data->simulationInfo->realParameter[31] /* Q_flow_des PARAM */;
  TRACE_POP
}

/*
equation index: 850
type: SIMPLE_ASSIGN
powerBlock.m_flow_ref = powerBlock.Q_flow_ref / (powerBlock.h_in_ref - powerBlock.h_out_ref)
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_850(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,850};
  data->simulationInfo->realParameter[192] /* powerBlock.m_flow_ref PARAM */ = DIVISION_SIM(data->simulationInfo->realParameter[180] /* powerBlock.Q_flow_ref PARAM */,data->simulationInfo->realParameter[190] /* powerBlock.h_in_ref PARAM */ - data->simulationInfo->realParameter[191] /* powerBlock.h_out_ref PARAM */,"powerBlock.h_in_ref - powerBlock.h_out_ref",equationIndexes);
  TRACE_POP
}

/*
equation index: 851
type: SIMPLE_ASSIGN
powerBlock.cool.T_des = blk_T_amb_des
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_851(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,851};
  data->simulationInfo->realParameter[186] /* powerBlock.cool.T_des PARAM */ = data->simulationInfo->realParameter[50] /* blk_T_amb_des PARAM */;
  TRACE_POP
}

/*
equation index: 852
type: SIMPLE_ASSIGN
powerBlock.cycle.p_bo = p_blk
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_852(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,852};
  data->simulationInfo->realParameter[189] /* powerBlock.cycle.p_bo PARAM */ = data->simulationInfo->realParameter[176] /* p_blk PARAM */;
  TRACE_POP
}

/*
equation index: 853
type: SIMPLE_ASSIGN
powerBlock.cycle.Tsat_ref = Modelica.Media.Water.IF97_Utilities.BaseIF97.Basic.tsat(powerBlock.cycle.p_bo)
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_853(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,853};
  data->simulationInfo->realParameter[188] /* powerBlock.cycle.Tsat_ref PARAM */ = omc_Modelica_Media_Water_IF97__Utilities_BaseIF97_Basic_tsat(threadData, data->simulationInfo->realParameter[189] /* powerBlock.cycle.p_bo PARAM */);
  TRACE_POP
}

/*
equation index: 854
type: SIMPLE_ASSIGN
powerBlock.T_in_ref = T_in_ref_blk
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_854(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,854};
  data->simulationInfo->realParameter[182] /* powerBlock.T_in_ref PARAM */ = data->simulationInfo->realParameter[40] /* T_in_ref_blk PARAM */;
  TRACE_POP
}

/*
equation index: 855
type: SIMPLE_ASSIGN
powerBlock.cycle.T_in_ref = powerBlock.T_in_ref
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_855(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,855};
  data->simulationInfo->realParameter[187] /* powerBlock.cycle.T_in_ref PARAM */ = data->simulationInfo->realParameter[182] /* powerBlock.T_in_ref PARAM */;
  TRACE_POP
}

/*
equation index: 856
type: SIMPLE_ASSIGN
W_base_blk = par_fix_fr * P_gross
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_856(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,856};
  data->simulationInfo->realParameter[44] /* W_base_blk PARAM */ = (data->simulationInfo->realParameter[178] /* par_fix_fr PARAM */) * (data->simulationInfo->realParameter[27] /* P_gross PARAM */);
  TRACE_POP
}

/*
equation index: 857
type: SIMPLE_ASSIGN
powerBlock.W_base = W_base_blk
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_857(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,857};
  data->simulationInfo->realParameter[184] /* powerBlock.W_base PARAM */ = data->simulationInfo->realParameter[44] /* W_base_blk PARAM */;
  TRACE_POP
}

/*
equation index: 858
type: SIMPLE_ASSIGN
powerBlock.nu_net = nu_net_blk
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_858(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,858};
  data->simulationInfo->realParameter[195] /* powerBlock.nu_net PARAM */ = data->simulationInfo->realParameter[174] /* nu_net_blk PARAM */;
  TRACE_POP
}

/*
equation index: 860
type: SIMPLE_ASSIGN
powerBlock.T_des = blk_T_amb_des
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_860(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,860};
  data->simulationInfo->realParameter[181] /* powerBlock.T_des PARAM */ = data->simulationInfo->realParameter[50] /* blk_T_amb_des PARAM */;
  TRACE_POP
}

/*
equation index: 862
type: SIMPLE_ASSIGN
powerBlock.nu_min = nu_min_blk
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_862(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,862};
  data->simulationInfo->realParameter[194] /* powerBlock.nu_min PARAM */ = data->simulationInfo->realParameter[172] /* nu_min_blk PARAM */;
  TRACE_POP
}

/*
equation index: 863
type: SIMPLE_ASSIGN
powerBlock.p_bo = p_blk
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_863(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,863};
  data->simulationInfo->realParameter[196] /* powerBlock.p_bo PARAM */ = data->simulationInfo->realParameter[176] /* p_blk PARAM */;
  TRACE_POP
}

/*
equation index: 864
type: SIMPLE_ASSIGN
powerBlock.T_out_ref = T_out_ref_blk
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_864(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,864};
  data->simulationInfo->realParameter[183] /* powerBlock.T_out_ref PARAM */ = data->simulationInfo->realParameter[41] /* T_out_ref_blk PARAM */;
  TRACE_POP
}

/*
equation index: 865
type: SIMPLE_ASSIGN
powerBlock.W_des = P_gross
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_865(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,865};
  data->simulationInfo->realParameter[185] /* powerBlock.W_des PARAM */ = data->simulationInfo->realParameter[27] /* P_gross PARAM */;
  TRACE_POP
}

/*
equation index: 866
type: SIMPLE_ASSIGN
controlCold.L_df_on = cold_tnk_defocus_lb
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_866(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,866};
  data->simulationInfo->realParameter[57] /* controlCold.L_df_on PARAM */ = data->simulationInfo->realParameter[53] /* cold_tnk_defocus_lb PARAM */;
  TRACE_POP
}

/*
equation index: 867
type: SIMPLE_ASSIGN
controlCold.defocus_logic.level_min = controlCold.L_df_on
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_867(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,867};
  data->simulationInfo->realParameter[83] /* controlCold.defocus_logic.level_min PARAM */ = data->simulationInfo->realParameter[57] /* controlCold.L_df_on PARAM */;
  TRACE_POP
}

/*
equation index: 868
type: SIMPLE_ASSIGN
controlCold.L_df_off = cold_tnk_defocus_ub
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_868(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,868};
  data->simulationInfo->realParameter[56] /* controlCold.L_df_off PARAM */ = data->simulationInfo->realParameter[54] /* cold_tnk_defocus_ub PARAM */;
  TRACE_POP
}

/*
equation index: 869
type: SIMPLE_ASSIGN
controlCold.defocus_logic.level_max = controlCold.L_df_off
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_869(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,869};
  data->simulationInfo->realParameter[82] /* controlCold.defocus_logic.level_max PARAM */ = data->simulationInfo->realParameter[56] /* controlCold.L_df_off PARAM */;
  TRACE_POP
}

/*
equation index: 870
type: SIMPLE_ASSIGN
controlCold.L_off = cold_tnk_crit_lb
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_870(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,870};
  data->simulationInfo->realParameter[58] /* controlCold.L_off PARAM */ = data->simulationInfo->realParameter[51] /* cold_tnk_crit_lb PARAM */;
  TRACE_POP
}

/*
equation index: 871
type: SIMPLE_ASSIGN
controlCold.hotTankLogic.level_min = controlCold.L_off
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_871(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,871};
  data->simulationInfo->realParameter[86] /* controlCold.hotTankLogic.level_min PARAM */ = data->simulationInfo->realParameter[58] /* controlCold.L_off PARAM */;
  TRACE_POP
}

/*
equation index: 872
type: SIMPLE_ASSIGN
controlCold.PI.gain1.k = 1.0 / controlCold.PI.Tt
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_872(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,872};
  data->simulationInfo->realParameter[73] /* controlCold.PI.gain1.k PARAM */ = DIVISION_SIM(1.0,data->simulationInfo->realParameter[68] /* controlCold.PI.Tt PARAM */,"controlCold.PI.Tt",equationIndexes);
  TRACE_POP
}

/*
equation index: 876
type: SIMPLE_ASSIGN
controlCold.PI.uMin = controlCold.m_flow_min
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_876(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,876};
  data->simulationInfo->realParameter[77] /* controlCold.PI.uMin PARAM */ = data->simulationInfo->realParameter[88] /* controlCold.m_flow_min PARAM */;
  TRACE_POP
}

/*
equation index: 877
type: SIMPLE_ASSIGN
controlCold.PI.limiter.uMin = controlCold.PI.uMin
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_877(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,877};
  data->simulationInfo->realParameter[75] /* controlCold.PI.limiter.uMin PARAM */ = data->simulationInfo->realParameter[77] /* controlCold.PI.uMin PARAM */;
  TRACE_POP
}

/*
equation index: 878
type: SIMPLE_ASSIGN
eta_rec_des = 1.0 - rec_fr
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_878(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,878};
  data->simulationInfo->realParameter[129] /* eta_rec_des PARAM */ = 1.0 - data->simulationInfo->realParameter[223] /* rec_fr PARAM */;
  TRACE_POP
}

/*
equation index: 879
type: SIMPLE_ASSIGN
h_cold_set = state_cold_set.h
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_879(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,879};
  data->simulationInfo->realParameter[131] /* h_cold_set PARAM */ = data->simulationInfo->realParameter[243] /* state_cold_set.h PARAM */;
  TRACE_POP
}

/*
equation index: 880
type: SIMPLE_ASSIGN
h_hot_set = state_hot_set.h
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_880(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,880};
  data->simulationInfo->realParameter[132] /* h_hot_set PARAM */ = data->simulationInfo->realParameter[245] /* state_hot_set.h PARAM */;
  TRACE_POP
}

/*
equation index: 881
type: SIMPLE_ASSIGN
m_flow_fac = R_des * eta_rec_des / (h_hot_set - h_cold_set)
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_881(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,881};
  data->simulationInfo->realParameter[165] /* m_flow_fac PARAM */ = (data->simulationInfo->realParameter[32] /* R_des PARAM */) * (DIVISION_SIM(data->simulationInfo->realParameter[129] /* eta_rec_des PARAM */,data->simulationInfo->realParameter[132] /* h_hot_set PARAM */ - data->simulationInfo->realParameter[131] /* h_cold_set PARAM */,"h_hot_set - h_cold_set",equationIndexes));
  TRACE_POP
}

/*
equation index: 882
type: SIMPLE_ASSIGN
m_flow_rec_max = 1.2 * m_flow_fac
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_882(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,882};
  data->simulationInfo->realParameter[166] /* m_flow_rec_max PARAM */ = (1.2) * (data->simulationInfo->realParameter[165] /* m_flow_fac PARAM */);
  TRACE_POP
}

/*
equation index: 883
type: SIMPLE_ASSIGN
controlCold.m_flow_max = m_flow_rec_max
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_883(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,883};
  data->simulationInfo->realParameter[87] /* controlCold.m_flow_max PARAM */ = data->simulationInfo->realParameter[166] /* m_flow_rec_max PARAM */;
  TRACE_POP
}

/*
equation index: 884
type: SIMPLE_ASSIGN
controlCold.PI.uMax = controlCold.m_flow_max
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_884(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,884};
  data->simulationInfo->realParameter[76] /* controlCold.PI.uMax PARAM */ = data->simulationInfo->realParameter[87] /* controlCold.m_flow_max PARAM */;
  TRACE_POP
}

/*
equation index: 885
type: SIMPLE_ASSIGN
controlCold.PI.limiter.uMax = controlCold.PI.uMax
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_885(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,885};
  data->simulationInfo->realParameter[74] /* controlCold.PI.limiter.uMax PARAM */ = data->simulationInfo->realParameter[76] /* controlCold.PI.uMax PARAM */;
  TRACE_POP
}

/*
equation index: 886
type: SIMPLE_ASSIGN
controlCold.Ti = Ti
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_886(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,886};
  data->simulationInfo->realParameter[81] /* controlCold.Ti PARAM */ = data->simulationInfo->realParameter[42] /* Ti PARAM */;
  TRACE_POP
}

/*
equation index: 887
type: SIMPLE_ASSIGN
controlCold.PI.Ti = controlCold.Ti
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_887(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,887};
  data->simulationInfo->realParameter[67] /* controlCold.PI.Ti PARAM */ = data->simulationInfo->realParameter[81] /* controlCold.Ti PARAM */;
  TRACE_POP
}

/*
equation index: 888
type: SIMPLE_ASSIGN
controlCold.Kp = Kp
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_888(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,888};
  data->simulationInfo->realParameter[55] /* controlCold.Kp PARAM */ = data->simulationInfo->realParameter[26] /* Kp PARAM */;
  TRACE_POP
}

/*
equation index: 889
type: SIMPLE_ASSIGN
controlCold.PI.Kp = controlCold.Kp
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_889(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,889};
  data->simulationInfo->realParameter[64] /* controlCold.PI.Kp PARAM */ = data->simulationInfo->realParameter[55] /* controlCold.Kp PARAM */;
  TRACE_POP
}

/*
equation index: 890
type: SIMPLE_ASSIGN
controlCold.PI.P1.k = controlCold.PI.Kp / controlCold.PI.Ti
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_890(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,890};
  data->simulationInfo->realParameter[66] /* controlCold.PI.P1.k PARAM */ = DIVISION_SIM(data->simulationInfo->realParameter[64] /* controlCold.PI.Kp PARAM */,data->simulationInfo->realParameter[67] /* controlCold.PI.Ti PARAM */,"controlCold.PI.Ti",equationIndexes);
  TRACE_POP
}

/*
equation index: 891
type: SIMPLE_ASSIGN
m_flow_rec_start = m_flow_fac
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_891(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,891};
  data->simulationInfo->realParameter[167] /* m_flow_rec_start PARAM */ = data->simulationInfo->realParameter[165] /* m_flow_fac PARAM */;
  TRACE_POP
}

/*
equation index: 892
type: SIMPLE_ASSIGN
controlCold.y_start = m_flow_rec_start
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_892(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,892};
  data->simulationInfo->realParameter[89] /* controlCold.y_start PARAM */ = data->simulationInfo->realParameter[167] /* m_flow_rec_start PARAM */;
  TRACE_POP
}

/*
equation index: 893
type: SIMPLE_ASSIGN
controlCold.PI.y_start = controlCold.y_start
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_893(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,893};
  data->simulationInfo->realParameter[78] /* controlCold.PI.y_start PARAM */ = data->simulationInfo->realParameter[89] /* controlCold.y_start PARAM */;
  TRACE_POP
}

/*
equation index: 894
type: SIMPLE_ASSIGN
controlCold.PI.I.y_start = controlCold.PI.y_start / controlCold.PI.Kp
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_894(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,894};
  data->simulationInfo->realParameter[63] /* controlCold.PI.I.y_start PARAM */ = DIVISION_SIM(data->simulationInfo->realParameter[78] /* controlCold.PI.y_start PARAM */,data->simulationInfo->realParameter[64] /* controlCold.PI.Kp PARAM */,"controlCold.PI.Kp",equationIndexes);
  TRACE_POP
}

/*
equation index: 898
type: SIMPLE_ASSIGN
controlCold.PI.P.k = controlCold.PI.Kp
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_898(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,898};
  data->simulationInfo->realParameter[65] /* controlCold.PI.P.k PARAM */ = data->simulationInfo->realParameter[64] /* controlCold.PI.Kp PARAM */;
  TRACE_POP
}

/*
equation index: 900
type: SIMPLE_ASSIGN
controlCold.L_on = cold_tnk_crit_ub
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_900(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,900};
  data->simulationInfo->realParameter[59] /* controlCold.L_on PARAM */ = data->simulationInfo->realParameter[52] /* cold_tnk_crit_ub PARAM */;
  TRACE_POP
}

/*
equation index: 901
type: SIMPLE_ASSIGN
controlHot.L_off = hot_tnk_empty_lb
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_901(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,901};
  data->simulationInfo->realParameter[92] /* controlHot.L_off PARAM */ = data->simulationInfo->realParameter[155] /* hot_tnk_empty_lb PARAM */;
  TRACE_POP
}

/*
equation index: 902
type: SIMPLE_ASSIGN
controlHot.logic.level_off = controlHot.L_off
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_902(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,902};
  data->simulationInfo->realParameter[96] /* controlHot.logic.level_off PARAM */ = data->simulationInfo->realParameter[92] /* controlHot.L_off PARAM */;
  TRACE_POP
}

/*
equation index: 903
type: SIMPLE_ASSIGN
controlHot.L_on = hot_tnk_empty_ub
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_903(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,903};
  data->simulationInfo->realParameter[93] /* controlHot.L_on PARAM */ = data->simulationInfo->realParameter[156] /* hot_tnk_empty_ub PARAM */;
  TRACE_POP
}

/*
equation index: 904
type: SIMPLE_ASSIGN
controlHot.logic.level_on = controlHot.L_on
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_904(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,904};
  data->simulationInfo->realParameter[97] /* controlHot.logic.level_on PARAM */ = data->simulationInfo->realParameter[93] /* controlHot.L_on PARAM */;
  TRACE_POP
}

/*
equation index: 905
type: SIMPLE_ASSIGN
m_flow_blk = Q_flow_des / (h_hot_set - h_cold_set)
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_905(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,905};
  data->simulationInfo->realParameter[164] /* m_flow_blk PARAM */ = DIVISION_SIM(data->simulationInfo->realParameter[31] /* Q_flow_des PARAM */,data->simulationInfo->realParameter[132] /* h_hot_set PARAM */ - data->simulationInfo->realParameter[131] /* h_cold_set PARAM */,"h_hot_set - h_cold_set",equationIndexes);
  TRACE_POP
}

/*
equation index: 906
type: SIMPLE_ASSIGN
controlHot.m_flow_on = m_flow_blk
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_906(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,906};
  data->simulationInfo->realParameter[104] /* controlHot.m_flow_on PARAM */ = data->simulationInfo->realParameter[164] /* m_flow_blk PARAM */;
  TRACE_POP
}

/*
equation index: 907
type: SIMPLE_ASSIGN
controlHot.logic.m_flow_startup = 0.5 * controlHot.m_flow_on
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_907(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,907};
  data->simulationInfo->realParameter[100] /* controlHot.logic.m_flow_startup PARAM */ = (0.5) * (data->simulationInfo->realParameter[104] /* controlHot.m_flow_on PARAM */);
  TRACE_POP
}

/*
equation index: 908
type: SIMPLE_ASSIGN
controlHot.logic.m_flow_max = controlHot.m_flow_on
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_908(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,908};
  data->simulationInfo->realParameter[98] /* controlHot.logic.m_flow_max PARAM */ = data->simulationInfo->realParameter[104] /* controlHot.m_flow_on PARAM */;
  TRACE_POP
}

/*
equation index: 909
type: SIMPLE_ASSIGN
controlHot.L_df_off = hot_tnk_full_lb
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_909(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,909};
  data->simulationInfo->realParameter[90] /* controlHot.L_df_off PARAM */ = data->simulationInfo->realParameter[157] /* hot_tnk_full_lb PARAM */;
  TRACE_POP
}

/*
equation index: 910
type: SIMPLE_ASSIGN
controlHot.defocus_logic.level_min = controlHot.L_df_off
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_910(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,910};
  data->simulationInfo->realParameter[95] /* controlHot.defocus_logic.level_min PARAM */ = data->simulationInfo->realParameter[90] /* controlHot.L_df_off PARAM */;
  TRACE_POP
}

/*
equation index: 911
type: SIMPLE_ASSIGN
controlHot.L_df_on = hot_tnk_full_ub
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_911(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,911};
  data->simulationInfo->realParameter[91] /* controlHot.L_df_on PARAM */ = data->simulationInfo->realParameter[158] /* hot_tnk_full_ub PARAM */;
  TRACE_POP
}

/*
equation index: 912
type: SIMPLE_ASSIGN
controlHot.defocus_logic.level_max = controlHot.L_df_on
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_912(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,912};
  data->simulationInfo->realParameter[94] /* controlHot.defocus_logic.level_max PARAM */ = data->simulationInfo->realParameter[91] /* controlHot.L_df_on PARAM */;
  TRACE_POP
}

/*
equation index: 913
type: SIMPLE_ASSIGN
pumpCold.k_loss = k_loss_cold
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_913(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,913};
  data->simulationInfo->realParameter[218] /* pumpCold.k_loss PARAM */ = data->simulationInfo->realParameter[159] /* k_loss_cold PARAM */;
  TRACE_POP
}

/*
equation index: 914
type: SIMPLE_ASSIGN
E_max = 3600.0 * t_storage * Q_flow_des
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_914(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,914};
  data->simulationInfo->realParameter[22] /* E_max PARAM */ = (3600.0) * ((data->simulationInfo->realParameter[250] /* t_storage PARAM */) * (data->simulationInfo->realParameter[31] /* Q_flow_des PARAM */));
  TRACE_POP
}

/*
equation index: 915
type: SIMPLE_ASSIGN
m_max = E_max / (h_hot_set - h_cold_set)
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_915(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,915};
  data->simulationInfo->realParameter[168] /* m_max PARAM */ = DIVISION_SIM(data->simulationInfo->realParameter[22] /* E_max PARAM */,data->simulationInfo->realParameter[132] /* h_hot_set PARAM */ - data->simulationInfo->realParameter[131] /* h_cold_set PARAM */,"h_hot_set - h_cold_set",equationIndexes);
  TRACE_POP
}

/*
equation index: 916
type: SIMPLE_ASSIGN
rho_cold_set = SolarTherm.Media.MoltenSalt.MoltenSalt_utilities.rho_T(SolarTherm.Media.MoltenSalt.MoltenSalt_utilities.T_h(state_cold_set.h))
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_916(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,916};
  data->simulationInfo->realParameter[238] /* rho_cold_set PARAM */ = omc_SolarTherm_Media_MoltenSalt_MoltenSalt__utilities_rho__T(threadData, omc_SolarTherm_Media_MoltenSalt_MoltenSalt__utilities_T__h(threadData, data->simulationInfo->realParameter[243] /* state_cold_set.h PARAM */));
  TRACE_POP
}

/*
equation index: 917
type: SIMPLE_ASSIGN
rho_hot_set = SolarTherm.Media.MoltenSalt.MoltenSalt_utilities.rho_T(SolarTherm.Media.MoltenSalt.MoltenSalt_utilities.T_h(state_hot_set.h))
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_917(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,917};
  data->simulationInfo->realParameter[239] /* rho_hot_set PARAM */ = omc_SolarTherm_Media_MoltenSalt_MoltenSalt__utilities_rho__T(threadData, omc_SolarTherm_Media_MoltenSalt_MoltenSalt__utilities_T__h(threadData, data->simulationInfo->realParameter[245] /* state_hot_set.h PARAM */));
  TRACE_POP
}

/*
equation index: 918
type: SIMPLE_ASSIGN
V_max = 2.0 * m_max / (rho_hot_set + rho_cold_set)
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_918(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,918};
  data->simulationInfo->realParameter[43] /* V_max PARAM */ = (2.0) * (DIVISION_SIM(data->simulationInfo->realParameter[168] /* m_max PARAM */,data->simulationInfo->realParameter[239] /* rho_hot_set PARAM */ + data->simulationInfo->realParameter[238] /* rho_cold_set PARAM */,"rho_hot_set + rho_cold_set",equationIndexes));
  TRACE_POP
}

/*
equation index: 919
type: SIMPLE_ASSIGN
H_storage = ceil(1.083852140278578 * V_max ^ 0.3333333333333333 * abs(tank_ar) ^ 0.6666666666666666)
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_919(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,919};
  modelica_real tmp9;
  modelica_real tmp10;
  modelica_real tmp11;
  modelica_real tmp12;
  modelica_real tmp13;
  modelica_real tmp14;
  modelica_real tmp15;
  modelica_real tmp16;
  modelica_real tmp17;
  modelica_real tmp18;
  modelica_real tmp19;
  modelica_real tmp20;
  modelica_real tmp21;
  modelica_real tmp22;
  tmp9 = data->simulationInfo->realParameter[43] /* V_max PARAM */;
  tmp10 = 0.3333333333333333;
  if(tmp9 < 0.0 && tmp10 != 0.0)
  {
    tmp12 = modf(tmp10, &tmp13);
    
    if(tmp12 > 0.5)
    {
      tmp12 -= 1.0;
      tmp13 += 1.0;
    }
    else if(tmp12 < -0.5)
    {
      tmp12 += 1.0;
      tmp13 -= 1.0;
    }
    
    if(fabs(tmp12) < 1e-10)
      tmp11 = pow(tmp9, tmp13);
    else
    {
      tmp15 = modf(1.0/tmp10, &tmp14);
      if(tmp15 > 0.5)
      {
        tmp15 -= 1.0;
        tmp14 += 1.0;
      }
      else if(tmp15 < -0.5)
      {
        tmp15 += 1.0;
        tmp14 -= 1.0;
      }
      if(fabs(tmp15) < 1e-10 && ((unsigned long)tmp14 & 1))
      {
        tmp11 = -pow(-tmp9, tmp12)*pow(tmp9, tmp13);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp9, tmp10);
      }
    }
  }
  else
  {
    tmp11 = pow(tmp9, tmp10);
  }
  if(isnan(tmp11) || isinf(tmp11))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp9, tmp10);
  }tmp16 = fabs(data->simulationInfo->realParameter[273] /* tank_ar PARAM */);
  tmp17 = 0.6666666666666666;
  if(tmp16 < 0.0 && tmp17 != 0.0)
  {
    tmp19 = modf(tmp17, &tmp20);
    
    if(tmp19 > 0.5)
    {
      tmp19 -= 1.0;
      tmp20 += 1.0;
    }
    else if(tmp19 < -0.5)
    {
      tmp19 += 1.0;
      tmp20 -= 1.0;
    }
    
    if(fabs(tmp19) < 1e-10)
      tmp18 = pow(tmp16, tmp20);
    else
    {
      tmp22 = modf(1.0/tmp17, &tmp21);
      if(tmp22 > 0.5)
      {
        tmp22 -= 1.0;
        tmp21 += 1.0;
      }
      else if(tmp22 < -0.5)
      {
        tmp22 += 1.0;
        tmp21 -= 1.0;
      }
      if(fabs(tmp22) < 1e-10 && ((unsigned long)tmp21 & 1))
      {
        tmp18 = -pow(-tmp16, tmp19)*pow(tmp16, tmp20);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp16, tmp17);
      }
    }
  }
  else
  {
    tmp18 = pow(tmp16, tmp17);
  }
  if(isnan(tmp18) || isinf(tmp18))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp16, tmp17);
  }
  data->simulationInfo->realParameter[24] /* H_storage PARAM */ = ceil((1.083852140278578) * ((tmp11) * (tmp18)));
  TRACE_POP
}

/*
equation index: 920
type: SIMPLE_ASSIGN
D_storage = H_storage / tank_ar
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_920(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,920};
  data->simulationInfo->realParameter[20] /* D_storage PARAM */ = DIVISION_SIM(data->simulationInfo->realParameter[24] /* H_storage PARAM */,data->simulationInfo->realParameter[273] /* tank_ar PARAM */,"tank_ar",equationIndexes);
  TRACE_POP
}

/*
equation index: 921
type: SIMPLE_ASSIGN
tankCold.D = D_storage
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_921(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,921};
  data->simulationInfo->realParameter[253] /* tankCold.D PARAM */ = data->simulationInfo->realParameter[20] /* D_storage PARAM */;
  TRACE_POP
}

/*
equation index: 922
type: SIMPLE_ASSIGN
tankCold.H = H_storage
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_922(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,922};
  data->simulationInfo->realParameter[254] /* tankCold.H PARAM */ = data->simulationInfo->realParameter[24] /* H_storage PARAM */;
  TRACE_POP
}

/*
equation index: 923
type: SIMPLE_ASSIGN
tankCold.V_t = 0.7853981633974483 * tankCold.H * tankCold.D ^ 2.0
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_923(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,923};
  modelica_real tmp23;
  tmp23 = data->simulationInfo->realParameter[253] /* tankCold.D PARAM */;
  data->simulationInfo->realParameter[258] /* tankCold.V_t PARAM */ = (0.7853981633974483) * ((data->simulationInfo->realParameter[254] /* tankCold.H PARAM */) * ((tmp23 * tmp23)));
  TRACE_POP
}

/*
equation index: 926
type: SIMPLE_ASSIGN
tankCold.W_max = W_heater_cold
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_926(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,926};
  data->simulationInfo->realParameter[259] /* tankCold.W_max PARAM */ = data->simulationInfo->realParameter[45] /* W_heater_cold PARAM */;
  TRACE_POP
}

/*
equation index: 927
type: SIMPLE_ASSIGN
tankCold.T_set = T_cold_aux_set
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_927(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,927};
  data->simulationInfo->realParameter[256] /* tankCold.T_set PARAM */ = data->simulationInfo->realParameter[34] /* T_cold_aux_set PARAM */;
  TRACE_POP
}

/*
equation index: 928
type: SIMPLE_ASSIGN
tankCold.T_start = T_cold_start
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_928(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,928};
  data->simulationInfo->realParameter[257] /* tankCold.T_start PARAM */ = data->simulationInfo->realParameter[36] /* T_cold_start PARAM */;
  TRACE_POP
}

/*
equation index: 929
type: SIMPLE_ASSIGN
tankCold.L_start = 100.0 * split_cold
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_929(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,929};
  data->simulationInfo->realParameter[255] /* tankCold.L_start PARAM */ = (100.0) * (data->simulationInfo->realParameter[242] /* split_cold PARAM */);
  TRACE_POP
}

/*
equation index: 931
type: SIMPLE_ASSIGN
tankCold.alpha = alpha
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_931(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,931};
  data->simulationInfo->realParameter[260] /* tankCold.alpha PARAM */ = data->simulationInfo->realParameter[49] /* alpha PARAM */;
  TRACE_POP
}

/*
equation index: 935
type: SIMPLE_ASSIGN
pumpHot.k_loss = k_loss_hot
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_935(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,935};
  data->simulationInfo->realParameter[219] /* pumpHot.k_loss PARAM */ = data->simulationInfo->realParameter[160] /* k_loss_hot PARAM */;
  TRACE_POP
}

/*
equation index: 936
type: SIMPLE_ASSIGN
tankHot.D = D_storage
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_936(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,936};
  data->simulationInfo->realParameter[263] /* tankHot.D PARAM */ = data->simulationInfo->realParameter[20] /* D_storage PARAM */;
  TRACE_POP
}

/*
equation index: 937
type: SIMPLE_ASSIGN
tankHot.H = H_storage
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_937(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,937};
  data->simulationInfo->realParameter[264] /* tankHot.H PARAM */ = data->simulationInfo->realParameter[24] /* H_storage PARAM */;
  TRACE_POP
}

/*
equation index: 938
type: SIMPLE_ASSIGN
tankHot.V_t = 0.7853981633974483 * tankHot.H * tankHot.D ^ 2.0
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_938(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,938};
  modelica_real tmp24;
  tmp24 = data->simulationInfo->realParameter[263] /* tankHot.D PARAM */;
  data->simulationInfo->realParameter[268] /* tankHot.V_t PARAM */ = (0.7853981633974483) * ((data->simulationInfo->realParameter[264] /* tankHot.H PARAM */) * ((tmp24 * tmp24)));
  TRACE_POP
}

/*
equation index: 941
type: SIMPLE_ASSIGN
tankHot.W_max = W_heater_hot
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_941(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,941};
  data->simulationInfo->realParameter[269] /* tankHot.W_max PARAM */ = data->simulationInfo->realParameter[46] /* W_heater_hot PARAM */;
  TRACE_POP
}

/*
equation index: 942
type: SIMPLE_ASSIGN
tankHot.T_set = T_hot_aux_set
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_942(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,942};
  data->simulationInfo->realParameter[266] /* tankHot.T_set PARAM */ = data->simulationInfo->realParameter[37] /* T_hot_aux_set PARAM */;
  TRACE_POP
}

/*
equation index: 943
type: SIMPLE_ASSIGN
tankHot.T_start = T_hot_start
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_943(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,943};
  data->simulationInfo->realParameter[267] /* tankHot.T_start PARAM */ = data->simulationInfo->realParameter[39] /* T_hot_start PARAM */;
  TRACE_POP
}

/*
equation index: 944
type: SIMPLE_ASSIGN
tankHot.L_start = 100.0 * (1.0 - split_cold)
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_944(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,944};
  data->simulationInfo->realParameter[265] /* tankHot.L_start PARAM */ = (100.0) * (1.0 - data->simulationInfo->realParameter[242] /* split_cold PARAM */);
  TRACE_POP
}

/*
equation index: 946
type: SIMPLE_ASSIGN
tankHot.alpha = alpha
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_946(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,946};
  data->simulationInfo->realParameter[270] /* tankHot.alpha PARAM */ = data->simulationInfo->realParameter[49] /* alpha PARAM */;
  TRACE_POP
}

/*
equation index: 952
type: SIMPLE_ASSIGN
receiver.h_0 = receiver.state_0.h
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_952(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,952};
  data->simulationInfo->realParameter[233] /* receiver.h_0 PARAM */ = data->simulationInfo->realParameter[234] /* receiver.state_0.h PARAM */;
  TRACE_POP
}

/*
equation index: 954
type: SIMPLE_ASSIGN
receiver.H_rcv = H_receiver
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_954(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,954};
  data->simulationInfo->realParameter[227] /* receiver.H_rcv PARAM */ = data->simulationInfo->realParameter[23] /* H_receiver PARAM */;
  TRACE_POP
}

/*
equation index: 955
type: SIMPLE_ASSIGN
receiver.N_pa = N_pa_rec
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_955(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,955};
  data->simulationInfo->integerParameter[31] /* receiver.N_pa PARAM */ = data->simulationInfo->integerParameter[0] /* N_pa_rec PARAM */;
  TRACE_POP
}

/*
equation index: 956
type: SIMPLE_ASSIGN
receiver.D_tb = D_tb_rec
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_956(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,956};
  data->simulationInfo->realParameter[226] /* receiver.D_tb PARAM */ = data->simulationInfo->realParameter[21] /* D_tb_rec PARAM */;
  TRACE_POP
}

/*
equation index: 957
type: SIMPLE_ASSIGN
receiver.D_rcv = D_receiver
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_957(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,957};
  data->simulationInfo->realParameter[225] /* receiver.D_rcv PARAM */ = data->simulationInfo->realParameter[19] /* D_receiver PARAM */;
  TRACE_POP
}

/*
equation index: 958
type: SIMPLE_ASSIGN
receiver.w_pa = 3.141592653589793 * receiver.D_rcv / (*Real*)(receiver.N_pa)
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_958(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,958};
  data->simulationInfo->realParameter[237] /* receiver.w_pa PARAM */ = (3.141592653589793) * (DIVISION_SIM(data->simulationInfo->realParameter[225] /* receiver.D_rcv PARAM */,((modelica_real)data->simulationInfo->integerParameter[31] /* receiver.N_pa PARAM */),"/*Real*/(receiver.N_pa)",equationIndexes));
  TRACE_POP
}

/*
equation index: 959
type: SIMPLE_ASSIGN
receiver.N_tb_pa = div(receiver.w_pa, receiver.D_tb)
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_959(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,959};
  modelica_real tmp25;
  tmp25 = data->simulationInfo->realParameter[226] /* receiver.D_tb PARAM */;
  if (tmp25 == 0.0) {throwStreamPrint(threadData, "Division by zero %s", "div(receiver.w_pa, receiver.D_tb)");}
  data->simulationInfo->realParameter[228] /* receiver.N_tb_pa PARAM */ = trunc((data->simulationInfo->realParameter[237] /* receiver.w_pa PARAM */) / (tmp25));
  TRACE_POP
}

/*
equation index: 960
type: SIMPLE_ASSIGN
receiver.A = 1.570796326794897 * (*Real*)(receiver.N_pa) * receiver.N_tb_pa * receiver.H_rcv * receiver.D_tb
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_960(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,960};
  data->simulationInfo->realParameter[224] /* receiver.A PARAM */ = (1.570796326794897) * ((((modelica_real)data->simulationInfo->integerParameter[31] /* receiver.N_pa PARAM */)) * ((data->simulationInfo->realParameter[228] /* receiver.N_tb_pa PARAM */) * ((data->simulationInfo->realParameter[227] /* receiver.H_rcv PARAM */) * (data->simulationInfo->realParameter[226] /* receiver.D_tb PARAM */))));
  TRACE_POP
}

/*
equation index: 961
type: SIMPLE_ASSIGN
receiver.t_tb = t_tb_rec
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_961(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,961};
  data->simulationInfo->realParameter[236] /* receiver.t_tb PARAM */ = data->simulationInfo->realParameter[251] /* t_tb_rec PARAM */;
  TRACE_POP
}

/*
equation index: 962
type: SIMPLE_ASSIGN
receiver.V_rcv = 3.141592653589793 * (*Real*)(receiver.N_pa) * receiver.N_tb_pa * receiver.H_rcv * (0.5 * receiver.D_tb - receiver.t_tb) ^ 2.0
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_962(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,962};
  modelica_real tmp26;
  tmp26 = (0.5) * (data->simulationInfo->realParameter[226] /* receiver.D_tb PARAM */) - data->simulationInfo->realParameter[236] /* receiver.t_tb PARAM */;
  data->simulationInfo->realParameter[230] /* receiver.V_rcv PARAM */ = (3.141592653589793) * ((((modelica_real)data->simulationInfo->integerParameter[31] /* receiver.N_pa PARAM */)) * ((data->simulationInfo->realParameter[228] /* receiver.N_tb_pa PARAM */) * ((data->simulationInfo->realParameter[227] /* receiver.H_rcv PARAM */) * ((tmp26 * tmp26)))));
  TRACE_POP
}

/*
equation index: 963
type: SIMPLE_ASSIGN
receiver.em = em_rec
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_963(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,963};
  data->simulationInfo->realParameter[232] /* receiver.em PARAM */ = data->simulationInfo->realParameter[128] /* em_rec PARAM */;
  TRACE_POP
}

/*
equation index: 964
type: SIMPLE_ASSIGN
receiver.ab = ab_rec
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_964(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,964};
  data->simulationInfo->realParameter[231] /* receiver.ab PARAM */ = data->simulationInfo->realParameter[48] /* ab_rec PARAM */;
  TRACE_POP
}

/*
equation index: 968
type: SIMPLE_ASSIGN
heliostatField.Q_design = R_des
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_968(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,968};
  data->simulationInfo->realParameter[137] /* heliostatField.Q_design PARAM */ = data->simulationInfo->realParameter[32] /* R_des PARAM */;
  TRACE_POP
}

/*
equation index: 969
type: SIMPLE_ASSIGN
heliostatField.nu_min = nu_min_sf
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_969(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,969};
  data->simulationInfo->realParameter[147] /* heliostatField.nu_min PARAM */ = data->simulationInfo->realParameter[173] /* nu_min_sf PARAM */;
  TRACE_POP
}

/*
equation index: 970
type: SIMPLE_ASSIGN
heliostatField.Q_min = heliostatField.nu_min * heliostatField.Q_design
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_970(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,970};
  data->simulationInfo->realParameter[138] /* heliostatField.Q_min PARAM */ = (data->simulationInfo->realParameter[147] /* heliostatField.nu_min PARAM */) * (data->simulationInfo->realParameter[137] /* heliostatField.Q_design PARAM */);
  TRACE_POP
}

/*
equation index: 971
type: SIMPLE_ASSIGN
heliostatField.nu_start = nu_start
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_971(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,971};
  data->simulationInfo->realParameter[148] /* heliostatField.nu_start PARAM */ = data->simulationInfo->realParameter[175] /* nu_start PARAM */;
  TRACE_POP
}

/*
equation index: 972
type: SIMPLE_ASSIGN
heliostatField.Q_start = heliostatField.nu_start * heliostatField.Q_design
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_972(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,972};
  data->simulationInfo->realParameter[139] /* heliostatField.Q_start PARAM */ = (data->simulationInfo->realParameter[148] /* heliostatField.nu_start PARAM */) * (data->simulationInfo->realParameter[137] /* heliostatField.Q_design PARAM */);
  TRACE_POP
}

/*
equation index: 974
type: SIMPLE_ASSIGN
heliostatField.optical.nu_table.u_max[2] = Modelica.Blocks.Tables.Internal.getTable2DAbscissaUmax(heliostatField.optical.nu_table.tableID)[2]
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_974(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,974};
  data->simulationInfo->realParameter[151] /* heliostatField.optical.nu_table.u_max[2] PARAM */ = real_get(omc_Modelica_Blocks_Tables_Internal_getTable2DAbscissaUmax(threadData, data->simulationInfo->extObjs[1]), 1);
  TRACE_POP
}

/*
equation index: 975
type: SIMPLE_ASSIGN
heliostatField.optical.nu_table.u_max[1] = Modelica.Blocks.Tables.Internal.getTable2DAbscissaUmax(heliostatField.optical.nu_table.tableID)[1]
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_975(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,975};
  data->simulationInfo->realParameter[150] /* heliostatField.optical.nu_table.u_max[1] PARAM */ = real_get(omc_Modelica_Blocks_Tables_Internal_getTable2DAbscissaUmax(threadData, data->simulationInfo->extObjs[1]), 0);
  TRACE_POP
}

/*
equation index: 976
type: SIMPLE_ASSIGN
heliostatField.optical.nu_table.u_min[2] = Modelica.Blocks.Tables.Internal.getTable2DAbscissaUmin(heliostatField.optical.nu_table.tableID)[2]
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_976(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,976};
  data->simulationInfo->realParameter[153] /* heliostatField.optical.nu_table.u_min[2] PARAM */ = real_get(omc_Modelica_Blocks_Tables_Internal_getTable2DAbscissaUmin(threadData, data->simulationInfo->extObjs[1]), 1);
  TRACE_POP
}

/*
equation index: 977
type: SIMPLE_ASSIGN
heliostatField.optical.nu_table.u_min[1] = Modelica.Blocks.Tables.Internal.getTable2DAbscissaUmin(heliostatField.optical.nu_table.tableID)[1]
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_977(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,977};
  data->simulationInfo->realParameter[152] /* heliostatField.optical.nu_table.u_min[1] PARAM */ = real_get(omc_Modelica_Blocks_Tables_Internal_getTable2DAbscissaUmin(threadData, data->simulationInfo->extObjs[1]), 0);
  TRACE_POP
}

/*
equation index: 982
type: SIMPLE_ASSIGN
data.lat = lat
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_982(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,982};
  data->simulationInfo->realParameter[105] /* data.lat PARAM */ = data->simulationInfo->realParameter[162] /* lat PARAM */;
  TRACE_POP
}

/*
equation index: 983
type: SIMPLE_ASSIGN
heliostatField.lat = data.lat
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_983(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,983};
  data->simulationInfo->realParameter[144] /* heliostatField.lat PARAM */ = data->simulationInfo->realParameter[105] /* data.lat PARAM */;
  TRACE_POP
}

/*
equation index: 984
type: SIMPLE_ASSIGN
heliostatField.optical.lat = heliostatField.lat
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_984(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,984};
  data->simulationInfo->realParameter[149] /* heliostatField.optical.lat PARAM */ = data->simulationInfo->realParameter[144] /* heliostatField.lat PARAM */;
  TRACE_POP
}

/*
equation index: 985
type: SIMPLE_ASSIGN
heliostatField.Wspd_max = Wspd_max
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_985(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,985};
  data->simulationInfo->realParameter[141] /* heliostatField.Wspd_max PARAM */ = data->simulationInfo->realParameter[47] /* Wspd_max PARAM */;
  TRACE_POP
}

/*
equation index: 986
type: SIMPLE_ASSIGN
Q_flow_defocus = Q_flow_des / (1.0 - rec_fr)
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_986(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,986};
  data->simulationInfo->realParameter[30] /* Q_flow_defocus PARAM */ = DIVISION_SIM(data->simulationInfo->realParameter[31] /* Q_flow_des PARAM */,1.0 - data->simulationInfo->realParameter[223] /* rec_fr PARAM */,"1.0 - rec_fr",equationIndexes);
  TRACE_POP
}

/*
equation index: 987
type: SIMPLE_ASSIGN
nu_defocus = Q_flow_defocus / R_des
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_987(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,987};
  data->simulationInfo->realParameter[171] /* nu_defocus PARAM */ = DIVISION_SIM(data->simulationInfo->realParameter[30] /* Q_flow_defocus PARAM */,data->simulationInfo->realParameter[32] /* R_des PARAM */,"R_des",equationIndexes);
  TRACE_POP
}

/*
equation index: 988
type: SIMPLE_ASSIGN
heliostatField.nu_defocus = nu_defocus
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_988(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,988};
  data->simulationInfo->realParameter[146] /* heliostatField.nu_defocus PARAM */ = data->simulationInfo->realParameter[171] /* nu_defocus PARAM */;
  TRACE_POP
}

/*
equation index: 989
type: SIMPLE_ASSIGN
heliostatField.ele_min = ele_min
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_989(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,989};
  data->simulationInfo->realParameter[142] /* heliostatField.ele_min PARAM */ = data->simulationInfo->realParameter[127] /* ele_min PARAM */;
  TRACE_POP
}

/*
equation index: 993
type: SIMPLE_ASSIGN
heliostatField.he_av = he_av_design
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_993(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,993};
  data->simulationInfo->realParameter[143] /* heliostatField.he_av PARAM */ = data->simulationInfo->realParameter[133] /* he_av_design PARAM */;
  TRACE_POP
}

/*
equation index: 994
type: SIMPLE_ASSIGN
heliostatField.A_h = A_heliostat
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_994(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,994};
  data->simulationInfo->realParameter[134] /* heliostatField.A_h PARAM */ = data->simulationInfo->realParameter[1] /* A_heliostat PARAM */;
  TRACE_POP
}

/*
equation index: 995
type: SIMPLE_ASSIGN
heliostatField.n_h = n_heliostat
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_995(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,995};
  data->simulationInfo->integerParameter[21] /* heliostatField.n_h PARAM */ = data->simulationInfo->integerParameter[25] /* n_heliostat PARAM */;
  TRACE_POP
}

/*
equation index: 996
type: SIMPLE_ASSIGN
data.lon = lon
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_996(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,996};
  data->simulationInfo->realParameter[106] /* data.lon PARAM */ = data->simulationInfo->realParameter[163] /* lon PARAM */;
  TRACE_POP
}

/*
equation index: 997
type: SIMPLE_ASSIGN
heliostatField.lon = data.lon
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_997(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,997};
  data->simulationInfo->realParameter[145] /* heliostatField.lon PARAM */ = data->simulationInfo->realParameter[106] /* data.lon PARAM */;
  TRACE_POP
}

/*
equation index: 998
type: SIMPLE_ASSIGN
data.year = year
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_998(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,998};
  data->simulationInfo->integerParameter[20] /* data.year PARAM */ = data->simulationInfo->integerParameter[91] /* year PARAM */;
  TRACE_POP
}

/*
equation index: 999
type: SIMPLE_ASSIGN
sun.year = data.year
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_999(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,999};
  data->simulationInfo->integerParameter[76] /* sun.year PARAM */ = data->simulationInfo->integerParameter[20] /* data.year PARAM */;
  TRACE_POP
}

/*
equation index: 1000
type: SIMPLE_ASSIGN
data.t_zone = t_zone
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1000(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1000};
  data->simulationInfo->realParameter[107] /* data.t_zone PARAM */ = data->simulationInfo->realParameter[252] /* t_zone PARAM */;
  TRACE_POP
}

/*
equation index: 1001
type: SIMPLE_ASSIGN
sun.t_zone = data.t_zone
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1001(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1001};
  data->simulationInfo->realParameter[249] /* sun.t_zone PARAM */ = data->simulationInfo->realParameter[107] /* data.t_zone PARAM */;
  TRACE_POP
}

/*
equation index: 1002
type: SIMPLE_ASSIGN
sun.lat = data.lat
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1002(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1002};
  data->simulationInfo->realParameter[247] /* sun.lat PARAM */ = data->simulationInfo->realParameter[105] /* data.lat PARAM */;
  TRACE_POP
}

/*
equation index: 1003
type: SIMPLE_ASSIGN
sun.lon = data.lon
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1003(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1003};
  data->simulationInfo->realParameter[248] /* sun.lon PARAM */ = data->simulationInfo->realParameter[106] /* data.lon PARAM */;
  TRACE_POP
}

/*
equation index: 1005
type: SIMPLE_ASSIGN
data.table.p_offset[10] = data.table.offset[1]
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1005(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1005};
  data->simulationInfo->realParameter[118] /* data.table.p_offset[10] PARAM */ = data->simulationInfo->realParameter[108] /* data.table.offset[1] PARAM */;
  TRACE_POP
}

/*
equation index: 1006
type: SIMPLE_ASSIGN
data.table.p_offset[9] = data.table.offset[1]
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1006(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1006};
  data->simulationInfo->realParameter[117] /* data.table.p_offset[9] PARAM */ = data->simulationInfo->realParameter[108] /* data.table.offset[1] PARAM */;
  TRACE_POP
}

/*
equation index: 1007
type: SIMPLE_ASSIGN
data.table.p_offset[8] = data.table.offset[1]
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1007(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1007};
  data->simulationInfo->realParameter[116] /* data.table.p_offset[8] PARAM */ = data->simulationInfo->realParameter[108] /* data.table.offset[1] PARAM */;
  TRACE_POP
}

/*
equation index: 1008
type: SIMPLE_ASSIGN
data.table.p_offset[7] = data.table.offset[1]
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1008(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1008};
  data->simulationInfo->realParameter[115] /* data.table.p_offset[7] PARAM */ = data->simulationInfo->realParameter[108] /* data.table.offset[1] PARAM */;
  TRACE_POP
}

/*
equation index: 1009
type: SIMPLE_ASSIGN
data.table.p_offset[6] = data.table.offset[1]
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1009(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1009};
  data->simulationInfo->realParameter[114] /* data.table.p_offset[6] PARAM */ = data->simulationInfo->realParameter[108] /* data.table.offset[1] PARAM */;
  TRACE_POP
}

/*
equation index: 1010
type: SIMPLE_ASSIGN
data.table.p_offset[5] = data.table.offset[1]
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1010(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1010};
  data->simulationInfo->realParameter[113] /* data.table.p_offset[5] PARAM */ = data->simulationInfo->realParameter[108] /* data.table.offset[1] PARAM */;
  TRACE_POP
}

/*
equation index: 1011
type: SIMPLE_ASSIGN
data.table.p_offset[4] = data.table.offset[1]
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1011(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1011};
  data->simulationInfo->realParameter[112] /* data.table.p_offset[4] PARAM */ = data->simulationInfo->realParameter[108] /* data.table.offset[1] PARAM */;
  TRACE_POP
}

/*
equation index: 1012
type: SIMPLE_ASSIGN
data.table.p_offset[3] = data.table.offset[1]
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1012(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1012};
  data->simulationInfo->realParameter[111] /* data.table.p_offset[3] PARAM */ = data->simulationInfo->realParameter[108] /* data.table.offset[1] PARAM */;
  TRACE_POP
}

/*
equation index: 1013
type: SIMPLE_ASSIGN
data.table.p_offset[2] = data.table.offset[1]
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1013(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1013};
  data->simulationInfo->realParameter[110] /* data.table.p_offset[2] PARAM */ = data->simulationInfo->realParameter[108] /* data.table.offset[1] PARAM */;
  TRACE_POP
}

/*
equation index: 1014
type: SIMPLE_ASSIGN
data.table.p_offset[1] = data.table.offset[1]
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1014(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1014};
  data->simulationInfo->realParameter[109] /* data.table.p_offset[1] PARAM */ = data->simulationInfo->realParameter[108] /* data.table.offset[1] PARAM */;
  TRACE_POP
}

/*
equation index: 1015
type: SIMPLE_ASSIGN
data.table.t_maxScaled = Modelica.Blocks.Tables.Internal.getTimeTableTmax(data.table.tableID)
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1015(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1015};
  data->simulationInfo->realParameter[122] /* data.table.t_maxScaled PARAM */ = omc_Modelica_Blocks_Tables_Internal_getTimeTableTmax(threadData, data->simulationInfo->extObjs[0]);
  TRACE_POP
}

/*
equation index: 1016
type: SIMPLE_ASSIGN
data.table.t_minScaled = Modelica.Blocks.Tables.Internal.getTimeTableTmin(data.table.tableID)
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1016(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1016};
  data->simulationInfo->realParameter[124] /* data.table.t_minScaled PARAM */ = omc_Modelica_Blocks_Tables_Internal_getTimeTableTmin(threadData, data->simulationInfo->extObjs[0]);
  TRACE_POP
}

/*
equation index: 1017
type: SIMPLE_ASSIGN
data.table.t_max = data.table.t_maxScaled
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1017(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1017};
  data->simulationInfo->realParameter[121] /* data.table.t_max PARAM */ = data->simulationInfo->realParameter[122] /* data.table.t_maxScaled PARAM */;
  TRACE_POP
}

/*
equation index: 1018
type: SIMPLE_ASSIGN
data.table.t_min = data.table.t_minScaled
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1018(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1018};
  data->simulationInfo->realParameter[123] /* data.table.t_min PARAM */ = data->simulationInfo->realParameter[124] /* data.table.t_minScaled PARAM */;
  TRACE_POP
}

/*
equation index: 1026
type: SIMPLE_ASSIGN
wea.wtab.delay[8] = wea.delay[8]
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1026(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1026};
  data->simulationInfo->realParameter[310] /* wea.wtab.delay[8] PARAM */ = data->simulationInfo->realParameter[292] /* wea.delay[8] PARAM */;
  TRACE_POP
}

/*
equation index: 1027
type: SIMPLE_ASSIGN
wea.wtab.delay[7] = wea.delay[7]
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1027(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1027};
  data->simulationInfo->realParameter[309] /* wea.wtab.delay[7] PARAM */ = data->simulationInfo->realParameter[291] /* wea.delay[7] PARAM */;
  TRACE_POP
}

/*
equation index: 1028
type: SIMPLE_ASSIGN
wea.wtab.delay[6] = wea.delay[6]
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1028(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1028};
  data->simulationInfo->realParameter[308] /* wea.wtab.delay[6] PARAM */ = data->simulationInfo->realParameter[290] /* wea.delay[6] PARAM */;
  TRACE_POP
}

/*
equation index: 1029
type: SIMPLE_ASSIGN
wea.wtab.delay[5] = wea.delay[5]
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1029(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1029};
  data->simulationInfo->realParameter[307] /* wea.wtab.delay[5] PARAM */ = data->simulationInfo->realParameter[289] /* wea.delay[5] PARAM */;
  TRACE_POP
}

/*
equation index: 1030
type: SIMPLE_ASSIGN
wea.wtab.delay[4] = wea.delay[4]
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1030(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1030};
  data->simulationInfo->realParameter[306] /* wea.wtab.delay[4] PARAM */ = data->simulationInfo->realParameter[288] /* wea.delay[4] PARAM */;
  TRACE_POP
}

/*
equation index: 1031
type: SIMPLE_ASSIGN
wea.wtab.delay[3] = wea.delay[3]
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1031(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1031};
  data->simulationInfo->realParameter[305] /* wea.wtab.delay[3] PARAM */ = data->simulationInfo->realParameter[287] /* wea.delay[3] PARAM */;
  TRACE_POP
}

/*
equation index: 1032
type: SIMPLE_ASSIGN
wea.wtab.delay[2] = wea.delay[2]
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1032(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1032};
  data->simulationInfo->realParameter[304] /* wea.wtab.delay[2] PARAM */ = data->simulationInfo->realParameter[286] /* wea.delay[2] PARAM */;
  TRACE_POP
}

/*
equation index: 1033
type: SIMPLE_ASSIGN
wea.wtab.delay[1] = wea.delay[1]
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1033(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1033};
  data->simulationInfo->realParameter[303] /* wea.wtab.delay[1] PARAM */ = data->simulationInfo->realParameter[285] /* wea.delay[1] PARAM */;
  TRACE_POP
}

/*
equation index: 1034
type: SIMPLE_ASSIGN
wea.wtab.u_max = Modelica.Blocks.Tables.Internal.getTable1DAbscissaUmax(wea.wtab.tableID)
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1034(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1034};
  data->simulationInfo->realParameter[311] /* wea.wtab.u_max PARAM */ = omc_Modelica_Blocks_Tables_Internal_getTable1DAbscissaUmax(threadData, data->simulationInfo->extObjs[4]);
  TRACE_POP
}

/*
equation index: 1035
type: SIMPLE_ASSIGN
wea.wtab.u_min = Modelica.Blocks.Tables.Internal.getTable1DAbscissaUmin(wea.wtab.tableID)
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1035(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1035};
  data->simulationInfo->realParameter[312] /* wea.wtab.u_min PARAM */ = omc_Modelica_Blocks_Tables_Internal_getTable1DAbscissaUmin(threadData, data->simulationInfo->extObjs[4]);
  TRACE_POP
}

/*
equation index: 1040
type: SIMPLE_ASSIGN
C_prod = 2.777777777777778e-10 * pri_om_prod
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1040(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1040};
  data->simulationInfo->realParameter[13] /* C_prod PARAM */ = (2.777777777777778e-10) * (data->simulationInfo->realParameter[206] /* pri_om_prod PARAM */);
  TRACE_POP
}

/*
equation index: 1041
type: SIMPLE_ASSIGN
P_net = (1.0 - par_fr) * P_gross
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1041(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1041};
  data->simulationInfo->realParameter[29] /* P_net PARAM */ = (1.0 - data->simulationInfo->realParameter[179] /* par_fr PARAM */) * (data->simulationInfo->realParameter[27] /* P_gross PARAM */);
  TRACE_POP
}

/*
equation index: 1042
type: SIMPLE_ASSIGN
P_name = P_net
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1042(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1042};
  data->simulationInfo->realParameter[28] /* P_name PARAM */ = data->simulationInfo->realParameter[29] /* P_net PARAM */;
  TRACE_POP
}

/*
equation index: 1043
type: SIMPLE_ASSIGN
C_year = 0.001 * pri_om_name * P_name
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1043(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1043};
  data->simulationInfo->realParameter[18] /* C_year PARAM */ = (0.001) * ((data->simulationInfo->realParameter[205] /* pri_om_name PARAM */) * (data->simulationInfo->realParameter[28] /* P_name PARAM */));
  TRACE_POP
}

/*
equation index: 1044
type: SIMPLE_ASSIGN
A_field = (*Real*)(n_heliostat) * A_heliostat
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1044(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1044};
  data->simulationInfo->realParameter[0] /* A_field PARAM */ = (((modelica_real)data->simulationInfo->integerParameter[25] /* n_heliostat PARAM */)) * (data->simulationInfo->realParameter[1] /* A_heliostat PARAM */);
  TRACE_POP
}

/*
equation index: 1045
type: SIMPLE_ASSIGN
C_field = pri_field * A_field
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1045(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1045};
  data->simulationInfo->realParameter[11] /* C_field PARAM */ = (data->simulationInfo->realParameter[203] /* pri_field PARAM */) * (data->simulationInfo->realParameter[0] /* A_field PARAM */);
  TRACE_POP
}

/*
equation index: 1046
type: SIMPLE_ASSIGN
C_site = pri_site * A_field
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1046(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1046};
  data->simulationInfo->realParameter[15] /* C_site PARAM */ = (data->simulationInfo->realParameter[207] /* pri_site PARAM */) * (data->simulationInfo->realParameter[0] /* A_field PARAM */);
  TRACE_POP
}

/*
equation index: 1047
type: SIMPLE_ASSIGN
C_tower = 3000000.0 * exp(0.0113 * H_tower)
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1047(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1047};
  data->simulationInfo->realParameter[17] /* C_tower PARAM */ = (3000000.0) * (exp((0.0113) * (data->simulationInfo->realParameter[25] /* H_tower PARAM */)));
  TRACE_POP
}

/*
equation index: 1048
type: SIMPLE_ASSIGN
A_receiver = 3.141592653589793 * D_receiver * H_receiver
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1048(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1048};
  data->simulationInfo->realParameter[3] /* A_receiver PARAM */ = (3.141592653589793) * ((data->simulationInfo->realParameter[19] /* D_receiver PARAM */) * (data->simulationInfo->realParameter[23] /* H_receiver PARAM */));
  TRACE_POP
}

/*
equation index: 1049
type: SIMPLE_ASSIGN
C_receiver = 103000000.0 * (0.0006365372374283895 * A_receiver) ^ 0.7
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1049(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1049};
  modelica_real tmp27;
  modelica_real tmp28;
  modelica_real tmp29;
  modelica_real tmp30;
  modelica_real tmp31;
  modelica_real tmp32;
  modelica_real tmp33;
  tmp27 = (0.0006365372374283895) * (data->simulationInfo->realParameter[3] /* A_receiver PARAM */);
  tmp28 = 0.7;
  if(tmp27 < 0.0 && tmp28 != 0.0)
  {
    tmp30 = modf(tmp28, &tmp31);
    
    if(tmp30 > 0.5)
    {
      tmp30 -= 1.0;
      tmp31 += 1.0;
    }
    else if(tmp30 < -0.5)
    {
      tmp30 += 1.0;
      tmp31 -= 1.0;
    }
    
    if(fabs(tmp30) < 1e-10)
      tmp29 = pow(tmp27, tmp31);
    else
    {
      tmp33 = modf(1.0/tmp28, &tmp32);
      if(tmp33 > 0.5)
      {
        tmp33 -= 1.0;
        tmp32 += 1.0;
      }
      else if(tmp33 < -0.5)
      {
        tmp33 += 1.0;
        tmp32 -= 1.0;
      }
      if(fabs(tmp33) < 1e-10 && ((unsigned long)tmp32 & 1))
      {
        tmp29 = -pow(-tmp27, tmp30)*pow(tmp27, tmp31);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp27, tmp28);
      }
    }
  }
  else
  {
    tmp29 = pow(tmp27, tmp28);
  }
  if(isnan(tmp29) || isinf(tmp29))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp27, tmp28);
  }
  data->simulationInfo->realParameter[14] /* C_receiver PARAM */ = (103000000.0) * (tmp29);
  TRACE_POP
}

/*
equation index: 1050
type: SIMPLE_ASSIGN
C_storage = 2.777777777777778e-07 * pri_storage * E_max
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1050(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1050};
  data->simulationInfo->realParameter[16] /* C_storage PARAM */ = (2.777777777777778e-07) * ((data->simulationInfo->realParameter[208] /* pri_storage PARAM */) * (data->simulationInfo->realParameter[22] /* E_max PARAM */));
  TRACE_POP
}

/*
equation index: 1051
type: SIMPLE_ASSIGN
C_block = 0.001 * pri_block * P_gross
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1051(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1051};
  data->simulationInfo->realParameter[5] /* C_block PARAM */ = (0.001) * ((data->simulationInfo->realParameter[201] /* pri_block PARAM */) * (data->simulationInfo->realParameter[27] /* P_gross PARAM */));
  TRACE_POP
}

/*
equation index: 1052
type: SIMPLE_ASSIGN
C_bop = 0.001 * pri_bop * P_gross
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1052(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1052};
  data->simulationInfo->realParameter[6] /* C_bop PARAM */ = (0.001) * ((data->simulationInfo->realParameter[202] /* pri_bop PARAM */) * (data->simulationInfo->realParameter[27] /* P_gross PARAM */));
  TRACE_POP
}

/*
equation index: 1053
type: SIMPLE_ASSIGN
C_cap_dir_sub = (1.0 - f_Subs) * (C_field + C_site + C_tower + C_receiver + C_storage + C_block + C_bop)
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1053(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1053};
  data->simulationInfo->realParameter[8] /* C_cap_dir_sub PARAM */ = (1.0 - data->simulationInfo->realParameter[130] /* f_Subs PARAM */) * (data->simulationInfo->realParameter[11] /* C_field PARAM */ + data->simulationInfo->realParameter[15] /* C_site PARAM */ + data->simulationInfo->realParameter[17] /* C_tower PARAM */ + data->simulationInfo->realParameter[14] /* C_receiver PARAM */ + data->simulationInfo->realParameter[16] /* C_storage PARAM */ + data->simulationInfo->realParameter[5] /* C_block PARAM */ + data->simulationInfo->realParameter[6] /* C_bop PARAM */);
  TRACE_POP
}

/*
equation index: 1054
type: SIMPLE_ASSIGN
C_contingency = 0.07000000000000001 * C_cap_dir_sub
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1054(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1054};
  data->simulationInfo->realParameter[10] /* C_contingency PARAM */ = (0.07000000000000001) * (data->simulationInfo->realParameter[8] /* C_cap_dir_sub PARAM */);
  TRACE_POP
}

/*
equation index: 1055
type: SIMPLE_ASSIGN
C_cap_dir_tot = C_cap_dir_sub + C_contingency
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1055(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1055};
  data->simulationInfo->realParameter[9] /* C_cap_dir_tot PARAM */ = data->simulationInfo->realParameter[8] /* C_cap_dir_sub PARAM */ + data->simulationInfo->realParameter[10] /* C_contingency PARAM */;
  TRACE_POP
}

/*
equation index: 1056
type: SIMPLE_ASSIGN
C_EPC = 0.11 * C_cap_dir_tot
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1056(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1056};
  data->simulationInfo->realParameter[4] /* C_EPC PARAM */ = (0.11) * (data->simulationInfo->realParameter[9] /* C_cap_dir_tot PARAM */);
  TRACE_POP
}

/*
equation index: 1057
type: SIMPLE_ASSIGN
A_land = 197434.207385281 + land_mult * A_field
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1057(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1057};
  data->simulationInfo->realParameter[2] /* A_land PARAM */ = 197434.207385281 + (data->simulationInfo->realParameter[161] /* land_mult PARAM */) * (data->simulationInfo->realParameter[0] /* A_field PARAM */);
  TRACE_POP
}

/*
equation index: 1058
type: SIMPLE_ASSIGN
C_land = 0.000247105163015276 * pri_land * A_land
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1058(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1058};
  data->simulationInfo->realParameter[12] /* C_land PARAM */ = (0.000247105163015276) * ((data->simulationInfo->realParameter[204] /* pri_land PARAM */) * (data->simulationInfo->realParameter[2] /* A_land PARAM */));
  TRACE_POP
}

/*
equation index: 1059
type: SIMPLE_ASSIGN
C_cap = C_cap_dir_tot + C_EPC + C_land
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1059(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1059};
  data->simulationInfo->realParameter[7] /* C_cap PARAM */ = data->simulationInfo->realParameter[9] /* C_cap_dir_tot PARAM */ + data->simulationInfo->realParameter[4] /* C_EPC PARAM */ + data->simulationInfo->realParameter[12] /* C_land PARAM */;
  TRACE_POP
}

/*
equation index: 1065
type: SIMPLE_ASSIGN
SM = R_des / Q_flow_des
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1065(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1065};
  data->simulationInfo->realParameter[33] /* SM PARAM */ = DIVISION_SIM(data->simulationInfo->realParameter[32] /* R_des PARAM */,data->simulationInfo->realParameter[31] /* Q_flow_des PARAM */,"Q_flow_des",equationIndexes);
  TRACE_POP
}
extern void Reference_1_eqFunction_221(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_220(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_219(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_218(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_217(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_16(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_216(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_215(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_214(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_213(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_15(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_12(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_11(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_10(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_9(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_8(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_7(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_6(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_5(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_4(DATA *data, threadData_t *threadData);


/*
equation index: 1088
type: ALGORITHM

  assert(wea.wtab.extrapolation >= Modelica.Blocks.Types.Extrapolation.HoldLastPoint and wea.wtab.extrapolation <= Modelica.Blocks.Types.Extrapolation.NoExtrapolation, "Variable violating min/max constraint: Modelica.Blocks.Types.Extrapolation.HoldLastPoint <= wea.wtab.extrapolation <= Modelica.Blocks.Types.Extrapolation.NoExtrapolation, has value: " + String(wea.wtab.extrapolation, "d"));
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1088(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1088};
  modelica_boolean tmp34;
  modelica_boolean tmp35;
  static const MMC_DEFSTRINGLIT(tmp36,182,"Variable violating min/max constraint: Modelica.Blocks.Types.Extrapolation.HoldLastPoint <= wea.wtab.extrapolation <= Modelica.Blocks.Types.Extrapolation.NoExtrapolation, has value: ");
  modelica_string tmp37;
  static int tmp38 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp38)
  {
    tmp34 = GreaterEq(data->simulationInfo->integerParameter[88] /* wea.wtab.extrapolation PARAM */,1);
    tmp35 = LessEq(data->simulationInfo->integerParameter[88] /* wea.wtab.extrapolation PARAM */,4);
    if(!(tmp34 && tmp35))
    {
      tmp37 = modelica_integer_to_modelica_string_format(data->simulationInfo->integerParameter[88] /* wea.wtab.extrapolation PARAM */, (modelica_string) mmc_strings_len1[100]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp36),tmp37);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Blocks/Tables.mo",32,5,34,61,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nwea.wtab.extrapolation >= Modelica.Blocks.Types.Extrapolation.HoldLastPoint and wea.wtab.extrapolation <= Modelica.Blocks.Types.Extrapolation.NoExtrapolation", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp38 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1089
type: ALGORITHM

  assert(data.table.extrapolation >= Modelica.Blocks.Types.Extrapolation.HoldLastPoint and data.table.extrapolation <= Modelica.Blocks.Types.Extrapolation.NoExtrapolation, "Variable violating min/max constraint: Modelica.Blocks.Types.Extrapolation.HoldLastPoint <= data.table.extrapolation <= Modelica.Blocks.Types.Extrapolation.NoExtrapolation, has value: " + String(data.table.extrapolation, "d"));
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1089(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1089};
  modelica_boolean tmp39;
  modelica_boolean tmp40;
  static const MMC_DEFSTRINGLIT(tmp41,184,"Variable violating min/max constraint: Modelica.Blocks.Types.Extrapolation.HoldLastPoint <= data.table.extrapolation <= Modelica.Blocks.Types.Extrapolation.NoExtrapolation, has value: ");
  modelica_string tmp42;
  static int tmp43 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp43)
  {
    tmp39 = GreaterEq(data->simulationInfo->integerParameter[16] /* data.table.extrapolation PARAM */,1);
    tmp40 = LessEq(data->simulationInfo->integerParameter[16] /* data.table.extrapolation PARAM */,4);
    if(!(tmp39 && tmp40))
    {
      tmp42 = modelica_integer_to_modelica_string_format(data->simulationInfo->integerParameter[16] /* data.table.extrapolation PARAM */, (modelica_string) mmc_strings_len1[100]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp41),tmp42);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Blocks/Sources.mo",2153,5,2155,61,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\ndata.table.extrapolation >= Modelica.Blocks.Types.Extrapolation.HoldLastPoint and data.table.extrapolation <= Modelica.Blocks.Types.Extrapolation.NoExtrapolation", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp43 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1090
type: ALGORITHM

  assert(heliostatField.optical.nu_table.extrapolation >= Modelica.Blocks.Types.Extrapolation.HoldLastPoint and heliostatField.optical.nu_table.extrapolation <= Modelica.Blocks.Types.Extrapolation.NoExtrapolation, "Variable violating min/max constraint: Modelica.Blocks.Types.Extrapolation.HoldLastPoint <= heliostatField.optical.nu_table.extrapolation <= Modelica.Blocks.Types.Extrapolation.NoExtrapolation, has value: " + String(heliostatField.optical.nu_table.extrapolation, "d"));
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1090(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1090};
  modelica_boolean tmp44;
  modelica_boolean tmp45;
  static const MMC_DEFSTRINGLIT(tmp46,205,"Variable violating min/max constraint: Modelica.Blocks.Types.Extrapolation.HoldLastPoint <= heliostatField.optical.nu_table.extrapolation <= Modelica.Blocks.Types.Extrapolation.NoExtrapolation, has value: ");
  modelica_string tmp47;
  static int tmp48 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp48)
  {
    tmp44 = GreaterEq(data->simulationInfo->integerParameter[23] /* heliostatField.optical.nu_table.extrapolation PARAM */,1);
    tmp45 = LessEq(data->simulationInfo->integerParameter[23] /* heliostatField.optical.nu_table.extrapolation PARAM */,4);
    if(!(tmp44 && tmp45))
    {
      tmp47 = modelica_integer_to_modelica_string_format(data->simulationInfo->integerParameter[23] /* heliostatField.optical.nu_table.extrapolation PARAM */, (modelica_string) mmc_strings_len1[100]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp46),tmp47);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Blocks/Tables.mo",972,7,974,63,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nheliostatField.optical.nu_table.extrapolation >= Modelica.Blocks.Types.Extrapolation.HoldLastPoint and heliostatField.optical.nu_table.extrapolation <= Modelica.Blocks.Types.Extrapolation.NoExtrapolation", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp48 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1091
type: ALGORITHM

  assert(prices.extrapolation >= Modelica.Blocks.Types.Extrapolation.HoldLastPoint and prices.extrapolation <= Modelica.Blocks.Types.Extrapolation.NoExtrapolation, "Variable violating min/max constraint: Modelica.Blocks.Types.Extrapolation.HoldLastPoint <= prices.extrapolation <= Modelica.Blocks.Types.Extrapolation.NoExtrapolation, has value: " + String(prices.extrapolation, "d"));
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1091(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1091};
  modelica_boolean tmp49;
  modelica_boolean tmp50;
  static const MMC_DEFSTRINGLIT(tmp51,180,"Variable violating min/max constraint: Modelica.Blocks.Types.Extrapolation.HoldLastPoint <= prices.extrapolation <= Modelica.Blocks.Types.Extrapolation.NoExtrapolation, has value: ");
  modelica_string tmp52;
  static int tmp53 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp53)
  {
    tmp49 = GreaterEq(data->simulationInfo->integerParameter[27] /* prices.extrapolation PARAM */,1);
    tmp50 = LessEq(data->simulationInfo->integerParameter[27] /* prices.extrapolation PARAM */,4);
    if(!(tmp49 && tmp50))
    {
      tmp52 = modelica_integer_to_modelica_string_format(data->simulationInfo->integerParameter[27] /* prices.extrapolation PARAM */, (modelica_string) mmc_strings_len1[100]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp51),tmp52);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Blocks/Sources.mo",2153,5,2155,61,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nprices.extrapolation >= Modelica.Blocks.Types.Extrapolation.HoldLastPoint and prices.extrapolation <= Modelica.Blocks.Types.Extrapolation.NoExtrapolation", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp53 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1092
type: ALGORITHM

  assert(sch_fixed.daily[1].table.extrapolation >= Modelica.Blocks.Types.Extrapolation.HoldLastPoint and sch_fixed.daily[1].table.extrapolation <= Modelica.Blocks.Types.Extrapolation.NoExtrapolation, "Variable violating min/max constraint: Modelica.Blocks.Types.Extrapolation.HoldLastPoint <= sch_fixed.daily[1].table.extrapolation <= Modelica.Blocks.Types.Extrapolation.NoExtrapolation, has value: " + String(sch_fixed.daily[1].table.extrapolation, "d"));
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1092(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1092};
  modelica_boolean tmp54;
  modelica_boolean tmp55;
  static const MMC_DEFSTRINGLIT(tmp56,198,"Variable violating min/max constraint: Modelica.Blocks.Types.Extrapolation.HoldLastPoint <= sch_fixed.daily[1].table.extrapolation <= Modelica.Blocks.Types.Extrapolation.NoExtrapolation, has value: ");
  modelica_string tmp57;
  static int tmp58 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp58)
  {
    tmp54 = GreaterEq(data->simulationInfo->integerParameter[33] /* sch_fixed.daily[1].table.extrapolation PARAM */,1);
    tmp55 = LessEq(data->simulationInfo->integerParameter[33] /* sch_fixed.daily[1].table.extrapolation PARAM */,4);
    if(!(tmp54 && tmp55))
    {
      tmp57 = modelica_integer_to_modelica_string_format(data->simulationInfo->integerParameter[33] /* sch_fixed.daily[1].table.extrapolation PARAM */, (modelica_string) mmc_strings_len1[100]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp56),tmp57);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Blocks/Tables.mo",323,5,325,61,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nsch_fixed.daily[1].table.extrapolation >= Modelica.Blocks.Types.Extrapolation.HoldLastPoint and sch_fixed.daily[1].table.extrapolation <= Modelica.Blocks.Types.Extrapolation.NoExtrapolation", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp58 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1093
type: ALGORITHM

  assert(T_hot_set >= 0.0, "Variable violating min constraint: 0.0 <= T_hot_set, has value: " + String(T_hot_set, "g"));
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1093(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1093};
  modelica_boolean tmp59;
  static const MMC_DEFSTRINGLIT(tmp60,64,"Variable violating min constraint: 0.0 <= T_hot_set, has value: ");
  modelica_string tmp61;
  static int tmp62 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp62)
  {
    tmp59 = GreaterEq(data->simulationInfo->realParameter[38] /* T_hot_set PARAM */,0.0);
    if(!tmp59)
    {
      tmp61 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[38] /* T_hot_set PARAM */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp60),tmp61);
      {
        FILE_INFO info = {"/home/cparrado/.openmodelica/libraries/SolarTherm/Systems/Reference_1.mo",82,2,82,86,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nT_hot_set >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp62 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1094
type: ALGORITHM

  assert(controlCold.T_ref >= 0.0, "Variable violating min constraint: 0.0 <= controlCold.T_ref, has value: " + String(controlCold.T_ref, "g"));
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1094(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1094};
  modelica_boolean tmp63;
  static const MMC_DEFSTRINGLIT(tmp64,72,"Variable violating min constraint: 0.0 <= controlCold.T_ref, has value: ");
  modelica_string tmp65;
  static int tmp66 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp66)
  {
    tmp63 = GreaterEq(data->simulationInfo->realParameter[79] /* controlCold.T_ref PARAM */,0.0);
    if(!tmp63)
    {
      tmp65 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[79] /* controlCold.T_ref PARAM */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp64),tmp65);
      {
        FILE_INFO info = {"/home/cparrado/.openmodelica/libraries/SolarTherm/Models/Control/ReceiverControl.mo",4,3,4,74,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\ncontrolCold.T_ref >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp66 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1095
type: ALGORITHM

  assert(sch_fixed.daily[1].table.smoothness >= Modelica.Blocks.Types.Smoothness.LinearSegments and sch_fixed.daily[1].table.smoothness <= Modelica.Blocks.Types.Smoothness.MonotoneContinuousDerivative2, "Variable violating min/max constraint: Modelica.Blocks.Types.Smoothness.LinearSegments <= sch_fixed.daily[1].table.smoothness <= Modelica.Blocks.Types.Smoothness.MonotoneContinuousDerivative2, has value: " + String(sch_fixed.daily[1].table.smoothness, "d"));
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1095(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1095};
  modelica_boolean tmp67;
  modelica_boolean tmp68;
  static const MMC_DEFSTRINGLIT(tmp69,204,"Variable violating min/max constraint: Modelica.Blocks.Types.Smoothness.LinearSegments <= sch_fixed.daily[1].table.smoothness <= Modelica.Blocks.Types.Smoothness.MonotoneContinuousDerivative2, has value: ");
  modelica_string tmp70;
  static int tmp71 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp71)
  {
    tmp67 = GreaterEq(data->simulationInfo->integerParameter[35] /* sch_fixed.daily[1].table.smoothness PARAM */,1);
    tmp68 = LessEq(data->simulationInfo->integerParameter[35] /* sch_fixed.daily[1].table.smoothness PARAM */,5);
    if(!(tmp67 && tmp68))
    {
      tmp70 = modelica_integer_to_modelica_string_format(data->simulationInfo->integerParameter[35] /* sch_fixed.daily[1].table.smoothness PARAM */, (modelica_string) mmc_strings_len1[100]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp69),tmp70);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Blocks/Tables.mo",320,5,322,61,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nsch_fixed.daily[1].table.smoothness >= Modelica.Blocks.Types.Smoothness.LinearSegments and sch_fixed.daily[1].table.smoothness <= Modelica.Blocks.Types.Smoothness.MonotoneContinuousDerivative2", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp71 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1096
type: ALGORITHM

  assert(prices.timeEvents >= Modelica.Blocks.Types.TimeEvents.Always and prices.timeEvents <= Modelica.Blocks.Types.TimeEvents.NoTimeEvents, "Variable violating min/max constraint: Modelica.Blocks.Types.TimeEvents.Always <= prices.timeEvents <= Modelica.Blocks.Types.TimeEvents.NoTimeEvents, has value: " + String(prices.timeEvents, "d"));
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1096(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1096};
  modelica_boolean tmp72;
  modelica_boolean tmp73;
  static const MMC_DEFSTRINGLIT(tmp74,161,"Variable violating min/max constraint: Modelica.Blocks.Types.TimeEvents.Always <= prices.timeEvents <= Modelica.Blocks.Types.TimeEvents.NoTimeEvents, has value: ");
  modelica_string tmp75;
  static int tmp76 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp76)
  {
    tmp72 = GreaterEq(data->simulationInfo->integerParameter[30] /* prices.timeEvents PARAM */,1);
    tmp73 = LessEq(data->simulationInfo->integerParameter[30] /* prices.timeEvents PARAM */,3);
    if(!(tmp72 && tmp73))
    {
      tmp75 = modelica_integer_to_modelica_string_format(data->simulationInfo->integerParameter[30] /* prices.timeEvents PARAM */, (modelica_string) mmc_strings_len1[100]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp74),tmp75);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Blocks/Sources.mo",2167,5,2169,131,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nprices.timeEvents >= Modelica.Blocks.Types.TimeEvents.Always and prices.timeEvents <= Modelica.Blocks.Types.TimeEvents.NoTimeEvents", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp76 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1097
type: ALGORITHM

  assert(prices.timeScale >= 1e-15, "Variable violating min constraint: 1e-15 <= prices.timeScale, has value: " + String(prices.timeScale, "g"));
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1097(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1097};
  modelica_boolean tmp77;
  static const MMC_DEFSTRINGLIT(tmp78,73,"Variable violating min constraint: 1e-15 <= prices.timeScale, has value: ");
  modelica_string tmp79;
  static int tmp80 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp80)
  {
    tmp77 = GreaterEq(data->simulationInfo->realParameter[217] /* prices.timeScale PARAM */,1e-15);
    if(!tmp77)
    {
      tmp79 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[217] /* prices.timeScale PARAM */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp78),tmp79);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Blocks/Sources.mo",2156,5,2158,76,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nprices.timeScale >= 1e-15", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp80 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1098
type: ALGORITHM

  assert(prices.smoothness >= Modelica.Blocks.Types.Smoothness.LinearSegments and prices.smoothness <= Modelica.Blocks.Types.Smoothness.MonotoneContinuousDerivative2, "Variable violating min/max constraint: Modelica.Blocks.Types.Smoothness.LinearSegments <= prices.smoothness <= Modelica.Blocks.Types.Smoothness.MonotoneContinuousDerivative2, has value: " + String(prices.smoothness, "d"));
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1098(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1098};
  modelica_boolean tmp81;
  modelica_boolean tmp82;
  static const MMC_DEFSTRINGLIT(tmp83,186,"Variable violating min/max constraint: Modelica.Blocks.Types.Smoothness.LinearSegments <= prices.smoothness <= Modelica.Blocks.Types.Smoothness.MonotoneContinuousDerivative2, has value: ");
  modelica_string tmp84;
  static int tmp85 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp85)
  {
    tmp81 = GreaterEq(data->simulationInfo->integerParameter[29] /* prices.smoothness PARAM */,1);
    tmp82 = LessEq(data->simulationInfo->integerParameter[29] /* prices.smoothness PARAM */,5);
    if(!(tmp81 && tmp82))
    {
      tmp84 = modelica_integer_to_modelica_string_format(data->simulationInfo->integerParameter[29] /* prices.smoothness PARAM */, (modelica_string) mmc_strings_len1[100]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp83),tmp84);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Blocks/Sources.mo",2150,5,2152,61,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nprices.smoothness >= Modelica.Blocks.Types.Smoothness.LinearSegments and prices.smoothness <= Modelica.Blocks.Types.Smoothness.MonotoneContinuousDerivative2", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp85 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1099
type: ALGORITHM

  assert(prices.nout >= 1, "Variable violating min constraint: 1 <= prices.nout, has value: " + String(prices.nout, "d"));
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1099(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1099};
  modelica_boolean tmp86;
  static const MMC_DEFSTRINGLIT(tmp87,64,"Variable violating min constraint: 1 <= prices.nout, has value: ");
  modelica_string tmp88;
  static int tmp89 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp89)
  {
    tmp86 = GreaterEq(data->simulationInfo->integerParameter[28] /* prices.nout PARAM */,((modelica_integer) 1));
    if(!tmp86)
    {
      tmp88 = modelica_integer_to_modelica_string_format(data->simulationInfo->integerParameter[28] /* prices.nout PARAM */, (modelica_string) mmc_strings_len1[100]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp87),tmp88);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Blocks/Interfaces.mo",313,5,313,58,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nprices.nout >= 1", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp89 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1100
type: ALGORITHM

  assert(powerBlock.state_out_ref.h >= -10000000000.0 and powerBlock.state_out_ref.h <= 10000000000.0, "Variable violating min/max constraint: -10000000000.0 <= powerBlock.state_out_ref.h <= 10000000000.0, has value: " + String(powerBlock.state_out_ref.h, "g"));
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1100(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1100};
  modelica_boolean tmp90;
  modelica_boolean tmp91;
  static const MMC_DEFSTRINGLIT(tmp92,113,"Variable violating min/max constraint: -10000000000.0 <= powerBlock.state_out_ref.h <= 10000000000.0, has value: ");
  modelica_string tmp93;
  static int tmp94 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp94)
  {
    tmp90 = GreaterEq(data->simulationInfo->realParameter[199] /* powerBlock.state_out_ref.h PARAM */,-10000000000.0);
    tmp91 = LessEq(data->simulationInfo->realParameter[199] /* powerBlock.state_out_ref.h PARAM */,10000000000.0);
    if(!(tmp90 && tmp91))
    {
      tmp93 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[199] /* powerBlock.state_out_ref.h PARAM */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp92),tmp93);
      {
        FILE_INFO info = {"/home/cparrado/.openmodelica/libraries/SolarTherm/Media/MoltenSalt/MoltenSalt_ph/package.mo",70,3,70,41,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\npowerBlock.state_out_ref.h >= -10000000000.0 and powerBlock.state_out_ref.h <= 10000000000.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp94 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1101
type: ALGORITHM

  assert(powerBlock.state_in_ref.h >= -10000000000.0 and powerBlock.state_in_ref.h <= 10000000000.0, "Variable violating min/max constraint: -10000000000.0 <= powerBlock.state_in_ref.h <= 10000000000.0, has value: " + String(powerBlock.state_in_ref.h, "g"));
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1101(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1101};
  modelica_boolean tmp95;
  modelica_boolean tmp96;
  static const MMC_DEFSTRINGLIT(tmp97,112,"Variable violating min/max constraint: -10000000000.0 <= powerBlock.state_in_ref.h <= 10000000000.0, has value: ");
  modelica_string tmp98;
  static int tmp99 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp99)
  {
    tmp95 = GreaterEq(data->simulationInfo->realParameter[197] /* powerBlock.state_in_ref.h PARAM */,-10000000000.0);
    tmp96 = LessEq(data->simulationInfo->realParameter[197] /* powerBlock.state_in_ref.h PARAM */,10000000000.0);
    if(!(tmp95 && tmp96))
    {
      tmp98 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[197] /* powerBlock.state_in_ref.h PARAM */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp97),tmp98);
      {
        FILE_INFO info = {"/home/cparrado/.openmodelica/libraries/SolarTherm/Media/MoltenSalt/MoltenSalt_ph/package.mo",70,3,70,41,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\npowerBlock.state_in_ref.h >= -10000000000.0 and powerBlock.state_in_ref.h <= 10000000000.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp99 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1102
type: ALGORITHM

  assert(powerBlock.state_out_ref.p >= 0.0 and powerBlock.state_out_ref.p <= 100000000.0, "Variable violating min/max constraint: 0.0 <= powerBlock.state_out_ref.p <= 100000000.0, has value: " + String(powerBlock.state_out_ref.p, "g"));
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1102(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1102};
  modelica_boolean tmp100;
  modelica_boolean tmp101;
  static const MMC_DEFSTRINGLIT(tmp102,100,"Variable violating min/max constraint: 0.0 <= powerBlock.state_out_ref.p <= 100000000.0, has value: ");
  modelica_string tmp103;
  static int tmp104 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp104)
  {
    tmp100 = GreaterEq(data->simulationInfo->realParameter[200] /* powerBlock.state_out_ref.p PARAM */,0.0);
    tmp101 = LessEq(data->simulationInfo->realParameter[200] /* powerBlock.state_out_ref.p PARAM */,100000000.0);
    if(!(tmp100 && tmp101))
    {
      tmp103 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[200] /* powerBlock.state_out_ref.p PARAM */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp102),tmp103);
      {
        FILE_INFO info = {"/home/cparrado/.openmodelica/libraries/SolarTherm/Media/MoltenSalt/MoltenSalt_ph/package.mo",69,3,69,51,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\npowerBlock.state_out_ref.p >= 0.0 and powerBlock.state_out_ref.p <= 100000000.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp104 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1103
type: ALGORITHM

  assert(powerBlock.state_in_ref.p >= 0.0 and powerBlock.state_in_ref.p <= 100000000.0, "Variable violating min/max constraint: 0.0 <= powerBlock.state_in_ref.p <= 100000000.0, has value: " + String(powerBlock.state_in_ref.p, "g"));
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1103(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1103};
  modelica_boolean tmp105;
  modelica_boolean tmp106;
  static const MMC_DEFSTRINGLIT(tmp107,99,"Variable violating min/max constraint: 0.0 <= powerBlock.state_in_ref.p <= 100000000.0, has value: ");
  modelica_string tmp108;
  static int tmp109 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp109)
  {
    tmp105 = GreaterEq(data->simulationInfo->realParameter[198] /* powerBlock.state_in_ref.p PARAM */,0.0);
    tmp106 = LessEq(data->simulationInfo->realParameter[198] /* powerBlock.state_in_ref.p PARAM */,100000000.0);
    if(!(tmp105 && tmp106))
    {
      tmp108 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[198] /* powerBlock.state_in_ref.p PARAM */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp107),tmp108);
      {
        FILE_INFO info = {"/home/cparrado/.openmodelica/libraries/SolarTherm/Media/MoltenSalt/MoltenSalt_ph/package.mo",69,3,69,51,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\npowerBlock.state_in_ref.p >= 0.0 and powerBlock.state_in_ref.p <= 100000000.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp109 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1104
type: ALGORITHM

  assert(eff_blk >= 0.0, "Variable violating min constraint: 0.0 <= eff_blk, has value: " + String(eff_blk, "g"));
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1104(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1104};
  modelica_boolean tmp110;
  static const MMC_DEFSTRINGLIT(tmp111,62,"Variable violating min constraint: 0.0 <= eff_blk, has value: ");
  modelica_string tmp112;
  static int tmp113 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp113)
  {
    tmp110 = GreaterEq(data->simulationInfo->realParameter[126] /* eff_blk PARAM */,0.0);
    if(!tmp110)
    {
      tmp112 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[126] /* eff_blk PARAM */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp111),tmp112);
      {
        FILE_INFO info = {"/home/cparrado/.openmodelica/libraries/SolarTherm/Systems/Reference_1.mo",115,2,115,81,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\neff_blk >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp113 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1105
type: ALGORITHM

  assert(blk_T_amb_des >= 0.0, "Variable violating min constraint: 0.0 <= blk_T_amb_des, has value: " + String(blk_T_amb_des, "g"));
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1105(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1105};
  modelica_boolean tmp114;
  static const MMC_DEFSTRINGLIT(tmp115,68,"Variable violating min constraint: 0.0 <= blk_T_amb_des, has value: ");
  modelica_string tmp116;
  static int tmp117 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp117)
  {
    tmp114 = GreaterEq(data->simulationInfo->realParameter[50] /* blk_T_amb_des PARAM */,0.0);
    if(!tmp114)
    {
      tmp116 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[50] /* blk_T_amb_des PARAM */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp115),tmp116);
      {
        FILE_INFO info = {"/home/cparrado/.openmodelica/libraries/SolarTherm/Systems/Reference_1.mo",127,2,127,104,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nblk_T_amb_des >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp117 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1106
type: ALGORITHM

  assert(powerBlock.cool.T_des >= 0.0, "Variable violating min constraint: 0.0 <= powerBlock.cool.T_des, has value: " + String(powerBlock.cool.T_des, "g"));
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1106(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1106};
  modelica_boolean tmp118;
  static const MMC_DEFSTRINGLIT(tmp119,76,"Variable violating min constraint: 0.0 <= powerBlock.cool.T_des, has value: ");
  modelica_string tmp120;
  static int tmp121 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp121)
  {
    tmp118 = GreaterEq(data->simulationInfo->realParameter[186] /* powerBlock.cool.T_des PARAM */,0.0);
    if(!tmp118)
    {
      tmp120 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[186] /* powerBlock.cool.T_des PARAM */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp119),tmp120);
      {
        FILE_INFO info = {"/home/cparrado/.openmodelica/libraries/SolarTherm/Models/PowerBlocks/Cooling/SAM.mo",5,2,5,78,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\npowerBlock.cool.T_des >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp121 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1107
type: ALGORITHM

  assert(p_blk >= 0.0, "Variable violating min constraint: 0.0 <= p_blk, has value: " + String(p_blk, "g"));
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1107(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1107};
  modelica_boolean tmp122;
  static const MMC_DEFSTRINGLIT(tmp123,60,"Variable violating min constraint: 0.0 <= p_blk, has value: ");
  modelica_string tmp124;
  static int tmp125 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp125)
  {
    tmp122 = GreaterEq(data->simulationInfo->realParameter[176] /* p_blk PARAM */,0.0);
    if(!tmp122)
    {
      tmp124 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[176] /* p_blk PARAM */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp123),tmp124);
      {
        FILE_INFO info = {"/home/cparrado/.openmodelica/libraries/SolarTherm/Systems/Reference_1.mo",125,2,125,77,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\np_blk >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp125 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1108
type: ALGORITHM

  assert(powerBlock.cycle.p_bo >= 0.0, "Variable violating min constraint: 0.0 <= powerBlock.cycle.p_bo, has value: " + String(powerBlock.cycle.p_bo, "g"));
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1108(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1108};
  modelica_boolean tmp126;
  static const MMC_DEFSTRINGLIT(tmp127,76,"Variable violating min constraint: 0.0 <= powerBlock.cycle.p_bo, has value: ");
  modelica_string tmp128;
  static int tmp129 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp129)
  {
    tmp126 = GreaterEq(data->simulationInfo->realParameter[189] /* powerBlock.cycle.p_bo PARAM */,0.0);
    if(!tmp126)
    {
      tmp128 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[189] /* powerBlock.cycle.p_bo PARAM */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp127),tmp128);
      {
        FILE_INFO info = {"/home/cparrado/.openmodelica/libraries/SolarTherm/Models/PowerBlocks/Correlation/Rankine.mo",7,2,7,105,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\npowerBlock.cycle.p_bo >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp129 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1109
type: ALGORITHM

  assert(powerBlock.cycle.Tsat_ref >= 0.0, "Variable violating min constraint: 0.0 <= powerBlock.cycle.Tsat_ref, has value: " + String(powerBlock.cycle.Tsat_ref, "g"));
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1109(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1109};
  modelica_boolean tmp130;
  static const MMC_DEFSTRINGLIT(tmp131,80,"Variable violating min constraint: 0.0 <= powerBlock.cycle.Tsat_ref, has value: ");
  modelica_string tmp132;
  static int tmp133 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp133)
  {
    tmp130 = GreaterEq(data->simulationInfo->realParameter[188] /* powerBlock.cycle.Tsat_ref PARAM */,0.0);
    if(!tmp130)
    {
      tmp132 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[188] /* powerBlock.cycle.Tsat_ref PARAM */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp131),tmp132);
      {
        FILE_INFO info = {"/home/cparrado/.openmodelica/libraries/SolarTherm/Models/PowerBlocks/Correlation/Rankine.mo",8,2,8,97,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\npowerBlock.cycle.Tsat_ref >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp133 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1110
type: ALGORITHM

  assert(T_in_ref_blk >= 0.0, "Variable violating min constraint: 0.0 <= T_in_ref_blk, has value: " + String(T_in_ref_blk, "g"));
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1110(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1110};
  modelica_boolean tmp134;
  static const MMC_DEFSTRINGLIT(tmp135,67,"Variable violating min constraint: 0.0 <= T_in_ref_blk, has value: ");
  modelica_string tmp136;
  static int tmp137 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp137)
  {
    tmp134 = GreaterEq(data->simulationInfo->realParameter[40] /* T_in_ref_blk PARAM */,0.0);
    if(!tmp134)
    {
      tmp136 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[40] /* T_in_ref_blk PARAM */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp135),tmp136);
      {
        FILE_INFO info = {"/home/cparrado/.openmodelica/libraries/SolarTherm/Systems/Reference_1.mo",131,2,131,105,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nT_in_ref_blk >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp137 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1111
type: ALGORITHM

  assert(powerBlock.T_in_ref >= 0.0, "Variable violating min constraint: 0.0 <= powerBlock.T_in_ref, has value: " + String(powerBlock.T_in_ref, "g"));
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1111(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1111};
  modelica_boolean tmp138;
  static const MMC_DEFSTRINGLIT(tmp139,74,"Variable violating min constraint: 0.0 <= powerBlock.T_in_ref, has value: ");
  modelica_string tmp140;
  static int tmp141 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp141)
  {
    tmp138 = GreaterEq(data->simulationInfo->realParameter[182] /* powerBlock.T_in_ref PARAM */,0.0);
    if(!tmp138)
    {
      tmp140 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[182] /* powerBlock.T_in_ref PARAM */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp139),tmp140);
      {
        FILE_INFO info = {"/home/cparrado/.openmodelica/libraries/SolarTherm/Models/PowerBlocks/PowerBlockModel.mo",6,3,6,120,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\npowerBlock.T_in_ref >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp141 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1112
type: ALGORITHM

  assert(powerBlock.cycle.T_in_ref >= 0.0, "Variable violating min constraint: 0.0 <= powerBlock.cycle.T_in_ref, has value: " + String(powerBlock.cycle.T_in_ref, "g"));
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1112(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1112};
  modelica_boolean tmp142;
  static const MMC_DEFSTRINGLIT(tmp143,80,"Variable violating min constraint: 0.0 <= powerBlock.cycle.T_in_ref, has value: ");
  modelica_string tmp144;
  static int tmp145 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp145)
  {
    tmp142 = GreaterEq(data->simulationInfo->realParameter[187] /* powerBlock.cycle.T_in_ref PARAM */,0.0);
    if(!tmp142)
    {
      tmp144 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[187] /* powerBlock.cycle.T_in_ref PARAM */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp143),tmp144);
      {
        FILE_INFO info = {"/home/cparrado/.openmodelica/libraries/SolarTherm/Models/PowerBlocks/Correlation/Cycle.mo",5,2,5,118,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\npowerBlock.cycle.T_in_ref >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp145 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1113
type: ALGORITHM

  assert(powerBlock.T_des >= 0.0, "Variable violating min constraint: 0.0 <= powerBlock.T_des, has value: " + String(powerBlock.T_des, "g"));
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1113(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1113};
  modelica_boolean tmp146;
  static const MMC_DEFSTRINGLIT(tmp147,71,"Variable violating min constraint: 0.0 <= powerBlock.T_des, has value: ");
  modelica_string tmp148;
  static int tmp149 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp149)
  {
    tmp146 = GreaterEq(data->simulationInfo->realParameter[181] /* powerBlock.T_des PARAM */,0.0);
    if(!tmp146)
    {
      tmp148 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[181] /* powerBlock.T_des PARAM */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp147),tmp148);
      {
        FILE_INFO info = {"/home/cparrado/.openmodelica/libraries/SolarTherm/Models/PowerBlocks/PowerBlockModel.mo",21,3,21,143,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\npowerBlock.T_des >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp149 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1114
type: ALGORITHM

  assert(powerBlock.p_bo >= 0.0, "Variable violating min constraint: 0.0 <= powerBlock.p_bo, has value: " + String(powerBlock.p_bo, "g"));
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1114(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1114};
  modelica_boolean tmp150;
  static const MMC_DEFSTRINGLIT(tmp151,70,"Variable violating min constraint: 0.0 <= powerBlock.p_bo, has value: ");
  modelica_string tmp152;
  static int tmp153 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp153)
  {
    tmp150 = GreaterEq(data->simulationInfo->realParameter[196] /* powerBlock.p_bo PARAM */,0.0);
    if(!tmp150)
    {
      tmp152 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[196] /* powerBlock.p_bo PARAM */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp151),tmp152);
      {
        FILE_INFO info = {"/home/cparrado/.openmodelica/libraries/SolarTherm/Models/PowerBlocks/PowerBlockModel.mo",9,3,9,106,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\npowerBlock.p_bo >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp153 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1115
type: ALGORITHM

  assert(T_out_ref_blk >= 0.0, "Variable violating min constraint: 0.0 <= T_out_ref_blk, has value: " + String(T_out_ref_blk, "g"));
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1115(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1115};
  modelica_boolean tmp154;
  static const MMC_DEFSTRINGLIT(tmp155,68,"Variable violating min constraint: 0.0 <= T_out_ref_blk, has value: ");
  modelica_string tmp156;
  static int tmp157 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp157)
  {
    tmp154 = GreaterEq(data->simulationInfo->realParameter[41] /* T_out_ref_blk PARAM */,0.0);
    if(!tmp154)
    {
      tmp156 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[41] /* T_out_ref_blk PARAM */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp155),tmp156);
      {
        FILE_INFO info = {"/home/cparrado/.openmodelica/libraries/SolarTherm/Systems/Reference_1.mo",132,2,132,107,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nT_out_ref_blk >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp157 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1116
type: ALGORITHM

  assert(powerBlock.T_out_ref >= 0.0, "Variable violating min constraint: 0.0 <= powerBlock.T_out_ref, has value: " + String(powerBlock.T_out_ref, "g"));
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1116(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1116};
  modelica_boolean tmp158;
  static const MMC_DEFSTRINGLIT(tmp159,75,"Variable violating min constraint: 0.0 <= powerBlock.T_out_ref, has value: ");
  modelica_string tmp160;
  static int tmp161 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp161)
  {
    tmp158 = GreaterEq(data->simulationInfo->realParameter[183] /* powerBlock.T_out_ref PARAM */,0.0);
    if(!tmp158)
    {
      tmp160 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[183] /* powerBlock.T_out_ref PARAM */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp159),tmp160);
      {
        FILE_INFO info = {"/home/cparrado/.openmodelica/libraries/SolarTherm/Models/PowerBlocks/PowerBlockModel.mo",7,3,8,121,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\npowerBlock.T_out_ref >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp161 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1117
type: ALGORITHM

  assert(controlCold.PI.limiter.homotopyType >= Modelica.Blocks.Types.LimiterHomotopy.NoHomotopy and controlCold.PI.limiter.homotopyType <= Modelica.Blocks.Types.LimiterHomotopy.LowerLimit, "Variable violating min/max constraint: Modelica.Blocks.Types.LimiterHomotopy.NoHomotopy <= controlCold.PI.limiter.homotopyType <= Modelica.Blocks.Types.LimiterHomotopy.LowerLimit, has value: " + String(controlCold.PI.limiter.homotopyType, "d"));
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1117(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1117};
  modelica_boolean tmp162;
  modelica_boolean tmp163;
  static const MMC_DEFSTRINGLIT(tmp164,191,"Variable violating min/max constraint: Modelica.Blocks.Types.LimiterHomotopy.NoHomotopy <= controlCold.PI.limiter.homotopyType <= Modelica.Blocks.Types.LimiterHomotopy.LowerLimit, has value: ");
  modelica_string tmp165;
  static int tmp166 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp166)
  {
    tmp162 = GreaterEq(data->simulationInfo->integerParameter[4] /* controlCold.PI.limiter.homotopyType PARAM */,1);
    tmp163 = LessEq(data->simulationInfo->integerParameter[4] /* controlCold.PI.limiter.homotopyType PARAM */,4);
    if(!(tmp162 && tmp163))
    {
      tmp165 = modelica_integer_to_modelica_string_format(data->simulationInfo->integerParameter[4] /* controlCold.PI.limiter.homotopyType PARAM */, (modelica_string) mmc_strings_len1[100]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp164),tmp165);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Blocks/Nonlinear.mo",12,9,13,69,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\ncontrolCold.PI.limiter.homotopyType >= Modelica.Blocks.Types.LimiterHomotopy.NoHomotopy and controlCold.PI.limiter.homotopyType <= Modelica.Blocks.Types.LimiterHomotopy.LowerLimit", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp166 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1118
type: ALGORITHM

  assert(state_cold_set.h >= -10000000000.0 and state_cold_set.h <= 10000000000.0, "Variable violating min/max constraint: -10000000000.0 <= state_cold_set.h <= 10000000000.0, has value: " + String(state_cold_set.h, "g"));
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1118(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1118};
  modelica_boolean tmp167;
  modelica_boolean tmp168;
  static const MMC_DEFSTRINGLIT(tmp169,103,"Variable violating min/max constraint: -10000000000.0 <= state_cold_set.h <= 10000000000.0, has value: ");
  modelica_string tmp170;
  static int tmp171 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp171)
  {
    tmp167 = GreaterEq(data->simulationInfo->realParameter[243] /* state_cold_set.h PARAM */,-10000000000.0);
    tmp168 = LessEq(data->simulationInfo->realParameter[243] /* state_cold_set.h PARAM */,10000000000.0);
    if(!(tmp167 && tmp168))
    {
      tmp170 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[243] /* state_cold_set.h PARAM */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp169),tmp170);
      {
        FILE_INFO info = {"/home/cparrado/.openmodelica/libraries/SolarTherm/Media/MoltenSalt/MoltenSalt_ph/package.mo",70,3,70,41,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nstate_cold_set.h >= -10000000000.0 and state_cold_set.h <= 10000000000.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp171 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1119
type: ALGORITHM

  assert(state_hot_set.h >= -10000000000.0 and state_hot_set.h <= 10000000000.0, "Variable violating min/max constraint: -10000000000.0 <= state_hot_set.h <= 10000000000.0, has value: " + String(state_hot_set.h, "g"));
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1119(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1119};
  modelica_boolean tmp172;
  modelica_boolean tmp173;
  static const MMC_DEFSTRINGLIT(tmp174,102,"Variable violating min/max constraint: -10000000000.0 <= state_hot_set.h <= 10000000000.0, has value: ");
  modelica_string tmp175;
  static int tmp176 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp176)
  {
    tmp172 = GreaterEq(data->simulationInfo->realParameter[245] /* state_hot_set.h PARAM */,-10000000000.0);
    tmp173 = LessEq(data->simulationInfo->realParameter[245] /* state_hot_set.h PARAM */,10000000000.0);
    if(!(tmp172 && tmp173))
    {
      tmp175 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[245] /* state_hot_set.h PARAM */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp174),tmp175);
      {
        FILE_INFO info = {"/home/cparrado/.openmodelica/libraries/SolarTherm/Media/MoltenSalt/MoltenSalt_ph/package.mo",70,3,70,41,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nstate_hot_set.h >= -10000000000.0 and state_hot_set.h <= 10000000000.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp176 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1120
type: ALGORITHM

  assert(controlCold.PI.Ti >= 1e-60, "Variable violating min constraint: 1e-60 <= controlCold.PI.Ti, has value: " + String(controlCold.PI.Ti, "g"));
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1120(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1120};
  modelica_boolean tmp177;
  static const MMC_DEFSTRINGLIT(tmp178,74,"Variable violating min constraint: 1e-60 <= controlCold.PI.Ti, has value: ");
  modelica_string tmp179;
  static int tmp180 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp180)
  {
    tmp177 = GreaterEq(data->simulationInfo->realParameter[67] /* controlCold.PI.Ti PARAM */,1e-60);
    if(!tmp177)
    {
      tmp179 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[67] /* controlCold.PI.Ti PARAM */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp178),tmp179);
      {
        FILE_INFO info = {"/home/cparrado/.openmodelica/libraries/SolarTherm/Models/Control/PID_AW_reset3.mo",8,3,9,34,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\ncontrolCold.PI.Ti >= 1e-60", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp180 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1121
type: ALGORITHM

  assert(controlCold.PI.I.initType >= Modelica.Blocks.Types.Init.NoInit and controlCold.PI.I.initType <= Modelica.Blocks.Types.Init.InitialOutput, "Variable violating min/max constraint: Modelica.Blocks.Types.Init.NoInit <= controlCold.PI.I.initType <= Modelica.Blocks.Types.Init.InitialOutput, has value: " + String(controlCold.PI.I.initType, "d"));
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1121(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1121};
  modelica_boolean tmp181;
  modelica_boolean tmp182;
  static const MMC_DEFSTRINGLIT(tmp183,158,"Variable violating min/max constraint: Modelica.Blocks.Types.Init.NoInit <= controlCold.PI.I.initType <= Modelica.Blocks.Types.Init.InitialOutput, has value: ");
  modelica_string tmp184;
  static int tmp185 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp185)
  {
    tmp181 = GreaterEq(data->simulationInfo->integerParameter[2] /* controlCold.PI.I.initType PARAM */,1);
    tmp182 = LessEq(data->simulationInfo->integerParameter[2] /* controlCold.PI.I.initType PARAM */,4);
    if(!(tmp181 && tmp182))
    {
      tmp184 = modelica_integer_to_modelica_string_format(data->simulationInfo->integerParameter[2] /* controlCold.PI.I.initType PARAM */, (modelica_string) mmc_strings_len1[100]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp183),tmp184);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Blocks/Continuous.mo",19,5,21,40,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\ncontrolCold.PI.I.initType >= Modelica.Blocks.Types.Init.NoInit and controlCold.PI.I.initType <= Modelica.Blocks.Types.Init.InitialOutput", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp185 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1122
type: ALGORITHM

  assert(controlCold.PI.initType >= Modelica.Blocks.Types.InitPID.NoInit and controlCold.PI.initType <= Modelica.Blocks.Types.InitPID.DoNotUse_InitialIntegratorState, "Variable violating min/max constraint: Modelica.Blocks.Types.InitPID.NoInit <= controlCold.PI.initType <= Modelica.Blocks.Types.InitPID.DoNotUse_InitialIntegratorState, has value: " + String(controlCold.PI.initType, "d"));
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1122(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1122};
  modelica_boolean tmp186;
  modelica_boolean tmp187;
  static const MMC_DEFSTRINGLIT(tmp188,180,"Variable violating min/max constraint: Modelica.Blocks.Types.InitPID.NoInit <= controlCold.PI.initType <= Modelica.Blocks.Types.InitPID.DoNotUse_InitialIntegratorState, has value: ");
  modelica_string tmp189;
  static int tmp190 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp190)
  {
    tmp186 = GreaterEq(data->simulationInfo->integerParameter[3] /* controlCold.PI.initType PARAM */,1);
    tmp187 = LessEq(data->simulationInfo->integerParameter[3] /* controlCold.PI.initType PARAM */,5);
    if(!(tmp186 && tmp187))
    {
      tmp189 = modelica_integer_to_modelica_string_format(data->simulationInfo->integerParameter[3] /* controlCold.PI.initType PARAM */, (modelica_string) mmc_strings_len1[100]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp188),tmp189);
      {
        FILE_INFO info = {"/home/cparrado/.openmodelica/libraries/SolarTherm/Models/Control/PID_AW_reset3.mo",11,3,14,38,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\ncontrolCold.PI.initType >= Modelica.Blocks.Types.InitPID.NoInit and controlCold.PI.initType <= Modelica.Blocks.Types.InitPID.DoNotUse_InitialIntegratorState", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp190 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1123
type: ALGORITHM

  assert(m_max >= 0.0, "Variable violating min constraint: 0.0 <= m_max, has value: " + String(m_max, "g"));
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1123(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1123};
  modelica_boolean tmp191;
  static const MMC_DEFSTRINGLIT(tmp192,60,"Variable violating min constraint: 0.0 <= m_max, has value: ");
  modelica_string tmp193;
  static int tmp194 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp194)
  {
    tmp191 = GreaterEq(data->simulationInfo->realParameter[168] /* m_max PARAM */,0.0);
    if(!tmp191)
    {
      tmp193 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[168] /* m_max PARAM */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp192),tmp193);
      {
        FILE_INFO info = {"/home/cparrado/.openmodelica/libraries/SolarTherm/Systems/Reference_1.mo",76,2,76,83,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nm_max >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp194 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1124
type: ALGORITHM

  assert(rho_cold_set >= 0.0, "Variable violating min constraint: 0.0 <= rho_cold_set, has value: " + String(rho_cold_set, "g"));
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1124(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1124};
  modelica_boolean tmp195;
  static const MMC_DEFSTRINGLIT(tmp196,67,"Variable violating min constraint: 0.0 <= rho_cold_set, has value: ");
  modelica_string tmp197;
  static int tmp198 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp198)
  {
    tmp195 = GreaterEq(data->simulationInfo->realParameter[238] /* rho_cold_set PARAM */,0.0);
    if(!tmp195)
    {
      tmp197 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[238] /* rho_cold_set PARAM */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp196),tmp197);
      {
        FILE_INFO info = {"/home/cparrado/.openmodelica/libraries/SolarTherm/Systems/Reference_1.mo",166,2,166,98,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nrho_cold_set >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp198 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1125
type: ALGORITHM

  assert(rho_hot_set >= 0.0, "Variable violating min constraint: 0.0 <= rho_hot_set, has value: " + String(rho_hot_set, "g"));
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1125(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1125};
  modelica_boolean tmp199;
  static const MMC_DEFSTRINGLIT(tmp200,66,"Variable violating min constraint: 0.0 <= rho_hot_set, has value: ");
  modelica_string tmp201;
  static int tmp202 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp202)
  {
    tmp199 = GreaterEq(data->simulationInfo->realParameter[239] /* rho_hot_set PARAM */,0.0);
    if(!tmp199)
    {
      tmp201 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[239] /* rho_hot_set PARAM */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp200),tmp201);
      {
        FILE_INFO info = {"/home/cparrado/.openmodelica/libraries/SolarTherm/Systems/Reference_1.mo",167,2,167,95,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nrho_hot_set >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp202 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1126
type: ALGORITHM

  assert(D_storage >= 0.0, "Variable violating min constraint: 0.0 <= D_storage, has value: " + String(D_storage, "g"));
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1126(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1126};
  modelica_boolean tmp203;
  static const MMC_DEFSTRINGLIT(tmp204,64,"Variable violating min constraint: 0.0 <= D_storage, has value: ");
  modelica_string tmp205;
  static int tmp206 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp206)
  {
    tmp203 = GreaterEq(data->simulationInfo->realParameter[20] /* D_storage PARAM */,0.0);
    if(!tmp203)
    {
      tmp205 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[20] /* D_storage PARAM */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp204),tmp205);
      {
        FILE_INFO info = {"/home/cparrado/.openmodelica/libraries/SolarTherm/Systems/Reference_1.mo",79,2,79,77,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nD_storage >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp206 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1127
type: ALGORITHM

  assert(tankCold.D >= 0.0, "Variable violating min constraint: 0.0 <= tankCold.D, has value: " + String(tankCold.D, "g"));
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1127(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1127};
  modelica_boolean tmp207;
  static const MMC_DEFSTRINGLIT(tmp208,65,"Variable violating min constraint: 0.0 <= tankCold.D, has value: ");
  modelica_string tmp209;
  static int tmp210 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp210)
  {
    tmp207 = GreaterEq(data->simulationInfo->realParameter[253] /* tankCold.D PARAM */,0.0);
    if(!tmp207)
    {
      tmp209 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[253] /* tankCold.D PARAM */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp208),tmp209);
      {
        FILE_INFO info = {"/home/cparrado/.openmodelica/libraries/SolarTherm/Models/Storage/Tank/Tank.mo",6,3,6,44,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\ntankCold.D >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp210 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1128
type: ALGORITHM

  assert(tankCold.H >= 0.0, "Variable violating min constraint: 0.0 <= tankCold.H, has value: " + String(tankCold.H, "g"));
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1128(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1128};
  modelica_boolean tmp211;
  static const MMC_DEFSTRINGLIT(tmp212,65,"Variable violating min constraint: 0.0 <= tankCold.H, has value: ");
  modelica_string tmp213;
  static int tmp214 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp214)
  {
    tmp211 = GreaterEq(data->simulationInfo->realParameter[254] /* tankCold.H PARAM */,0.0);
    if(!tmp211)
    {
      tmp213 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[254] /* tankCold.H PARAM */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp212),tmp213);
      {
        FILE_INFO info = {"/home/cparrado/.openmodelica/libraries/SolarTherm/Models/Storage/Tank/Tank.mo",7,3,7,36,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\ntankCold.H >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp214 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1129
type: ALGORITHM

  assert(tankCold.e_ht >= 0.0, "Variable violating min constraint: 0.0 <= tankCold.e_ht, has value: " + String(tankCold.e_ht, "g"));
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1129(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1129};
  modelica_boolean tmp215;
  static const MMC_DEFSTRINGLIT(tmp216,68,"Variable violating min constraint: 0.0 <= tankCold.e_ht, has value: ");
  modelica_string tmp217;
  static int tmp218 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp218)
  {
    tmp215 = GreaterEq(data->simulationInfo->realParameter[261] /* tankCold.e_ht PARAM */,0.0);
    if(!tmp215)
    {
      tmp217 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[261] /* tankCold.e_ht PARAM */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp216),tmp217);
      {
        FILE_INFO info = {"/home/cparrado/.openmodelica/libraries/SolarTherm/Models/Storage/Tank/Tank.mo",32,3,33,96,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\ntankCold.e_ht >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp218 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1130
type: ALGORITHM

  assert(T_cold_aux_set >= 0.0, "Variable violating min constraint: 0.0 <= T_cold_aux_set, has value: " + String(T_cold_aux_set, "g"));
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1130(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1130};
  modelica_boolean tmp219;
  static const MMC_DEFSTRINGLIT(tmp220,69,"Variable violating min constraint: 0.0 <= T_cold_aux_set, has value: ");
  modelica_string tmp221;
  static int tmp222 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp222)
  {
    tmp219 = GreaterEq(data->simulationInfo->realParameter[34] /* T_cold_aux_set PARAM */,0.0);
    if(!tmp219)
    {
      tmp221 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[34] /* T_cold_aux_set PARAM */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp220),tmp221);
      {
        FILE_INFO info = {"/home/cparrado/.openmodelica/libraries/SolarTherm/Systems/Reference_1.mo",87,2,87,112,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nT_cold_aux_set >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp222 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1131
type: ALGORITHM

  assert(tankCold.T_set >= 0.0, "Variable violating min constraint: 0.0 <= tankCold.T_set, has value: " + String(tankCold.T_set, "g"));
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1131(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1131};
  modelica_boolean tmp223;
  static const MMC_DEFSTRINGLIT(tmp224,69,"Variable violating min constraint: 0.0 <= tankCold.T_set, has value: ");
  modelica_string tmp225;
  static int tmp226 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp226)
  {
    tmp223 = GreaterEq(data->simulationInfo->realParameter[256] /* tankCold.T_set PARAM */,0.0);
    if(!tmp223)
    {
      tmp225 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[256] /* tankCold.T_set PARAM */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp224),tmp225);
      {
        FILE_INFO info = {"/home/cparrado/.openmodelica/libraries/SolarTherm/Models/Storage/Tank/Tank.mo",29,3,29,120,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\ntankCold.T_set >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp226 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1132
type: ALGORITHM

  assert(T_cold_start >= 0.0, "Variable violating min constraint: 0.0 <= T_cold_start, has value: " + String(T_cold_start, "g"));
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1132(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1132};
  modelica_boolean tmp227;
  static const MMC_DEFSTRINGLIT(tmp228,67,"Variable violating min constraint: 0.0 <= T_cold_start, has value: ");
  modelica_string tmp229;
  static int tmp230 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp230)
  {
    tmp227 = GreaterEq(data->simulationInfo->realParameter[36] /* T_cold_start PARAM */,0.0);
    if(!tmp227)
    {
      tmp229 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[36] /* T_cold_start PARAM */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp228),tmp229);
      {
        FILE_INFO info = {"/home/cparrado/.openmodelica/libraries/SolarTherm/Systems/Reference_1.mo",84,2,84,92,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nT_cold_start >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp230 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1133
type: ALGORITHM

  assert(tankCold.T_start >= 0.0, "Variable violating min constraint: 0.0 <= tankCold.T_start, has value: " + String(tankCold.T_start, "g"));
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1133(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1133};
  modelica_boolean tmp231;
  static const MMC_DEFSTRINGLIT(tmp232,71,"Variable violating min constraint: 0.0 <= tankCold.T_start, has value: ");
  modelica_string tmp233;
  static int tmp234 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp234)
  {
    tmp231 = GreaterEq(data->simulationInfo->realParameter[257] /* tankCold.T_start PARAM */,0.0);
    if(!tmp231)
    {
      tmp233 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[257] /* tankCold.T_start PARAM */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp232),tmp233);
      {
        FILE_INFO info = {"/home/cparrado/.openmodelica/libraries/SolarTherm/Models/Storage/Tank/Tank.mo",27,3,27,123,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\ntankCold.T_start >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp234 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1134
type: ALGORITHM

  assert(tankCold.p_fixed >= 0.0, "Variable violating min constraint: 0.0 <= tankCold.p_fixed, has value: " + String(tankCold.p_fixed, "g"));
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1134(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1134};
  modelica_boolean tmp235;
  static const MMC_DEFSTRINGLIT(tmp236,71,"Variable violating min constraint: 0.0 <= tankCold.p_fixed, has value: ");
  modelica_string tmp237;
  static int tmp238 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp238)
  {
    tmp235 = GreaterEq(data->simulationInfo->realParameter[262] /* tankCold.p_fixed PARAM */,0.0);
    if(!tmp235)
    {
      tmp237 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[262] /* tankCold.p_fixed PARAM */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp236),tmp237);
      {
        FILE_INFO info = {"/home/cparrado/.openmodelica/libraries/SolarTherm/Models/Storage/Tank/Tank.mo",15,3,17,68,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\ntankCold.p_fixed >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp238 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1135
type: ALGORITHM

  assert(tankHot.D >= 0.0, "Variable violating min constraint: 0.0 <= tankHot.D, has value: " + String(tankHot.D, "g"));
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1135(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1135};
  modelica_boolean tmp239;
  static const MMC_DEFSTRINGLIT(tmp240,64,"Variable violating min constraint: 0.0 <= tankHot.D, has value: ");
  modelica_string tmp241;
  static int tmp242 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp242)
  {
    tmp239 = GreaterEq(data->simulationInfo->realParameter[263] /* tankHot.D PARAM */,0.0);
    if(!tmp239)
    {
      tmp241 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[263] /* tankHot.D PARAM */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp240),tmp241);
      {
        FILE_INFO info = {"/home/cparrado/.openmodelica/libraries/SolarTherm/Models/Storage/Tank/Tank.mo",6,3,6,44,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\ntankHot.D >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp242 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1136
type: ALGORITHM

  assert(tankHot.H >= 0.0, "Variable violating min constraint: 0.0 <= tankHot.H, has value: " + String(tankHot.H, "g"));
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1136(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1136};
  modelica_boolean tmp243;
  static const MMC_DEFSTRINGLIT(tmp244,64,"Variable violating min constraint: 0.0 <= tankHot.H, has value: ");
  modelica_string tmp245;
  static int tmp246 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp246)
  {
    tmp243 = GreaterEq(data->simulationInfo->realParameter[264] /* tankHot.H PARAM */,0.0);
    if(!tmp243)
    {
      tmp245 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[264] /* tankHot.H PARAM */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp244),tmp245);
      {
        FILE_INFO info = {"/home/cparrado/.openmodelica/libraries/SolarTherm/Models/Storage/Tank/Tank.mo",7,3,7,36,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\ntankHot.H >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp246 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1137
type: ALGORITHM

  assert(tankHot.e_ht >= 0.0, "Variable violating min constraint: 0.0 <= tankHot.e_ht, has value: " + String(tankHot.e_ht, "g"));
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1137(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1137};
  modelica_boolean tmp247;
  static const MMC_DEFSTRINGLIT(tmp248,67,"Variable violating min constraint: 0.0 <= tankHot.e_ht, has value: ");
  modelica_string tmp249;
  static int tmp250 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp250)
  {
    tmp247 = GreaterEq(data->simulationInfo->realParameter[271] /* tankHot.e_ht PARAM */,0.0);
    if(!tmp247)
    {
      tmp249 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[271] /* tankHot.e_ht PARAM */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp248),tmp249);
      {
        FILE_INFO info = {"/home/cparrado/.openmodelica/libraries/SolarTherm/Models/Storage/Tank/Tank.mo",32,3,33,96,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\ntankHot.e_ht >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp250 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1138
type: ALGORITHM

  assert(T_hot_aux_set >= 0.0, "Variable violating min constraint: 0.0 <= T_hot_aux_set, has value: " + String(T_hot_aux_set, "g"));
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1138(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1138};
  modelica_boolean tmp251;
  static const MMC_DEFSTRINGLIT(tmp252,68,"Variable violating min constraint: 0.0 <= T_hot_aux_set, has value: ");
  modelica_string tmp253;
  static int tmp254 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp254)
  {
    tmp251 = GreaterEq(data->simulationInfo->realParameter[37] /* T_hot_aux_set PARAM */,0.0);
    if(!tmp251)
    {
      tmp253 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[37] /* T_hot_aux_set PARAM */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp252),tmp253);
      {
        FILE_INFO info = {"/home/cparrado/.openmodelica/libraries/SolarTherm/Systems/Reference_1.mo",88,2,88,110,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nT_hot_aux_set >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp254 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1139
type: ALGORITHM

  assert(tankHot.T_set >= 0.0, "Variable violating min constraint: 0.0 <= tankHot.T_set, has value: " + String(tankHot.T_set, "g"));
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1139(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1139};
  modelica_boolean tmp255;
  static const MMC_DEFSTRINGLIT(tmp256,68,"Variable violating min constraint: 0.0 <= tankHot.T_set, has value: ");
  modelica_string tmp257;
  static int tmp258 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp258)
  {
    tmp255 = GreaterEq(data->simulationInfo->realParameter[266] /* tankHot.T_set PARAM */,0.0);
    if(!tmp255)
    {
      tmp257 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[266] /* tankHot.T_set PARAM */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp256),tmp257);
      {
        FILE_INFO info = {"/home/cparrado/.openmodelica/libraries/SolarTherm/Models/Storage/Tank/Tank.mo",29,3,29,120,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\ntankHot.T_set >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp258 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1140
type: ALGORITHM

  assert(T_hot_start >= 0.0, "Variable violating min constraint: 0.0 <= T_hot_start, has value: " + String(T_hot_start, "g"));
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1140(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1140};
  modelica_boolean tmp259;
  static const MMC_DEFSTRINGLIT(tmp260,66,"Variable violating min constraint: 0.0 <= T_hot_start, has value: ");
  modelica_string tmp261;
  static int tmp262 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp262)
  {
    tmp259 = GreaterEq(data->simulationInfo->realParameter[39] /* T_hot_start PARAM */,0.0);
    if(!tmp259)
    {
      tmp261 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[39] /* T_hot_start PARAM */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp260),tmp261);
      {
        FILE_INFO info = {"/home/cparrado/.openmodelica/libraries/SolarTherm/Systems/Reference_1.mo",85,2,85,90,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nT_hot_start >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp262 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1141
type: ALGORITHM

  assert(tankHot.T_start >= 0.0, "Variable violating min constraint: 0.0 <= tankHot.T_start, has value: " + String(tankHot.T_start, "g"));
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1141(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1141};
  modelica_boolean tmp263;
  static const MMC_DEFSTRINGLIT(tmp264,70,"Variable violating min constraint: 0.0 <= tankHot.T_start, has value: ");
  modelica_string tmp265;
  static int tmp266 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp266)
  {
    tmp263 = GreaterEq(data->simulationInfo->realParameter[267] /* tankHot.T_start PARAM */,0.0);
    if(!tmp263)
    {
      tmp265 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[267] /* tankHot.T_start PARAM */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp264),tmp265);
      {
        FILE_INFO info = {"/home/cparrado/.openmodelica/libraries/SolarTherm/Models/Storage/Tank/Tank.mo",27,3,27,123,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\ntankHot.T_start >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp266 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1142
type: ALGORITHM

  assert(tankHot.p_fixed >= 0.0, "Variable violating min constraint: 0.0 <= tankHot.p_fixed, has value: " + String(tankHot.p_fixed, "g"));
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1142(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1142};
  modelica_boolean tmp267;
  static const MMC_DEFSTRINGLIT(tmp268,70,"Variable violating min constraint: 0.0 <= tankHot.p_fixed, has value: ");
  modelica_string tmp269;
  static int tmp270 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp270)
  {
    tmp267 = GreaterEq(data->simulationInfo->realParameter[272] /* tankHot.p_fixed PARAM */,0.0);
    if(!tmp267)
    {
      tmp269 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[272] /* tankHot.p_fixed PARAM */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp268),tmp269);
      {
        FILE_INFO info = {"/home/cparrado/.openmodelica/libraries/SolarTherm/Models/Storage/Tank/Tank.mo",15,3,17,68,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\ntankHot.p_fixed >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp270 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1143
type: ALGORITHM

  assert(receiver.T_0 >= 0.0, "Variable violating min constraint: 0.0 <= receiver.T_0, has value: " + String(receiver.T_0, "g"));
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1143(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1143};
  modelica_boolean tmp271;
  static const MMC_DEFSTRINGLIT(tmp272,67,"Variable violating min constraint: 0.0 <= receiver.T_0, has value: ");
  modelica_string tmp273;
  static int tmp274 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp274)
  {
    tmp271 = GreaterEq(data->simulationInfo->realParameter[229] /* receiver.T_0 PARAM */,0.0);
    if(!tmp271)
    {
      tmp273 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[229] /* receiver.T_0 PARAM */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp272),tmp273);
      {
        FILE_INFO info = {"/home/cparrado/.openmodelica/libraries/SolarTherm/Models/CSP/CRS/Receivers/ReceiverSimple.mo",47,3,47,75,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nreceiver.T_0 >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp274 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1144
type: ALGORITHM

  assert(receiver.state_0.h >= -10000000000.0 and receiver.state_0.h <= 10000000000.0, "Variable violating min/max constraint: -10000000000.0 <= receiver.state_0.h <= 10000000000.0, has value: " + String(receiver.state_0.h, "g"));
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1144(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1144};
  modelica_boolean tmp275;
  modelica_boolean tmp276;
  static const MMC_DEFSTRINGLIT(tmp277,105,"Variable violating min/max constraint: -10000000000.0 <= receiver.state_0.h <= 10000000000.0, has value: ");
  modelica_string tmp278;
  static int tmp279 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp279)
  {
    tmp275 = GreaterEq(data->simulationInfo->realParameter[234] /* receiver.state_0.h PARAM */,-10000000000.0);
    tmp276 = LessEq(data->simulationInfo->realParameter[234] /* receiver.state_0.h PARAM */,10000000000.0);
    if(!(tmp275 && tmp276))
    {
      tmp278 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[234] /* receiver.state_0.h PARAM */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp277),tmp278);
      {
        FILE_INFO info = {"/home/cparrado/.openmodelica/libraries/SolarTherm/Media/MoltenSalt/MoltenSalt_ph/package.mo",70,3,70,41,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nreceiver.state_0.h >= -10000000000.0 and receiver.state_0.h <= 10000000000.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp279 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1145
type: ALGORITHM

  assert(receiver.state_0.p >= 0.0 and receiver.state_0.p <= 100000000.0, "Variable violating min/max constraint: 0.0 <= receiver.state_0.p <= 100000000.0, has value: " + String(receiver.state_0.p, "g"));
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1145(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1145};
  modelica_boolean tmp280;
  modelica_boolean tmp281;
  static const MMC_DEFSTRINGLIT(tmp282,92,"Variable violating min/max constraint: 0.0 <= receiver.state_0.p <= 100000000.0, has value: ");
  modelica_string tmp283;
  static int tmp284 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp284)
  {
    tmp280 = GreaterEq(data->simulationInfo->realParameter[235] /* receiver.state_0.p PARAM */,0.0);
    tmp281 = LessEq(data->simulationInfo->realParameter[235] /* receiver.state_0.p PARAM */,100000000.0);
    if(!(tmp280 && tmp281))
    {
      tmp283 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[235] /* receiver.state_0.p PARAM */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp282),tmp283);
      {
        FILE_INFO info = {"/home/cparrado/.openmodelica/libraries/SolarTherm/Media/MoltenSalt/MoltenSalt_ph/package.mo",69,3,69,51,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nreceiver.state_0.p >= 0.0 and receiver.state_0.p <= 100000000.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp284 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1146
type: ALGORITHM

  assert(D_tb_rec >= 0.0, "Variable violating min constraint: 0.0 <= D_tb_rec, has value: " + String(D_tb_rec, "g"));
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1146(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1146};
  modelica_boolean tmp285;
  static const MMC_DEFSTRINGLIT(tmp286,63,"Variable violating min constraint: 0.0 <= D_tb_rec, has value: ");
  modelica_string tmp287;
  static int tmp288 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp288)
  {
    tmp285 = GreaterEq(data->simulationInfo->realParameter[21] /* D_tb_rec PARAM */,0.0);
    if(!tmp285)
    {
      tmp287 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[21] /* D_tb_rec PARAM */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp286),tmp287);
      {
        FILE_INFO info = {"/home/cparrado/.openmodelica/libraries/SolarTherm/Systems/Reference_1.mo",58,2,58,71,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nD_tb_rec >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp288 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1147
type: ALGORITHM

  assert(receiver.D_tb >= 0.0, "Variable violating min constraint: 0.0 <= receiver.D_tb, has value: " + String(receiver.D_tb, "g"));
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1147(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1147};
  modelica_boolean tmp289;
  static const MMC_DEFSTRINGLIT(tmp290,68,"Variable violating min constraint: 0.0 <= receiver.D_tb, has value: ");
  modelica_string tmp291;
  static int tmp292 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp292)
  {
    tmp289 = GreaterEq(data->simulationInfo->realParameter[226] /* receiver.D_tb PARAM */,0.0);
    if(!tmp289)
    {
      tmp291 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[226] /* receiver.D_tb PARAM */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp290),tmp291);
      {
        FILE_INFO info = {"/home/cparrado/.openmodelica/libraries/SolarTherm/Models/CSP/CRS/Receivers/ReceiverSimple.mo",11,3,11,96,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nreceiver.D_tb >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp292 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1148
type: ALGORITHM

  assert(D_receiver >= 0.0, "Variable violating min constraint: 0.0 <= D_receiver, has value: " + String(D_receiver, "g"));
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1148(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1148};
  modelica_boolean tmp293;
  static const MMC_DEFSTRINGLIT(tmp294,65,"Variable violating min constraint: 0.0 <= D_receiver, has value: ");
  modelica_string tmp295;
  static int tmp296 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp296)
  {
    tmp293 = GreaterEq(data->simulationInfo->realParameter[19] /* D_receiver PARAM */,0.0);
    if(!tmp293)
    {
      tmp295 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[19] /* D_receiver PARAM */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp294),tmp295);
      {
        FILE_INFO info = {"/home/cparrado/.openmodelica/libraries/SolarTherm/Systems/Reference_1.mo",60,2,60,62,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nD_receiver >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp296 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1149
type: ALGORITHM

  assert(receiver.D_rcv >= 0.0, "Variable violating min constraint: 0.0 <= receiver.D_rcv, has value: " + String(receiver.D_rcv, "g"));
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1149(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1149};
  modelica_boolean tmp297;
  static const MMC_DEFSTRINGLIT(tmp298,69,"Variable violating min constraint: 0.0 <= receiver.D_rcv, has value: ");
  modelica_string tmp299;
  static int tmp300 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp300)
  {
    tmp297 = GreaterEq(data->simulationInfo->realParameter[225] /* receiver.D_rcv PARAM */,0.0);
    if(!tmp297)
    {
      tmp299 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[225] /* receiver.D_rcv PARAM */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp298),tmp299);
      {
        FILE_INFO info = {"/home/cparrado/.openmodelica/libraries/SolarTherm/Models/CSP/CRS/Receivers/ReceiverSimple.mo",9,3,9,95,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nreceiver.D_rcv >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp300 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1150
type: ALGORITHM

  assert(t_tb_rec >= 0.0, "Variable violating min constraint: 0.0 <= t_tb_rec, has value: " + String(t_tb_rec, "g"));
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1150(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1150};
  modelica_boolean tmp301;
  static const MMC_DEFSTRINGLIT(tmp302,63,"Variable violating min constraint: 0.0 <= t_tb_rec, has value: ");
  modelica_string tmp303;
  static int tmp304 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp304)
  {
    tmp301 = GreaterEq(data->simulationInfo->realParameter[251] /* t_tb_rec PARAM */,0.0);
    if(!tmp301)
    {
      tmp303 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[251] /* t_tb_rec PARAM */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp302),tmp303);
      {
        FILE_INFO info = {"/home/cparrado/.openmodelica/libraries/SolarTherm/Systems/Reference_1.mo",57,2,57,74,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nt_tb_rec >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp304 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1151
type: ALGORITHM

  assert(receiver.t_tb >= 0.0, "Variable violating min constraint: 0.0 <= receiver.t_tb, has value: " + String(receiver.t_tb, "g"));
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1151(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1151};
  modelica_boolean tmp305;
  static const MMC_DEFSTRINGLIT(tmp306,68,"Variable violating min constraint: 0.0 <= receiver.t_tb, has value: ");
  modelica_string tmp307;
  static int tmp308 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp308)
  {
    tmp305 = GreaterEq(data->simulationInfo->realParameter[236] /* receiver.t_tb PARAM */,0.0);
    if(!tmp305)
    {
      tmp307 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[236] /* receiver.t_tb PARAM */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp306),tmp307);
      {
        FILE_INFO info = {"/home/cparrado/.openmodelica/libraries/SolarTherm/Models/CSP/CRS/Receivers/ReceiverSimple.mo",12,3,12,97,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nreceiver.t_tb >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp308 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1152
type: ALGORITHM

  assert(em_rec >= 0.0, "Variable violating min constraint: 0.0 <= em_rec, has value: " + String(em_rec, "g"));
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1152(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1152};
  modelica_boolean tmp309;
  static const MMC_DEFSTRINGLIT(tmp310,61,"Variable violating min constraint: 0.0 <= em_rec, has value: ");
  modelica_string tmp311;
  static int tmp312 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp312)
  {
    tmp309 = GreaterEq(data->simulationInfo->realParameter[128] /* em_rec PARAM */,0.0);
    if(!tmp309)
    {
      tmp311 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[128] /* em_rec PARAM */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp310),tmp311);
      {
        FILE_INFO info = {"/home/cparrado/.openmodelica/libraries/SolarTherm/Systems/Reference_1.mo",65,2,65,69,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nem_rec >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp312 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1153
type: ALGORITHM

  assert(receiver.em >= 0.0, "Variable violating min constraint: 0.0 <= receiver.em, has value: " + String(receiver.em, "g"));
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1153(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1153};
  modelica_boolean tmp313;
  static const MMC_DEFSTRINGLIT(tmp314,66,"Variable violating min constraint: 0.0 <= receiver.em, has value: ");
  modelica_string tmp315;
  static int tmp316 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp316)
  {
    tmp313 = GreaterEq(data->simulationInfo->realParameter[232] /* receiver.em PARAM */,0.0);
    if(!tmp313)
    {
      tmp315 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[232] /* receiver.em PARAM */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp314),tmp315);
      {
        FILE_INFO info = {"/home/cparrado/.openmodelica/libraries/SolarTherm/Models/CSP/CRS/Receivers/ReceiverSimple.mo",14,3,14,93,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nreceiver.em >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp316 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1154
type: ALGORITHM

  assert(ab_rec >= 0.0, "Variable violating min constraint: 0.0 <= ab_rec, has value: " + String(ab_rec, "g"));
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1154(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1154};
  modelica_boolean tmp317;
  static const MMC_DEFSTRINGLIT(tmp318,61,"Variable violating min constraint: 0.0 <= ab_rec, has value: ");
  modelica_string tmp319;
  static int tmp320 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp320)
  {
    tmp317 = GreaterEq(data->simulationInfo->realParameter[48] /* ab_rec PARAM */,0.0);
    if(!tmp317)
    {
      tmp319 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[48] /* ab_rec PARAM */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp318),tmp319);
      {
        FILE_INFO info = {"/home/cparrado/.openmodelica/libraries/SolarTherm/Systems/Reference_1.mo",64,2,64,70,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nab_rec >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp320 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1155
type: ALGORITHM

  assert(receiver.ab >= 0.0, "Variable violating min constraint: 0.0 <= receiver.ab, has value: " + String(receiver.ab, "g"));
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1155(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1155};
  modelica_boolean tmp321;
  static const MMC_DEFSTRINGLIT(tmp322,66,"Variable violating min constraint: 0.0 <= receiver.ab, has value: ");
  modelica_string tmp323;
  static int tmp324 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp324)
  {
    tmp321 = GreaterEq(data->simulationInfo->realParameter[231] /* receiver.ab PARAM */,0.0);
    if(!tmp321)
    {
      tmp323 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[231] /* receiver.ab PARAM */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp322),tmp323);
      {
        FILE_INFO info = {"/home/cparrado/.openmodelica/libraries/SolarTherm/Models/CSP/CRS/Receivers/ReceiverSimple.mo",13,3,13,95,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nreceiver.ab >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp324 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1156
type: ALGORITHM

  assert(heliostatField.optical.nu_table.smoothness >= Modelica.Blocks.Types.Smoothness.LinearSegments and heliostatField.optical.nu_table.smoothness <= Modelica.Blocks.Types.Smoothness.MonotoneContinuousDerivative2, "Variable violating min/max constraint: Modelica.Blocks.Types.Smoothness.LinearSegments <= heliostatField.optical.nu_table.smoothness <= Modelica.Blocks.Types.Smoothness.MonotoneContinuousDerivative2, has value: " + String(heliostatField.optical.nu_table.smoothness, "d"));
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1156(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1156};
  modelica_boolean tmp325;
  modelica_boolean tmp326;
  static const MMC_DEFSTRINGLIT(tmp327,211,"Variable violating min/max constraint: Modelica.Blocks.Types.Smoothness.LinearSegments <= heliostatField.optical.nu_table.smoothness <= Modelica.Blocks.Types.Smoothness.MonotoneContinuousDerivative2, has value: ");
  modelica_string tmp328;
  static int tmp329 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp329)
  {
    tmp325 = GreaterEq(data->simulationInfo->integerParameter[24] /* heliostatField.optical.nu_table.smoothness PARAM */,1);
    tmp326 = LessEq(data->simulationInfo->integerParameter[24] /* heliostatField.optical.nu_table.smoothness PARAM */,5);
    if(!(tmp325 && tmp326))
    {
      tmp328 = modelica_integer_to_modelica_string_format(data->simulationInfo->integerParameter[24] /* heliostatField.optical.nu_table.smoothness PARAM */, (modelica_string) mmc_strings_len1[100]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp327),tmp328);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Blocks/Tables.mo",969,7,971,63,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nheliostatField.optical.nu_table.smoothness >= Modelica.Blocks.Types.Smoothness.LinearSegments and heliostatField.optical.nu_table.smoothness <= Modelica.Blocks.Types.Smoothness.MonotoneContinuousDerivative2", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp329 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1157
type: ALGORITHM

  assert(heliostatField.optical.angles >= SolarTherm.Types.Solar_angles.elo_hra and heliostatField.optical.angles <= SolarTherm.Types.Solar_angles.zen_azi, "Variable violating min/max constraint: SolarTherm.Types.Solar_angles.elo_hra <= heliostatField.optical.angles <= SolarTherm.Types.Solar_angles.zen_azi, has value: " + String(heliostatField.optical.angles, "d"));
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1157(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1157};
  modelica_boolean tmp330;
  modelica_boolean tmp331;
  static const MMC_DEFSTRINGLIT(tmp332,163,"Variable violating min/max constraint: SolarTherm.Types.Solar_angles.elo_hra <= heliostatField.optical.angles <= SolarTherm.Types.Solar_angles.zen_azi, has value: ");
  modelica_string tmp333;
  static int tmp334 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp334)
  {
    tmp330 = GreaterEq(data->simulationInfo->integerParameter[22] /* heliostatField.optical.angles PARAM */,1);
    tmp331 = LessEq(data->simulationInfo->integerParameter[22] /* heliostatField.optical.angles PARAM */,4);
    if(!(tmp330 && tmp331))
    {
      tmp333 = modelica_integer_to_modelica_string_format(data->simulationInfo->integerParameter[22] /* heliostatField.optical.angles PARAM */, (modelica_string) mmc_strings_len1[100]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp332),tmp333);
      {
        FILE_INFO info = {"/home/cparrado/.openmodelica/libraries/SolarTherm/Models/CSP/CRS/HeliostatsField/Optical/Table.mo",9,3,11,59,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nheliostatField.optical.angles >= SolarTherm.Types.Solar_angles.elo_hra and heliostatField.optical.angles <= SolarTherm.Types.Solar_angles.zen_azi", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp334 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1158
type: ALGORITHM

  assert(data.table.timeEvents >= Modelica.Blocks.Types.TimeEvents.Always and data.table.timeEvents <= Modelica.Blocks.Types.TimeEvents.NoTimeEvents, "Variable violating min/max constraint: Modelica.Blocks.Types.TimeEvents.Always <= data.table.timeEvents <= Modelica.Blocks.Types.TimeEvents.NoTimeEvents, has value: " + String(data.table.timeEvents, "d"));
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1158(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1158};
  modelica_boolean tmp335;
  modelica_boolean tmp336;
  static const MMC_DEFSTRINGLIT(tmp337,165,"Variable violating min/max constraint: Modelica.Blocks.Types.TimeEvents.Always <= data.table.timeEvents <= Modelica.Blocks.Types.TimeEvents.NoTimeEvents, has value: ");
  modelica_string tmp338;
  static int tmp339 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp339)
  {
    tmp335 = GreaterEq(data->simulationInfo->integerParameter[19] /* data.table.timeEvents PARAM */,1);
    tmp336 = LessEq(data->simulationInfo->integerParameter[19] /* data.table.timeEvents PARAM */,3);
    if(!(tmp335 && tmp336))
    {
      tmp338 = modelica_integer_to_modelica_string_format(data->simulationInfo->integerParameter[19] /* data.table.timeEvents PARAM */, (modelica_string) mmc_strings_len1[100]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp337),tmp338);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Blocks/Sources.mo",2167,5,2169,131,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\ndata.table.timeEvents >= Modelica.Blocks.Types.TimeEvents.Always and data.table.timeEvents <= Modelica.Blocks.Types.TimeEvents.NoTimeEvents", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp339 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1159
type: ALGORITHM

  assert(data.table.timeScale >= 1e-15, "Variable violating min constraint: 1e-15 <= data.table.timeScale, has value: " + String(data.table.timeScale, "g"));
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1159(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1159};
  modelica_boolean tmp340;
  static const MMC_DEFSTRINGLIT(tmp341,77,"Variable violating min constraint: 1e-15 <= data.table.timeScale, has value: ");
  modelica_string tmp342;
  static int tmp343 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp343)
  {
    tmp340 = GreaterEq(data->simulationInfo->realParameter[125] /* data.table.timeScale PARAM */,1e-15);
    if(!tmp340)
    {
      tmp342 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[125] /* data.table.timeScale PARAM */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp341),tmp342);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Blocks/Sources.mo",2156,5,2158,76,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\ndata.table.timeScale >= 1e-15", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp343 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1160
type: ALGORITHM

  assert(data.table.smoothness >= Modelica.Blocks.Types.Smoothness.LinearSegments and data.table.smoothness <= Modelica.Blocks.Types.Smoothness.MonotoneContinuousDerivative2, "Variable violating min/max constraint: Modelica.Blocks.Types.Smoothness.LinearSegments <= data.table.smoothness <= Modelica.Blocks.Types.Smoothness.MonotoneContinuousDerivative2, has value: " + String(data.table.smoothness, "d"));
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1160(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1160};
  modelica_boolean tmp344;
  modelica_boolean tmp345;
  static const MMC_DEFSTRINGLIT(tmp346,190,"Variable violating min/max constraint: Modelica.Blocks.Types.Smoothness.LinearSegments <= data.table.smoothness <= Modelica.Blocks.Types.Smoothness.MonotoneContinuousDerivative2, has value: ");
  modelica_string tmp347;
  static int tmp348 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp348)
  {
    tmp344 = GreaterEq(data->simulationInfo->integerParameter[18] /* data.table.smoothness PARAM */,1);
    tmp345 = LessEq(data->simulationInfo->integerParameter[18] /* data.table.smoothness PARAM */,5);
    if(!(tmp344 && tmp345))
    {
      tmp347 = modelica_integer_to_modelica_string_format(data->simulationInfo->integerParameter[18] /* data.table.smoothness PARAM */, (modelica_string) mmc_strings_len1[100]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp346),tmp347);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Blocks/Sources.mo",2150,5,2152,61,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\ndata.table.smoothness >= Modelica.Blocks.Types.Smoothness.LinearSegments and data.table.smoothness <= Modelica.Blocks.Types.Smoothness.MonotoneContinuousDerivative2", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp348 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1161
type: ALGORITHM

  assert(data.table.nout >= 1, "Variable violating min constraint: 1 <= data.table.nout, has value: " + String(data.table.nout, "d"));
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1161(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1161};
  modelica_boolean tmp349;
  static const MMC_DEFSTRINGLIT(tmp350,68,"Variable violating min constraint: 1 <= data.table.nout, has value: ");
  modelica_string tmp351;
  static int tmp352 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp352)
  {
    tmp349 = GreaterEq(data->simulationInfo->integerParameter[17] /* data.table.nout PARAM */,((modelica_integer) 1));
    if(!tmp349)
    {
      tmp351 = modelica_integer_to_modelica_string_format(data->simulationInfo->integerParameter[17] /* data.table.nout PARAM */, (modelica_string) mmc_strings_len1[100]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp350),tmp351);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Blocks/Interfaces.mo",313,5,313,58,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\ndata.table.nout >= 1", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp352 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1162
type: ALGORITHM

  assert(wea.date.dow0 >= 1 and wea.date.dow0 <= 7, "Variable violating min/max constraint: 1 <= wea.date.dow0 <= 7, has value: " + String(wea.date.dow0, "d"));
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1162(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1162};
  modelica_boolean tmp353;
  modelica_boolean tmp354;
  static const MMC_DEFSTRINGLIT(tmp355,75,"Variable violating min/max constraint: 1 <= wea.date.dow0 <= 7, has value: ");
  modelica_string tmp356;
  static int tmp357 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp357)
  {
    tmp353 = GreaterEq(data->simulationInfo->integerParameter[79] /* wea.date.dow0 PARAM */,((modelica_integer) 1));
    tmp354 = LessEq(data->simulationInfo->integerParameter[79] /* wea.date.dow0 PARAM */,((modelica_integer) 7));
    if(!(tmp353 && tmp354))
    {
      tmp356 = modelica_integer_to_modelica_string_format(data->simulationInfo->integerParameter[79] /* wea.date.dow0 PARAM */, (modelica_string) mmc_strings_len1[100]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp355),tmp356);
      {
        FILE_INFO info = {"/home/cparrado/.openmodelica/libraries/SolarTherm/Models/Sources/Date/SimpleDate.mo",5,2,5,58,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nwea.date.dow0 >= 1 and wea.date.dow0 <= 7", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp357 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1163
type: ALGORITHM

  assert(wea.wtab.smoothness >= Modelica.Blocks.Types.Smoothness.LinearSegments and wea.wtab.smoothness <= Modelica.Blocks.Types.Smoothness.MonotoneContinuousDerivative2, "Variable violating min/max constraint: Modelica.Blocks.Types.Smoothness.LinearSegments <= wea.wtab.smoothness <= Modelica.Blocks.Types.Smoothness.MonotoneContinuousDerivative2, has value: " + String(wea.wtab.smoothness, "d"));
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1163(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1163};
  modelica_boolean tmp358;
  modelica_boolean tmp359;
  static const MMC_DEFSTRINGLIT(tmp360,188,"Variable violating min/max constraint: Modelica.Blocks.Types.Smoothness.LinearSegments <= wea.wtab.smoothness <= Modelica.Blocks.Types.Smoothness.MonotoneContinuousDerivative2, has value: ");
  modelica_string tmp361;
  static int tmp362 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp362)
  {
    tmp358 = GreaterEq(data->simulationInfo->integerParameter[90] /* wea.wtab.smoothness PARAM */,1);
    tmp359 = LessEq(data->simulationInfo->integerParameter[90] /* wea.wtab.smoothness PARAM */,5);
    if(!(tmp358 && tmp359))
    {
      tmp361 = modelica_integer_to_modelica_string_format(data->simulationInfo->integerParameter[90] /* wea.wtab.smoothness PARAM */, (modelica_string) mmc_strings_len1[100]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp360),tmp361);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Blocks/Tables.mo",29,5,31,61,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nwea.wtab.smoothness >= Modelica.Blocks.Types.Smoothness.LinearSegments and wea.wtab.smoothness <= Modelica.Blocks.Types.Smoothness.MonotoneContinuousDerivative2", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp362 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1164
type: ALGORITHM

  assert(par_T_amb_des >= 0.0, "Variable violating min constraint: 0.0 <= par_T_amb_des, has value: " + String(par_T_amb_des, "g"));
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1164(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1164};
  modelica_boolean tmp363;
  static const MMC_DEFSTRINGLIT(tmp364,68,"Variable violating min constraint: 0.0 <= par_T_amb_des, has value: ");
  modelica_string tmp365;
  static int tmp366 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp366)
  {
    tmp363 = GreaterEq(data->simulationInfo->realParameter[177] /* par_T_amb_des PARAM */,0.0);
    if(!tmp363)
    {
      tmp365 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[177] /* par_T_amb_des PARAM */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp364),tmp365);
      {
        FILE_INFO info = {"/home/cparrado/.openmodelica/libraries/SolarTherm/Systems/Reference_1.mo",128,2,128,94,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\npar_T_amb_des >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp366 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1165
type: ALGORITHM

  assert(tnk_T_amb_des >= 0.0, "Variable violating min constraint: 0.0 <= tnk_T_amb_des, has value: " + String(tnk_T_amb_des, "g"));
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1165(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1165};
  modelica_boolean tmp367;
  static const MMC_DEFSTRINGLIT(tmp368,68,"Variable violating min constraint: 0.0 <= tnk_T_amb_des, has value: ");
  modelica_string tmp369;
  static int tmp370 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp370)
  {
    tmp367 = GreaterEq(data->simulationInfo->realParameter[274] /* tnk_T_amb_des PARAM */,0.0);
    if(!tmp367)
    {
      tmp369 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[274] /* tnk_T_amb_des PARAM */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp368),tmp369);
      {
        FILE_INFO info = {"/home/cparrado/.openmodelica/libraries/SolarTherm/Systems/Reference_1.mo",94,2,94,87,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\ntnk_T_amb_des >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp370 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1166
type: ALGORITHM

  assert(state_hot_set.p >= 0.0 and state_hot_set.p <= 100000000.0, "Variable violating min/max constraint: 0.0 <= state_hot_set.p <= 100000000.0, has value: " + String(state_hot_set.p, "g"));
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1166(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1166};
  modelica_boolean tmp371;
  modelica_boolean tmp372;
  static const MMC_DEFSTRINGLIT(tmp373,89,"Variable violating min/max constraint: 0.0 <= state_hot_set.p <= 100000000.0, has value: ");
  modelica_string tmp374;
  static int tmp375 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp375)
  {
    tmp371 = GreaterEq(data->simulationInfo->realParameter[246] /* state_hot_set.p PARAM */,0.0);
    tmp372 = LessEq(data->simulationInfo->realParameter[246] /* state_hot_set.p PARAM */,100000000.0);
    if(!(tmp371 && tmp372))
    {
      tmp374 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[246] /* state_hot_set.p PARAM */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp373),tmp374);
      {
        FILE_INFO info = {"/home/cparrado/.openmodelica/libraries/SolarTherm/Media/MoltenSalt/MoltenSalt_ph/package.mo",69,3,69,51,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nstate_hot_set.p >= 0.0 and state_hot_set.p <= 100000000.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp375 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1167
type: ALGORITHM

  assert(state_cold_set.p >= 0.0 and state_cold_set.p <= 100000000.0, "Variable violating min/max constraint: 0.0 <= state_cold_set.p <= 100000000.0, has value: " + String(state_cold_set.p, "g"));
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1167(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1167};
  modelica_boolean tmp376;
  modelica_boolean tmp377;
  static const MMC_DEFSTRINGLIT(tmp378,90,"Variable violating min/max constraint: 0.0 <= state_cold_set.p <= 100000000.0, has value: ");
  modelica_string tmp379;
  static int tmp380 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp380)
  {
    tmp376 = GreaterEq(data->simulationInfo->realParameter[244] /* state_cold_set.p PARAM */,0.0);
    tmp377 = LessEq(data->simulationInfo->realParameter[244] /* state_cold_set.p PARAM */,100000000.0);
    if(!(tmp376 && tmp377))
    {
      tmp379 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[244] /* state_cold_set.p PARAM */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp378),tmp379);
      {
        FILE_INFO info = {"/home/cparrado/.openmodelica/libraries/SolarTherm/Media/MoltenSalt/MoltenSalt_ph/package.mo",69,3,69,51,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nstate_cold_set.p >= 0.0 and state_cold_set.p <= 100000000.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp380 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1168
type: ALGORITHM

  assert(T_cold_set >= 0.0, "Variable violating min constraint: 0.0 <= T_cold_set, has value: " + String(T_cold_set, "g"));
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1168(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1168};
  modelica_boolean tmp381;
  static const MMC_DEFSTRINGLIT(tmp382,65,"Variable violating min constraint: 0.0 <= T_cold_set, has value: ");
  modelica_string tmp383;
  static int tmp384 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp384)
  {
    tmp381 = GreaterEq(data->simulationInfo->realParameter[35] /* T_cold_set PARAM */,0.0);
    if(!tmp381)
    {
      tmp383 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[35] /* T_cold_set PARAM */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp382),tmp383);
      {
        FILE_INFO info = {"/home/cparrado/.openmodelica/libraries/SolarTherm/Systems/Reference_1.mo",81,2,81,88,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nT_cold_set >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp384 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1169
type: ALGORITHM

  assert(rec_T_amb_des >= 0.0, "Variable violating min constraint: 0.0 <= rec_T_amb_des, has value: " + String(rec_T_amb_des, "g"));
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1169(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1169};
  modelica_boolean tmp385;
  static const MMC_DEFSTRINGLIT(tmp386,68,"Variable violating min constraint: 0.0 <= rec_T_amb_des, has value: ");
  modelica_string tmp387;
  static int tmp388 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp388)
  {
    tmp385 = GreaterEq(data->simulationInfo->realParameter[222] /* rec_T_amb_des PARAM */,0.0);
    if(!tmp385)
    {
      tmp387 = modelica_real_to_modelica_string_format(data->simulationInfo->realParameter[222] /* rec_T_amb_des PARAM */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp386),tmp387);
      {
        FILE_INFO info = {"/home/cparrado/.openmodelica/libraries/SolarTherm/Systems/Reference_1.mo",69,2,69,87,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nrec_T_amb_des >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp388 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1170
type: ALGORITHM

  assert(angles >= SolarTherm.Types.Solar_angles.elo_hra and angles <= SolarTherm.Types.Solar_angles.zen_azi, "Variable violating min/max constraint: SolarTherm.Types.Solar_angles.elo_hra <= angles <= SolarTherm.Types.Solar_angles.zen_azi, has value: " + String(angles, "d"));
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1170(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1170};
  modelica_boolean tmp389;
  modelica_boolean tmp390;
  static const MMC_DEFSTRINGLIT(tmp391,140,"Variable violating min/max constraint: SolarTherm.Types.Solar_angles.elo_hra <= angles <= SolarTherm.Types.Solar_angles.zen_azi, has value: ");
  modelica_string tmp392;
  static int tmp393 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp393)
  {
    tmp389 = GreaterEq(data->simulationInfo->integerParameter[1] /* angles PARAM */,1);
    tmp390 = LessEq(data->simulationInfo->integerParameter[1] /* angles PARAM */,4);
    if(!(tmp389 && tmp390))
    {
      tmp392 = modelica_integer_to_modelica_string_format(data->simulationInfo->integerParameter[1] /* angles PARAM */, (modelica_string) mmc_strings_len1[100]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp391),tmp392);
      {
        FILE_INFO info = {"/home/cparrado/.openmodelica/libraries/SolarTherm/Systems/Reference_1.mo",40,2,40,93,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nangles >= SolarTherm.Types.Solar_angles.elo_hra and angles <= SolarTherm.Types.Solar_angles.zen_azi", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp393 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1171
type: ALGORITHM

  assert(currency >= SolarTherm.Types.Currency.AUD and currency <= SolarTherm.Types.Currency.USD, "Variable violating min/max constraint: SolarTherm.Types.Currency.AUD <= currency <= SolarTherm.Types.Currency.USD, has value: " + String(currency, "d"));
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_1171(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1171};
  modelica_boolean tmp394;
  modelica_boolean tmp395;
  static const MMC_DEFSTRINGLIT(tmp396,126,"Variable violating min/max constraint: SolarTherm.Types.Currency.AUD <= currency <= SolarTherm.Types.Currency.USD, has value: ");
  modelica_string tmp397;
  static int tmp398 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp398)
  {
    tmp394 = GreaterEq(data->simulationInfo->integerParameter[5] /* currency PARAM */,1);
    tmp395 = LessEq(data->simulationInfo->integerParameter[5] /* currency PARAM */,2);
    if(!(tmp394 && tmp395))
    {
      tmp397 = modelica_integer_to_modelica_string_format(data->simulationInfo->integerParameter[5] /* currency PARAM */, (modelica_string) mmc_strings_len1[100]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp396),tmp397);
      {
        FILE_INFO info = {"/home/cparrado/.openmodelica/libraries/SolarTherm/Systems/Reference_1.mo",23,2,23,78,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\ncurrency >= SolarTherm.Types.Currency.AUD and currency <= SolarTherm.Types.Currency.USD", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp398 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 750
type: ALGORITHM

  assert(false, "Nominal variable violating min/max constraint: 573.15 <= tankHot.T <= 873.15, has value: " + String(300.0, "g"));
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_750(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,750};
  static const MMC_DEFSTRINGLIT(tmp399,89,"Nominal variable violating min/max constraint: 573.15 <= tankHot.T <= 873.15, has value: ");
  modelica_string tmp400;
  static int tmp401 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp401)
  {
    if(!0)
    {
      tmp400 = modelica_real_to_modelica_string_format(300.0, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp399),tmp400);
      {
        FILE_INFO info = {"/home/cparrado/.openmodelica/libraries/SolarTherm/Models/Storage/Tank/Tank.mo",43,3,43,52,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nfalse", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp401 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 751
type: ALGORITHM

  assert(false, "Nominal variable violating min/max constraint: 573.15 <= receiver.T_in <= 873.15, has value: " + String(300.0, "g"));
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_751(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,751};
  static const MMC_DEFSTRINGLIT(tmp402,93,"Nominal variable violating min/max constraint: 573.15 <= receiver.T_in <= 873.15, has value: ");
  modelica_string tmp403;
  static int tmp404 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp404)
  {
    if(!0)
    {
      tmp403 = modelica_real_to_modelica_string_format(300.0, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp402),tmp403);
      {
        FILE_INFO info = {"/home/cparrado/.openmodelica/libraries/SolarTherm/Models/CSP/CRS/Receivers/ReceiverSimple.mo",16,3,16,74,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nfalse", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp404 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 752
type: ALGORITHM

  assert(false, "Nominal variable violating min/max constraint: 573.15 <= tankCold.medium.T <= 873.15, has value: " + String(300.0, "g"));
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_752(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,752};
  static const MMC_DEFSTRINGLIT(tmp405,97,"Nominal variable violating min/max constraint: 573.15 <= tankCold.medium.T <= 873.15, has value: ");
  modelica_string tmp406;
  static int tmp407 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp407)
  {
    if(!0)
    {
      tmp406 = modelica_real_to_modelica_string_format(300.0, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp405),tmp406);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Media/package.mo",5020,7,5020,44,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nfalse", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp407 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 753
type: ALGORITHM

  assert(false, "Nominal variable violating min/max constraint: 573.15 <= tankHot.medium.T <= 873.15, has value: " + String(300.0, "g"));
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_753(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,753};
  static const MMC_DEFSTRINGLIT(tmp408,96,"Nominal variable violating min/max constraint: 573.15 <= tankHot.medium.T <= 873.15, has value: ");
  modelica_string tmp409;
  static int tmp410 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp410)
  {
    if(!0)
    {
      tmp409 = modelica_real_to_modelica_string_format(300.0, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp408),tmp409);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Media/package.mo",5020,7,5020,44,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nfalse", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp410 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 754
type: ALGORITHM

  assert(false, "Nominal variable violating min/max constraint: 573.15 <= receiver.medium.T <= 873.15, has value: " + String(300.0, "g"));
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_754(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,754};
  static const MMC_DEFSTRINGLIT(tmp411,97,"Nominal variable violating min/max constraint: 573.15 <= receiver.medium.T <= 873.15, has value: ");
  modelica_string tmp412;
  static int tmp413 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp413)
  {
    if(!0)
    {
      tmp412 = modelica_real_to_modelica_string_format(300.0, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp411),tmp412);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Media/package.mo",5020,7,5020,44,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nfalse", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp413 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 755
type: ALGORITHM

  assert(false, "Nominal variable violating min/max constraint: 573.15 <= tankCold.T <= 873.15, has value: " + String(300.0, "g"));
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_755(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,755};
  static const MMC_DEFSTRINGLIT(tmp414,90,"Nominal variable violating min/max constraint: 573.15 <= tankCold.T <= 873.15, has value: ");
  modelica_string tmp415;
  static int tmp416 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp416)
  {
    if(!0)
    {
      tmp415 = modelica_real_to_modelica_string_format(300.0, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp414),tmp415);
      {
        FILE_INFO info = {"/home/cparrado/.openmodelica/libraries/SolarTherm/Models/Storage/Tank/Tank.mo",43,3,43,52,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nfalse", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp416 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 756
type: ALGORITHM

  assert(false, "Nominal variable violating min/max constraint: 573.15 <= powerBlock.T_in <= 873.15, has value: " + String(300.0, "g"));
*/
OMC_DISABLE_OPT
static void Reference_1_eqFunction_756(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,756};
  static const MMC_DEFSTRINGLIT(tmp417,95,"Nominal variable violating min/max constraint: 573.15 <= powerBlock.T_in <= 873.15, has value: ");
  modelica_string tmp418;
  static int tmp419 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp419)
  {
    if(!0)
    {
      tmp418 = modelica_real_to_modelica_string_format(300.0, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp417),tmp418);
      {
        FILE_INFO info = {"/home/cparrado/.openmodelica/libraries/SolarTherm/Models/PowerBlocks/PowerBlockModel.mo",14,3,14,51,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nfalse", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp419 = 1;
    }
  }
  TRACE_POP
}
OMC_DISABLE_OPT
void Reference_1_updateBoundParameters_0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  Reference_1_eqFunction_757(data, threadData);
  Reference_1_eqFunction_758(data, threadData);
  Reference_1_eqFunction_759(data, threadData);
  Reference_1_eqFunction_760(data, threadData);
  Reference_1_eqFunction_771(data, threadData);
  Reference_1_eqFunction_772(data, threadData);
  Reference_1_eqFunction_773(data, threadData);
  Reference_1_eqFunction_774(data, threadData);
  Reference_1_eqFunction_788(data, threadData);
  Reference_1_eqFunction_789(data, threadData);
  Reference_1_eqFunction_790(data, threadData);
  Reference_1_eqFunction_791(data, threadData);
  Reference_1_eqFunction_792(data, threadData);
  Reference_1_eqFunction_793(data, threadData);
  Reference_1_eqFunction_794(data, threadData);
  Reference_1_eqFunction_795(data, threadData);
  Reference_1_eqFunction_796(data, threadData);
  Reference_1_eqFunction_797(data, threadData);
  Reference_1_eqFunction_798(data, threadData);
  Reference_1_eqFunction_799(data, threadData);
  Reference_1_eqFunction_800(data, threadData);
  Reference_1_eqFunction_801(data, threadData);
  Reference_1_eqFunction_802(data, threadData);
  Reference_1_eqFunction_803(data, threadData);
  Reference_1_eqFunction_804(data, threadData);
  Reference_1_eqFunction_805(data, threadData);
  Reference_1_eqFunction_806(data, threadData);
  Reference_1_eqFunction_807(data, threadData);
  Reference_1_eqFunction_808(data, threadData);
  Reference_1_eqFunction_809(data, threadData);
  Reference_1_eqFunction_810(data, threadData);
  Reference_1_eqFunction_811(data, threadData);
  Reference_1_eqFunction_812(data, threadData);
  Reference_1_eqFunction_813(data, threadData);
  Reference_1_eqFunction_814(data, threadData);
  Reference_1_eqFunction_815(data, threadData);
  Reference_1_eqFunction_816(data, threadData);
  Reference_1_eqFunction_817(data, threadData);
  Reference_1_eqFunction_818(data, threadData);
  Reference_1_eqFunction_819(data, threadData);
  Reference_1_eqFunction_820(data, threadData);
  Reference_1_eqFunction_821(data, threadData);
  Reference_1_eqFunction_822(data, threadData);
  Reference_1_eqFunction_823(data, threadData);
  Reference_1_eqFunction_824(data, threadData);
  Reference_1_eqFunction_825(data, threadData);
  Reference_1_eqFunction_831(data, threadData);
  Reference_1_eqFunction_832(data, threadData);
  Reference_1_eqFunction_833(data, threadData);
  Reference_1_eqFunction_834(data, threadData);
  Reference_1_eqFunction_835(data, threadData);
  Reference_1_eqFunction_843(data, threadData);
  Reference_1_eqFunction_845(data, threadData);
  Reference_1_eqFunction_848(data, threadData);
  Reference_1_eqFunction_849(data, threadData);
  Reference_1_eqFunction_850(data, threadData);
  Reference_1_eqFunction_851(data, threadData);
  Reference_1_eqFunction_852(data, threadData);
  Reference_1_eqFunction_853(data, threadData);
  Reference_1_eqFunction_854(data, threadData);
  Reference_1_eqFunction_855(data, threadData);
  Reference_1_eqFunction_856(data, threadData);
  Reference_1_eqFunction_857(data, threadData);
  Reference_1_eqFunction_858(data, threadData);
  Reference_1_eqFunction_860(data, threadData);
  Reference_1_eqFunction_862(data, threadData);
  Reference_1_eqFunction_863(data, threadData);
  Reference_1_eqFunction_864(data, threadData);
  Reference_1_eqFunction_865(data, threadData);
  Reference_1_eqFunction_866(data, threadData);
  Reference_1_eqFunction_867(data, threadData);
  Reference_1_eqFunction_868(data, threadData);
  Reference_1_eqFunction_869(data, threadData);
  Reference_1_eqFunction_870(data, threadData);
  Reference_1_eqFunction_871(data, threadData);
  Reference_1_eqFunction_872(data, threadData);
  Reference_1_eqFunction_876(data, threadData);
  Reference_1_eqFunction_877(data, threadData);
  Reference_1_eqFunction_878(data, threadData);
  Reference_1_eqFunction_879(data, threadData);
  Reference_1_eqFunction_880(data, threadData);
  Reference_1_eqFunction_881(data, threadData);
  Reference_1_eqFunction_882(data, threadData);
  Reference_1_eqFunction_883(data, threadData);
  Reference_1_eqFunction_884(data, threadData);
  Reference_1_eqFunction_885(data, threadData);
  Reference_1_eqFunction_886(data, threadData);
  Reference_1_eqFunction_887(data, threadData);
  Reference_1_eqFunction_888(data, threadData);
  Reference_1_eqFunction_889(data, threadData);
  Reference_1_eqFunction_890(data, threadData);
  Reference_1_eqFunction_891(data, threadData);
  Reference_1_eqFunction_892(data, threadData);
  Reference_1_eqFunction_893(data, threadData);
  Reference_1_eqFunction_894(data, threadData);
  Reference_1_eqFunction_898(data, threadData);
  Reference_1_eqFunction_900(data, threadData);
  Reference_1_eqFunction_901(data, threadData);
  Reference_1_eqFunction_902(data, threadData);
  Reference_1_eqFunction_903(data, threadData);
  Reference_1_eqFunction_904(data, threadData);
  Reference_1_eqFunction_905(data, threadData);
  Reference_1_eqFunction_906(data, threadData);
  Reference_1_eqFunction_907(data, threadData);
  Reference_1_eqFunction_908(data, threadData);
  Reference_1_eqFunction_909(data, threadData);
  Reference_1_eqFunction_910(data, threadData);
  Reference_1_eqFunction_911(data, threadData);
  Reference_1_eqFunction_912(data, threadData);
  Reference_1_eqFunction_913(data, threadData);
  Reference_1_eqFunction_914(data, threadData);
  Reference_1_eqFunction_915(data, threadData);
  Reference_1_eqFunction_916(data, threadData);
  Reference_1_eqFunction_917(data, threadData);
  Reference_1_eqFunction_918(data, threadData);
  Reference_1_eqFunction_919(data, threadData);
  Reference_1_eqFunction_920(data, threadData);
  Reference_1_eqFunction_921(data, threadData);
  Reference_1_eqFunction_922(data, threadData);
  Reference_1_eqFunction_923(data, threadData);
  Reference_1_eqFunction_926(data, threadData);
  Reference_1_eqFunction_927(data, threadData);
  Reference_1_eqFunction_928(data, threadData);
  Reference_1_eqFunction_929(data, threadData);
  Reference_1_eqFunction_931(data, threadData);
  Reference_1_eqFunction_935(data, threadData);
  Reference_1_eqFunction_936(data, threadData);
  Reference_1_eqFunction_937(data, threadData);
  Reference_1_eqFunction_938(data, threadData);
  Reference_1_eqFunction_941(data, threadData);
  Reference_1_eqFunction_942(data, threadData);
  Reference_1_eqFunction_943(data, threadData);
  Reference_1_eqFunction_944(data, threadData);
  Reference_1_eqFunction_946(data, threadData);
  Reference_1_eqFunction_952(data, threadData);
  Reference_1_eqFunction_954(data, threadData);
  Reference_1_eqFunction_955(data, threadData);
  Reference_1_eqFunction_956(data, threadData);
  Reference_1_eqFunction_957(data, threadData);
  Reference_1_eqFunction_958(data, threadData);
  Reference_1_eqFunction_959(data, threadData);
  Reference_1_eqFunction_960(data, threadData);
  Reference_1_eqFunction_961(data, threadData);
  Reference_1_eqFunction_962(data, threadData);
  Reference_1_eqFunction_963(data, threadData);
  Reference_1_eqFunction_964(data, threadData);
  Reference_1_eqFunction_968(data, threadData);
  Reference_1_eqFunction_969(data, threadData);
  Reference_1_eqFunction_970(data, threadData);
  Reference_1_eqFunction_971(data, threadData);
  Reference_1_eqFunction_972(data, threadData);
  Reference_1_eqFunction_974(data, threadData);
  Reference_1_eqFunction_975(data, threadData);
  Reference_1_eqFunction_976(data, threadData);
  Reference_1_eqFunction_977(data, threadData);
  Reference_1_eqFunction_982(data, threadData);
  Reference_1_eqFunction_983(data, threadData);
  Reference_1_eqFunction_984(data, threadData);
  Reference_1_eqFunction_985(data, threadData);
  Reference_1_eqFunction_986(data, threadData);
  Reference_1_eqFunction_987(data, threadData);
  Reference_1_eqFunction_988(data, threadData);
  Reference_1_eqFunction_989(data, threadData);
  Reference_1_eqFunction_993(data, threadData);
  Reference_1_eqFunction_994(data, threadData);
  Reference_1_eqFunction_995(data, threadData);
  Reference_1_eqFunction_996(data, threadData);
  Reference_1_eqFunction_997(data, threadData);
  Reference_1_eqFunction_998(data, threadData);
  Reference_1_eqFunction_999(data, threadData);
  Reference_1_eqFunction_1000(data, threadData);
  Reference_1_eqFunction_1001(data, threadData);
  Reference_1_eqFunction_1002(data, threadData);
  Reference_1_eqFunction_1003(data, threadData);
  Reference_1_eqFunction_1005(data, threadData);
  Reference_1_eqFunction_1006(data, threadData);
  Reference_1_eqFunction_1007(data, threadData);
  Reference_1_eqFunction_1008(data, threadData);
  Reference_1_eqFunction_1009(data, threadData);
  Reference_1_eqFunction_1010(data, threadData);
  Reference_1_eqFunction_1011(data, threadData);
  Reference_1_eqFunction_1012(data, threadData);
  Reference_1_eqFunction_1013(data, threadData);
  Reference_1_eqFunction_1014(data, threadData);
  Reference_1_eqFunction_1015(data, threadData);
  Reference_1_eqFunction_1016(data, threadData);
  Reference_1_eqFunction_1017(data, threadData);
  Reference_1_eqFunction_1018(data, threadData);
  Reference_1_eqFunction_1026(data, threadData);
  Reference_1_eqFunction_1027(data, threadData);
  Reference_1_eqFunction_1028(data, threadData);
  Reference_1_eqFunction_1029(data, threadData);
  Reference_1_eqFunction_1030(data, threadData);
  Reference_1_eqFunction_1031(data, threadData);
  Reference_1_eqFunction_1032(data, threadData);
  Reference_1_eqFunction_1033(data, threadData);
  Reference_1_eqFunction_1034(data, threadData);
  Reference_1_eqFunction_1035(data, threadData);
  Reference_1_eqFunction_1040(data, threadData);
  Reference_1_eqFunction_1041(data, threadData);
  Reference_1_eqFunction_1042(data, threadData);
  Reference_1_eqFunction_1043(data, threadData);
  Reference_1_eqFunction_1044(data, threadData);
  Reference_1_eqFunction_1045(data, threadData);
  Reference_1_eqFunction_1046(data, threadData);
  Reference_1_eqFunction_1047(data, threadData);
  Reference_1_eqFunction_1048(data, threadData);
  Reference_1_eqFunction_1049(data, threadData);
  Reference_1_eqFunction_1050(data, threadData);
  Reference_1_eqFunction_1051(data, threadData);
  Reference_1_eqFunction_1052(data, threadData);
  Reference_1_eqFunction_1053(data, threadData);
  Reference_1_eqFunction_1054(data, threadData);
  Reference_1_eqFunction_1055(data, threadData);
  Reference_1_eqFunction_1056(data, threadData);
  Reference_1_eqFunction_1057(data, threadData);
  Reference_1_eqFunction_1058(data, threadData);
  Reference_1_eqFunction_1059(data, threadData);
  Reference_1_eqFunction_1065(data, threadData);
  Reference_1_eqFunction_221(data, threadData);
  Reference_1_eqFunction_220(data, threadData);
  Reference_1_eqFunction_219(data, threadData);
  Reference_1_eqFunction_218(data, threadData);
  Reference_1_eqFunction_217(data, threadData);
  Reference_1_eqFunction_16(data, threadData);
  Reference_1_eqFunction_216(data, threadData);
  Reference_1_eqFunction_215(data, threadData);
  Reference_1_eqFunction_214(data, threadData);
  Reference_1_eqFunction_213(data, threadData);
  Reference_1_eqFunction_15(data, threadData);
  Reference_1_eqFunction_12(data, threadData);
  Reference_1_eqFunction_11(data, threadData);
  Reference_1_eqFunction_10(data, threadData);
  Reference_1_eqFunction_9(data, threadData);
  Reference_1_eqFunction_8(data, threadData);
  Reference_1_eqFunction_7(data, threadData);
  Reference_1_eqFunction_6(data, threadData);
  Reference_1_eqFunction_5(data, threadData);
  Reference_1_eqFunction_4(data, threadData);
  Reference_1_eqFunction_1088(data, threadData);
  Reference_1_eqFunction_1089(data, threadData);
  Reference_1_eqFunction_1090(data, threadData);
  Reference_1_eqFunction_1091(data, threadData);
  Reference_1_eqFunction_1092(data, threadData);
  Reference_1_eqFunction_1093(data, threadData);
  Reference_1_eqFunction_1094(data, threadData);
  Reference_1_eqFunction_1095(data, threadData);
  Reference_1_eqFunction_1096(data, threadData);
  Reference_1_eqFunction_1097(data, threadData);
  Reference_1_eqFunction_1098(data, threadData);
  Reference_1_eqFunction_1099(data, threadData);
  Reference_1_eqFunction_1100(data, threadData);
  Reference_1_eqFunction_1101(data, threadData);
  Reference_1_eqFunction_1102(data, threadData);
  Reference_1_eqFunction_1103(data, threadData);
  Reference_1_eqFunction_1104(data, threadData);
  Reference_1_eqFunction_1105(data, threadData);
  Reference_1_eqFunction_1106(data, threadData);
  Reference_1_eqFunction_1107(data, threadData);
  Reference_1_eqFunction_1108(data, threadData);
  Reference_1_eqFunction_1109(data, threadData);
  Reference_1_eqFunction_1110(data, threadData);
  Reference_1_eqFunction_1111(data, threadData);
  Reference_1_eqFunction_1112(data, threadData);
  Reference_1_eqFunction_1113(data, threadData);
  Reference_1_eqFunction_1114(data, threadData);
  Reference_1_eqFunction_1115(data, threadData);
  Reference_1_eqFunction_1116(data, threadData);
  Reference_1_eqFunction_1117(data, threadData);
  Reference_1_eqFunction_1118(data, threadData);
  Reference_1_eqFunction_1119(data, threadData);
  Reference_1_eqFunction_1120(data, threadData);
  Reference_1_eqFunction_1121(data, threadData);
  Reference_1_eqFunction_1122(data, threadData);
  Reference_1_eqFunction_1123(data, threadData);
  Reference_1_eqFunction_1124(data, threadData);
  Reference_1_eqFunction_1125(data, threadData);
  Reference_1_eqFunction_1126(data, threadData);
  Reference_1_eqFunction_1127(data, threadData);
  Reference_1_eqFunction_1128(data, threadData);
  Reference_1_eqFunction_1129(data, threadData);
  Reference_1_eqFunction_1130(data, threadData);
  Reference_1_eqFunction_1131(data, threadData);
  Reference_1_eqFunction_1132(data, threadData);
  Reference_1_eqFunction_1133(data, threadData);
  Reference_1_eqFunction_1134(data, threadData);
  Reference_1_eqFunction_1135(data, threadData);
  Reference_1_eqFunction_1136(data, threadData);
  Reference_1_eqFunction_1137(data, threadData);
  Reference_1_eqFunction_1138(data, threadData);
  Reference_1_eqFunction_1139(data, threadData);
  Reference_1_eqFunction_1140(data, threadData);
  Reference_1_eqFunction_1141(data, threadData);
  Reference_1_eqFunction_1142(data, threadData);
  Reference_1_eqFunction_1143(data, threadData);
  Reference_1_eqFunction_1144(data, threadData);
  Reference_1_eqFunction_1145(data, threadData);
  Reference_1_eqFunction_1146(data, threadData);
  Reference_1_eqFunction_1147(data, threadData);
  Reference_1_eqFunction_1148(data, threadData);
  Reference_1_eqFunction_1149(data, threadData);
  Reference_1_eqFunction_1150(data, threadData);
  Reference_1_eqFunction_1151(data, threadData);
  Reference_1_eqFunction_1152(data, threadData);
  Reference_1_eqFunction_1153(data, threadData);
  Reference_1_eqFunction_1154(data, threadData);
  Reference_1_eqFunction_1155(data, threadData);
  Reference_1_eqFunction_1156(data, threadData);
  Reference_1_eqFunction_1157(data, threadData);
  Reference_1_eqFunction_1158(data, threadData);
  Reference_1_eqFunction_1159(data, threadData);
  Reference_1_eqFunction_1160(data, threadData);
  Reference_1_eqFunction_1161(data, threadData);
  Reference_1_eqFunction_1162(data, threadData);
  Reference_1_eqFunction_1163(data, threadData);
  Reference_1_eqFunction_1164(data, threadData);
  Reference_1_eqFunction_1165(data, threadData);
  Reference_1_eqFunction_1166(data, threadData);
  Reference_1_eqFunction_1167(data, threadData);
  Reference_1_eqFunction_1168(data, threadData);
  Reference_1_eqFunction_1169(data, threadData);
  Reference_1_eqFunction_1170(data, threadData);
  Reference_1_eqFunction_1171(data, threadData);
  Reference_1_eqFunction_750(data, threadData);
  Reference_1_eqFunction_751(data, threadData);
  Reference_1_eqFunction_752(data, threadData);
  Reference_1_eqFunction_753(data, threadData);
  Reference_1_eqFunction_754(data, threadData);
  Reference_1_eqFunction_755(data, threadData);
  Reference_1_eqFunction_756(data, threadData);
  TRACE_POP
}
OMC_DISABLE_OPT
int Reference_1_updateBoundParameters(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  data->simulationInfo->integerParameter[6] /* data.table.columns[1] PARAM */ = ((modelica_integer) 2);
  data->modelData->integerParameterData[6].time_unvarying = 1;
  data->simulationInfo->integerParameter[7] /* data.table.columns[2] PARAM */ = ((modelica_integer) 3);
  data->modelData->integerParameterData[7].time_unvarying = 1;
  data->simulationInfo->integerParameter[8] /* data.table.columns[3] PARAM */ = ((modelica_integer) 4);
  data->modelData->integerParameterData[8].time_unvarying = 1;
  data->simulationInfo->integerParameter[9] /* data.table.columns[4] PARAM */ = ((modelica_integer) 5);
  data->modelData->integerParameterData[9].time_unvarying = 1;
  data->simulationInfo->integerParameter[10] /* data.table.columns[5] PARAM */ = ((modelica_integer) 6);
  data->modelData->integerParameterData[10].time_unvarying = 1;
  data->simulationInfo->integerParameter[11] /* data.table.columns[6] PARAM */ = ((modelica_integer) 7);
  data->modelData->integerParameterData[11].time_unvarying = 1;
  data->simulationInfo->integerParameter[12] /* data.table.columns[7] PARAM */ = ((modelica_integer) 8);
  data->modelData->integerParameterData[12].time_unvarying = 1;
  data->simulationInfo->integerParameter[13] /* data.table.columns[8] PARAM */ = ((modelica_integer) 9);
  data->modelData->integerParameterData[13].time_unvarying = 1;
  data->simulationInfo->integerParameter[14] /* data.table.columns[9] PARAM */ = ((modelica_integer) 10);
  data->modelData->integerParameterData[14].time_unvarying = 1;
  data->simulationInfo->integerParameter[15] /* data.table.columns[10] PARAM */ = ((modelica_integer) 11);
  data->modelData->integerParameterData[15].time_unvarying = 1;
  data->simulationInfo->integerParameter[17] /* data.table.nout PARAM */ = ((modelica_integer) 10);
  data->modelData->integerParameterData[17].time_unvarying = 1;
  data->simulationInfo->integerParameter[28] /* prices.nout PARAM */ = ((modelica_integer) 1);
  data->modelData->integerParameterData[28].time_unvarying = 1;
  data->simulationInfo->integerParameter[34] /* sch_fixed.daily[1].table.nout PARAM */ = ((modelica_integer) 1);
  data->modelData->integerParameterData[34].time_unvarying = 1;
  data->simulationInfo->integerParameter[61] /* sch_fixed.nweek PARAM */ = ((modelica_integer) 1);
  data->modelData->integerParameterData[61].time_unvarying = 1;
  data->simulationInfo->integerParameter[79] /* wea.date.dow0 PARAM */ = ((modelica_integer) 1);
  data->modelData->integerParameterData[79].time_unvarying = 1;
  data->simulationInfo->integerParameter[80] /* wea.wtab.columns[1] PARAM */ = ((modelica_integer) 2);
  data->modelData->integerParameterData[80].time_unvarying = 1;
  data->simulationInfo->integerParameter[81] /* wea.wtab.columns[2] PARAM */ = ((modelica_integer) 3);
  data->modelData->integerParameterData[81].time_unvarying = 1;
  data->simulationInfo->integerParameter[82] /* wea.wtab.columns[3] PARAM */ = ((modelica_integer) 4);
  data->modelData->integerParameterData[82].time_unvarying = 1;
  data->simulationInfo->integerParameter[83] /* wea.wtab.columns[4] PARAM */ = ((modelica_integer) 5);
  data->modelData->integerParameterData[83].time_unvarying = 1;
  data->simulationInfo->integerParameter[84] /* wea.wtab.columns[5] PARAM */ = ((modelica_integer) 6);
  data->modelData->integerParameterData[84].time_unvarying = 1;
  data->simulationInfo->integerParameter[85] /* wea.wtab.columns[6] PARAM */ = ((modelica_integer) 7);
  data->modelData->integerParameterData[85].time_unvarying = 1;
  data->simulationInfo->integerParameter[86] /* wea.wtab.columns[7] PARAM */ = ((modelica_integer) 8);
  data->modelData->integerParameterData[86].time_unvarying = 1;
  data->simulationInfo->integerParameter[87] /* wea.wtab.columns[8] PARAM */ = ((modelica_integer) 9);
  data->modelData->integerParameterData[87].time_unvarying = 1;
  data->simulationInfo->integerParameter[89] /* wea.wtab.n PARAM */ = ((modelica_integer) 8);
  data->modelData->integerParameterData[89].time_unvarying = 1;
  data->simulationInfo->realParameter[108] /* data.table.offset[1] PARAM */ = 0.0;
  data->modelData->realParameterData[108].time_unvarying = 1;
  data->simulationInfo->realParameter[120] /* data.table.startTime PARAM */ = 0.0;
  data->modelData->realParameterData[120].time_unvarying = 1;
  data->simulationInfo->realParameter[125] /* data.table.timeScale PARAM */ = 1.0;
  data->modelData->realParameterData[125].time_unvarying = 1;
  data->simulationInfo->realParameter[136] /* heliostatField.Q_defocus PARAM */ = 700.0;
  data->modelData->realParameterData[136].time_unvarying = 1;
  data->simulationInfo->realParameter[154] /* heliostatField.t_start PARAM */ = 3600.0;
  data->modelData->realParameterData[154].time_unvarying = 1;
  data->simulationInfo->realParameter[193] /* powerBlock.nu_eps PARAM */ = 0.1;
  data->modelData->realParameterData[193].time_unvarying = 1;
  data->simulationInfo->realParameter[197] /* powerBlock.state_in_ref.h PARAM */ = 1244355.846665;
  data->modelData->realParameterData[197].time_unvarying = 1;
  data->simulationInfo->realParameter[198] /* powerBlock.state_in_ref.p PARAM */ = 100000.0;
  data->modelData->realParameterData[198].time_unvarying = 1;
  data->simulationInfo->realParameter[199] /* powerBlock.state_out_ref.h PARAM */ = 813441.510665;
  data->modelData->realParameterData[199].time_unvarying = 1;
  data->simulationInfo->realParameter[200] /* powerBlock.state_out_ref.p PARAM */ = 100000.0;
  data->modelData->realParameterData[200].time_unvarying = 1;
  data->simulationInfo->realParameter[217] /* prices.timeScale PARAM */ = 1.0;
  data->modelData->realParameterData[217].time_unvarying = 1;
  data->simulationInfo->realParameter[229] /* receiver.T_0 PARAM */ = 563.15;
  data->modelData->realParameterData[229].time_unvarying = 1;
  data->simulationInfo->realParameter[234] /* receiver.state_0.h PARAM */ = 813441.510665;
  data->modelData->realParameterData[234].time_unvarying = 1;
  data->simulationInfo->realParameter[235] /* receiver.state_0.p PARAM */ = 100000.0;
  data->modelData->realParameterData[235].time_unvarying = 1;
  data->simulationInfo->realParameter[262] /* tankCold.p_fixed PARAM */ = 101325.0;
  data->modelData->realParameterData[262].time_unvarying = 1;
  data->simulationInfo->realParameter[272] /* tankHot.p_fixed PARAM */ = 101325.0;
  data->modelData->realParameterData[272].time_unvarying = 1;
  data->simulationInfo->booleanParameter[0] /* blk_enable_losses PARAM */ = 1;
  data->modelData->booleanParameterData[0].time_unvarying = 1;
  data->simulationInfo->booleanParameter[2] /* controlCold.PI.I.use_reset PARAM */ = 0;
  data->modelData->booleanParameterData[2].time_unvarying = 1;
  data->simulationInfo->booleanParameter[3] /* controlCold.PI.I.use_set PARAM */ = 0;
  data->modelData->booleanParameterData[3].time_unvarying = 1;
  data->simulationInfo->booleanParameter[4] /* controlCold.PI.limiter.limitsAtInit PARAM */ = 1;
  data->modelData->booleanParameterData[4].time_unvarying = 1;
  data->simulationInfo->booleanParameter[5] /* controlCold.PI.limiter.strict PARAM */ = 0;
  data->modelData->booleanParameterData[5].time_unvarying = 1;
  data->simulationInfo->booleanParameter[6] /* data.table.tableOnFile PARAM */ = 1;
  data->modelData->booleanParameterData[6].time_unvarying = 1;
  data->simulationInfo->booleanParameter[7] /* data.table.verboseExtrapolation PARAM */ = 0;
  data->modelData->booleanParameterData[7].time_unvarying = 1;
  data->simulationInfo->booleanParameter[8] /* data.table.verboseRead PARAM */ = 1;
  data->modelData->booleanParameterData[8].time_unvarying = 1;
  data->simulationInfo->booleanParameter[9] /* external_parasities PARAM */ = 1;
  data->modelData->booleanParameterData[9].time_unvarying = 1;
  data->simulationInfo->booleanParameter[10] /* fixed_field PARAM */ = 0;
  data->modelData->booleanParameterData[10].time_unvarying = 1;
  data->simulationInfo->booleanParameter[11] /* heliostatField.optical.nu_table.tableOnFile PARAM */ = 1;
  data->modelData->booleanParameterData[11].time_unvarying = 1;
  data->simulationInfo->booleanParameter[12] /* heliostatField.optical.nu_table.verboseExtrapolation PARAM */ = 0;
  data->modelData->booleanParameterData[12].time_unvarying = 1;
  data->simulationInfo->booleanParameter[14] /* heliostatField.use_defocus PARAM */ = 1;
  data->modelData->booleanParameterData[14].time_unvarying = 1;
  data->simulationInfo->booleanParameter[15] /* heliostatField.use_on PARAM */ = 1;
  data->modelData->booleanParameterData[15].time_unvarying = 1;
  data->simulationInfo->booleanParameter[16] /* heliostatField.use_wind PARAM */ = 1;
  data->modelData->booleanParameterData[16].time_unvarying = 1;
  data->simulationInfo->booleanParameter[18] /* powerBlock.enable_losses PARAM */ = 1;
  data->modelData->booleanParameterData[18].time_unvarying = 1;
  data->simulationInfo->booleanParameter[19] /* powerBlock.external_parasities PARAM */ = 1;
  data->modelData->booleanParameterData[19].time_unvarying = 1;
  data->simulationInfo->booleanParameter[20] /* prices.tableOnFile PARAM */ = 1;
  data->modelData->booleanParameterData[20].time_unvarying = 1;
  data->simulationInfo->booleanParameter[21] /* prices.verboseExtrapolation PARAM */ = 0;
  data->modelData->booleanParameterData[21].time_unvarying = 1;
  data->simulationInfo->booleanParameter[23] /* receiver.medium.preferredMediumStates PARAM */ = 0;
  data->modelData->booleanParameterData[23].time_unvarying = 1;
  data->simulationInfo->booleanParameter[24] /* receiver.medium.standardOrderComponents PARAM */ = 1;
  data->modelData->booleanParameterData[24].time_unvarying = 1;
  data->simulationInfo->booleanParameter[25] /* sch_fixed.daily[1].table.tableOnFile PARAM */ = 1;
  data->modelData->booleanParameterData[25].time_unvarying = 1;
  data->simulationInfo->booleanParameter[26] /* sch_fixed.daily[1].table.verboseExtrapolation PARAM */ = 0;
  data->modelData->booleanParameterData[26].time_unvarying = 1;
  data->simulationInfo->booleanParameter[28] /* tankCold.enable_losses PARAM */ = 1;
  data->modelData->booleanParameterData[28].time_unvarying = 1;
  data->simulationInfo->booleanParameter[29] /* tankCold.medium.preferredMediumStates PARAM */ = 0;
  data->modelData->booleanParameterData[29].time_unvarying = 1;
  data->simulationInfo->booleanParameter[30] /* tankCold.medium.standardOrderComponents PARAM */ = 1;
  data->modelData->booleanParameterData[30].time_unvarying = 1;
  data->simulationInfo->booleanParameter[31] /* tankCold.use_L PARAM */ = 1;
  data->modelData->booleanParameterData[31].time_unvarying = 1;
  data->simulationInfo->booleanParameter[32] /* tankCold.use_p_top PARAM */ = 1;
  data->modelData->booleanParameterData[32].time_unvarying = 1;
  data->simulationInfo->booleanParameter[33] /* tankHot.enable_losses PARAM */ = 1;
  data->modelData->booleanParameterData[33].time_unvarying = 1;
  data->simulationInfo->booleanParameter[34] /* tankHot.medium.preferredMediumStates PARAM */ = 0;
  data->modelData->booleanParameterData[34].time_unvarying = 1;
  data->simulationInfo->booleanParameter[35] /* tankHot.medium.standardOrderComponents PARAM */ = 1;
  data->modelData->booleanParameterData[35].time_unvarying = 1;
  data->simulationInfo->booleanParameter[36] /* tankHot.use_L PARAM */ = 1;
  data->modelData->booleanParameterData[36].time_unvarying = 1;
  data->simulationInfo->booleanParameter[37] /* tankHot.use_p_top PARAM */ = 1;
  data->modelData->booleanParameterData[37].time_unvarying = 1;
  data->simulationInfo->booleanParameter[38] /* tnk_enable_losses PARAM */ = 1;
  data->modelData->booleanParameterData[38].time_unvarying = 1;
  data->simulationInfo->booleanParameter[39] /* tnk_use_p_top PARAM */ = 1;
  data->modelData->booleanParameterData[39].time_unvarying = 1;
  data->simulationInfo->booleanParameter[40] /* use_wind PARAM */ = 1;
  data->modelData->booleanParameterData[40].time_unvarying = 1;
  data->simulationInfo->booleanParameter[42] /* wea.wtab.tableOnFile PARAM */ = 1;
  data->modelData->booleanParameterData[42].time_unvarying = 1;
  data->simulationInfo->booleanParameter[43] /* wea.wtab.verboseExtrapolation PARAM */ = 0;
  data->modelData->booleanParameterData[43].time_unvarying = 1;
  data->simulationInfo->booleanParameter[44] /* wea.wtab.verboseRead PARAM */ = 0;
  data->modelData->booleanParameterData[44].time_unvarying = 1;
  data->simulationInfo->integerParameter[1] /* angles PARAM */ = 3;
  data->modelData->integerParameterData[1].time_unvarying = 1;
  data->simulationInfo->integerParameter[2] /* controlCold.PI.I.initType PARAM */ = 4;
  data->modelData->integerParameterData[2].time_unvarying = 1;
  data->simulationInfo->integerParameter[3] /* controlCold.PI.initType PARAM */ = 4;
  data->modelData->integerParameterData[3].time_unvarying = 1;
  data->simulationInfo->integerParameter[4] /* controlCold.PI.limiter.homotopyType PARAM */ = 2;
  data->modelData->integerParameterData[4].time_unvarying = 1;
  data->simulationInfo->integerParameter[16] /* data.table.extrapolation PARAM */ = 2;
  data->modelData->integerParameterData[16].time_unvarying = 1;
  data->simulationInfo->integerParameter[18] /* data.table.smoothness PARAM */ = 2;
  data->modelData->integerParameterData[18].time_unvarying = 1;
  data->simulationInfo->integerParameter[19] /* data.table.timeEvents PARAM */ = 1;
  data->modelData->integerParameterData[19].time_unvarying = 1;
  data->simulationInfo->integerParameter[22] /* heliostatField.optical.angles PARAM */ = 3;
  data->modelData->integerParameterData[22].time_unvarying = 1;
  data->simulationInfo->integerParameter[24] /* heliostatField.optical.nu_table.smoothness PARAM */ = 2;
  data->modelData->integerParameterData[24].time_unvarying = 1;
  data->simulationInfo->integerParameter[29] /* prices.smoothness PARAM */ = 3;
  data->modelData->integerParameterData[29].time_unvarying = 1;
  data->simulationInfo->integerParameter[35] /* sch_fixed.daily[1].table.smoothness PARAM */ = 3;
  data->modelData->integerParameterData[35].time_unvarying = 1;
  data->simulationInfo->integerParameter[88] /* wea.wtab.extrapolation PARAM */ = 2;
  data->modelData->integerParameterData[88].time_unvarying = 1;
  data->simulationInfo->integerParameter[90] /* wea.wtab.smoothness PARAM */ = 2;
  data->modelData->integerParameterData[90].time_unvarying = 1;
  Reference_1_updateBoundParameters_0(data, threadData);
  TRACE_POP
  return 0;
}

#if defined(__cplusplus)
}
#endif

