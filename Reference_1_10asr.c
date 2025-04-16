/* Asserts */
#include "Reference_1_model.h"
#if defined(__cplusplus)
extern "C" {
#endif


/*
equation index: 1208
type: ALGORITHM

  assert(sch_fixed.wbus.Tdew >= 0.0, "Variable violating min constraint: 0.0 <= sch_fixed.wbus.Tdew, has value: " + String(sch_fixed.wbus.Tdew, "g"));
*/
void Reference_1_eqFunction_1208(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1208};
  modelica_boolean tmp0;
  static const MMC_DEFSTRINGLIT(tmp1,74,"Variable violating min constraint: 0.0 <= sch_fixed.wbus.Tdew, has value: ");
  modelica_string tmp2;
  static int tmp3 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp3)
  {
    tmp0 = GreaterEq(data->localData[0]->realVars[144] /* sch_fixed.wbus.Tdew variable */,0.0);
    if(!tmp0)
    {
      tmp2 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[144] /* sch_fixed.wbus.Tdew variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp1),tmp2);
      {
        FILE_INFO info = {"/home/cparrado/.openmodelica/libraries/SolarTherm/Interfaces/Connectors/WeatherBus.mo",14,2,14,45,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nsch_fixed.wbus.Tdew >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp3 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1207
type: ALGORITHM

  assert(sch_fixed.wbus.Tdry >= 0.0, "Variable violating min constraint: 0.0 <= sch_fixed.wbus.Tdry, has value: " + String(sch_fixed.wbus.Tdry, "g"));
*/
void Reference_1_eqFunction_1207(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1207};
  modelica_boolean tmp4;
  static const MMC_DEFSTRINGLIT(tmp5,74,"Variable violating min constraint: 0.0 <= sch_fixed.wbus.Tdry, has value: ");
  modelica_string tmp6;
  static int tmp7 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp7)
  {
    tmp4 = GreaterEq(data->localData[0]->realVars[145] /* sch_fixed.wbus.Tdry variable */,0.0);
    if(!tmp4)
    {
      tmp6 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[145] /* sch_fixed.wbus.Tdry variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp5),tmp6);
      {
        FILE_INFO info = {"/home/cparrado/.openmodelica/libraries/SolarTherm/Interfaces/Connectors/WeatherBus.mo",13,2,13,44,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nsch_fixed.wbus.Tdry >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp7 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1206
type: ALGORITHM

  assert(sch_fixed.wbus.dni >= 0.0, "Variable violating min constraint: 0.0 <= sch_fixed.wbus.dni, has value: " + String(sch_fixed.wbus.dni, "g"));
*/
void Reference_1_eqFunction_1206(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1206};
  modelica_boolean tmp8;
  static const MMC_DEFSTRINGLIT(tmp9,73,"Variable violating min constraint: 0.0 <= sch_fixed.wbus.dni, has value: ");
  modelica_string tmp10;
  static int tmp11 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp11)
  {
    tmp8 = GreaterEq(data->localData[0]->realVars[149] /* sch_fixed.wbus.dni variable */,0.0);
    if(!tmp8)
    {
      tmp10 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[149] /* sch_fixed.wbus.dni variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp9),tmp10);
      {
        FILE_INFO info = {"/home/cparrado/.openmodelica/libraries/SolarTherm/Interfaces/Connectors/WeatherBus.mo",12,2,12,53,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nsch_fixed.wbus.dni >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp11 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1205
type: ALGORITHM

  assert(sch_fixed.wbus.ghi >= 0.0, "Variable violating min constraint: 0.0 <= sch_fixed.wbus.ghi, has value: " + String(sch_fixed.wbus.ghi, "g"));
*/
void Reference_1_eqFunction_1205(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1205};
  modelica_boolean tmp12;
  static const MMC_DEFSTRINGLIT(tmp13,73,"Variable violating min constraint: 0.0 <= sch_fixed.wbus.ghi, has value: ");
  modelica_string tmp14;
  static int tmp15 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp15)
  {
    tmp12 = GreaterEq(data->localData[0]->realVars[151] /* sch_fixed.wbus.ghi variable */,0.0);
    if(!tmp12)
    {
      tmp14 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[151] /* sch_fixed.wbus.ghi variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp13),tmp14);
      {
        FILE_INFO info = {"/home/cparrado/.openmodelica/libraries/SolarTherm/Interfaces/Connectors/WeatherBus.mo",11,2,11,57,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nsch_fixed.wbus.ghi >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp15 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1204
type: ALGORITHM

  assert(sch_fixed.wbus.wspd >= 0.0, "Variable violating min constraint: 0.0 <= sch_fixed.wbus.wspd, has value: " + String(sch_fixed.wbus.wspd, "g"));
*/
void Reference_1_eqFunction_1204(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1204};
  modelica_boolean tmp16;
  static const MMC_DEFSTRINGLIT(tmp17,74,"Variable violating min constraint: 0.0 <= sch_fixed.wbus.wspd, has value: ");
  modelica_string tmp18;
  static int tmp19 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp19)
  {
    tmp16 = GreaterEq(data->localData[0]->realVars[155] /* sch_fixed.wbus.wspd variable */,0.0);
    if(!tmp16)
    {
      tmp18 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[155] /* sch_fixed.wbus.wspd variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp17),tmp18);
      {
        FILE_INFO info = {"/home/cparrado/.openmodelica/libraries/SolarTherm/Interfaces/Connectors/WeatherBus.mo",16,2,16,38,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nsch_fixed.wbus.wspd >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp19 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1172
type: ALGORITHM

  assert(tankHot.T >= 573.15 and tankHot.T <= 873.15, "Variable violating min/max constraint: 573.15 <= tankHot.T <= 873.15, has value: " + String(tankHot.T, "g"));
*/
void Reference_1_eqFunction_1172(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1172};
  modelica_boolean tmp20;
  modelica_boolean tmp21;
  static const MMC_DEFSTRINGLIT(tmp22,81,"Variable violating min/max constraint: 573.15 <= tankHot.T <= 873.15, has value: ");
  modelica_string tmp23;
  static int tmp24 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp24)
  {
    tmp20 = GreaterEq(data->localData[0]->realVars[179] /* tankHot.T variable */,573.15);
    tmp21 = LessEq(data->localData[0]->realVars[179] /* tankHot.T variable */,873.15);
    if(!(tmp20 && tmp21))
    {
      tmp23 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[179] /* tankHot.T variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp22),tmp23);
      {
        FILE_INFO info = {"/home/cparrado/.openmodelica/libraries/SolarTherm/Models/Storage/Tank/Tank.mo",43,3,43,52,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\ntankHot.T >= 573.15 and tankHot.T <= 873.15", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp24 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1173
type: ALGORITHM

  assert(receiver.T_in >= 573.15 and receiver.T_in <= 873.15, "Variable violating min/max constraint: 573.15 <= receiver.T_in <= 873.15, has value: " + String(receiver.T_in, "g"));
*/
void Reference_1_eqFunction_1173(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1173};
  modelica_boolean tmp25;
  modelica_boolean tmp26;
  static const MMC_DEFSTRINGLIT(tmp27,85,"Variable violating min/max constraint: 573.15 <= receiver.T_in <= 873.15, has value: ");
  modelica_string tmp28;
  static int tmp29 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp29)
  {
    tmp25 = GreaterEq(data->localData[0]->realVars[129] /* receiver.T_in variable */,573.15);
    tmp26 = LessEq(data->localData[0]->realVars[129] /* receiver.T_in variable */,873.15);
    if(!(tmp25 && tmp26))
    {
      tmp28 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[129] /* receiver.T_in variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp27),tmp28);
      {
        FILE_INFO info = {"/home/cparrado/.openmodelica/libraries/SolarTherm/Models/CSP/CRS/Receivers/ReceiverSimple.mo",16,3,16,74,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nreceiver.T_in >= 573.15 and receiver.T_in <= 873.15", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp29 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1174
type: ALGORITHM

  assert(tankCold.medium.T >= 573.15 and tankCold.medium.T <= 873.15, "Variable violating min/max constraint: 573.15 <= tankCold.medium.T <= 873.15, has value: " + String(tankCold.medium.T, "g"));
*/
void Reference_1_eqFunction_1174(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1174};
  modelica_boolean tmp30;
  modelica_boolean tmp31;
  static const MMC_DEFSTRINGLIT(tmp32,89,"Variable violating min/max constraint: 573.15 <= tankCold.medium.T <= 873.15, has value: ");
  modelica_string tmp33;
  static int tmp34 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp34)
  {
    tmp30 = GreaterEq(data->localData[0]->realVars[168] /* tankCold.medium.T variable */,573.15);
    tmp31 = LessEq(data->localData[0]->realVars[168] /* tankCold.medium.T variable */,873.15);
    if(!(tmp30 && tmp31))
    {
      tmp33 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[168] /* tankCold.medium.T variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp32),tmp33);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Media/package.mo",5020,7,5020,44,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\ntankCold.medium.T >= 573.15 and tankCold.medium.T <= 873.15", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp34 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1175
type: ALGORITHM

  assert(tankHot.medium.T >= 573.15 and tankHot.medium.T <= 873.15, "Variable violating min/max constraint: 573.15 <= tankHot.medium.T <= 873.15, has value: " + String(tankHot.medium.T, "g"));
*/
void Reference_1_eqFunction_1175(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1175};
  modelica_boolean tmp35;
  modelica_boolean tmp36;
  static const MMC_DEFSTRINGLIT(tmp37,88,"Variable violating min/max constraint: 573.15 <= tankHot.medium.T <= 873.15, has value: ");
  modelica_string tmp38;
  static int tmp39 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp39)
  {
    tmp35 = GreaterEq(data->localData[0]->realVars[184] /* tankHot.medium.T variable */,573.15);
    tmp36 = LessEq(data->localData[0]->realVars[184] /* tankHot.medium.T variable */,873.15);
    if(!(tmp35 && tmp36))
    {
      tmp38 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[184] /* tankHot.medium.T variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp37),tmp38);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Media/package.mo",5020,7,5020,44,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\ntankHot.medium.T >= 573.15 and tankHot.medium.T <= 873.15", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp39 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1176
type: ALGORITHM

  assert(data.Tdew >= 0.0, "Variable violating min constraint: 0.0 <= data.Tdew, has value: " + String(data.Tdew, "g"));
*/
void Reference_1_eqFunction_1176(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1176};
  modelica_boolean tmp40;
  static const MMC_DEFSTRINGLIT(tmp41,64,"Variable violating min constraint: 0.0 <= data.Tdew, has value: ");
  modelica_string tmp42;
  static int tmp43 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp43)
  {
    tmp40 = GreaterEq(data->localData[0]->realVars[81] /* data.Tdew variable */,0.0);
    if(!tmp40)
    {
      tmp42 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[81] /* data.Tdew variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp41),tmp42);
      {
        FILE_INFO info = {"/home/cparrado/.openmodelica/libraries/SolarTherm/Models/Sources/DataTable/DataTable.mo",19,3,19,29,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\ndata.Tdew >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp43 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1177
type: ALGORITHM

  assert(Tamb_input.y >= 0.0, "Variable violating min constraint: 0.0 <= Tamb_input.y, has value: " + String(Tamb_input.y, "g"));
*/
void Reference_1_eqFunction_1177(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1177};
  modelica_boolean tmp44;
  static const MMC_DEFSTRINGLIT(tmp45,67,"Variable violating min constraint: 0.0 <= Tamb_input.y, has value: ");
  modelica_string tmp46;
  static int tmp47 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp47)
  {
    tmp44 = GreaterEq(data->localData[0]->realVars[57] /* Tamb_input.y variable */,0.0);
    if(!tmp44)
    {
      tmp46 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[57] /* Tamb_input.y variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp45),tmp46);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Blocks/Sources.mo",10,5,12,56,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nTamb_input.y >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp47 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1178
type: ALGORITHM

  assert(heliostatField.optical.nu >= 0.0, "Variable violating min constraint: 0.0 <= heliostatField.optical.nu, has value: " + String(heliostatField.optical.nu, "g"));
*/
void Reference_1_eqFunction_1178(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1178};
  modelica_boolean tmp48;
  static const MMC_DEFSTRINGLIT(tmp49,80,"Variable violating min constraint: 0.0 <= heliostatField.optical.nu, has value: ");
  modelica_string tmp50;
  static int tmp51 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp51)
  {
    tmp48 = GreaterEq(data->localData[0]->realVars[102] /* heliostatField.optical.nu variable */,0.0);
    if(!tmp48)
    {
      tmp50 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[102] /* heliostatField.optical.nu variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp49),tmp50);
      {
        FILE_INFO info = {"/home/cparrado/.openmodelica/libraries/SolarTherm/Models/CSP/CRS/HeliostatsField/Optical/OpticalEfficiency.mo",3,3,3,53,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nheliostatField.optical.nu >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp51 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1179
type: ALGORITHM

  assert(receiver.medium.h >= -10000000000.0 and receiver.medium.h <= 10000000000.0, "Variable violating min/max constraint: -10000000000.0 <= receiver.medium.h <= 10000000000.0, has value: " + String(receiver.medium.h, "g"));
*/
void Reference_1_eqFunction_1179(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1179};
  modelica_boolean tmp52;
  modelica_boolean tmp53;
  static const MMC_DEFSTRINGLIT(tmp54,104,"Variable violating min/max constraint: -10000000000.0 <= receiver.medium.h <= 10000000000.0, has value: ");
  modelica_string tmp55;
  static int tmp56 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp56)
  {
    tmp52 = GreaterEq(data->localData[0]->realVars[140] /* receiver.medium.h variable */,-10000000000.0);
    tmp53 = LessEq(data->localData[0]->realVars[140] /* receiver.medium.h variable */,10000000000.0);
    if(!(tmp52 && tmp53))
    {
      tmp55 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[140] /* receiver.medium.h variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp54),tmp55);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Media/package.mo",5018,7,5018,60,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nreceiver.medium.h >= -10000000000.0 and receiver.medium.h <= 10000000000.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp56 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1180
type: ALGORITHM

  assert(receiver.medium.d >= 0.0 and receiver.medium.d <= 100000.0, "Variable violating min/max constraint: 0.0 <= receiver.medium.d <= 100000.0, has value: " + String(receiver.medium.d, "g"));
*/
void Reference_1_eqFunction_1180(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1180};
  modelica_boolean tmp57;
  modelica_boolean tmp58;
  static const MMC_DEFSTRINGLIT(tmp59,88,"Variable violating min/max constraint: 0.0 <= receiver.medium.d <= 100000.0, has value: ");
  modelica_string tmp60;
  static int tmp61 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp61)
  {
    tmp57 = GreaterEq(data->localData[0]->realVars[139] /* receiver.medium.d variable */,0.0);
    tmp58 = LessEq(data->localData[0]->realVars[139] /* receiver.medium.d variable */,100000.0);
    if(!(tmp57 && tmp58))
    {
      tmp60 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[139] /* receiver.medium.d variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp59),tmp60);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Media/package.mo",5019,7,5019,36,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nreceiver.medium.d >= 0.0 and receiver.medium.d <= 100000.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp61 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1181
type: ALGORITHM

  assert(receiver.medium.T >= 573.15 and receiver.medium.T <= 873.15, "Variable violating min/max constraint: 573.15 <= receiver.medium.T <= 873.15, has value: " + String(receiver.medium.T, "g"));
*/
void Reference_1_eqFunction_1181(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1181};
  modelica_boolean tmp62;
  modelica_boolean tmp63;
  static const MMC_DEFSTRINGLIT(tmp64,89,"Variable violating min/max constraint: 573.15 <= receiver.medium.T <= 873.15, has value: ");
  modelica_string tmp65;
  static int tmp66 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp66)
  {
    tmp62 = GreaterEq(data->localData[0]->realVars[135] /* receiver.medium.T variable */,573.15);
    tmp63 = LessEq(data->localData[0]->realVars[135] /* receiver.medium.T variable */,873.15);
    if(!(tmp62 && tmp63))
    {
      tmp65 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[135] /* receiver.medium.T variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp64),tmp65);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Media/package.mo",5020,7,5020,44,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nreceiver.medium.T >= 573.15 and receiver.medium.T <= 873.15", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp66 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1182
type: ALGORITHM

  assert(receiver.medium.u >= -100000000.0 and receiver.medium.u <= 100000000.0, "Variable violating min/max constraint: -100000000.0 <= receiver.medium.u <= 100000000.0, has value: " + String(receiver.medium.u, "g"));
*/
void Reference_1_eqFunction_1182(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1182};
  modelica_boolean tmp67;
  modelica_boolean tmp68;
  static const MMC_DEFSTRINGLIT(tmp69,100,"Variable violating min/max constraint: -100000000.0 <= receiver.medium.u <= 100000000.0, has value: ");
  modelica_string tmp70;
  static int tmp71 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp71)
  {
    tmp67 = GreaterEq(data->localData[0]->realVars[142] /* receiver.medium.u variable */,-100000000.0);
    tmp68 = LessEq(data->localData[0]->realVars[142] /* receiver.medium.u variable */,100000000.0);
    if(!(tmp67 && tmp68))
    {
      tmp70 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[142] /* receiver.medium.u variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp69),tmp70);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Media/package.mo",5023,7,5023,68,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nreceiver.medium.u >= -100000000.0 and receiver.medium.u <= 100000000.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp71 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1183
type: ALGORITHM

  assert(receiver.h_out >= -10000000000.0 and receiver.h_out <= 10000000000.0, "Variable violating min/max constraint: -10000000000.0 <= receiver.h_out <= 10000000000.0, has value: " + String(receiver.h_out, "g"));
*/
void Reference_1_eqFunction_1183(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1183};
  modelica_boolean tmp72;
  modelica_boolean tmp73;
  static const MMC_DEFSTRINGLIT(tmp74,101,"Variable violating min/max constraint: -10000000000.0 <= receiver.h_out <= 10000000000.0, has value: ");
  modelica_string tmp75;
  static int tmp76 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp76)
  {
    tmp72 = GreaterEq(data->localData[0]->realVars[131] /* receiver.h_out variable */,-10000000000.0);
    tmp73 = LessEq(data->localData[0]->realVars[131] /* receiver.h_out variable */,10000000000.0);
    if(!(tmp72 && tmp73))
    {
      tmp75 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[131] /* receiver.h_out variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp74),tmp75);
      {
        FILE_INFO info = {"/home/cparrado/.openmodelica/libraries/SolarTherm/Models/CSP/CRS/Receivers/ReceiverSimple.mo",6,3,6,40,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nreceiver.h_out >= -10000000000.0 and receiver.h_out <= 10000000000.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp76 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1184
type: ALGORITHM

  assert(receiver.T >= 0.0, "Variable violating min constraint: 0.0 <= receiver.T, has value: " + String(receiver.T, "g"));
*/
void Reference_1_eqFunction_1184(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1184};
  modelica_boolean tmp77;
  static const MMC_DEFSTRINGLIT(tmp78,65,"Variable violating min constraint: 0.0 <= receiver.T, has value: ");
  modelica_string tmp79;
  static int tmp80 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp80)
  {
    tmp77 = GreaterEq(data->localData[0]->realVars[128] /* receiver.T variable */,0.0);
    if(!tmp77)
    {
      tmp79 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[128] /* receiver.T variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp78),tmp79);
      {
        FILE_INFO info = {"/home/cparrado/.openmodelica/libraries/SolarTherm/Models/CSP/CRS/Receivers/ReceiverSimple.mo",21,3,28,25,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nreceiver.T >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp80 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1185
type: ALGORITHM

  assert(tankHot.m >= 0.0, "Variable violating min constraint: 0.0 <= tankHot.m, has value: " + String(tankHot.m, "g"));
*/
void Reference_1_eqFunction_1185(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1185};
  modelica_boolean tmp81;
  static const MMC_DEFSTRINGLIT(tmp82,64,"Variable violating min constraint: 0.0 <= tankHot.m, has value: ");
  modelica_string tmp83;
  static int tmp84 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp84)
  {
    tmp81 = GreaterEq(data->localData[0]->realVars[9] /* tankHot.m STATE(1) */,0.0);
    if(!tmp81)
    {
      tmp83 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[9] /* tankHot.m STATE(1) */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp82),tmp83);
      {
        FILE_INFO info = {"/home/cparrado/.openmodelica/libraries/SolarTherm/Models/Storage/Tank/Tank.mo",37,3,37,12,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\ntankHot.m >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp84 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1186
type: ALGORITHM

  assert(tankHot.medium.h >= -10000000000.0 and tankHot.medium.h <= 10000000000.0, "Variable violating min/max constraint: -10000000000.0 <= tankHot.medium.h <= 10000000000.0, has value: " + String(tankHot.medium.h, "g"));
*/
void Reference_1_eqFunction_1186(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1186};
  modelica_boolean tmp85;
  modelica_boolean tmp86;
  static const MMC_DEFSTRINGLIT(tmp87,103,"Variable violating min/max constraint: -10000000000.0 <= tankHot.medium.h <= 10000000000.0, has value: ");
  modelica_string tmp88;
  static int tmp89 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp89)
  {
    tmp85 = GreaterEq(data->localData[0]->realVars[10] /* tankHot.medium.h STATE(1) */,-10000000000.0);
    tmp86 = LessEq(data->localData[0]->realVars[10] /* tankHot.medium.h STATE(1) */,10000000000.0);
    if(!(tmp85 && tmp86))
    {
      tmp88 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[10] /* tankHot.medium.h STATE(1) */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp87),tmp88);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Media/package.mo",5018,7,5018,60,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\ntankHot.medium.h >= -10000000000.0 and tankHot.medium.h <= 10000000000.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp89 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1187
type: ALGORITHM

  assert(tankHot.medium.d >= 0.0 and tankHot.medium.d <= 100000.0, "Variable violating min/max constraint: 0.0 <= tankHot.medium.d <= 100000.0, has value: " + String(tankHot.medium.d, "g"));
*/
void Reference_1_eqFunction_1187(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1187};
  modelica_boolean tmp90;
  modelica_boolean tmp91;
  static const MMC_DEFSTRINGLIT(tmp92,87,"Variable violating min/max constraint: 0.0 <= tankHot.medium.d <= 100000.0, has value: ");
  modelica_string tmp93;
  static int tmp94 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp94)
  {
    tmp90 = GreaterEq(data->localData[0]->realVars[188] /* tankHot.medium.d variable */,0.0);
    tmp91 = LessEq(data->localData[0]->realVars[188] /* tankHot.medium.d variable */,100000.0);
    if(!(tmp90 && tmp91))
    {
      tmp93 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[188] /* tankHot.medium.d variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp92),tmp93);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Media/package.mo",5019,7,5019,36,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\ntankHot.medium.d >= 0.0 and tankHot.medium.d <= 100000.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp94 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1188
type: ALGORITHM

  assert(tankHot.medium.u >= -100000000.0 and tankHot.medium.u <= 100000000.0, "Variable violating min/max constraint: -100000000.0 <= tankHot.medium.u <= 100000000.0, has value: " + String(tankHot.medium.u, "g"));
*/
void Reference_1_eqFunction_1188(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1188};
  modelica_boolean tmp95;
  modelica_boolean tmp96;
  static const MMC_DEFSTRINGLIT(tmp97,99,"Variable violating min/max constraint: -100000000.0 <= tankHot.medium.u <= 100000000.0, has value: ");
  modelica_string tmp98;
  static int tmp99 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp99)
  {
    tmp95 = GreaterEq(data->localData[0]->realVars[190] /* tankHot.medium.u variable */,-100000000.0);
    tmp96 = LessEq(data->localData[0]->realVars[190] /* tankHot.medium.u variable */,100000000.0);
    if(!(tmp95 && tmp96))
    {
      tmp98 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[190] /* tankHot.medium.u variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp97),tmp98);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Media/package.mo",5023,7,5023,68,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\ntankHot.medium.u >= -100000000.0 and tankHot.medium.u <= 100000000.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp99 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1189
type: ALGORITHM

  assert(tankCold.m >= 0.0, "Variable violating min constraint: 0.0 <= tankCold.m, has value: " + String(tankCold.m, "g"));
*/
void Reference_1_eqFunction_1189(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1189};
  modelica_boolean tmp100;
  static const MMC_DEFSTRINGLIT(tmp101,65,"Variable violating min constraint: 0.0 <= tankCold.m, has value: ");
  modelica_string tmp102;
  static int tmp103 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp103)
  {
    tmp100 = GreaterEq(data->localData[0]->realVars[7] /* tankCold.m STATE(1) */,0.0);
    if(!tmp100)
    {
      tmp102 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[7] /* tankCold.m STATE(1) */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp101),tmp102);
      {
        FILE_INFO info = {"/home/cparrado/.openmodelica/libraries/SolarTherm/Models/Storage/Tank/Tank.mo",37,3,37,12,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\ntankCold.m >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp103 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1190
type: ALGORITHM

  assert(tankCold.medium.h >= -10000000000.0 and tankCold.medium.h <= 10000000000.0, "Variable violating min/max constraint: -10000000000.0 <= tankCold.medium.h <= 10000000000.0, has value: " + String(tankCold.medium.h, "g"));
*/
void Reference_1_eqFunction_1190(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1190};
  modelica_boolean tmp104;
  modelica_boolean tmp105;
  static const MMC_DEFSTRINGLIT(tmp106,104,"Variable violating min/max constraint: -10000000000.0 <= tankCold.medium.h <= 10000000000.0, has value: ");
  modelica_string tmp107;
  static int tmp108 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp108)
  {
    tmp104 = GreaterEq(data->localData[0]->realVars[8] /* tankCold.medium.h STATE(1) */,-10000000000.0);
    tmp105 = LessEq(data->localData[0]->realVars[8] /* tankCold.medium.h STATE(1) */,10000000000.0);
    if(!(tmp104 && tmp105))
    {
      tmp107 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[8] /* tankCold.medium.h STATE(1) */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp106),tmp107);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Media/package.mo",5018,7,5018,60,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\ntankCold.medium.h >= -10000000000.0 and tankCold.medium.h <= 10000000000.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp108 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1191
type: ALGORITHM

  assert(tankCold.medium.d >= 0.0 and tankCold.medium.d <= 100000.0, "Variable violating min/max constraint: 0.0 <= tankCold.medium.d <= 100000.0, has value: " + String(tankCold.medium.d, "g"));
*/
void Reference_1_eqFunction_1191(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1191};
  modelica_boolean tmp109;
  modelica_boolean tmp110;
  static const MMC_DEFSTRINGLIT(tmp111,88,"Variable violating min/max constraint: 0.0 <= tankCold.medium.d <= 100000.0, has value: ");
  modelica_string tmp112;
  static int tmp113 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp113)
  {
    tmp109 = GreaterEq(data->localData[0]->realVars[172] /* tankCold.medium.d variable */,0.0);
    tmp110 = LessEq(data->localData[0]->realVars[172] /* tankCold.medium.d variable */,100000.0);
    if(!(tmp109 && tmp110))
    {
      tmp112 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[172] /* tankCold.medium.d variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp111),tmp112);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Media/package.mo",5019,7,5019,36,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\ntankCold.medium.d >= 0.0 and tankCold.medium.d <= 100000.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp113 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1192
type: ALGORITHM

  assert(tankCold.medium.u >= -100000000.0 and tankCold.medium.u <= 100000000.0, "Variable violating min/max constraint: -100000000.0 <= tankCold.medium.u <= 100000000.0, has value: " + String(tankCold.medium.u, "g"));
*/
void Reference_1_eqFunction_1192(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1192};
  modelica_boolean tmp114;
  modelica_boolean tmp115;
  static const MMC_DEFSTRINGLIT(tmp116,100,"Variable violating min/max constraint: -100000000.0 <= tankCold.medium.u <= 100000000.0, has value: ");
  modelica_string tmp117;
  static int tmp118 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp118)
  {
    tmp114 = GreaterEq(data->localData[0]->realVars[174] /* tankCold.medium.u variable */,-100000000.0);
    tmp115 = LessEq(data->localData[0]->realVars[174] /* tankCold.medium.u variable */,100000000.0);
    if(!(tmp114 && tmp115))
    {
      tmp117 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[174] /* tankCold.medium.u variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp116),tmp117);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Media/package.mo",5023,7,5023,68,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\ntankCold.medium.u >= -100000000.0 and tankCold.medium.u <= 100000000.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp118 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1193
type: ALGORITHM

  assert(tankCold.T >= 573.15 and tankCold.T <= 873.15, "Variable violating min/max constraint: 573.15 <= tankCold.T <= 873.15, has value: " + String(tankCold.T, "g"));
*/
void Reference_1_eqFunction_1193(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1193};
  modelica_boolean tmp119;
  modelica_boolean tmp120;
  static const MMC_DEFSTRINGLIT(tmp121,82,"Variable violating min/max constraint: 573.15 <= tankCold.T <= 873.15, has value: ");
  modelica_string tmp122;
  static int tmp123 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp123)
  {
    tmp119 = GreaterEq(data->localData[0]->realVars[163] /* tankCold.T variable */,573.15);
    tmp120 = LessEq(data->localData[0]->realVars[163] /* tankCold.T variable */,873.15);
    if(!(tmp119 && tmp120))
    {
      tmp122 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[163] /* tankCold.T variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp121),tmp122);
      {
        FILE_INFO info = {"/home/cparrado/.openmodelica/libraries/SolarTherm/Models/Storage/Tank/Tank.mo",43,3,43,52,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\ntankCold.T >= 573.15 and tankCold.T <= 873.15", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp123 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1194
type: ALGORITHM

  assert(tankCold.p_top_internal >= 0.0 and tankCold.p_top_internal <= 100000000.0, "Variable violating min/max constraint: 0.0 <= tankCold.p_top_internal <= 100000000.0, has value: " + String(tankCold.p_top_internal, "g"));
*/
void Reference_1_eqFunction_1194(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1194};
  modelica_boolean tmp124;
  modelica_boolean tmp125;
  static const MMC_DEFSTRINGLIT(tmp126,97,"Variable violating min/max constraint: 0.0 <= tankCold.p_top_internal <= 100000000.0, has value: ");
  modelica_string tmp127;
  static int tmp128 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp128)
  {
    tmp124 = GreaterEq(data->localData[0]->realVars[175] /* tankCold.p_top_internal variable */,0.0);
    tmp125 = LessEq(data->localData[0]->realVars[175] /* tankCold.p_top_internal variable */,100000000.0);
    if(!(tmp124 && tmp125))
    {
      tmp127 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[175] /* tankCold.p_top_internal variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp126),tmp127);
      {
        FILE_INFO info = {"/home/cparrado/.openmodelica/libraries/SolarTherm/Models/Storage/Tank/Tank.mo",75,3,75,54,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\ntankCold.p_top_internal >= 0.0 and tankCold.p_top_internal <= 100000000.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp128 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1195
type: ALGORITHM

  assert(temperature.state.h >= -10000000000.0 and temperature.state.h <= 10000000000.0, "Variable violating min/max constraint: -10000000000.0 <= temperature.state.h <= 10000000000.0, has value: " + String(temperature.state.h, "g"));
*/
void Reference_1_eqFunction_1195(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1195};
  modelica_boolean tmp129;
  modelica_boolean tmp130;
  static const MMC_DEFSTRINGLIT(tmp131,106,"Variable violating min/max constraint: -10000000000.0 <= temperature.state.h <= 10000000000.0, has value: ");
  modelica_string tmp132;
  static int tmp133 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp133)
  {
    tmp129 = GreaterEq(data->localData[0]->realVars[192] /* temperature.state.h variable */,-10000000000.0);
    tmp130 = LessEq(data->localData[0]->realVars[192] /* temperature.state.h variable */,10000000000.0);
    if(!(tmp129 && tmp130))
    {
      tmp132 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[192] /* temperature.state.h variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp131),tmp132);
      {
        FILE_INFO info = {"/home/cparrado/.openmodelica/libraries/SolarTherm/Media/MoltenSalt/MoltenSalt_ph/package.mo",70,3,70,41,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\ntemperature.state.h >= -10000000000.0 and temperature.state.h <= 10000000000.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp133 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1196
type: ALGORITHM

  assert(controlHot.m_flow >= -100000.0 and controlHot.m_flow <= 100000.0, "Variable violating min/max constraint: -100000.0 <= controlHot.m_flow <= 100000.0, has value: " + String(controlHot.m_flow, "g"));
*/
void Reference_1_eqFunction_1196(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1196};
  modelica_boolean tmp134;
  modelica_boolean tmp135;
  static const MMC_DEFSTRINGLIT(tmp136,94,"Variable violating min/max constraint: -100000.0 <= controlHot.m_flow <= 100000.0, has value: ");
  modelica_string tmp137;
  static int tmp138 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp138)
  {
    tmp134 = GreaterEq(data->localData[0]->realVars[75] /* controlHot.m_flow variable */,-100000.0);
    tmp135 = LessEq(data->localData[0]->realVars[75] /* controlHot.m_flow variable */,100000.0);
    if(!(tmp134 && tmp135))
    {
      tmp137 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[75] /* controlHot.m_flow variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp136),tmp137);
      {
        FILE_INFO info = {"/home/cparrado/.openmodelica/libraries/SolarTherm/Models/Control/PowerBlockControl.mo",17,3,18,71,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\ncontrolHot.m_flow >= -100000.0 and controlHot.m_flow <= 100000.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp138 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1197
type: ALGORITHM

  assert(controlCold.m_flow >= -100000.0 and controlCold.m_flow <= 100000.0, "Variable violating min/max constraint: -100000.0 <= controlCold.m_flow <= 100000.0, has value: " + String(controlCold.m_flow, "g"));
*/
void Reference_1_eqFunction_1197(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1197};
  modelica_boolean tmp139;
  modelica_boolean tmp140;
  static const MMC_DEFSTRINGLIT(tmp141,95,"Variable violating min/max constraint: -100000.0 <= controlCold.m_flow <= 100000.0, has value: ");
  modelica_string tmp142;
  static int tmp143 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp143)
  {
    tmp139 = GreaterEq(data->localData[0]->realVars[71] /* controlCold.m_flow variable */,-100000.0);
    tmp140 = LessEq(data->localData[0]->realVars[71] /* controlCold.m_flow variable */,100000.0);
    if(!(tmp139 && tmp140))
    {
      tmp142 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[71] /* controlCold.m_flow variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp141),tmp142);
      {
        FILE_INFO info = {"/home/cparrado/.openmodelica/libraries/SolarTherm/Models/Control/ReceiverControl.mo",34,3,35,71,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\ncontrolCold.m_flow >= -100000.0 and controlCold.m_flow <= 100000.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp143 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1198
type: ALGORITHM

  assert(controlCold.T_mea >= 0.0, "Variable violating min constraint: 0.0 <= controlCold.T_mea, has value: " + String(controlCold.T_mea, "g"));
*/
void Reference_1_eqFunction_1198(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1198};
  modelica_boolean tmp144;
  static const MMC_DEFSTRINGLIT(tmp145,72,"Variable violating min constraint: 0.0 <= controlCold.T_mea, has value: ");
  modelica_string tmp146;
  static int tmp147 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp147)
  {
    tmp144 = GreaterEq(data->localData[0]->realVars[68] /* controlCold.T_mea variable */,0.0);
    if(!tmp144)
    {
      tmp146 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[68] /* controlCold.T_mea variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp145),tmp146);
      {
        FILE_INFO info = {"/home/cparrado/.openmodelica/libraries/SolarTherm/Models/Control/ReceiverControl.mo",38,3,39,72,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\ncontrolCold.T_mea >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp147 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1199
type: ALGORITHM

  assert(powerBlock.fluid_b.h_outflow >= -10000000000.0 and powerBlock.fluid_b.h_outflow <= 10000000000.0, "Variable violating min/max constraint: -10000000000.0 <= powerBlock.fluid_b.h_outflow <= 10000000000.0, has value: " + String(powerBlock.fluid_b.h_outflow, "g"));
*/
void Reference_1_eqFunction_1199(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1199};
  modelica_boolean tmp148;
  modelica_boolean tmp149;
  static const MMC_DEFSTRINGLIT(tmp150,115,"Variable violating min/max constraint: -10000000000.0 <= powerBlock.fluid_b.h_outflow <= 10000000000.0, has value: ");
  modelica_string tmp151;
  static int tmp152 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp152)
  {
    tmp148 = GreaterEq(data->localData[0]->realVars[118] /* powerBlock.fluid_b.h_outflow variable */,-10000000000.0);
    tmp149 = LessEq(data->localData[0]->realVars[118] /* powerBlock.fluid_b.h_outflow variable */,10000000000.0);
    if(!(tmp148 && tmp149))
    {
      tmp151 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[118] /* powerBlock.fluid_b.h_outflow variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp150),tmp151);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Fluid/Interfaces.mo",16,5,17,84,1};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\npowerBlock.fluid_b.h_outflow >= -10000000000.0 and powerBlock.fluid_b.h_outflow <= 10000000000.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp152 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1200
type: ALGORITHM

  assert(powerBlock.T_in >= 573.15 and powerBlock.T_in <= 873.15, "Variable violating min/max constraint: 573.15 <= powerBlock.T_in <= 873.15, has value: " + String(powerBlock.T_in, "g"));
*/
void Reference_1_eqFunction_1200(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1200};
  modelica_boolean tmp153;
  modelica_boolean tmp154;
  static const MMC_DEFSTRINGLIT(tmp155,87,"Variable violating min/max constraint: 573.15 <= powerBlock.T_in <= 873.15, has value: ");
  modelica_string tmp156;
  static int tmp157 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp157)
  {
    tmp153 = GreaterEq(data->localData[0]->realVars[108] /* powerBlock.T_in variable */,573.15);
    tmp154 = LessEq(data->localData[0]->realVars[108] /* powerBlock.T_in variable */,873.15);
    if(!(tmp153 && tmp154))
    {
      tmp156 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[108] /* powerBlock.T_in variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp155),tmp156);
      {
        FILE_INFO info = {"/home/cparrado/.openmodelica/libraries/SolarTherm/Models/PowerBlocks/PowerBlockModel.mo",14,3,14,51,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\npowerBlock.T_in >= 573.15 and powerBlock.T_in <= 873.15", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp157 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1201
type: ALGORITHM

  assert(powerBlock.T_out >= 0.0, "Variable violating min constraint: 0.0 <= powerBlock.T_out, has value: " + String(powerBlock.T_out, "g"));
*/
void Reference_1_eqFunction_1201(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1201};
  modelica_boolean tmp158;
  static const MMC_DEFSTRINGLIT(tmp159,71,"Variable violating min constraint: 0.0 <= powerBlock.T_out, has value: ");
  modelica_string tmp160;
  static int tmp161 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp161)
  {
    tmp158 = GreaterEq(data->localData[0]->realVars[109] /* powerBlock.T_out variable */,0.0);
    if(!tmp158)
    {
      tmp160 = modelica_real_to_modelica_string_format(data->localData[0]->realVars[109] /* powerBlock.T_out variable */, (modelica_string) mmc_strings_len1[103]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp159),tmp160);
      {
        FILE_INFO info = {"/home/cparrado/.openmodelica/libraries/SolarTherm/Models/PowerBlocks/PowerBlockModel.mo",15,3,15,53,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\npowerBlock.T_out >= 0.0", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp161 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1202
type: ALGORITHM

  assert(sch_fixed.week[1].i >= 1 and sch_fixed.week[1].i <= 7, "Variable violating min/max constraint: 1 <= sch_fixed.week[1].i <= 7, has value: " + String(sch_fixed.week[1].i, "d"));
*/
void Reference_1_eqFunction_1202(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1202};
  modelica_boolean tmp162;
  modelica_boolean tmp163;
  static const MMC_DEFSTRINGLIT(tmp164,81,"Variable violating min/max constraint: 1 <= sch_fixed.week[1].i <= 7, has value: ");
  modelica_string tmp165;
  static int tmp166 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp166)
  {
    tmp162 = GreaterEq(data->localData[0]->integerVars[2] /* sch_fixed.week[1].i DISCRETE */,((modelica_integer) 1));
    tmp163 = LessEq(data->localData[0]->integerVars[2] /* sch_fixed.week[1].i DISCRETE */,((modelica_integer) 7));
    if(!(tmp162 && tmp163))
    {
      tmp165 = modelica_integer_to_modelica_string_format(data->localData[0]->integerVars[2] /* sch_fixed.week[1].i DISCRETE */, (modelica_string) mmc_strings_len1[100]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp164),tmp165);
      {
        FILE_INFO info = {"/home/cparrado/.openmodelica/libraries/SolarTherm/Models/Sources/Schedule/IntMap.mo",3,2,3,33,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nsch_fixed.week[1].i >= 1 and sch_fixed.week[1].i <= 7", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp166 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 1203
type: ALGORITHM

  assert(sch_fixed.month.i >= 1 and sch_fixed.month.i <= 12, "Variable violating min/max constraint: 1 <= sch_fixed.month.i <= 12, has value: " + String(sch_fixed.month.i, "d"));
*/
void Reference_1_eqFunction_1203(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1203};
  modelica_boolean tmp167;
  modelica_boolean tmp168;
  static const MMC_DEFSTRINGLIT(tmp169,80,"Variable violating min/max constraint: 1 <= sch_fixed.month.i <= 12, has value: ");
  modelica_string tmp170;
  static int tmp171 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp171)
  {
    tmp167 = GreaterEq(data->localData[0]->integerVars[0] /* sch_fixed.month.i DISCRETE */,((modelica_integer) 1));
    tmp168 = LessEq(data->localData[0]->integerVars[0] /* sch_fixed.month.i DISCRETE */,((modelica_integer) 12));
    if(!(tmp167 && tmp168))
    {
      tmp170 = modelica_integer_to_modelica_string_format(data->localData[0]->integerVars[0] /* sch_fixed.month.i DISCRETE */, (modelica_string) mmc_strings_len1[100]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp169),tmp170);
      {
        FILE_INFO info = {"/home/cparrado/.openmodelica/libraries/SolarTherm/Models/Sources/Schedule/IntMap.mo",3,2,3,33,0};
        omc_assert_warning(info, "The following assertion has been violated %sat time %f\nsch_fixed.month.i >= 1 and sch_fixed.month.i <= 12", initial() ? "during initialization " : "", data->localData[0]->timeValue);
        omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      }
      tmp171 = 1;
    }
  }
  TRACE_POP
}
/* function to check assert after a step is done */
OMC_DISABLE_OPT
int Reference_1_checkForAsserts(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  Reference_1_eqFunction_1208(data, threadData);

  Reference_1_eqFunction_1207(data, threadData);

  Reference_1_eqFunction_1206(data, threadData);

  Reference_1_eqFunction_1205(data, threadData);

  Reference_1_eqFunction_1204(data, threadData);

  Reference_1_eqFunction_1172(data, threadData);

  Reference_1_eqFunction_1173(data, threadData);

  Reference_1_eqFunction_1174(data, threadData);

  Reference_1_eqFunction_1175(data, threadData);

  Reference_1_eqFunction_1176(data, threadData);

  Reference_1_eqFunction_1177(data, threadData);

  Reference_1_eqFunction_1178(data, threadData);

  Reference_1_eqFunction_1179(data, threadData);

  Reference_1_eqFunction_1180(data, threadData);

  Reference_1_eqFunction_1181(data, threadData);

  Reference_1_eqFunction_1182(data, threadData);

  Reference_1_eqFunction_1183(data, threadData);

  Reference_1_eqFunction_1184(data, threadData);

  Reference_1_eqFunction_1185(data, threadData);

  Reference_1_eqFunction_1186(data, threadData);

  Reference_1_eqFunction_1187(data, threadData);

  Reference_1_eqFunction_1188(data, threadData);

  Reference_1_eqFunction_1189(data, threadData);

  Reference_1_eqFunction_1190(data, threadData);

  Reference_1_eqFunction_1191(data, threadData);

  Reference_1_eqFunction_1192(data, threadData);

  Reference_1_eqFunction_1193(data, threadData);

  Reference_1_eqFunction_1194(data, threadData);

  Reference_1_eqFunction_1195(data, threadData);

  Reference_1_eqFunction_1196(data, threadData);

  Reference_1_eqFunction_1197(data, threadData);

  Reference_1_eqFunction_1198(data, threadData);

  Reference_1_eqFunction_1199(data, threadData);

  Reference_1_eqFunction_1200(data, threadData);

  Reference_1_eqFunction_1201(data, threadData);

  Reference_1_eqFunction_1202(data, threadData);

  Reference_1_eqFunction_1203(data, threadData);
  
  TRACE_POP
  return 0;
}

#if defined(__cplusplus)
}
#endif

