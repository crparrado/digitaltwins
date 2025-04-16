/* Events: Sample, Zero Crossings, Relations, Discrete Changes */
#include "Reference_1_model.h"
#if defined(__cplusplus)
extern "C" {
#endif

/* Initializes the raw time events of the simulation using the now
   calcualted parameters. */
void Reference_1_function_initSample(DATA *data, threadData_t *threadData)
{
  long i=0;
}

const char *Reference_1_zeroCrossingDescription(int i, int **out_EquationIndexes)
{
  static const char *res[] = {"time >= pre(prices.nextTimeEvent)",
  "heliostatField.ele > 0.01",
  "time >= pre(data.table.nextTimeEvent)",
  "mod(sch_fixed.wbus.t, 86400.0, 0)",
  "integer(mod(1.157407407407407e-05 * sch_fixed.wbus.t, 7.0), 2)",
  "mod(1.157407407407407e-05 * sch_fixed.wbus.t, 7.0, 3)",
  "integer(mod(3.80517503805175e-07 * sch_fixed.wbus.t, 12.0), 5)",
  "mod(3.80517503805175e-07 * sch_fixed.wbus.t, 12.0, 6)",
  "mod(wea.spos.t_solar, 24.0, 8)",
  "controlHot.logic.level > controlHot.defocus_logic.level_max",
  "controlHot.logic.level < controlHot.defocus_logic.level_min",
  "controlHot.logic.level > controlHot.logic.level_on",
  "controlHot.logic.level < controlHot.logic.level_off",
  "controlCold.hotTankLogic.level_ref > controlCold.defocus_logic.level_max",
  "controlCold.hotTankLogic.level_ref < controlCold.defocus_logic.level_min",
  "controlCold.hotTankLogic.level_ref > controlCold.hotTankLogic.level_max",
  "controlCold.hotTankLogic.level_ref < controlCold.hotTankLogic.level_min",
  "tankCold.T < tankCold.T_set",
  "tankCold.T > 1.0 + tankCold.T_set",
  "powerBlock.T_in < tankHot.T_set",
  "powerBlock.T_in > 1.0 + tankHot.T_set",
  "heliostatField.ele > heliostatField.ele_min and Wspd_input.y < heliostatField.Wspd_max",
  "heliostatField.Q_raw > heliostatField.Q_start",
  "heliostatField.Q_raw < heliostatField.Q_start",
  "time < heliostatField.t_on + heliostatField.t_start",
  "controlCold.m_flow > 0.0",
  "time - controlHot.logic.t_on > controlHot.logic.t_start",
  "time - controlHot.logic.t_off < controlHot.logic.t_standby",
  "powerBlock.load > powerBlock.nu_min"};
  static const int occurEqs0[] = {1,567};
  static const int occurEqs1[] = {1,594};
  static const int occurEqs2[] = {1,534};
  static const int occurEqs3[] = {1,508};
  static const int occurEqs4[] = {1,510};
  static const int occurEqs5[] = {1,510};
  static const int occurEqs6[] = {1,512};
  static const int occurEqs7[] = {1,512};
  static const int occurEqs8[] = {1,531};
  static const int occurEqs9[] = {1,632};
  static const int occurEqs10[] = {1,633};
  static const int occurEqs11[] = {1,669};
  static const int occurEqs12[] = {1,670};
  static const int occurEqs13[] = {1,610};
  static const int occurEqs14[] = {1,611};
  static const int occurEqs15[] = {1,614};
  static const int occurEqs16[] = {1,615};
  static const int occurEqs17[] = {1,624};
  static const int occurEqs18[] = {1,624};
  static const int occurEqs19[] = {1,706};
  static const int occurEqs20[] = {1,706};
  static const int occurEqs21[] = {1,597};
  static const int occurEqs22[] = {1,599};
  static const int occurEqs23[] = {1,600};
  static const int occurEqs24[] = {1,639};
  static const int occurEqs25[] = {1,656};
  static const int occurEqs26[] = {1,675};
  static const int occurEqs27[] = {1,678};
  static const int occurEqs28[] = {1,685};
  static const int *occurEqs[] = {occurEqs0,occurEqs1,occurEqs2,occurEqs3,occurEqs4,occurEqs5,occurEqs6,occurEqs7,occurEqs8,occurEqs9,occurEqs10,occurEqs11,occurEqs12,occurEqs13,occurEqs14,occurEqs15,occurEqs16,occurEqs17,occurEqs18,occurEqs19,occurEqs20,occurEqs21,occurEqs22,occurEqs23,occurEqs24,occurEqs25,occurEqs26,occurEqs27,occurEqs28};
  *out_EquationIndexes = (int*) occurEqs[i];
  return res[i];
}

/* forwarded equations */
extern void Reference_1_eqFunction_506(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_507(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_508(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_509(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_514(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_517(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_518(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_519(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_520(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_521(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_530(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_534(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_538(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_539(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_540(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_544(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_545(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_546(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_559(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_560(DATA* data, threadData_t *threadData);
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
extern void Reference_1_eqFunction_628(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_629(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_630(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_631(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_632(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_633(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_636(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_637(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_643(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_655(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_656(DATA* data, threadData_t *threadData);
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
extern void Reference_1_eqFunction_705(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_706(DATA* data, threadData_t *threadData);
extern void Reference_1_eqFunction_714(DATA* data, threadData_t *threadData);

int Reference_1_function_ZeroCrossingsEquations(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->callStatistics.functionZeroCrossingsEquations++;

  Reference_1_eqFunction_506(data, threadData);

  Reference_1_eqFunction_507(data, threadData);

  Reference_1_eqFunction_508(data, threadData);

  Reference_1_eqFunction_509(data, threadData);

  Reference_1_eqFunction_514(data, threadData);

  Reference_1_eqFunction_517(data, threadData);

  Reference_1_eqFunction_518(data, threadData);

  Reference_1_eqFunction_519(data, threadData);

  Reference_1_eqFunction_520(data, threadData);

  Reference_1_eqFunction_521(data, threadData);

  Reference_1_eqFunction_530(data, threadData);

  Reference_1_eqFunction_534(data, threadData);

  Reference_1_eqFunction_538(data, threadData);

  Reference_1_eqFunction_539(data, threadData);

  Reference_1_eqFunction_540(data, threadData);

  Reference_1_eqFunction_544(data, threadData);

  Reference_1_eqFunction_545(data, threadData);

  Reference_1_eqFunction_546(data, threadData);

  Reference_1_eqFunction_559(data, threadData);

  Reference_1_eqFunction_560(data, threadData);

  Reference_1_eqFunction_585(data, threadData);

  Reference_1_eqFunction_587(data, threadData);

  Reference_1_eqFunction_588(data, threadData);

  Reference_1_eqFunction_589(data, threadData);

  Reference_1_eqFunction_590(data, threadData);

  Reference_1_eqFunction_591(data, threadData);

  Reference_1_eqFunction_592(data, threadData);

  Reference_1_eqFunction_593(data, threadData);

  Reference_1_eqFunction_594(data, threadData);

  Reference_1_eqFunction_597(data, threadData);

  Reference_1_eqFunction_598(data, threadData);

  Reference_1_eqFunction_599(data, threadData);

  Reference_1_eqFunction_600(data, threadData);

  Reference_1_eqFunction_605(data, threadData);

  Reference_1_eqFunction_607(data, threadData);

  Reference_1_eqFunction_608(data, threadData);

  Reference_1_eqFunction_609(data, threadData);

  Reference_1_eqFunction_610(data, threadData);

  Reference_1_eqFunction_611(data, threadData);

  Reference_1_eqFunction_614(data, threadData);

  Reference_1_eqFunction_615(data, threadData);

  Reference_1_eqFunction_618(data, threadData);

  Reference_1_eqFunction_620(data, threadData);

  Reference_1_eqFunction_623(data, threadData);

  Reference_1_eqFunction_624(data, threadData);

  Reference_1_eqFunction_628(data, threadData);

  Reference_1_eqFunction_629(data, threadData);

  Reference_1_eqFunction_630(data, threadData);

  Reference_1_eqFunction_631(data, threadData);

  Reference_1_eqFunction_632(data, threadData);

  Reference_1_eqFunction_633(data, threadData);

  Reference_1_eqFunction_636(data, threadData);

  Reference_1_eqFunction_637(data, threadData);

  Reference_1_eqFunction_643(data, threadData);

  Reference_1_eqFunction_655(data, threadData);

  Reference_1_eqFunction_656(data, threadData);

  Reference_1_eqFunction_658(data, threadData);

  Reference_1_eqFunction_659(data, threadData);

  Reference_1_eqFunction_660(data, threadData);

  Reference_1_eqFunction_661(data, threadData);

  Reference_1_eqFunction_662(data, threadData);

  Reference_1_eqFunction_669(data, threadData);

  Reference_1_eqFunction_670(data, threadData);

  Reference_1_eqFunction_673(data, threadData);

  Reference_1_eqFunction_675(data, threadData);

  Reference_1_eqFunction_676(data, threadData);

  Reference_1_eqFunction_678(data, threadData);

  Reference_1_eqFunction_679(data, threadData);

  Reference_1_eqFunction_682(data, threadData);

  Reference_1_eqFunction_684(data, threadData);

  Reference_1_eqFunction_685(data, threadData);

  Reference_1_eqFunction_686(data, threadData);

  Reference_1_eqFunction_687(data, threadData);

  Reference_1_eqFunction_688(data, threadData);

  Reference_1_eqFunction_692(data, threadData);

  Reference_1_eqFunction_693(data, threadData);

  Reference_1_eqFunction_694(data, threadData);

  Reference_1_eqFunction_695(data, threadData);

  Reference_1_eqFunction_697(data, threadData);

  Reference_1_eqFunction_699(data, threadData);

  Reference_1_eqFunction_705(data, threadData);

  Reference_1_eqFunction_706(data, threadData);

  Reference_1_eqFunction_714(data, threadData);
  
  TRACE_POP
  return 0;
}

int Reference_1_function_ZeroCrossings(DATA *data, threadData_t *threadData, double *gout)
{
  TRACE_PUSH
  modelica_boolean tmp0;
  modelica_boolean tmp1;
  modelica_boolean tmp2;
  modelica_real tmp3;
  modelica_real tmp4;
  modelica_real tmp5;
  modelica_real tmp6;
  modelica_real tmp7;
  modelica_real tmp8;
  modelica_real tmp9;
  modelica_real tmp10;
  modelica_real tmp11;
  modelica_real tmp12;
  modelica_boolean tmp13;
  modelica_boolean tmp14;
  modelica_boolean tmp15;
  modelica_boolean tmp16;
  modelica_boolean tmp17;
  modelica_boolean tmp18;
  modelica_boolean tmp19;
  modelica_boolean tmp20;
  modelica_boolean tmp21;
  modelica_boolean tmp22;
  modelica_boolean tmp23;
  modelica_boolean tmp24;
  modelica_boolean tmp25;
  modelica_boolean tmp26;
  modelica_boolean tmp27;
  modelica_boolean tmp28;
  modelica_boolean tmp29;
  modelica_boolean tmp30;
  modelica_boolean tmp31;
  modelica_boolean tmp32;
  modelica_boolean tmp33;

#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_ZC);
#endif
  data->simulationInfo->callStatistics.functionZeroCrossings++;

  tmp0 = GreaterEqZC(data->localData[0]->timeValue, data->simulationInfo->realVarsPre[219] /* prices.nextTimeEvent DISCRETE */, data->simulationInfo->storedRelations[0]);
  gout[0] = (tmp0) ? 1 : -1;
  tmp1 = GreaterZC(data->localData[0]->realVars[96] /* heliostatField.ele variable */, 0.01, data->simulationInfo->storedRelations[1]);
  gout[1] = (tmp1) ? 1 : -1;
  tmp2 = GreaterEqZC(data->localData[0]->timeValue, data->simulationInfo->realVarsPre[216] /* data.table.nextTimeEvent DISCRETE */, data->simulationInfo->storedRelations[2]);
  gout[2] = (tmp2) ? 1 : -1;
  tmp3 = floor((data->localData[0]->realVars[153] /* sch_fixed.wbus.t variable */) / (86400.0));
  tmp4 = floor((data->simulationInfo->mathEventsValuePre[((modelica_integer) 0)]) / (data->simulationInfo->mathEventsValuePre[((modelica_integer) 0)+1]));
  gout[3] = tmp3 != tmp4 ? 1 : -1;
  tmp5 = 7.0;
  if (tmp5 == 0) {throwStreamPrint(threadData, "Division by zero %s", "mod(1.157407407407407e-05 * sch_fixed.wbus.t, 7.0)");}
  gout[4] = (floor(modelica_real_mod((1.157407407407407e-05) * (data->localData[0]->realVars[153] /* sch_fixed.wbus.t variable */), tmp5)) != floor(data->simulationInfo->mathEventsValuePre[((modelica_integer) 2)])) ? 1 : -1;
  tmp6 = floor(((1.157407407407407e-05) * (data->localData[0]->realVars[153] /* sch_fixed.wbus.t variable */)) / (7.0));
  tmp7 = floor((data->simulationInfo->mathEventsValuePre[((modelica_integer) 3)]) / (data->simulationInfo->mathEventsValuePre[((modelica_integer) 3)+1]));
  gout[5] = tmp6 != tmp7 ? 1 : -1;
  tmp8 = 12.0;
  if (tmp8 == 0) {throwStreamPrint(threadData, "Division by zero %s", "mod(3.80517503805175e-07 * sch_fixed.wbus.t, 12.0)");}
  gout[6] = (floor(modelica_real_mod((3.80517503805175e-07) * (data->localData[0]->realVars[153] /* sch_fixed.wbus.t variable */), tmp8)) != floor(data->simulationInfo->mathEventsValuePre[((modelica_integer) 5)])) ? 1 : -1;
  tmp9 = floor(((3.80517503805175e-07) * (data->localData[0]->realVars[153] /* sch_fixed.wbus.t variable */)) / (12.0));
  tmp10 = floor((data->simulationInfo->mathEventsValuePre[((modelica_integer) 6)]) / (data->simulationInfo->mathEventsValuePre[((modelica_integer) 6)+1]));
  gout[7] = tmp9 != tmp10 ? 1 : -1;
  tmp11 = floor((data->localData[0]->realVars[197] /* wea.spos.t_solar variable */) / (24.0));
  tmp12 = floor((data->simulationInfo->mathEventsValuePre[((modelica_integer) 8)]) / (data->simulationInfo->mathEventsValuePre[((modelica_integer) 8)+1]));
  gout[8] = tmp11 != tmp12 ? 1 : -1;
  tmp13 = GreaterZC(data->localData[0]->realVars[74] /* controlHot.logic.level variable */, data->simulationInfo->realParameter[94] /* controlHot.defocus_logic.level_max PARAM */, data->simulationInfo->storedRelations[3]);
  gout[9] = (tmp13) ? 1 : -1;
  tmp14 = LessZC(data->localData[0]->realVars[74] /* controlHot.logic.level variable */, data->simulationInfo->realParameter[95] /* controlHot.defocus_logic.level_min PARAM */, data->simulationInfo->storedRelations[4]);
  gout[10] = (tmp14) ? 1 : -1;
  tmp15 = GreaterZC(data->localData[0]->realVars[74] /* controlHot.logic.level variable */, data->simulationInfo->realParameter[97] /* controlHot.logic.level_on PARAM */, data->simulationInfo->storedRelations[5]);
  gout[11] = (tmp15) ? 1 : -1;
  tmp16 = LessZC(data->localData[0]->realVars[74] /* controlHot.logic.level variable */, data->simulationInfo->realParameter[96] /* controlHot.logic.level_off PARAM */, data->simulationInfo->storedRelations[6]);
  gout[12] = (tmp16) ? 1 : -1;
  tmp17 = GreaterZC(data->localData[0]->realVars[70] /* controlCold.hotTankLogic.level_ref variable */, data->simulationInfo->realParameter[82] /* controlCold.defocus_logic.level_max PARAM */, data->simulationInfo->storedRelations[7]);
  gout[13] = (tmp17) ? 1 : -1;
  tmp18 = LessZC(data->localData[0]->realVars[70] /* controlCold.hotTankLogic.level_ref variable */, data->simulationInfo->realParameter[83] /* controlCold.defocus_logic.level_min PARAM */, data->simulationInfo->storedRelations[8]);
  gout[14] = (tmp18) ? 1 : -1;
  tmp19 = GreaterZC(data->localData[0]->realVars[70] /* controlCold.hotTankLogic.level_ref variable */, data->simulationInfo->realParameter[85] /* controlCold.hotTankLogic.level_max PARAM */, data->simulationInfo->storedRelations[9]);
  gout[15] = (tmp19) ? 1 : -1;
  tmp20 = LessZC(data->localData[0]->realVars[70] /* controlCold.hotTankLogic.level_ref variable */, data->simulationInfo->realParameter[86] /* controlCold.hotTankLogic.level_min PARAM */, data->simulationInfo->storedRelations[10]);
  gout[16] = (tmp20) ? 1 : -1;
  tmp21 = LessZC(data->localData[0]->realVars[163] /* tankCold.T variable */, data->simulationInfo->realParameter[256] /* tankCold.T_set PARAM */, data->simulationInfo->storedRelations[11]);
  gout[17] = (tmp21) ? 1 : -1;
  tmp22 = GreaterZC(data->localData[0]->realVars[163] /* tankCold.T variable */, 1.0 + data->simulationInfo->realParameter[256] /* tankCold.T_set PARAM */, data->simulationInfo->storedRelations[12]);
  gout[18] = (tmp22) ? 1 : -1;
  tmp23 = LessZC(data->localData[0]->realVars[108] /* powerBlock.T_in variable */, data->simulationInfo->realParameter[266] /* tankHot.T_set PARAM */, data->simulationInfo->storedRelations[13]);
  gout[19] = (tmp23) ? 1 : -1;
  tmp24 = GreaterZC(data->localData[0]->realVars[108] /* powerBlock.T_in variable */, 1.0 + data->simulationInfo->realParameter[266] /* tankHot.T_set PARAM */, data->simulationInfo->storedRelations[14]);
  gout[20] = (tmp24) ? 1 : -1;
  tmp25 = GreaterZC(data->localData[0]->realVars[96] /* heliostatField.ele variable */, data->simulationInfo->realParameter[142] /* heliostatField.ele_min PARAM */, data->simulationInfo->storedRelations[15]);
  tmp26 = LessZC(data->localData[0]->realVars[58] /* Wspd_input.y variable */, data->simulationInfo->realParameter[141] /* heliostatField.Wspd_max PARAM */, data->simulationInfo->storedRelations[16]);
  gout[21] = ((tmp25 && tmp26)) ? 1 : -1;
  tmp27 = GreaterZC(data->localData[0]->realVars[90] /* heliostatField.Q_raw variable */, data->simulationInfo->realParameter[139] /* heliostatField.Q_start PARAM */, data->simulationInfo->storedRelations[17]);
  gout[22] = (tmp27) ? 1 : -1;
  tmp28 = LessZC(data->localData[0]->realVars[90] /* heliostatField.Q_raw variable */, data->simulationInfo->realParameter[139] /* heliostatField.Q_start PARAM */, data->simulationInfo->storedRelations[18]);
  gout[23] = (tmp28) ? 1 : -1;
  tmp29 = LessZC(data->localData[0]->timeValue, data->localData[0]->realVars[218] /* heliostatField.t_on DISCRETE */ + data->simulationInfo->realParameter[154] /* heliostatField.t_start PARAM */, data->simulationInfo->storedRelations[19]);
  gout[24] = (tmp29) ? 1 : -1;
  tmp30 = GreaterZC(data->localData[0]->realVars[71] /* controlCold.m_flow variable */, 0.0, data->simulationInfo->storedRelations[20]);
  gout[25] = (tmp30) ? 1 : -1;
  tmp31 = GreaterZC(data->localData[0]->timeValue - data->localData[0]->realVars[215] /* controlHot.logic.t_on DISCRETE */, data->simulationInfo->realParameter[102] /* controlHot.logic.t_start PARAM */, data->simulationInfo->storedRelations[21]);
  gout[26] = (tmp31) ? 1 : -1;
  tmp32 = LessZC(data->localData[0]->timeValue - data->localData[0]->realVars[214] /* controlHot.logic.t_off DISCRETE */, data->simulationInfo->realParameter[101] /* controlHot.logic.t_standby PARAM */, data->simulationInfo->storedRelations[22]);
  gout[27] = (tmp32) ? 1 : -1;
  tmp33 = GreaterZC(data->localData[0]->realVars[121] /* powerBlock.load variable */, data->simulationInfo->realParameter[194] /* powerBlock.nu_min PARAM */, data->simulationInfo->storedRelations[23]);
  gout[28] = (tmp33) ? 1 : -1;

#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_ZC);
#endif

  TRACE_POP
  return 0;
}

const char *Reference_1_relationDescription(int i)
{
  const char *res[] = {"time >= pre(prices.nextTimeEvent)",
  "heliostatField.ele > 0.01",
  "time >= pre(data.table.nextTimeEvent)",
  "controlHot.logic.level > controlHot.defocus_logic.level_max",
  "controlHot.logic.level < controlHot.defocus_logic.level_min",
  "controlHot.logic.level > controlHot.logic.level_on",
  "controlHot.logic.level < controlHot.logic.level_off",
  "controlCold.hotTankLogic.level_ref > controlCold.defocus_logic.level_max",
  "controlCold.hotTankLogic.level_ref < controlCold.defocus_logic.level_min",
  "controlCold.hotTankLogic.level_ref > controlCold.hotTankLogic.level_max",
  "controlCold.hotTankLogic.level_ref < controlCold.hotTankLogic.level_min",
  "tankCold.T < tankCold.T_set",
  "tankCold.T > 1.0 + tankCold.T_set",
  "powerBlock.T_in < tankHot.T_set",
  "powerBlock.T_in > 1.0 + tankHot.T_set",
  "heliostatField.ele > heliostatField.ele_min",
  "Wspd_input.y < heliostatField.Wspd_max",
  "heliostatField.Q_raw > heliostatField.Q_start",
  "heliostatField.Q_raw < heliostatField.Q_start",
  "time < heliostatField.t_on + heliostatField.t_start",
  "controlCold.m_flow > 0.0",
  "time - controlHot.logic.t_on > controlHot.logic.t_start",
  "time - controlHot.logic.t_off < controlHot.logic.t_standby",
  "powerBlock.load > powerBlock.nu_min"};
  return res[i];
}

int Reference_1_function_updateRelations(DATA *data, threadData_t *threadData, int evalforZeroCross)
{
  TRACE_PUSH
  modelica_boolean tmp34;
  modelica_boolean tmp35;
  modelica_boolean tmp36;
  modelica_boolean tmp37;
  modelica_boolean tmp38;
  modelica_boolean tmp39;
  modelica_boolean tmp40;
  modelica_boolean tmp41;
  modelica_boolean tmp42;
  modelica_boolean tmp43;
  modelica_boolean tmp44;
  modelica_boolean tmp45;
  modelica_boolean tmp46;
  modelica_boolean tmp47;
  modelica_boolean tmp48;
  modelica_boolean tmp49;
  modelica_boolean tmp50;
  modelica_boolean tmp51;
  modelica_boolean tmp52;
  modelica_boolean tmp53;
  modelica_boolean tmp54;
  modelica_boolean tmp55;
  modelica_boolean tmp56;
  modelica_boolean tmp57;
  
  if(evalforZeroCross) {
    tmp34 = GreaterEqZC(data->localData[0]->timeValue, data->simulationInfo->realVarsPre[219] /* prices.nextTimeEvent DISCRETE */, data->simulationInfo->storedRelations[0]);
    data->simulationInfo->relations[0] = tmp34;
    tmp35 = GreaterZC(data->localData[0]->realVars[96] /* heliostatField.ele variable */, 0.01, data->simulationInfo->storedRelations[1]);
    data->simulationInfo->relations[1] = tmp35;
    tmp36 = GreaterEqZC(data->localData[0]->timeValue, data->simulationInfo->realVarsPre[216] /* data.table.nextTimeEvent DISCRETE */, data->simulationInfo->storedRelations[2]);
    data->simulationInfo->relations[2] = tmp36;
    tmp37 = GreaterZC(data->localData[0]->realVars[74] /* controlHot.logic.level variable */, data->simulationInfo->realParameter[94] /* controlHot.defocus_logic.level_max PARAM */, data->simulationInfo->storedRelations[3]);
    data->simulationInfo->relations[3] = tmp37;
    tmp38 = LessZC(data->localData[0]->realVars[74] /* controlHot.logic.level variable */, data->simulationInfo->realParameter[95] /* controlHot.defocus_logic.level_min PARAM */, data->simulationInfo->storedRelations[4]);
    data->simulationInfo->relations[4] = tmp38;
    tmp39 = GreaterZC(data->localData[0]->realVars[74] /* controlHot.logic.level variable */, data->simulationInfo->realParameter[97] /* controlHot.logic.level_on PARAM */, data->simulationInfo->storedRelations[5]);
    data->simulationInfo->relations[5] = tmp39;
    tmp40 = LessZC(data->localData[0]->realVars[74] /* controlHot.logic.level variable */, data->simulationInfo->realParameter[96] /* controlHot.logic.level_off PARAM */, data->simulationInfo->storedRelations[6]);
    data->simulationInfo->relations[6] = tmp40;
    tmp41 = GreaterZC(data->localData[0]->realVars[70] /* controlCold.hotTankLogic.level_ref variable */, data->simulationInfo->realParameter[82] /* controlCold.defocus_logic.level_max PARAM */, data->simulationInfo->storedRelations[7]);
    data->simulationInfo->relations[7] = tmp41;
    tmp42 = LessZC(data->localData[0]->realVars[70] /* controlCold.hotTankLogic.level_ref variable */, data->simulationInfo->realParameter[83] /* controlCold.defocus_logic.level_min PARAM */, data->simulationInfo->storedRelations[8]);
    data->simulationInfo->relations[8] = tmp42;
    tmp43 = GreaterZC(data->localData[0]->realVars[70] /* controlCold.hotTankLogic.level_ref variable */, data->simulationInfo->realParameter[85] /* controlCold.hotTankLogic.level_max PARAM */, data->simulationInfo->storedRelations[9]);
    data->simulationInfo->relations[9] = tmp43;
    tmp44 = LessZC(data->localData[0]->realVars[70] /* controlCold.hotTankLogic.level_ref variable */, data->simulationInfo->realParameter[86] /* controlCold.hotTankLogic.level_min PARAM */, data->simulationInfo->storedRelations[10]);
    data->simulationInfo->relations[10] = tmp44;
    tmp45 = LessZC(data->localData[0]->realVars[163] /* tankCold.T variable */, data->simulationInfo->realParameter[256] /* tankCold.T_set PARAM */, data->simulationInfo->storedRelations[11]);
    data->simulationInfo->relations[11] = tmp45;
    tmp46 = GreaterZC(data->localData[0]->realVars[163] /* tankCold.T variable */, 1.0 + data->simulationInfo->realParameter[256] /* tankCold.T_set PARAM */, data->simulationInfo->storedRelations[12]);
    data->simulationInfo->relations[12] = tmp46;
    tmp47 = LessZC(data->localData[0]->realVars[108] /* powerBlock.T_in variable */, data->simulationInfo->realParameter[266] /* tankHot.T_set PARAM */, data->simulationInfo->storedRelations[13]);
    data->simulationInfo->relations[13] = tmp47;
    tmp48 = GreaterZC(data->localData[0]->realVars[108] /* powerBlock.T_in variable */, 1.0 + data->simulationInfo->realParameter[266] /* tankHot.T_set PARAM */, data->simulationInfo->storedRelations[14]);
    data->simulationInfo->relations[14] = tmp48;
    tmp49 = GreaterZC(data->localData[0]->realVars[96] /* heliostatField.ele variable */, data->simulationInfo->realParameter[142] /* heliostatField.ele_min PARAM */, data->simulationInfo->storedRelations[15]);
    data->simulationInfo->relations[15] = tmp49;
    tmp50 = LessZC(data->localData[0]->realVars[58] /* Wspd_input.y variable */, data->simulationInfo->realParameter[141] /* heliostatField.Wspd_max PARAM */, data->simulationInfo->storedRelations[16]);
    data->simulationInfo->relations[16] = tmp50;
    tmp51 = GreaterZC(data->localData[0]->realVars[90] /* heliostatField.Q_raw variable */, data->simulationInfo->realParameter[139] /* heliostatField.Q_start PARAM */, data->simulationInfo->storedRelations[17]);
    data->simulationInfo->relations[17] = tmp51;
    tmp52 = LessZC(data->localData[0]->realVars[90] /* heliostatField.Q_raw variable */, data->simulationInfo->realParameter[139] /* heliostatField.Q_start PARAM */, data->simulationInfo->storedRelations[18]);
    data->simulationInfo->relations[18] = tmp52;
    tmp53 = LessZC(data->localData[0]->timeValue, data->localData[0]->realVars[218] /* heliostatField.t_on DISCRETE */ + data->simulationInfo->realParameter[154] /* heliostatField.t_start PARAM */, data->simulationInfo->storedRelations[19]);
    data->simulationInfo->relations[19] = tmp53;
    tmp54 = GreaterZC(data->localData[0]->realVars[71] /* controlCold.m_flow variable */, 0.0, data->simulationInfo->storedRelations[20]);
    data->simulationInfo->relations[20] = tmp54;
    tmp55 = GreaterZC(data->localData[0]->timeValue - data->localData[0]->realVars[215] /* controlHot.logic.t_on DISCRETE */, data->simulationInfo->realParameter[102] /* controlHot.logic.t_start PARAM */, data->simulationInfo->storedRelations[21]);
    data->simulationInfo->relations[21] = tmp55;
    tmp56 = LessZC(data->localData[0]->timeValue - data->localData[0]->realVars[214] /* controlHot.logic.t_off DISCRETE */, data->simulationInfo->realParameter[101] /* controlHot.logic.t_standby PARAM */, data->simulationInfo->storedRelations[22]);
    data->simulationInfo->relations[22] = tmp56;
    tmp57 = GreaterZC(data->localData[0]->realVars[121] /* powerBlock.load variable */, data->simulationInfo->realParameter[194] /* powerBlock.nu_min PARAM */, data->simulationInfo->storedRelations[23]);
    data->simulationInfo->relations[23] = tmp57;
  } else {
    data->simulationInfo->relations[0] = (data->localData[0]->timeValue >= data->simulationInfo->realVarsPre[219] /* prices.nextTimeEvent DISCRETE */);
    data->simulationInfo->relations[1] = (data->localData[0]->realVars[96] /* heliostatField.ele variable */ > 0.01);
    data->simulationInfo->relations[2] = (data->localData[0]->timeValue >= data->simulationInfo->realVarsPre[216] /* data.table.nextTimeEvent DISCRETE */);
    data->simulationInfo->relations[3] = (data->localData[0]->realVars[74] /* controlHot.logic.level variable */ > data->simulationInfo->realParameter[94] /* controlHot.defocus_logic.level_max PARAM */);
    data->simulationInfo->relations[4] = (data->localData[0]->realVars[74] /* controlHot.logic.level variable */ < data->simulationInfo->realParameter[95] /* controlHot.defocus_logic.level_min PARAM */);
    data->simulationInfo->relations[5] = (data->localData[0]->realVars[74] /* controlHot.logic.level variable */ > data->simulationInfo->realParameter[97] /* controlHot.logic.level_on PARAM */);
    data->simulationInfo->relations[6] = (data->localData[0]->realVars[74] /* controlHot.logic.level variable */ < data->simulationInfo->realParameter[96] /* controlHot.logic.level_off PARAM */);
    data->simulationInfo->relations[7] = (data->localData[0]->realVars[70] /* controlCold.hotTankLogic.level_ref variable */ > data->simulationInfo->realParameter[82] /* controlCold.defocus_logic.level_max PARAM */);
    data->simulationInfo->relations[8] = (data->localData[0]->realVars[70] /* controlCold.hotTankLogic.level_ref variable */ < data->simulationInfo->realParameter[83] /* controlCold.defocus_logic.level_min PARAM */);
    data->simulationInfo->relations[9] = (data->localData[0]->realVars[70] /* controlCold.hotTankLogic.level_ref variable */ > data->simulationInfo->realParameter[85] /* controlCold.hotTankLogic.level_max PARAM */);
    data->simulationInfo->relations[10] = (data->localData[0]->realVars[70] /* controlCold.hotTankLogic.level_ref variable */ < data->simulationInfo->realParameter[86] /* controlCold.hotTankLogic.level_min PARAM */);
    data->simulationInfo->relations[11] = (data->localData[0]->realVars[163] /* tankCold.T variable */ < data->simulationInfo->realParameter[256] /* tankCold.T_set PARAM */);
    data->simulationInfo->relations[12] = (data->localData[0]->realVars[163] /* tankCold.T variable */ > 1.0 + data->simulationInfo->realParameter[256] /* tankCold.T_set PARAM */);
    data->simulationInfo->relations[13] = (data->localData[0]->realVars[108] /* powerBlock.T_in variable */ < data->simulationInfo->realParameter[266] /* tankHot.T_set PARAM */);
    data->simulationInfo->relations[14] = (data->localData[0]->realVars[108] /* powerBlock.T_in variable */ > 1.0 + data->simulationInfo->realParameter[266] /* tankHot.T_set PARAM */);
    data->simulationInfo->relations[15] = (data->localData[0]->realVars[96] /* heliostatField.ele variable */ > data->simulationInfo->realParameter[142] /* heliostatField.ele_min PARAM */);
    data->simulationInfo->relations[16] = (data->localData[0]->realVars[58] /* Wspd_input.y variable */ < data->simulationInfo->realParameter[141] /* heliostatField.Wspd_max PARAM */);
    data->simulationInfo->relations[17] = (data->localData[0]->realVars[90] /* heliostatField.Q_raw variable */ > data->simulationInfo->realParameter[139] /* heliostatField.Q_start PARAM */);
    data->simulationInfo->relations[18] = (data->localData[0]->realVars[90] /* heliostatField.Q_raw variable */ < data->simulationInfo->realParameter[139] /* heliostatField.Q_start PARAM */);
    data->simulationInfo->relations[19] = (data->localData[0]->timeValue < data->localData[0]->realVars[218] /* heliostatField.t_on DISCRETE */ + data->simulationInfo->realParameter[154] /* heliostatField.t_start PARAM */);
    data->simulationInfo->relations[20] = (data->localData[0]->realVars[71] /* controlCold.m_flow variable */ > 0.0);
    data->simulationInfo->relations[21] = (data->localData[0]->timeValue - data->localData[0]->realVars[215] /* controlHot.logic.t_on DISCRETE */ > data->simulationInfo->realParameter[102] /* controlHot.logic.t_start PARAM */);
    data->simulationInfo->relations[22] = (data->localData[0]->timeValue - data->localData[0]->realVars[214] /* controlHot.logic.t_off DISCRETE */ < data->simulationInfo->realParameter[101] /* controlHot.logic.t_standby PARAM */);
    data->simulationInfo->relations[23] = (data->localData[0]->realVars[121] /* powerBlock.load variable */ > data->simulationInfo->realParameter[194] /* powerBlock.nu_min PARAM */);
  }
  
  TRACE_POP
  return 0;
}

#if defined(__cplusplus)
}
#endif

