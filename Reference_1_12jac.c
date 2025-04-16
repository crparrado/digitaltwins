/* Jacobians 5 */
#include "Reference_1_model.h"
#include "Reference_1_12jac.h"
int Reference_1_functionJacF_column(void* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  TRACE_POP
  return 0;
}
int Reference_1_functionJacD_column(void* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  TRACE_POP
  return 0;
}
int Reference_1_functionJacC_column(void* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  TRACE_POP
  return 0;
}
int Reference_1_functionJacB_column(void* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  TRACE_POP
  return 0;
}
/* constant equations */
/* dynamic equations */

OMC_DISABLE_OPT
int Reference_1_functionJacA_constantEqns(void* inData, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  DATA* data = ((DATA*)inData);
  int index = Reference_1_INDEX_JAC_A;
  
  
  TRACE_POP
  return 0;
}

int Reference_1_functionJacA_column(void* inData, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  DATA* data = ((DATA*)inData);
  int index = Reference_1_INDEX_JAC_A;
  TRACE_POP
  return 0;
}

int Reference_1_initialAnalyticJacobianF(void* inData, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  TRACE_POP
  return 1;
}
int Reference_1_initialAnalyticJacobianD(void* inData, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  TRACE_POP
  return 1;
}
int Reference_1_initialAnalyticJacobianC(void* inData, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  TRACE_POP
  return 1;
}
int Reference_1_initialAnalyticJacobianB(void* inData, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  TRACE_POP
  return 1;
}
OMC_DISABLE_OPT
int Reference_1_initialAnalyticJacobianA(void* inData, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  DATA* data = ((DATA*)inData);
  const int colPtrIndex[1+11] = {0,0,9,0,0,0,0,0,10,10,10,10};
  const int rowIndex[49] = {0,1,4,5,6,7,8,9,10,0,1,3,4,5,6,7,8,9,10,0,1,3,4,5,6,7,8,9,10,0,1,3,4,5,6,7,8,9,10,0,1,3,4,5,6,7,8,9,10};
  int i = 0;
  
  jacobian->sizeCols = 11;
  jacobian->sizeRows = 11;
  jacobian->sizeTmpVars = 0;
  jacobian->seedVars = (modelica_real*) calloc(11,sizeof(modelica_real));
  jacobian->resultVars = (modelica_real*) calloc(11,sizeof(modelica_real));
  jacobian->tmpVars = (modelica_real*) calloc(0,sizeof(modelica_real));
  jacobian->sparsePattern = (SPARSE_PATTERN*) malloc(sizeof(SPARSE_PATTERN));
  jacobian->sparsePattern->leadindex = (unsigned int*) malloc((11+1)*sizeof(unsigned int));
  jacobian->sparsePattern->index = (unsigned int*) malloc(49*sizeof(unsigned int));
  jacobian->sparsePattern->numberOfNoneZeros = 49;
  jacobian->sparsePattern->colorCols = (unsigned int*) malloc(11*sizeof(unsigned int));
  jacobian->sparsePattern->maxColors = 5;
  jacobian->constantEqns = NULL;
  
  /* write lead index of compressed sparse column */
  memcpy(jacobian->sparsePattern->leadindex, colPtrIndex, (11+1)*sizeof(unsigned int));
  
  for(i=2;i<11+1;++i)
    jacobian->sparsePattern->leadindex[i] += jacobian->sparsePattern->leadindex[i-1];
  
  /* call sparse index */
  memcpy(jacobian->sparsePattern->index, rowIndex, 49*sizeof(unsigned int));
  
  /* write color array */
  jacobian->sparsePattern->colorCols[1] = 1;
  jacobian->sparsePattern->colorCols[8] = 2;
  jacobian->sparsePattern->colorCols[7] = 3;
  jacobian->sparsePattern->colorCols[10] = 4;
  jacobian->sparsePattern->colorCols[2] = 5;
  jacobian->sparsePattern->colorCols[3] = 5;
  jacobian->sparsePattern->colorCols[9] = 5;
  jacobian->sparsePattern->colorCols[5] = 5;
  jacobian->sparsePattern->colorCols[6] = 5;
  jacobian->sparsePattern->colorCols[4] = 5;
  jacobian->sparsePattern->colorCols[0] = 5;
  TRACE_POP
  return 0;
}


