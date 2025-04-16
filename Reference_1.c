/* Main Simulation File */

#if defined(__cplusplus)
extern "C" {
#endif

#include "Reference_1_model.h"
#include "simulation/solver/events.h"

#define prefixedName_performSimulation Reference_1_performSimulation
#define prefixedName_updateContinuousSystem Reference_1_updateContinuousSystem
#include <simulation/solver/perform_simulation.c.inc>

#define prefixedName_performQSSSimulation Reference_1_performQSSSimulation
#include <simulation/solver/perform_qss_simulation.c.inc>


/* dummy VARINFO and FILEINFO */
const FILE_INFO dummyFILE_INFO = omc_dummyFileInfo;
const VAR_INFO dummyVAR_INFO = omc_dummyVarInfo;

int Reference_1_input_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int Reference_1_input_function_init(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int Reference_1_input_function_updateStartValues(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int Reference_1_inputNames(DATA *data, char ** names){
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int Reference_1_data_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  TRACE_POP
  return 0;
}

int Reference_1_dataReconciliationInputNames(DATA *data, char ** names){
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int Reference_1_output_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int Reference_1_setc_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}


/*
equation index: 505
type: SIMPLE_ASSIGN
prices.timeScaled = time
*/
void Reference_1_eqFunction_505(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,505};
  data->localData[0]->realVars[122] /* prices.timeScaled variable */ = data->localData[0]->timeValue;
  TRACE_POP
}
/*
equation index: 506
type: SIMPLE_ASSIGN
data.table.timeScaled = time
*/
void Reference_1_eqFunction_506(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,506};
  data->localData[0]->realVars[83] /* data.table.timeScaled variable */ = data->localData[0]->timeValue;
  TRACE_POP
}
/*
equation index: 507
type: SIMPLE_ASSIGN
sch_fixed.wbus.t = time + wea.date.toyoffset
*/
void Reference_1_eqFunction_507(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,507};
  data->localData[0]->realVars[153] /* sch_fixed.wbus.t variable */ = data->localData[0]->timeValue + data->simulationInfo->realParameter[284] /* wea.date.toyoffset PARAM */;
  TRACE_POP
}
/*
equation index: 508
type: SIMPLE_ASSIGN
sch_fixed.daily[1].t = mod(sch_fixed.wbus.t, 86400.0, 0)
*/
void Reference_1_eqFunction_508(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,508};
  data->localData[0]->realVars[143] /* sch_fixed.daily[1].t variable */ = _event_mod_real(data->localData[0]->realVars[153] /* sch_fixed.wbus.t variable */, 86400.0, ((modelica_integer) 0), data, threadData);
  TRACE_POP
}
/*
equation index: 509
type: SIMPLE_ASSIGN
controlHot.schedule = Modelica.Blocks.Tables.Internal.getTable1DValueNoDer(sch_fixed.daily[1].table.tableID, 1, sch_fixed.daily[1].t)
*/
void Reference_1_eqFunction_509(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,509};
  data->localData[0]->realVars[76] /* controlHot.schedule variable */ = omc_Modelica_Blocks_Tables_Internal_getTable1DValueNoDer(threadData, data->simulationInfo->extObjs[3], ((modelica_integer) 1), data->localData[0]->realVars[143] /* sch_fixed.daily[1].t variable */);
  TRACE_POP
}
/*
equation index: 510
type: SIMPLE_ASSIGN
sch_fixed.week[1].i = 1 + integer(mod(1.157407407407407e-05 * sch_fixed.wbus.t, 7.0, 3), 2)
*/
void Reference_1_eqFunction_510(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,510};
  data->localData[0]->integerVars[2] /* sch_fixed.week[1].i DISCRETE */ = ((modelica_integer) 1) + (_event_integer(_event_mod_real((1.157407407407407e-05) * (data->localData[0]->realVars[153] /* sch_fixed.wbus.t variable */), 7.0, ((modelica_integer) 3), data, threadData), ((modelica_integer) 2), data));
  TRACE_POP
}
/*
equation index: 511
type: SIMPLE_ASSIGN
sch_fixed.week[1].j = sch_fixed.week[1].map[sch_fixed.week[1].i]
*/
void Reference_1_eqFunction_511(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,511};
  data->localData[0]->integerVars[3] /* sch_fixed.week[1].j DISCRETE */ = (&data->simulationInfo->integerParameter[62] /* sch_fixed.week[1].map[1] PARAM */)[calc_base_index_dims_subs(2, (_index_t)1, (_index_t)7, ((modelica_integer) 1), data->localData[0]->integerVars[2] /* sch_fixed.week[1].i DISCRETE */)];
  TRACE_POP
}
/*
equation index: 512
type: SIMPLE_ASSIGN
sch_fixed.month.i = 1 + integer(mod(3.80517503805175e-07 * sch_fixed.wbus.t, 12.0, 6), 5)
*/
void Reference_1_eqFunction_512(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,512};
  data->localData[0]->integerVars[0] /* sch_fixed.month.i DISCRETE */ = ((modelica_integer) 1) + (_event_integer(_event_mod_real((3.80517503805175e-07) * (data->localData[0]->realVars[153] /* sch_fixed.wbus.t variable */), 12.0, ((modelica_integer) 6), data, threadData), ((modelica_integer) 5), data));
  TRACE_POP
}
/*
equation index: 513
type: SIMPLE_ASSIGN
sch_fixed.month.j = sch_fixed.month.map[sch_fixed.month.i]
*/
void Reference_1_eqFunction_513(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,513};
  data->localData[0]->integerVars[1] /* sch_fixed.month.j DISCRETE */ = (&data->simulationInfo->integerParameter[48] /* sch_fixed.month.map[1] PARAM */)[calc_base_index_dims_subs(1, (_index_t)12, data->localData[0]->integerVars[0] /* sch_fixed.month.i DISCRETE */)];
  TRACE_POP
}
/*
equation index: 514
type: SIMPLE_ASSIGN
wea.spos.B = 0.0007172585967099984 * (-12.0 + 0.0002777777777777778 * sch_fixed.wbus.t - wea.spos.tzone)
*/
void Reference_1_eqFunction_514(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,514};
  data->localData[0]->realVars[193] /* wea.spos.B variable */ = (0.0007172585967099984) * (-12.0 + (0.0002777777777777778) * (data->localData[0]->realVars[153] /* sch_fixed.wbus.t variable */) - data->simulationInfo->realParameter[302] /* wea.spos.tzone PARAM */);
  TRACE_POP
}
/*
equation index: 515
type: SIMPLE_ASSIGN
$cse34 = sin(3.0 * wea.spos.B)
*/
void Reference_1_eqFunction_515(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,515};
  data->localData[0]->realVars[49] /* $cse34 variable */ = sin((3.0) * (data->localData[0]->realVars[193] /* wea.spos.B variable */));
  TRACE_POP
}
/*
equation index: 516
type: SIMPLE_ASSIGN
$cse33 = cos(3.0 * wea.spos.B)
*/
void Reference_1_eqFunction_516(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,516};
  data->localData[0]->realVars[48] /* $cse33 variable */ = cos((3.0) * (data->localData[0]->realVars[193] /* wea.spos.B variable */));
  TRACE_POP
}
/*
equation index: 517
type: SIMPLE_ASSIGN
$cse32 = sin(2.0 * wea.spos.B)
*/
void Reference_1_eqFunction_517(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,517};
  data->localData[0]->realVars[47] /* $cse32 variable */ = sin((2.0) * (data->localData[0]->realVars[193] /* wea.spos.B variable */));
  TRACE_POP
}
/*
equation index: 518
type: SIMPLE_ASSIGN
$cse31 = cos(2.0 * wea.spos.B)
*/
void Reference_1_eqFunction_518(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,518};
  data->localData[0]->realVars[46] /* $cse31 variable */ = cos((2.0) * (data->localData[0]->realVars[193] /* wea.spos.B variable */));
  TRACE_POP
}
/*
equation index: 519
type: SIMPLE_ASSIGN
$cse30 = sin(wea.spos.B)
*/
void Reference_1_eqFunction_519(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,519};
  data->localData[0]->realVars[45] /* $cse30 variable */ = sin(data->localData[0]->realVars[193] /* wea.spos.B variable */);
  TRACE_POP
}
/*
equation index: 520
type: SIMPLE_ASSIGN
$cse29 = cos(wea.spos.B)
*/
void Reference_1_eqFunction_520(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,520};
  data->localData[0]->realVars[43] /* $cse29 variable */ = cos(data->localData[0]->realVars[193] /* wea.spos.B variable */);
  TRACE_POP
}
/*
equation index: 521
type: SIMPLE_ASSIGN
wea.spos.E = 3.82 * (7.499999999999999e-05 + 0.001868 * $cse29 + (-0.032077) * $cse30 + (-0.014615) * $cse31 + (-0.04089) * $cse32)
*/
void Reference_1_eqFunction_521(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,521};
  data->localData[0]->realVars[194] /* wea.spos.E variable */ = (3.82) * (7.499999999999999e-05 + (0.001868) * (data->localData[0]->realVars[43] /* $cse29 variable */) + (-0.032077) * (data->localData[0]->realVars[45] /* $cse30 variable */) + (-0.014615) * (data->localData[0]->realVars[46] /* $cse31 variable */) + (-0.04089) * (data->localData[0]->realVars[47] /* $cse32 variable */));
  TRACE_POP
}
/*
equation index: 522
type: SIMPLE_ASSIGN
wea.spos.dec_r = 0.006918 + (-0.399912) * $cse29 + 0.070257 * $cse30 + (-0.006758) * $cse31 + 0.000907 * $cse32 + (-0.002697) * $cse33 + 0.00148 * $cse34
*/
void Reference_1_eqFunction_522(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,522};
  data->localData[0]->realVars[195] /* wea.spos.dec_r variable */ = 0.006918 + (-0.399912) * (data->localData[0]->realVars[43] /* $cse29 variable */) + (0.070257) * (data->localData[0]->realVars[45] /* $cse30 variable */) + (-0.006758) * (data->localData[0]->realVars[46] /* $cse31 variable */) + (0.000907) * (data->localData[0]->realVars[47] /* $cse32 variable */) + (-0.002697) * (data->localData[0]->realVars[48] /* $cse33 variable */) + (0.00148) * (data->localData[0]->realVars[49] /* $cse34 variable */);
  TRACE_POP
}
/*
equation index: 523
type: SIMPLE_ASSIGN
$cse27 = cos(wea.spos.dec_r)
*/
void Reference_1_eqFunction_523(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,523};
  data->localData[0]->realVars[41] /* $cse27 variable */ = cos(data->localData[0]->realVars[195] /* wea.spos.dec_r variable */);
  TRACE_POP
}
/*
equation index: 524
type: SIMPLE_ASSIGN
$cse17 = sin(wea.spos.dec_r)
*/
void Reference_1_eqFunction_524(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,524};
  data->localData[0]->realVars[30] /* $cse17 variable */ = sin(data->localData[0]->realVars[195] /* wea.spos.dec_r variable */);
  TRACE_POP
}
/*
equation index: 525
type: SIMPLE_ASSIGN
$cse16 = max(2.514364271857552 * $cse17, -1.0)
*/
void Reference_1_eqFunction_525(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,525};
  data->localData[0]->realVars[29] /* $cse16 variable */ = fmax((2.514364271857552) * (data->localData[0]->realVars[30] /* $cse17 variable */),-1.0);
  TRACE_POP
}
/*
equation index: 526
type: SIMPLE_ASSIGN
$cse15 = min($cse16, 1.0)
*/
void Reference_1_eqFunction_526(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,526};
  data->localData[0]->realVars[28] /* $cse15 variable */ = fmin(data->localData[0]->realVars[29] /* $cse16 variable */,1.0);
  TRACE_POP
}
/*
equation index: 527
type: SIMPLE_ASSIGN
$cse14 = asin($cse15)
*/
void Reference_1_eqFunction_527(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,527};
  modelica_real tmp0;
  tmp0 = data->localData[0]->realVars[28] /* $cse15 variable */;
  if(!(tmp0 >= -1.0 && tmp0 <= 1.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
    throwStreamPrintWithEquationIndexes(threadData, equationIndexes, "Model error: Argument of asin($cse15) outside the domain -1.0 <= %g <= 1.0", tmp0);
  }
  data->localData[0]->realVars[27] /* $cse14 variable */ = asin(tmp0);
  TRACE_POP
}
/*
equation index: 528
type: SIMPLE_ASSIGN
sch_fixed.wbus.elo = 57.29577951308232 * $cse14
*/
void Reference_1_eqFunction_528(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,528};
  data->localData[0]->realVars[150] /* sch_fixed.wbus.elo variable */ = (57.29577951308232) * (data->localData[0]->realVars[27] /* $cse14 variable */);
  TRACE_POP
}
/*
equation index: 529
type: SIMPLE_ASSIGN
sch_fixed.wbus.dec = 57.29577951308232 * wea.spos.dec_r
*/
void Reference_1_eqFunction_529(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,529};
  data->localData[0]->realVars[148] /* sch_fixed.wbus.dec variable */ = (57.29577951308232) * (data->localData[0]->realVars[195] /* wea.spos.dec_r variable */);
  TRACE_POP
}
/*
equation index: 530
type: SIMPLE_ASSIGN
wea.spos.t_solar = 0.0002777777777777778 * sch_fixed.wbus.t + 0.06666666666666667 * wea.spos.lon + wea.spos.E - wea.spos.tzone
*/
void Reference_1_eqFunction_530(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,530};
  data->localData[0]->realVars[197] /* wea.spos.t_solar variable */ = (0.0002777777777777778) * (data->localData[0]->realVars[153] /* sch_fixed.wbus.t variable */) + (0.06666666666666667) * (data->simulationInfo->realParameter[301] /* wea.spos.lon PARAM */) + data->localData[0]->realVars[194] /* wea.spos.E variable */ - data->simulationInfo->realParameter[302] /* wea.spos.tzone PARAM */;
  TRACE_POP
}
/*
equation index: 531
type: SIMPLE_ASSIGN
sch_fixed.wbus.hra = 15.0 * (-12.0 + mod(wea.spos.t_solar, 24.0, 8))
*/
void Reference_1_eqFunction_531(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,531};
  data->localData[0]->realVars[152] /* sch_fixed.wbus.hra variable */ = (15.0) * (-12.0 + _event_mod_real(data->localData[0]->realVars[197] /* wea.spos.t_solar variable */, 24.0, ((modelica_integer) 8), data, threadData));
  TRACE_POP
}
/*
equation index: 532
type: SIMPLE_ASSIGN
$cse28 = cos(0.0174532925199433 * sch_fixed.wbus.hra)
*/
void Reference_1_eqFunction_532(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,532};
  data->localData[0]->realVars[42] /* $cse28 variable */ = cos((0.0174532925199433) * (data->localData[0]->realVars[152] /* sch_fixed.wbus.hra variable */));
  TRACE_POP
}
/*
equation index: 533
type: SIMPLE_ASSIGN
wea.spos.hra_s = if noEvent(sch_fixed.wbus.hra >= 0.0) then 1.0 else -1.0
*/
void Reference_1_eqFunction_533(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,533};
  modelica_boolean tmp1;
  tmp1 = GreaterEq(data->localData[0]->realVars[152] /* sch_fixed.wbus.hra variable */,0.0);
  data->localData[0]->realVars[196] /* wea.spos.hra_s variable */ = (tmp1?1.0:-1.0);
  TRACE_POP
}
/*
equation index: 534
type: SIMPLE_ASSIGN
$whenCondition1 = time >= pre(data.table.nextTimeEvent)
*/
void Reference_1_eqFunction_534(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,534};
  modelica_boolean tmp2;
  relationhysteresis(data, &tmp2, data->localData[0]->timeValue, data->simulationInfo->realVarsPre[216] /* data.table.nextTimeEvent DISCRETE */, 2, GreaterEq, GreaterEqZC);
  data->localData[0]->booleanVars[0] /* $whenCondition1 DISCRETE */ = tmp2;
  TRACE_POP
}
/*
equation index: 535
type: WHEN

when {$whenCondition1} then
  data.table.nextTimeEventScaled = Modelica.Blocks.Tables.Internal.getNextTimeEvent(data.table.tableID, data.table.timeScaled);
end when;
*/
void Reference_1_eqFunction_535(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,535};
  if((data->localData[0]->booleanVars[0] /* $whenCondition1 DISCRETE */ && !data->simulationInfo->booleanVarsPre[0] /* $whenCondition1 DISCRETE */ /* edge */))
  {
    data->localData[0]->realVars[217] /* data.table.nextTimeEventScaled DISCRETE */ = omc_Modelica_Blocks_Tables_Internal_getNextTimeEvent(threadData, data->simulationInfo->extObjs[0], data->localData[0]->realVars[83] /* data.table.timeScaled variable */);
  }
  TRACE_POP
}
/*
equation index: 536
type: SIMPLE_ASSIGN
$cse13 = Modelica.Blocks.Tables.Internal.getTimeTableValue(data.table.tableID, 1, data.table.timeScaled, data.table.nextTimeEventScaled, pre(data.table.nextTimeEventScaled))
*/
void Reference_1_eqFunction_536(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,536};
  data->localData[0]->realVars[26] /* $cse13 variable */ = omc_Modelica_Blocks_Tables_Internal_getTimeTableValue(threadData, data->simulationInfo->extObjs[0], ((modelica_integer) 1), data->localData[0]->realVars[83] /* data.table.timeScaled variable */, data->localData[0]->realVars[217] /* data.table.nextTimeEventScaled DISCRETE */, data->simulationInfo->realVarsPre[217] /* data.table.nextTimeEventScaled DISCRETE */);
  TRACE_POP
}
/*
equation index: 537
type: SIMPLE_ASSIGN
data.GHI = data.table.p_offset[1] + $cse13
*/
void Reference_1_eqFunction_537(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,537};
  data->localData[0]->realVars[79] /* data.GHI variable */ = data->simulationInfo->realParameter[109] /* data.table.p_offset[1] PARAM */ + data->localData[0]->realVars[26] /* $cse13 variable */;
  TRACE_POP
}
/*
equation index: 538
type: SIMPLE_ASSIGN
$cse12 = Modelica.Blocks.Tables.Internal.getTimeTableValue(data.table.tableID, 2, data.table.timeScaled, data.table.nextTimeEventScaled, pre(data.table.nextTimeEventScaled))
*/
void Reference_1_eqFunction_538(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,538};
  data->localData[0]->realVars[25] /* $cse12 variable */ = omc_Modelica_Blocks_Tables_Internal_getTimeTableValue(threadData, data->simulationInfo->extObjs[0], ((modelica_integer) 2), data->localData[0]->realVars[83] /* data.table.timeScaled variable */, data->localData[0]->realVars[217] /* data.table.nextTimeEventScaled DISCRETE */, data->simulationInfo->realVarsPre[217] /* data.table.nextTimeEventScaled DISCRETE */);
  TRACE_POP
}
/*
equation index: 539
type: SIMPLE_ASSIGN
data.table.y[2] = data.table.p_offset[2] + $cse12
*/
void Reference_1_eqFunction_539(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,539};
  data->localData[0]->realVars[84] /* data.table.y[2] variable */ = data->simulationInfo->realParameter[110] /* data.table.p_offset[2] PARAM */ + data->localData[0]->realVars[25] /* $cse12 variable */;
  TRACE_POP
}
/*
equation index: 540
type: SIMPLE_ASSIGN
sun.dni = max(data.table.y[2], 0.0)
*/
void Reference_1_eqFunction_540(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,540};
  data->localData[0]->realVars[159] /* sun.dni variable */ = fmax(data->localData[0]->realVars[84] /* data.table.y[2] variable */,0.0);
  TRACE_POP
}
/*
equation index: 541
type: SIMPLE_ASSIGN
$DER.heliostatField.E_dni = heliostatField.he_av * (*Real*)(heliostatField.n_h) * heliostatField.A_h * sun.dni
*/
void Reference_1_eqFunction_541(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,541};
  data->localData[0]->realVars[13] /* der(heliostatField.E_dni) STATE_DER */ = (data->simulationInfo->realParameter[143] /* heliostatField.he_av PARAM */) * ((((modelica_real)data->simulationInfo->integerParameter[21] /* heliostatField.n_h PARAM */)) * ((data->simulationInfo->realParameter[134] /* heliostatField.A_h PARAM */) * (data->localData[0]->realVars[159] /* sun.dni variable */)));
  TRACE_POP
}
/*
equation index: 542
type: SIMPLE_ASSIGN
$cse11 = Modelica.Blocks.Tables.Internal.getTimeTableValue(data.table.tableID, 3, data.table.timeScaled, data.table.nextTimeEventScaled, pre(data.table.nextTimeEventScaled))
*/
void Reference_1_eqFunction_542(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,542};
  data->localData[0]->realVars[24] /* $cse11 variable */ = omc_Modelica_Blocks_Tables_Internal_getTimeTableValue(threadData, data->simulationInfo->extObjs[0], ((modelica_integer) 3), data->localData[0]->realVars[83] /* data.table.timeScaled variable */, data->localData[0]->realVars[217] /* data.table.nextTimeEventScaled DISCRETE */, data->simulationInfo->realVarsPre[217] /* data.table.nextTimeEventScaled DISCRETE */);
  TRACE_POP
}
/*
equation index: 543
type: SIMPLE_ASSIGN
data.DHI = data.table.p_offset[3] + $cse11
*/
void Reference_1_eqFunction_543(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,543};
  data->localData[0]->realVars[78] /* data.DHI variable */ = data->simulationInfo->realParameter[111] /* data.table.p_offset[3] PARAM */ + data->localData[0]->realVars[24] /* $cse11 variable */;
  TRACE_POP
}
/*
equation index: 544
type: SIMPLE_ASSIGN
$cse10 = Modelica.Blocks.Tables.Internal.getTimeTableValue(data.table.tableID, 4, data.table.timeScaled, data.table.nextTimeEventScaled, pre(data.table.nextTimeEventScaled))
*/
void Reference_1_eqFunction_544(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,544};
  data->localData[0]->realVars[23] /* $cse10 variable */ = omc_Modelica_Blocks_Tables_Internal_getTimeTableValue(threadData, data->simulationInfo->extObjs[0], ((modelica_integer) 4), data->localData[0]->realVars[83] /* data.table.timeScaled variable */, data->localData[0]->realVars[217] /* data.table.nextTimeEventScaled DISCRETE */, data->simulationInfo->realVarsPre[217] /* data.table.nextTimeEventScaled DISCRETE */);
  TRACE_POP
}
/*
equation index: 545
type: SIMPLE_ASSIGN
data.table.y[4] = data.table.p_offset[4] + $cse10
*/
void Reference_1_eqFunction_545(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,545};
  data->localData[0]->realVars[85] /* data.table.y[4] variable */ = data->simulationInfo->realParameter[112] /* data.table.p_offset[4] PARAM */ + data->localData[0]->realVars[23] /* $cse10 variable */;
  TRACE_POP
}
/*
equation index: 546
type: SIMPLE_ASSIGN
Tamb_input.y = 273.15 + data.table.y[4]
*/
void Reference_1_eqFunction_546(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,546};
  data->localData[0]->realVars[57] /* Tamb_input.y variable */ = 273.15 + data->localData[0]->realVars[85] /* data.table.y[4] variable */;
  TRACE_POP
}
/*
equation index: 547
type: SIMPLE_ASSIGN
powerBlock.cool.nu_w = 1.0 + 0.00375 * (powerBlock.cool.T_des - Tamb_input.y)
*/
void Reference_1_eqFunction_547(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,547};
  data->localData[0]->realVars[113] /* powerBlock.cool.nu_w variable */ = 1.0 + (0.00375) * (data->simulationInfo->realParameter[186] /* powerBlock.cool.T_des PARAM */ - data->localData[0]->realVars[57] /* Tamb_input.y variable */);
  TRACE_POP
}
/*
equation index: 548
type: SIMPLE_ASSIGN
$cse9 = Modelica.Blocks.Tables.Internal.getTimeTableValue(data.table.tableID, 5, data.table.timeScaled, data.table.nextTimeEventScaled, pre(data.table.nextTimeEventScaled))
*/
void Reference_1_eqFunction_548(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,548};
  data->localData[0]->realVars[55] /* $cse9 variable */ = omc_Modelica_Blocks_Tables_Internal_getTimeTableValue(threadData, data->simulationInfo->extObjs[0], ((modelica_integer) 5), data->localData[0]->realVars[83] /* data.table.timeScaled variable */, data->localData[0]->realVars[217] /* data.table.nextTimeEventScaled DISCRETE */, data->simulationInfo->realVarsPre[217] /* data.table.nextTimeEventScaled DISCRETE */);
  TRACE_POP
}
/*
equation index: 549
type: SIMPLE_ASSIGN
data.table.y[5] = data.table.p_offset[5] + $cse9
*/
void Reference_1_eqFunction_549(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,549};
  data->localData[0]->realVars[86] /* data.table.y[5] variable */ = data->simulationInfo->realParameter[113] /* data.table.p_offset[5] PARAM */ + data->localData[0]->realVars[55] /* $cse9 variable */;
  TRACE_POP
}
/*
equation index: 550
type: SIMPLE_ASSIGN
data.Tdew = 273.15 + data.table.y[5]
*/
void Reference_1_eqFunction_550(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,550};
  data->localData[0]->realVars[81] /* data.Tdew variable */ = 273.15 + data->localData[0]->realVars[86] /* data.table.y[5] variable */;
  TRACE_POP
}
/*
equation index: 551
type: SIMPLE_ASSIGN
$cse8 = Modelica.Blocks.Tables.Internal.getTimeTableValue(data.table.tableID, 6, data.table.timeScaled, data.table.nextTimeEventScaled, pre(data.table.nextTimeEventScaled))
*/
void Reference_1_eqFunction_551(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,551};
  data->localData[0]->realVars[54] /* $cse8 variable */ = omc_Modelica_Blocks_Tables_Internal_getTimeTableValue(threadData, data->simulationInfo->extObjs[0], ((modelica_integer) 6), data->localData[0]->realVars[83] /* data.table.timeScaled variable */, data->localData[0]->realVars[217] /* data.table.nextTimeEventScaled DISCRETE */, data->simulationInfo->realVarsPre[217] /* data.table.nextTimeEventScaled DISCRETE */);
  TRACE_POP
}
/*
equation index: 552
type: SIMPLE_ASSIGN
data.RH = data.table.p_offset[6] + $cse8
*/
void Reference_1_eqFunction_552(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,552};
  data->localData[0]->realVars[80] /* data.RH variable */ = data->simulationInfo->realParameter[114] /* data.table.p_offset[6] PARAM */ + data->localData[0]->realVars[54] /* $cse8 variable */;
  TRACE_POP
}
/*
equation index: 553
type: SIMPLE_ASSIGN
$cse7 = Modelica.Blocks.Tables.Internal.getTimeTableValue(data.table.tableID, 7, data.table.timeScaled, data.table.nextTimeEventScaled, pre(data.table.nextTimeEventScaled))
*/
void Reference_1_eqFunction_553(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,553};
  data->localData[0]->realVars[53] /* $cse7 variable */ = omc_Modelica_Blocks_Tables_Internal_getTimeTableValue(threadData, data->simulationInfo->extObjs[0], ((modelica_integer) 7), data->localData[0]->realVars[83] /* data.table.timeScaled variable */, data->localData[0]->realVars[217] /* data.table.nextTimeEventScaled DISCRETE */, data->simulationInfo->realVarsPre[217] /* data.table.nextTimeEventScaled DISCRETE */);
  TRACE_POP
}
/*
equation index: 554
type: SIMPLE_ASSIGN
data.table.y[7] = data.table.p_offset[7] + $cse7
*/
void Reference_1_eqFunction_554(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,554};
  data->localData[0]->realVars[87] /* data.table.y[7] variable */ = data->simulationInfo->realParameter[115] /* data.table.p_offset[7] PARAM */ + data->localData[0]->realVars[53] /* $cse7 variable */;
  TRACE_POP
}
/*
equation index: 555
type: SIMPLE_ASSIGN
tankCold.p_top_internal = 100.0 * data.table.y[7]
*/
void Reference_1_eqFunction_555(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,555};
  data->localData[0]->realVars[175] /* tankCold.p_top_internal variable */ = (100.0) * (data->localData[0]->realVars[87] /* data.table.y[7] variable */);
  TRACE_POP
}
/*
equation index: 556
type: SIMPLE_ASSIGN
tankCold.medium.p_bar = 1e-05 * tankCold.p_top_internal
*/
void Reference_1_eqFunction_556(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,556};
  data->localData[0]->realVars[173] /* tankCold.medium.p_bar variable */ = (1e-05) * (data->localData[0]->realVars[175] /* tankCold.p_top_internal variable */);
  TRACE_POP
}
/*
equation index: 557
type: SIMPLE_ASSIGN
tankHot.medium.p_bar = 1e-05 * tankCold.p_top_internal
*/
void Reference_1_eqFunction_557(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,557};
  data->localData[0]->realVars[189] /* tankHot.medium.p_bar variable */ = (1e-05) * (data->localData[0]->realVars[175] /* tankCold.p_top_internal variable */);
  TRACE_POP
}
/*
equation index: 558
type: SIMPLE_ASSIGN
receiver.medium.p_bar = 1e-05 * tankCold.p_top_internal
*/
void Reference_1_eqFunction_558(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,558};
  data->localData[0]->realVars[141] /* receiver.medium.p_bar variable */ = (1e-05) * (data->localData[0]->realVars[175] /* tankCold.p_top_internal variable */);
  TRACE_POP
}
/*
equation index: 559
type: SIMPLE_ASSIGN
$cse6 = Modelica.Blocks.Tables.Internal.getTimeTableValue(data.table.tableID, 8, data.table.timeScaled, data.table.nextTimeEventScaled, pre(data.table.nextTimeEventScaled))
*/
void Reference_1_eqFunction_559(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,559};
  data->localData[0]->realVars[52] /* $cse6 variable */ = omc_Modelica_Blocks_Tables_Internal_getTimeTableValue(threadData, data->simulationInfo->extObjs[0], ((modelica_integer) 8), data->localData[0]->realVars[83] /* data.table.timeScaled variable */, data->localData[0]->realVars[217] /* data.table.nextTimeEventScaled DISCRETE */, data->simulationInfo->realVarsPre[217] /* data.table.nextTimeEventScaled DISCRETE */);
  TRACE_POP
}
/*
equation index: 560
type: SIMPLE_ASSIGN
Wspd_input.y = data.table.p_offset[8] + $cse6
*/
void Reference_1_eqFunction_560(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,560};
  data->localData[0]->realVars[58] /* Wspd_input.y variable */ = data->simulationInfo->realParameter[116] /* data.table.p_offset[8] PARAM */ + data->localData[0]->realVars[52] /* $cse6 variable */;
  TRACE_POP
}
/*
equation index: 561
type: SIMPLE_ASSIGN
$cse5 = Modelica.Blocks.Tables.Internal.getTimeTableValue(data.table.tableID, 9, data.table.timeScaled, data.table.nextTimeEventScaled, pre(data.table.nextTimeEventScaled))
*/
void Reference_1_eqFunction_561(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,561};
  data->localData[0]->realVars[51] /* $cse5 variable */ = omc_Modelica_Blocks_Tables_Internal_getTimeTableValue(threadData, data->simulationInfo->extObjs[0], ((modelica_integer) 9), data->localData[0]->realVars[83] /* data.table.timeScaled variable */, data->localData[0]->realVars[217] /* data.table.nextTimeEventScaled DISCRETE */, data->simulationInfo->realVarsPre[217] /* data.table.nextTimeEventScaled DISCRETE */);
  TRACE_POP
}
/*
equation index: 562
type: SIMPLE_ASSIGN
data.table.y[9] = data.table.p_offset[9] + $cse5
*/
void Reference_1_eqFunction_562(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,562};
  data->localData[0]->realVars[88] /* data.table.y[9] variable */ = data->simulationInfo->realParameter[117] /* data.table.p_offset[9] PARAM */ + data->localData[0]->realVars[51] /* $cse5 variable */;
  TRACE_POP
}
/*
equation index: 563
type: SIMPLE_ASSIGN
data.Wdir = 0.0174532925199433 * data.table.y[9]
*/
void Reference_1_eqFunction_563(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,563};
  data->localData[0]->realVars[82] /* data.Wdir variable */ = (0.0174532925199433) * (data->localData[0]->realVars[88] /* data.table.y[9] variable */);
  TRACE_POP
}
/*
equation index: 564
type: SIMPLE_ASSIGN
$cse4 = Modelica.Blocks.Tables.Internal.getTimeTableValue(data.table.tableID, 10, data.table.timeScaled, data.table.nextTimeEventScaled, pre(data.table.nextTimeEventScaled))
*/
void Reference_1_eqFunction_564(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,564};
  data->localData[0]->realVars[50] /* $cse4 variable */ = omc_Modelica_Blocks_Tables_Internal_getTimeTableValue(threadData, data->simulationInfo->extObjs[0], ((modelica_integer) 10), data->localData[0]->realVars[83] /* data.table.timeScaled variable */, data->localData[0]->realVars[217] /* data.table.nextTimeEventScaled DISCRETE */, data->simulationInfo->realVarsPre[217] /* data.table.nextTimeEventScaled DISCRETE */);
  TRACE_POP
}
/*
equation index: 565
type: SIMPLE_ASSIGN
data.Albedo = data.table.p_offset[10] + $cse4
*/
void Reference_1_eqFunction_565(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,565};
  data->localData[0]->realVars[77] /* data.Albedo variable */ = data->simulationInfo->realParameter[118] /* data.table.p_offset[10] PARAM */ + data->localData[0]->realVars[50] /* $cse4 variable */;
  TRACE_POP
}
/*
equation index: 566
type: WHEN

when {$whenCondition1} then
  data.table.nextTimeEvent = if data.table.nextTimeEventScaled < 9.999999999999999e+59 then data.table.nextTimeEventScaled else 9.999999999999999e+59;
end when;
*/
void Reference_1_eqFunction_566(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,566};
  modelica_boolean tmp3;
  if((data->localData[0]->booleanVars[0] /* $whenCondition1 DISCRETE */ && !data->simulationInfo->booleanVarsPre[0] /* $whenCondition1 DISCRETE */ /* edge */))
  {
    tmp3 = Less(data->localData[0]->realVars[217] /* data.table.nextTimeEventScaled DISCRETE */,9.999999999999999e+59);
    data->localData[0]->realVars[216] /* data.table.nextTimeEvent DISCRETE */ = (tmp3?data->localData[0]->realVars[217] /* data.table.nextTimeEventScaled DISCRETE */:9.999999999999999e+59);
  }
  TRACE_POP
}
/*
equation index: 567
type: SIMPLE_ASSIGN
$whenCondition17 = time >= pre(prices.nextTimeEvent)
*/
void Reference_1_eqFunction_567(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,567};
  modelica_boolean tmp4;
  relationhysteresis(data, &tmp4, data->localData[0]->timeValue, data->simulationInfo->realVarsPre[219] /* prices.nextTimeEvent DISCRETE */, 0, GreaterEq, GreaterEqZC);
  data->localData[0]->booleanVars[8] /* $whenCondition17 DISCRETE */ = tmp4;
  TRACE_POP
}
/*
equation index: 568
type: WHEN

when {$whenCondition17} then
  prices.nextTimeEventScaled = Modelica.Blocks.Tables.Internal.getNextTimeEvent(prices.tableID, prices.timeScaled);
end when;
*/
void Reference_1_eqFunction_568(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,568};
  if((data->localData[0]->booleanVars[8] /* $whenCondition17 DISCRETE */ && !data->simulationInfo->booleanVarsPre[8] /* $whenCondition17 DISCRETE */ /* edge */))
  {
    data->localData[0]->realVars[220] /* prices.nextTimeEventScaled DISCRETE */ = omc_Modelica_Blocks_Tables_Internal_getNextTimeEvent(threadData, data->simulationInfo->extObjs[2], data->localData[0]->realVars[122] /* prices.timeScaled variable */);
  }
  TRACE_POP
}
/*
equation index: 569
type: SIMPLE_ASSIGN
$cse1 = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(prices.tableID, 1, prices.timeScaled, prices.nextTimeEventScaled, pre(prices.nextTimeEventScaled))
*/
void Reference_1_eqFunction_569(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,569};
  data->localData[0]->realVars[22] /* $cse1 variable */ = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, data->simulationInfo->extObjs[2], ((modelica_integer) 1), data->localData[0]->realVars[122] /* prices.timeScaled variable */, data->localData[0]->realVars[220] /* prices.nextTimeEventScaled DISCRETE */, data->simulationInfo->realVarsPre[220] /* prices.nextTimeEventScaled DISCRETE */);
  TRACE_POP
}
/*
equation index: 570
type: SIMPLE_ASSIGN
prices.y[1] = prices.p_offset[1] + $cse1
*/
void Reference_1_eqFunction_570(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,570};
  data->localData[0]->realVars[123] /* prices.y[1] variable */ = data->simulationInfo->realParameter[210] /* prices.p_offset[1] PARAM */ + data->localData[0]->realVars[22] /* $cse1 variable */;
  TRACE_POP
}
/*
equation index: 571
type: WHEN

when {$whenCondition17} then
  prices.nextTimeEvent = if prices.nextTimeEventScaled < 9.999999999999999e+59 then prices.nextTimeEventScaled else 9.999999999999999e+59;
end when;
*/
void Reference_1_eqFunction_571(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,571};
  modelica_boolean tmp5;
  if((data->localData[0]->booleanVars[8] /* $whenCondition17 DISCRETE */ && !data->simulationInfo->booleanVarsPre[8] /* $whenCondition17 DISCRETE */ /* edge */))
  {
    tmp5 = Less(data->localData[0]->realVars[220] /* prices.nextTimeEventScaled DISCRETE */,9.999999999999999e+59);
    data->localData[0]->realVars[219] /* prices.nextTimeEvent DISCRETE */ = (tmp5?data->localData[0]->realVars[220] /* prices.nextTimeEventScaled DISCRETE */:9.999999999999999e+59);
  }
  TRACE_POP
}
/*
equation index: 572
type: SIMPLE_ASSIGN
$cse23 = cos(0.0174532925199433 * wea.spos.lat)
*/
void Reference_1_eqFunction_572(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,572};
  data->localData[0]->realVars[37] /* $cse23 variable */ = cos((0.0174532925199433) * (data->simulationInfo->realParameter[300] /* wea.spos.lat PARAM */));
  TRACE_POP
}
/*
equation index: 573
type: SIMPLE_ASSIGN
$cse22 = sin(0.0174532925199433 * wea.spos.lat)
*/
void Reference_1_eqFunction_573(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,573};
  data->localData[0]->realVars[36] /* $cse22 variable */ = sin((0.0174532925199433) * (data->simulationInfo->realParameter[300] /* wea.spos.lat PARAM */));
  TRACE_POP
}
/*
equation index: 574
type: SIMPLE_ASSIGN
$cse26 = max($cse17 * $cse22 + $cse27 * $cse23 * $cse28, -1.0)
*/
void Reference_1_eqFunction_574(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,574};
  data->localData[0]->realVars[40] /* $cse26 variable */ = fmax((data->localData[0]->realVars[30] /* $cse17 variable */) * (data->localData[0]->realVars[36] /* $cse22 variable */) + (data->localData[0]->realVars[41] /* $cse27 variable */) * ((data->localData[0]->realVars[37] /* $cse23 variable */) * (data->localData[0]->realVars[42] /* $cse28 variable */)),-1.0);
  TRACE_POP
}
/*
equation index: 575
type: SIMPLE_ASSIGN
$cse25 = min($cse26, 1.0)
*/
void Reference_1_eqFunction_575(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,575};
  data->localData[0]->realVars[39] /* $cse25 variable */ = fmin(data->localData[0]->realVars[40] /* $cse26 variable */,1.0);
  TRACE_POP
}
/*
equation index: 576
type: SIMPLE_ASSIGN
wea.spos.zen_r = acos($cse25)
*/
void Reference_1_eqFunction_576(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,576};
  modelica_real tmp6;
  tmp6 = data->localData[0]->realVars[39] /* $cse25 variable */;
  if(!(tmp6 >= -1.0 && tmp6 <= 1.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
    throwStreamPrintWithEquationIndexes(threadData, equationIndexes, "Model error: Argument of acos($cse25) outside the domain -1.0 <= %g <= 1.0", tmp6);
  }
  data->localData[0]->realVars[198] /* wea.spos.zen_r variable */ = acos(tmp6);
  TRACE_POP
}
/*
equation index: 577
type: SIMPLE_ASSIGN
$cse24 = sin(wea.spos.zen_r)
*/
void Reference_1_eqFunction_577(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,577};
  data->localData[0]->realVars[38] /* $cse24 variable */ = sin(data->localData[0]->realVars[198] /* wea.spos.zen_r variable */);
  TRACE_POP
}
/*
equation index: 578
type: SIMPLE_ASSIGN
$cse21 = cos(wea.spos.zen_r)
*/
void Reference_1_eqFunction_578(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,578};
  data->localData[0]->realVars[35] /* $cse21 variable */ = cos(data->localData[0]->realVars[198] /* wea.spos.zen_r variable */);
  TRACE_POP
}
/*
equation index: 579
type: SIMPLE_ASSIGN
sch_fixed.wbus.zen = 57.29577951308232 * wea.spos.zen_r
*/
void Reference_1_eqFunction_579(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,579};
  data->localData[0]->realVars[156] /* sch_fixed.wbus.zen variable */ = (57.29577951308232) * (data->localData[0]->realVars[198] /* wea.spos.zen_r variable */);
  TRACE_POP
}
/*
equation index: 580
type: SIMPLE_ASSIGN
sch_fixed.wbus.alt = 57.29577951308232 * (1.570796326794897 - wea.spos.zen_r)
*/
void Reference_1_eqFunction_580(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,580};
  data->localData[0]->realVars[146] /* sch_fixed.wbus.alt variable */ = (57.29577951308232) * (1.570796326794897 - data->localData[0]->realVars[198] /* wea.spos.zen_r variable */);
  TRACE_POP
}
/*
equation index: 581
type: SIMPLE_ASSIGN
$cse20 = max(($cse21 * $cse22 - $cse17) / ($cse23 * $cse24), -1.0)
*/
void Reference_1_eqFunction_581(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,581};
  data->localData[0]->realVars[34] /* $cse20 variable */ = fmax(DIVISION_SIM((data->localData[0]->realVars[35] /* $cse21 variable */) * (data->localData[0]->realVars[36] /* $cse22 variable */) - data->localData[0]->realVars[30] /* $cse17 variable */,(data->localData[0]->realVars[37] /* $cse23 variable */) * (data->localData[0]->realVars[38] /* $cse24 variable */),"$cse23 * $cse24",equationIndexes),-1.0);
  TRACE_POP
}
/*
equation index: 582
type: SIMPLE_ASSIGN
$cse19 = min($cse20, 1.0)
*/
void Reference_1_eqFunction_582(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,582};
  data->localData[0]->realVars[32] /* $cse19 variable */ = fmin(data->localData[0]->realVars[34] /* $cse20 variable */,1.0);
  TRACE_POP
}
/*
equation index: 583
type: SIMPLE_ASSIGN
$cse18 = acos($cse19)
*/
void Reference_1_eqFunction_583(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,583};
  modelica_real tmp7;
  tmp7 = data->localData[0]->realVars[32] /* $cse19 variable */;
  if(!(tmp7 >= -1.0 && tmp7 <= 1.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
    throwStreamPrintWithEquationIndexes(threadData, equationIndexes, "Model error: Argument of acos($cse19) outside the domain -1.0 <= %g <= 1.0", tmp7);
  }
  data->localData[0]->realVars[31] /* $cse18 variable */ = acos(tmp7);
  TRACE_POP
}
/*
equation index: 584
type: SIMPLE_ASSIGN
sch_fixed.wbus.azi = 57.29577951308232 * (3.141592653589793 + wea.spos.hra_s * $cse18)
*/
void Reference_1_eqFunction_584(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,584};
  data->localData[0]->realVars[147] /* sch_fixed.wbus.azi variable */ = (57.29577951308232) * (3.141592653589793 + (data->localData[0]->realVars[196] /* wea.spos.hra_s variable */) * (data->localData[0]->realVars[31] /* $cse18 variable */));
  TRACE_POP
}
/*
equation index: 585
type: ALGORITHM

  (sun.dec, sun.hra) := SolarTherm.Models.Sources.SolarModel.Sun$sun.solarPosition(time, sun.lon, sun.lat, sun.t_zone, sun.year);
*/
void Reference_1_eqFunction_585(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,585};
  data->localData[0]->realVars[158] /* sun.dec variable */ = omc_SolarTherm_Models_Sources_SolarModel__omcQSun_24sun_solarPosition(threadData, data->localData[0]->timeValue, data->simulationInfo->realParameter[248] /* sun.lon PARAM */, data->simulationInfo->realParameter[247] /* sun.lat PARAM */, data->simulationInfo->realParameter[249] /* sun.t_zone PARAM */, data->simulationInfo->integerParameter[76] /* sun.year PARAM */ ,&data->localData[0]->realVars[160] /* sun.hra variable */);
  TRACE_POP
}
/*
equation index: 586
type: SIMPLE_ASSIGN
heliostatField.elo = SolarTherm.Models.Sources.SolarFunctions.eclipticLongitude(sun.dec)
*/
void Reference_1_eqFunction_586(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,586};
  data->localData[0]->realVars[97] /* heliostatField.elo variable */ = omc_SolarTherm_Models_Sources_SolarFunctions_eclipticLongitude(threadData, data->localData[0]->realVars[158] /* sun.dec variable */);
  TRACE_POP
}
/*
equation index: 587
type: SIMPLE_ASSIGN
heliostatField.optical.angle1 = SolarTherm.Models.Sources.SolarFunctions.elevationAngle(sun.dec, sun.hra, heliostatField.optical.lat)
*/
void Reference_1_eqFunction_587(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,587};
  data->localData[0]->realVars[98] /* heliostatField.optical.angle1 variable */ = omc_SolarTherm_Models_Sources_SolarFunctions_elevationAngle(threadData, data->localData[0]->realVars[158] /* sun.dec variable */, data->localData[0]->realVars[160] /* sun.hra variable */, data->simulationInfo->realParameter[149] /* heliostatField.optical.lat PARAM */);
  TRACE_POP
}
/*
equation index: 588
type: SIMPLE_ASSIGN
heliostatField.optical.angle1_input.y = 57.29577951308232 * heliostatField.optical.angle1
*/
void Reference_1_eqFunction_588(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,588};
  data->localData[0]->realVars[99] /* heliostatField.optical.angle1_input.y variable */ = (57.29577951308232) * (data->localData[0]->realVars[98] /* heliostatField.optical.angle1 variable */);
  TRACE_POP
}
/*
equation index: 589
type: SIMPLE_ASSIGN
heliostatField.optical.angle2 = SolarTherm.Models.Sources.SolarFunctions.solarAzimuth(sun.dec, sun.hra, heliostatField.optical.lat)
*/
void Reference_1_eqFunction_589(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,589};
  data->localData[0]->realVars[100] /* heliostatField.optical.angle2 variable */ = omc_SolarTherm_Models_Sources_SolarFunctions_solarAzimuth(threadData, data->localData[0]->realVars[158] /* sun.dec variable */, data->localData[0]->realVars[160] /* sun.hra variable */, data->simulationInfo->realParameter[149] /* heliostatField.optical.lat PARAM */);
  TRACE_POP
}
/*
equation index: 590
type: SIMPLE_ASSIGN
heliostatField.optical.angle2_input.y = 57.29577951308232 * heliostatField.optical.angle2
*/
void Reference_1_eqFunction_590(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,590};
  data->localData[0]->realVars[101] /* heliostatField.optical.angle2_input.y variable */ = (57.29577951308232) * (data->localData[0]->realVars[100] /* heliostatField.optical.angle2 variable */);
  TRACE_POP
}
/*
equation index: 591
type: SIMPLE_ASSIGN
heliostatField.optical.nu_table.y = Modelica.Blocks.Tables.Internal.getTable2DValue(heliostatField.optical.nu_table.tableID, heliostatField.optical.angle1_input.y, heliostatField.optical.angle2_input.y)
*/
void Reference_1_eqFunction_591(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,591};
  data->localData[0]->realVars[103] /* heliostatField.optical.nu_table.y variable */ = omc_Modelica_Blocks_Tables_Internal_getTable2DValue(threadData, data->simulationInfo->extObjs[1], data->localData[0]->realVars[99] /* heliostatField.optical.angle1_input.y variable */, data->localData[0]->realVars[101] /* heliostatField.optical.angle2_input.y variable */);
  TRACE_POP
}
/*
equation index: 592
type: SIMPLE_ASSIGN
heliostatField.optical.nu = max(0.0, heliostatField.optical.nu_table.y)
*/
void Reference_1_eqFunction_592(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,592};
  data->localData[0]->realVars[102] /* heliostatField.optical.nu variable */ = fmax(0.0,data->localData[0]->realVars[103] /* heliostatField.optical.nu_table.y variable */);
  TRACE_POP
}
/*
equation index: 593
type: SIMPLE_ASSIGN
heliostatField.ele = SolarTherm.Models.Sources.SolarFunctions.elevationAngle(sun.dec, sun.hra, heliostatField.lat)
*/
void Reference_1_eqFunction_593(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,593};
  data->localData[0]->realVars[96] /* heliostatField.ele variable */ = omc_SolarTherm_Models_Sources_SolarFunctions_elevationAngle(threadData, data->localData[0]->realVars[158] /* sun.dec variable */, data->localData[0]->realVars[160] /* sun.hra variable */, data->simulationInfo->realParameter[144] /* heliostatField.lat PARAM */);
  TRACE_POP
}
/*
equation index: 594
type: SIMPLE_ASSIGN
$whenCondition4 = heliostatField.ele > 0.01
*/
void Reference_1_eqFunction_594(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,594};
  modelica_boolean tmp8;
  relationhysteresis(data, &tmp8, data->localData[0]->realVars[96] /* heliostatField.ele variable */, 0.01, 1, Greater, GreaterZC);
  data->localData[0]->booleanVars[16] /* $whenCondition4 DISCRETE */ = tmp8;
  TRACE_POP
}
/*
equation index: 595
type: WHEN

when {$whenCondition4} then
  heliostatField.t_on = time;
end when;
*/
void Reference_1_eqFunction_595(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,595};
  if((data->localData[0]->booleanVars[16] /* $whenCondition4 DISCRETE */ && !data->simulationInfo->booleanVarsPre[16] /* $whenCondition4 DISCRETE */ /* edge */))
  {
    data->localData[0]->realVars[218] /* heliostatField.t_on DISCRETE */ = data->localData[0]->timeValue;
  }
  TRACE_POP
}
/*
equation index: 596
type: SIMPLE_ASSIGN
heliostatField.zen = 1.570796326794897 - heliostatField.ele
*/
void Reference_1_eqFunction_596(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,596};
  data->localData[0]->realVars[104] /* heliostatField.zen variable */ = 1.570796326794897 - data->localData[0]->realVars[96] /* heliostatField.ele variable */;
  TRACE_POP
}
/*
equation index: 597
type: SIMPLE_ASSIGN
heliostatField.on_hf = heliostatField.ele > heliostatField.ele_min and Wspd_input.y < heliostatField.Wspd_max
*/
void Reference_1_eqFunction_597(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,597};
  modelica_boolean tmp9;
  modelica_boolean tmp10;
  relationhysteresis(data, &tmp9, data->localData[0]->realVars[96] /* heliostatField.ele variable */, data->simulationInfo->realParameter[142] /* heliostatField.ele_min PARAM */, 15, Greater, GreaterZC);
  relationhysteresis(data, &tmp10, data->localData[0]->realVars[58] /* Wspd_input.y variable */, data->simulationInfo->realParameter[141] /* heliostatField.Wspd_max PARAM */, 16, Less, LessZC);
  data->localData[0]->booleanVars[32] /* heliostatField.on_hf DISCRETE */ = (tmp9 && tmp10);
  TRACE_POP
}
/*
equation index: 598
type: SIMPLE_ASSIGN
heliostatField.Q_raw = if heliostatField.on_hf then max(heliostatField.he_av * (*Real*)(heliostatField.n_h) * heliostatField.A_h * sun.dni * heliostatField.optical.nu, 0.0) else 0.0
*/
void Reference_1_eqFunction_598(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,598};
  data->localData[0]->realVars[90] /* heliostatField.Q_raw variable */ = (data->localData[0]->booleanVars[32] /* heliostatField.on_hf DISCRETE */?fmax((data->simulationInfo->realParameter[143] /* heliostatField.he_av PARAM */) * ((((modelica_real)data->simulationInfo->integerParameter[21] /* heliostatField.n_h PARAM */)) * ((data->simulationInfo->realParameter[134] /* heliostatField.A_h PARAM */) * ((data->localData[0]->realVars[159] /* sun.dni variable */) * (data->localData[0]->realVars[102] /* heliostatField.optical.nu variable */)))),0.0):0.0);
  TRACE_POP
}
/*
equation index: 599
type: SIMPLE_ASSIGN
$whenCondition3 = heliostatField.Q_raw > heliostatField.Q_start
*/
void Reference_1_eqFunction_599(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,599};
  modelica_boolean tmp11;
  relationhysteresis(data, &tmp11, data->localData[0]->realVars[90] /* heliostatField.Q_raw variable */, data->simulationInfo->realParameter[139] /* heliostatField.Q_start PARAM */, 17, Greater, GreaterZC);
  data->localData[0]->booleanVars[15] /* $whenCondition3 DISCRETE */ = tmp11;
  TRACE_POP
}
/*
equation index: 600
type: SIMPLE_ASSIGN
$whenCondition2 = heliostatField.Q_raw < heliostatField.Q_start
*/
void Reference_1_eqFunction_600(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,600};
  modelica_boolean tmp12;
  relationhysteresis(data, &tmp12, data->localData[0]->realVars[90] /* heliostatField.Q_raw variable */, data->simulationInfo->realParameter[139] /* heliostatField.Q_start PARAM */, 18, Less, LessZC);
  data->localData[0]->booleanVars[11] /* $whenCondition2 DISCRETE */ = tmp12;
  TRACE_POP
}
/*
equation index: 601
type: WHEN

when {$whenCondition3} then
  heliostatField.on_internal = true;
end when;
*/
void Reference_1_eqFunction_601(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,601};
  if((data->localData[0]->booleanVars[15] /* $whenCondition3 DISCRETE */ && !data->simulationInfo->booleanVarsPre[15] /* $whenCondition3 DISCRETE */ /* edge */))
  {
    data->localData[0]->booleanVars[33] /* heliostatField.on_internal DISCRETE */ = 1;
  }
  else if((data->localData[0]->booleanVars[11] /* $whenCondition2 DISCRETE */ && !data->simulationInfo->booleanVarsPre[11] /* $whenCondition2 DISCRETE */ /* edge */))
  {
    data->localData[0]->booleanVars[33] /* heliostatField.on_internal DISCRETE */ = 0;
  }
  TRACE_POP
}
/*
equation index: 603
type: SIMPLE_ASSIGN
heliostatField.zen2 = SolarTherm.Models.Sources.SolarFunctions.aparentSolarZenith(sun.dec, sun.hra, heliostatField.lat)
*/
void Reference_1_eqFunction_603(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,603};
  data->localData[0]->realVars[105] /* heliostatField.zen2 variable */ = omc_SolarTherm_Models_Sources_SolarFunctions_aparentSolarZenith(threadData, data->localData[0]->realVars[158] /* sun.dec variable */, data->localData[0]->realVars[160] /* sun.hra variable */, data->simulationInfo->realParameter[144] /* heliostatField.lat PARAM */);
  TRACE_POP
}
/*
equation index: 604
type: SIMPLE_ASSIGN
heliostatField.azi = SolarTherm.Models.Sources.SolarFunctions.solarAzimuth(sun.dec, sun.hra, heliostatField.lat)
*/
void Reference_1_eqFunction_604(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,604};
  data->localData[0]->realVars[94] /* heliostatField.azi variable */ = omc_SolarTherm_Models_Sources_SolarFunctions_solarAzimuth(threadData, data->localData[0]->realVars[158] /* sun.dec variable */, data->localData[0]->realVars[160] /* sun.hra variable */, data->simulationInfo->realParameter[144] /* heliostatField.lat PARAM */);
  TRACE_POP
}
/*
equation index: 605
type: SIMPLE_ASSIGN
tankCold.T = SolarTherm.Media.MoltenSalt.MoltenSalt_utilities.T_h(tankCold.medium.h)
*/
void Reference_1_eqFunction_605(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,605};
  data->localData[0]->realVars[163] /* tankCold.T variable */ = omc_SolarTherm_Media_MoltenSalt_MoltenSalt__utilities_T__h(threadData, data->localData[0]->realVars[8] /* tankCold.medium.h STATE(1) */);
  TRACE_POP
}
/*
equation index: 606
type: SIMPLE_ASSIGN
tankCold.medium.T_degC = -273.15 + tankCold.T
*/
void Reference_1_eqFunction_606(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,606};
  data->localData[0]->realVars[169] /* tankCold.medium.T_degC variable */ = -273.15 + data->localData[0]->realVars[163] /* tankCold.T variable */;
  TRACE_POP
}
/*
equation index: 607
type: SIMPLE_ASSIGN
tankCold.medium.d = SolarTherm.Media.MoltenSalt.MoltenSalt_utilities.rho_T(tankCold.T)
*/
void Reference_1_eqFunction_607(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,607};
  data->localData[0]->realVars[172] /* tankCold.medium.d variable */ = omc_SolarTherm_Media_MoltenSalt_MoltenSalt__utilities_rho__T(threadData, data->localData[0]->realVars[163] /* tankCold.T variable */);
  TRACE_POP
}
/*
equation index: 608
type: SIMPLE_ASSIGN
tankCold.V = tankCold.m / tankCold.medium.d
*/
void Reference_1_eqFunction_608(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,608};
  data->localData[0]->realVars[164] /* tankCold.V variable */ = DIVISION_SIM(data->localData[0]->realVars[7] /* tankCold.m STATE(1) */,data->localData[0]->realVars[172] /* tankCold.medium.d variable */,"tankCold.medium.d",equationIndexes);
  TRACE_POP
}
/*
equation index: 609
type: SIMPLE_ASSIGN
controlCold.hotTankLogic.level_ref = 100.0 * tankCold.V / tankCold.V_t
*/
void Reference_1_eqFunction_609(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,609};
  data->localData[0]->realVars[70] /* controlCold.hotTankLogic.level_ref variable */ = (100.0) * (DIVISION_SIM(data->localData[0]->realVars[164] /* tankCold.V variable */,data->simulationInfo->realParameter[258] /* tankCold.V_t PARAM */,"tankCold.V_t",equationIndexes));
  TRACE_POP
}
/*
equation index: 610
type: SIMPLE_ASSIGN
$whenCondition16 = controlCold.hotTankLogic.level_ref > controlCold.defocus_logic.level_max
*/
void Reference_1_eqFunction_610(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,610};
  modelica_boolean tmp13;
  relationhysteresis(data, &tmp13, data->localData[0]->realVars[70] /* controlCold.hotTankLogic.level_ref variable */, data->simulationInfo->realParameter[82] /* controlCold.defocus_logic.level_max PARAM */, 7, Greater, GreaterZC);
  data->localData[0]->booleanVars[7] /* $whenCondition16 DISCRETE */ = tmp13;
  TRACE_POP
}
/*
equation index: 611
type: SIMPLE_ASSIGN
$whenCondition15 = controlCold.hotTankLogic.level_ref < controlCold.defocus_logic.level_min
*/
void Reference_1_eqFunction_611(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,611};
  modelica_boolean tmp14;
  relationhysteresis(data, &tmp14, data->localData[0]->realVars[70] /* controlCold.hotTankLogic.level_ref variable */, data->simulationInfo->realParameter[83] /* controlCold.defocus_logic.level_min PARAM */, 8, Less, LessZC);
  data->localData[0]->booleanVars[6] /* $whenCondition15 DISCRETE */ = tmp14;
  TRACE_POP
}
/*
equation index: 612
type: WHEN

when {$whenCondition16} then
  controlCold.defocus_logic.y = true;
end when;
*/
void Reference_1_eqFunction_612(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,612};
  if((data->localData[0]->booleanVars[7] /* $whenCondition16 DISCRETE */ && !data->simulationInfo->booleanVarsPre[7] /* $whenCondition16 DISCRETE */ /* edge */))
  {
    data->localData[0]->booleanVars[24] /* controlCold.defocus_logic.y DISCRETE */ = 1;
  }
  else if((data->localData[0]->booleanVars[6] /* $whenCondition15 DISCRETE */ && !data->simulationInfo->booleanVarsPre[6] /* $whenCondition15 DISCRETE */ /* edge */))
  {
    data->localData[0]->booleanVars[24] /* controlCold.defocus_logic.y DISCRETE */ = 0;
  }
  TRACE_POP
}
/*
equation index: 614
type: SIMPLE_ASSIGN
$whenCondition14 = controlCold.hotTankLogic.level_ref > controlCold.hotTankLogic.level_max
*/
void Reference_1_eqFunction_614(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,614};
  modelica_boolean tmp15;
  relationhysteresis(data, &tmp15, data->localData[0]->realVars[70] /* controlCold.hotTankLogic.level_ref variable */, data->simulationInfo->realParameter[85] /* controlCold.hotTankLogic.level_max PARAM */, 9, Greater, GreaterZC);
  data->localData[0]->booleanVars[5] /* $whenCondition14 DISCRETE */ = tmp15;
  TRACE_POP
}
/*
equation index: 615
type: SIMPLE_ASSIGN
$whenCondition13 = controlCold.hotTankLogic.level_ref < controlCold.hotTankLogic.level_min
*/
void Reference_1_eqFunction_615(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,615};
  modelica_boolean tmp16;
  relationhysteresis(data, &tmp16, data->localData[0]->realVars[70] /* controlCold.hotTankLogic.level_ref variable */, data->simulationInfo->realParameter[86] /* controlCold.hotTankLogic.level_min PARAM */, 10, Less, LessZC);
  data->localData[0]->booleanVars[4] /* $whenCondition13 DISCRETE */ = tmp16;
  TRACE_POP
}
/*
equation index: 616
type: WHEN

when {$whenCondition14} then
  controlCold.hotTankLogic.y = true;
end when;
*/
void Reference_1_eqFunction_616(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,616};
  if((data->localData[0]->booleanVars[5] /* $whenCondition14 DISCRETE */ && !data->simulationInfo->booleanVarsPre[5] /* $whenCondition14 DISCRETE */ /* edge */))
  {
    data->localData[0]->booleanVars[25] /* controlCold.hotTankLogic.y DISCRETE */ = 1;
  }
  else if((data->localData[0]->booleanVars[4] /* $whenCondition13 DISCRETE */ && !data->simulationInfo->booleanVarsPre[4] /* $whenCondition13 DISCRETE */ /* edge */))
  {
    data->localData[0]->booleanVars[25] /* controlCold.hotTankLogic.y DISCRETE */ = 0;
  }
  TRACE_POP
}
/*
equation index: 618
type: SIMPLE_ASSIGN
$whenCondition22 = controlCold.hotTankLogic.y and heliostatField.on_internal
*/
void Reference_1_eqFunction_618(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,618};
  data->localData[0]->booleanVars[14] /* $whenCondition22 DISCRETE */ = (data->localData[0]->booleanVars[25] /* controlCold.hotTankLogic.y DISCRETE */ && data->localData[0]->booleanVars[33] /* heliostatField.on_internal DISCRETE */);
  TRACE_POP
}
/*
equation index: 619
type: SIMPLE_ASSIGN
controlCold.PI.reset = $whenCondition22
*/
void Reference_1_eqFunction_619(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,619};
  data->localData[0]->booleanVars[23] /* controlCold.PI.reset DISCRETE */ = data->localData[0]->booleanVars[14] /* $whenCondition22 DISCRETE */;
  TRACE_POP
}
/*
equation index: 620
type: SIMPLE_ASSIGN
tankCold.A = 0.03141592653589793 * tankCold.D * tankCold.H * controlCold.hotTankLogic.level_ref
*/
void Reference_1_eqFunction_620(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,620};
  data->localData[0]->realVars[161] /* tankCold.A variable */ = (0.03141592653589793) * ((data->simulationInfo->realParameter[253] /* tankCold.D PARAM */) * ((data->simulationInfo->realParameter[254] /* tankCold.H PARAM */) * (data->localData[0]->realVars[70] /* controlCold.hotTankLogic.level_ref variable */)));
  TRACE_POP
}
/*
equation index: 621
type: SIMPLE_ASSIGN
controlCold.defocus_logic.level_ref = controlCold.hotTankLogic.level_ref
*/
void Reference_1_eqFunction_621(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,621};
  data->localData[0]->realVars[69] /* controlCold.defocus_logic.level_ref variable */ = data->localData[0]->realVars[70] /* controlCold.hotTankLogic.level_ref variable */;
  TRACE_POP
}
/*
equation index: 622
type: SIMPLE_ASSIGN
tankCold.medium.u = tankCold.medium.h - tankCold.p_top_internal / tankCold.medium.d
*/
void Reference_1_eqFunction_622(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,622};
  data->localData[0]->realVars[174] /* tankCold.medium.u variable */ = data->localData[0]->realVars[8] /* tankCold.medium.h STATE(1) */ - (DIVISION_SIM(data->localData[0]->realVars[175] /* tankCold.p_top_internal variable */,data->localData[0]->realVars[172] /* tankCold.medium.d variable */,"tankCold.medium.d",equationIndexes));
  TRACE_POP
}
/*
equation index: 623
type: SIMPLE_ASSIGN
tankCold.Q_losses = (-tankCold.A) * tankCold.alpha * (tankCold.T - Tamb_input.y)
*/
void Reference_1_eqFunction_623(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,623};
  data->localData[0]->realVars[162] /* tankCold.Q_losses variable */ = ((-data->localData[0]->realVars[161] /* tankCold.A variable */)) * ((data->simulationInfo->realParameter[260] /* tankCold.alpha PARAM */) * (data->localData[0]->realVars[163] /* tankCold.T variable */ - data->localData[0]->realVars[57] /* Tamb_input.y variable */));
  TRACE_POP
}
/*
equation index: 624
type: ALGORITHM

  tankCold.W_net := pre(tankCold.W_net);
  $whenCondition19 := pre($whenCondition19);
  $whenCondition18 := pre($whenCondition18);
  $whenCondition18 := tankCold.T < tankCold.T_set;
  $whenCondition19 := tankCold.T > 1.0 + tankCold.T_set;
  when $whenCondition18 then
    tankCold.W_net := 10.0 * min(-tankCold.Q_losses, tankCold.W_max);
  elsewhen $whenCondition19 then
    tankCold.W_net := 0.0;
  end when;
*/
void Reference_1_eqFunction_624(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,624};
  modelica_boolean tmp17;
  modelica_boolean tmp18;
  data->localData[0]->realVars[221] /* tankCold.W_net DISCRETE */ = data->simulationInfo->realVarsPre[221] /* tankCold.W_net DISCRETE */;

  data->localData[0]->booleanVars[10] /* $whenCondition19 DISCRETE */ = data->simulationInfo->booleanVarsPre[10] /* $whenCondition19 DISCRETE */;

  data->localData[0]->booleanVars[9] /* $whenCondition18 DISCRETE */ = data->simulationInfo->booleanVarsPre[9] /* $whenCondition18 DISCRETE */;

  relationhysteresis(data, &tmp17, data->localData[0]->realVars[163] /* tankCold.T variable */, data->simulationInfo->realParameter[256] /* tankCold.T_set PARAM */, 11, Less, LessZC);
  data->localData[0]->booleanVars[9] /* $whenCondition18 DISCRETE */ = tmp17;

  relationhysteresis(data, &tmp18, data->localData[0]->realVars[163] /* tankCold.T variable */, 1.0 + data->simulationInfo->realParameter[256] /* tankCold.T_set PARAM */, 12, Greater, GreaterZC);
  data->localData[0]->booleanVars[10] /* $whenCondition19 DISCRETE */ = tmp18;

  if(data->simulationInfo->discreteCall == 1)
  {
    if((data->localData[0]->booleanVars[9] /* $whenCondition18 DISCRETE */ && !data->simulationInfo->booleanVarsPre[9] /* $whenCondition18 DISCRETE */ /* edge */))
    {
      data->localData[0]->realVars[221] /* tankCold.W_net DISCRETE */ = (10.0) * (fmin((-data->localData[0]->realVars[162] /* tankCold.Q_losses variable */),data->simulationInfo->realParameter[259] /* tankCold.W_max PARAM */));
    }
    else if((data->localData[0]->booleanVars[10] /* $whenCondition19 DISCRETE */ && !data->simulationInfo->booleanVarsPre[10] /* $whenCondition19 DISCRETE */ /* edge */))
    {
      data->localData[0]->realVars[221] /* tankCold.W_net DISCRETE */ = 0.0;
    }
  }
  TRACE_POP
}
/*
equation index: 625
type: SIMPLE_ASSIGN
tankCold.W_loss = tankCold.W_net / tankCold.e_ht
*/
void Reference_1_eqFunction_625(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,625};
  data->localData[0]->realVars[165] /* tankCold.W_loss variable */ = DIVISION_SIM(data->localData[0]->realVars[221] /* tankCold.W_net DISCRETE */,data->simulationInfo->realParameter[261] /* tankCold.e_ht PARAM */,"tankCold.e_ht",equationIndexes);
  TRACE_POP
}
/*
equation index: 626
type: SIMPLE_ASSIGN
tankCold.medium.T = tankCold.T
*/
void Reference_1_eqFunction_626(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,626};
  data->localData[0]->realVars[168] /* tankCold.medium.T variable */ = data->localData[0]->realVars[163] /* tankCold.T variable */;
  TRACE_POP
}
/*
equation index: 627
type: SIMPLE_ASSIGN
receiver.T_in = tankCold.T
*/
void Reference_1_eqFunction_627(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,627};
  data->localData[0]->realVars[129] /* receiver.T_in variable */ = data->localData[0]->realVars[163] /* tankCold.T variable */;
  TRACE_POP
}
/*
equation index: 628
type: SIMPLE_ASSIGN
powerBlock.T_in = SolarTherm.Media.MoltenSalt.MoltenSalt_utilities.T_h(tankHot.medium.h)
*/
void Reference_1_eqFunction_628(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,628};
  data->localData[0]->realVars[108] /* powerBlock.T_in variable */ = omc_SolarTherm_Media_MoltenSalt_MoltenSalt__utilities_T__h(threadData, data->localData[0]->realVars[10] /* tankHot.medium.h STATE(1) */);
  TRACE_POP
}
/*
equation index: 629
type: SIMPLE_ASSIGN
tankHot.medium.d = SolarTherm.Media.MoltenSalt.MoltenSalt_utilities.rho_T(powerBlock.T_in)
*/
void Reference_1_eqFunction_629(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,629};
  data->localData[0]->realVars[188] /* tankHot.medium.d variable */ = omc_SolarTherm_Media_MoltenSalt_MoltenSalt__utilities_rho__T(threadData, data->localData[0]->realVars[108] /* powerBlock.T_in variable */);
  TRACE_POP
}
/*
equation index: 630
type: SIMPLE_ASSIGN
tankHot.V = tankHot.m / tankHot.medium.d
*/
void Reference_1_eqFunction_630(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,630};
  data->localData[0]->realVars[180] /* tankHot.V variable */ = DIVISION_SIM(data->localData[0]->realVars[9] /* tankHot.m STATE(1) */,data->localData[0]->realVars[188] /* tankHot.medium.d variable */,"tankHot.medium.d",equationIndexes);
  TRACE_POP
}
/*
equation index: 631
type: SIMPLE_ASSIGN
controlHot.logic.level = 100.0 * tankHot.V / tankHot.V_t
*/
void Reference_1_eqFunction_631(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,631};
  data->localData[0]->realVars[74] /* controlHot.logic.level variable */ = (100.0) * (DIVISION_SIM(data->localData[0]->realVars[180] /* tankHot.V variable */,data->simulationInfo->realParameter[268] /* tankHot.V_t PARAM */,"tankHot.V_t",equationIndexes));
  TRACE_POP
}
/*
equation index: 632
type: SIMPLE_ASSIGN
$whenCondition6 = controlHot.logic.level > controlHot.defocus_logic.level_max
*/
void Reference_1_eqFunction_632(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,632};
  modelica_boolean tmp19;
  relationhysteresis(data, &tmp19, data->localData[0]->realVars[74] /* controlHot.logic.level variable */, data->simulationInfo->realParameter[94] /* controlHot.defocus_logic.level_max PARAM */, 3, Greater, GreaterZC);
  data->localData[0]->booleanVars[18] /* $whenCondition6 DISCRETE */ = tmp19;
  TRACE_POP
}
/*
equation index: 633
type: SIMPLE_ASSIGN
$whenCondition5 = controlHot.logic.level < controlHot.defocus_logic.level_min
*/
void Reference_1_eqFunction_633(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,633};
  modelica_boolean tmp20;
  relationhysteresis(data, &tmp20, data->localData[0]->realVars[74] /* controlHot.logic.level variable */, data->simulationInfo->realParameter[95] /* controlHot.defocus_logic.level_min PARAM */, 4, Less, LessZC);
  data->localData[0]->booleanVars[17] /* $whenCondition5 DISCRETE */ = tmp20;
  TRACE_POP
}
/*
equation index: 634
type: WHEN

when {$whenCondition6} then
  controlHot.defocus_logic.y = true;
end when;
*/
void Reference_1_eqFunction_634(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,634};
  if((data->localData[0]->booleanVars[18] /* $whenCondition6 DISCRETE */ && !data->simulationInfo->booleanVarsPre[18] /* $whenCondition6 DISCRETE */ /* edge */))
  {
    data->localData[0]->booleanVars[26] /* controlHot.defocus_logic.y DISCRETE */ = 1;
  }
  else if((data->localData[0]->booleanVars[17] /* $whenCondition5 DISCRETE */ && !data->simulationInfo->booleanVarsPre[17] /* $whenCondition5 DISCRETE */ /* edge */))
  {
    data->localData[0]->booleanVars[26] /* controlHot.defocus_logic.y DISCRETE */ = 0;
  }
  TRACE_POP
}
/*
equation index: 636
type: SIMPLE_ASSIGN
heliostatField.defocus = controlHot.defocus_logic.y or not controlCold.defocus_logic.y
*/
void Reference_1_eqFunction_636(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,636};
  data->localData[0]->booleanVars[31] /* heliostatField.defocus DISCRETE */ = (data->localData[0]->booleanVars[26] /* controlHot.defocus_logic.y DISCRETE */ || (!data->localData[0]->booleanVars[24] /* controlCold.defocus_logic.y DISCRETE */));
  TRACE_POP
}
/*
equation index: 637
type: SIMPLE_ASSIGN
heliostatField.Q_net = if heliostatField.on_internal then if heliostatField.defocus then min(heliostatField.Q_defocus, heliostatField.Q_raw) else heliostatField.Q_raw else 0.0
*/
void Reference_1_eqFunction_637(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,637};
  data->localData[0]->realVars[89] /* heliostatField.Q_net variable */ = (data->localData[0]->booleanVars[33] /* heliostatField.on_internal DISCRETE */?(data->localData[0]->booleanVars[31] /* heliostatField.defocus DISCRETE */?fmin(data->simulationInfo->realParameter[136] /* heliostatField.Q_defocus PARAM */,data->localData[0]->realVars[90] /* heliostatField.Q_raw variable */):data->localData[0]->realVars[90] /* heliostatField.Q_raw variable */):0.0);
  TRACE_POP
}
/*
equation index: 638
type: SIMPLE_ASSIGN
heliostatField.damping = if heliostatField.on_internal then heliostatField.Q_net / (0.001 + heliostatField.Q_raw) else 1.0
*/
void Reference_1_eqFunction_638(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,638};
  data->localData[0]->realVars[95] /* heliostatField.damping variable */ = (data->localData[0]->booleanVars[33] /* heliostatField.on_internal DISCRETE */?DIVISION_SIM(data->localData[0]->realVars[89] /* heliostatField.Q_net variable */,0.001 + data->localData[0]->realVars[90] /* heliostatField.Q_raw variable */,"0.001 + heliostatField.Q_raw",equationIndexes):1.0);
  TRACE_POP
}
/*
equation index: 639
type: SIMPLE_ASSIGN
heliostatField.W_loss2 = if time < heliostatField.t_on + heliostatField.t_start then (*Real*)(heliostatField.n_h) * heliostatField.he_av * heliostatField.damping * heliostatField.E_start / heliostatField.t_start else 0.0
*/
void Reference_1_eqFunction_639(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,639};
  modelica_boolean tmp21;
  relationhysteresis(data, &tmp21, data->localData[0]->timeValue, data->localData[0]->realVars[218] /* heliostatField.t_on DISCRETE */ + data->simulationInfo->realParameter[154] /* heliostatField.t_start PARAM */, 19, Less, LessZC);
  data->localData[0]->realVars[93] /* heliostatField.W_loss2 variable */ = (tmp21?(((modelica_real)data->simulationInfo->integerParameter[21] /* heliostatField.n_h PARAM */)) * ((data->simulationInfo->realParameter[143] /* heliostatField.he_av PARAM */) * ((data->localData[0]->realVars[95] /* heliostatField.damping variable */) * (DIVISION_SIM(data->simulationInfo->realParameter[135] /* heliostatField.E_start PARAM */,data->simulationInfo->realParameter[154] /* heliostatField.t_start PARAM */,"heliostatField.t_start",equationIndexes)))):0.0);
  TRACE_POP
}
/*
equation index: 640
type: SIMPLE_ASSIGN
heliostatField.W_loss1 = if heliostatField.ele > 0.01 then (*Real*)(heliostatField.n_h) * heliostatField.he_av * heliostatField.damping * heliostatField.W_track else 0.0
*/
void Reference_1_eqFunction_640(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,640};
  modelica_boolean tmp22;
  relationhysteresis(data, &tmp22, data->localData[0]->realVars[96] /* heliostatField.ele variable */, 0.01, 1, Greater, GreaterZC);
  data->localData[0]->realVars[92] /* heliostatField.W_loss1 variable */ = (tmp22?(((modelica_real)data->simulationInfo->integerParameter[21] /* heliostatField.n_h PARAM */)) * ((data->simulationInfo->realParameter[143] /* heliostatField.he_av PARAM */) * ((data->localData[0]->realVars[95] /* heliostatField.damping variable */) * (data->simulationInfo->realParameter[140] /* heliostatField.W_track PARAM */))):0.0);
  TRACE_POP
}
/*
equation index: 641
type: SIMPLE_ASSIGN
heliostatField.W_loss = heliostatField.W_loss1 + heliostatField.W_loss2
*/
void Reference_1_eqFunction_641(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,641};
  data->localData[0]->realVars[91] /* heliostatField.W_loss variable */ = data->localData[0]->realVars[92] /* heliostatField.W_loss1 variable */ + data->localData[0]->realVars[93] /* heliostatField.W_loss2 variable */;
  TRACE_POP
}
/*
equation index: 642
type: SIMPLE_ASSIGN
$DER.heliostatField.E_field = heliostatField.Q_net
*/
void Reference_1_eqFunction_642(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,642};
  data->localData[0]->realVars[14] /* der(heliostatField.E_field) STATE_DER */ = data->localData[0]->realVars[89] /* heliostatField.Q_net variable */;
  TRACE_POP
}
/*
equation index: 643
type: SIMPLE_ASSIGN
$cse3 = max(-heliostatField.Q_net, -700000000.0)
*/
void Reference_1_eqFunction_643(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,643};
  data->localData[0]->realVars[44] /* $cse3 variable */ = fmax((-data->localData[0]->realVars[89] /* heliostatField.Q_net variable */),-700000000.0);
  TRACE_POP
}
void Reference_1_eqFunction_644(DATA*, threadData_t*);
void Reference_1_eqFunction_645(DATA*, threadData_t*);
void Reference_1_eqFunction_646(DATA*, threadData_t*);
void Reference_1_eqFunction_647(DATA*, threadData_t*);
void Reference_1_eqFunction_648(DATA*, threadData_t*);
void Reference_1_eqFunction_649(DATA*, threadData_t*);
void Reference_1_eqFunction_650(DATA*, threadData_t*);
void Reference_1_eqFunction_651(DATA*, threadData_t*);
void Reference_1_eqFunction_652(DATA*, threadData_t*);
void Reference_1_eqFunction_653(DATA*, threadData_t*);
void Reference_1_eqFunction_654(DATA*, threadData_t*);
/*
equation index: 655
indexNonlinear: 2
type: NONLINEAR

vars: {receiver.h_out}
eqns: {644, 645, 646, 647, 648, 649, 650, 651, 652, 653, 654}
*/
void Reference_1_eqFunction_655(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,655};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 655 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[2].nlsxOld[0] = data->localData[0]->realVars[131] /* receiver.h_out variable */;
  retValue = solve_nonlinear_system(data, threadData, 2);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,655};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving non-linear system 655 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->localData[0]->realVars[131] /* receiver.h_out variable */ = data->simulationInfo->nonlinearSystemData[2].nlsx[0];
  TRACE_POP
}
/*
equation index: 656
type: SIMPLE_ASSIGN
controlHot.logic.on_charge = controlCold.m_flow > 0.0
*/
void Reference_1_eqFunction_656(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,656};
  modelica_boolean tmp0;
  relationhysteresis(data, &tmp0, data->localData[0]->realVars[71] /* controlCold.m_flow variable */, 0.0, 20, Greater, GreaterZC);
  data->localData[0]->booleanVars[27] /* controlHot.logic.on_charge DISCRETE */ = tmp0;
  TRACE_POP
}
/*
equation index: 657
type: SIMPLE_ASSIGN
pumpCold.W_loss = pumpCold.k_loss * controlCold.m_flow
*/
void Reference_1_eqFunction_657(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,657};
  data->localData[0]->realVars[124] /* pumpCold.W_loss variable */ = (data->simulationInfo->realParameter[218] /* pumpCold.k_loss PARAM */) * (data->localData[0]->realVars[71] /* controlCold.m_flow variable */);
  TRACE_POP
}
/*
equation index: 658
type: SIMPLE_ASSIGN
controlCold.PI.add1.y = controlCold.PI.add1.k1 * controlCold.PI.y + controlCold.PI.add1.k2 * controlCold.PI.Add.y
*/
void Reference_1_eqFunction_658(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,658};
  data->localData[0]->realVars[64] /* controlCold.PI.add1.y variable */ = (data->simulationInfo->realParameter[69] /* controlCold.PI.add1.k1 PARAM */) * (data->localData[0]->realVars[67] /* controlCold.PI.y variable */) + (data->simulationInfo->realParameter[70] /* controlCold.PI.add1.k2 PARAM */) * (data->localData[0]->realVars[60] /* controlCold.PI.Add.y variable */);
  TRACE_POP
}
/*
equation index: 659
type: SIMPLE_ASSIGN
controlCold.PI.add2.u2 = controlCold.PI.gain1.k * controlCold.PI.add1.y
*/
void Reference_1_eqFunction_659(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,659};
  data->localData[0]->realVars[65] /* controlCold.PI.add2.u2 variable */ = (data->simulationInfo->realParameter[73] /* controlCold.PI.gain1.k PARAM */) * (data->localData[0]->realVars[64] /* controlCold.PI.add1.y variable */);
  TRACE_POP
}
/*
equation index: 660
type: SIMPLE_ASSIGN
controlCold.PI.P1.y = controlCold.PI.P1.k * controlCold.PI.u
*/
void Reference_1_eqFunction_660(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,660};
  data->localData[0]->realVars[63] /* controlCold.PI.P1.y variable */ = (data->simulationInfo->realParameter[66] /* controlCold.PI.P1.k PARAM */) * (data->localData[0]->realVars[66] /* controlCold.PI.u variable */);
  TRACE_POP
}
/*
equation index: 661
type: SIMPLE_ASSIGN
controlCold.PI.I.u = controlCold.PI.add2.k1 * controlCold.PI.P1.y + controlCold.PI.add2.k2 * controlCold.PI.add2.u2
*/
void Reference_1_eqFunction_661(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,661};
  data->localData[0]->realVars[62] /* controlCold.PI.I.u variable */ = (data->simulationInfo->realParameter[71] /* controlCold.PI.add2.k1 PARAM */) * (data->localData[0]->realVars[63] /* controlCold.PI.P1.y variable */) + (data->simulationInfo->realParameter[72] /* controlCold.PI.add2.k2 PARAM */) * (data->localData[0]->realVars[65] /* controlCold.PI.add2.u2 variable */);
  TRACE_POP
}
/*
equation index: 662
type: SIMPLE_ASSIGN
$DER.controlCold.PI.I.y = controlCold.PI.I.k * controlCold.PI.I.u
*/
void Reference_1_eqFunction_662(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,662};
  data->localData[0]->realVars[12] /* der(controlCold.PI.I.y) STATE_DER */ = (data->simulationInfo->realParameter[62] /* controlCold.PI.I.k PARAM */) * (data->localData[0]->realVars[62] /* controlCold.PI.I.u variable */);
  TRACE_POP
}
/*
equation index: 663
type: SIMPLE_ASSIGN
receiver.medium.T_degC = -273.15 + receiver.medium.T
*/
void Reference_1_eqFunction_663(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,663};
  data->localData[0]->realVars[136] /* receiver.medium.T_degC variable */ = -273.15 + data->localData[0]->realVars[135] /* receiver.medium.T variable */;
  TRACE_POP
}
/*
equation index: 664
type: SIMPLE_ASSIGN
receiver.medium.d = SolarTherm.Media.MoltenSalt.MoltenSalt_utilities.rho_T(receiver.medium.T)
*/
void Reference_1_eqFunction_664(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,664};
  data->localData[0]->realVars[139] /* receiver.medium.d variable */ = omc_SolarTherm_Media_MoltenSalt_MoltenSalt__utilities_rho__T(threadData, data->localData[0]->realVars[135] /* receiver.medium.T variable */);
  TRACE_POP
}
/*
equation index: 665
type: SIMPLE_ASSIGN
receiver.medium.u = receiver.medium.h - tankCold.p_top_internal / receiver.medium.d
*/
void Reference_1_eqFunction_665(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,665};
  data->localData[0]->realVars[142] /* receiver.medium.u variable */ = data->localData[0]->realVars[140] /* receiver.medium.h variable */ - (DIVISION_SIM(data->localData[0]->realVars[175] /* tankCold.p_top_internal variable */,data->localData[0]->realVars[139] /* receiver.medium.d variable */,"receiver.medium.d",equationIndexes));
  TRACE_POP
}
/*
equation index: 666
type: SIMPLE_ASSIGN
receiver.T = SolarTherm.Media.MoltenSalt.MoltenSalt_utilities.T_h(receiver.h_out)
*/
void Reference_1_eqFunction_666(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,666};
  data->localData[0]->realVars[128] /* receiver.T variable */ = omc_SolarTherm_Media_MoltenSalt_MoltenSalt__utilities_T__h(threadData, data->localData[0]->realVars[131] /* receiver.h_out variable */);
  TRACE_POP
}
/*
equation index: 667
type: SIMPLE_ASSIGN
receiver.Q_rcv = controlCold.m_flow * (receiver.h_out - tankCold.medium.h)
*/
void Reference_1_eqFunction_667(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,667};
  data->localData[0]->realVars[127] /* receiver.Q_rcv variable */ = (data->localData[0]->realVars[71] /* controlCold.m_flow variable */) * (data->localData[0]->realVars[131] /* receiver.h_out variable */ - data->localData[0]->realVars[8] /* tankCold.medium.h STATE(1) */);
  TRACE_POP
}
/*
equation index: 668
type: SIMPLE_ASSIGN
receiver.heat.Q_flow = -$cse3
*/
void Reference_1_eqFunction_668(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,668};
  data->localData[0]->realVars[132] /* receiver.heat.Q_flow variable */ = (-data->localData[0]->realVars[44] /* $cse3 variable */);
  TRACE_POP
}
/*
equation index: 669
type: SIMPLE_ASSIGN
$whenCondition8 = controlHot.logic.level > controlHot.logic.level_on
*/
void Reference_1_eqFunction_669(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,669};
  modelica_boolean tmp1;
  relationhysteresis(data, &tmp1, data->localData[0]->realVars[74] /* controlHot.logic.level variable */, data->simulationInfo->realParameter[97] /* controlHot.logic.level_on PARAM */, 5, Greater, GreaterZC);
  data->localData[0]->booleanVars[20] /* $whenCondition8 DISCRETE */ = tmp1;
  TRACE_POP
}
/*
equation index: 670
type: SIMPLE_ASSIGN
$whenCondition7 = controlHot.logic.level < controlHot.logic.level_off
*/
void Reference_1_eqFunction_670(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,670};
  modelica_boolean tmp2;
  relationhysteresis(data, &tmp2, data->localData[0]->realVars[74] /* controlHot.logic.level variable */, data->simulationInfo->realParameter[96] /* controlHot.logic.level_off PARAM */, 6, Less, LessZC);
  data->localData[0]->booleanVars[19] /* $whenCondition7 DISCRETE */ = tmp2;
  TRACE_POP
}
/*
equation index: 671
type: WHEN

when {$whenCondition8} then
  controlHot.logic.on_discharge = true;
end when;
*/
void Reference_1_eqFunction_671(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,671};
  if((data->localData[0]->booleanVars[20] /* $whenCondition8 DISCRETE */ && !data->simulationInfo->booleanVarsPre[20] /* $whenCondition8 DISCRETE */ /* edge */))
  {
    data->localData[0]->booleanVars[28] /* controlHot.logic.on_discharge DISCRETE */ = 1;
  }
  else if((data->localData[0]->booleanVars[19] /* $whenCondition7 DISCRETE */ && !data->simulationInfo->booleanVarsPre[19] /* $whenCondition7 DISCRETE */ /* edge */))
  {
    data->localData[0]->booleanVars[28] /* controlHot.logic.on_discharge DISCRETE */ = 0;
  }
  TRACE_POP
}
/*
equation index: 673
type: SIMPLE_ASSIGN
$whenCondition9 = controlHot.logic.on_charge or controlHot.logic.on_discharge
*/
void Reference_1_eqFunction_673(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,673};
  data->localData[0]->booleanVars[21] /* $whenCondition9 DISCRETE */ = (data->localData[0]->booleanVars[27] /* controlHot.logic.on_charge DISCRETE */ || data->localData[0]->booleanVars[28] /* controlHot.logic.on_discharge DISCRETE */);
  TRACE_POP
}
/*
equation index: 674
type: WHEN

when {$whenCondition9} then
  controlHot.logic.t_on = time;
end when;
*/
void Reference_1_eqFunction_674(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,674};
  if((data->localData[0]->booleanVars[21] /* $whenCondition9 DISCRETE */ && !data->simulationInfo->booleanVarsPre[21] /* $whenCondition9 DISCRETE */ /* edge */))
  {
    data->localData[0]->realVars[215] /* controlHot.logic.t_on DISCRETE */ = data->localData[0]->timeValue;
  }
  TRACE_POP
}
/*
equation index: 675
type: SIMPLE_ASSIGN
$whenCondition11 = time - controlHot.logic.t_on > controlHot.logic.t_start
*/
void Reference_1_eqFunction_675(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,675};
  modelica_boolean tmp3;
  relationhysteresis(data, &tmp3, data->localData[0]->timeValue - data->localData[0]->realVars[215] /* controlHot.logic.t_on DISCRETE */, data->simulationInfo->realParameter[102] /* controlHot.logic.t_start PARAM */, 21, Greater, GreaterZC);
  data->localData[0]->booleanVars[2] /* $whenCondition11 DISCRETE */ = tmp3;
  TRACE_POP
}
/*
equation index: 676
type: SIMPLE_ASSIGN
$whenCondition10 = not (controlHot.logic.on_charge or controlHot.logic.on_discharge)
*/
void Reference_1_eqFunction_676(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,676};
  data->localData[0]->booleanVars[1] /* $whenCondition10 DISCRETE */ = (!(data->localData[0]->booleanVars[27] /* controlHot.logic.on_charge DISCRETE */ || data->localData[0]->booleanVars[28] /* controlHot.logic.on_discharge DISCRETE */));
  TRACE_POP
}
/*
equation index: 677
type: WHEN

when {$whenCondition10} then
  controlHot.logic.t_off = time;
end when;
*/
void Reference_1_eqFunction_677(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,677};
  if((data->localData[0]->booleanVars[1] /* $whenCondition10 DISCRETE */ && !data->simulationInfo->booleanVarsPre[1] /* $whenCondition10 DISCRETE */ /* edge */))
  {
    data->localData[0]->realVars[214] /* controlHot.logic.t_off DISCRETE */ = data->localData[0]->timeValue;
  }
  TRACE_POP
}
/*
equation index: 678
type: SIMPLE_ASSIGN
controlHot.logic.standby = time - controlHot.logic.t_off < controlHot.logic.t_standby
*/
void Reference_1_eqFunction_678(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,678};
  modelica_boolean tmp4;
  relationhysteresis(data, &tmp4, data->localData[0]->timeValue - data->localData[0]->realVars[214] /* controlHot.logic.t_off DISCRETE */, data->simulationInfo->realParameter[101] /* controlHot.logic.t_standby PARAM */, 22, Less, LessZC);
  data->localData[0]->booleanVars[29] /* controlHot.logic.standby DISCRETE */ = tmp4;
  TRACE_POP
}
/*
equation index: 679
type: SIMPLE_ASSIGN
$whenCondition12 = controlHot.logic.t_on + (-controlHot.logic.t_off) - controlHot.logic.t_standby > 0.0
*/
void Reference_1_eqFunction_679(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,679};
  modelica_boolean tmp5;
  tmp5 = Greater(data->localData[0]->realVars[215] /* controlHot.logic.t_on DISCRETE */ + (-data->localData[0]->realVars[214] /* controlHot.logic.t_off DISCRETE */) - data->simulationInfo->realParameter[101] /* controlHot.logic.t_standby PARAM */,0.0);
  data->localData[0]->booleanVars[3] /* $whenCondition12 DISCRETE */ = tmp5;
  TRACE_POP
}
/*
equation index: 680
type: WHEN

when {$whenCondition12} then
  controlHot.logic.startup = true;
end when;
*/
void Reference_1_eqFunction_680(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,680};
  if((data->localData[0]->booleanVars[3] /* $whenCondition12 DISCRETE */ && !data->simulationInfo->booleanVarsPre[3] /* $whenCondition12 DISCRETE */ /* edge */))
  {
    data->localData[0]->booleanVars[30] /* controlHot.logic.startup DISCRETE */ = 1;
  }
  else if((data->localData[0]->booleanVars[2] /* $whenCondition11 DISCRETE */ && !data->simulationInfo->booleanVarsPre[2] /* $whenCondition11 DISCRETE */ /* edge */))
  {
    data->localData[0]->booleanVars[30] /* controlHot.logic.startup DISCRETE */ = 0;
  }
  TRACE_POP
}
/*
equation index: 682
type: SIMPLE_ASSIGN
controlHot.m_flow = if controlHot.logic.on_charge or controlHot.logic.on_discharge then if controlHot.logic.startup then controlHot.logic.m_flow_startup else if controlHot.logic.on_discharge then controlHot.schedule * controlHot.logic.m_flow_max else min(controlCold.m_flow, controlHot.schedule * controlHot.logic.m_flow_max) else if controlHot.logic.standby then controlHot.logic.m_flow_standby else 0.0
*/
void Reference_1_eqFunction_682(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,682};
  data->localData[0]->realVars[75] /* controlHot.m_flow variable */ = ((data->localData[0]->booleanVars[27] /* controlHot.logic.on_charge DISCRETE */ || data->localData[0]->booleanVars[28] /* controlHot.logic.on_discharge DISCRETE */)?(data->localData[0]->booleanVars[30] /* controlHot.logic.startup DISCRETE */?data->simulationInfo->realParameter[100] /* controlHot.logic.m_flow_startup PARAM */:(data->localData[0]->booleanVars[28] /* controlHot.logic.on_discharge DISCRETE */?(data->localData[0]->realVars[76] /* controlHot.schedule variable */) * (data->simulationInfo->realParameter[98] /* controlHot.logic.m_flow_max PARAM */):fmin(data->localData[0]->realVars[71] /* controlCold.m_flow variable */,(data->localData[0]->realVars[76] /* controlHot.schedule variable */) * (data->simulationInfo->realParameter[98] /* controlHot.logic.m_flow_max PARAM */)))):(data->localData[0]->booleanVars[29] /* controlHot.logic.standby DISCRETE */?data->simulationInfo->realParameter[99] /* controlHot.logic.m_flow_standby PARAM */:0.0));
  TRACE_POP
}
/*
equation index: 683
type: SIMPLE_ASSIGN
pumpHot.W_loss = pumpHot.k_loss * controlHot.m_flow
*/
void Reference_1_eqFunction_683(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,683};
  data->localData[0]->realVars[125] /* pumpHot.W_loss variable */ = (data->simulationInfo->realParameter[219] /* pumpHot.k_loss PARAM */) * (data->localData[0]->realVars[75] /* controlHot.m_flow variable */);
  TRACE_POP
}
/*
equation index: 684
type: SIMPLE_ASSIGN
powerBlock.load = max(powerBlock.nu_eps, controlHot.m_flow / powerBlock.m_flow_ref)
*/
void Reference_1_eqFunction_684(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,684};
  data->localData[0]->realVars[121] /* powerBlock.load variable */ = fmax(data->simulationInfo->realParameter[193] /* powerBlock.nu_eps PARAM */,DIVISION_SIM(data->localData[0]->realVars[75] /* controlHot.m_flow variable */,data->simulationInfo->realParameter[192] /* powerBlock.m_flow_ref PARAM */,"powerBlock.m_flow_ref",equationIndexes));
  TRACE_POP
}
/*
equation index: 685
type: SIMPLE_ASSIGN
powerBlock.logic = powerBlock.load > powerBlock.nu_min
*/
void Reference_1_eqFunction_685(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,685};
  modelica_boolean tmp6;
  relationhysteresis(data, &tmp6, data->localData[0]->realVars[121] /* powerBlock.load variable */, data->simulationInfo->realParameter[194] /* powerBlock.nu_min PARAM */, 23, Greater, GreaterZC);
  data->localData[0]->booleanVars[34] /* powerBlock.logic DISCRETE */ = tmp6;
  TRACE_POP
}
/*
equation index: 686
type: SIMPLE_ASSIGN
$DER.tankCold.m = controlHot.m_flow - controlCold.m_flow
*/
void Reference_1_eqFunction_686(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,686};
  data->localData[0]->realVars[18] /* der(tankCold.m) STATE_DER */ = data->localData[0]->realVars[75] /* controlHot.m_flow variable */ - data->localData[0]->realVars[71] /* controlCold.m_flow variable */;
  TRACE_POP
}
/*
equation index: 687
type: SIMPLE_ASSIGN
$DER.tankHot.m = controlCold.m_flow - controlHot.m_flow
*/
void Reference_1_eqFunction_687(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,687};
  data->localData[0]->realVars[20] /* der(tankHot.m) STATE_DER */ = data->localData[0]->realVars[71] /* controlCold.m_flow variable */ - data->localData[0]->realVars[75] /* controlHot.m_flow variable */;
  TRACE_POP
}
/*
equation index: 688
type: SIMPLE_ASSIGN
tankHot.A = 0.03141592653589793 * tankHot.D * tankHot.H * controlHot.logic.level
*/
void Reference_1_eqFunction_688(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,688};
  data->localData[0]->realVars[177] /* tankHot.A variable */ = (0.03141592653589793) * ((data->simulationInfo->realParameter[263] /* tankHot.D PARAM */) * ((data->simulationInfo->realParameter[264] /* tankHot.H PARAM */) * (data->localData[0]->realVars[74] /* controlHot.logic.level variable */)));
  TRACE_POP
}
/*
equation index: 689
type: SIMPLE_ASSIGN
controlHot.defocus_logic.level_ref = controlHot.logic.level
*/
void Reference_1_eqFunction_689(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,689};
  data->localData[0]->realVars[73] /* controlHot.defocus_logic.level_ref variable */ = data->localData[0]->realVars[74] /* controlHot.logic.level variable */;
  TRACE_POP
}
/*
equation index: 690
type: SIMPLE_ASSIGN
tankHot.medium.u = tankHot.medium.h - tankCold.p_top_internal / tankHot.medium.d
*/
void Reference_1_eqFunction_690(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,690};
  data->localData[0]->realVars[190] /* tankHot.medium.u variable */ = data->localData[0]->realVars[10] /* tankHot.medium.h STATE(1) */ - (DIVISION_SIM(data->localData[0]->realVars[175] /* tankCold.p_top_internal variable */,data->localData[0]->realVars[188] /* tankHot.medium.d variable */,"tankHot.medium.d",equationIndexes));
  TRACE_POP
}
/*
equation index: 691
type: SIMPLE_ASSIGN
tankHot.medium.T_degC = -273.15 + powerBlock.T_in
*/
void Reference_1_eqFunction_691(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,691};
  data->localData[0]->realVars[185] /* tankHot.medium.T_degC variable */ = -273.15 + data->localData[0]->realVars[108] /* powerBlock.T_in variable */;
  TRACE_POP
}
/*
equation index: 692
type: SIMPLE_ASSIGN
powerBlock.cycle.T_ND = (powerBlock.T_in - powerBlock.cycle.Tsat_ref) / (powerBlock.cycle.T_in_ref - powerBlock.cycle.Tsat_ref)
*/
void Reference_1_eqFunction_692(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,692};
  data->localData[0]->realVars[114] /* powerBlock.cycle.T_ND variable */ = DIVISION_SIM(data->localData[0]->realVars[108] /* powerBlock.T_in variable */ - data->simulationInfo->realParameter[188] /* powerBlock.cycle.Tsat_ref PARAM */,data->simulationInfo->realParameter[187] /* powerBlock.cycle.T_in_ref PARAM */ - data->simulationInfo->realParameter[188] /* powerBlock.cycle.Tsat_ref PARAM */,"powerBlock.cycle.T_in_ref - powerBlock.cycle.Tsat_ref",equationIndexes);
  TRACE_POP
}
/*
equation index: 693
type: SIMPLE_ASSIGN
powerBlock.cycle.k_q = -0.006011 + 1.060131 * powerBlock.cycle.T_ND + (-0.054078) * powerBlock.cycle.T_ND ^ 2.0
*/
void Reference_1_eqFunction_693(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,693};
  modelica_real tmp7;
  tmp7 = data->localData[0]->realVars[114] /* powerBlock.cycle.T_ND variable */;
  data->localData[0]->realVars[115] /* powerBlock.cycle.k_q variable */ = -0.006011 + (1.060131) * (data->localData[0]->realVars[114] /* powerBlock.cycle.T_ND variable */) + (-0.054078) * ((tmp7 * tmp7));
  TRACE_POP
}
/*
equation index: 694
type: SIMPLE_ASSIGN
powerBlock.k_q = if powerBlock.logic then powerBlock.cycle.k_q else 0.0
*/
void Reference_1_eqFunction_694(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,694};
  data->localData[0]->realVars[119] /* powerBlock.k_q variable */ = (data->localData[0]->booleanVars[34] /* powerBlock.logic DISCRETE */?data->localData[0]->realVars[115] /* powerBlock.cycle.k_q variable */:0.0);
  TRACE_POP
}
/*
equation index: 695
type: SIMPLE_ASSIGN
powerBlock.Q_flow = powerBlock.k_q * powerBlock.Q_flow_ref * powerBlock.load
*/
void Reference_1_eqFunction_695(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,695};
  data->localData[0]->realVars[107] /* powerBlock.Q_flow variable */ = (data->localData[0]->realVars[119] /* powerBlock.k_q variable */) * ((data->simulationInfo->realParameter[180] /* powerBlock.Q_flow_ref PARAM */) * (data->localData[0]->realVars[121] /* powerBlock.load variable */));
  TRACE_POP
}
/*
equation index: 696
type: SIMPLE_ASSIGN
$cse2 = max(1.0, powerBlock.Q_flow)
*/
void Reference_1_eqFunction_696(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,696};
  data->localData[0]->realVars[33] /* $cse2 variable */ = fmax(1.0,data->localData[0]->realVars[107] /* powerBlock.Q_flow variable */);
  TRACE_POP
}
/*
equation index: 697
type: SIMPLE_ASSIGN
powerBlock.fluid_b.h_outflow = if powerBlock.logic then tankHot.medium.h - powerBlock.Q_flow / controlHot.m_flow else powerBlock.h_out_ref
*/
void Reference_1_eqFunction_697(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,697};
  data->localData[0]->realVars[118] /* powerBlock.fluid_b.h_outflow variable */ = (data->localData[0]->booleanVars[34] /* powerBlock.logic DISCRETE */?data->localData[0]->realVars[10] /* tankHot.medium.h STATE(1) */ - (DIVISION_SIM(data->localData[0]->realVars[107] /* powerBlock.Q_flow variable */,data->localData[0]->realVars[75] /* controlHot.m_flow variable */,"controlHot.m_flow",equationIndexes)):data->simulationInfo->realParameter[191] /* powerBlock.h_out_ref PARAM */);
  TRACE_POP
}
/*
equation index: 698
type: SIMPLE_ASSIGN
powerBlock.T_out = SolarTherm.Media.MoltenSalt.MoltenSalt_utilities.T_h(powerBlock.fluid_b.h_outflow)
*/
void Reference_1_eqFunction_698(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,698};
  data->localData[0]->realVars[109] /* powerBlock.T_out variable */ = omc_SolarTherm_Media_MoltenSalt_MoltenSalt__utilities_T__h(threadData, data->localData[0]->realVars[118] /* powerBlock.fluid_b.h_outflow variable */);
  TRACE_POP
}
/*
equation index: 699
type: SIMPLE_ASSIGN
$DER.tankCold.medium.h = (tankCold.Q_losses + tankCold.W_net + controlHot.m_flow * powerBlock.fluid_b.h_outflow - controlCold.m_flow * tankCold.medium.h - der(tankCold.m) * tankCold.medium.h) / tankCold.m
*/
void Reference_1_eqFunction_699(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,699};
  data->localData[0]->realVars[19] /* der(tankCold.medium.h) STATE_DER */ = DIVISION_SIM(data->localData[0]->realVars[162] /* tankCold.Q_losses variable */ + data->localData[0]->realVars[221] /* tankCold.W_net DISCRETE */ + (data->localData[0]->realVars[75] /* controlHot.m_flow variable */) * (data->localData[0]->realVars[118] /* powerBlock.fluid_b.h_outflow variable */) - ((data->localData[0]->realVars[71] /* controlCold.m_flow variable */) * (data->localData[0]->realVars[8] /* tankCold.medium.h STATE(1) */)) - ((data->localData[0]->realVars[18] /* der(tankCold.m) STATE_DER */) * (data->localData[0]->realVars[8] /* tankCold.medium.h STATE(1) */)),data->localData[0]->realVars[7] /* tankCold.m STATE(1) */,"tankCold.m",equationIndexes);
  TRACE_POP
}
/*
equation index: 700
type: SIMPLE_ASSIGN
powerBlock.cycle.k_w = -0.027262 + 1.036423 * powerBlock.cycle.T_ND + (-0.007885) * powerBlock.cycle.T_ND ^ 2.0
*/
void Reference_1_eqFunction_700(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,700};
  modelica_real tmp8;
  tmp8 = data->localData[0]->realVars[114] /* powerBlock.cycle.T_ND variable */;
  data->localData[0]->realVars[116] /* powerBlock.cycle.k_w variable */ = -0.027262 + (1.036423) * (data->localData[0]->realVars[114] /* powerBlock.cycle.T_ND variable */) + (-0.007885) * ((tmp8 * tmp8));
  TRACE_POP
}
/*
equation index: 701
type: SIMPLE_ASSIGN
powerBlock.k_w = if powerBlock.logic then powerBlock.cycle.k_w else 0.0
*/
void Reference_1_eqFunction_701(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,701};
  data->localData[0]->realVars[120] /* powerBlock.k_w variable */ = (data->localData[0]->booleanVars[34] /* powerBlock.logic DISCRETE */?data->localData[0]->realVars[116] /* powerBlock.cycle.k_w variable */:0.0);
  TRACE_POP
}
/*
equation index: 702
type: SIMPLE_ASSIGN
powerBlock.W_gross = powerBlock.k_w * powerBlock.load * powerBlock.W_des * powerBlock.cool.nu_w
*/
void Reference_1_eqFunction_702(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,702};
  data->localData[0]->realVars[110] /* powerBlock.W_gross variable */ = (data->localData[0]->realVars[120] /* powerBlock.k_w variable */) * (((data->localData[0]->realVars[121] /* powerBlock.load variable */) * (data->simulationInfo->realParameter[185] /* powerBlock.W_des PARAM */)) * (data->localData[0]->realVars[113] /* powerBlock.cool.nu_w variable */));
  TRACE_POP
}
/*
equation index: 703
type: SIMPLE_ASSIGN
$DER.powerBlock.E_gross = powerBlock.W_gross
*/
void Reference_1_eqFunction_703(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,703};
  data->localData[0]->realVars[16] /* der(powerBlock.E_gross) STATE_DER */ = data->localData[0]->realVars[110] /* powerBlock.W_gross variable */;
  TRACE_POP
}
/*
equation index: 704
type: SIMPLE_ASSIGN
powerBlock.eff_pb = powerBlock.W_gross / $cse2
*/
void Reference_1_eqFunction_704(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,704};
  data->localData[0]->realVars[117] /* powerBlock.eff_pb variable */ = DIVISION_SIM(data->localData[0]->realVars[110] /* powerBlock.W_gross variable */,data->localData[0]->realVars[33] /* $cse2 variable */,"$cse2",equationIndexes);
  TRACE_POP
}
/*
equation index: 705
type: SIMPLE_ASSIGN
tankHot.Q_losses = (-tankHot.A) * tankHot.alpha * (powerBlock.T_in - Tamb_input.y)
*/
void Reference_1_eqFunction_705(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,705};
  data->localData[0]->realVars[178] /* tankHot.Q_losses variable */ = ((-data->localData[0]->realVars[177] /* tankHot.A variable */)) * ((data->simulationInfo->realParameter[270] /* tankHot.alpha PARAM */) * (data->localData[0]->realVars[108] /* powerBlock.T_in variable */ - data->localData[0]->realVars[57] /* Tamb_input.y variable */));
  TRACE_POP
}
/*
equation index: 706
type: ALGORITHM

  tankHot.W_net := pre(tankHot.W_net);
  $whenCondition21 := pre($whenCondition21);
  $whenCondition20 := pre($whenCondition20);
  $whenCondition20 := powerBlock.T_in < tankHot.T_set;
  $whenCondition21 := powerBlock.T_in > 1.0 + tankHot.T_set;
  when $whenCondition20 then
    tankHot.W_net := 10.0 * min(-tankHot.Q_losses, tankHot.W_max);
  elsewhen $whenCondition21 then
    tankHot.W_net := 0.0;
  end when;
*/
void Reference_1_eqFunction_706(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,706};
  modelica_boolean tmp9;
  modelica_boolean tmp10;
  data->localData[0]->realVars[222] /* tankHot.W_net DISCRETE */ = data->simulationInfo->realVarsPre[222] /* tankHot.W_net DISCRETE */;

  data->localData[0]->booleanVars[13] /* $whenCondition21 DISCRETE */ = data->simulationInfo->booleanVarsPre[13] /* $whenCondition21 DISCRETE */;

  data->localData[0]->booleanVars[12] /* $whenCondition20 DISCRETE */ = data->simulationInfo->booleanVarsPre[12] /* $whenCondition20 DISCRETE */;

  relationhysteresis(data, &tmp9, data->localData[0]->realVars[108] /* powerBlock.T_in variable */, data->simulationInfo->realParameter[266] /* tankHot.T_set PARAM */, 13, Less, LessZC);
  data->localData[0]->booleanVars[12] /* $whenCondition20 DISCRETE */ = tmp9;

  relationhysteresis(data, &tmp10, data->localData[0]->realVars[108] /* powerBlock.T_in variable */, 1.0 + data->simulationInfo->realParameter[266] /* tankHot.T_set PARAM */, 14, Greater, GreaterZC);
  data->localData[0]->booleanVars[13] /* $whenCondition21 DISCRETE */ = tmp10;

  if(data->simulationInfo->discreteCall == 1)
  {
    if((data->localData[0]->booleanVars[12] /* $whenCondition20 DISCRETE */ && !data->simulationInfo->booleanVarsPre[12] /* $whenCondition20 DISCRETE */ /* edge */))
    {
      data->localData[0]->realVars[222] /* tankHot.W_net DISCRETE */ = (10.0) * (fmin((-data->localData[0]->realVars[178] /* tankHot.Q_losses variable */),data->simulationInfo->realParameter[269] /* tankHot.W_max PARAM */));
    }
    else if((data->localData[0]->booleanVars[13] /* $whenCondition21 DISCRETE */ && !data->simulationInfo->booleanVarsPre[13] /* $whenCondition21 DISCRETE */ /* edge */))
    {
      data->localData[0]->realVars[222] /* tankHot.W_net DISCRETE */ = 0.0;
    }
  }
  TRACE_POP
}
/*
equation index: 707
type: SIMPLE_ASSIGN
tankHot.W_loss = tankHot.W_net / tankHot.e_ht
*/
void Reference_1_eqFunction_707(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,707};
  data->localData[0]->realVars[181] /* tankHot.W_loss variable */ = DIVISION_SIM(data->localData[0]->realVars[222] /* tankHot.W_net DISCRETE */,data->simulationInfo->realParameter[271] /* tankHot.e_ht PARAM */,"tankHot.e_ht",equationIndexes);
  TRACE_POP
}
/*
equation index: 708
type: SIMPLE_ASSIGN
parasities_input.y = heliostatField.W_loss + pumpHot.W_loss + pumpCold.W_loss + tankHot.W_loss + tankCold.W_loss
*/
void Reference_1_eqFunction_708(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,708};
  data->localData[0]->realVars[106] /* parasities_input.y variable */ = data->localData[0]->realVars[91] /* heliostatField.W_loss variable */ + data->localData[0]->realVars[125] /* pumpHot.W_loss variable */ + data->localData[0]->realVars[124] /* pumpCold.W_loss variable */ + data->localData[0]->realVars[181] /* tankHot.W_loss variable */ + data->localData[0]->realVars[165] /* tankCold.W_loss variable */;
  TRACE_POP
}
/*
equation index: 709
type: SIMPLE_ASSIGN
powerBlock.W_loss = (1.0 - powerBlock.nu_net) * powerBlock.W_gross + powerBlock.W_base + parasities_input.y
*/
void Reference_1_eqFunction_709(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,709};
  data->localData[0]->realVars[111] /* powerBlock.W_loss variable */ = (1.0 - data->simulationInfo->realParameter[195] /* powerBlock.nu_net PARAM */) * (data->localData[0]->realVars[110] /* powerBlock.W_gross variable */) + data->simulationInfo->realParameter[184] /* powerBlock.W_base PARAM */ + data->localData[0]->realVars[106] /* parasities_input.y variable */;
  TRACE_POP
}
/*
equation index: 710
type: SIMPLE_ASSIGN
P_elec = powerBlock.W_gross - powerBlock.W_loss
*/
void Reference_1_eqFunction_710(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,710};
  data->localData[0]->realVars[56] /* P_elec variable */ = data->localData[0]->realVars[110] /* powerBlock.W_gross variable */ - data->localData[0]->realVars[111] /* powerBlock.W_loss variable */;
  TRACE_POP
}
/*
equation index: 711
type: SIMPLE_ASSIGN
$DER.R_spot = 2.777777777777778e-10 * prices.y[1] * P_elec
*/
void Reference_1_eqFunction_711(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,711};
  data->localData[0]->realVars[11] /* der(R_spot) STATE_DER */ = (2.777777777777778e-10) * ((data->localData[0]->realVars[123] /* prices.y[1] variable */) * (data->localData[0]->realVars[56] /* P_elec variable */));
  TRACE_POP
}
/*
equation index: 712
type: SIMPLE_ASSIGN
$DER.market.profit = P_elec * market.price.price_annual
*/
void Reference_1_eqFunction_712(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,712};
  data->localData[0]->realVars[15] /* der(market.profit) STATE_DER */ = (data->localData[0]->realVars[56] /* P_elec variable */) * (data->simulationInfo->realParameter[170] /* market.price.price_annual PARAM */);
  TRACE_POP
}
/*
equation index: 713
type: SIMPLE_ASSIGN
$DER.powerBlock.E_net = P_elec
*/
void Reference_1_eqFunction_713(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,713};
  data->localData[0]->realVars[17] /* der(powerBlock.E_net) STATE_DER */ = data->localData[0]->realVars[56] /* P_elec variable */;
  TRACE_POP
}
/*
equation index: 714
type: SIMPLE_ASSIGN
$DER.tankHot.medium.h = (tankHot.Q_losses + tankHot.W_net + controlCold.m_flow * temperature.state.h - controlHot.m_flow * tankHot.medium.h - der(tankHot.m) * tankHot.medium.h) / tankHot.m
*/
void Reference_1_eqFunction_714(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,714};
  data->localData[0]->realVars[21] /* der(tankHot.medium.h) STATE_DER */ = DIVISION_SIM(data->localData[0]->realVars[178] /* tankHot.Q_losses variable */ + data->localData[0]->realVars[222] /* tankHot.W_net DISCRETE */ + (data->localData[0]->realVars[71] /* controlCold.m_flow variable */) * (data->localData[0]->realVars[192] /* temperature.state.h variable */) - ((data->localData[0]->realVars[75] /* controlHot.m_flow variable */) * (data->localData[0]->realVars[10] /* tankHot.medium.h STATE(1) */)) - ((data->localData[0]->realVars[20] /* der(tankHot.m) STATE_DER */) * (data->localData[0]->realVars[10] /* tankHot.medium.h STATE(1) */)),data->localData[0]->realVars[9] /* tankHot.m STATE(1) */,"tankHot.m",equationIndexes);
  TRACE_POP
}
/*
equation index: 715
type: SIMPLE_ASSIGN
tankHot.medium.T = powerBlock.T_in
*/
void Reference_1_eqFunction_715(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,715};
  data->localData[0]->realVars[184] /* tankHot.medium.T variable */ = data->localData[0]->realVars[108] /* powerBlock.T_in variable */;
  TRACE_POP
}
/*
equation index: 716
type: SIMPLE_ASSIGN
tankHot.T = powerBlock.T_in
*/
void Reference_1_eqFunction_716(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,716};
  data->localData[0]->realVars[179] /* tankHot.T variable */ = data->localData[0]->realVars[108] /* powerBlock.T_in variable */;
  TRACE_POP
}
/*
equation index: 717
type: SIMPLE_ASSIGN
wea.wtab.u[8] = time + wea.wtab.delay[8]
*/
void Reference_1_eqFunction_717(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,717};
  data->localData[0]->realVars[206] /* wea.wtab.u[8] variable */ = data->localData[0]->timeValue + data->simulationInfo->realParameter[310] /* wea.wtab.delay[8] PARAM */;
  TRACE_POP
}
/*
equation index: 718
type: SIMPLE_ASSIGN
wea.wtab.y[8] = Modelica.Blocks.Tables.Internal.getTable1DValue(wea.wtab.tableID, 8, wea.wtab.u[8])
*/
void Reference_1_eqFunction_718(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,718};
  data->localData[0]->realVars[213] /* wea.wtab.y[8] variable */ = omc_Modelica_Blocks_Tables_Internal_getTable1DValue(threadData, data->simulationInfo->extObjs[4], ((modelica_integer) 8), data->localData[0]->realVars[206] /* wea.wtab.u[8] variable */);
  TRACE_POP
}
/*
equation index: 719
type: SIMPLE_ASSIGN
sch_fixed.wbus.wspd = max(wea.wtab.y[8], 0.0)
*/
void Reference_1_eqFunction_719(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,719};
  data->localData[0]->realVars[155] /* sch_fixed.wbus.wspd variable */ = fmax(data->localData[0]->realVars[213] /* wea.wtab.y[8] variable */,0.0);
  TRACE_POP
}
/*
equation index: 720
type: SIMPLE_ASSIGN
wea.wtab.u[7] = time + wea.wtab.delay[7]
*/
void Reference_1_eqFunction_720(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,720};
  data->localData[0]->realVars[205] /* wea.wtab.u[7] variable */ = data->localData[0]->timeValue + data->simulationInfo->realParameter[309] /* wea.wtab.delay[7] PARAM */;
  TRACE_POP
}
/*
equation index: 721
type: SIMPLE_ASSIGN
sch_fixed.wbus.wdir = Modelica.Blocks.Tables.Internal.getTable1DValue(wea.wtab.tableID, 7, wea.wtab.u[7])
*/
void Reference_1_eqFunction_721(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,721};
  data->localData[0]->realVars[154] /* sch_fixed.wbus.wdir variable */ = omc_Modelica_Blocks_Tables_Internal_getTable1DValue(threadData, data->simulationInfo->extObjs[4], ((modelica_integer) 7), data->localData[0]->realVars[205] /* wea.wtab.u[7] variable */);
  TRACE_POP
}
/*
equation index: 722
type: SIMPLE_ASSIGN
wea.wtab.u[1] = time + wea.wtab.delay[1]
*/
void Reference_1_eqFunction_722(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,722};
  data->localData[0]->realVars[199] /* wea.wtab.u[1] variable */ = data->localData[0]->timeValue + data->simulationInfo->realParameter[303] /* wea.wtab.delay[1] PARAM */;
  TRACE_POP
}
/*
equation index: 723
type: SIMPLE_ASSIGN
wea.wtab.y[1] = Modelica.Blocks.Tables.Internal.getTable1DValue(wea.wtab.tableID, 1, wea.wtab.u[1])
*/
void Reference_1_eqFunction_723(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,723};
  data->localData[0]->realVars[207] /* wea.wtab.y[1] variable */ = omc_Modelica_Blocks_Tables_Internal_getTable1DValue(threadData, data->simulationInfo->extObjs[4], ((modelica_integer) 1), data->localData[0]->realVars[199] /* wea.wtab.u[1] variable */);
  TRACE_POP
}
/*
equation index: 724
type: SIMPLE_ASSIGN
sch_fixed.wbus.ghi = max(wea.wtab.y[1], 0.0)
*/
void Reference_1_eqFunction_724(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,724};
  data->localData[0]->realVars[151] /* sch_fixed.wbus.ghi variable */ = fmax(data->localData[0]->realVars[207] /* wea.wtab.y[1] variable */,0.0);
  TRACE_POP
}
/*
equation index: 725
type: SIMPLE_ASSIGN
wea.wtab.u[2] = time + wea.wtab.delay[2]
*/
void Reference_1_eqFunction_725(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,725};
  data->localData[0]->realVars[200] /* wea.wtab.u[2] variable */ = data->localData[0]->timeValue + data->simulationInfo->realParameter[304] /* wea.wtab.delay[2] PARAM */;
  TRACE_POP
}
/*
equation index: 726
type: SIMPLE_ASSIGN
wea.wtab.y[2] = Modelica.Blocks.Tables.Internal.getTable1DValue(wea.wtab.tableID, 2, wea.wtab.u[2])
*/
void Reference_1_eqFunction_726(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,726};
  data->localData[0]->realVars[208] /* wea.wtab.y[2] variable */ = omc_Modelica_Blocks_Tables_Internal_getTable1DValue(threadData, data->simulationInfo->extObjs[4], ((modelica_integer) 2), data->localData[0]->realVars[200] /* wea.wtab.u[2] variable */);
  TRACE_POP
}
/*
equation index: 727
type: SIMPLE_ASSIGN
sch_fixed.wbus.dni = max(wea.wtab.y[2], 0.0)
*/
void Reference_1_eqFunction_727(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,727};
  data->localData[0]->realVars[149] /* sch_fixed.wbus.dni variable */ = fmax(data->localData[0]->realVars[208] /* wea.wtab.y[2] variable */,0.0);
  TRACE_POP
}
/*
equation index: 728
type: SIMPLE_ASSIGN
wea.wtab.u[3] = time + wea.wtab.delay[3]
*/
void Reference_1_eqFunction_728(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,728};
  data->localData[0]->realVars[201] /* wea.wtab.u[3] variable */ = data->localData[0]->timeValue + data->simulationInfo->realParameter[305] /* wea.wtab.delay[3] PARAM */;
  TRACE_POP
}
/*
equation index: 729
type: SIMPLE_ASSIGN
wea.wtab.y[3] = Modelica.Blocks.Tables.Internal.getTable1DValue(wea.wtab.tableID, 3, wea.wtab.u[3])
*/
void Reference_1_eqFunction_729(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,729};
  data->localData[0]->realVars[209] /* wea.wtab.y[3] variable */ = omc_Modelica_Blocks_Tables_Internal_getTable1DValue(threadData, data->simulationInfo->extObjs[4], ((modelica_integer) 3), data->localData[0]->realVars[201] /* wea.wtab.u[3] variable */);
  TRACE_POP
}
/*
equation index: 730
type: SIMPLE_ASSIGN
sch_fixed.wbus.Tdry = 273.15 + wea.wtab.y[3]
*/
void Reference_1_eqFunction_730(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,730};
  data->localData[0]->realVars[145] /* sch_fixed.wbus.Tdry variable */ = 273.15 + data->localData[0]->realVars[209] /* wea.wtab.y[3] variable */;
  TRACE_POP
}
/*
equation index: 731
type: SIMPLE_ASSIGN
wea.wtab.u[4] = time + wea.wtab.delay[4]
*/
void Reference_1_eqFunction_731(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,731};
  data->localData[0]->realVars[202] /* wea.wtab.u[4] variable */ = data->localData[0]->timeValue + data->simulationInfo->realParameter[306] /* wea.wtab.delay[4] PARAM */;
  TRACE_POP
}
/*
equation index: 732
type: SIMPLE_ASSIGN
wea.wtab.y[4] = Modelica.Blocks.Tables.Internal.getTable1DValue(wea.wtab.tableID, 4, wea.wtab.u[4])
*/
void Reference_1_eqFunction_732(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,732};
  data->localData[0]->realVars[210] /* wea.wtab.y[4] variable */ = omc_Modelica_Blocks_Tables_Internal_getTable1DValue(threadData, data->simulationInfo->extObjs[4], ((modelica_integer) 4), data->localData[0]->realVars[202] /* wea.wtab.u[4] variable */);
  TRACE_POP
}
/*
equation index: 733
type: SIMPLE_ASSIGN
sch_fixed.wbus.Tdew = 273.15 + wea.wtab.y[4]
*/
void Reference_1_eqFunction_733(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,733};
  data->localData[0]->realVars[144] /* sch_fixed.wbus.Tdew variable */ = 273.15 + data->localData[0]->realVars[210] /* wea.wtab.y[4] variable */;
  TRACE_POP
}
/*
equation index: 734
type: SIMPLE_ASSIGN
wea.wtab.u[6] = time + wea.wtab.delay[6]
*/
void Reference_1_eqFunction_734(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,734};
  data->localData[0]->realVars[204] /* wea.wtab.u[6] variable */ = data->localData[0]->timeValue + data->simulationInfo->realParameter[308] /* wea.wtab.delay[6] PARAM */;
  TRACE_POP
}
/*
equation index: 735
type: SIMPLE_ASSIGN
wea.wtab.y[6] = Modelica.Blocks.Tables.Internal.getTable1DValue(wea.wtab.tableID, 6, wea.wtab.u[6])
*/
void Reference_1_eqFunction_735(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,735};
  data->localData[0]->realVars[212] /* wea.wtab.y[6] variable */ = omc_Modelica_Blocks_Tables_Internal_getTable1DValue(threadData, data->simulationInfo->extObjs[4], ((modelica_integer) 6), data->localData[0]->realVars[204] /* wea.wtab.u[6] variable */);
  TRACE_POP
}
/*
equation index: 736
type: SIMPLE_ASSIGN
wea.wtab.u[5] = time + wea.wtab.delay[5]
*/
void Reference_1_eqFunction_736(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,736};
  data->localData[0]->realVars[203] /* wea.wtab.u[5] variable */ = data->localData[0]->timeValue + data->simulationInfo->realParameter[307] /* wea.wtab.delay[5] PARAM */;
  TRACE_POP
}
/*
equation index: 737
type: SIMPLE_ASSIGN
wea.wtab.y[5] = Modelica.Blocks.Tables.Internal.getTable1DValue(wea.wtab.tableID, 5, wea.wtab.u[5])
*/
void Reference_1_eqFunction_737(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,737};
  data->localData[0]->realVars[211] /* wea.wtab.y[5] variable */ = omc_Modelica_Blocks_Tables_Internal_getTable1DValue(threadData, data->simulationInfo->extObjs[4], ((modelica_integer) 5), data->localData[0]->realVars[203] /* wea.wtab.u[5] variable */);
  TRACE_POP
}
/*
equation index: 747
type: ALGORITHM

  assert(sch_fixed.daily[1].table.tableName <> "NoName", "tableOnFile = true and no table name given");
*/
void Reference_1_eqFunction_747(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,747};
  static const MMC_DEFSTRINGLIT(tmp13,6,"NoName");
  static const MMC_DEFSTRINGLIT(tmp14,42,"tableOnFile = true and no table name given");
  static int tmp15 = 0;
  {
    if(!(!stringEqual(data->simulationInfo->stringParameter[14] /* sch_fixed.daily[1].table.tableName PARAM */, MMC_REFSTRINGLIT(tmp13))))
    {
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Blocks/Tables.mo",347,7,348,54,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nsch_fixed.daily[1].table.tableName <> \"NoName\"", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_withEquationIndexes(threadData, info, equationIndexes, MMC_STRINGDATA(MMC_REFSTRINGLIT(tmp14)));
      }
    }
  }
  TRACE_POP
}
/*
equation index: 746
type: ALGORITHM

  assert(prices.tableName <> "NoName", "tableOnFile = true and no table name given");
*/
void Reference_1_eqFunction_746(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,746};
  static const MMC_DEFSTRINGLIT(tmp18,6,"NoName");
  static const MMC_DEFSTRINGLIT(tmp19,42,"tableOnFile = true and no table name given");
  static int tmp20 = 0;
  {
    if(!(!stringEqual(data->simulationInfo->stringParameter[9] /* prices.tableName PARAM */, MMC_REFSTRINGLIT(tmp18))))
    {
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Blocks/Sources.mo",2205,7,2206,54,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nprices.tableName <> \"NoName\"", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_withEquationIndexes(threadData, info, equationIndexes, MMC_STRINGDATA(MMC_REFSTRINGLIT(tmp19)));
      }
    }
  }
  TRACE_POP
}
/*
equation index: 745
type: ALGORITHM

  assert(controlCold.PI.limiter.uMax >= controlCold.PI.limiter.uMin, "Limiter: Limits must be consistent. However, uMax (=" + String(controlCold.PI.limiter.uMax, 6, 0, true) + ") < uMin (=" + String(controlCold.PI.limiter.uMin, 6, 0, true) + ")");
*/
void Reference_1_eqFunction_745(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,745};
  modelica_boolean tmp21;
  static const MMC_DEFSTRINGLIT(tmp22,52,"Limiter: Limits must be consistent. However, uMax (=");
  modelica_string tmp23;
  static const MMC_DEFSTRINGLIT(tmp24,11,") < uMin (=");
  modelica_string tmp25;
  static int tmp26 = 0;
  modelica_metatype tmpMeta[4] __attribute__((unused)) = {0};
  {
    tmp21 = GreaterEq(data->simulationInfo->realParameter[74] /* controlCold.PI.limiter.uMax PARAM */,data->simulationInfo->realParameter[75] /* controlCold.PI.limiter.uMin PARAM */);
    if(!tmp21)
    {
      tmp23 = modelica_real_to_modelica_string(data->simulationInfo->realParameter[74] /* controlCold.PI.limiter.uMax PARAM */, ((modelica_integer) 6), ((modelica_integer) 0), 1);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp22),tmp23);
      tmpMeta[1] = stringAppend(tmpMeta[0],MMC_REFSTRINGLIT(tmp24));
      tmp25 = modelica_real_to_modelica_string(data->simulationInfo->realParameter[75] /* controlCold.PI.limiter.uMin PARAM */, ((modelica_integer) 6), ((modelica_integer) 0), 1);
      tmpMeta[2] = stringAppend(tmpMeta[1],tmp25);
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
equation index: 744
type: ALGORITHM

  assert(heliostatField.optical.nu_table.tableName <> "NoName", "tableOnFile = true and no table name given");
*/
void Reference_1_eqFunction_744(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,744};
  static const MMC_DEFSTRINGLIT(tmp29,6,"NoName");
  static const MMC_DEFSTRINGLIT(tmp30,42,"tableOnFile = true and no table name given");
  static int tmp31 = 0;
  {
    if(!(!stringEqual(data->simulationInfo->stringParameter[5] /* heliostatField.optical.nu_table.tableName PARAM */, MMC_REFSTRINGLIT(tmp29))))
    {
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Blocks/Tables.mo",993,11,994,58,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nheliostatField.optical.nu_table.tableName <> \"NoName\"", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_withEquationIndexes(threadData, info, equationIndexes, MMC_STRINGDATA(MMC_REFSTRINGLIT(tmp30)));
      }
    }
  }
  TRACE_POP
}
/*
equation index: 743
type: ALGORITHM

  assert(data.table.tableName <> "NoName", "tableOnFile = true and no table name given");
*/
void Reference_1_eqFunction_743(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,743};
  static const MMC_DEFSTRINGLIT(tmp34,6,"NoName");
  static const MMC_DEFSTRINGLIT(tmp35,42,"tableOnFile = true and no table name given");
  static int tmp36 = 0;
  {
    if(!(!stringEqual(data->simulationInfo->stringParameter[2] /* data.table.tableName PARAM */, MMC_REFSTRINGLIT(tmp34))))
    {
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Blocks/Sources.mo",2205,7,2206,54,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\ndata.table.tableName <> \"NoName\"", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_withEquationIndexes(threadData, info, equationIndexes, MMC_STRINGDATA(MMC_REFSTRINGLIT(tmp35)));
      }
    }
  }
  TRACE_POP
}
/*
equation index: 742
type: ALGORITHM

  assert(wea.wtab.tableName <> "NoName", "tableOnFile = true and no table name given");
*/
void Reference_1_eqFunction_742(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,742};
  static const MMC_DEFSTRINGLIT(tmp39,6,"NoName");
  static const MMC_DEFSTRINGLIT(tmp40,42,"tableOnFile = true and no table name given");
  static int tmp41 = 0;
  {
    if(!(!stringEqual(data->simulationInfo->stringParameter[20] /* wea.wtab.tableName PARAM */, MMC_REFSTRINGLIT(tmp39))))
    {
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Blocks/Tables.mo",56,7,57,54,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nwea.wtab.tableName <> \"NoName\"", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_withEquationIndexes(threadData, info, equationIndexes, MMC_STRINGDATA(MMC_REFSTRINGLIT(tmp40)));
      }
    }
  }
  TRACE_POP
}
/*
equation index: 741
type: WHEN

when {$whenCondition22} then
  reinit(controlCold.PI.I.y,  controlCold.PI.y_start / controlCold.PI.Kp + controlCold.PI.u);
end when;
*/
void Reference_1_eqFunction_741(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,741};
  if((data->localData[0]->booleanVars[14] /* $whenCondition22 DISCRETE */ && !data->simulationInfo->booleanVarsPre[14] /* $whenCondition22 DISCRETE */ /* edge */))
  {
    data->localData[0]->realVars[1] /* controlCold.PI.I.y STATE(1) */ = DIVISION_SIM(data->simulationInfo->realParameter[78] /* controlCold.PI.y_start PARAM */,data->simulationInfo->realParameter[64] /* controlCold.PI.Kp PARAM */,"controlCold.PI.Kp",equationIndexes) + data->localData[0]->realVars[66] /* controlCold.PI.u variable */;
    infoStreamPrint(LOG_EVENTS, 0, "reinit controlCold.PI.I.y = %g", data->localData[0]->realVars[1] /* controlCold.PI.I.y STATE(1) */);
    data->simulationInfo->needToIterate = 1;
  }
  TRACE_POP
}
/*
equation index: 740
type: ALGORITHM

  assert(tankCold.p_top_internal >= 0.0, "Pressure (= " + String(tankCold.p_top_internal, 6, 0, true) + " Pa) of medium \"" + "MoltenSalt" + "\" is negative
(Temperature = " + String(tankCold.T, 6, 0, true) + " K)");
*/
void Reference_1_eqFunction_740(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,740};
  modelica_boolean tmp42;
  static const MMC_DEFSTRINGLIT(tmp43,12,"Pressure (= ");
  modelica_string tmp44;
  static const MMC_DEFSTRINGLIT(tmp45,16," Pa) of medium \"");
  static const MMC_DEFSTRINGLIT(tmp46,10,"MoltenSalt");
  static const MMC_DEFSTRINGLIT(tmp47,29,"\" is negative\n(Temperature = ");
  modelica_string tmp48;
  static const MMC_DEFSTRINGLIT(tmp49,3," K)");
  static int tmp50 = 0;
  modelica_metatype tmpMeta[6] __attribute__((unused)) = {0};
  {
    tmp42 = GreaterEq(data->localData[0]->realVars[175] /* tankCold.p_top_internal variable */,0.0);
    if(!tmp42)
    {
      tmp44 = modelica_real_to_modelica_string(data->localData[0]->realVars[175] /* tankCold.p_top_internal variable */, ((modelica_integer) 6), ((modelica_integer) 0), 1);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp43),tmp44);
      tmpMeta[1] = stringAppend(tmpMeta[0],MMC_REFSTRINGLIT(tmp45));
      tmpMeta[2] = stringAppend(tmpMeta[1],MMC_REFSTRINGLIT(tmp46));
      tmpMeta[3] = stringAppend(tmpMeta[2],MMC_REFSTRINGLIT(tmp47));
      tmp48 = modelica_real_to_modelica_string(data->localData[0]->realVars[163] /* tankCold.T variable */, ((modelica_integer) 6), ((modelica_integer) 0), 1);
      tmpMeta[4] = stringAppend(tmpMeta[3],tmp48);
      tmpMeta[5] = stringAppend(tmpMeta[4],MMC_REFSTRINGLIT(tmp49));
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Media/package.mo",5067,7,5068,76,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\ntankCold.p_top_internal >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_withEquationIndexes(threadData, info, equationIndexes, MMC_STRINGDATA(tmpMeta[5]));
      }
    }
  }
  TRACE_POP
}
/*
equation index: 739
type: ALGORITHM

  assert(tankCold.p_top_internal >= 0.0, "Pressure (= " + String(tankCold.p_top_internal, 6, 0, true) + " Pa) of medium \"" + "MoltenSalt" + "\" is negative
(Temperature = " + String(powerBlock.T_in, 6, 0, true) + " K)");
*/
void Reference_1_eqFunction_739(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,739};
  modelica_boolean tmp51;
  static const MMC_DEFSTRINGLIT(tmp52,12,"Pressure (= ");
  modelica_string tmp53;
  static const MMC_DEFSTRINGLIT(tmp54,16," Pa) of medium \"");
  static const MMC_DEFSTRINGLIT(tmp55,10,"MoltenSalt");
  static const MMC_DEFSTRINGLIT(tmp56,29,"\" is negative\n(Temperature = ");
  modelica_string tmp57;
  static const MMC_DEFSTRINGLIT(tmp58,3," K)");
  static int tmp59 = 0;
  modelica_metatype tmpMeta[6] __attribute__((unused)) = {0};
  {
    tmp51 = GreaterEq(data->localData[0]->realVars[175] /* tankCold.p_top_internal variable */,0.0);
    if(!tmp51)
    {
      tmp53 = modelica_real_to_modelica_string(data->localData[0]->realVars[175] /* tankCold.p_top_internal variable */, ((modelica_integer) 6), ((modelica_integer) 0), 1);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp52),tmp53);
      tmpMeta[1] = stringAppend(tmpMeta[0],MMC_REFSTRINGLIT(tmp54));
      tmpMeta[2] = stringAppend(tmpMeta[1],MMC_REFSTRINGLIT(tmp55));
      tmpMeta[3] = stringAppend(tmpMeta[2],MMC_REFSTRINGLIT(tmp56));
      tmp57 = modelica_real_to_modelica_string(data->localData[0]->realVars[108] /* powerBlock.T_in variable */, ((modelica_integer) 6), ((modelica_integer) 0), 1);
      tmpMeta[4] = stringAppend(tmpMeta[3],tmp57);
      tmpMeta[5] = stringAppend(tmpMeta[4],MMC_REFSTRINGLIT(tmp58));
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Media/package.mo",5067,7,5068,76,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\ntankCold.p_top_internal >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_withEquationIndexes(threadData, info, equationIndexes, MMC_STRINGDATA(tmpMeta[5]));
      }
    }
  }
  TRACE_POP
}
/*
equation index: 738
type: ALGORITHM

  assert(tankCold.p_top_internal >= 0.0, "Pressure (= " + String(tankCold.p_top_internal, 6, 0, true) + " Pa) of medium \"" + "MoltenSalt" + "\" is negative
(Temperature = " + String(receiver.medium.T, 6, 0, true) + " K)");
*/
void Reference_1_eqFunction_738(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,738};
  modelica_boolean tmp60;
  static const MMC_DEFSTRINGLIT(tmp61,12,"Pressure (= ");
  modelica_string tmp62;
  static const MMC_DEFSTRINGLIT(tmp63,16," Pa) of medium \"");
  static const MMC_DEFSTRINGLIT(tmp64,10,"MoltenSalt");
  static const MMC_DEFSTRINGLIT(tmp65,29,"\" is negative\n(Temperature = ");
  modelica_string tmp66;
  static const MMC_DEFSTRINGLIT(tmp67,3," K)");
  static int tmp68 = 0;
  modelica_metatype tmpMeta[6] __attribute__((unused)) = {0};
  {
    tmp60 = GreaterEq(data->localData[0]->realVars[175] /* tankCold.p_top_internal variable */,0.0);
    if(!tmp60)
    {
      tmp62 = modelica_real_to_modelica_string(data->localData[0]->realVars[175] /* tankCold.p_top_internal variable */, ((modelica_integer) 6), ((modelica_integer) 0), 1);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp61),tmp62);
      tmpMeta[1] = stringAppend(tmpMeta[0],MMC_REFSTRINGLIT(tmp63));
      tmpMeta[2] = stringAppend(tmpMeta[1],MMC_REFSTRINGLIT(tmp64));
      tmpMeta[3] = stringAppend(tmpMeta[2],MMC_REFSTRINGLIT(tmp65));
      tmp66 = modelica_real_to_modelica_string(data->localData[0]->realVars[135] /* receiver.medium.T variable */, ((modelica_integer) 6), ((modelica_integer) 0), 1);
      tmpMeta[4] = stringAppend(tmpMeta[3],tmp66);
      tmpMeta[5] = stringAppend(tmpMeta[4],MMC_REFSTRINGLIT(tmp67));
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Media/package.mo",5067,7,5068,76,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\ntankCold.p_top_internal >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_withEquationIndexes(threadData, info, equationIndexes, MMC_STRINGDATA(tmpMeta[5]));
      }
    }
  }
  TRACE_POP
}

OMC_DISABLE_OPT
int Reference_1_functionDAE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  int equationIndexes[1] = {0};
  modelica_metatype tmpMeta[6] __attribute__((unused)) = {0};
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_DAE);
#endif

  data->simulationInfo->needToIterate = 0;
  data->simulationInfo->discreteCall = 1;
  Reference_1_functionLocalKnownVars(data, threadData);
  Reference_1_eqFunction_505(data, threadData);

  Reference_1_eqFunction_506(data, threadData);

  Reference_1_eqFunction_507(data, threadData);

  Reference_1_eqFunction_508(data, threadData);

  Reference_1_eqFunction_509(data, threadData);

  Reference_1_eqFunction_510(data, threadData);

  Reference_1_eqFunction_511(data, threadData);

  Reference_1_eqFunction_512(data, threadData);

  Reference_1_eqFunction_513(data, threadData);

  Reference_1_eqFunction_514(data, threadData);

  Reference_1_eqFunction_515(data, threadData);

  Reference_1_eqFunction_516(data, threadData);

  Reference_1_eqFunction_517(data, threadData);

  Reference_1_eqFunction_518(data, threadData);

  Reference_1_eqFunction_519(data, threadData);

  Reference_1_eqFunction_520(data, threadData);

  Reference_1_eqFunction_521(data, threadData);

  Reference_1_eqFunction_522(data, threadData);

  Reference_1_eqFunction_523(data, threadData);

  Reference_1_eqFunction_524(data, threadData);

  Reference_1_eqFunction_525(data, threadData);

  Reference_1_eqFunction_526(data, threadData);

  Reference_1_eqFunction_527(data, threadData);

  Reference_1_eqFunction_528(data, threadData);

  Reference_1_eqFunction_529(data, threadData);

  Reference_1_eqFunction_530(data, threadData);

  Reference_1_eqFunction_531(data, threadData);

  Reference_1_eqFunction_532(data, threadData);

  Reference_1_eqFunction_533(data, threadData);

  Reference_1_eqFunction_534(data, threadData);

  Reference_1_eqFunction_535(data, threadData);

  Reference_1_eqFunction_536(data, threadData);

  Reference_1_eqFunction_537(data, threadData);

  Reference_1_eqFunction_538(data, threadData);

  Reference_1_eqFunction_539(data, threadData);

  Reference_1_eqFunction_540(data, threadData);

  Reference_1_eqFunction_541(data, threadData);

  Reference_1_eqFunction_542(data, threadData);

  Reference_1_eqFunction_543(data, threadData);

  Reference_1_eqFunction_544(data, threadData);

  Reference_1_eqFunction_545(data, threadData);

  Reference_1_eqFunction_546(data, threadData);

  Reference_1_eqFunction_547(data, threadData);

  Reference_1_eqFunction_548(data, threadData);

  Reference_1_eqFunction_549(data, threadData);

  Reference_1_eqFunction_550(data, threadData);

  Reference_1_eqFunction_551(data, threadData);

  Reference_1_eqFunction_552(data, threadData);

  Reference_1_eqFunction_553(data, threadData);

  Reference_1_eqFunction_554(data, threadData);

  Reference_1_eqFunction_555(data, threadData);

  Reference_1_eqFunction_556(data, threadData);

  Reference_1_eqFunction_557(data, threadData);

  Reference_1_eqFunction_558(data, threadData);

  Reference_1_eqFunction_559(data, threadData);

  Reference_1_eqFunction_560(data, threadData);

  Reference_1_eqFunction_561(data, threadData);

  Reference_1_eqFunction_562(data, threadData);

  Reference_1_eqFunction_563(data, threadData);

  Reference_1_eqFunction_564(data, threadData);

  Reference_1_eqFunction_565(data, threadData);

  Reference_1_eqFunction_566(data, threadData);

  Reference_1_eqFunction_567(data, threadData);

  Reference_1_eqFunction_568(data, threadData);

  Reference_1_eqFunction_569(data, threadData);

  Reference_1_eqFunction_570(data, threadData);

  Reference_1_eqFunction_571(data, threadData);

  Reference_1_eqFunction_572(data, threadData);

  Reference_1_eqFunction_573(data, threadData);

  Reference_1_eqFunction_574(data, threadData);

  Reference_1_eqFunction_575(data, threadData);

  Reference_1_eqFunction_576(data, threadData);

  Reference_1_eqFunction_577(data, threadData);

  Reference_1_eqFunction_578(data, threadData);

  Reference_1_eqFunction_579(data, threadData);

  Reference_1_eqFunction_580(data, threadData);

  Reference_1_eqFunction_581(data, threadData);

  Reference_1_eqFunction_582(data, threadData);

  Reference_1_eqFunction_583(data, threadData);

  Reference_1_eqFunction_584(data, threadData);

  Reference_1_eqFunction_585(data, threadData);

  Reference_1_eqFunction_586(data, threadData);

  Reference_1_eqFunction_587(data, threadData);

  Reference_1_eqFunction_588(data, threadData);

  Reference_1_eqFunction_589(data, threadData);

  Reference_1_eqFunction_590(data, threadData);

  Reference_1_eqFunction_591(data, threadData);

  Reference_1_eqFunction_592(data, threadData);

  Reference_1_eqFunction_593(data, threadData);

  Reference_1_eqFunction_594(data, threadData);

  Reference_1_eqFunction_595(data, threadData);

  Reference_1_eqFunction_596(data, threadData);

  Reference_1_eqFunction_597(data, threadData);

  Reference_1_eqFunction_598(data, threadData);

  Reference_1_eqFunction_599(data, threadData);

  Reference_1_eqFunction_600(data, threadData);

  Reference_1_eqFunction_601(data, threadData);

  Reference_1_eqFunction_603(data, threadData);

  Reference_1_eqFunction_604(data, threadData);

  Reference_1_eqFunction_605(data, threadData);

  Reference_1_eqFunction_606(data, threadData);

  Reference_1_eqFunction_607(data, threadData);

  Reference_1_eqFunction_608(data, threadData);

  Reference_1_eqFunction_609(data, threadData);

  Reference_1_eqFunction_610(data, threadData);

  Reference_1_eqFunction_611(data, threadData);

  Reference_1_eqFunction_612(data, threadData);

  Reference_1_eqFunction_614(data, threadData);

  Reference_1_eqFunction_615(data, threadData);

  Reference_1_eqFunction_616(data, threadData);

  Reference_1_eqFunction_618(data, threadData);

  Reference_1_eqFunction_619(data, threadData);

  Reference_1_eqFunction_620(data, threadData);

  Reference_1_eqFunction_621(data, threadData);

  Reference_1_eqFunction_622(data, threadData);

  Reference_1_eqFunction_623(data, threadData);

  Reference_1_eqFunction_624(data, threadData);

  Reference_1_eqFunction_625(data, threadData);

  Reference_1_eqFunction_626(data, threadData);

  Reference_1_eqFunction_627(data, threadData);

  Reference_1_eqFunction_628(data, threadData);

  Reference_1_eqFunction_629(data, threadData);

  Reference_1_eqFunction_630(data, threadData);

  Reference_1_eqFunction_631(data, threadData);

  Reference_1_eqFunction_632(data, threadData);

  Reference_1_eqFunction_633(data, threadData);

  Reference_1_eqFunction_634(data, threadData);

  Reference_1_eqFunction_636(data, threadData);

  Reference_1_eqFunction_637(data, threadData);

  Reference_1_eqFunction_638(data, threadData);

  Reference_1_eqFunction_639(data, threadData);

  Reference_1_eqFunction_640(data, threadData);

  Reference_1_eqFunction_641(data, threadData);

  Reference_1_eqFunction_642(data, threadData);

  Reference_1_eqFunction_643(data, threadData);

  Reference_1_eqFunction_655(data, threadData);

  Reference_1_eqFunction_656(data, threadData);

  Reference_1_eqFunction_657(data, threadData);

  Reference_1_eqFunction_658(data, threadData);

  Reference_1_eqFunction_659(data, threadData);

  Reference_1_eqFunction_660(data, threadData);

  Reference_1_eqFunction_661(data, threadData);

  Reference_1_eqFunction_662(data, threadData);

  Reference_1_eqFunction_663(data, threadData);

  Reference_1_eqFunction_664(data, threadData);

  Reference_1_eqFunction_665(data, threadData);

  Reference_1_eqFunction_666(data, threadData);

  Reference_1_eqFunction_667(data, threadData);

  Reference_1_eqFunction_668(data, threadData);

  Reference_1_eqFunction_669(data, threadData);

  Reference_1_eqFunction_670(data, threadData);

  Reference_1_eqFunction_671(data, threadData);

  Reference_1_eqFunction_673(data, threadData);

  Reference_1_eqFunction_674(data, threadData);

  Reference_1_eqFunction_675(data, threadData);

  Reference_1_eqFunction_676(data, threadData);

  Reference_1_eqFunction_677(data, threadData);

  Reference_1_eqFunction_678(data, threadData);

  Reference_1_eqFunction_679(data, threadData);

  Reference_1_eqFunction_680(data, threadData);

  Reference_1_eqFunction_682(data, threadData);

  Reference_1_eqFunction_683(data, threadData);

  Reference_1_eqFunction_684(data, threadData);

  Reference_1_eqFunction_685(data, threadData);

  Reference_1_eqFunction_686(data, threadData);

  Reference_1_eqFunction_687(data, threadData);

  Reference_1_eqFunction_688(data, threadData);

  Reference_1_eqFunction_689(data, threadData);

  Reference_1_eqFunction_690(data, threadData);

  Reference_1_eqFunction_691(data, threadData);

  Reference_1_eqFunction_692(data, threadData);

  Reference_1_eqFunction_693(data, threadData);

  Reference_1_eqFunction_694(data, threadData);

  Reference_1_eqFunction_695(data, threadData);

  Reference_1_eqFunction_696(data, threadData);

  Reference_1_eqFunction_697(data, threadData);

  Reference_1_eqFunction_698(data, threadData);

  Reference_1_eqFunction_699(data, threadData);

  Reference_1_eqFunction_700(data, threadData);

  Reference_1_eqFunction_701(data, threadData);

  Reference_1_eqFunction_702(data, threadData);

  Reference_1_eqFunction_703(data, threadData);

  Reference_1_eqFunction_704(data, threadData);

  Reference_1_eqFunction_705(data, threadData);

  Reference_1_eqFunction_706(data, threadData);

  Reference_1_eqFunction_707(data, threadData);

  Reference_1_eqFunction_708(data, threadData);

  Reference_1_eqFunction_709(data, threadData);

  Reference_1_eqFunction_710(data, threadData);

  Reference_1_eqFunction_711(data, threadData);

  Reference_1_eqFunction_712(data, threadData);

  Reference_1_eqFunction_713(data, threadData);

  Reference_1_eqFunction_714(data, threadData);

  Reference_1_eqFunction_715(data, threadData);

  Reference_1_eqFunction_716(data, threadData);

  Reference_1_eqFunction_717(data, threadData);

  Reference_1_eqFunction_718(data, threadData);

  Reference_1_eqFunction_719(data, threadData);

  Reference_1_eqFunction_720(data, threadData);

  Reference_1_eqFunction_721(data, threadData);

  Reference_1_eqFunction_722(data, threadData);

  Reference_1_eqFunction_723(data, threadData);

  Reference_1_eqFunction_724(data, threadData);

  Reference_1_eqFunction_725(data, threadData);

  Reference_1_eqFunction_726(data, threadData);

  Reference_1_eqFunction_727(data, threadData);

  Reference_1_eqFunction_728(data, threadData);

  Reference_1_eqFunction_729(data, threadData);

  Reference_1_eqFunction_730(data, threadData);

  Reference_1_eqFunction_731(data, threadData);

  Reference_1_eqFunction_732(data, threadData);

  Reference_1_eqFunction_733(data, threadData);

  Reference_1_eqFunction_734(data, threadData);

  Reference_1_eqFunction_735(data, threadData);

  Reference_1_eqFunction_736(data, threadData);

  Reference_1_eqFunction_737(data, threadData);

  Reference_1_eqFunction_747(data, threadData);

  Reference_1_eqFunction_746(data, threadData);

  Reference_1_eqFunction_745(data, threadData);

  Reference_1_eqFunction_744(data, threadData);

  Reference_1_eqFunction_743(data, threadData);

  Reference_1_eqFunction_742(data, threadData);

  Reference_1_eqFunction_741(data, threadData);

  Reference_1_eqFunction_740(data, threadData);

  Reference_1_eqFunction_739(data, threadData);

  Reference_1_eqFunction_738(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_DAE);
#endif
  TRACE_POP
  return 0;
}


int Reference_1_functionLocalKnownVars(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}


/* forwarded equations */
extern void Reference_1_eqFunction_505(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_506(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_507(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_508(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_509(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_534(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_538(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_539(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_540(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_541(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_544(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_545(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_546(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_547(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_559(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_560(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_567(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_569(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_570(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_585(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_587(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_588(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_589(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_590(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_591(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_592(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_593(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_594(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_597(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_598(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_599(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_600(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_605(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_607(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_608(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_609(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_610(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_611(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_614(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_615(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_618(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_620(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_623(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_624(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_625(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_628(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_629(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_630(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_631(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_632(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_633(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_636(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_637(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_638(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_639(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_640(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_641(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_642(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_643(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_655(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_656(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_657(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_658(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_659(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_660(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_661(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_662(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_669(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_670(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_673(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_675(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_676(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_678(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_679(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_682(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_683(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_684(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_685(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_686(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_687(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_688(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_692(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_693(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_694(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_695(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_697(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_699(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_700(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_701(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_702(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_703(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_705(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_706(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_707(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_708(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_709(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_710(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_711(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_712(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_713(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_714(DATA* data, threadData_t *threadData);

static void functionODE_system0(DATA *data, threadData_t *threadData)
{
  Reference_1_eqFunction_505(data, threadData);
  threadData->lastEquationSolved = 505;
  Reference_1_eqFunction_506(data, threadData);
  threadData->lastEquationSolved = 506;
  Reference_1_eqFunction_507(data, threadData);
  threadData->lastEquationSolved = 507;
  Reference_1_eqFunction_508(data, threadData);
  threadData->lastEquationSolved = 508;
  Reference_1_eqFunction_509(data, threadData);
  threadData->lastEquationSolved = 509;
  Reference_1_eqFunction_534(data, threadData);
  threadData->lastEquationSolved = 534;
  Reference_1_eqFunction_538(data, threadData);
  threadData->lastEquationSolved = 538;
  Reference_1_eqFunction_539(data, threadData);
  threadData->lastEquationSolved = 539;
  Reference_1_eqFunction_540(data, threadData);
  threadData->lastEquationSolved = 540;
  Reference_1_eqFunction_541(data, threadData);
  threadData->lastEquationSolved = 541;
  Reference_1_eqFunction_544(data, threadData);
  threadData->lastEquationSolved = 544;
  Reference_1_eqFunction_545(data, threadData);
  threadData->lastEquationSolved = 545;
  Reference_1_eqFunction_546(data, threadData);
  threadData->lastEquationSolved = 546;
  Reference_1_eqFunction_547(data, threadData);
  threadData->lastEquationSolved = 547;
  Reference_1_eqFunction_559(data, threadData);
  threadData->lastEquationSolved = 559;
  Reference_1_eqFunction_560(data, threadData);
  threadData->lastEquationSolved = 560;
  Reference_1_eqFunction_567(data, threadData);
  threadData->lastEquationSolved = 567;
  Reference_1_eqFunction_569(data, threadData);
  threadData->lastEquationSolved = 569;
  Reference_1_eqFunction_570(data, threadData);
  threadData->lastEquationSolved = 570;
  Reference_1_eqFunction_585(data, threadData);
  threadData->lastEquationSolved = 585;
  Reference_1_eqFunction_587(data, threadData);
  threadData->lastEquationSolved = 587;
  Reference_1_eqFunction_588(data, threadData);
  threadData->lastEquationSolved = 588;
  Reference_1_eqFunction_589(data, threadData);
  threadData->lastEquationSolved = 589;
  Reference_1_eqFunction_590(data, threadData);
  threadData->lastEquationSolved = 590;
  Reference_1_eqFunction_591(data, threadData);
  threadData->lastEquationSolved = 591;
  Reference_1_eqFunction_592(data, threadData);
  threadData->lastEquationSolved = 592;
  Reference_1_eqFunction_593(data, threadData);
  threadData->lastEquationSolved = 593;
  Reference_1_eqFunction_594(data, threadData);
  threadData->lastEquationSolved = 594;
  Reference_1_eqFunction_597(data, threadData);
  threadData->lastEquationSolved = 597;
  Reference_1_eqFunction_598(data, threadData);
  threadData->lastEquationSolved = 598;
  Reference_1_eqFunction_599(data, threadData);
  threadData->lastEquationSolved = 599;
  Reference_1_eqFunction_600(data, threadData);
  threadData->lastEquationSolved = 600;
  Reference_1_eqFunction_605(data, threadData);
  threadData->lastEquationSolved = 605;
  Reference_1_eqFunction_607(data, threadData);
  threadData->lastEquationSolved = 607;
  Reference_1_eqFunction_608(data, threadData);
  threadData->lastEquationSolved = 608;
  Reference_1_eqFunction_609(data, threadData);
  threadData->lastEquationSolved = 609;
  Reference_1_eqFunction_610(data, threadData);
  threadData->lastEquationSolved = 610;
  Reference_1_eqFunction_611(data, threadData);
  threadData->lastEquationSolved = 611;
  Reference_1_eqFunction_614(data, threadData);
  threadData->lastEquationSolved = 614;
  Reference_1_eqFunction_615(data, threadData);
  threadData->lastEquationSolved = 615;
  Reference_1_eqFunction_618(data, threadData);
  threadData->lastEquationSolved = 618;
  Reference_1_eqFunction_620(data, threadData);
  threadData->lastEquationSolved = 620;
  Reference_1_eqFunction_623(data, threadData);
  threadData->lastEquationSolved = 623;
  Reference_1_eqFunction_624(data, threadData);
  threadData->lastEquationSolved = 624;
  Reference_1_eqFunction_625(data, threadData);
  threadData->lastEquationSolved = 625;
  Reference_1_eqFunction_628(data, threadData);
  threadData->lastEquationSolved = 628;
  Reference_1_eqFunction_629(data, threadData);
  threadData->lastEquationSolved = 629;
  Reference_1_eqFunction_630(data, threadData);
  threadData->lastEquationSolved = 630;
  Reference_1_eqFunction_631(data, threadData);
  threadData->lastEquationSolved = 631;
  Reference_1_eqFunction_632(data, threadData);
  threadData->lastEquationSolved = 632;
  Reference_1_eqFunction_633(data, threadData);
  threadData->lastEquationSolved = 633;
  Reference_1_eqFunction_636(data, threadData);
  threadData->lastEquationSolved = 636;
  Reference_1_eqFunction_637(data, threadData);
  threadData->lastEquationSolved = 637;
  Reference_1_eqFunction_638(data, threadData);
  threadData->lastEquationSolved = 638;
  Reference_1_eqFunction_639(data, threadData);
  threadData->lastEquationSolved = 639;
  Reference_1_eqFunction_640(data, threadData);
  threadData->lastEquationSolved = 640;
  Reference_1_eqFunction_641(data, threadData);
  threadData->lastEquationSolved = 641;
  Reference_1_eqFunction_642(data, threadData);
  threadData->lastEquationSolved = 642;
  Reference_1_eqFunction_643(data, threadData);
  threadData->lastEquationSolved = 643;
  Reference_1_eqFunction_655(data, threadData);
  threadData->lastEquationSolved = 655;
  Reference_1_eqFunction_656(data, threadData);
  threadData->lastEquationSolved = 656;
  Reference_1_eqFunction_657(data, threadData);
  threadData->lastEquationSolved = 657;
  Reference_1_eqFunction_658(data, threadData);
  threadData->lastEquationSolved = 658;
  Reference_1_eqFunction_659(data, threadData);
  threadData->lastEquationSolved = 659;
  Reference_1_eqFunction_660(data, threadData);
  threadData->lastEquationSolved = 660;
  Reference_1_eqFunction_661(data, threadData);
  threadData->lastEquationSolved = 661;
  Reference_1_eqFunction_662(data, threadData);
  threadData->lastEquationSolved = 662;
  Reference_1_eqFunction_669(data, threadData);
  threadData->lastEquationSolved = 669;
  Reference_1_eqFunction_670(data, threadData);
  threadData->lastEquationSolved = 670;
  Reference_1_eqFunction_673(data, threadData);
  threadData->lastEquationSolved = 673;
  Reference_1_eqFunction_675(data, threadData);
  threadData->lastEquationSolved = 675;
  Reference_1_eqFunction_676(data, threadData);
  threadData->lastEquationSolved = 676;
  Reference_1_eqFunction_678(data, threadData);
  threadData->lastEquationSolved = 678;
  Reference_1_eqFunction_679(data, threadData);
  threadData->lastEquationSolved = 679;
  Reference_1_eqFunction_682(data, threadData);
  threadData->lastEquationSolved = 682;
  Reference_1_eqFunction_683(data, threadData);
  threadData->lastEquationSolved = 683;
  Reference_1_eqFunction_684(data, threadData);
  threadData->lastEquationSolved = 684;
  Reference_1_eqFunction_685(data, threadData);
  threadData->lastEquationSolved = 685;
  Reference_1_eqFunction_686(data, threadData);
  threadData->lastEquationSolved = 686;
  Reference_1_eqFunction_687(data, threadData);
  threadData->lastEquationSolved = 687;
  Reference_1_eqFunction_688(data, threadData);
  threadData->lastEquationSolved = 688;
  Reference_1_eqFunction_692(data, threadData);
  threadData->lastEquationSolved = 692;
  Reference_1_eqFunction_693(data, threadData);
  threadData->lastEquationSolved = 693;
  Reference_1_eqFunction_694(data, threadData);
  threadData->lastEquationSolved = 694;
  Reference_1_eqFunction_695(data, threadData);
  threadData->lastEquationSolved = 695;
  Reference_1_eqFunction_697(data, threadData);
  threadData->lastEquationSolved = 697;
  Reference_1_eqFunction_699(data, threadData);
  threadData->lastEquationSolved = 699;
  Reference_1_eqFunction_700(data, threadData);
  threadData->lastEquationSolved = 700;
  Reference_1_eqFunction_701(data, threadData);
  threadData->lastEquationSolved = 701;
  Reference_1_eqFunction_702(data, threadData);
  threadData->lastEquationSolved = 702;
  Reference_1_eqFunction_703(data, threadData);
  threadData->lastEquationSolved = 703;
  Reference_1_eqFunction_705(data, threadData);
  threadData->lastEquationSolved = 705;
  Reference_1_eqFunction_706(data, threadData);
  threadData->lastEquationSolved = 706;
  Reference_1_eqFunction_707(data, threadData);
  threadData->lastEquationSolved = 707;
  Reference_1_eqFunction_708(data, threadData);
  threadData->lastEquationSolved = 708;
  Reference_1_eqFunction_709(data, threadData);
  threadData->lastEquationSolved = 709;
  Reference_1_eqFunction_710(data, threadData);
  threadData->lastEquationSolved = 710;
  Reference_1_eqFunction_711(data, threadData);
  threadData->lastEquationSolved = 711;
  Reference_1_eqFunction_712(data, threadData);
  threadData->lastEquationSolved = 712;
  Reference_1_eqFunction_713(data, threadData);
  threadData->lastEquationSolved = 713;
  Reference_1_eqFunction_714(data, threadData);
  threadData->lastEquationSolved = 714;
}

int Reference_1_functionODE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_FUNCTION_ODE);
#endif

  
  data->simulationInfo->callStatistics.functionODE++;
  
  Reference_1_functionLocalKnownVars(data, threadData);
  functionODE_system0(data, threadData);

#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_FUNCTION_ODE);
#endif

  TRACE_POP
  return 0;
}

/* forward the main in the simulation runtime */
extern int _main_SimulationRuntime(int argc, char**argv, DATA *data, threadData_t *threadData);

#include "Reference_1_12jac.h"
#include "Reference_1_13opt.h"

struct OpenModelicaGeneratedFunctionCallbacks Reference_1_callback = {
   (int (*)(DATA *, threadData_t *, void *)) Reference_1_performSimulation,    /* performSimulation */
   (int (*)(DATA *, threadData_t *, void *)) Reference_1_performQSSSimulation,    /* performQSSSimulation */
   Reference_1_updateContinuousSystem,    /* updateContinuousSystem */
   Reference_1_callExternalObjectDestructors,    /* callExternalObjectDestructors */
   Reference_1_initialNonLinearSystem,    /* initialNonLinearSystem */
   NULL,    /* initialLinearSystem */
   NULL,    /* initialMixedSystem */
   #if !defined(OMC_NO_STATESELECTION)
   Reference_1_initializeStateSets,
   #else
   NULL,
   #endif    /* initializeStateSets */
   Reference_1_initializeDAEmodeData,
   Reference_1_functionODE,
   Reference_1_functionAlgebraics,
   Reference_1_functionDAE,
   Reference_1_functionLocalKnownVars,
   Reference_1_input_function,
   Reference_1_input_function_init,
   Reference_1_input_function_updateStartValues,
   Reference_1_data_function,
   Reference_1_output_function,
   Reference_1_setc_function,
   Reference_1_function_storeDelayed,
   Reference_1_function_storeSpatialDistribution,
   Reference_1_function_initSpatialDistribution,
   Reference_1_updateBoundVariableAttributes,
   Reference_1_functionInitialEquations,
   1, /* useHomotopy - 0: local homotopy (equidistant lambda), 1: global homotopy (equidistant lambda), 2: new global homotopy approach (adaptive lambda), 3: new local homotopy approach (adaptive lambda)*/
   Reference_1_functionInitialEquations_lambda0,
   Reference_1_functionRemovedInitialEquations,
   Reference_1_updateBoundParameters,
   Reference_1_checkForAsserts,
   Reference_1_function_ZeroCrossingsEquations,
   Reference_1_function_ZeroCrossings,
   Reference_1_function_updateRelations,
   Reference_1_zeroCrossingDescription,
   Reference_1_relationDescription,
   Reference_1_function_initSample,
   Reference_1_INDEX_JAC_A,
   Reference_1_INDEX_JAC_B,
   Reference_1_INDEX_JAC_C,
   Reference_1_INDEX_JAC_D,
   Reference_1_INDEX_JAC_F,
   Reference_1_initialAnalyticJacobianA,
   Reference_1_initialAnalyticJacobianB,
   Reference_1_initialAnalyticJacobianC,
   Reference_1_initialAnalyticJacobianD,
   Reference_1_initialAnalyticJacobianF,
   Reference_1_functionJacA_column,
   Reference_1_functionJacB_column,
   Reference_1_functionJacC_column,
   Reference_1_functionJacD_column,
   Reference_1_functionJacF_column,
   Reference_1_linear_model_frame,
   Reference_1_linear_model_datarecovery_frame,
   Reference_1_mayer,
   Reference_1_lagrange,
   Reference_1_pickUpBoundsForInputsInOptimization,
   Reference_1_setInputData,
   Reference_1_getTimeGrid,
   Reference_1_symbolicInlineSystem,
   Reference_1_function_initSynchronous,
   Reference_1_function_updateSynchronous,
   Reference_1_function_equationsSynchronous,
   Reference_1_inputNames,
   Reference_1_dataReconciliationInputNames,
   NULL,
   NULL,
   NULL,
   -1

};

#define _OMC_LIT_RESOURCE_0_name_data "Complex"
#define _OMC_LIT_RESOURCE_0_dir_data "/usr/lib/omlibrary"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_0_name,7,_OMC_LIT_RESOURCE_0_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_0_dir,18,_OMC_LIT_RESOURCE_0_dir_data);

#define _OMC_LIT_RESOURCE_1_name_data "Modelica"
#define _OMC_LIT_RESOURCE_1_dir_data "/usr/lib/omlibrary/Modelica 3.2.3"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_1_name,8,_OMC_LIT_RESOURCE_1_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_1_dir,33,_OMC_LIT_RESOURCE_1_dir_data);

#define _OMC_LIT_RESOURCE_2_name_data "ModelicaServices"
#define _OMC_LIT_RESOURCE_2_dir_data "/usr/lib/omlibrary/ModelicaServices 3.2.3"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_2_name,16,_OMC_LIT_RESOURCE_2_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_2_dir,41,_OMC_LIT_RESOURCE_2_dir_data);

#define _OMC_LIT_RESOURCE_3_name_data "Reference_1"
#define _OMC_LIT_RESOURCE_3_dir_data "/home/cparrado/.openmodelica/libraries/SolarTherm/Systems"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_3_name,11,_OMC_LIT_RESOURCE_3_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_3_dir,57,_OMC_LIT_RESOURCE_3_dir_data);

#define _OMC_LIT_RESOURCE_4_name_data "SolarTherm"
#define _OMC_LIT_RESOURCE_4_dir_data "/home/cparrado/.openmodelica/libraries/SolarTherm"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_4_name,10,_OMC_LIT_RESOURCE_4_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_4_dir,49,_OMC_LIT_RESOURCE_4_dir_data);

static const MMC_DEFSTRUCTLIT(_OMC_LIT_RESOURCES,10,MMC_ARRAY_TAG) {MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_0_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_0_dir), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_1_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_1_dir), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_2_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_2_dir), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_3_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_3_dir), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_4_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_4_dir)}};
void Reference_1_setupDataStruc(DATA *data, threadData_t *threadData)
{
  assertStreamPrint(threadData,0!=data, "Error while initialize Data");
  threadData->localRoots[LOCAL_ROOT_SIMULATION_DATA] = data;
  data->callback = &Reference_1_callback;
  OpenModelica_updateUriMapping(threadData, MMC_REFSTRUCTLIT(_OMC_LIT_RESOURCES));
  data->modelData->modelName = "Reference_1";
  data->modelData->modelFilePrefix = "Reference_1";
  data->modelData->resultFileName = NULL;
  data->modelData->modelDir = "/home/cparrado/.openmodelica/libraries/SolarTherm/Systems";
  data->modelData->modelGUID = "{2ccdd755-b04e-449f-8cc8-b803b87cf65a}";
  #if defined(OPENMODELICA_XML_FROM_FILE_AT_RUNTIME)
  data->modelData->initXMLData = NULL;
  data->modelData->modelDataXml.infoXMLData = NULL;
  #else
  #if defined(_MSC_VER) /* handle joke compilers */
  {
  /* for MSVC we encode a string like char x[] = {'a', 'b', 'c', '\0'} */
  /* because the string constant limit is 65535 bytes */
  static const char contents_init[] =
    #include "Reference_1_init.c"
    ;
  static const char contents_info[] =
    #include "Reference_1_info.c"
    ;
    data->modelData->initXMLData = contents_init;
    data->modelData->modelDataXml.infoXMLData = contents_info;
  }
  #else /* handle real compilers */
  data->modelData->initXMLData =
  #include "Reference_1_init.c"
    ;
  data->modelData->modelDataXml.infoXMLData =
  #include "Reference_1_info.c"
    ;
  #endif /* defined(_MSC_VER) */
  #endif /* defined(OPENMODELICA_XML_FROM_FILE_AT_RUNTIME) */
  data->modelData->runTestsuite = 0;
  
  data->modelData->nStates = 11;
  data->modelData->nVariablesReal = 223;
  data->modelData->nDiscreteReal = 9;
  data->modelData->nVariablesInteger = 4;
  data->modelData->nVariablesBoolean = 35;
  data->modelData->nVariablesString = 0;
  data->modelData->nParametersReal = 313;
  data->modelData->nParametersInteger = 92;
  data->modelData->nParametersBoolean = 45;
  data->modelData->nParametersString = 23;
  data->modelData->nInputVars = 0;
  data->modelData->nOutputVars = 0;
  
  data->modelData->nAliasReal = 173;
  data->modelData->nAliasInteger = 6;
  data->modelData->nAliasBoolean = 14;
  data->modelData->nAliasString = 0;
  
  data->modelData->nZeroCrossings = 29;
  data->modelData->nSamples = 0;
  data->modelData->nRelations = 24;
  data->modelData->nMathEvents = 10;
  data->modelData->nExtObjs = 5;
  
  data->modelData->modelDataXml.fileName = "Reference_1_info.json";
  data->modelData->modelDataXml.modelInfoXmlLength = 0;
  data->modelData->modelDataXml.nFunctions = 59;
  data->modelData->modelDataXml.nProfileBlocks = 0;
  data->modelData->modelDataXml.nEquations = 1209;
  data->modelData->nMixedSystems = 0;
  data->modelData->nLinearSystems = 0;
  data->modelData->nNonLinearSystems = 3;
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
  
    Reference_1_setupDataStruc(&data, threadData);
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


