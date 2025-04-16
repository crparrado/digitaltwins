/* Initialization */
#include "Reference_1_model.h"
#include "Reference_1_11mix.h"
#include "Reference_1_12jac.h"
#if defined(__cplusplus)
extern "C" {
#endif

void Reference_1_functionInitialEquations_0(DATA *data, threadData_t *threadData);

/*
equation index: 1
type: SIMPLE_ASSIGN
market.profit = $START.market.profit
*/
void Reference_1_eqFunction_1(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1};
  data->localData[0]->realVars[4] /* market.profit STATE(1) */ = data->modelData->realVarsData[4].attribute /* market.profit STATE(1) */.start;
  TRACE_POP
}

/*
equation index: 2
type: SIMPLE_ASSIGN
heliostatField.E_field = $START.heliostatField.E_field
*/
void Reference_1_eqFunction_2(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2};
  data->localData[0]->realVars[3] /* heliostatField.E_field STATE(1,heliostatField.Q_net) */ = data->modelData->realVarsData[3].attribute /* heliostatField.E_field STATE(1,heliostatField.Q_net) */.start;
  TRACE_POP
}

/*
equation index: 3
type: SIMPLE_ASSIGN
heliostatField.E_dni = $START.heliostatField.E_dni
*/
void Reference_1_eqFunction_3(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3};
  data->localData[0]->realVars[2] /* heliostatField.E_dni STATE(1) */ = data->modelData->realVarsData[2].attribute /* heliostatField.E_dni STATE(1) */.start;
  TRACE_POP
}

/*
equation index: 4
type: SIMPLE_ASSIGN
receiver.medium.R = 90.9293729084188
*/
void Reference_1_eqFunction_4(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,4};
  data->localData[0]->realVars[134] /* receiver.medium.R variable */ = 90.9293729084188;
  TRACE_POP
}

/*
equation index: 5
type: SIMPLE_ASSIGN
receiver.medium.MM = 0.09143800000000001
*/
void Reference_1_eqFunction_5(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,5};
  data->localData[0]->realVars[133] /* receiver.medium.MM variable */ = 0.09143800000000001;
  TRACE_POP
}

/*
equation index: 6
type: SIMPLE_ASSIGN
receiver.medium.X[1] = 0.5
*/
void Reference_1_eqFunction_6(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,6};
  data->localData[0]->realVars[137] /* receiver.medium.X[1] variable */ = 0.5;
  TRACE_POP
}

/*
equation index: 7
type: SIMPLE_ASSIGN
receiver.medium.X[2] = 0.5
*/
void Reference_1_eqFunction_7(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,7};
  data->localData[0]->realVars[138] /* receiver.medium.X[2] variable */ = 0.5;
  TRACE_POP
}

/*
equation index: 8
type: SIMPLE_ASSIGN
receiver.fluid_a.h_outflow = 0.0
*/
void Reference_1_eqFunction_8(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,8};
  data->localData[0]->realVars[130] /* receiver.fluid_a.h_outflow variable */ = 0.0;
  TRACE_POP
}

/*
equation index: 9
type: SIMPLE_ASSIGN
tankHot.medium.R = 90.9293729084188
*/
void Reference_1_eqFunction_9(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,9};
  data->localData[0]->realVars[183] /* tankHot.medium.R variable */ = 90.9293729084188;
  TRACE_POP
}

/*
equation index: 10
type: SIMPLE_ASSIGN
tankHot.medium.MM = 0.09143800000000001
*/
void Reference_1_eqFunction_10(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,10};
  data->localData[0]->realVars[182] /* tankHot.medium.MM variable */ = 0.09143800000000001;
  TRACE_POP
}

/*
equation index: 11
type: SIMPLE_ASSIGN
tankHot.medium.X[1] = 0.5
*/
void Reference_1_eqFunction_11(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,11};
  data->localData[0]->realVars[186] /* tankHot.medium.X[1] variable */ = 0.5;
  TRACE_POP
}

/*
equation index: 12
type: SIMPLE_ASSIGN
tankHot.medium.X[2] = 0.5
*/
void Reference_1_eqFunction_12(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,12};
  data->localData[0]->realVars[187] /* tankHot.medium.X[2] variable */ = 0.5;
  TRACE_POP
}

/*
equation index: 13
type: SIMPLE_ASSIGN
$PRE.tankCold.W_net = $START.tankCold.W_net
*/
void Reference_1_eqFunction_13(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,13};
  data->simulationInfo->realVarsPre[221] /* tankCold.W_net DISCRETE */ = data->modelData->realVarsData[221].attribute /* tankCold.W_net DISCRETE */.start;
  TRACE_POP
}

/*
equation index: 14
type: SIMPLE_ASSIGN
$PRE.tankHot.W_net = $START.tankHot.W_net
*/
void Reference_1_eqFunction_14(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,14};
  data->simulationInfo->realVarsPre[222] /* tankHot.W_net DISCRETE */ = data->modelData->realVarsData[222].attribute /* tankHot.W_net DISCRETE */.start;
  TRACE_POP
}

/*
equation index: 15
type: SIMPLE_ASSIGN
tankHot.state_i.h = 1396.0182 * tankHot.T_start + 0.08599999999999999 * tankHot.T_start ^ 2.0
*/
void Reference_1_eqFunction_15(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,15};
  modelica_real tmp0;
  tmp0 = data->simulationInfo->realParameter[267] /* tankHot.T_start PARAM */;
  data->localData[0]->realVars[191] /* tankHot.state_i.h variable */ = (1396.0182) * (data->simulationInfo->realParameter[267] /* tankHot.T_start PARAM */) + (0.08599999999999999) * ((tmp0 * tmp0));
  TRACE_POP
}

/*
equation index: 16
type: SIMPLE_ASSIGN
tankCold.state_i.h = 1396.0182 * tankCold.T_start + 0.08599999999999999 * tankCold.T_start ^ 2.0
*/
void Reference_1_eqFunction_16(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,16};
  modelica_real tmp1;
  tmp1 = data->simulationInfo->realParameter[257] /* tankCold.T_start PARAM */;
  data->localData[0]->realVars[176] /* tankCold.state_i.h variable */ = (1396.0182) * (data->simulationInfo->realParameter[257] /* tankCold.T_start PARAM */) + (0.08599999999999999) * ((tmp1 * tmp1));
  TRACE_POP
}
extern void Reference_1_eqFunction_505(DATA *data, threadData_t *threadData);


/*
equation index: 18
type: SIMPLE_ASSIGN
prices.nextTimeEventScaled = Modelica.Blocks.Tables.Internal.getNextTimeEvent(prices.tableID, prices.timeScaled)
*/
void Reference_1_eqFunction_18(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,18};
  data->localData[0]->realVars[220] /* prices.nextTimeEventScaled DISCRETE */ = omc_Modelica_Blocks_Tables_Internal_getNextTimeEvent(threadData, data->simulationInfo->extObjs[2], data->localData[0]->realVars[122] /* prices.timeScaled variable */);
  TRACE_POP
}

/*
equation index: 19
type: SIMPLE_ASSIGN
prices.nextTimeEvent = if prices.nextTimeEventScaled < 9.999999999999999e+59 then prices.nextTimeEventScaled else 9.999999999999999e+59
*/
void Reference_1_eqFunction_19(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,19};
  modelica_boolean tmp2;
  tmp2 = Less(data->localData[0]->realVars[220] /* prices.nextTimeEventScaled DISCRETE */,9.999999999999999e+59);
  data->localData[0]->realVars[219] /* prices.nextTimeEvent DISCRETE */ = (tmp2?data->localData[0]->realVars[220] /* prices.nextTimeEventScaled DISCRETE */:9.999999999999999e+59);
  TRACE_POP
}

/*
equation index: 20
type: ALGORITHM

  (sun.dec, sun.hra) := SolarTherm.Models.Sources.SolarModel.Sun$sun.solarPosition(time, sun.lon, sun.lat, sun.t_zone, sun.year);
*/
void Reference_1_eqFunction_20(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,20};
  data->localData[0]->realVars[158] /* sun.dec variable */ = omc_SolarTherm_Models_Sources_SolarModel__omcQSun_24sun_solarPosition(threadData, data->localData[0]->timeValue, data->simulationInfo->realParameter[248] /* sun.lon PARAM */, data->simulationInfo->realParameter[247] /* sun.lat PARAM */, data->simulationInfo->realParameter[249] /* sun.t_zone PARAM */, data->simulationInfo->integerParameter[76] /* sun.year PARAM */ ,&data->localData[0]->realVars[160] /* sun.hra variable */);
  TRACE_POP
}
extern void Reference_1_eqFunction_587(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_588(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_589(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_590(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_591(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_592(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_586(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_593(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_596(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_603(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_604(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_506(DATA *data, threadData_t *threadData);


/*
equation index: 33
type: SIMPLE_ASSIGN
data.table.nextTimeEventScaled = Modelica.Blocks.Tables.Internal.getNextTimeEvent(data.table.tableID, data.table.timeScaled)
*/
void Reference_1_eqFunction_33(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,33};
  data->localData[0]->realVars[217] /* data.table.nextTimeEventScaled DISCRETE */ = omc_Modelica_Blocks_Tables_Internal_getNextTimeEvent(threadData, data->simulationInfo->extObjs[0], data->localData[0]->realVars[83] /* data.table.timeScaled variable */);
  TRACE_POP
}

/*
equation index: 34
type: SIMPLE_ASSIGN
data.table.nextTimeEvent = if data.table.nextTimeEventScaled < 9.999999999999999e+59 then data.table.nextTimeEventScaled else 9.999999999999999e+59
*/
void Reference_1_eqFunction_34(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,34};
  modelica_boolean tmp3;
  tmp3 = Less(data->localData[0]->realVars[217] /* data.table.nextTimeEventScaled DISCRETE */,9.999999999999999e+59);
  data->localData[0]->realVars[216] /* data.table.nextTimeEvent DISCRETE */ = (tmp3?data->localData[0]->realVars[217] /* data.table.nextTimeEventScaled DISCRETE */:9.999999999999999e+59);
  TRACE_POP
}
extern void Reference_1_eqFunction_594(DATA *data, threadData_t *threadData);


/*
equation index: 36
type: SIMPLE_ASSIGN
tankCold.W_net = $PRE.tankCold.W_net
*/
void Reference_1_eqFunction_36(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,36};
  data->localData[0]->realVars[221] /* tankCold.W_net DISCRETE */ = data->simulationInfo->realVarsPre[221] /* tankCold.W_net DISCRETE */;
  TRACE_POP
}
extern void Reference_1_eqFunction_625(DATA *data, threadData_t *threadData);


/*
equation index: 38
type: SIMPLE_ASSIGN
tankHot.W_net = $PRE.tankHot.W_net
*/
void Reference_1_eqFunction_38(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,38};
  data->localData[0]->realVars[222] /* tankHot.W_net DISCRETE */ = data->simulationInfo->realVarsPre[222] /* tankHot.W_net DISCRETE */;
  TRACE_POP
}
extern void Reference_1_eqFunction_707(DATA *data, threadData_t *threadData);


/*
equation index: 40
type: SIMPLE_ASSIGN
$PRE.data.table.nextTimeEventScaled = 0.0
*/
void Reference_1_eqFunction_40(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,40};
  data->simulationInfo->realVarsPre[217] /* data.table.nextTimeEventScaled DISCRETE */ = 0.0;
  TRACE_POP
}

/*
equation index: 41
type: SIMPLE_ASSIGN
data.GHI = data.table.p_offset[1] + Modelica.Blocks.Tables.Internal.getTimeTableValue(data.table.tableID, 1, data.table.timeScaled, data.table.nextTimeEventScaled, $PRE.data.table.nextTimeEventScaled)
*/
void Reference_1_eqFunction_41(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,41};
  data->localData[0]->realVars[79] /* data.GHI variable */ = data->simulationInfo->realParameter[109] /* data.table.p_offset[1] PARAM */ + omc_Modelica_Blocks_Tables_Internal_getTimeTableValue(threadData, data->simulationInfo->extObjs[0], ((modelica_integer) 1), data->localData[0]->realVars[83] /* data.table.timeScaled variable */, data->localData[0]->realVars[217] /* data.table.nextTimeEventScaled DISCRETE */, data->simulationInfo->realVarsPre[217] /* data.table.nextTimeEventScaled DISCRETE */);
  TRACE_POP
}

/*
equation index: 42
type: SIMPLE_ASSIGN
data.table.y[2] = data.table.p_offset[2] + Modelica.Blocks.Tables.Internal.getTimeTableValue(data.table.tableID, 2, data.table.timeScaled, data.table.nextTimeEventScaled, $PRE.data.table.nextTimeEventScaled)
*/
void Reference_1_eqFunction_42(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,42};
  data->localData[0]->realVars[84] /* data.table.y[2] variable */ = data->simulationInfo->realParameter[110] /* data.table.p_offset[2] PARAM */ + omc_Modelica_Blocks_Tables_Internal_getTimeTableValue(threadData, data->simulationInfo->extObjs[0], ((modelica_integer) 2), data->localData[0]->realVars[83] /* data.table.timeScaled variable */, data->localData[0]->realVars[217] /* data.table.nextTimeEventScaled DISCRETE */, data->simulationInfo->realVarsPre[217] /* data.table.nextTimeEventScaled DISCRETE */);
  TRACE_POP
}
extern void Reference_1_eqFunction_540(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_541(DATA *data, threadData_t *threadData);


/*
equation index: 45
type: SIMPLE_ASSIGN
data.DHI = data.table.p_offset[3] + Modelica.Blocks.Tables.Internal.getTimeTableValue(data.table.tableID, 3, data.table.timeScaled, data.table.nextTimeEventScaled, $PRE.data.table.nextTimeEventScaled)
*/
void Reference_1_eqFunction_45(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,45};
  data->localData[0]->realVars[78] /* data.DHI variable */ = data->simulationInfo->realParameter[111] /* data.table.p_offset[3] PARAM */ + omc_Modelica_Blocks_Tables_Internal_getTimeTableValue(threadData, data->simulationInfo->extObjs[0], ((modelica_integer) 3), data->localData[0]->realVars[83] /* data.table.timeScaled variable */, data->localData[0]->realVars[217] /* data.table.nextTimeEventScaled DISCRETE */, data->simulationInfo->realVarsPre[217] /* data.table.nextTimeEventScaled DISCRETE */);
  TRACE_POP
}

/*
equation index: 46
type: SIMPLE_ASSIGN
data.table.y[4] = data.table.p_offset[4] + Modelica.Blocks.Tables.Internal.getTimeTableValue(data.table.tableID, 4, data.table.timeScaled, data.table.nextTimeEventScaled, $PRE.data.table.nextTimeEventScaled)
*/
void Reference_1_eqFunction_46(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,46};
  data->localData[0]->realVars[85] /* data.table.y[4] variable */ = data->simulationInfo->realParameter[112] /* data.table.p_offset[4] PARAM */ + omc_Modelica_Blocks_Tables_Internal_getTimeTableValue(threadData, data->simulationInfo->extObjs[0], ((modelica_integer) 4), data->localData[0]->realVars[83] /* data.table.timeScaled variable */, data->localData[0]->realVars[217] /* data.table.nextTimeEventScaled DISCRETE */, data->simulationInfo->realVarsPre[217] /* data.table.nextTimeEventScaled DISCRETE */);
  TRACE_POP
}
extern void Reference_1_eqFunction_546(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_547(DATA *data, threadData_t *threadData);


/*
equation index: 49
type: SIMPLE_ASSIGN
data.table.y[5] = data.table.p_offset[5] + Modelica.Blocks.Tables.Internal.getTimeTableValue(data.table.tableID, 5, data.table.timeScaled, data.table.nextTimeEventScaled, $PRE.data.table.nextTimeEventScaled)
*/
void Reference_1_eqFunction_49(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,49};
  data->localData[0]->realVars[86] /* data.table.y[5] variable */ = data->simulationInfo->realParameter[113] /* data.table.p_offset[5] PARAM */ + omc_Modelica_Blocks_Tables_Internal_getTimeTableValue(threadData, data->simulationInfo->extObjs[0], ((modelica_integer) 5), data->localData[0]->realVars[83] /* data.table.timeScaled variable */, data->localData[0]->realVars[217] /* data.table.nextTimeEventScaled DISCRETE */, data->simulationInfo->realVarsPre[217] /* data.table.nextTimeEventScaled DISCRETE */);
  TRACE_POP
}
extern void Reference_1_eqFunction_550(DATA *data, threadData_t *threadData);


/*
equation index: 51
type: SIMPLE_ASSIGN
data.RH = data.table.p_offset[6] + Modelica.Blocks.Tables.Internal.getTimeTableValue(data.table.tableID, 6, data.table.timeScaled, data.table.nextTimeEventScaled, $PRE.data.table.nextTimeEventScaled)
*/
void Reference_1_eqFunction_51(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,51};
  data->localData[0]->realVars[80] /* data.RH variable */ = data->simulationInfo->realParameter[114] /* data.table.p_offset[6] PARAM */ + omc_Modelica_Blocks_Tables_Internal_getTimeTableValue(threadData, data->simulationInfo->extObjs[0], ((modelica_integer) 6), data->localData[0]->realVars[83] /* data.table.timeScaled variable */, data->localData[0]->realVars[217] /* data.table.nextTimeEventScaled DISCRETE */, data->simulationInfo->realVarsPre[217] /* data.table.nextTimeEventScaled DISCRETE */);
  TRACE_POP
}

/*
equation index: 52
type: SIMPLE_ASSIGN
data.table.y[7] = data.table.p_offset[7] + Modelica.Blocks.Tables.Internal.getTimeTableValue(data.table.tableID, 7, data.table.timeScaled, data.table.nextTimeEventScaled, $PRE.data.table.nextTimeEventScaled)
*/
void Reference_1_eqFunction_52(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,52};
  data->localData[0]->realVars[87] /* data.table.y[7] variable */ = data->simulationInfo->realParameter[115] /* data.table.p_offset[7] PARAM */ + omc_Modelica_Blocks_Tables_Internal_getTimeTableValue(threadData, data->simulationInfo->extObjs[0], ((modelica_integer) 7), data->localData[0]->realVars[83] /* data.table.timeScaled variable */, data->localData[0]->realVars[217] /* data.table.nextTimeEventScaled DISCRETE */, data->simulationInfo->realVarsPre[217] /* data.table.nextTimeEventScaled DISCRETE */);
  TRACE_POP
}
extern void Reference_1_eqFunction_555(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_558(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_557(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_556(DATA *data, threadData_t *threadData);


/*
equation index: 57
type: SIMPLE_ASSIGN
Wspd_input.y = data.table.p_offset[8] + Modelica.Blocks.Tables.Internal.getTimeTableValue(data.table.tableID, 8, data.table.timeScaled, data.table.nextTimeEventScaled, $PRE.data.table.nextTimeEventScaled)
*/
void Reference_1_eqFunction_57(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,57};
  data->localData[0]->realVars[58] /* Wspd_input.y variable */ = data->simulationInfo->realParameter[116] /* data.table.p_offset[8] PARAM */ + omc_Modelica_Blocks_Tables_Internal_getTimeTableValue(threadData, data->simulationInfo->extObjs[0], ((modelica_integer) 8), data->localData[0]->realVars[83] /* data.table.timeScaled variable */, data->localData[0]->realVars[217] /* data.table.nextTimeEventScaled DISCRETE */, data->simulationInfo->realVarsPre[217] /* data.table.nextTimeEventScaled DISCRETE */);
  TRACE_POP
}
extern void Reference_1_eqFunction_597(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_598(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_600(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_599(DATA *data, threadData_t *threadData);


/*
equation index: 62
type: SIMPLE_ASSIGN
data.table.y[9] = data.table.p_offset[9] + Modelica.Blocks.Tables.Internal.getTimeTableValue(data.table.tableID, 9, data.table.timeScaled, data.table.nextTimeEventScaled, $PRE.data.table.nextTimeEventScaled)
*/
void Reference_1_eqFunction_62(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,62};
  data->localData[0]->realVars[88] /* data.table.y[9] variable */ = data->simulationInfo->realParameter[117] /* data.table.p_offset[9] PARAM */ + omc_Modelica_Blocks_Tables_Internal_getTimeTableValue(threadData, data->simulationInfo->extObjs[0], ((modelica_integer) 9), data->localData[0]->realVars[83] /* data.table.timeScaled variable */, data->localData[0]->realVars[217] /* data.table.nextTimeEventScaled DISCRETE */, data->simulationInfo->realVarsPre[217] /* data.table.nextTimeEventScaled DISCRETE */);
  TRACE_POP
}
extern void Reference_1_eqFunction_563(DATA *data, threadData_t *threadData);


/*
equation index: 64
type: SIMPLE_ASSIGN
data.Albedo = data.table.p_offset[10] + Modelica.Blocks.Tables.Internal.getTimeTableValue(data.table.tableID, 10, data.table.timeScaled, data.table.nextTimeEventScaled, $PRE.data.table.nextTimeEventScaled)
*/
void Reference_1_eqFunction_64(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,64};
  data->localData[0]->realVars[77] /* data.Albedo variable */ = data->simulationInfo->realParameter[118] /* data.table.p_offset[10] PARAM */ + omc_Modelica_Blocks_Tables_Internal_getTimeTableValue(threadData, data->simulationInfo->extObjs[0], ((modelica_integer) 10), data->localData[0]->realVars[83] /* data.table.timeScaled variable */, data->localData[0]->realVars[217] /* data.table.nextTimeEventScaled DISCRETE */, data->simulationInfo->realVarsPre[217] /* data.table.nextTimeEventScaled DISCRETE */);
  TRACE_POP
}

/*
equation index: 65
type: SIMPLE_ASSIGN
$PRE.heliostatField.t_on = 0.0
*/
void Reference_1_eqFunction_65(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,65};
  data->simulationInfo->realVarsPre[218] /* heliostatField.t_on DISCRETE */ = 0.0;
  TRACE_POP
}

/*
equation index: 66
type: SIMPLE_ASSIGN
heliostatField.t_on = $PRE.heliostatField.t_on
*/
void Reference_1_eqFunction_66(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,66};
  data->localData[0]->realVars[218] /* heliostatField.t_on DISCRETE */ = data->simulationInfo->realVarsPre[218] /* heliostatField.t_on DISCRETE */;
  TRACE_POP
}

/*
equation index: 67
type: SIMPLE_ASSIGN
$PRE.controlHot.logic.startup = false
*/
void Reference_1_eqFunction_67(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,67};
  data->simulationInfo->booleanVarsPre[30] /* controlHot.logic.startup DISCRETE */ = 0;
  TRACE_POP
}

/*
equation index: 68
type: SIMPLE_ASSIGN
controlHot.logic.startup = $PRE.controlHot.logic.startup
*/
void Reference_1_eqFunction_68(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,68};
  data->localData[0]->booleanVars[30] /* controlHot.logic.startup DISCRETE */ = data->simulationInfo->booleanVarsPre[30] /* controlHot.logic.startup DISCRETE */;
  TRACE_POP
}

/*
equation index: 69
type: SIMPLE_ASSIGN
$PRE.prices.nextTimeEventScaled = 0.0
*/
void Reference_1_eqFunction_69(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,69};
  data->simulationInfo->realVarsPre[220] /* prices.nextTimeEventScaled DISCRETE */ = 0.0;
  TRACE_POP
}

/*
equation index: 70
type: SIMPLE_ASSIGN
prices.y[1] = prices.p_offset[1] + Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(prices.tableID, 1, prices.timeScaled, prices.nextTimeEventScaled, $PRE.prices.nextTimeEventScaled)
*/
void Reference_1_eqFunction_70(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,70};
  data->localData[0]->realVars[123] /* prices.y[1] variable */ = data->simulationInfo->realParameter[210] /* prices.p_offset[1] PARAM */ + omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, data->simulationInfo->extObjs[2], ((modelica_integer) 1), data->localData[0]->realVars[122] /* prices.timeScaled variable */, data->localData[0]->realVars[220] /* prices.nextTimeEventScaled DISCRETE */, data->simulationInfo->realVarsPre[220] /* prices.nextTimeEventScaled DISCRETE */);
  TRACE_POP
}

/*
equation index: 71
type: SIMPLE_ASSIGN
controlCold.PI.I.y = controlCold.PI.I.y_start
*/
void Reference_1_eqFunction_71(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,71};
  data->localData[0]->realVars[1] /* controlCold.PI.I.y STATE(1) */ = data->simulationInfo->realParameter[63] /* controlCold.PI.I.y_start PARAM */;
  TRACE_POP
}

/*
equation index: 72
type: SIMPLE_ASSIGN
$PRE.controlHot.logic.t_on = 0.0
*/
void Reference_1_eqFunction_72(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,72};
  data->simulationInfo->realVarsPre[215] /* controlHot.logic.t_on DISCRETE */ = 0.0;
  TRACE_POP
}

/*
equation index: 73
type: SIMPLE_ASSIGN
controlHot.logic.t_on = $PRE.controlHot.logic.t_on
*/
void Reference_1_eqFunction_73(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,73};
  data->localData[0]->realVars[215] /* controlHot.logic.t_on DISCRETE */ = data->simulationInfo->realVarsPre[215] /* controlHot.logic.t_on DISCRETE */;
  TRACE_POP
}
extern void Reference_1_eqFunction_675(DATA *data, threadData_t *threadData);


/*
equation index: 75
type: SIMPLE_ASSIGN
$PRE.controlHot.logic.t_off = 0.0
*/
void Reference_1_eqFunction_75(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,75};
  data->simulationInfo->realVarsPre[214] /* controlHot.logic.t_off DISCRETE */ = 0.0;
  TRACE_POP
}

/*
equation index: 76
type: SIMPLE_ASSIGN
controlHot.logic.t_off = $PRE.controlHot.logic.t_off
*/
void Reference_1_eqFunction_76(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,76};
  data->localData[0]->realVars[214] /* controlHot.logic.t_off DISCRETE */ = data->simulationInfo->realVarsPre[214] /* controlHot.logic.t_off DISCRETE */;
  TRACE_POP
}
extern void Reference_1_eqFunction_679(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_678(DATA *data, threadData_t *threadData);


/*
equation index: 79
type: SIMPLE_ASSIGN
tankCold.m = 0.01 * SolarTherm.Media.MoltenSalt.MoltenSalt_utilities.rho_T(SolarTherm.Media.MoltenSalt.MoltenSalt_utilities.T_h(tankCold.state_i.h)) * tankCold.V_t * tankCold.L_start
*/
void Reference_1_eqFunction_79(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,79};
  data->localData[0]->realVars[7] /* tankCold.m STATE(1) */ = (0.01) * ((omc_SolarTherm_Media_MoltenSalt_MoltenSalt__utilities_rho__T(threadData, omc_SolarTherm_Media_MoltenSalt_MoltenSalt__utilities_T__h(threadData, data->localData[0]->realVars[176] /* tankCold.state_i.h variable */))) * ((data->simulationInfo->realParameter[258] /* tankCold.V_t PARAM */) * (data->simulationInfo->realParameter[255] /* tankCold.L_start PARAM */)));
  TRACE_POP
}

/*
equation index: 80
type: SIMPLE_ASSIGN
tankCold.medium.h = tankCold.state_i.h
*/
void Reference_1_eqFunction_80(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,80};
  data->localData[0]->realVars[8] /* tankCold.medium.h STATE(1) */ = data->localData[0]->realVars[176] /* tankCold.state_i.h variable */;
  TRACE_POP
}

/*
equation index: 81
type: SIMPLE_ASSIGN
receiver.T_in = SolarTherm.Media.MoltenSalt.MoltenSalt_utilities.T_h(tankCold.medium.h)
*/
void Reference_1_eqFunction_81(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,81};
  data->localData[0]->realVars[129] /* receiver.T_in variable */ = omc_SolarTherm_Media_MoltenSalt_MoltenSalt__utilities_T__h(threadData, data->localData[0]->realVars[8] /* tankCold.medium.h STATE(1) */);
  TRACE_POP
}

/*
equation index: 82
type: SIMPLE_ASSIGN
tankCold.medium.T = SolarTherm.Media.MoltenSalt.MoltenSalt_utilities.T_h(tankCold.medium.h)
*/
void Reference_1_eqFunction_82(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,82};
  data->localData[0]->realVars[168] /* tankCold.medium.T variable */ = omc_SolarTherm_Media_MoltenSalt_MoltenSalt__utilities_T__h(threadData, data->localData[0]->realVars[8] /* tankCold.medium.h STATE(1) */);
  TRACE_POP
}

/*
equation index: 83
type: SIMPLE_ASSIGN
tankCold.medium.T_degC = -273.15 + tankCold.medium.T
*/
void Reference_1_eqFunction_83(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,83};
  data->localData[0]->realVars[169] /* tankCold.medium.T_degC variable */ = -273.15 + data->localData[0]->realVars[168] /* tankCold.medium.T variable */;
  TRACE_POP
}

/*
equation index: 84
type: SIMPLE_ASSIGN
tankCold.medium.d = SolarTherm.Media.MoltenSalt.MoltenSalt_utilities.rho_T(tankCold.medium.T)
*/
void Reference_1_eqFunction_84(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,84};
  data->localData[0]->realVars[172] /* tankCold.medium.d variable */ = omc_SolarTherm_Media_MoltenSalt_MoltenSalt__utilities_rho__T(threadData, data->localData[0]->realVars[168] /* tankCold.medium.T variable */);
  TRACE_POP
}
extern void Reference_1_eqFunction_622(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_608(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_609(DATA *data, threadData_t *threadData);


/*
equation index: 88
type: SIMPLE_ASSIGN
controlCold.hotTankLogic.y = controlCold.hotTankLogic.level_ref > controlCold.hotTankLogic.level_max and controlCold.hotTankLogic.level_ref > controlCold.hotTankLogic.level_min
*/
void Reference_1_eqFunction_88(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,88};
  modelica_boolean tmp4;
  modelica_boolean tmp5;
  tmp4 = Greater(data->localData[0]->realVars[70] /* controlCold.hotTankLogic.level_ref variable */,data->simulationInfo->realParameter[85] /* controlCold.hotTankLogic.level_max PARAM */);
  tmp5 = Greater(data->localData[0]->realVars[70] /* controlCold.hotTankLogic.level_ref variable */,data->simulationInfo->realParameter[86] /* controlCold.hotTankLogic.level_min PARAM */);
  data->localData[0]->booleanVars[25] /* controlCold.hotTankLogic.y DISCRETE */ = (tmp4 && tmp5);
  TRACE_POP
}

/*
equation index: 89
type: SIMPLE_ASSIGN
$PRE.controlCold.hotTankLogic.y = controlCold.hotTankLogic.y
*/
void Reference_1_eqFunction_89(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,89};
  data->simulationInfo->booleanVarsPre[25] /* controlCold.hotTankLogic.y DISCRETE */ = data->localData[0]->booleanVars[25] /* controlCold.hotTankLogic.y DISCRETE */;
  TRACE_POP
}
extern void Reference_1_eqFunction_615(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_614(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_621(DATA *data, threadData_t *threadData);


/*
equation index: 93
type: SIMPLE_ASSIGN
controlCold.defocus_logic.y = controlCold.defocus_logic.level_ref > controlCold.defocus_logic.level_max and controlCold.defocus_logic.level_ref > controlCold.defocus_logic.level_min
*/
void Reference_1_eqFunction_93(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,93};
  modelica_boolean tmp6;
  modelica_boolean tmp7;
  tmp6 = Greater(data->localData[0]->realVars[69] /* controlCold.defocus_logic.level_ref variable */,data->simulationInfo->realParameter[82] /* controlCold.defocus_logic.level_max PARAM */);
  tmp7 = Greater(data->localData[0]->realVars[69] /* controlCold.defocus_logic.level_ref variable */,data->simulationInfo->realParameter[83] /* controlCold.defocus_logic.level_min PARAM */);
  data->localData[0]->booleanVars[24] /* controlCold.defocus_logic.y DISCRETE */ = (tmp6 && tmp7);
  TRACE_POP
}

/*
equation index: 94
type: SIMPLE_ASSIGN
$PRE.controlCold.defocus_logic.y = controlCold.defocus_logic.y
*/
void Reference_1_eqFunction_94(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,94};
  data->simulationInfo->booleanVarsPre[24] /* controlCold.defocus_logic.y DISCRETE */ = data->localData[0]->booleanVars[24] /* controlCold.defocus_logic.y DISCRETE */;
  TRACE_POP
}

/*
equation index: 95
type: SIMPLE_ASSIGN
$whenCondition15 = controlCold.defocus_logic.level_ref < controlCold.defocus_logic.level_min
*/
void Reference_1_eqFunction_95(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,95};
  modelica_boolean tmp8;
  tmp8 = Less(data->localData[0]->realVars[69] /* controlCold.defocus_logic.level_ref variable */,data->simulationInfo->realParameter[83] /* controlCold.defocus_logic.level_min PARAM */);
  data->localData[0]->booleanVars[6] /* $whenCondition15 DISCRETE */ = tmp8;
  TRACE_POP
}

/*
equation index: 96
type: SIMPLE_ASSIGN
$whenCondition16 = controlCold.defocus_logic.level_ref > controlCold.defocus_logic.level_max
*/
void Reference_1_eqFunction_96(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,96};
  modelica_boolean tmp9;
  tmp9 = Greater(data->localData[0]->realVars[69] /* controlCold.defocus_logic.level_ref variable */,data->simulationInfo->realParameter[82] /* controlCold.defocus_logic.level_max PARAM */);
  data->localData[0]->booleanVars[7] /* $whenCondition16 DISCRETE */ = tmp9;
  TRACE_POP
}
extern void Reference_1_eqFunction_620(DATA *data, threadData_t *threadData);


/*
equation index: 98
type: SIMPLE_ASSIGN
tankCold.Q_losses = (-tankCold.A) * tankCold.alpha * (tankCold.medium.T - Tamb_input.y)
*/
void Reference_1_eqFunction_98(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,98};
  data->localData[0]->realVars[162] /* tankCold.Q_losses variable */ = ((-data->localData[0]->realVars[161] /* tankCold.A variable */)) * ((data->simulationInfo->realParameter[260] /* tankCold.alpha PARAM */) * (data->localData[0]->realVars[168] /* tankCold.medium.T variable */ - data->localData[0]->realVars[57] /* Tamb_input.y variable */));
  TRACE_POP
}

/*
equation index: 99
type: ALGORITHM

  $whenCondition19 := $START.$whenCondition19;
  $whenCondition18 := $START.$whenCondition18;
  $whenCondition18 := tankCold.medium.T < tankCold.T_set;
  $whenCondition19 := tankCold.medium.T > 1.0 + tankCold.T_set;
*/
void Reference_1_eqFunction_99(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,99};
  modelica_boolean tmp10;
  modelica_boolean tmp11;
  data->localData[0]->booleanVars[10] /* $whenCondition19 DISCRETE */ = data->modelData->booleanVarsData[10].attribute /* $whenCondition19 DISCRETE */.start;

  data->localData[0]->booleanVars[9] /* $whenCondition18 DISCRETE */ = data->modelData->booleanVarsData[9].attribute /* $whenCondition18 DISCRETE */.start;

  tmp10 = Less(data->localData[0]->realVars[168] /* tankCold.medium.T variable */,data->simulationInfo->realParameter[256] /* tankCold.T_set PARAM */);
  data->localData[0]->booleanVars[9] /* $whenCondition18 DISCRETE */ = tmp10;

  tmp11 = Greater(data->localData[0]->realVars[168] /* tankCold.medium.T variable */,1.0 + data->simulationInfo->realParameter[256] /* tankCold.T_set PARAM */);
  data->localData[0]->booleanVars[10] /* $whenCondition19 DISCRETE */ = tmp11;
  TRACE_POP
}
extern void Reference_1_eqFunction_605(DATA *data, threadData_t *threadData);


/*
equation index: 101
type: SIMPLE_ASSIGN
tankHot.m = 0.01 * SolarTherm.Media.MoltenSalt.MoltenSalt_utilities.rho_T(SolarTherm.Media.MoltenSalt.MoltenSalt_utilities.T_h(tankHot.state_i.h)) * tankHot.V_t * tankHot.L_start
*/
void Reference_1_eqFunction_101(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,101};
  data->localData[0]->realVars[9] /* tankHot.m STATE(1) */ = (0.01) * ((omc_SolarTherm_Media_MoltenSalt_MoltenSalt__utilities_rho__T(threadData, omc_SolarTherm_Media_MoltenSalt_MoltenSalt__utilities_T__h(threadData, data->localData[0]->realVars[191] /* tankHot.state_i.h variable */))) * ((data->simulationInfo->realParameter[268] /* tankHot.V_t PARAM */) * (data->simulationInfo->realParameter[265] /* tankHot.L_start PARAM */)));
  TRACE_POP
}

/*
equation index: 102
type: SIMPLE_ASSIGN
tankHot.medium.h = tankHot.state_i.h
*/
void Reference_1_eqFunction_102(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,102};
  data->localData[0]->realVars[10] /* tankHot.medium.h STATE(1) */ = data->localData[0]->realVars[191] /* tankHot.state_i.h variable */;
  TRACE_POP
}

/*
equation index: 103
type: SIMPLE_ASSIGN
tankHot.medium.T = SolarTherm.Media.MoltenSalt.MoltenSalt_utilities.T_h(tankHot.medium.h)
*/
void Reference_1_eqFunction_103(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,103};
  data->localData[0]->realVars[184] /* tankHot.medium.T variable */ = omc_SolarTherm_Media_MoltenSalt_MoltenSalt__utilities_T__h(threadData, data->localData[0]->realVars[10] /* tankHot.medium.h STATE(1) */);
  TRACE_POP
}

/*
equation index: 104
type: SIMPLE_ASSIGN
tankHot.medium.T_degC = -273.15 + tankHot.medium.T
*/
void Reference_1_eqFunction_104(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,104};
  data->localData[0]->realVars[185] /* tankHot.medium.T_degC variable */ = -273.15 + data->localData[0]->realVars[184] /* tankHot.medium.T variable */;
  TRACE_POP
}

/*
equation index: 105
type: SIMPLE_ASSIGN
tankHot.medium.d = SolarTherm.Media.MoltenSalt.MoltenSalt_utilities.rho_T(tankHot.medium.T)
*/
void Reference_1_eqFunction_105(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,105};
  data->localData[0]->realVars[188] /* tankHot.medium.d variable */ = omc_SolarTherm_Media_MoltenSalt_MoltenSalt__utilities_rho__T(threadData, data->localData[0]->realVars[184] /* tankHot.medium.T variable */);
  TRACE_POP
}
extern void Reference_1_eqFunction_690(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_630(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_631(DATA *data, threadData_t *threadData);


/*
equation index: 109
type: SIMPLE_ASSIGN
controlHot.logic.on_discharge = controlHot.logic.level > controlHot.logic.level_on and controlHot.logic.level > controlHot.logic.level_off
*/
void Reference_1_eqFunction_109(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,109};
  modelica_boolean tmp12;
  modelica_boolean tmp13;
  tmp12 = Greater(data->localData[0]->realVars[74] /* controlHot.logic.level variable */,data->simulationInfo->realParameter[97] /* controlHot.logic.level_on PARAM */);
  tmp13 = Greater(data->localData[0]->realVars[74] /* controlHot.logic.level variable */,data->simulationInfo->realParameter[96] /* controlHot.logic.level_off PARAM */);
  data->localData[0]->booleanVars[28] /* controlHot.logic.on_discharge DISCRETE */ = (tmp12 && tmp13);
  TRACE_POP
}

/*
equation index: 110
type: SIMPLE_ASSIGN
$PRE.controlHot.logic.on_discharge = controlHot.logic.on_discharge
*/
void Reference_1_eqFunction_110(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,110};
  data->simulationInfo->booleanVarsPre[28] /* controlHot.logic.on_discharge DISCRETE */ = data->localData[0]->booleanVars[28] /* controlHot.logic.on_discharge DISCRETE */;
  TRACE_POP
}
extern void Reference_1_eqFunction_670(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_669(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_689(DATA *data, threadData_t *threadData);


/*
equation index: 114
type: SIMPLE_ASSIGN
controlHot.defocus_logic.y = controlHot.defocus_logic.level_ref > controlHot.defocus_logic.level_max and controlHot.defocus_logic.level_ref > controlHot.defocus_logic.level_min
*/
void Reference_1_eqFunction_114(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,114};
  modelica_boolean tmp14;
  modelica_boolean tmp15;
  tmp14 = Greater(data->localData[0]->realVars[73] /* controlHot.defocus_logic.level_ref variable */,data->simulationInfo->realParameter[94] /* controlHot.defocus_logic.level_max PARAM */);
  tmp15 = Greater(data->localData[0]->realVars[73] /* controlHot.defocus_logic.level_ref variable */,data->simulationInfo->realParameter[95] /* controlHot.defocus_logic.level_min PARAM */);
  data->localData[0]->booleanVars[26] /* controlHot.defocus_logic.y DISCRETE */ = (tmp14 && tmp15);
  TRACE_POP
}

/*
equation index: 115
type: SIMPLE_ASSIGN
$PRE.controlHot.defocus_logic.y = controlHot.defocus_logic.y
*/
void Reference_1_eqFunction_115(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,115};
  data->simulationInfo->booleanVarsPre[26] /* controlHot.defocus_logic.y DISCRETE */ = data->localData[0]->booleanVars[26] /* controlHot.defocus_logic.y DISCRETE */;
  TRACE_POP
}
extern void Reference_1_eqFunction_636(DATA *data, threadData_t *threadData);


/*
equation index: 117
type: SIMPLE_ASSIGN
$whenCondition5 = controlHot.defocus_logic.level_ref < controlHot.defocus_logic.level_min
*/
void Reference_1_eqFunction_117(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,117};
  modelica_boolean tmp16;
  tmp16 = Less(data->localData[0]->realVars[73] /* controlHot.defocus_logic.level_ref variable */,data->simulationInfo->realParameter[95] /* controlHot.defocus_logic.level_min PARAM */);
  data->localData[0]->booleanVars[17] /* $whenCondition5 DISCRETE */ = tmp16;
  TRACE_POP
}

/*
equation index: 118
type: SIMPLE_ASSIGN
$whenCondition6 = controlHot.defocus_logic.level_ref > controlHot.defocus_logic.level_max
*/
void Reference_1_eqFunction_118(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,118};
  modelica_boolean tmp17;
  tmp17 = Greater(data->localData[0]->realVars[73] /* controlHot.defocus_logic.level_ref variable */,data->simulationInfo->realParameter[94] /* controlHot.defocus_logic.level_max PARAM */);
  data->localData[0]->booleanVars[18] /* $whenCondition6 DISCRETE */ = tmp17;
  TRACE_POP
}
extern void Reference_1_eqFunction_688(DATA *data, threadData_t *threadData);


/*
equation index: 120
type: SIMPLE_ASSIGN
tankHot.Q_losses = (-tankHot.A) * tankHot.alpha * (tankHot.medium.T - Tamb_input.y)
*/
void Reference_1_eqFunction_120(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,120};
  data->localData[0]->realVars[178] /* tankHot.Q_losses variable */ = ((-data->localData[0]->realVars[177] /* tankHot.A variable */)) * ((data->simulationInfo->realParameter[270] /* tankHot.alpha PARAM */) * (data->localData[0]->realVars[184] /* tankHot.medium.T variable */ - data->localData[0]->realVars[57] /* Tamb_input.y variable */));
  TRACE_POP
}

/*
equation index: 121
type: ALGORITHM

  $whenCondition21 := $START.$whenCondition21;
  $whenCondition20 := $START.$whenCondition20;
  $whenCondition20 := tankHot.medium.T < tankHot.T_set;
  $whenCondition21 := tankHot.medium.T > 1.0 + tankHot.T_set;
*/
void Reference_1_eqFunction_121(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,121};
  modelica_boolean tmp18;
  modelica_boolean tmp19;
  data->localData[0]->booleanVars[13] /* $whenCondition21 DISCRETE */ = data->modelData->booleanVarsData[13].attribute /* $whenCondition21 DISCRETE */.start;

  data->localData[0]->booleanVars[12] /* $whenCondition20 DISCRETE */ = data->modelData->booleanVarsData[12].attribute /* $whenCondition20 DISCRETE */.start;

  tmp18 = Less(data->localData[0]->realVars[184] /* tankHot.medium.T variable */,data->simulationInfo->realParameter[266] /* tankHot.T_set PARAM */);
  data->localData[0]->booleanVars[12] /* $whenCondition20 DISCRETE */ = tmp18;

  tmp19 = Greater(data->localData[0]->realVars[184] /* tankHot.medium.T variable */,1.0 + data->simulationInfo->realParameter[266] /* tankHot.T_set PARAM */);
  data->localData[0]->booleanVars[13] /* $whenCondition21 DISCRETE */ = tmp19;
  TRACE_POP
}

/*
equation index: 122
type: SIMPLE_ASSIGN
tankHot.T = SolarTherm.Media.MoltenSalt.MoltenSalt_utilities.T_h(tankHot.medium.h)
*/
void Reference_1_eqFunction_122(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,122};
  data->localData[0]->realVars[179] /* tankHot.T variable */ = omc_SolarTherm_Media_MoltenSalt_MoltenSalt__utilities_T__h(threadData, data->localData[0]->realVars[10] /* tankHot.medium.h STATE(1) */);
  TRACE_POP
}
extern void Reference_1_eqFunction_628(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_692(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_693(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_700(DATA *data, threadData_t *threadData);


/*
equation index: 127
type: SIMPLE_ASSIGN
heliostatField.on_internal = heliostatField.Q_raw > heliostatField.Q_start
*/
void Reference_1_eqFunction_127(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,127};
  modelica_boolean tmp20;
  tmp20 = Greater(data->localData[0]->realVars[90] /* heliostatField.Q_raw variable */,data->simulationInfo->realParameter[139] /* heliostatField.Q_start PARAM */);
  data->localData[0]->booleanVars[33] /* heliostatField.on_internal DISCRETE */ = tmp20;
  TRACE_POP
}

/*
equation index: 128
type: SIMPLE_ASSIGN
$PRE.heliostatField.on_internal = heliostatField.on_internal
*/
void Reference_1_eqFunction_128(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,128};
  data->simulationInfo->booleanVarsPre[33] /* heliostatField.on_internal DISCRETE */ = data->localData[0]->booleanVars[33] /* heliostatField.on_internal DISCRETE */;
  TRACE_POP
}
extern void Reference_1_eqFunction_637(DATA *data, threadData_t *threadData);


/*
equation index: 130
type: SIMPLE_ASSIGN
receiver.heat.Q_flow = -max(-heliostatField.Q_net, -700000000.0)
*/
void Reference_1_eqFunction_130(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,130};
  data->localData[0]->realVars[132] /* receiver.heat.Q_flow variable */ = (-fmax((-data->localData[0]->realVars[89] /* heliostatField.Q_net variable */),-700000000.0));
  TRACE_POP
}
extern void Reference_1_eqFunction_642(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_638(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_640(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_639(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_641(DATA *data, threadData_t *threadData);


/*
equation index: 136
type: SIMPLE_ASSIGN
controlCold.PI.reset = controlCold.hotTankLogic.y and heliostatField.on_internal
*/
void Reference_1_eqFunction_136(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,136};
  data->localData[0]->booleanVars[23] /* controlCold.PI.reset DISCRETE */ = (data->localData[0]->booleanVars[25] /* controlCold.hotTankLogic.y DISCRETE */ && data->localData[0]->booleanVars[33] /* heliostatField.on_internal DISCRETE */);
  TRACE_POP
}

/*
equation index: 137
type: SIMPLE_ASSIGN
$whenCondition22 = controlCold.PI.reset
*/
void Reference_1_eqFunction_137(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,137};
  data->localData[0]->booleanVars[14] /* $whenCondition22 DISCRETE */ = data->localData[0]->booleanVars[23] /* controlCold.PI.reset DISCRETE */;
  TRACE_POP
}

void Reference_1_eqFunction_138(DATA*, threadData_t*);
void Reference_1_eqFunction_139(DATA*, threadData_t*);
void Reference_1_eqFunction_140(DATA*, threadData_t*);
void Reference_1_eqFunction_141(DATA*, threadData_t*);
void Reference_1_eqFunction_142(DATA*, threadData_t*);
void Reference_1_eqFunction_143(DATA*, threadData_t*);
void Reference_1_eqFunction_144(DATA*, threadData_t*);
void Reference_1_eqFunction_145(DATA*, threadData_t*);
void Reference_1_eqFunction_146(DATA*, threadData_t*);
void Reference_1_eqFunction_147(DATA*, threadData_t*);
void Reference_1_eqFunction_148(DATA*, threadData_t*);
/*
equation index: 149
indexNonlinear: 0
type: NONLINEAR

vars: {receiver.h_out}
eqns: {138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148}
*/
void Reference_1_eqFunction_149(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,149};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 149 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[0].nlsxOld[0] = data->localData[0]->realVars[131] /* receiver.h_out variable */;
  retValue = solve_nonlinear_system(data, threadData, 0);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,149};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving non-linear system 149 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->localData[0]->realVars[131] /* receiver.h_out variable */ = data->simulationInfo->nonlinearSystemData[0].nlsx[0];
  TRACE_POP
}
extern void Reference_1_eqFunction_663(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_664(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_665(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_666(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_658(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_659(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_660(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_661(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_662(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_667(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_657(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_656(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_676(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_673(DATA *data, threadData_t *threadData);


/*
equation index: 164
type: ALGORITHM

  wea.meta := SolarTherm.Models.Sources.Weather.getMetadata(wea.file_act);
*/
void Reference_1_eqFunction_164(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,164};
  SolarTherm_Models_Sources_Weather_Metadata tmp0;
  tmp0 = omc_SolarTherm_Models_Sources_Weather_getMetadata(threadData, data->simulationInfo->stringParameter[17] /* wea.file_act PARAM */);
  data->simulationInfo->stringParameter[18] /* wea.meta.name PARAM */ = tmp0._name;
  data->simulationInfo->realParameter[296] /* wea.meta.lat PARAM */ = tmp0._lat;
  data->simulationInfo->realParameter[297] /* wea.meta.lon PARAM */ = tmp0._lon;
  data->simulationInfo->realParameter[295] /* wea.meta.elev PARAM */ = tmp0._elev;
  data->simulationInfo->realParameter[299] /* wea.meta.tzone PARAM */ = tmp0._tzone;
  data->simulationInfo->realParameter[298] /* wea.meta.tstart PARAM */ = tmp0._tstart;
  ;
  TRACE_POP
}

/*
equation index: 165
type: SIMPLE_ASSIGN
wea.lat = wea.meta.lat
*/
void Reference_1_eqFunction_165(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,165};
  data->simulationInfo->realParameter[293] /* wea.lat PARAM */ = data->simulationInfo->realParameter[296] /* wea.meta.lat PARAM */;
  TRACE_POP
}

/*
equation index: 166
type: SIMPLE_ASSIGN
wea.spos.lat = wea.lat
*/
void Reference_1_eqFunction_166(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,166};
  data->simulationInfo->realParameter[300] /* wea.spos.lat PARAM */ = data->simulationInfo->realParameter[293] /* wea.lat PARAM */;
  TRACE_POP
}

/*
equation index: 167
type: SIMPLE_ASSIGN
wea.orient_north = wea.lat < 0.0
*/
void Reference_1_eqFunction_167(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,167};
  modelica_boolean tmp1;
  tmp1 = Less(data->simulationInfo->realParameter[293] /* wea.lat PARAM */,0.0);
  data->simulationInfo->booleanParameter[41] /* wea.orient_north PARAM */ = tmp1;
  TRACE_POP
}

/*
equation index: 168
type: SIMPLE_ASSIGN
wea.date.toyoffset = wea.meta.tstart
*/
void Reference_1_eqFunction_168(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,168};
  data->simulationInfo->realParameter[284] /* wea.date.toyoffset PARAM */ = data->simulationInfo->realParameter[298] /* wea.meta.tstart PARAM */;
  TRACE_POP
}
extern void Reference_1_eqFunction_507(DATA *data, threadData_t *threadData);


/*
equation index: 170
type: SIMPLE_ASSIGN
sch_fixed.daily[1].t = mod(sch_fixed.wbus.t, 86400.0)
*/
void Reference_1_eqFunction_170(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,170};
  modelica_real tmp2;
  tmp2 = 86400.0;
  if (tmp2 == 0) {throwStreamPrint(threadData, "Division by zero %s", "mod(sch_fixed.wbus.t, 86400.0)");}
  data->localData[0]->realVars[143] /* sch_fixed.daily[1].t variable */ = modelica_real_mod(data->localData[0]->realVars[153] /* sch_fixed.wbus.t variable */, tmp2);
  TRACE_POP
}
extern void Reference_1_eqFunction_509(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_682(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_687(DATA *data, threadData_t *threadData);


/*
equation index: 174
type: SIMPLE_ASSIGN
$DER.tankHot.medium.h = (tankHot.Q_losses + tankHot.W_net + controlCold.m_flow * temperature.state.h - controlHot.m_flow * tankHot.medium.h - $DER.tankHot.m * tankHot.medium.h) / tankHot.m
*/
void Reference_1_eqFunction_174(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,174};
  data->localData[0]->realVars[21] /* der(tankHot.medium.h) STATE_DER */ = DIVISION_SIM(data->localData[0]->realVars[178] /* tankHot.Q_losses variable */ + data->localData[0]->realVars[222] /* tankHot.W_net DISCRETE */ + (data->localData[0]->realVars[71] /* controlCold.m_flow variable */) * (data->localData[0]->realVars[192] /* temperature.state.h variable */) - ((data->localData[0]->realVars[75] /* controlHot.m_flow variable */) * (data->localData[0]->realVars[10] /* tankHot.medium.h STATE(1) */)) - ((data->localData[0]->realVars[20] /* der(tankHot.m) STATE_DER */) * (data->localData[0]->realVars[10] /* tankHot.medium.h STATE(1) */)),data->localData[0]->realVars[9] /* tankHot.m STATE(1) */,"tankHot.m",equationIndexes);
  TRACE_POP
}
extern void Reference_1_eqFunction_683(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_708(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_686(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_684(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_685(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_701(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_694(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_695(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_702(DATA *data, threadData_t *threadData);


/*
equation index: 184
type: SIMPLE_ASSIGN
powerBlock.eff_pb = powerBlock.W_gross / max(1.0, powerBlock.Q_flow)
*/
void Reference_1_eqFunction_184(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,184};
  data->localData[0]->realVars[117] /* powerBlock.eff_pb variable */ = DIVISION_SIM(data->localData[0]->realVars[110] /* powerBlock.W_gross variable */,fmax(1.0,data->localData[0]->realVars[107] /* powerBlock.Q_flow variable */),"max(1.0, powerBlock.Q_flow)",equationIndexes);
  TRACE_POP
}
extern void Reference_1_eqFunction_703(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_709(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_710(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_713(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_712(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_711(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_697(DATA *data, threadData_t *threadData);


/*
equation index: 192
type: SIMPLE_ASSIGN
$DER.tankCold.medium.h = (tankCold.Q_losses + tankCold.W_net + controlHot.m_flow * powerBlock.fluid_b.h_outflow - controlCold.m_flow * tankCold.medium.h - $DER.tankCold.m * tankCold.medium.h) / tankCold.m
*/
void Reference_1_eqFunction_192(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,192};
  data->localData[0]->realVars[19] /* der(tankCold.medium.h) STATE_DER */ = DIVISION_SIM(data->localData[0]->realVars[162] /* tankCold.Q_losses variable */ + data->localData[0]->realVars[221] /* tankCold.W_net DISCRETE */ + (data->localData[0]->realVars[75] /* controlHot.m_flow variable */) * (data->localData[0]->realVars[118] /* powerBlock.fluid_b.h_outflow variable */) - ((data->localData[0]->realVars[71] /* controlCold.m_flow variable */) * (data->localData[0]->realVars[8] /* tankCold.medium.h STATE(1) */)) - ((data->localData[0]->realVars[18] /* der(tankCold.m) STATE_DER */) * (data->localData[0]->realVars[8] /* tankCold.medium.h STATE(1) */)),data->localData[0]->realVars[7] /* tankCold.m STATE(1) */,"tankCold.m",equationIndexes);
  TRACE_POP
}
extern void Reference_1_eqFunction_698(DATA *data, threadData_t *threadData);


/*
equation index: 194
type: SIMPLE_ASSIGN
sch_fixed.week[1].i = 1 + integer(mod(1.157407407407407e-05 * sch_fixed.wbus.t, 7.0))
*/
void Reference_1_eqFunction_194(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,194};
  modelica_real tmp3;
  tmp3 = 7.0;
  if (tmp3 == 0) {throwStreamPrint(threadData, "Division by zero %s", "mod(1.157407407407407e-05 * sch_fixed.wbus.t, 7.0)");}
  data->localData[0]->integerVars[2] /* sch_fixed.week[1].i DISCRETE */ = ((modelica_integer) 1) + ((modelica_integer)floor(modelica_real_mod((1.157407407407407e-05) * (data->localData[0]->realVars[153] /* sch_fixed.wbus.t variable */), tmp3)));
  TRACE_POP
}
extern void Reference_1_eqFunction_511(DATA *data, threadData_t *threadData);


/*
equation index: 196
type: SIMPLE_ASSIGN
sch_fixed.month.i = 1 + integer(mod(3.80517503805175e-07 * sch_fixed.wbus.t, 12.0))
*/
void Reference_1_eqFunction_196(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,196};
  modelica_real tmp4;
  tmp4 = 12.0;
  if (tmp4 == 0) {throwStreamPrint(threadData, "Division by zero %s", "mod(3.80517503805175e-07 * sch_fixed.wbus.t, 12.0)");}
  data->localData[0]->integerVars[0] /* sch_fixed.month.i DISCRETE */ = ((modelica_integer) 1) + ((modelica_integer)floor(modelica_real_mod((3.80517503805175e-07) * (data->localData[0]->realVars[153] /* sch_fixed.wbus.t variable */), tmp4)));
  TRACE_POP
}
extern void Reference_1_eqFunction_513(DATA *data, threadData_t *threadData);


/*
equation index: 198
type: SIMPLE_ASSIGN
wea.spos.tzone = wea.meta.tzone
*/
void Reference_1_eqFunction_198(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,198};
  data->simulationInfo->realParameter[302] /* wea.spos.tzone PARAM */ = data->simulationInfo->realParameter[299] /* wea.meta.tzone PARAM */;
  TRACE_POP
}
extern void Reference_1_eqFunction_514(DATA *data, threadData_t *threadData);


/*
equation index: 200
type: SIMPLE_ASSIGN
wea.spos.E = 3.82 * (7.499999999999999e-05 + 0.001868 * cos(wea.spos.B) + (-0.032077) * sin(wea.spos.B) + (-0.014615) * cos(2.0 * wea.spos.B) + (-0.04089) * sin(2.0 * wea.spos.B))
*/
void Reference_1_eqFunction_200(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,200};
  data->localData[0]->realVars[194] /* wea.spos.E variable */ = (3.82) * (7.499999999999999e-05 + (0.001868) * (cos(data->localData[0]->realVars[193] /* wea.spos.B variable */)) + (-0.032077) * (sin(data->localData[0]->realVars[193] /* wea.spos.B variable */)) + (-0.014615) * (cos((2.0) * (data->localData[0]->realVars[193] /* wea.spos.B variable */))) + (-0.04089) * (sin((2.0) * (data->localData[0]->realVars[193] /* wea.spos.B variable */))));
  TRACE_POP
}

/*
equation index: 201
type: SIMPLE_ASSIGN
wea.spos.dec_r = 0.006918 + (-0.399912) * cos(wea.spos.B) + 0.070257 * sin(wea.spos.B) + (-0.006758) * cos(2.0 * wea.spos.B) + 0.000907 * sin(2.0 * wea.spos.B) + (-0.002697) * cos(3.0 * wea.spos.B) + 0.00148 * sin(3.0 * wea.spos.B)
*/
void Reference_1_eqFunction_201(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,201};
  data->localData[0]->realVars[195] /* wea.spos.dec_r variable */ = 0.006918 + (-0.399912) * (cos(data->localData[0]->realVars[193] /* wea.spos.B variable */)) + (0.070257) * (sin(data->localData[0]->realVars[193] /* wea.spos.B variable */)) + (-0.006758) * (cos((2.0) * (data->localData[0]->realVars[193] /* wea.spos.B variable */))) + (0.000907) * (sin((2.0) * (data->localData[0]->realVars[193] /* wea.spos.B variable */))) + (-0.002697) * (cos((3.0) * (data->localData[0]->realVars[193] /* wea.spos.B variable */))) + (0.00148) * (sin((3.0) * (data->localData[0]->realVars[193] /* wea.spos.B variable */)));
  TRACE_POP
}
extern void Reference_1_eqFunction_529(DATA *data, threadData_t *threadData);


/*
equation index: 203
type: SIMPLE_ASSIGN
sch_fixed.wbus.elo = 57.29577951308232 * asin(min(max(2.514364271857552 * sin(wea.spos.dec_r), -1.0), 1.0))
*/
void Reference_1_eqFunction_203(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,203};
  modelica_real tmp5;
  tmp5 = fmin(fmax((2.514364271857552) * (sin(data->localData[0]->realVars[195] /* wea.spos.dec_r variable */)),-1.0),1.0);
  if(!(tmp5 >= -1.0 && tmp5 <= 1.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
    throwStreamPrintWithEquationIndexes(threadData, equationIndexes, "Model error: Argument of asin(min(max(2.514364271857552 * sin(wea.spos.dec_r), -1.0), 1.0)) outside the domain -1.0 <= %g <= 1.0", tmp5);
  }
  data->localData[0]->realVars[150] /* sch_fixed.wbus.elo variable */ = (57.29577951308232) * (asin(tmp5));
  TRACE_POP
}

/*
equation index: 204
type: SIMPLE_ASSIGN
wea.lon = wea.meta.lon
*/
void Reference_1_eqFunction_204(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,204};
  data->simulationInfo->realParameter[294] /* wea.lon PARAM */ = data->simulationInfo->realParameter[297] /* wea.meta.lon PARAM */;
  TRACE_POP
}

/*
equation index: 205
type: SIMPLE_ASSIGN
wea.spos.lon = wea.lon
*/
void Reference_1_eqFunction_205(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,205};
  data->simulationInfo->realParameter[301] /* wea.spos.lon PARAM */ = data->simulationInfo->realParameter[294] /* wea.lon PARAM */;
  TRACE_POP
}
extern void Reference_1_eqFunction_530(DATA *data, threadData_t *threadData);


/*
equation index: 207
type: SIMPLE_ASSIGN
sch_fixed.wbus.hra = 15.0 * (-12.0 + mod(wea.spos.t_solar, 24.0))
*/
void Reference_1_eqFunction_207(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,207};
  modelica_real tmp6;
  tmp6 = 24.0;
  if (tmp6 == 0) {throwStreamPrint(threadData, "Division by zero %s", "mod(wea.spos.t_solar, 24.0)");}
  data->localData[0]->realVars[152] /* sch_fixed.wbus.hra variable */ = (15.0) * (-12.0 + modelica_real_mod(data->localData[0]->realVars[197] /* wea.spos.t_solar variable */, tmp6));
  TRACE_POP
}
extern void Reference_1_eqFunction_533(DATA *data, threadData_t *threadData);


/*
equation index: 209
type: SIMPLE_ASSIGN
wea.spos.zen_r = acos(min(max(sin(wea.spos.dec_r) * sin(0.0174532925199433 * wea.spos.lat) + cos(wea.spos.dec_r) * cos(0.0174532925199433 * wea.spos.lat) * cos(0.0174532925199433 * sch_fixed.wbus.hra), -1.0), 1.0))
*/
void Reference_1_eqFunction_209(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,209};
  modelica_real tmp7;
  tmp7 = fmin(fmax((sin(data->localData[0]->realVars[195] /* wea.spos.dec_r variable */)) * (sin((0.0174532925199433) * (data->simulationInfo->realParameter[300] /* wea.spos.lat PARAM */))) + (cos(data->localData[0]->realVars[195] /* wea.spos.dec_r variable */)) * ((cos((0.0174532925199433) * (data->simulationInfo->realParameter[300] /* wea.spos.lat PARAM */))) * (cos((0.0174532925199433) * (data->localData[0]->realVars[152] /* sch_fixed.wbus.hra variable */)))),-1.0),1.0);
  if(!(tmp7 >= -1.0 && tmp7 <= 1.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
    throwStreamPrintWithEquationIndexes(threadData, equationIndexes, "Model error: Argument of acos(min(max(sin(wea.spos.dec_r) * sin(0.0174532925199433 * wea.spos.lat) + cos(wea.spos.dec_r) * cos(0.0174532925199433 * wea.spos.lat) * cos(0.0174532925199433 * sch_fixed.wbus.hra), -1.0), 1.0)) outside the domain -1.0 <= %g <= 1.0", tmp7);
  }
  data->localData[0]->realVars[198] /* wea.spos.zen_r variable */ = acos(tmp7);
  TRACE_POP
}
extern void Reference_1_eqFunction_579(DATA *data, threadData_t *threadData);


/*
equation index: 211
type: SIMPLE_ASSIGN
sch_fixed.wbus.azi = 57.29577951308232 * (3.141592653589793 + wea.spos.hra_s * acos(min(max((cos(wea.spos.zen_r) * sin(0.0174532925199433 * wea.spos.lat) - sin(wea.spos.dec_r)) / (cos(0.0174532925199433 * wea.spos.lat) * sin(wea.spos.zen_r)), -1.0), 1.0)))
*/
void Reference_1_eqFunction_211(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,211};
  modelica_real tmp8;
  tmp8 = fmin(fmax(DIVISION_SIM((cos(data->localData[0]->realVars[198] /* wea.spos.zen_r variable */)) * (sin((0.0174532925199433) * (data->simulationInfo->realParameter[300] /* wea.spos.lat PARAM */))) - sin(data->localData[0]->realVars[195] /* wea.spos.dec_r variable */),(cos((0.0174532925199433) * (data->simulationInfo->realParameter[300] /* wea.spos.lat PARAM */))) * (sin(data->localData[0]->realVars[198] /* wea.spos.zen_r variable */)),"cos(0.0174532925199433 * wea.spos.lat) * sin(wea.spos.zen_r)",equationIndexes),-1.0),1.0);
  if(!(tmp8 >= -1.0 && tmp8 <= 1.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
    throwStreamPrintWithEquationIndexes(threadData, equationIndexes, "Model error: Argument of acos(min(max((cos(wea.spos.zen_r) * sin(0.0174532925199433 * wea.spos.lat) - sin(wea.spos.dec_r)) / (cos(0.0174532925199433 * wea.spos.lat) * sin(wea.spos.zen_r)), -1.0), 1.0)) outside the domain -1.0 <= %g <= 1.0", tmp8);
  }
  data->localData[0]->realVars[147] /* sch_fixed.wbus.azi variable */ = (57.29577951308232) * (3.141592653589793 + (data->localData[0]->realVars[196] /* wea.spos.hra_s variable */) * (acos(tmp8)));
  TRACE_POP
}
extern void Reference_1_eqFunction_580(DATA *data, threadData_t *threadData);


/*
equation index: 213
type: SIMPLE_ASSIGN
tankCold.medium.R = 90.9293729084188
*/
void Reference_1_eqFunction_213(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,213};
  data->localData[0]->realVars[167] /* tankCold.medium.R variable */ = 90.9293729084188;
  TRACE_POP
}

/*
equation index: 214
type: SIMPLE_ASSIGN
tankCold.medium.MM = 0.09143800000000001
*/
void Reference_1_eqFunction_214(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,214};
  data->localData[0]->realVars[166] /* tankCold.medium.MM variable */ = 0.09143800000000001;
  TRACE_POP
}

/*
equation index: 215
type: SIMPLE_ASSIGN
tankCold.medium.X[1] = 0.5
*/
void Reference_1_eqFunction_215(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,215};
  data->localData[0]->realVars[170] /* tankCold.medium.X[1] variable */ = 0.5;
  TRACE_POP
}

/*
equation index: 216
type: SIMPLE_ASSIGN
tankCold.medium.X[2] = 0.5
*/
void Reference_1_eqFunction_216(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,216};
  data->localData[0]->realVars[171] /* tankCold.medium.X[2] variable */ = 0.5;
  TRACE_POP
}

/*
equation index: 217
type: SIMPLE_ASSIGN
controlCold.PI.I.local_reset = false
*/
void Reference_1_eqFunction_217(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,217};
  data->localData[0]->booleanVars[22] /* controlCold.PI.I.local_reset DISCRETE */ = 0;
  TRACE_POP
}

/*
equation index: 218
type: SIMPLE_ASSIGN
controlCold.PI.I.local_set = 0.0
*/
void Reference_1_eqFunction_218(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,218};
  data->localData[0]->realVars[61] /* controlCold.PI.I.local_set variable */ = 0.0;
  TRACE_POP
}

/*
equation index: 219
type: SIMPLE_ASSIGN
schedule.y = 1.0
*/
void Reference_1_eqFunction_219(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,219};
  data->localData[0]->realVars[157] /* schedule.y variable */ = 1.0;
  TRACE_POP
}

/*
equation index: 220
type: SIMPLE_ASSIGN
powerBlock.cool.nu_q = 1.0
*/
void Reference_1_eqFunction_220(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,220};
  data->localData[0]->realVars[112] /* powerBlock.cool.nu_q variable */ = 1.0;
  TRACE_POP
}

/*
equation index: 221
type: SIMPLE_ASSIGN
controlCold.m_flow_off_input.y = 0.0
*/
void Reference_1_eqFunction_221(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,221};
  data->localData[0]->realVars[72] /* controlCold.m_flow_off_input.y variable */ = 0.0;
  TRACE_POP
}
extern void Reference_1_eqFunction_736(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_737(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_734(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_735(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_731(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_732(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_733(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_728(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_729(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_730(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_725(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_726(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_727(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_722(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_723(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_724(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_720(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_721(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_717(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_718(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_719(DATA *data, threadData_t *threadData);


/*
equation index: 243
type: SIMPLE_ASSIGN
$PRE.data.table.nextTimeEvent = 0.0
*/
void Reference_1_eqFunction_243(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,243};
  data->simulationInfo->realVarsPre[216] /* data.table.nextTimeEvent DISCRETE */ = 0.0;
  TRACE_POP
}

/*
equation index: 244
type: SIMPLE_ASSIGN
$whenCondition1 = time >= $PRE.data.table.nextTimeEvent
*/
void Reference_1_eqFunction_244(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,244};
  modelica_boolean tmp9;
  tmp9 = GreaterEq(data->localData[0]->timeValue,data->simulationInfo->realVarsPre[216] /* data.table.nextTimeEvent DISCRETE */);
  data->localData[0]->booleanVars[0] /* $whenCondition1 DISCRETE */ = tmp9;
  TRACE_POP
}

/*
equation index: 245
type: SIMPLE_ASSIGN
$PRE.prices.nextTimeEvent = 0.0
*/
void Reference_1_eqFunction_245(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,245};
  data->simulationInfo->realVarsPre[219] /* prices.nextTimeEvent DISCRETE */ = 0.0;
  TRACE_POP
}

/*
equation index: 246
type: SIMPLE_ASSIGN
$whenCondition17 = time >= $PRE.prices.nextTimeEvent
*/
void Reference_1_eqFunction_246(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,246};
  modelica_boolean tmp10;
  tmp10 = GreaterEq(data->localData[0]->timeValue,data->simulationInfo->realVarsPre[219] /* prices.nextTimeEvent DISCRETE */);
  data->localData[0]->booleanVars[8] /* $whenCondition17 DISCRETE */ = tmp10;
  TRACE_POP
}

/*
equation index: 247
type: SIMPLE_ASSIGN
powerBlock.E_gross = $START.powerBlock.E_gross
*/
void Reference_1_eqFunction_247(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,247};
  data->localData[0]->realVars[5] /* powerBlock.E_gross STATE(1,powerBlock.W_gross) */ = data->modelData->realVarsData[5].attribute /* powerBlock.E_gross STATE(1,powerBlock.W_gross) */.start;
  TRACE_POP
}

/*
equation index: 248
type: SIMPLE_ASSIGN
powerBlock.E_net = $START.powerBlock.E_net
*/
void Reference_1_eqFunction_248(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,248};
  data->localData[0]->realVars[6] /* powerBlock.E_net STATE(1,P_elec) */ = data->modelData->realVarsData[6].attribute /* powerBlock.E_net STATE(1,P_elec) */.start;
  TRACE_POP
}

/*
equation index: 249
type: SIMPLE_ASSIGN
R_spot = $START.R_spot
*/
void Reference_1_eqFunction_249(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,249};
  data->localData[0]->realVars[0] /* R_spot STATE(1) */ = data->modelData->realVarsData[0].attribute /* R_spot STATE(1) */.start;
  TRACE_POP
}

/*
equation index: 255
type: ALGORITHM

  assert(wea.wtab.tableName <> "NoName", "tableOnFile = true and no table name given");
*/
void Reference_1_eqFunction_255(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,255};
  static const MMC_DEFSTRINGLIT(tmp13,6,"NoName");
  static const MMC_DEFSTRINGLIT(tmp14,42,"tableOnFile = true and no table name given");
  static int tmp15 = 0;
  {
    if(!(!stringEqual(data->simulationInfo->stringParameter[20] /* wea.wtab.tableName PARAM */, MMC_REFSTRINGLIT(tmp13))))
    {
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Blocks/Tables.mo",56,7,57,54,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nwea.wtab.tableName <> \"NoName\"", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_withEquationIndexes(threadData, info, equationIndexes, MMC_STRINGDATA(MMC_REFSTRINGLIT(tmp14)));
      }
    }
  }
  TRACE_POP
}

/*
equation index: 254
type: ALGORITHM

  assert(data.table.tableName <> "NoName", "tableOnFile = true and no table name given");
*/
void Reference_1_eqFunction_254(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,254};
  static const MMC_DEFSTRINGLIT(tmp18,6,"NoName");
  static const MMC_DEFSTRINGLIT(tmp19,42,"tableOnFile = true and no table name given");
  static int tmp20 = 0;
  {
    if(!(!stringEqual(data->simulationInfo->stringParameter[2] /* data.table.tableName PARAM */, MMC_REFSTRINGLIT(tmp18))))
    {
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Blocks/Sources.mo",2205,7,2206,54,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\ndata.table.tableName <> \"NoName\"", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_withEquationIndexes(threadData, info, equationIndexes, MMC_STRINGDATA(MMC_REFSTRINGLIT(tmp19)));
      }
    }
  }
  TRACE_POP
}

/*
equation index: 253
type: ALGORITHM

  assert(heliostatField.optical.nu_table.tableName <> "NoName", "tableOnFile = true and no table name given");
*/
void Reference_1_eqFunction_253(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,253};
  static const MMC_DEFSTRINGLIT(tmp23,6,"NoName");
  static const MMC_DEFSTRINGLIT(tmp24,42,"tableOnFile = true and no table name given");
  static int tmp25 = 0;
  {
    if(!(!stringEqual(data->simulationInfo->stringParameter[5] /* heliostatField.optical.nu_table.tableName PARAM */, MMC_REFSTRINGLIT(tmp23))))
    {
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Blocks/Tables.mo",993,11,994,58,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nheliostatField.optical.nu_table.tableName <> \"NoName\"", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_withEquationIndexes(threadData, info, equationIndexes, MMC_STRINGDATA(MMC_REFSTRINGLIT(tmp24)));
      }
    }
  }
  TRACE_POP
}

/*
equation index: 252
type: ALGORITHM

  assert(controlCold.PI.limiter.uMax >= controlCold.PI.limiter.uMin, "Limiter: Limits must be consistent. However, uMax (=" + String(controlCold.PI.limiter.uMax, 6, 0, true) + ") < uMin (=" + String(controlCold.PI.limiter.uMin, 6, 0, true) + ")");
*/
void Reference_1_eqFunction_252(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,252};
  modelica_boolean tmp26;
  static const MMC_DEFSTRINGLIT(tmp27,52,"Limiter: Limits must be consistent. However, uMax (=");
  modelica_string tmp28;
  static const MMC_DEFSTRINGLIT(tmp29,11,") < uMin (=");
  modelica_string tmp30;
  static int tmp31 = 0;
  modelica_metatype tmpMeta[4] __attribute__((unused)) = {0};
  {
    tmp26 = GreaterEq(data->simulationInfo->realParameter[74] /* controlCold.PI.limiter.uMax PARAM */,data->simulationInfo->realParameter[75] /* controlCold.PI.limiter.uMin PARAM */);
    if(!tmp26)
    {
      tmp28 = modelica_real_to_modelica_string(data->simulationInfo->realParameter[74] /* controlCold.PI.limiter.uMax PARAM */, ((modelica_integer) 6), ((modelica_integer) 0), 1);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp27),tmp28);
      tmpMeta[1] = stringAppend(tmpMeta[0],MMC_REFSTRINGLIT(tmp29));
      tmp30 = modelica_real_to_modelica_string(data->simulationInfo->realParameter[75] /* controlCold.PI.limiter.uMin PARAM */, ((modelica_integer) 6), ((modelica_integer) 0), 1);
      tmpMeta[2] = stringAppend(tmpMeta[1],tmp30);
      tmpMeta[3] = stringAppend(tmpMeta[2],(modelica_string) mmc_strings_len1[41]);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Blocks/Nonlinear.mo",22,9,23,65,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\ncontrolCold.PI.limiter.uMax >= controlCold.PI.limiter.uMin", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_withEquationIndexes(threadData, info, equationIndexes, MMC_STRINGDATA(tmpMeta[3]));
      }
    }
  }
  TRACE_POP
}

/*
equation index: 251
type: ALGORITHM

  assert(prices.tableName <> "NoName", "tableOnFile = true and no table name given");
*/
void Reference_1_eqFunction_251(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,251};
  static const MMC_DEFSTRINGLIT(tmp34,6,"NoName");
  static const MMC_DEFSTRINGLIT(tmp35,42,"tableOnFile = true and no table name given");
  static int tmp36 = 0;
  {
    if(!(!stringEqual(data->simulationInfo->stringParameter[9] /* prices.tableName PARAM */, MMC_REFSTRINGLIT(tmp34))))
    {
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Blocks/Sources.mo",2205,7,2206,54,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nprices.tableName <> \"NoName\"", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_withEquationIndexes(threadData, info, equationIndexes, MMC_STRINGDATA(MMC_REFSTRINGLIT(tmp35)));
      }
    }
  }
  TRACE_POP
}

/*
equation index: 250
type: ALGORITHM

  assert(sch_fixed.daily[1].table.tableName <> "NoName", "tableOnFile = true and no table name given");
*/
void Reference_1_eqFunction_250(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,250};
  static const MMC_DEFSTRINGLIT(tmp39,6,"NoName");
  static const MMC_DEFSTRINGLIT(tmp40,42,"tableOnFile = true and no table name given");
  static int tmp41 = 0;
  {
    if(!(!stringEqual(data->simulationInfo->stringParameter[14] /* sch_fixed.daily[1].table.tableName PARAM */, MMC_REFSTRINGLIT(tmp39))))
    {
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Blocks/Tables.mo",347,7,348,54,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nsch_fixed.daily[1].table.tableName <> \"NoName\"", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_withEquationIndexes(threadData, info, equationIndexes, MMC_STRINGDATA(MMC_REFSTRINGLIT(tmp40)));
      }
    }
  }
  TRACE_POP
}
OMC_DISABLE_OPT
void Reference_1_functionInitialEquations_0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  Reference_1_eqFunction_1(data, threadData);
  Reference_1_eqFunction_2(data, threadData);
  Reference_1_eqFunction_3(data, threadData);
  Reference_1_eqFunction_4(data, threadData);
  Reference_1_eqFunction_5(data, threadData);
  Reference_1_eqFunction_6(data, threadData);
  Reference_1_eqFunction_7(data, threadData);
  Reference_1_eqFunction_8(data, threadData);
  Reference_1_eqFunction_9(data, threadData);
  Reference_1_eqFunction_10(data, threadData);
  Reference_1_eqFunction_11(data, threadData);
  Reference_1_eqFunction_12(data, threadData);
  Reference_1_eqFunction_13(data, threadData);
  Reference_1_eqFunction_14(data, threadData);
  Reference_1_eqFunction_15(data, threadData);
  Reference_1_eqFunction_16(data, threadData);
  Reference_1_eqFunction_505(data, threadData);
  Reference_1_eqFunction_18(data, threadData);
  Reference_1_eqFunction_19(data, threadData);
  Reference_1_eqFunction_20(data, threadData);
  Reference_1_eqFunction_587(data, threadData);
  Reference_1_eqFunction_588(data, threadData);
  Reference_1_eqFunction_589(data, threadData);
  Reference_1_eqFunction_590(data, threadData);
  Reference_1_eqFunction_591(data, threadData);
  Reference_1_eqFunction_592(data, threadData);
  Reference_1_eqFunction_586(data, threadData);
  Reference_1_eqFunction_593(data, threadData);
  Reference_1_eqFunction_596(data, threadData);
  Reference_1_eqFunction_603(data, threadData);
  Reference_1_eqFunction_604(data, threadData);
  Reference_1_eqFunction_506(data, threadData);
  Reference_1_eqFunction_33(data, threadData);
  Reference_1_eqFunction_34(data, threadData);
  Reference_1_eqFunction_594(data, threadData);
  Reference_1_eqFunction_36(data, threadData);
  Reference_1_eqFunction_625(data, threadData);
  Reference_1_eqFunction_38(data, threadData);
  Reference_1_eqFunction_707(data, threadData);
  Reference_1_eqFunction_40(data, threadData);
  Reference_1_eqFunction_41(data, threadData);
  Reference_1_eqFunction_42(data, threadData);
  Reference_1_eqFunction_540(data, threadData);
  Reference_1_eqFunction_541(data, threadData);
  Reference_1_eqFunction_45(data, threadData);
  Reference_1_eqFunction_46(data, threadData);
  Reference_1_eqFunction_546(data, threadData);
  Reference_1_eqFunction_547(data, threadData);
  Reference_1_eqFunction_49(data, threadData);
  Reference_1_eqFunction_550(data, threadData);
  Reference_1_eqFunction_51(data, threadData);
  Reference_1_eqFunction_52(data, threadData);
  Reference_1_eqFunction_555(data, threadData);
  Reference_1_eqFunction_558(data, threadData);
  Reference_1_eqFunction_557(data, threadData);
  Reference_1_eqFunction_556(data, threadData);
  Reference_1_eqFunction_57(data, threadData);
  Reference_1_eqFunction_597(data, threadData);
  Reference_1_eqFunction_598(data, threadData);
  Reference_1_eqFunction_600(data, threadData);
  Reference_1_eqFunction_599(data, threadData);
  Reference_1_eqFunction_62(data, threadData);
  Reference_1_eqFunction_563(data, threadData);
  Reference_1_eqFunction_64(data, threadData);
  Reference_1_eqFunction_65(data, threadData);
  Reference_1_eqFunction_66(data, threadData);
  Reference_1_eqFunction_67(data, threadData);
  Reference_1_eqFunction_68(data, threadData);
  Reference_1_eqFunction_69(data, threadData);
  Reference_1_eqFunction_70(data, threadData);
  Reference_1_eqFunction_71(data, threadData);
  Reference_1_eqFunction_72(data, threadData);
  Reference_1_eqFunction_73(data, threadData);
  Reference_1_eqFunction_675(data, threadData);
  Reference_1_eqFunction_75(data, threadData);
  Reference_1_eqFunction_76(data, threadData);
  Reference_1_eqFunction_679(data, threadData);
  Reference_1_eqFunction_678(data, threadData);
  Reference_1_eqFunction_79(data, threadData);
  Reference_1_eqFunction_80(data, threadData);
  Reference_1_eqFunction_81(data, threadData);
  Reference_1_eqFunction_82(data, threadData);
  Reference_1_eqFunction_83(data, threadData);
  Reference_1_eqFunction_84(data, threadData);
  Reference_1_eqFunction_622(data, threadData);
  Reference_1_eqFunction_608(data, threadData);
  Reference_1_eqFunction_609(data, threadData);
  Reference_1_eqFunction_88(data, threadData);
  Reference_1_eqFunction_89(data, threadData);
  Reference_1_eqFunction_615(data, threadData);
  Reference_1_eqFunction_614(data, threadData);
  Reference_1_eqFunction_621(data, threadData);
  Reference_1_eqFunction_93(data, threadData);
  Reference_1_eqFunction_94(data, threadData);
  Reference_1_eqFunction_95(data, threadData);
  Reference_1_eqFunction_96(data, threadData);
  Reference_1_eqFunction_620(data, threadData);
  Reference_1_eqFunction_98(data, threadData);
  Reference_1_eqFunction_99(data, threadData);
  Reference_1_eqFunction_605(data, threadData);
  Reference_1_eqFunction_101(data, threadData);
  Reference_1_eqFunction_102(data, threadData);
  Reference_1_eqFunction_103(data, threadData);
  Reference_1_eqFunction_104(data, threadData);
  Reference_1_eqFunction_105(data, threadData);
  Reference_1_eqFunction_690(data, threadData);
  Reference_1_eqFunction_630(data, threadData);
  Reference_1_eqFunction_631(data, threadData);
  Reference_1_eqFunction_109(data, threadData);
  Reference_1_eqFunction_110(data, threadData);
  Reference_1_eqFunction_670(data, threadData);
  Reference_1_eqFunction_669(data, threadData);
  Reference_1_eqFunction_689(data, threadData);
  Reference_1_eqFunction_114(data, threadData);
  Reference_1_eqFunction_115(data, threadData);
  Reference_1_eqFunction_636(data, threadData);
  Reference_1_eqFunction_117(data, threadData);
  Reference_1_eqFunction_118(data, threadData);
  Reference_1_eqFunction_688(data, threadData);
  Reference_1_eqFunction_120(data, threadData);
  Reference_1_eqFunction_121(data, threadData);
  Reference_1_eqFunction_122(data, threadData);
  Reference_1_eqFunction_628(data, threadData);
  Reference_1_eqFunction_692(data, threadData);
  Reference_1_eqFunction_693(data, threadData);
  Reference_1_eqFunction_700(data, threadData);
  Reference_1_eqFunction_127(data, threadData);
  Reference_1_eqFunction_128(data, threadData);
  Reference_1_eqFunction_637(data, threadData);
  Reference_1_eqFunction_130(data, threadData);
  Reference_1_eqFunction_642(data, threadData);
  Reference_1_eqFunction_638(data, threadData);
  Reference_1_eqFunction_640(data, threadData);
  Reference_1_eqFunction_639(data, threadData);
  Reference_1_eqFunction_641(data, threadData);
  Reference_1_eqFunction_136(data, threadData);
  Reference_1_eqFunction_137(data, threadData);
  Reference_1_eqFunction_149(data, threadData);
  Reference_1_eqFunction_663(data, threadData);
  Reference_1_eqFunction_664(data, threadData);
  Reference_1_eqFunction_665(data, threadData);
  Reference_1_eqFunction_666(data, threadData);
  Reference_1_eqFunction_658(data, threadData);
  Reference_1_eqFunction_659(data, threadData);
  Reference_1_eqFunction_660(data, threadData);
  Reference_1_eqFunction_661(data, threadData);
  Reference_1_eqFunction_662(data, threadData);
  Reference_1_eqFunction_667(data, threadData);
  Reference_1_eqFunction_657(data, threadData);
  Reference_1_eqFunction_656(data, threadData);
  Reference_1_eqFunction_676(data, threadData);
  Reference_1_eqFunction_673(data, threadData);
  Reference_1_eqFunction_164(data, threadData);
  Reference_1_eqFunction_165(data, threadData);
  Reference_1_eqFunction_166(data, threadData);
  Reference_1_eqFunction_167(data, threadData);
  Reference_1_eqFunction_168(data, threadData);
  Reference_1_eqFunction_507(data, threadData);
  Reference_1_eqFunction_170(data, threadData);
  Reference_1_eqFunction_509(data, threadData);
  Reference_1_eqFunction_682(data, threadData);
  Reference_1_eqFunction_687(data, threadData);
  Reference_1_eqFunction_174(data, threadData);
  Reference_1_eqFunction_683(data, threadData);
  Reference_1_eqFunction_708(data, threadData);
  Reference_1_eqFunction_686(data, threadData);
  Reference_1_eqFunction_684(data, threadData);
  Reference_1_eqFunction_685(data, threadData);
  Reference_1_eqFunction_701(data, threadData);
  Reference_1_eqFunction_694(data, threadData);
  Reference_1_eqFunction_695(data, threadData);
  Reference_1_eqFunction_702(data, threadData);
  Reference_1_eqFunction_184(data, threadData);
  Reference_1_eqFunction_703(data, threadData);
  Reference_1_eqFunction_709(data, threadData);
  Reference_1_eqFunction_710(data, threadData);
  Reference_1_eqFunction_713(data, threadData);
  Reference_1_eqFunction_712(data, threadData);
  Reference_1_eqFunction_711(data, threadData);
  Reference_1_eqFunction_697(data, threadData);
  Reference_1_eqFunction_192(data, threadData);
  Reference_1_eqFunction_698(data, threadData);
  Reference_1_eqFunction_194(data, threadData);
  Reference_1_eqFunction_511(data, threadData);
  Reference_1_eqFunction_196(data, threadData);
  Reference_1_eqFunction_513(data, threadData);
  Reference_1_eqFunction_198(data, threadData);
  Reference_1_eqFunction_514(data, threadData);
  Reference_1_eqFunction_200(data, threadData);
  Reference_1_eqFunction_201(data, threadData);
  Reference_1_eqFunction_529(data, threadData);
  Reference_1_eqFunction_203(data, threadData);
  Reference_1_eqFunction_204(data, threadData);
  Reference_1_eqFunction_205(data, threadData);
  Reference_1_eqFunction_530(data, threadData);
  Reference_1_eqFunction_207(data, threadData);
  Reference_1_eqFunction_533(data, threadData);
  Reference_1_eqFunction_209(data, threadData);
  Reference_1_eqFunction_579(data, threadData);
  Reference_1_eqFunction_211(data, threadData);
  Reference_1_eqFunction_580(data, threadData);
  Reference_1_eqFunction_213(data, threadData);
  Reference_1_eqFunction_214(data, threadData);
  Reference_1_eqFunction_215(data, threadData);
  Reference_1_eqFunction_216(data, threadData);
  Reference_1_eqFunction_217(data, threadData);
  Reference_1_eqFunction_218(data, threadData);
  Reference_1_eqFunction_219(data, threadData);
  Reference_1_eqFunction_220(data, threadData);
  Reference_1_eqFunction_221(data, threadData);
  Reference_1_eqFunction_736(data, threadData);
  Reference_1_eqFunction_737(data, threadData);
  Reference_1_eqFunction_734(data, threadData);
  Reference_1_eqFunction_735(data, threadData);
  Reference_1_eqFunction_731(data, threadData);
  Reference_1_eqFunction_732(data, threadData);
  Reference_1_eqFunction_733(data, threadData);
  Reference_1_eqFunction_728(data, threadData);
  Reference_1_eqFunction_729(data, threadData);
  Reference_1_eqFunction_730(data, threadData);
  Reference_1_eqFunction_725(data, threadData);
  Reference_1_eqFunction_726(data, threadData);
  Reference_1_eqFunction_727(data, threadData);
  Reference_1_eqFunction_722(data, threadData);
  Reference_1_eqFunction_723(data, threadData);
  Reference_1_eqFunction_724(data, threadData);
  Reference_1_eqFunction_720(data, threadData);
  Reference_1_eqFunction_721(data, threadData);
  Reference_1_eqFunction_717(data, threadData);
  Reference_1_eqFunction_718(data, threadData);
  Reference_1_eqFunction_719(data, threadData);
  Reference_1_eqFunction_243(data, threadData);
  Reference_1_eqFunction_244(data, threadData);
  Reference_1_eqFunction_245(data, threadData);
  Reference_1_eqFunction_246(data, threadData);
  Reference_1_eqFunction_247(data, threadData);
  Reference_1_eqFunction_248(data, threadData);
  Reference_1_eqFunction_249(data, threadData);
  Reference_1_eqFunction_255(data, threadData);
  Reference_1_eqFunction_254(data, threadData);
  Reference_1_eqFunction_253(data, threadData);
  Reference_1_eqFunction_252(data, threadData);
  Reference_1_eqFunction_251(data, threadData);
  Reference_1_eqFunction_250(data, threadData);
  TRACE_POP
}

int Reference_1_functionInitialEquations(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->discreteCall = 1;
  Reference_1_functionInitialEquations_0(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
  TRACE_POP
  return 0;
}
extern void Reference_1_eqFunction_1(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_2(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_3(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_4(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_5(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_6(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_7(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_8(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_9(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_10(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_11(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_12(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_13(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_14(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_15(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_16(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_505(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_18(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_19(DATA *data, threadData_t *threadData);


/*
equation index: 275
type: ALGORITHM

  (sun.dec, sun.hra) := SolarTherm.Models.Sources.SolarModel.Sun$sun.solarPosition(time, sun.lon, sun.lat, sun.t_zone, sun.year);
*/
void Reference_1_eqFunction_275(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,275};
  data->localData[0]->realVars[158] /* sun.dec variable */ = omc_SolarTherm_Models_Sources_SolarModel__omcQSun_24sun_solarPosition(threadData, data->localData[0]->timeValue, data->simulationInfo->realParameter[248] /* sun.lon PARAM */, data->simulationInfo->realParameter[247] /* sun.lat PARAM */, data->simulationInfo->realParameter[249] /* sun.t_zone PARAM */, data->simulationInfo->integerParameter[76] /* sun.year PARAM */ ,&data->localData[0]->realVars[160] /* sun.hra variable */);
  TRACE_POP
}
extern void Reference_1_eqFunction_587(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_588(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_589(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_590(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_591(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_592(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_586(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_593(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_596(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_603(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_604(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_506(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_33(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_34(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_594(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_36(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_625(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_38(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_707(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_40(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_41(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_42(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_540(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_541(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_45(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_46(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_546(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_547(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_49(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_550(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_51(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_52(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_555(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_558(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_557(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_556(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_57(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_597(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_598(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_600(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_599(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_62(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_563(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_64(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_65(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_66(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_67(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_68(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_69(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_70(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_71(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_72(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_73(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_675(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_75(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_76(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_679(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_678(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_79(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_80(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_81(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_82(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_83(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_84(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_622(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_608(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_609(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_88(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_89(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_615(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_614(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_621(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_93(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_94(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_95(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_96(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_620(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_98(DATA *data, threadData_t *threadData);


/*
equation index: 354
type: ALGORITHM

  $whenCondition19 := $START.$whenCondition19;
  $whenCondition18 := $START.$whenCondition18;
  $whenCondition18 := tankCold.medium.T < tankCold.T_set;
  $whenCondition19 := tankCold.medium.T > 1.0 + tankCold.T_set;
*/
void Reference_1_eqFunction_354(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,354};
  modelica_boolean tmp0;
  modelica_boolean tmp1;
  data->localData[0]->booleanVars[10] /* $whenCondition19 DISCRETE */ = data->modelData->booleanVarsData[10].attribute /* $whenCondition19 DISCRETE */.start;

  data->localData[0]->booleanVars[9] /* $whenCondition18 DISCRETE */ = data->modelData->booleanVarsData[9].attribute /* $whenCondition18 DISCRETE */.start;

  tmp0 = Less(data->localData[0]->realVars[168] /* tankCold.medium.T variable */,data->simulationInfo->realParameter[256] /* tankCold.T_set PARAM */);
  data->localData[0]->booleanVars[9] /* $whenCondition18 DISCRETE */ = tmp0;

  tmp1 = Greater(data->localData[0]->realVars[168] /* tankCold.medium.T variable */,1.0 + data->simulationInfo->realParameter[256] /* tankCold.T_set PARAM */);
  data->localData[0]->booleanVars[10] /* $whenCondition19 DISCRETE */ = tmp1;
  TRACE_POP
}
extern void Reference_1_eqFunction_605(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_101(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_102(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_103(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_104(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_105(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_690(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_630(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_631(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_109(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_110(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_670(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_669(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_689(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_114(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_115(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_636(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_117(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_118(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_688(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_120(DATA *data, threadData_t *threadData);


/*
equation index: 376
type: ALGORITHM

  $whenCondition21 := $START.$whenCondition21;
  $whenCondition20 := $START.$whenCondition20;
  $whenCondition20 := tankHot.medium.T < tankHot.T_set;
  $whenCondition21 := tankHot.medium.T > 1.0 + tankHot.T_set;
*/
void Reference_1_eqFunction_376(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,376};
  modelica_boolean tmp2;
  modelica_boolean tmp3;
  data->localData[0]->booleanVars[13] /* $whenCondition21 DISCRETE */ = data->modelData->booleanVarsData[13].attribute /* $whenCondition21 DISCRETE */.start;

  data->localData[0]->booleanVars[12] /* $whenCondition20 DISCRETE */ = data->modelData->booleanVarsData[12].attribute /* $whenCondition20 DISCRETE */.start;

  tmp2 = Less(data->localData[0]->realVars[184] /* tankHot.medium.T variable */,data->simulationInfo->realParameter[266] /* tankHot.T_set PARAM */);
  data->localData[0]->booleanVars[12] /* $whenCondition20 DISCRETE */ = tmp2;

  tmp3 = Greater(data->localData[0]->realVars[184] /* tankHot.medium.T variable */,1.0 + data->simulationInfo->realParameter[266] /* tankHot.T_set PARAM */);
  data->localData[0]->booleanVars[13] /* $whenCondition21 DISCRETE */ = tmp3;
  TRACE_POP
}
extern void Reference_1_eqFunction_122(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_628(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_692(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_693(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_700(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_127(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_128(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_637(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_130(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_642(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_638(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_640(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_639(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_641(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_136(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_137(DATA *data, threadData_t *threadData);


void Reference_1_eqFunction_393(DATA*, threadData_t*);
void Reference_1_eqFunction_394(DATA*, threadData_t*);
void Reference_1_eqFunction_395(DATA*, threadData_t*);
void Reference_1_eqFunction_396(DATA*, threadData_t*);
void Reference_1_eqFunction_397(DATA*, threadData_t*);
void Reference_1_eqFunction_398(DATA*, threadData_t*);
void Reference_1_eqFunction_399(DATA*, threadData_t*);
void Reference_1_eqFunction_400(DATA*, threadData_t*);
void Reference_1_eqFunction_401(DATA*, threadData_t*);
void Reference_1_eqFunction_402(DATA*, threadData_t*);
void Reference_1_eqFunction_403(DATA*, threadData_t*);
/*
equation index: 404
indexNonlinear: 1
type: NONLINEAR

vars: {receiver.h_out}
eqns: {393, 394, 395, 396, 397, 398, 399, 400, 401, 402, 403}
*/
void Reference_1_eqFunction_404(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,404};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 404 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[1].nlsxOld[0] = data->simulationInfo->realParameter[233] /* receiver.h_0 PARAM */;
  retValue = solve_nonlinear_system(data, threadData, 1);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,404};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving non-linear system 404 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->localData[0]->realVars[131] /* receiver.h_out variable */ = data->simulationInfo->nonlinearSystemData[1].nlsx[0];
  TRACE_POP
}
extern void Reference_1_eqFunction_663(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_664(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_665(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_666(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_658(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_659(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_660(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_661(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_662(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_667(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_657(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_656(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_676(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_673(DATA *data, threadData_t *threadData);


/*
equation index: 419
type: ALGORITHM

  wea.meta := SolarTherm.Models.Sources.Weather.getMetadata(wea.file_act);
*/
void Reference_1_eqFunction_419(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,419};
  SolarTherm_Models_Sources_Weather_Metadata tmp0;
  tmp0 = omc_SolarTherm_Models_Sources_Weather_getMetadata(threadData, data->simulationInfo->stringParameter[17] /* wea.file_act PARAM */);
  data->simulationInfo->stringParameter[18] /* wea.meta.name PARAM */ = tmp0._name;
  data->simulationInfo->realParameter[296] /* wea.meta.lat PARAM */ = tmp0._lat;
  data->simulationInfo->realParameter[297] /* wea.meta.lon PARAM */ = tmp0._lon;
  data->simulationInfo->realParameter[295] /* wea.meta.elev PARAM */ = tmp0._elev;
  data->simulationInfo->realParameter[299] /* wea.meta.tzone PARAM */ = tmp0._tzone;
  data->simulationInfo->realParameter[298] /* wea.meta.tstart PARAM */ = tmp0._tstart;
  ;
  TRACE_POP
}
extern void Reference_1_eqFunction_165(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_166(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_167(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_168(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_507(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_170(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_509(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_682(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_687(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_174(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_683(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_708(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_686(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_684(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_685(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_701(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_694(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_695(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_702(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_184(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_703(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_709(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_710(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_713(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_712(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_711(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_697(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_192(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_698(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_194(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_511(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_196(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_513(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_198(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_514(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_200(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_201(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_529(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_203(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_204(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_205(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_530(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_207(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_533(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_209(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_579(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_211(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_580(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_213(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_214(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_215(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_216(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_217(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_218(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_219(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_220(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_221(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_736(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_737(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_734(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_735(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_731(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_732(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_733(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_728(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_729(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_730(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_725(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_726(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_727(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_722(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_723(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_724(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_720(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_721(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_717(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_718(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_719(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_243(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_244(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_245(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_246(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_247(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_248(DATA *data, threadData_t *threadData);

extern void Reference_1_eqFunction_249(DATA *data, threadData_t *threadData);

int Reference_1_functionInitialEquations_lambda0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->discreteCall = 1;
  Reference_1_eqFunction_1(data, threadData);

  Reference_1_eqFunction_2(data, threadData);

  Reference_1_eqFunction_3(data, threadData);

  Reference_1_eqFunction_4(data, threadData);

  Reference_1_eqFunction_5(data, threadData);

  Reference_1_eqFunction_6(data, threadData);

  Reference_1_eqFunction_7(data, threadData);

  Reference_1_eqFunction_8(data, threadData);

  Reference_1_eqFunction_9(data, threadData);

  Reference_1_eqFunction_10(data, threadData);

  Reference_1_eqFunction_11(data, threadData);

  Reference_1_eqFunction_12(data, threadData);

  Reference_1_eqFunction_13(data, threadData);

  Reference_1_eqFunction_14(data, threadData);

  Reference_1_eqFunction_15(data, threadData);

  Reference_1_eqFunction_16(data, threadData);

  Reference_1_eqFunction_505(data, threadData);

  Reference_1_eqFunction_18(data, threadData);

  Reference_1_eqFunction_19(data, threadData);

  Reference_1_eqFunction_275(data, threadData);

  Reference_1_eqFunction_587(data, threadData);

  Reference_1_eqFunction_588(data, threadData);

  Reference_1_eqFunction_589(data, threadData);

  Reference_1_eqFunction_590(data, threadData);

  Reference_1_eqFunction_591(data, threadData);

  Reference_1_eqFunction_592(data, threadData);

  Reference_1_eqFunction_586(data, threadData);

  Reference_1_eqFunction_593(data, threadData);

  Reference_1_eqFunction_596(data, threadData);

  Reference_1_eqFunction_603(data, threadData);

  Reference_1_eqFunction_604(data, threadData);

  Reference_1_eqFunction_506(data, threadData);

  Reference_1_eqFunction_33(data, threadData);

  Reference_1_eqFunction_34(data, threadData);

  Reference_1_eqFunction_594(data, threadData);

  Reference_1_eqFunction_36(data, threadData);

  Reference_1_eqFunction_625(data, threadData);

  Reference_1_eqFunction_38(data, threadData);

  Reference_1_eqFunction_707(data, threadData);

  Reference_1_eqFunction_40(data, threadData);

  Reference_1_eqFunction_41(data, threadData);

  Reference_1_eqFunction_42(data, threadData);

  Reference_1_eqFunction_540(data, threadData);

  Reference_1_eqFunction_541(data, threadData);

  Reference_1_eqFunction_45(data, threadData);

  Reference_1_eqFunction_46(data, threadData);

  Reference_1_eqFunction_546(data, threadData);

  Reference_1_eqFunction_547(data, threadData);

  Reference_1_eqFunction_49(data, threadData);

  Reference_1_eqFunction_550(data, threadData);

  Reference_1_eqFunction_51(data, threadData);

  Reference_1_eqFunction_52(data, threadData);

  Reference_1_eqFunction_555(data, threadData);

  Reference_1_eqFunction_558(data, threadData);

  Reference_1_eqFunction_557(data, threadData);

  Reference_1_eqFunction_556(data, threadData);

  Reference_1_eqFunction_57(data, threadData);

  Reference_1_eqFunction_597(data, threadData);

  Reference_1_eqFunction_598(data, threadData);

  Reference_1_eqFunction_600(data, threadData);

  Reference_1_eqFunction_599(data, threadData);

  Reference_1_eqFunction_62(data, threadData);

  Reference_1_eqFunction_563(data, threadData);

  Reference_1_eqFunction_64(data, threadData);

  Reference_1_eqFunction_65(data, threadData);

  Reference_1_eqFunction_66(data, threadData);

  Reference_1_eqFunction_67(data, threadData);

  Reference_1_eqFunction_68(data, threadData);

  Reference_1_eqFunction_69(data, threadData);

  Reference_1_eqFunction_70(data, threadData);

  Reference_1_eqFunction_71(data, threadData);

  Reference_1_eqFunction_72(data, threadData);

  Reference_1_eqFunction_73(data, threadData);

  Reference_1_eqFunction_675(data, threadData);

  Reference_1_eqFunction_75(data, threadData);

  Reference_1_eqFunction_76(data, threadData);

  Reference_1_eqFunction_679(data, threadData);

  Reference_1_eqFunction_678(data, threadData);

  Reference_1_eqFunction_79(data, threadData);

  Reference_1_eqFunction_80(data, threadData);

  Reference_1_eqFunction_81(data, threadData);

  Reference_1_eqFunction_82(data, threadData);

  Reference_1_eqFunction_83(data, threadData);

  Reference_1_eqFunction_84(data, threadData);

  Reference_1_eqFunction_622(data, threadData);

  Reference_1_eqFunction_608(data, threadData);

  Reference_1_eqFunction_609(data, threadData);

  Reference_1_eqFunction_88(data, threadData);

  Reference_1_eqFunction_89(data, threadData);

  Reference_1_eqFunction_615(data, threadData);

  Reference_1_eqFunction_614(data, threadData);

  Reference_1_eqFunction_621(data, threadData);

  Reference_1_eqFunction_93(data, threadData);

  Reference_1_eqFunction_94(data, threadData);

  Reference_1_eqFunction_95(data, threadData);

  Reference_1_eqFunction_96(data, threadData);

  Reference_1_eqFunction_620(data, threadData);

  Reference_1_eqFunction_98(data, threadData);

  Reference_1_eqFunction_354(data, threadData);

  Reference_1_eqFunction_605(data, threadData);

  Reference_1_eqFunction_101(data, threadData);

  Reference_1_eqFunction_102(data, threadData);

  Reference_1_eqFunction_103(data, threadData);

  Reference_1_eqFunction_104(data, threadData);

  Reference_1_eqFunction_105(data, threadData);

  Reference_1_eqFunction_690(data, threadData);

  Reference_1_eqFunction_630(data, threadData);

  Reference_1_eqFunction_631(data, threadData);

  Reference_1_eqFunction_109(data, threadData);

  Reference_1_eqFunction_110(data, threadData);

  Reference_1_eqFunction_670(data, threadData);

  Reference_1_eqFunction_669(data, threadData);

  Reference_1_eqFunction_689(data, threadData);

  Reference_1_eqFunction_114(data, threadData);

  Reference_1_eqFunction_115(data, threadData);

  Reference_1_eqFunction_636(data, threadData);

  Reference_1_eqFunction_117(data, threadData);

  Reference_1_eqFunction_118(data, threadData);

  Reference_1_eqFunction_688(data, threadData);

  Reference_1_eqFunction_120(data, threadData);

  Reference_1_eqFunction_376(data, threadData);

  Reference_1_eqFunction_122(data, threadData);

  Reference_1_eqFunction_628(data, threadData);

  Reference_1_eqFunction_692(data, threadData);

  Reference_1_eqFunction_693(data, threadData);

  Reference_1_eqFunction_700(data, threadData);

  Reference_1_eqFunction_127(data, threadData);

  Reference_1_eqFunction_128(data, threadData);

  Reference_1_eqFunction_637(data, threadData);

  Reference_1_eqFunction_130(data, threadData);

  Reference_1_eqFunction_642(data, threadData);

  Reference_1_eqFunction_638(data, threadData);

  Reference_1_eqFunction_640(data, threadData);

  Reference_1_eqFunction_639(data, threadData);

  Reference_1_eqFunction_641(data, threadData);

  Reference_1_eqFunction_136(data, threadData);

  Reference_1_eqFunction_137(data, threadData);

  Reference_1_eqFunction_404(data, threadData);

  Reference_1_eqFunction_663(data, threadData);

  Reference_1_eqFunction_664(data, threadData);

  Reference_1_eqFunction_665(data, threadData);

  Reference_1_eqFunction_666(data, threadData);

  Reference_1_eqFunction_658(data, threadData);

  Reference_1_eqFunction_659(data, threadData);

  Reference_1_eqFunction_660(data, threadData);

  Reference_1_eqFunction_661(data, threadData);

  Reference_1_eqFunction_662(data, threadData);

  Reference_1_eqFunction_667(data, threadData);

  Reference_1_eqFunction_657(data, threadData);

  Reference_1_eqFunction_656(data, threadData);

  Reference_1_eqFunction_676(data, threadData);

  Reference_1_eqFunction_673(data, threadData);

  Reference_1_eqFunction_419(data, threadData);

  Reference_1_eqFunction_165(data, threadData);

  Reference_1_eqFunction_166(data, threadData);

  Reference_1_eqFunction_167(data, threadData);

  Reference_1_eqFunction_168(data, threadData);

  Reference_1_eqFunction_507(data, threadData);

  Reference_1_eqFunction_170(data, threadData);

  Reference_1_eqFunction_509(data, threadData);

  Reference_1_eqFunction_682(data, threadData);

  Reference_1_eqFunction_687(data, threadData);

  Reference_1_eqFunction_174(data, threadData);

  Reference_1_eqFunction_683(data, threadData);

  Reference_1_eqFunction_708(data, threadData);

  Reference_1_eqFunction_686(data, threadData);

  Reference_1_eqFunction_684(data, threadData);

  Reference_1_eqFunction_685(data, threadData);

  Reference_1_eqFunction_701(data, threadData);

  Reference_1_eqFunction_694(data, threadData);

  Reference_1_eqFunction_695(data, threadData);

  Reference_1_eqFunction_702(data, threadData);

  Reference_1_eqFunction_184(data, threadData);

  Reference_1_eqFunction_703(data, threadData);

  Reference_1_eqFunction_709(data, threadData);

  Reference_1_eqFunction_710(data, threadData);

  Reference_1_eqFunction_713(data, threadData);

  Reference_1_eqFunction_712(data, threadData);

  Reference_1_eqFunction_711(data, threadData);

  Reference_1_eqFunction_697(data, threadData);

  Reference_1_eqFunction_192(data, threadData);

  Reference_1_eqFunction_698(data, threadData);

  Reference_1_eqFunction_194(data, threadData);

  Reference_1_eqFunction_511(data, threadData);

  Reference_1_eqFunction_196(data, threadData);

  Reference_1_eqFunction_513(data, threadData);

  Reference_1_eqFunction_198(data, threadData);

  Reference_1_eqFunction_514(data, threadData);

  Reference_1_eqFunction_200(data, threadData);

  Reference_1_eqFunction_201(data, threadData);

  Reference_1_eqFunction_529(data, threadData);

  Reference_1_eqFunction_203(data, threadData);

  Reference_1_eqFunction_204(data, threadData);

  Reference_1_eqFunction_205(data, threadData);

  Reference_1_eqFunction_530(data, threadData);

  Reference_1_eqFunction_207(data, threadData);

  Reference_1_eqFunction_533(data, threadData);

  Reference_1_eqFunction_209(data, threadData);

  Reference_1_eqFunction_579(data, threadData);

  Reference_1_eqFunction_211(data, threadData);

  Reference_1_eqFunction_580(data, threadData);

  Reference_1_eqFunction_213(data, threadData);

  Reference_1_eqFunction_214(data, threadData);

  Reference_1_eqFunction_215(data, threadData);

  Reference_1_eqFunction_216(data, threadData);

  Reference_1_eqFunction_217(data, threadData);

  Reference_1_eqFunction_218(data, threadData);

  Reference_1_eqFunction_219(data, threadData);

  Reference_1_eqFunction_220(data, threadData);

  Reference_1_eqFunction_221(data, threadData);

  Reference_1_eqFunction_736(data, threadData);

  Reference_1_eqFunction_737(data, threadData);

  Reference_1_eqFunction_734(data, threadData);

  Reference_1_eqFunction_735(data, threadData);

  Reference_1_eqFunction_731(data, threadData);

  Reference_1_eqFunction_732(data, threadData);

  Reference_1_eqFunction_733(data, threadData);

  Reference_1_eqFunction_728(data, threadData);

  Reference_1_eqFunction_729(data, threadData);

  Reference_1_eqFunction_730(data, threadData);

  Reference_1_eqFunction_725(data, threadData);

  Reference_1_eqFunction_726(data, threadData);

  Reference_1_eqFunction_727(data, threadData);

  Reference_1_eqFunction_722(data, threadData);

  Reference_1_eqFunction_723(data, threadData);

  Reference_1_eqFunction_724(data, threadData);

  Reference_1_eqFunction_720(data, threadData);

  Reference_1_eqFunction_721(data, threadData);

  Reference_1_eqFunction_717(data, threadData);

  Reference_1_eqFunction_718(data, threadData);

  Reference_1_eqFunction_719(data, threadData);

  Reference_1_eqFunction_243(data, threadData);

  Reference_1_eqFunction_244(data, threadData);

  Reference_1_eqFunction_245(data, threadData);

  Reference_1_eqFunction_246(data, threadData);

  Reference_1_eqFunction_247(data, threadData);

  Reference_1_eqFunction_248(data, threadData);

  Reference_1_eqFunction_249(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
  TRACE_POP
  return 0;
}
int Reference_1_functionRemovedInitialEquations(DATA *data, threadData_t *threadData)
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

