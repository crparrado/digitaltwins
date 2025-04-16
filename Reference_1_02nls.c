/* Non Linear Systems */
#include "Reference_1_model.h"
#include "Reference_1_12jac.h"
#if defined(__cplusplus)
extern "C" {
#endif

/* inner equations */

/*
equation index: 138
type: SIMPLE_ASSIGN
temperature.state.h = max(receiver.h_0, receiver.h_out)
*/
void Reference_1_eqFunction_138(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,138};
  data->localData[0]->realVars[192] /* temperature.state.h variable */ = fmax(data->simulationInfo->realParameter[233] /* receiver.h_0 PARAM */,data->localData[0]->realVars[131] /* receiver.h_out variable */);
  TRACE_POP
}
/*
equation index: 139
type: SIMPLE_ASSIGN
controlCold.T_mea = SolarTherm.Media.MoltenSalt.MoltenSalt_utilities.T_h(temperature.state.h)
*/
void Reference_1_eqFunction_139(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,139};
  data->localData[0]->realVars[68] /* controlCold.T_mea variable */ = omc_SolarTherm_Media_MoltenSalt_MoltenSalt__utilities_T__h(threadData, data->localData[0]->realVars[192] /* temperature.state.h variable */);
  TRACE_POP
}
/*
equation index: 140
type: SIMPLE_ASSIGN
receiver.medium.h = 0.5 * (tankCold.medium.h + receiver.h_out)
*/
void Reference_1_eqFunction_140(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,140};
  data->localData[0]->realVars[140] /* receiver.medium.h variable */ = (0.5) * (data->localData[0]->realVars[8] /* tankCold.medium.h STATE(1) */ + data->localData[0]->realVars[131] /* receiver.h_out variable */);
  TRACE_POP
}
/*
equation index: 141
type: SIMPLE_ASSIGN
receiver.medium.T = SolarTherm.Media.MoltenSalt.MoltenSalt_utilities.T_h(receiver.medium.h)
*/
void Reference_1_eqFunction_141(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,141};
  data->localData[0]->realVars[135] /* receiver.medium.T variable */ = omc_SolarTherm_Media_MoltenSalt_MoltenSalt__utilities_T__h(threadData, data->localData[0]->realVars[140] /* receiver.medium.h variable */);
  TRACE_POP
}
/*
equation index: 142
type: SIMPLE_ASSIGN
receiver.Q_loss = (-5.670367e-08) * receiver.A * receiver.em * (receiver.medium.T ^ 4.0 - Tamb_input.y ^ 4.0)
*/
void Reference_1_eqFunction_142(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,142};
  modelica_real tmp0;
  modelica_real tmp1;
  tmp0 = data->localData[0]->realVars[135] /* receiver.medium.T variable */;
  tmp0 *= tmp0;tmp1 = data->localData[0]->realVars[57] /* Tamb_input.y variable */;
  tmp1 *= tmp1;
  data->localData[0]->realVars[126] /* receiver.Q_loss variable */ = (-5.670367e-08) * ((data->simulationInfo->realParameter[224] /* receiver.A PARAM */) * ((data->simulationInfo->realParameter[232] /* receiver.em PARAM */) * ((tmp0 * tmp0) - ((tmp1 * tmp1)))));
  TRACE_POP
}
/*
equation index: 143
type: SIMPLE_ASSIGN
controlCold.PI.u = controlCold.T_ref - controlCold.T_mea
*/
void Reference_1_eqFunction_143(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,143};
  data->localData[0]->realVars[66] /* controlCold.PI.u variable */ = data->simulationInfo->realParameter[79] /* controlCold.T_ref PARAM */ - data->localData[0]->realVars[68] /* controlCold.T_mea variable */;
  TRACE_POP
}
/*
equation index: 144
type: SIMPLE_ASSIGN
controlCold.PI.Add.u1 = controlCold.PI.P.k * controlCold.PI.u
*/
void Reference_1_eqFunction_144(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,144};
  data->localData[0]->realVars[59] /* controlCold.PI.Add.u1 variable */ = (data->simulationInfo->realParameter[65] /* controlCold.PI.P.k PARAM */) * (data->localData[0]->realVars[66] /* controlCold.PI.u variable */);
  TRACE_POP
}
/*
equation index: 145
type: SIMPLE_ASSIGN
controlCold.PI.Add.y = controlCold.PI.Add.k1 * controlCold.PI.Add.u1 + controlCold.PI.Add.k2 * controlCold.PI.I.y
*/
void Reference_1_eqFunction_145(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,145};
  data->localData[0]->realVars[60] /* controlCold.PI.Add.y variable */ = (data->simulationInfo->realParameter[60] /* controlCold.PI.Add.k1 PARAM */) * (data->localData[0]->realVars[59] /* controlCold.PI.Add.u1 variable */) + (data->simulationInfo->realParameter[61] /* controlCold.PI.Add.k2 PARAM */) * (data->localData[0]->realVars[1] /* controlCold.PI.I.y STATE(1) */);
  TRACE_POP
}
/*
equation index: 146
type: SIMPLE_ASSIGN
controlCold.PI.y = homotopy(smooth(0, if controlCold.PI.Add.y > controlCold.PI.limiter.uMax then controlCold.PI.limiter.uMax else if controlCold.PI.Add.y < controlCold.PI.limiter.uMin then controlCold.PI.limiter.uMin else controlCold.PI.Add.y), controlCold.PI.Add.y)
*/
void Reference_1_eqFunction_146(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,146};
  modelica_boolean tmp0;
  modelica_boolean tmp1;
  modelica_boolean tmp2;
  modelica_real tmp3;
  tmp0 = Greater(data->localData[0]->realVars[60] /* controlCold.PI.Add.y variable */,data->simulationInfo->realParameter[74] /* controlCold.PI.limiter.uMax PARAM */);
  tmp2 = (modelica_boolean)tmp0;
  if(tmp2)
  {
    tmp3 = data->simulationInfo->realParameter[74] /* controlCold.PI.limiter.uMax PARAM */;
  }
  else
  {
    tmp1 = Less(data->localData[0]->realVars[60] /* controlCold.PI.Add.y variable */,data->simulationInfo->realParameter[75] /* controlCold.PI.limiter.uMin PARAM */);
    tmp3 = (tmp1?data->simulationInfo->realParameter[75] /* controlCold.PI.limiter.uMin PARAM */:data->localData[0]->realVars[60] /* controlCold.PI.Add.y variable */);
  }
  data->localData[0]->realVars[67] /* controlCold.PI.y variable */ = homotopy(tmp3, data->localData[0]->realVars[60] /* controlCold.PI.Add.y variable */);
  TRACE_POP
}
/*
equation index: 147
type: SIMPLE_ASSIGN
controlCold.m_flow = if controlCold.PI.reset then controlCold.PI.y else 0.0
*/
void Reference_1_eqFunction_147(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,147};
  data->localData[0]->realVars[71] /* controlCold.m_flow variable */ = (data->localData[0]->booleanVars[23] /* controlCold.PI.reset DISCRETE */?data->localData[0]->realVars[67] /* controlCold.PI.y variable */:0.0);
  TRACE_POP
}

void residualFunc149(void** dataIn, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = (DATA*) ((void**)dataIn[0]);
  threadData_t *threadData = (threadData_t*) ((void**)dataIn[1]);
  const int equationIndexes[2] = {1,149};
  int i;
  /* iteration variables */
  for (i=0; i<1; i++) {
    if (isinf(xloc[i]) || isnan(xloc[i])) {
      for (i=0; i<1; i++) {
        res[i] = NAN;
      }
      return;
    }
  }
  data->localData[0]->realVars[131] /* receiver.h_out variable */ = xloc[0];
  /* backup outputs */
  /* pre body */
  /* local constraints */
  Reference_1_eqFunction_138(data, threadData);

  /* local constraints */
  Reference_1_eqFunction_139(data, threadData);

  /* local constraints */
  Reference_1_eqFunction_140(data, threadData);

  /* local constraints */
  Reference_1_eqFunction_141(data, threadData);

  /* local constraints */
  Reference_1_eqFunction_142(data, threadData);

  /* local constraints */
  Reference_1_eqFunction_143(data, threadData);

  /* local constraints */
  Reference_1_eqFunction_144(data, threadData);

  /* local constraints */
  Reference_1_eqFunction_145(data, threadData);

  /* local constraints */
  Reference_1_eqFunction_146(data, threadData);

  /* local constraints */
  Reference_1_eqFunction_147(data, threadData);
  /* body */
  res[0] = (data->localData[0]->realVars[71] /* controlCold.m_flow variable */) * (data->localData[0]->realVars[8] /* tankCold.medium.h STATE(1) */ - data->localData[0]->realVars[131] /* receiver.h_out variable */) + data->localData[0]->realVars[126] /* receiver.Q_loss variable */ + (data->simulationInfo->realParameter[231] /* receiver.ab PARAM */) * (data->localData[0]->realVars[132] /* receiver.heat.Q_flow variable */);
  /* restore known outputs */
  TRACE_POP
}

OMC_DISABLE_OPT
void initializeSparsePatternNLS149(NONLINEAR_SYSTEM_DATA* inSysData)
{
  int i=0;
  const int colPtrIndex[1+1] = {0,1};
  const int rowIndex[1] = {0};
  /* sparsity pattern available */
  inSysData->isPatternAvailable = 'T';
  inSysData->sparsePattern = (SPARSE_PATTERN*) malloc(sizeof(SPARSE_PATTERN));
  inSysData->sparsePattern->leadindex = (unsigned int*) malloc((1+1)*sizeof(unsigned int));
  inSysData->sparsePattern->index = (unsigned int*) malloc(1*sizeof(unsigned int));
  inSysData->sparsePattern->numberOfNoneZeros = 1;
  inSysData->sparsePattern->colorCols = (unsigned int*) malloc(1*sizeof(unsigned int));
  inSysData->sparsePattern->maxColors = 1;
  
  /* write lead index of compressed sparse column */
  memcpy(inSysData->sparsePattern->leadindex, colPtrIndex, (1+1)*sizeof(unsigned int));
  
  for(i=2;i<1+1;++i)
    inSysData->sparsePattern->leadindex[i] += inSysData->sparsePattern->leadindex[i-1];
  
  /* call sparse index */
  memcpy(inSysData->sparsePattern->index, rowIndex, 1*sizeof(unsigned int));
  
  /* write color array */
  inSysData->sparsePattern->colorCols[0] = 1;
}

OMC_DISABLE_OPT
void initializeStaticDataNLS149(void *inData, threadData_t *threadData, void *inSystemData)
{
  DATA* data = (DATA*) inData;
  NONLINEAR_SYSTEM_DATA* sysData = (NONLINEAR_SYSTEM_DATA*) inSystemData;
  int i=0;
  /* static nls data for receiver.h_out */
  sysData->nominal[i] = data->modelData->realVarsData[131].attribute /* receiver.h_out */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[131].attribute /* receiver.h_out */.min;
  sysData->max[i++]   = data->modelData->realVarsData[131].attribute /* receiver.h_out */.max;
  /* initial sparse pattern */
  initializeSparsePatternNLS149(sysData);
}

OMC_DISABLE_OPT
void getIterationVarsNLS149(struct DATA *inData, double *array)
{
  DATA* data = (DATA*) inData;
  array[0] = data->localData[0]->realVars[131] /* receiver.h_out variable */;
}


/* inner equations */

/*
equation index: 393
type: SIMPLE_ASSIGN
temperature.state.h = max(receiver.h_0, receiver.h_out)
*/
void Reference_1_eqFunction_393(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,393};
  data->localData[0]->realVars[192] /* temperature.state.h variable */ = fmax(data->simulationInfo->realParameter[233] /* receiver.h_0 PARAM */,data->localData[0]->realVars[131] /* receiver.h_out variable */);
  TRACE_POP
}
/*
equation index: 394
type: SIMPLE_ASSIGN
controlCold.T_mea = SolarTherm.Media.MoltenSalt.MoltenSalt_utilities.T_h(temperature.state.h)
*/
void Reference_1_eqFunction_394(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,394};
  data->localData[0]->realVars[68] /* controlCold.T_mea variable */ = omc_SolarTherm_Media_MoltenSalt_MoltenSalt__utilities_T__h(threadData, data->localData[0]->realVars[192] /* temperature.state.h variable */);
  TRACE_POP
}
/*
equation index: 395
type: SIMPLE_ASSIGN
receiver.medium.h = 0.5 * (tankCold.medium.h + receiver.h_out)
*/
void Reference_1_eqFunction_395(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,395};
  data->localData[0]->realVars[140] /* receiver.medium.h variable */ = (0.5) * (data->localData[0]->realVars[8] /* tankCold.medium.h STATE(1) */ + data->localData[0]->realVars[131] /* receiver.h_out variable */);
  TRACE_POP
}
/*
equation index: 396
type: SIMPLE_ASSIGN
receiver.medium.T = SolarTherm.Media.MoltenSalt.MoltenSalt_utilities.T_h(receiver.medium.h)
*/
void Reference_1_eqFunction_396(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,396};
  data->localData[0]->realVars[135] /* receiver.medium.T variable */ = omc_SolarTherm_Media_MoltenSalt_MoltenSalt__utilities_T__h(threadData, data->localData[0]->realVars[140] /* receiver.medium.h variable */);
  TRACE_POP
}
/*
equation index: 397
type: SIMPLE_ASSIGN
receiver.Q_loss = (-5.670367e-08) * receiver.A * receiver.em * (receiver.medium.T ^ 4.0 - Tamb_input.y ^ 4.0)
*/
void Reference_1_eqFunction_397(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,397};
  modelica_real tmp0;
  modelica_real tmp1;
  tmp0 = data->localData[0]->realVars[135] /* receiver.medium.T variable */;
  tmp0 *= tmp0;tmp1 = data->localData[0]->realVars[57] /* Tamb_input.y variable */;
  tmp1 *= tmp1;
  data->localData[0]->realVars[126] /* receiver.Q_loss variable */ = (-5.670367e-08) * ((data->simulationInfo->realParameter[224] /* receiver.A PARAM */) * ((data->simulationInfo->realParameter[232] /* receiver.em PARAM */) * ((tmp0 * tmp0) - ((tmp1 * tmp1)))));
  TRACE_POP
}
/*
equation index: 398
type: SIMPLE_ASSIGN
controlCold.PI.u = controlCold.T_ref - controlCold.T_mea
*/
void Reference_1_eqFunction_398(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,398};
  data->localData[0]->realVars[66] /* controlCold.PI.u variable */ = data->simulationInfo->realParameter[79] /* controlCold.T_ref PARAM */ - data->localData[0]->realVars[68] /* controlCold.T_mea variable */;
  TRACE_POP
}
/*
equation index: 399
type: SIMPLE_ASSIGN
controlCold.PI.Add.u1 = controlCold.PI.P.k * controlCold.PI.u
*/
void Reference_1_eqFunction_399(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,399};
  data->localData[0]->realVars[59] /* controlCold.PI.Add.u1 variable */ = (data->simulationInfo->realParameter[65] /* controlCold.PI.P.k PARAM */) * (data->localData[0]->realVars[66] /* controlCold.PI.u variable */);
  TRACE_POP
}
/*
equation index: 400
type: SIMPLE_ASSIGN
controlCold.PI.Add.y = controlCold.PI.Add.k1 * controlCold.PI.Add.u1 + controlCold.PI.Add.k2 * controlCold.PI.I.y
*/
void Reference_1_eqFunction_400(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,400};
  data->localData[0]->realVars[60] /* controlCold.PI.Add.y variable */ = (data->simulationInfo->realParameter[60] /* controlCold.PI.Add.k1 PARAM */) * (data->localData[0]->realVars[59] /* controlCold.PI.Add.u1 variable */) + (data->simulationInfo->realParameter[61] /* controlCold.PI.Add.k2 PARAM */) * (data->localData[0]->realVars[1] /* controlCold.PI.I.y STATE(1) */);
  TRACE_POP
}
/*
equation index: 401
type: SIMPLE_ASSIGN
controlCold.PI.y = controlCold.PI.Add.y
*/
void Reference_1_eqFunction_401(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,401};
  data->localData[0]->realVars[67] /* controlCold.PI.y variable */ = data->localData[0]->realVars[60] /* controlCold.PI.Add.y variable */;
  TRACE_POP
}
/*
equation index: 402
type: SIMPLE_ASSIGN
controlCold.m_flow = if controlCold.PI.reset then controlCold.PI.y else 0.0
*/
void Reference_1_eqFunction_402(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,402};
  data->localData[0]->realVars[71] /* controlCold.m_flow variable */ = (data->localData[0]->booleanVars[23] /* controlCold.PI.reset DISCRETE */?data->localData[0]->realVars[67] /* controlCold.PI.y variable */:0.0);
  TRACE_POP
}

void residualFunc404(void** dataIn, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = (DATA*) ((void**)dataIn[0]);
  threadData_t *threadData = (threadData_t*) ((void**)dataIn[1]);
  const int equationIndexes[2] = {1,404};
  int i;
  /* iteration variables */
  for (i=0; i<1; i++) {
    if (isinf(xloc[i]) || isnan(xloc[i])) {
      for (i=0; i<1; i++) {
        res[i] = NAN;
      }
      return;
    }
  }
  data->localData[0]->realVars[131] /* receiver.h_out variable */ = xloc[0];
  /* backup outputs */
  /* pre body */
  /* local constraints */
  Reference_1_eqFunction_393(data, threadData);

  /* local constraints */
  Reference_1_eqFunction_394(data, threadData);

  /* local constraints */
  Reference_1_eqFunction_395(data, threadData);

  /* local constraints */
  Reference_1_eqFunction_396(data, threadData);

  /* local constraints */
  Reference_1_eqFunction_397(data, threadData);

  /* local constraints */
  Reference_1_eqFunction_398(data, threadData);

  /* local constraints */
  Reference_1_eqFunction_399(data, threadData);

  /* local constraints */
  Reference_1_eqFunction_400(data, threadData);

  /* local constraints */
  Reference_1_eqFunction_401(data, threadData);

  /* local constraints */
  Reference_1_eqFunction_402(data, threadData);
  /* body */
  res[0] = (data->localData[0]->realVars[71] /* controlCold.m_flow variable */) * (data->localData[0]->realVars[8] /* tankCold.medium.h STATE(1) */ - data->localData[0]->realVars[131] /* receiver.h_out variable */) + data->localData[0]->realVars[126] /* receiver.Q_loss variable */ + (data->simulationInfo->realParameter[231] /* receiver.ab PARAM */) * (data->localData[0]->realVars[132] /* receiver.heat.Q_flow variable */);
  /* restore known outputs */
  TRACE_POP
}

OMC_DISABLE_OPT
void initializeSparsePatternNLS404(NONLINEAR_SYSTEM_DATA* inSysData)
{
  int i=0;
  const int colPtrIndex[1+1] = {0,1};
  const int rowIndex[1] = {0};
  /* sparsity pattern available */
  inSysData->isPatternAvailable = 'T';
  inSysData->sparsePattern = (SPARSE_PATTERN*) malloc(sizeof(SPARSE_PATTERN));
  inSysData->sparsePattern->leadindex = (unsigned int*) malloc((1+1)*sizeof(unsigned int));
  inSysData->sparsePattern->index = (unsigned int*) malloc(1*sizeof(unsigned int));
  inSysData->sparsePattern->numberOfNoneZeros = 1;
  inSysData->sparsePattern->colorCols = (unsigned int*) malloc(1*sizeof(unsigned int));
  inSysData->sparsePattern->maxColors = 1;
  
  /* write lead index of compressed sparse column */
  memcpy(inSysData->sparsePattern->leadindex, colPtrIndex, (1+1)*sizeof(unsigned int));
  
  for(i=2;i<1+1;++i)
    inSysData->sparsePattern->leadindex[i] += inSysData->sparsePattern->leadindex[i-1];
  
  /* call sparse index */
  memcpy(inSysData->sparsePattern->index, rowIndex, 1*sizeof(unsigned int));
  
  /* write color array */
  inSysData->sparsePattern->colorCols[0] = 1;
}

OMC_DISABLE_OPT
void initializeStaticDataNLS404(void *inData, threadData_t *threadData, void *inSystemData)
{
  DATA* data = (DATA*) inData;
  NONLINEAR_SYSTEM_DATA* sysData = (NONLINEAR_SYSTEM_DATA*) inSystemData;
  int i=0;
  /* static nls data for receiver.h_out */
  sysData->nominal[i] = data->modelData->realVarsData[131].attribute /* receiver.h_out */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[131].attribute /* receiver.h_out */.min;
  sysData->max[i++]   = data->modelData->realVarsData[131].attribute /* receiver.h_out */.max;
  /* initial sparse pattern */
  initializeSparsePatternNLS404(sysData);
}

OMC_DISABLE_OPT
void getIterationVarsNLS404(struct DATA *inData, double *array)
{
  DATA* data = (DATA*) inData;
  array[0] = data->localData[0]->realVars[131] /* receiver.h_out variable */;
}


/* inner equations */

/*
equation index: 644
type: SIMPLE_ASSIGN
temperature.state.h = max(receiver.h_0, receiver.h_out)
*/
void Reference_1_eqFunction_644(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,644};
  data->localData[0]->realVars[192] /* temperature.state.h variable */ = fmax(data->simulationInfo->realParameter[233] /* receiver.h_0 PARAM */,data->localData[0]->realVars[131] /* receiver.h_out variable */);
  TRACE_POP
}
/*
equation index: 645
type: SIMPLE_ASSIGN
controlCold.T_mea = SolarTherm.Media.MoltenSalt.MoltenSalt_utilities.T_h(temperature.state.h)
*/
void Reference_1_eqFunction_645(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,645};
  data->localData[0]->realVars[68] /* controlCold.T_mea variable */ = omc_SolarTherm_Media_MoltenSalt_MoltenSalt__utilities_T__h(threadData, data->localData[0]->realVars[192] /* temperature.state.h variable */);
  TRACE_POP
}
/*
equation index: 646
type: SIMPLE_ASSIGN
receiver.medium.h = 0.5 * (tankCold.medium.h + receiver.h_out)
*/
void Reference_1_eqFunction_646(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,646};
  data->localData[0]->realVars[140] /* receiver.medium.h variable */ = (0.5) * (data->localData[0]->realVars[8] /* tankCold.medium.h STATE(1) */ + data->localData[0]->realVars[131] /* receiver.h_out variable */);
  TRACE_POP
}
/*
equation index: 647
type: SIMPLE_ASSIGN
receiver.medium.T = SolarTherm.Media.MoltenSalt.MoltenSalt_utilities.T_h(receiver.medium.h)
*/
void Reference_1_eqFunction_647(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,647};
  data->localData[0]->realVars[135] /* receiver.medium.T variable */ = omc_SolarTherm_Media_MoltenSalt_MoltenSalt__utilities_T__h(threadData, data->localData[0]->realVars[140] /* receiver.medium.h variable */);
  TRACE_POP
}
/*
equation index: 648
type: SIMPLE_ASSIGN
receiver.Q_loss = (-5.670367e-08) * receiver.A * receiver.em * (receiver.medium.T ^ 4.0 - Tamb_input.y ^ 4.0)
*/
void Reference_1_eqFunction_648(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,648};
  modelica_real tmp0;
  modelica_real tmp1;
  tmp0 = data->localData[0]->realVars[135] /* receiver.medium.T variable */;
  tmp0 *= tmp0;tmp1 = data->localData[0]->realVars[57] /* Tamb_input.y variable */;
  tmp1 *= tmp1;
  data->localData[0]->realVars[126] /* receiver.Q_loss variable */ = (-5.670367e-08) * ((data->simulationInfo->realParameter[224] /* receiver.A PARAM */) * ((data->simulationInfo->realParameter[232] /* receiver.em PARAM */) * ((tmp0 * tmp0) - ((tmp1 * tmp1)))));
  TRACE_POP
}
/*
equation index: 649
type: SIMPLE_ASSIGN
controlCold.PI.u = controlCold.T_ref - controlCold.T_mea
*/
void Reference_1_eqFunction_649(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,649};
  data->localData[0]->realVars[66] /* controlCold.PI.u variable */ = data->simulationInfo->realParameter[79] /* controlCold.T_ref PARAM */ - data->localData[0]->realVars[68] /* controlCold.T_mea variable */;
  TRACE_POP
}
/*
equation index: 650
type: SIMPLE_ASSIGN
controlCold.PI.Add.u1 = controlCold.PI.P.k * controlCold.PI.u
*/
void Reference_1_eqFunction_650(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,650};
  data->localData[0]->realVars[59] /* controlCold.PI.Add.u1 variable */ = (data->simulationInfo->realParameter[65] /* controlCold.PI.P.k PARAM */) * (data->localData[0]->realVars[66] /* controlCold.PI.u variable */);
  TRACE_POP
}
/*
equation index: 651
type: SIMPLE_ASSIGN
controlCold.PI.Add.y = controlCold.PI.Add.k1 * controlCold.PI.Add.u1 + controlCold.PI.Add.k2 * controlCold.PI.I.y
*/
void Reference_1_eqFunction_651(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,651};
  data->localData[0]->realVars[60] /* controlCold.PI.Add.y variable */ = (data->simulationInfo->realParameter[60] /* controlCold.PI.Add.k1 PARAM */) * (data->localData[0]->realVars[59] /* controlCold.PI.Add.u1 variable */) + (data->simulationInfo->realParameter[61] /* controlCold.PI.Add.k2 PARAM */) * (data->localData[0]->realVars[1] /* controlCold.PI.I.y STATE(1) */);
  TRACE_POP
}
/*
equation index: 652
type: SIMPLE_ASSIGN
controlCold.PI.y = smooth(0, if controlCold.PI.Add.y > controlCold.PI.limiter.uMax then controlCold.PI.limiter.uMax else if controlCold.PI.Add.y < controlCold.PI.limiter.uMin then controlCold.PI.limiter.uMin else controlCold.PI.Add.y)
*/
void Reference_1_eqFunction_652(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,652};
  modelica_boolean tmp0;
  modelica_boolean tmp1;
  modelica_boolean tmp2;
  modelica_real tmp3;
  tmp0 = Greater(data->localData[0]->realVars[60] /* controlCold.PI.Add.y variable */,data->simulationInfo->realParameter[74] /* controlCold.PI.limiter.uMax PARAM */);
  tmp2 = (modelica_boolean)tmp0;
  if(tmp2)
  {
    tmp3 = data->simulationInfo->realParameter[74] /* controlCold.PI.limiter.uMax PARAM */;
  }
  else
  {
    tmp1 = Less(data->localData[0]->realVars[60] /* controlCold.PI.Add.y variable */,data->simulationInfo->realParameter[75] /* controlCold.PI.limiter.uMin PARAM */);
    tmp3 = (tmp1?data->simulationInfo->realParameter[75] /* controlCold.PI.limiter.uMin PARAM */:data->localData[0]->realVars[60] /* controlCold.PI.Add.y variable */);
  }
  data->localData[0]->realVars[67] /* controlCold.PI.y variable */ = tmp3;
  TRACE_POP
}
/*
equation index: 653
type: SIMPLE_ASSIGN
controlCold.m_flow = if $whenCondition22 then controlCold.PI.y else 0.0
*/
void Reference_1_eqFunction_653(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,653};
  data->localData[0]->realVars[71] /* controlCold.m_flow variable */ = (data->localData[0]->booleanVars[14] /* $whenCondition22 DISCRETE */?data->localData[0]->realVars[67] /* controlCold.PI.y variable */:0.0);
  TRACE_POP
}

void residualFunc655(void** dataIn, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = (DATA*) ((void**)dataIn[0]);
  threadData_t *threadData = (threadData_t*) ((void**)dataIn[1]);
  const int equationIndexes[2] = {1,655};
  int i;
  /* iteration variables */
  for (i=0; i<1; i++) {
    if (isinf(xloc[i]) || isnan(xloc[i])) {
      for (i=0; i<1; i++) {
        res[i] = NAN;
      }
      return;
    }
  }
  data->localData[0]->realVars[131] /* receiver.h_out variable */ = xloc[0];
  /* backup outputs */
  /* pre body */
  /* local constraints */
  Reference_1_eqFunction_644(data, threadData);

  /* local constraints */
  Reference_1_eqFunction_645(data, threadData);

  /* local constraints */
  Reference_1_eqFunction_646(data, threadData);

  /* local constraints */
  Reference_1_eqFunction_647(data, threadData);

  /* local constraints */
  Reference_1_eqFunction_648(data, threadData);

  /* local constraints */
  Reference_1_eqFunction_649(data, threadData);

  /* local constraints */
  Reference_1_eqFunction_650(data, threadData);

  /* local constraints */
  Reference_1_eqFunction_651(data, threadData);

  /* local constraints */
  Reference_1_eqFunction_652(data, threadData);

  /* local constraints */
  Reference_1_eqFunction_653(data, threadData);
  /* body */
  res[0] = (data->localData[0]->realVars[71] /* controlCold.m_flow variable */) * (data->localData[0]->realVars[8] /* tankCold.medium.h STATE(1) */ - data->localData[0]->realVars[131] /* receiver.h_out variable */) - ((data->simulationInfo->realParameter[231] /* receiver.ab PARAM */) * (data->localData[0]->realVars[44] /* $cse3 variable */)) + data->localData[0]->realVars[126] /* receiver.Q_loss variable */;
  /* restore known outputs */
  TRACE_POP
}

OMC_DISABLE_OPT
void initializeSparsePatternNLS655(NONLINEAR_SYSTEM_DATA* inSysData)
{
  int i=0;
  const int colPtrIndex[1+1] = {0,1};
  const int rowIndex[1] = {0};
  /* sparsity pattern available */
  inSysData->isPatternAvailable = 'T';
  inSysData->sparsePattern = (SPARSE_PATTERN*) malloc(sizeof(SPARSE_PATTERN));
  inSysData->sparsePattern->leadindex = (unsigned int*) malloc((1+1)*sizeof(unsigned int));
  inSysData->sparsePattern->index = (unsigned int*) malloc(1*sizeof(unsigned int));
  inSysData->sparsePattern->numberOfNoneZeros = 1;
  inSysData->sparsePattern->colorCols = (unsigned int*) malloc(1*sizeof(unsigned int));
  inSysData->sparsePattern->maxColors = 1;
  
  /* write lead index of compressed sparse column */
  memcpy(inSysData->sparsePattern->leadindex, colPtrIndex, (1+1)*sizeof(unsigned int));
  
  for(i=2;i<1+1;++i)
    inSysData->sparsePattern->leadindex[i] += inSysData->sparsePattern->leadindex[i-1];
  
  /* call sparse index */
  memcpy(inSysData->sparsePattern->index, rowIndex, 1*sizeof(unsigned int));
  
  /* write color array */
  inSysData->sparsePattern->colorCols[0] = 1;
}

OMC_DISABLE_OPT
void initializeStaticDataNLS655(void *inData, threadData_t *threadData, void *inSystemData)
{
  DATA* data = (DATA*) inData;
  NONLINEAR_SYSTEM_DATA* sysData = (NONLINEAR_SYSTEM_DATA*) inSystemData;
  int i=0;
  /* static nls data for receiver.h_out */
  sysData->nominal[i] = data->modelData->realVarsData[131].attribute /* receiver.h_out */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[131].attribute /* receiver.h_out */.min;
  sysData->max[i++]   = data->modelData->realVarsData[131].attribute /* receiver.h_out */.max;
  /* initial sparse pattern */
  initializeSparsePatternNLS655(sysData);
}

OMC_DISABLE_OPT
void getIterationVarsNLS655(struct DATA *inData, double *array)
{
  DATA* data = (DATA*) inData;
  array[0] = data->localData[0]->realVars[131] /* receiver.h_out variable */;
}

/* Prototypes for the strict sets (Dynamic Tearing) */

/* Global constraints for the casual sets */
/* function initialize non-linear systems */
void Reference_1_initialNonLinearSystem(int nNonLinearSystems, NONLINEAR_SYSTEM_DATA* nonLinearSystemData)
{
  
  nonLinearSystemData[2].equationIndex = 655;
  nonLinearSystemData[2].size = 1;
  nonLinearSystemData[2].homotopySupport = 0;
  nonLinearSystemData[2].mixedSystem = 1;
  nonLinearSystemData[2].residualFunc = residualFunc655;
  nonLinearSystemData[2].strictTearingFunctionCall = NULL;
  nonLinearSystemData[2].analyticalJacobianColumn = NULL;
  nonLinearSystemData[2].initialAnalyticalJacobian = NULL;
  nonLinearSystemData[2].jacobianIndex = -1;
  nonLinearSystemData[2].initializeStaticNLSData = initializeStaticDataNLS655;
  nonLinearSystemData[2].getIterationVars = getIterationVarsNLS655;
  nonLinearSystemData[2].checkConstraints = NULL;
  
  
  nonLinearSystemData[1].equationIndex = 404;
  nonLinearSystemData[1].size = 1;
  nonLinearSystemData[1].homotopySupport = 0;
  nonLinearSystemData[1].mixedSystem = 0;
  nonLinearSystemData[1].residualFunc = residualFunc404;
  nonLinearSystemData[1].strictTearingFunctionCall = NULL;
  nonLinearSystemData[1].analyticalJacobianColumn = NULL;
  nonLinearSystemData[1].initialAnalyticalJacobian = NULL;
  nonLinearSystemData[1].jacobianIndex = -1;
  nonLinearSystemData[1].initializeStaticNLSData = initializeStaticDataNLS404;
  nonLinearSystemData[1].getIterationVars = getIterationVarsNLS404;
  nonLinearSystemData[1].checkConstraints = NULL;
  
  
  nonLinearSystemData[0].equationIndex = 149;
  nonLinearSystemData[0].size = 1;
  nonLinearSystemData[0].homotopySupport = 1;
  nonLinearSystemData[0].mixedSystem = 1;
  nonLinearSystemData[0].residualFunc = residualFunc149;
  nonLinearSystemData[0].strictTearingFunctionCall = NULL;
  nonLinearSystemData[0].analyticalJacobianColumn = NULL;
  nonLinearSystemData[0].initialAnalyticalJacobian = NULL;
  nonLinearSystemData[0].jacobianIndex = -1;
  nonLinearSystemData[0].initializeStaticNLSData = initializeStaticDataNLS149;
  nonLinearSystemData[0].getIterationVars = getIterationVarsNLS149;
  nonLinearSystemData[0].checkConstraints = NULL;
}

#if defined(__cplusplus)
}
#endif

