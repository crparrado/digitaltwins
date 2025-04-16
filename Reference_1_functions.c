#include "omc_simulation_settings.h"
#include "Reference_1_functions.h"
#ifdef __cplusplus
extern "C" {
#endif

#include "Reference_1_includes.h"


modelica_real omc_Modelica_Blocks_Tables_Internal_getNextTimeEvent(threadData_t *threadData, modelica_complex _tableID, modelica_real _timeIn)
{
  void * _tableID_ext;
  double _timeIn_ext;
  double _nextTimeEvent_ext;
  modelica_real _nextTimeEvent;
  // _nextTimeEvent has no default value.
  _tableID_ext = (void *)_tableID;

  _timeIn_ext = (double)_timeIn;
  _nextTimeEvent_ext = ModelicaStandardTables_CombiTimeTable_nextTimeEvent(_tableID_ext, _timeIn_ext);
  _nextTimeEvent = (modelica_real)_nextTimeEvent_ext;
  return _nextTimeEvent;
}
modelica_metatype boxptr_Modelica_Blocks_Tables_Internal_getNextTimeEvent(threadData_t *threadData, modelica_metatype _tableID, modelica_metatype _timeIn)
{
  modelica_real tmp1;
  modelica_real _nextTimeEvent;
  modelica_metatype out_nextTimeEvent;
  tmp1 = mmc_unbox_real(_timeIn);
  _nextTimeEvent = omc_Modelica_Blocks_Tables_Internal_getNextTimeEvent(threadData, _tableID, tmp1);
  out_nextTimeEvent = mmc_mk_rcon(_nextTimeEvent);
  return out_nextTimeEvent;
}

modelica_real omc_Modelica_Blocks_Tables_Internal_getTable1DAbscissaUmax(threadData_t *threadData, modelica_complex _tableID)
{
  void * _tableID_ext;
  double _uMax_ext;
  modelica_real _uMax;
  // _uMax has no default value.
  _tableID_ext = (void *)_tableID;
  _uMax_ext = ModelicaStandardTables_CombiTable1D_maximumAbscissa(_tableID_ext);
  _uMax = (modelica_real)_uMax_ext;
  return _uMax;
}
modelica_metatype boxptr_Modelica_Blocks_Tables_Internal_getTable1DAbscissaUmax(threadData_t *threadData, modelica_metatype _tableID)
{
  modelica_real _uMax;
  modelica_metatype out_uMax;
  _uMax = omc_Modelica_Blocks_Tables_Internal_getTable1DAbscissaUmax(threadData, _tableID);
  out_uMax = mmc_mk_rcon(_uMax);
  return out_uMax;
}

modelica_real omc_Modelica_Blocks_Tables_Internal_getTable1DAbscissaUmin(threadData_t *threadData, modelica_complex _tableID)
{
  void * _tableID_ext;
  double _uMin_ext;
  modelica_real _uMin;
  // _uMin has no default value.
  _tableID_ext = (void *)_tableID;
  _uMin_ext = ModelicaStandardTables_CombiTable1D_minimumAbscissa(_tableID_ext);
  _uMin = (modelica_real)_uMin_ext;
  return _uMin;
}
modelica_metatype boxptr_Modelica_Blocks_Tables_Internal_getTable1DAbscissaUmin(threadData_t *threadData, modelica_metatype _tableID)
{
  modelica_real _uMin;
  modelica_metatype out_uMin;
  _uMin = omc_Modelica_Blocks_Tables_Internal_getTable1DAbscissaUmin(threadData, _tableID);
  out_uMin = mmc_mk_rcon(_uMin);
  return out_uMin;
}

modelica_real omc_Modelica_Blocks_Tables_Internal_getTable1DValue(threadData_t *threadData, modelica_complex _tableID, modelica_integer _icol, modelica_real _u)
{
  void * _tableID_ext;
  int _icol_ext;
  double _u_ext;
  double _y_ext;
  modelica_real _y;
  // _y has no default value.
  _tableID_ext = (void *)_tableID;

  _icol_ext = (int)_icol;

  _u_ext = (double)_u;
  _y_ext = ModelicaStandardTables_CombiTable1D_getValue(_tableID_ext, _icol_ext, _u_ext);
  _y = (modelica_real)_y_ext;
  return _y;
}
modelica_metatype boxptr_Modelica_Blocks_Tables_Internal_getTable1DValue(threadData_t *threadData, modelica_metatype _tableID, modelica_metatype _icol, modelica_metatype _u)
{
  modelica_integer tmp1;
  modelica_real tmp2;
  modelica_real _y;
  modelica_metatype out_y;
  tmp1 = mmc_unbox_integer(_icol);
  tmp2 = mmc_unbox_real(_u);
  _y = omc_Modelica_Blocks_Tables_Internal_getTable1DValue(threadData, _tableID, tmp1, tmp2);
  out_y = mmc_mk_rcon(_y);
  return out_y;
}

modelica_real omc_Modelica_Blocks_Tables_Internal_getTable1DValueNoDer(threadData_t *threadData, modelica_complex _tableID, modelica_integer _icol, modelica_real _u)
{
  void * _tableID_ext;
  int _icol_ext;
  double _u_ext;
  double _y_ext;
  modelica_real _y;
  // _y has no default value.
  _tableID_ext = (void *)_tableID;

  _icol_ext = (int)_icol;

  _u_ext = (double)_u;
  _y_ext = ModelicaStandardTables_CombiTable1D_getValue(_tableID_ext, _icol_ext, _u_ext);
  _y = (modelica_real)_y_ext;
  return _y;
}
modelica_metatype boxptr_Modelica_Blocks_Tables_Internal_getTable1DValueNoDer(threadData_t *threadData, modelica_metatype _tableID, modelica_metatype _icol, modelica_metatype _u)
{
  modelica_integer tmp1;
  modelica_real tmp2;
  modelica_real _y;
  modelica_metatype out_y;
  tmp1 = mmc_unbox_integer(_icol);
  tmp2 = mmc_unbox_real(_u);
  _y = omc_Modelica_Blocks_Tables_Internal_getTable1DValueNoDer(threadData, _tableID, tmp1, tmp2);
  out_y = mmc_mk_rcon(_y);
  return out_y;
}

real_array omc_Modelica_Blocks_Tables_Internal_getTable2DAbscissaUmax(threadData_t *threadData, modelica_complex _tableID)
{
  void * _tableID_ext;
  void *_uMax_c89;
  real_array _uMax;
  alloc_real_array(&(_uMax), 1, (_index_t)2); // _uMax has no default value.
  _tableID_ext = (void *)_tableID;
  _uMax_c89 = (void*) data_of_real_c89_array(&(_uMax));
  ModelicaStandardTables_CombiTable2D_maximumAbscissa(_tableID_ext, (double*) _uMax_c89);
  return _uMax;
}
modelica_metatype boxptr_Modelica_Blocks_Tables_Internal_getTable2DAbscissaUmax(threadData_t *threadData, modelica_metatype _tableID)
{
  real_array _uMax;
  modelica_metatype out_uMax;
  _uMax = omc_Modelica_Blocks_Tables_Internal_getTable2DAbscissaUmax(threadData, _tableID);
  out_uMax = mmc_mk_modelica_array(_uMax);
  return out_uMax;
}

real_array omc_Modelica_Blocks_Tables_Internal_getTable2DAbscissaUmin(threadData_t *threadData, modelica_complex _tableID)
{
  void * _tableID_ext;
  void *_uMin_c89;
  real_array _uMin;
  alloc_real_array(&(_uMin), 1, (_index_t)2); // _uMin has no default value.
  _tableID_ext = (void *)_tableID;
  _uMin_c89 = (void*) data_of_real_c89_array(&(_uMin));
  ModelicaStandardTables_CombiTable2D_minimumAbscissa(_tableID_ext, (double*) _uMin_c89);
  return _uMin;
}
modelica_metatype boxptr_Modelica_Blocks_Tables_Internal_getTable2DAbscissaUmin(threadData_t *threadData, modelica_metatype _tableID)
{
  real_array _uMin;
  modelica_metatype out_uMin;
  _uMin = omc_Modelica_Blocks_Tables_Internal_getTable2DAbscissaUmin(threadData, _tableID);
  out_uMin = mmc_mk_modelica_array(_uMin);
  return out_uMin;
}

modelica_real omc_Modelica_Blocks_Tables_Internal_getTable2DValue(threadData_t *threadData, modelica_complex _tableID, modelica_real _u1, modelica_real _u2)
{
  void * _tableID_ext;
  double _u1_ext;
  double _u2_ext;
  double _y_ext;
  modelica_real _y;
  // _y has no default value.
  _tableID_ext = (void *)_tableID;

  _u1_ext = (double)_u1;

  _u2_ext = (double)_u2;
  _y_ext = ModelicaStandardTables_CombiTable2D_getValue(_tableID_ext, _u1_ext, _u2_ext);
  _y = (modelica_real)_y_ext;
  return _y;
}
modelica_metatype boxptr_Modelica_Blocks_Tables_Internal_getTable2DValue(threadData_t *threadData, modelica_metatype _tableID, modelica_metatype _u1, modelica_metatype _u2)
{
  modelica_real tmp1;
  modelica_real tmp2;
  modelica_real _y;
  modelica_metatype out_y;
  tmp1 = mmc_unbox_real(_u1);
  tmp2 = mmc_unbox_real(_u2);
  _y = omc_Modelica_Blocks_Tables_Internal_getTable2DValue(threadData, _tableID, tmp1, tmp2);
  out_y = mmc_mk_rcon(_y);
  return out_y;
}

modelica_real omc_Modelica_Blocks_Tables_Internal_getTimeTableTmax(threadData_t *threadData, modelica_complex _tableID)
{
  void * _tableID_ext;
  double _timeMax_ext;
  modelica_real _timeMax;
  // _timeMax has no default value.
  _tableID_ext = (void *)_tableID;
  _timeMax_ext = ModelicaStandardTables_CombiTimeTable_maximumTime(_tableID_ext);
  _timeMax = (modelica_real)_timeMax_ext;
  return _timeMax;
}
modelica_metatype boxptr_Modelica_Blocks_Tables_Internal_getTimeTableTmax(threadData_t *threadData, modelica_metatype _tableID)
{
  modelica_real _timeMax;
  modelica_metatype out_timeMax;
  _timeMax = omc_Modelica_Blocks_Tables_Internal_getTimeTableTmax(threadData, _tableID);
  out_timeMax = mmc_mk_rcon(_timeMax);
  return out_timeMax;
}

modelica_real omc_Modelica_Blocks_Tables_Internal_getTimeTableTmin(threadData_t *threadData, modelica_complex _tableID)
{
  void * _tableID_ext;
  double _timeMin_ext;
  modelica_real _timeMin;
  // _timeMin has no default value.
  _tableID_ext = (void *)_tableID;
  _timeMin_ext = ModelicaStandardTables_CombiTimeTable_minimumTime(_tableID_ext);
  _timeMin = (modelica_real)_timeMin_ext;
  return _timeMin;
}
modelica_metatype boxptr_Modelica_Blocks_Tables_Internal_getTimeTableTmin(threadData_t *threadData, modelica_metatype _tableID)
{
  modelica_real _timeMin;
  modelica_metatype out_timeMin;
  _timeMin = omc_Modelica_Blocks_Tables_Internal_getTimeTableTmin(threadData, _tableID);
  out_timeMin = mmc_mk_rcon(_timeMin);
  return out_timeMin;
}

modelica_real omc_Modelica_Blocks_Tables_Internal_getTimeTableValue(threadData_t *threadData, modelica_complex _tableID, modelica_integer _icol, modelica_real _timeIn, modelica_real _nextTimeEvent, modelica_real _pre_nextTimeEvent)
{
  void * _tableID_ext;
  int _icol_ext;
  double _timeIn_ext;
  double _nextTimeEvent_ext;
  double _pre_nextTimeEvent_ext;
  double _y_ext;
  modelica_real _y;
  // _y has no default value.
  _tableID_ext = (void *)_tableID;

  _icol_ext = (int)_icol;

  _timeIn_ext = (double)_timeIn;

  _nextTimeEvent_ext = (double)_nextTimeEvent;

  _pre_nextTimeEvent_ext = (double)_pre_nextTimeEvent;
  _y_ext = ModelicaStandardTables_CombiTimeTable_getValue(_tableID_ext, _icol_ext, _timeIn_ext, _nextTimeEvent_ext, _pre_nextTimeEvent_ext);
  _y = (modelica_real)_y_ext;
  return _y;
}
modelica_metatype boxptr_Modelica_Blocks_Tables_Internal_getTimeTableValue(threadData_t *threadData, modelica_metatype _tableID, modelica_metatype _icol, modelica_metatype _timeIn, modelica_metatype _nextTimeEvent, modelica_metatype _pre_nextTimeEvent)
{
  modelica_integer tmp1;
  modelica_real tmp2;
  modelica_real tmp3;
  modelica_real tmp4;
  modelica_real _y;
  modelica_metatype out_y;
  tmp1 = mmc_unbox_integer(_icol);
  tmp2 = mmc_unbox_real(_timeIn);
  tmp3 = mmc_unbox_real(_nextTimeEvent);
  tmp4 = mmc_unbox_real(_pre_nextTimeEvent);
  _y = omc_Modelica_Blocks_Tables_Internal_getTimeTableValue(threadData, _tableID, tmp1, tmp2, tmp3, tmp4);
  out_y = mmc_mk_rcon(_y);
  return out_y;
}

modelica_real omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData_t *threadData, modelica_complex _tableID, modelica_integer _icol, modelica_real _timeIn, modelica_real _nextTimeEvent, modelica_real _pre_nextTimeEvent)
{
  void * _tableID_ext;
  int _icol_ext;
  double _timeIn_ext;
  double _nextTimeEvent_ext;
  double _pre_nextTimeEvent_ext;
  double _y_ext;
  modelica_real _y;
  // _y has no default value.
  _tableID_ext = (void *)_tableID;

  _icol_ext = (int)_icol;

  _timeIn_ext = (double)_timeIn;

  _nextTimeEvent_ext = (double)_nextTimeEvent;

  _pre_nextTimeEvent_ext = (double)_pre_nextTimeEvent;
  _y_ext = ModelicaStandardTables_CombiTimeTable_getValue(_tableID_ext, _icol_ext, _timeIn_ext, _nextTimeEvent_ext, _pre_nextTimeEvent_ext);
  _y = (modelica_real)_y_ext;
  return _y;
}
modelica_metatype boxptr_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData_t *threadData, modelica_metatype _tableID, modelica_metatype _icol, modelica_metatype _timeIn, modelica_metatype _nextTimeEvent, modelica_metatype _pre_nextTimeEvent)
{
  modelica_integer tmp1;
  modelica_real tmp2;
  modelica_real tmp3;
  modelica_real tmp4;
  modelica_real _y;
  modelica_metatype out_y;
  tmp1 = mmc_unbox_integer(_icol);
  tmp2 = mmc_unbox_real(_timeIn);
  tmp3 = mmc_unbox_real(_nextTimeEvent);
  tmp4 = mmc_unbox_real(_pre_nextTimeEvent);
  _y = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, _tableID, tmp1, tmp2, tmp3, tmp4);
  out_y = mmc_mk_rcon(_y);
  return out_y;
}

modelica_complex omc_Modelica_Blocks_Types_ExternalCombiTable1D_constructor(threadData_t *threadData, modelica_string _tableName, modelica_string _fileName, real_array _table, integer_array _columns, modelica_integer _smoothness, modelica_integer _extrapolation, modelica_boolean _verboseRead)
{
  integer_array _columns_packed;
  int _smoothness_ext;
  int _extrapolation_ext;
  int _verboseRead_ext;
  void *_table_c89;
  void *_columns_c89;
  void * _externalCombiTable1D_ext;
  modelica_complex _externalCombiTable1D;
  // _externalCombiTable1D has no default value.
  pack_alloc_integer_array(&_columns, &_columns_packed);

  _smoothness_ext = (int)_smoothness;

  _extrapolation_ext = (int)_extrapolation;

  _verboseRead_ext = (int)_verboseRead;
  _table_c89 = (void*) data_of_real_c89_array(&(_table));
  _columns_c89 = (void*) data_of_integer_c89_array(&(_columns_packed));
  _externalCombiTable1D_ext = ModelicaStandardTables_CombiTable1D_init2(MMC_STRINGDATA(_fileName), MMC_STRINGDATA(_tableName), (const double*) _table_c89, size_of_dimension_base_array(_table, ((modelica_integer) 1)), size_of_dimension_base_array(_table, ((modelica_integer) 2)), (const int*) _columns_c89, size_of_dimension_base_array(_columns, ((modelica_integer) 1)), _smoothness_ext, _extrapolation_ext, _verboseRead_ext);
  _externalCombiTable1D = (modelica_complex)_externalCombiTable1D_ext;
  return _externalCombiTable1D;
}
modelica_metatype boxptr_Modelica_Blocks_Types_ExternalCombiTable1D_constructor(threadData_t *threadData, modelica_metatype _tableName, modelica_metatype _fileName, modelica_metatype _table, modelica_metatype _columns, modelica_metatype _smoothness, modelica_metatype _extrapolation, modelica_metatype _verboseRead)
{
  modelica_integer tmp1;
  modelica_integer tmp2;
  modelica_integer tmp3;
  modelica_complex _externalCombiTable1D;
  tmp1 = mmc_unbox_integer(_smoothness);
  tmp2 = mmc_unbox_integer(_extrapolation);
  tmp3 = mmc_unbox_integer(_verboseRead);
  _externalCombiTable1D = omc_Modelica_Blocks_Types_ExternalCombiTable1D_constructor(threadData, _tableName, _fileName, *((base_array_t*)_table), *((base_array_t*)_columns), tmp1, tmp2, tmp3);
  /* skip box _externalCombiTable1D; ExternalObject Modelica.Blocks.Types.ExternalCombiTable1D */
  return _externalCombiTable1D;
}

void omc_Modelica_Blocks_Types_ExternalCombiTable1D_destructor(threadData_t *threadData, modelica_complex _externalCombiTable1D)
{
  void * _externalCombiTable1D_ext;
  _externalCombiTable1D_ext = (void *)_externalCombiTable1D;
  ModelicaStandardTables_CombiTable1D_close(_externalCombiTable1D_ext);
  return;
}
void boxptr_Modelica_Blocks_Types_ExternalCombiTable1D_destructor(threadData_t *threadData, modelica_metatype _externalCombiTable1D)
{
  omc_Modelica_Blocks_Types_ExternalCombiTable1D_destructor(threadData, _externalCombiTable1D);
  return;
}

modelica_complex omc_Modelica_Blocks_Types_ExternalCombiTable2D_constructor(threadData_t *threadData, modelica_string _tableName, modelica_string _fileName, real_array _table, modelica_integer _smoothness, modelica_integer _extrapolation, modelica_boolean _verboseRead)
{
  int _smoothness_ext;
  int _extrapolation_ext;
  int _verboseRead_ext;
  void *_table_c89;
  void * _externalCombiTable2D_ext;
  modelica_complex _externalCombiTable2D;
  // _externalCombiTable2D has no default value.
  _smoothness_ext = (int)_smoothness;

  _extrapolation_ext = (int)_extrapolation;

  _verboseRead_ext = (int)_verboseRead;
  _table_c89 = (void*) data_of_real_c89_array(&(_table));
  _externalCombiTable2D_ext = ModelicaStandardTables_CombiTable2D_init2(MMC_STRINGDATA(_fileName), MMC_STRINGDATA(_tableName), (const double*) _table_c89, size_of_dimension_base_array(_table, ((modelica_integer) 1)), size_of_dimension_base_array(_table, ((modelica_integer) 2)), _smoothness_ext, _extrapolation_ext, _verboseRead_ext);
  _externalCombiTable2D = (modelica_complex)_externalCombiTable2D_ext;
  return _externalCombiTable2D;
}
modelica_metatype boxptr_Modelica_Blocks_Types_ExternalCombiTable2D_constructor(threadData_t *threadData, modelica_metatype _tableName, modelica_metatype _fileName, modelica_metatype _table, modelica_metatype _smoothness, modelica_metatype _extrapolation, modelica_metatype _verboseRead)
{
  modelica_integer tmp1;
  modelica_integer tmp2;
  modelica_integer tmp3;
  modelica_complex _externalCombiTable2D;
  tmp1 = mmc_unbox_integer(_smoothness);
  tmp2 = mmc_unbox_integer(_extrapolation);
  tmp3 = mmc_unbox_integer(_verboseRead);
  _externalCombiTable2D = omc_Modelica_Blocks_Types_ExternalCombiTable2D_constructor(threadData, _tableName, _fileName, *((base_array_t*)_table), tmp1, tmp2, tmp3);
  /* skip box _externalCombiTable2D; ExternalObject Modelica.Blocks.Types.ExternalCombiTable2D */
  return _externalCombiTable2D;
}

void omc_Modelica_Blocks_Types_ExternalCombiTable2D_destructor(threadData_t *threadData, modelica_complex _externalCombiTable2D)
{
  void * _externalCombiTable2D_ext;
  _externalCombiTable2D_ext = (void *)_externalCombiTable2D;
  ModelicaStandardTables_CombiTable2D_close(_externalCombiTable2D_ext);
  return;
}
void boxptr_Modelica_Blocks_Types_ExternalCombiTable2D_destructor(threadData_t *threadData, modelica_metatype _externalCombiTable2D)
{
  omc_Modelica_Blocks_Types_ExternalCombiTable2D_destructor(threadData, _externalCombiTable2D);
  return;
}

modelica_complex omc_Modelica_Blocks_Types_ExternalCombiTimeTable_constructor(threadData_t *threadData, modelica_string _tableName, modelica_string _fileName, real_array _table, modelica_real _startTime, integer_array _columns, modelica_integer _smoothness, modelica_integer _extrapolation, modelica_real _shiftTime, modelica_integer _timeEvents, modelica_boolean _verboseRead)
{
  double _startTime_ext;
  integer_array _columns_packed;
  int _smoothness_ext;
  int _extrapolation_ext;
  double _shiftTime_ext;
  int _timeEvents_ext;
  int _verboseRead_ext;
  void *_table_c89;
  void *_columns_c89;
  void * _externalCombiTimeTable_ext;
  modelica_complex _externalCombiTimeTable;
  // _externalCombiTimeTable has no default value.
  _startTime_ext = (double)_startTime;

  pack_alloc_integer_array(&_columns, &_columns_packed);

  _smoothness_ext = (int)_smoothness;

  _extrapolation_ext = (int)_extrapolation;

  _shiftTime_ext = (double)_shiftTime;

  _timeEvents_ext = (int)_timeEvents;

  _verboseRead_ext = (int)_verboseRead;
  _table_c89 = (void*) data_of_real_c89_array(&(_table));
  _columns_c89 = (void*) data_of_integer_c89_array(&(_columns_packed));
  _externalCombiTimeTable_ext = ModelicaStandardTables_CombiTimeTable_init2(MMC_STRINGDATA(_fileName), MMC_STRINGDATA(_tableName), (const double*) _table_c89, size_of_dimension_base_array(_table, ((modelica_integer) 1)), size_of_dimension_base_array(_table, ((modelica_integer) 2)), _startTime_ext, (const int*) _columns_c89, size_of_dimension_base_array(_columns, ((modelica_integer) 1)), _smoothness_ext, _extrapolation_ext, _shiftTime_ext, _timeEvents_ext, _verboseRead_ext);
  _externalCombiTimeTable = (modelica_complex)_externalCombiTimeTable_ext;
  return _externalCombiTimeTable;
}
modelica_metatype boxptr_Modelica_Blocks_Types_ExternalCombiTimeTable_constructor(threadData_t *threadData, modelica_metatype _tableName, modelica_metatype _fileName, modelica_metatype _table, modelica_metatype _startTime, modelica_metatype _columns, modelica_metatype _smoothness, modelica_metatype _extrapolation, modelica_metatype _shiftTime, modelica_metatype _timeEvents, modelica_metatype _verboseRead)
{
  modelica_real tmp1;
  modelica_integer tmp2;
  modelica_integer tmp3;
  modelica_real tmp4;
  modelica_integer tmp5;
  modelica_integer tmp6;
  modelica_complex _externalCombiTimeTable;
  tmp1 = mmc_unbox_real(_startTime);
  tmp2 = mmc_unbox_integer(_smoothness);
  tmp3 = mmc_unbox_integer(_extrapolation);
  tmp4 = mmc_unbox_real(_shiftTime);
  tmp5 = mmc_unbox_integer(_timeEvents);
  tmp6 = mmc_unbox_integer(_verboseRead);
  _externalCombiTimeTable = omc_Modelica_Blocks_Types_ExternalCombiTimeTable_constructor(threadData, _tableName, _fileName, *((base_array_t*)_table), tmp1, *((base_array_t*)_columns), tmp2, tmp3, tmp4, tmp5, tmp6);
  /* skip box _externalCombiTimeTable; ExternalObject Modelica.Blocks.Types.ExternalCombiTimeTable */
  return _externalCombiTimeTable;
}

void omc_Modelica_Blocks_Types_ExternalCombiTimeTable_destructor(threadData_t *threadData, modelica_complex _externalCombiTimeTable)
{
  void * _externalCombiTimeTable_ext;
  _externalCombiTimeTable_ext = (void *)_externalCombiTimeTable;
  ModelicaStandardTables_CombiTimeTable_close(_externalCombiTimeTable_ext);
  return;
}
void boxptr_Modelica_Blocks_Types_ExternalCombiTimeTable_destructor(threadData_t *threadData, modelica_metatype _externalCombiTimeTable)
{
  omc_Modelica_Blocks_Types_ExternalCombiTimeTable_destructor(threadData, _externalCombiTimeTable);
  return;
}

DLLExport
modelica_real omc_Modelica_Media_Water_IF97__Utilities_BaseIF97_Basic_tsat(threadData_t *threadData, modelica_real _p)
{
  modelica_real _t_sat;
  modelica_real _pi;
  real_array _o;
  modelica_string tmp1;
  modelica_string tmp2;
  static int tmp3 = 0;
  modelica_real tmp4;
  modelica_real tmp5;
  modelica_real tmp6;
  modelica_real tmp7;
  modelica_real tmp8;
  modelica_real tmp9;
  modelica_real tmp10;
  modelica_real tmp11;
  modelica_real tmp12;
  modelica_real tmp13;
  modelica_real tmp14;
  modelica_real tmp15;
  modelica_real tmp16;
  modelica_metatype tmpMeta[4] __attribute__((unused)) = {0};
  _tailrecursive: OMC_LABEL_UNUSED
  // _t_sat has no default value.
  // _pi has no default value.
  alloc_real_array(&(_o), 1, (_index_t)20); // _o has no default value.
  {
    if(!(_p > 611.657))
    {
      tmp1 = modelica_real_to_modelica_string(_p, ((modelica_integer) 6), ((modelica_integer) 0), 1);
      tmpMeta[0] = stringAppend(_OMC_LIT12,tmp1);
      tmpMeta[1] = stringAppend(tmpMeta[0],_OMC_LIT13);
      tmp2 = modelica_real_to_modelica_string(611.657, ((modelica_integer) 6), ((modelica_integer) 0), 1);
      tmpMeta[2] = stringAppend(tmpMeta[1],tmp2);
      tmpMeta[3] = stringAppend(tmpMeta[2],_OMC_LIT14);
      {
        FILE_INFO info = {"/usr/lib/omlibrary/Modelica 3.2.3/Media/Water/IF97_Utilities.mo",2897,9,2900,41,1};
        omc_assert(threadData, info, MMC_STRINGDATA(tmpMeta[3]));
      }
    }
  }

  _pi = (1e-06) * (fmin(_p,22064000.0));

  tmp4 = _pi;
  tmp5 = 0.25;
  if(tmp4 < 0.0 && tmp5 != 0.0)
  {
    tmp7 = modf(tmp5, &tmp8);
    
    if(tmp7 > 0.5)
    {
      tmp7 -= 1.0;
      tmp8 += 1.0;
    }
    else if(tmp7 < -0.5)
    {
      tmp7 += 1.0;
      tmp8 -= 1.0;
    }
    
    if(fabs(tmp7) < 1e-10)
      tmp6 = pow(tmp4, tmp8);
    else
    {
      tmp10 = modf(1.0/tmp5, &tmp9);
      if(tmp10 > 0.5)
      {
        tmp10 -= 1.0;
        tmp9 += 1.0;
      }
      else if(tmp10 < -0.5)
      {
        tmp10 += 1.0;
        tmp9 -= 1.0;
      }
      if(fabs(tmp10) < 1e-10 && ((unsigned long)tmp9 & 1))
      {
        tmp6 = -pow(-tmp4, tmp7)*pow(tmp4, tmp8);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp4, tmp5);
      }
    }
  }
  else
  {
    tmp6 = pow(tmp4, tmp5);
  }
  if(isnan(tmp6) || isinf(tmp6))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp4, tmp5);
  }
  real_array_get(_o, 1, ((modelica_integer) 1)) = tmp6;

  real_array_get(_o, 1, ((modelica_integer) 2)) = (-3232555.0322333) * (real_array_get1(_o, 1, ((modelica_integer) 1)));

  tmp11 = _pi;
  if(!(tmp11 >= 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert(threadData, info, "Model error: Argument of sqrt(pi) was %g should be >= 0", tmp11);
  }
  real_array_get(_o, 1, ((modelica_integer) 3)) = sqrt(tmp11);

  real_array_get(_o, 1, ((modelica_integer) 4)) = (-724213.16703206) * (real_array_get1(_o, 1, ((modelica_integer) 3)));

  real_array_get(_o, 1, ((modelica_integer) 5)) = 405113.40542057 + real_array_get1(_o, 1, ((modelica_integer) 2)) + real_array_get1(_o, 1, ((modelica_integer) 4));

  real_array_get(_o, 1, ((modelica_integer) 6)) = (-17.073846940092) * (real_array_get1(_o, 1, ((modelica_integer) 1)));

  real_array_get(_o, 1, ((modelica_integer) 7)) = 14.91510861353 + real_array_get1(_o, 1, ((modelica_integer) 3)) + real_array_get1(_o, 1, ((modelica_integer) 6));

  real_array_get(_o, 1, ((modelica_integer) 8)) = (-4.0) * ((real_array_get1(_o, 1, ((modelica_integer) 5))) * (real_array_get1(_o, 1, ((modelica_integer) 7))));

  real_array_get(_o, 1, ((modelica_integer) 9)) = (12020.82470247) * (real_array_get1(_o, 1, ((modelica_integer) 1)));

  real_array_get(_o, 1, ((modelica_integer) 10)) = (1167.0521452767) * (real_array_get1(_o, 1, ((modelica_integer) 3)));

  real_array_get(_o, 1, ((modelica_integer) 11)) = -4823.2657361591 + real_array_get1(_o, 1, ((modelica_integer) 10)) + real_array_get1(_o, 1, ((modelica_integer) 9));

  tmp12 = real_array_get1(_o, 1, ((modelica_integer) 11));
  real_array_get(_o, 1, ((modelica_integer) 12)) = (tmp12 * tmp12);

  real_array_get(_o, 1, ((modelica_integer) 13)) = real_array_get1(_o, 1, ((modelica_integer) 12)) + real_array_get1(_o, 1, ((modelica_integer) 8));

  tmp13 = real_array_get1(_o, 1, ((modelica_integer) 13));
  if(!(tmp13 >= 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert(threadData, info, "Model error: Argument of sqrt(o[13]) was %g should be >= 0", tmp13);
  }
  real_array_get(_o, 1, ((modelica_integer) 14)) = sqrt(tmp13);

  real_array_get(_o, 1, ((modelica_integer) 15)) = (-real_array_get1(_o, 1, ((modelica_integer) 14)));

  real_array_get(_o, 1, ((modelica_integer) 16)) = (-12020.82470247) * (real_array_get1(_o, 1, ((modelica_integer) 1)));

  real_array_get(_o, 1, ((modelica_integer) 17)) = (-1167.0521452767) * (real_array_get1(_o, 1, ((modelica_integer) 3)));

  real_array_get(_o, 1, ((modelica_integer) 18)) = 4823.2657361591 + real_array_get1(_o, 1, ((modelica_integer) 15)) + real_array_get1(_o, 1, ((modelica_integer) 16)) + real_array_get1(_o, 1, ((modelica_integer) 17));

  tmp14 = real_array_get1(_o, 1, ((modelica_integer) 18));
  if (tmp14 == 0) {throwStreamPrint(threadData, "Division by zero %s", "1.0 / o[18]");}
  real_array_get(_o, 1, ((modelica_integer) 19)) = (1.0) / tmp14;

  real_array_get(_o, 1, ((modelica_integer) 20)) = (2.0) * ((real_array_get1(_o, 1, ((modelica_integer) 19))) * (real_array_get1(_o, 1, ((modelica_integer) 5))));

  tmp15 = 650.17534844798 + real_array_get1(_o, 1, ((modelica_integer) 20));
  tmp16 = (tmp15 * tmp15) + (-4.0) * (-0.23855557567849 + (1300.35069689596) * ((real_array_get1(_o, 1, ((modelica_integer) 19))) * (real_array_get1(_o, 1, ((modelica_integer) 5)))));
  if(!(tmp16 >= 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert(threadData, info, "Model error: Argument of sqrt((650.17534844798 + o[20]) ^ 2.0 + (-4.0) * (-0.23855557567849 + 1300.35069689596 * o[19] * o[5])) was %g should be >= 0", tmp16);
  }
  _t_sat = (0.5) * (650.17534844798 + real_array_get1(_o, 1, ((modelica_integer) 20)) - (sqrt(tmp16)));
  _return: OMC_LABEL_UNUSED
  return _t_sat;
}
modelica_metatype boxptr_Modelica_Media_Water_IF97__Utilities_BaseIF97_Basic_tsat(threadData_t *threadData, modelica_metatype _p)
{
  modelica_real tmp1;
  modelica_real _t_sat;
  modelica_metatype out_t_sat;
  tmp1 = mmc_unbox_real(_p);
  _t_sat = omc_Modelica_Media_Water_IF97__Utilities_BaseIF97_Basic_tsat(threadData, tmp1);
  out_t_sat = mmc_mk_rcon(_t_sat);
  return out_t_sat;
}

DLLExport
modelica_real omc_Modelica_SIunits_Conversions_from__deg(threadData_t *threadData, modelica_real _degree)
{
  modelica_real _radian;
  _tailrecursive: OMC_LABEL_UNUSED
  // _radian has no default value.
  _radian = (0.0174532925199433) * (_degree);
  _return: OMC_LABEL_UNUSED
  return _radian;
}
modelica_metatype boxptr_Modelica_SIunits_Conversions_from__deg(threadData_t *threadData, modelica_metatype _degree)
{
  modelica_real tmp1;
  modelica_real _radian;
  modelica_metatype out_radian;
  tmp1 = mmc_unbox_real(_degree);
  _radian = omc_Modelica_SIunits_Conversions_from__deg(threadData, tmp1);
  out_radian = mmc_mk_rcon(_radian);
  return out_radian;
}

DLLExport
modelica_real omc_Modelica_SIunits_Conversions_to__degC(threadData_t *threadData, modelica_real _Kelvin)
{
  modelica_real _Celsius;
  _tailrecursive: OMC_LABEL_UNUSED
  // _Celsius has no default value.
  _Celsius = -273.15 + _Kelvin;
  _return: OMC_LABEL_UNUSED
  return _Celsius;
}
modelica_metatype boxptr_Modelica_SIunits_Conversions_to__degC(threadData_t *threadData, modelica_metatype _Kelvin)
{
  modelica_real tmp1;
  modelica_real _Celsius;
  modelica_metatype out_Celsius;
  tmp1 = mmc_unbox_real(_Kelvin);
  _Celsius = omc_Modelica_SIunits_Conversions_to__degC(threadData, tmp1);
  out_Celsius = mmc_mk_rcon(_Celsius);
  return out_Celsius;
}

DLLExport
modelica_string omc_Modelica_Utilities_Files_splitPathName(threadData_t *threadData, modelica_string _pathName, modelica_string *out_name, modelica_string *out_extension)
{
  modelica_string _directory = NULL;
  modelica_string _name = NULL;
  modelica_string _extension = NULL;
  modelica_integer _indexDot;
  modelica_integer _indexSlash;
  modelica_string _c = NULL;
  modelica_integer _lenPath;
  modelica_integer _i;
  _tailrecursive: OMC_LABEL_UNUSED
  // _directory has no default value.
  // _name has no default value.
  // _extension has no default value.
  _indexDot = ((modelica_integer) 0);
  _indexSlash = ((modelica_integer) 0);
  // _c has no default value.
  _lenPath = omc_Modelica_Utilities_Strings_length(threadData, _pathName);
  _i = _lenPath;
  while(1)
  {
    if(!(_i >= ((modelica_integer) 1))) break;
    _c = omc_Modelica_Utilities_Strings_substring(threadData, _pathName, _i, _i);

    if((stringEqual(_c, _OMC_LIT19)))
    {
      _indexDot = _i;

      _i = ((modelica_integer) 0);
    }
    else
    {
      if((stringEqual(_c, _OMC_LIT18)))
      {
        _indexSlash = _i;

        _i = ((modelica_integer) 0);
      }
      else
      {
        _i = ((modelica_integer) -1) + _i;
      }
    }
  }

  if((_indexSlash == _lenPath))
  {
    _directory = _pathName;

    _name = _OMC_LIT20;

    _extension = _OMC_LIT20;
  }
  else
  {
    if((_indexDot > ((modelica_integer) 0)))
    {
      _indexSlash = omc_Modelica_Utilities_Strings_findLast(threadData, _pathName, _OMC_LIT18, ((modelica_integer) -1) + _indexDot, 1);

      if((_indexSlash == ((modelica_integer) 0)))
      {
        _directory = _OMC_LIT20;

        _name = omc_Modelica_Utilities_Strings_substring(threadData, _pathName, ((modelica_integer) 1), ((modelica_integer) -1) + _indexDot);
      }
      else
      {
        _directory = omc_Modelica_Utilities_Strings_substring(threadData, _pathName, ((modelica_integer) 1), _indexSlash);

        _name = omc_Modelica_Utilities_Strings_substring(threadData, _pathName, ((modelica_integer) 1) + _indexSlash, ((modelica_integer) -1) + _indexDot);
      }

      _extension = omc_Modelica_Utilities_Strings_substring(threadData, _pathName, _indexDot, _lenPath);
    }
    else
    {
      _extension = _OMC_LIT20;

      if((_indexSlash > ((modelica_integer) 0)))
      {
        _directory = omc_Modelica_Utilities_Strings_substring(threadData, _pathName, ((modelica_integer) 1), _indexSlash);

        _name = omc_Modelica_Utilities_Strings_substring(threadData, _pathName, ((modelica_integer) 1) + _indexSlash, _lenPath);
      }
      else
      {
        _directory = _OMC_LIT20;

        _name = _pathName;
      }
    }
  }
  _return: OMC_LABEL_UNUSED
  if (out_name) { *out_name = _name; }
  if (out_extension) { *out_extension = _extension; }
  return _directory;
}

void omc_Modelica_Utilities_Streams_close(threadData_t *threadData, modelica_string _fileName)
{
  ModelicaStreams_closeFile(MMC_STRINGDATA(_fileName));
  return;
}

void omc_Modelica_Utilities_Streams_error(threadData_t *threadData, modelica_string _string)
{
  ModelicaError(MMC_STRINGDATA(_string));
  return;
}

modelica_string omc_Modelica_Utilities_Streams_readLine(threadData_t *threadData, modelica_string _fileName, modelica_integer _lineNumber, modelica_boolean *out_endOfFile)
{
  int _lineNumber_ext;
  int _endOfFile_ext;
  const char* _string_ext;
  modelica_string _string = NULL;
  modelica_boolean _endOfFile;
  // _string has no default value.
  // _endOfFile has no default value.
  _lineNumber_ext = (int)_lineNumber;
  _string_ext = ModelicaInternal_readLine(MMC_STRINGDATA(_fileName), _lineNumber_ext, &_endOfFile_ext);
  _endOfFile = (modelica_boolean)_endOfFile_ext;
  _string = (modelica_string)mmc_mk_scon(_string_ext);
  if (out_endOfFile) { *out_endOfFile = _endOfFile; }
  return _string;
}
modelica_metatype boxptr_Modelica_Utilities_Streams_readLine(threadData_t *threadData, modelica_metatype _fileName, modelica_metatype _lineNumber, modelica_metatype *out_endOfFile)
{
  modelica_integer tmp1;
  modelica_boolean _endOfFile;
  modelica_string _string = NULL;
  tmp1 = mmc_unbox_integer(_lineNumber);
  _string = omc_Modelica_Utilities_Streams_readLine(threadData, _fileName, tmp1, &_endOfFile);
  /* skip box _string; String */
  if (out_endOfFile) { *out_endOfFile = mmc_mk_icon(_endOfFile); }
  return _string;
}

modelica_integer omc_Modelica_Utilities_Strings_compare(threadData_t *threadData, modelica_string _string1, modelica_string _string2, modelica_boolean _caseSensitive)
{
  int _caseSensitive_ext;
  int _result_ext;
  modelica_integer _result;
  // _result has no default value.
  _caseSensitive_ext = (int)_caseSensitive;
  _result_ext = ModelicaStrings_compare(MMC_STRINGDATA(_string1), MMC_STRINGDATA(_string2), _caseSensitive_ext);
  _result = (modelica_integer)_result_ext;
  return _result;
}
modelica_metatype boxptr_Modelica_Utilities_Strings_compare(threadData_t *threadData, modelica_metatype _string1, modelica_metatype _string2, modelica_metatype _caseSensitive)
{
  modelica_integer tmp1;
  modelica_integer _result;
  modelica_metatype out_result;
  tmp1 = mmc_unbox_integer(_caseSensitive);
  _result = omc_Modelica_Utilities_Strings_compare(threadData, _string1, _string2, tmp1);
  out_result = mmc_mk_icon(_result);
  return out_result;
}

DLLExport
modelica_integer omc_Modelica_Utilities_Strings_find(threadData_t *threadData, modelica_string _string, modelica_string _searchString, modelica_integer _startIndex, modelica_boolean _caseSensitive)
{
  modelica_integer _index;
  modelica_integer _lengthSearchString;
  modelica_integer _i;
  modelica_integer _len;
  modelica_integer _i_max;
  _tailrecursive: OMC_LABEL_UNUSED
  // _index has no default value.
  _lengthSearchString = omc_Modelica_Utilities_Strings_length(threadData, _searchString);
  _i = _startIndex;
  _len = ((modelica_integer) -1) + _lengthSearchString;
  _i_max = ((modelica_integer) 1) + omc_Modelica_Utilities_Strings_length(threadData, _string) - _lengthSearchString;
  _index = ((modelica_integer) 0);

  while(1)
  {
    if(!(_i <= _i_max)) break;
    if(omc_Modelica_Utilities_Strings_isEqual(threadData, omc_Modelica_Utilities_Strings_substring(threadData, _string, _i, _i + _len), _searchString, _caseSensitive))
    {
      _index = _i;

      _i = ((modelica_integer) 1) + _i_max;
    }
    else
    {
      _i = ((modelica_integer) 1) + _i;
    }
  }
  _return: OMC_LABEL_UNUSED
  return _index;
}
modelica_metatype boxptr_Modelica_Utilities_Strings_find(threadData_t *threadData, modelica_metatype _string, modelica_metatype _searchString, modelica_metatype _startIndex, modelica_metatype _caseSensitive)
{
  modelica_integer tmp1;
  modelica_integer tmp2;
  modelica_integer _index;
  modelica_metatype out_index;
  tmp1 = mmc_unbox_integer(_startIndex);
  tmp2 = mmc_unbox_integer(_caseSensitive);
  _index = omc_Modelica_Utilities_Strings_find(threadData, _string, _searchString, tmp1, tmp2);
  out_index = mmc_mk_icon(_index);
  return out_index;
}

DLLExport
modelica_integer omc_Modelica_Utilities_Strings_findLast(threadData_t *threadData, modelica_string _string, modelica_string _searchString, modelica_integer _startIndex, modelica_boolean _caseSensitive)
{
  modelica_integer _index;
  modelica_integer _i;
  modelica_integer _lenString;
  modelica_integer _lenSearchString;
  modelica_integer _iMax;
  _tailrecursive: OMC_LABEL_UNUSED
  // _index has no default value.
  // _i has no default value.
  _lenString = omc_Modelica_Utilities_Strings_length(threadData, _string);
  _lenSearchString = omc_Modelica_Utilities_Strings_length(threadData, _searchString);
  _iMax = ((modelica_integer) 1) + _lenString - _lenSearchString;
  _i = (((_startIndex == ((modelica_integer) 0)) || (_startIndex > _iMax))?_iMax:_startIndex);

  _index = ((modelica_integer) 0);

  while(1)
  {
    if(!(_i >= ((modelica_integer) 1))) break;
    if(omc_Modelica_Utilities_Strings_isEqual(threadData, omc_Modelica_Utilities_Strings_substring(threadData, _string, _i, ((modelica_integer) -1) + _i + _lenSearchString), _searchString, _caseSensitive))
    {
      _index = _i;

      _i = ((modelica_integer) 0);
    }
    else
    {
      _i = ((modelica_integer) -1) + _i;
    }
  }
  _return: OMC_LABEL_UNUSED
  return _index;
}
modelica_metatype boxptr_Modelica_Utilities_Strings_findLast(threadData_t *threadData, modelica_metatype _string, modelica_metatype _searchString, modelica_metatype _startIndex, modelica_metatype _caseSensitive)
{
  modelica_integer tmp1;
  modelica_integer tmp2;
  modelica_integer _index;
  modelica_metatype out_index;
  tmp1 = mmc_unbox_integer(_startIndex);
  tmp2 = mmc_unbox_integer(_caseSensitive);
  _index = omc_Modelica_Utilities_Strings_findLast(threadData, _string, _searchString, tmp1, tmp2);
  out_index = mmc_mk_icon(_index);
  return out_index;
}

DLLExport
modelica_boolean omc_Modelica_Utilities_Strings_isEmpty(threadData_t *threadData, modelica_string _string)
{
  modelica_boolean _result;
  modelica_integer _nextIndex;
  modelica_integer _len;
  _tailrecursive: OMC_LABEL_UNUSED
  // _result has no default value.
  // _nextIndex has no default value.
  // _len has no default value.
  _nextIndex = omc_Modelica_Utilities_Strings_Advanced_skipWhiteSpace(threadData, _string, ((modelica_integer) 1));

  _len = omc_Modelica_Utilities_Strings_length(threadData, _string);

  if(((_len < ((modelica_integer) 1)) || (_nextIndex > _len)))
  {
    _result = 1;
  }
  else
  {
    _result = 0;
  }
  _return: OMC_LABEL_UNUSED
  return _result;
}
modelica_metatype boxptr_Modelica_Utilities_Strings_isEmpty(threadData_t *threadData, modelica_metatype _string)
{
  modelica_boolean _result;
  modelica_metatype out_result;
  _result = omc_Modelica_Utilities_Strings_isEmpty(threadData, _string);
  out_result = mmc_mk_icon(_result);
  return out_result;
}

DLLExport
modelica_boolean omc_Modelica_Utilities_Strings_isEqual(threadData_t *threadData, modelica_string _string1, modelica_string _string2, modelica_boolean _caseSensitive)
{
  modelica_boolean _identical;
  _tailrecursive: OMC_LABEL_UNUSED
  // _identical has no default value.
  _identical = (omc_Modelica_Utilities_Strings_compare(threadData, _string1, _string2, _caseSensitive) == 2);
  _return: OMC_LABEL_UNUSED
  return _identical;
}
modelica_metatype boxptr_Modelica_Utilities_Strings_isEqual(threadData_t *threadData, modelica_metatype _string1, modelica_metatype _string2, modelica_metatype _caseSensitive)
{
  modelica_integer tmp1;
  modelica_boolean _identical;
  modelica_metatype out_identical;
  tmp1 = mmc_unbox_integer(_caseSensitive);
  _identical = omc_Modelica_Utilities_Strings_isEqual(threadData, _string1, _string2, tmp1);
  out_identical = mmc_mk_icon(_identical);
  return out_identical;
}

modelica_integer omc_Modelica_Utilities_Strings_length(threadData_t *threadData, modelica_string _string)
{
  int _result_ext;
  modelica_integer _result;
  // _result has no default value.
  _result_ext = ModelicaStrings_length(MMC_STRINGDATA(_string));
  _result = (modelica_integer)_result_ext;
  return _result;
}
modelica_metatype boxptr_Modelica_Utilities_Strings_length(threadData_t *threadData, modelica_metatype _string)
{
  modelica_integer _result;
  modelica_metatype out_result;
  _result = omc_Modelica_Utilities_Strings_length(threadData, _string);
  out_result = mmc_mk_icon(_result);
  return out_result;
}

DLLExport
modelica_string omc_Modelica_Utilities_Strings_repeat(threadData_t *threadData, modelica_integer _n, modelica_string _string)
{
  modelica_string _repeatedString = NULL;
  modelica_integer tmp1;
  modelica_integer tmp2;
  modelica_integer tmp3;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  _tailrecursive: OMC_LABEL_UNUSED
  // _repeatedString has no default value.
  _repeatedString = _OMC_LIT20;

  tmp1 = ((modelica_integer) 1); tmp2 = 1; tmp3 = _n;
  if(!(((tmp2 > 0) && (tmp1 > tmp3)) || ((tmp2 < 0) && (tmp1 < tmp3))))
  {
    modelica_integer _i;
    for(_i = ((modelica_integer) 1); in_range_integer(_i, tmp1, tmp3); _i += tmp2)
    {
      tmpMeta[0] = stringAppend(_repeatedString,_string);
      _repeatedString = tmpMeta[0];
    }
  }
  _return: OMC_LABEL_UNUSED
  return _repeatedString;
}
modelica_metatype boxptr_Modelica_Utilities_Strings_repeat(threadData_t *threadData, modelica_metatype _n, modelica_metatype _string)
{
  modelica_integer tmp1;
  modelica_string _repeatedString = NULL;
  tmp1 = mmc_unbox_integer(_n);
  _repeatedString = omc_Modelica_Utilities_Strings_repeat(threadData, tmp1, _string);
  /* skip box _repeatedString; String */
  return _repeatedString;
}

DLLExport
modelica_integer omc_Modelica_Utilities_Strings_scanInteger(threadData_t *threadData, modelica_string _string, modelica_integer _startIndex, modelica_boolean _unsigned, modelica_string _message, modelica_integer *out_nextIndex)
{
  modelica_integer _number;
  modelica_integer _nextIndex;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  _tailrecursive: OMC_LABEL_UNUSED
  // _number has no default value.
  // _nextIndex has no default value.
  _nextIndex = omc_Modelica_Utilities_Strings_Advanced_scanInteger(threadData, _string, _startIndex, _unsigned ,&_number);

  if((_nextIndex == _startIndex))
  {
    _nextIndex = omc_Modelica_Utilities_Strings_Advanced_skipWhiteSpace(threadData, _string, _startIndex);

    if(_unsigned)
    {
      tmpMeta[0] = stringAppend(_OMC_LIT23,_message);
      omc_Modelica_Utilities_Strings_syntaxError(threadData, _string, _nextIndex, tmpMeta[0]);
    }
    else
    {
      tmpMeta[0] = stringAppend(_OMC_LIT22,_message);
      omc_Modelica_Utilities_Strings_syntaxError(threadData, _string, _nextIndex, tmpMeta[0]);
    }
  }
  _return: OMC_LABEL_UNUSED
  if (out_nextIndex) { *out_nextIndex = _nextIndex; }
  return _number;
}
modelica_metatype boxptr_Modelica_Utilities_Strings_scanInteger(threadData_t *threadData, modelica_metatype _string, modelica_metatype _startIndex, modelica_metatype _unsigned, modelica_metatype _message, modelica_metatype *out_nextIndex)
{
  modelica_integer tmp1;
  modelica_integer tmp2;
  modelica_integer _nextIndex;
  modelica_integer _number;
  modelica_metatype out_number;
  tmp1 = mmc_unbox_integer(_startIndex);
  tmp2 = mmc_unbox_integer(_unsigned);
  _number = omc_Modelica_Utilities_Strings_scanInteger(threadData, _string, tmp1, tmp2, _message, &_nextIndex);
  out_number = mmc_mk_icon(_number);
  if (out_nextIndex) { *out_nextIndex = mmc_mk_icon(_nextIndex); }
  return out_number;
}

DLLExport
modelica_real omc_Modelica_Utilities_Strings_scanReal(threadData_t *threadData, modelica_string _string, modelica_integer _startIndex, modelica_boolean _unsigned, modelica_string _message, modelica_integer *out_nextIndex)
{
  modelica_real _number;
  modelica_integer _nextIndex;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  _tailrecursive: OMC_LABEL_UNUSED
  // _number has no default value.
  // _nextIndex has no default value.
  _nextIndex = omc_Modelica_Utilities_Strings_Advanced_scanReal(threadData, _string, _startIndex, _unsigned ,&_number);

  if((_nextIndex == _startIndex))
  {
    _nextIndex = omc_Modelica_Utilities_Strings_Advanced_skipWhiteSpace(threadData, _string, _startIndex);

    if(_unsigned)
    {
      tmpMeta[0] = stringAppend(_OMC_LIT25,_message);
      omc_Modelica_Utilities_Strings_syntaxError(threadData, _string, _nextIndex, tmpMeta[0]);
    }
    else
    {
      tmpMeta[0] = stringAppend(_OMC_LIT24,_message);
      omc_Modelica_Utilities_Strings_syntaxError(threadData, _string, _nextIndex, tmpMeta[0]);
    }
  }
  _return: OMC_LABEL_UNUSED
  if (out_nextIndex) { *out_nextIndex = _nextIndex; }
  return _number;
}
modelica_metatype boxptr_Modelica_Utilities_Strings_scanReal(threadData_t *threadData, modelica_metatype _string, modelica_metatype _startIndex, modelica_metatype _unsigned, modelica_metatype _message, modelica_metatype *out_nextIndex)
{
  modelica_integer tmp1;
  modelica_integer tmp2;
  modelica_integer _nextIndex;
  modelica_real _number;
  modelica_metatype out_number;
  tmp1 = mmc_unbox_integer(_startIndex);
  tmp2 = mmc_unbox_integer(_unsigned);
  _number = omc_Modelica_Utilities_Strings_scanReal(threadData, _string, tmp1, tmp2, _message, &_nextIndex);
  out_number = mmc_mk_rcon(_number);
  if (out_nextIndex) { *out_nextIndex = mmc_mk_icon(_nextIndex); }
  return out_number;
}

modelica_string omc_Modelica_Utilities_Strings_substring(threadData_t *threadData, modelica_string _string, modelica_integer _startIndex, modelica_integer _endIndex)
{
  int _startIndex_ext;
  int _endIndex_ext;
  const char* _result_ext;
  modelica_string _result = NULL;
  // _result has no default value.
  _startIndex_ext = (int)_startIndex;

  _endIndex_ext = (int)_endIndex;
  _result_ext = ModelicaStrings_substring(MMC_STRINGDATA(_string), _startIndex_ext, _endIndex_ext);
  _result = (modelica_string)mmc_mk_scon(_result_ext);
  return _result;
}
modelica_metatype boxptr_Modelica_Utilities_Strings_substring(threadData_t *threadData, modelica_metatype _string, modelica_metatype _startIndex, modelica_metatype _endIndex)
{
  modelica_integer tmp1;
  modelica_integer tmp2;
  modelica_string _result = NULL;
  tmp1 = mmc_unbox_integer(_startIndex);
  tmp2 = mmc_unbox_integer(_endIndex);
  _result = omc_Modelica_Utilities_Strings_substring(threadData, _string, tmp1, tmp2);
  /* skip box _result; String */
  return _result;
}

DLLExport
void omc_Modelica_Utilities_Strings_syntaxError(threadData_t *threadData, modelica_string _string, modelica_integer _index, modelica_string _message)
{
  modelica_integer _maxIndex;
  modelica_integer _maxLenString;
  modelica_string _errString = NULL;
  modelica_integer _lenString;
  modelica_integer _index2;
  modelica_string tmp1;
  modelica_metatype tmpMeta[8] __attribute__((unused)) = {0};
  _tailrecursive: OMC_LABEL_UNUSED
  _maxIndex = ((modelica_integer) 40);
  _maxLenString = ((modelica_integer) 60);
  // _errString has no default value.
  _lenString = omc_Modelica_Utilities_Strings_length(threadData, _string);
  _index2 = ((_index < ((modelica_integer) 1))?((modelica_integer) 1):((_index > _lenString)?_lenString:_index));
  if((_index2 <= _maxIndex))
  {
    _errString = _string;
  }
  else
  {
    tmpMeta[0] = stringAppend(_OMC_LIT26,omc_Modelica_Utilities_Strings_substring(threadData, _string, _index2 - _maxIndex, _lenString));
    _errString = tmpMeta[0];

    _index2 = ((modelica_integer) 5) + _maxIndex;
  }

  if((omc_Modelica_Utilities_Strings_length(threadData, _errString) > _maxLenString))
  {
    tmpMeta[0] = stringAppend(omc_Modelica_Utilities_Strings_substring(threadData, _errString, ((modelica_integer) 1), _maxLenString),_OMC_LIT27);
    _errString = tmpMeta[0];
  }

  tmp1 = modelica_integer_to_modelica_string(_index, ((modelica_integer) 0), 1);
  tmpMeta[0] = stringAppend(_OMC_LIT28,tmp1);
  tmpMeta[1] = stringAppend(tmpMeta[0],_OMC_LIT29);
  tmpMeta[2] = stringAppend(tmpMeta[1],_errString);
  tmpMeta[3] = stringAppend(tmpMeta[2],_OMC_LIT30);
  tmpMeta[4] = stringAppend(tmpMeta[3],omc_Modelica_Utilities_Strings_repeat(threadData, ((modelica_integer) -1) + _index2, _OMC_LIT21));
  tmpMeta[5] = stringAppend(tmpMeta[4],_OMC_LIT31);
  tmpMeta[6] = stringAppend(tmpMeta[5],_OMC_LIT30);
  tmpMeta[7] = stringAppend(tmpMeta[6],_message);
  omc_Modelica_Utilities_Streams_error(threadData, tmpMeta[7]);
  _return: OMC_LABEL_UNUSED
  return;
}
void boxptr_Modelica_Utilities_Strings_syntaxError(threadData_t *threadData, modelica_metatype _string, modelica_metatype _index, modelica_metatype _message)
{
  modelica_integer tmp1;
  tmp1 = mmc_unbox_integer(_index);
  omc_Modelica_Utilities_Strings_syntaxError(threadData, _string, tmp1, _message);
  return;
}

modelica_integer omc_Modelica_Utilities_Strings_Advanced_scanInteger(threadData_t *threadData, modelica_string _string, modelica_integer _startIndex, modelica_boolean _unsigned, modelica_integer *out_number)
{
  int _startIndex_ext;
  int _unsigned_ext;
  int _nextIndex_ext;
  int _number_ext;
  modelica_integer _nextIndex;
  modelica_integer _number;
  // _nextIndex has no default value.
  // _number has no default value.
  _startIndex_ext = (int)_startIndex;

  _unsigned_ext = (int)_unsigned;
  ModelicaStrings_scanInteger(MMC_STRINGDATA(_string), _startIndex_ext, _unsigned_ext, &_nextIndex_ext, &_number_ext);
  _nextIndex = (modelica_integer)_nextIndex_ext;
  _number = (modelica_integer)_number_ext;
  if (out_number) { *out_number = _number; }
  return _nextIndex;
}
modelica_metatype boxptr_Modelica_Utilities_Strings_Advanced_scanInteger(threadData_t *threadData, modelica_metatype _string, modelica_metatype _startIndex, modelica_metatype _unsigned, modelica_metatype *out_number)
{
  modelica_integer tmp1;
  modelica_integer tmp2;
  modelica_integer _number;
  modelica_integer _nextIndex;
  modelica_metatype out_nextIndex;
  tmp1 = mmc_unbox_integer(_startIndex);
  tmp2 = mmc_unbox_integer(_unsigned);
  _nextIndex = omc_Modelica_Utilities_Strings_Advanced_scanInteger(threadData, _string, tmp1, tmp2, &_number);
  out_nextIndex = mmc_mk_icon(_nextIndex);
  if (out_number) { *out_number = mmc_mk_icon(_number); }
  return out_nextIndex;
}

modelica_integer omc_Modelica_Utilities_Strings_Advanced_scanReal(threadData_t *threadData, modelica_string _string, modelica_integer _startIndex, modelica_boolean _unsigned, modelica_real *out_number)
{
  int _startIndex_ext;
  int _unsigned_ext;
  int _nextIndex_ext;
  double _number_ext;
  modelica_integer _nextIndex;
  modelica_real _number;
  // _nextIndex has no default value.
  // _number has no default value.
  _startIndex_ext = (int)_startIndex;

  _unsigned_ext = (int)_unsigned;
  ModelicaStrings_scanReal(MMC_STRINGDATA(_string), _startIndex_ext, _unsigned_ext, &_nextIndex_ext, &_number_ext);
  _nextIndex = (modelica_integer)_nextIndex_ext;
  _number = (modelica_real)_number_ext;
  if (out_number) { *out_number = _number; }
  return _nextIndex;
}
modelica_metatype boxptr_Modelica_Utilities_Strings_Advanced_scanReal(threadData_t *threadData, modelica_metatype _string, modelica_metatype _startIndex, modelica_metatype _unsigned, modelica_metatype *out_number)
{
  modelica_integer tmp1;
  modelica_integer tmp2;
  modelica_real _number;
  modelica_integer _nextIndex;
  modelica_metatype out_nextIndex;
  tmp1 = mmc_unbox_integer(_startIndex);
  tmp2 = mmc_unbox_integer(_unsigned);
  _nextIndex = omc_Modelica_Utilities_Strings_Advanced_scanReal(threadData, _string, tmp1, tmp2, &_number);
  out_nextIndex = mmc_mk_icon(_nextIndex);
  if (out_number) { *out_number = mmc_mk_rcon(_number); }
  return out_nextIndex;
}

modelica_integer omc_Modelica_Utilities_Strings_Advanced_skipWhiteSpace(threadData_t *threadData, modelica_string _string, modelica_integer _startIndex)
{
  int _startIndex_ext;
  int _nextIndex_ext;
  modelica_integer _nextIndex;
  // _nextIndex has no default value.
  _startIndex_ext = (int)_startIndex;
  _nextIndex_ext = ModelicaStrings_skipWhiteSpace(MMC_STRINGDATA(_string), _startIndex_ext);
  _nextIndex = (modelica_integer)_nextIndex_ext;
  return _nextIndex;
}
modelica_metatype boxptr_Modelica_Utilities_Strings_Advanced_skipWhiteSpace(threadData_t *threadData, modelica_metatype _string, modelica_metatype _startIndex)
{
  modelica_integer tmp1;
  modelica_integer _nextIndex;
  modelica_metatype out_nextIndex;
  tmp1 = mmc_unbox_integer(_startIndex);
  _nextIndex = omc_Modelica_Utilities_Strings_Advanced_skipWhiteSpace(threadData, _string, tmp1);
  out_nextIndex = mmc_mk_icon(_nextIndex);
  return out_nextIndex;
}

modelica_integer omc_Modelica_Utilities_System_command(threadData_t *threadData, modelica_string _string)
{
  int _result_ext;
  modelica_integer _result;
  // _result has no default value.
  _result_ext = system(MMC_STRINGDATA(_string));
  _result = (modelica_integer)_result_ext;
  return _result;
}
modelica_metatype boxptr_Modelica_Utilities_System_command(threadData_t *threadData, modelica_metatype _string)
{
  modelica_integer _result;
  modelica_metatype out_result;
  _result = omc_Modelica_Utilities_System_command(threadData, _string);
  out_result = mmc_mk_icon(_result);
  return out_result;
}

Reference__1_Medium_ThermodynamicState omc_Reference__1_Medium_ThermodynamicState(threadData_t *threadData, modelica_real omc_p, modelica_real omc_h)
{
  Reference__1_Medium_ThermodynamicState tmp1;
  tmp1._p = omc_p;
  tmp1._h = omc_h;
  return tmp1;
}

modelica_metatype boxptr_Reference__1_Medium_ThermodynamicState(threadData_t *threadData, modelica_metatype _p, modelica_metatype _h)
{
  return mmc_mk_box3(3, &Reference__1_Medium_ThermodynamicState__desc, _p, _h);
}

DLLExport
modelica_real omc_SolarTherm_Media_MoltenSalt_MoltenSalt__utilities_T__h(threadData_t *threadData, modelica_real _h)
{
  modelica_real _T;
  modelica_real _delta;
  modelica_real tmp1;
  _tailrecursive: OMC_LABEL_UNUSED
  // _T has no default value.
  // _delta has no default value.
  _delta = fabs(1948866.81473124 + (0.344) * (_h));

  tmp1 = _delta;
  if(!(tmp1 >= 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert(threadData, info, "Model error: Argument of sqrt(delta) was %g should be >= 0", tmp1);
  }
  _T = -8116.384883720931 + (5.813953488372094) * (sqrt(tmp1));
  _return: OMC_LABEL_UNUSED
  return _T;
}
modelica_metatype boxptr_SolarTherm_Media_MoltenSalt_MoltenSalt__utilities_T__h(threadData_t *threadData, modelica_metatype _h)
{
  modelica_real tmp1;
  modelica_real _T;
  modelica_metatype out_T;
  tmp1 = mmc_unbox_real(_h);
  _T = omc_SolarTherm_Media_MoltenSalt_MoltenSalt__utilities_T__h(threadData, tmp1);
  out_T = mmc_mk_rcon(_T);
  return out_T;
}

DLLExport
modelica_real omc_SolarTherm_Media_MoltenSalt_MoltenSalt__utilities_rho__T(threadData_t *threadData, modelica_real _K)
{
  modelica_real _rho;
  modelica_real _T;
  _tailrecursive: OMC_LABEL_UNUSED
  // _rho has no default value.
  _T = omc_Modelica_SIunits_Conversions_to__degC(threadData, _K);
  _rho = 2090.0 + (-0.636) * (_T);
  _return: OMC_LABEL_UNUSED
  return _rho;
}
modelica_metatype boxptr_SolarTherm_Media_MoltenSalt_MoltenSalt__utilities_rho__T(threadData_t *threadData, modelica_metatype _K)
{
  modelica_real tmp1;
  modelica_real _rho;
  modelica_metatype out_rho;
  tmp1 = mmc_unbox_real(_K);
  _rho = omc_SolarTherm_Media_MoltenSalt_MoltenSalt__utilities_rho__T(threadData, tmp1);
  out_rho = mmc_mk_rcon(_rho);
  return out_rho;
}

SolarTherm_Models_CSP_CRS_Receivers__omcQReceiverSimple_24receiver_Medium_ThermodynamicState omc_SolarTherm_Models_CSP_CRS_Receivers__omcQReceiverSimple_24receiver_Medium_ThermodynamicState(threadData_t *threadData, modelica_real omc_p, modelica_real omc_h)
{
  SolarTherm_Models_CSP_CRS_Receivers__omcQReceiverSimple_24receiver_Medium_ThermodynamicState tmp1;
  tmp1._p = omc_p;
  tmp1._h = omc_h;
  return tmp1;
}

modelica_metatype boxptr_SolarTherm_Models_CSP_CRS_Receivers__omcQReceiverSimple_24receiver_Medium_ThermodynamicState(threadData_t *threadData, modelica_metatype _p, modelica_metatype _h)
{
  return mmc_mk_box3(3, &SolarTherm_Models_CSP_CRS_Receivers__omcQReceiverSimple_24receiver_Medium_ThermodynamicState__desc, _p, _h);
}

SolarTherm_Models_Fluid_Sensors__omcQTemperature_24temperature_Medium_ThermodynamicState omc_SolarTherm_Models_Fluid_Sensors__omcQTemperature_24temperature_Medium_ThermodynamicState(threadData_t *threadData, modelica_real omc_p, modelica_real omc_h)
{
  SolarTherm_Models_Fluid_Sensors__omcQTemperature_24temperature_Medium_ThermodynamicState tmp1;
  tmp1._p = omc_p;
  tmp1._h = omc_h;
  return tmp1;
}

modelica_metatype boxptr_SolarTherm_Models_Fluid_Sensors__omcQTemperature_24temperature_Medium_ThermodynamicState(threadData_t *threadData, modelica_metatype _p, modelica_metatype _h)
{
  return mmc_mk_box3(3, &SolarTherm_Models_Fluid_Sensors__omcQTemperature_24temperature_Medium_ThermodynamicState__desc, _p, _h);
}

SolarTherm_Models_PowerBlocks__omcQPowerBlockModel_24powerBlock_Medium_ThermodynamicState omc_SolarTherm_Models_PowerBlocks__omcQPowerBlockModel_24powerBlock_Medium_ThermodynamicState(threadData_t *threadData, modelica_real omc_p, modelica_real omc_h)
{
  SolarTherm_Models_PowerBlocks__omcQPowerBlockModel_24powerBlock_Medium_ThermodynamicState tmp1;
  tmp1._p = omc_p;
  tmp1._h = omc_h;
  return tmp1;
}

modelica_metatype boxptr_SolarTherm_Models_PowerBlocks__omcQPowerBlockModel_24powerBlock_Medium_ThermodynamicState(threadData_t *threadData, modelica_metatype _p, modelica_metatype _h)
{
  return mmc_mk_box3(3, &SolarTherm_Models_PowerBlocks__omcQPowerBlockModel_24powerBlock_Medium_ThermodynamicState__desc, _p, _h);
}

DLLExport
modelica_real omc_SolarTherm_Models_Sources_SolarFunctions_aparentSolarZenith(threadData_t *threadData, modelica_real _dec, modelica_real _hra, modelica_real _lat)
{
  modelica_real _zen_ap;
  modelica_real _zen;
  modelica_real _A;
  modelica_real _B;
  modelica_real _C;
  modelica_real _D;
  modelica_real _E;
  modelica_real tmp1;
  modelica_real tmp2;
  modelica_real tmp3;
  modelica_real tmp4;
  modelica_real tmp5;
  modelica_real tmp6;
  modelica_real tmp7;
  modelica_real tmp8;
  _tailrecursive: OMC_LABEL_UNUSED
  // _zen_ap has no default value.
  // _zen has no default value.
  _A = 0.004013327;
  _B = 0.06476916000000001;
  _C = -0.66956539;
  _D = 0.019276169;
  _E = -0.00051297;
  tmp1 = (cos(omc_Modelica_SIunits_Conversions_from__deg(threadData, _lat))) * ((cos(_dec)) * (cos(_hra))) + (sin(omc_Modelica_SIunits_Conversions_from__deg(threadData, _lat))) * (sin(_dec));
  if(!(tmp1 >= -1.0 && tmp1 <= 1.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert(threadData, info, "Model error: Argument of acos(cos(Modelica.SIunits.Conversions.from_deg(lat)) * cos(dec) * cos(hra) + sin(Modelica.SIunits.Conversions.from_deg(lat)) * sin(dec)) outside the domain -1.0 <= %g <= 1.0", tmp1);
  }
  _zen = acos(tmp1);

  tmp2 = (15.43944679844543) * (_zen);
  tmp3 = -0.66956539 + (0.019276169) * (_zen);
  if(tmp2 < 0.0 && tmp3 != 0.0)
  {
    tmp5 = modf(tmp3, &tmp6);
    
    if(tmp5 > 0.5)
    {
      tmp5 -= 1.0;
      tmp6 += 1.0;
    }
    else if(tmp5 < -0.5)
    {
      tmp5 += 1.0;
      tmp6 -= 1.0;
    }
    
    if(fabs(tmp5) < 1e-10)
      tmp4 = pow(tmp2, tmp6);
    else
    {
      tmp8 = modf(1.0/tmp3, &tmp7);
      if(tmp8 > 0.5)
      {
        tmp8 -= 1.0;
        tmp7 += 1.0;
      }
      else if(tmp8 < -0.5)
      {
        tmp8 += 1.0;
        tmp7 -= 1.0;
      }
      if(fabs(tmp8) < 1e-10 && ((unsigned long)tmp7 & 1))
      {
        tmp4 = -pow(-tmp2, tmp5)*pow(tmp2, tmp6);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp2, tmp3);
      }
    }
  }
  else
  {
    tmp4 = pow(tmp2, tmp3);
  }
  if(isnan(tmp4) || isinf(tmp4))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp2, tmp3);
  }
  _zen_ap = fmin(1.570796326794897,-0.00051297 + _zen + (-0.004013327) * (tmp4));
  _return: OMC_LABEL_UNUSED
  return _zen_ap;
}
modelica_metatype boxptr_SolarTherm_Models_Sources_SolarFunctions_aparentSolarZenith(threadData_t *threadData, modelica_metatype _dec, modelica_metatype _hra, modelica_metatype _lat)
{
  modelica_real tmp1;
  modelica_real tmp2;
  modelica_real tmp3;
  modelica_real _zen_ap;
  modelica_metatype out_zen_ap;
  tmp1 = mmc_unbox_real(_dec);
  tmp2 = mmc_unbox_real(_hra);
  tmp3 = mmc_unbox_real(_lat);
  _zen_ap = omc_SolarTherm_Models_Sources_SolarFunctions_aparentSolarZenith(threadData, tmp1, tmp2, tmp3);
  out_zen_ap = mmc_mk_rcon(_zen_ap);
  return out_zen_ap;
}

DLLExport
modelica_real omc_SolarTherm_Models_Sources_SolarFunctions_eclipticLongitude(threadData_t *threadData, modelica_real _dec)
{
  modelica_real _elo;
  modelica_real _axial_tilt;
  modelica_real tmp1;
  modelica_real tmp2;
  _tailrecursive: OMC_LABEL_UNUSED
  // _elo has no default value.
  _axial_tilt = 0.409377448030782;
  tmp1 = sin(_axial_tilt);
  if (tmp1 == 0) {throwStreamPrint(threadData, "Division by zero %s", "sin(dec) / sin(axial_tilt)");}
  tmp2 = (sin(_dec)) / tmp1;
  if(!(tmp2 >= -1.0 && tmp2 <= 1.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert(threadData, info, "Model error: Argument of asin(sin(dec) / sin(axial_tilt)) outside the domain -1.0 <= %g <= 1.0", tmp2);
  }
  _elo = asin(tmp2);
  _return: OMC_LABEL_UNUSED
  return _elo;
}
modelica_metatype boxptr_SolarTherm_Models_Sources_SolarFunctions_eclipticLongitude(threadData_t *threadData, modelica_metatype _dec)
{
  modelica_real tmp1;
  modelica_real _elo;
  modelica_metatype out_elo;
  tmp1 = mmc_unbox_real(_dec);
  _elo = omc_SolarTherm_Models_Sources_SolarFunctions_eclipticLongitude(threadData, tmp1);
  out_elo = mmc_mk_rcon(_elo);
  return out_elo;
}

DLLExport
modelica_real omc_SolarTherm_Models_Sources_SolarFunctions_elevationAngle(threadData_t *threadData, modelica_real _dec, modelica_real _hra, modelica_real _lat)
{
  modelica_real _ele;
  modelica_real tmp1;
  _tailrecursive: OMC_LABEL_UNUSED
  // _ele has no default value.
  tmp1 = (sin(omc_Modelica_SIunits_Conversions_from__deg(threadData, _lat))) * (sin(_dec)) + (cos(omc_Modelica_SIunits_Conversions_from__deg(threadData, _lat))) * ((cos(_dec)) * (cos(_hra)));
  if(!(tmp1 >= -1.0 && tmp1 <= 1.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert(threadData, info, "Model error: Argument of asin(sin(Modelica.SIunits.Conversions.from_deg(lat)) * sin(dec) + cos(Modelica.SIunits.Conversions.from_deg(lat)) * cos(dec) * cos(hra)) outside the domain -1.0 <= %g <= 1.0", tmp1);
  }
  _ele = fmax(0.0,asin(tmp1));
  _return: OMC_LABEL_UNUSED
  return _ele;
}
modelica_metatype boxptr_SolarTherm_Models_Sources_SolarFunctions_elevationAngle(threadData_t *threadData, modelica_metatype _dec, modelica_metatype _hra, modelica_metatype _lat)
{
  modelica_real tmp1;
  modelica_real tmp2;
  modelica_real tmp3;
  modelica_real _ele;
  modelica_metatype out_ele;
  tmp1 = mmc_unbox_real(_dec);
  tmp2 = mmc_unbox_real(_hra);
  tmp3 = mmc_unbox_real(_lat);
  _ele = omc_SolarTherm_Models_Sources_SolarFunctions_elevationAngle(threadData, tmp1, tmp2, tmp3);
  out_ele = mmc_mk_rcon(_ele);
  return out_ele;
}

DLLExport
modelica_real omc_SolarTherm_Models_Sources_SolarFunctions_julianDay(threadData_t *threadData, modelica_integer _year, modelica_integer _month, modelica_integer _day, modelica_real _hour)
{
  modelica_real _jday;
  modelica_integer tmp1;
  modelica_integer tmp2;
  modelica_integer tmp3;
  modelica_integer tmp4;
  modelica_integer tmp5;
  modelica_integer tmp6;
  modelica_integer tmp7;
  _tailrecursive: OMC_LABEL_UNUSED
  // _jday has no default value.
  tmp1 = ((modelica_integer) 12);
  if (tmp1 == 0) {throwStreamPrint(threadData, "Division by zero %s", "div(-14 + month, 12)");}
  tmp2 = ((modelica_integer) 4);
  if (tmp2 == 0) {throwStreamPrint(threadData, "Division by zero %s", "div(1461 * (4800 + year + div(-14 + month, 12)), 4)");}
  tmp3 = ((modelica_integer) 12);
  if (tmp3 == 0) {throwStreamPrint(threadData, "Division by zero %s", "div(-14 + month, 12)");}
  tmp4 = ((modelica_integer) 12);
  if (tmp4 == 0) {throwStreamPrint(threadData, "Division by zero %s", "div(367 * (-2 + month + -12 * div(-14 + month, 12)), 12)");}
  tmp5 = ((modelica_integer) 12);
  if (tmp5 == 0) {throwStreamPrint(threadData, "Division by zero %s", "div(-14 + month, 12)");}
  tmp6 = ((modelica_integer) 100);
  if (tmp6 == 0) {throwStreamPrint(threadData, "Division by zero %s", "div(4900 + year + div(-14 + month, 12), 100)");}
  tmp7 = ((modelica_integer) 4);
  if (tmp7 == 0) {throwStreamPrint(threadData, "Division by zero %s", "div(3 * div(4900 + year + div(-14 + month, 12), 100), 4)");}
  _jday = -0.5 + ((modelica_real)((modelica_integer) -32075) + ldiv((((modelica_integer) 1461)) * (((modelica_integer) 4800) + _year + ldiv(((modelica_integer) -14) + _month,tmp1).quot),tmp2).quot + ldiv((((modelica_integer) 367)) * (((modelica_integer) -2) + _month + (((modelica_integer) -12)) * (ldiv(((modelica_integer) -14) + _month,tmp3).quot)),tmp4).quot + _day - ldiv((((modelica_integer) 3)) * (ldiv(((modelica_integer) 4900) + _year + ldiv(((modelica_integer) -14) + _month,tmp5).quot,tmp6).quot),tmp7).quot) + (0.04166666666666666) * (_hour);
  _return: OMC_LABEL_UNUSED
  return _jday;
}
modelica_metatype boxptr_SolarTherm_Models_Sources_SolarFunctions_julianDay(threadData_t *threadData, modelica_metatype _year, modelica_metatype _month, modelica_metatype _day, modelica_metatype _hour)
{
  modelica_integer tmp1;
  modelica_integer tmp2;
  modelica_integer tmp3;
  modelica_real tmp4;
  modelica_real _jday;
  modelica_metatype out_jday;
  tmp1 = mmc_unbox_integer(_year);
  tmp2 = mmc_unbox_integer(_month);
  tmp3 = mmc_unbox_integer(_day);
  tmp4 = mmc_unbox_real(_hour);
  _jday = omc_SolarTherm_Models_Sources_SolarFunctions_julianDay(threadData, tmp1, tmp2, tmp3, tmp4);
  out_jday = mmc_mk_rcon(_jday);
  return out_jday;
}

DLLExport
modelica_real omc_SolarTherm_Models_Sources_SolarFunctions_solarAzimuth(threadData_t *threadData, modelica_real _dec, modelica_real _hra, modelica_real _lat)
{
  modelica_real _azi;
  modelica_real _zen;
  modelica_real tmp1;
  modelica_real tmp2;
  modelica_real tmp3;
  modelica_real tmp4;
  _tailrecursive: OMC_LABEL_UNUSED
  // _azi has no default value.
  // _zen has no default value.
  _zen = omc_SolarTherm_Models_Sources_SolarFunctions_solarZenith(threadData, _dec, _hra, _lat);

  if((_lat > 0.0))
  {
    tmp1 = (cos(omc_Modelica_SIunits_Conversions_from__deg(threadData, _lat))) * (sin(_zen));
    if (tmp1 == 0) {throwStreamPrint(threadData, "Division by zero %s", "(cos(zen) * sin(Modelica.SIunits.Conversions.from_deg(lat)) - sin(dec)) / (cos(Modelica.SIunits.Conversions.from_deg(lat)) * sin(zen))");}
    tmp2 = ((cos(_zen)) * (sin(omc_Modelica_SIunits_Conversions_from__deg(threadData, _lat))) - sin(_dec)) / tmp1;
    if(!(tmp2 >= -1.0 && tmp2 <= 1.0))
    {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert(threadData, info, "Model error: Argument of acos((cos(zen) * sin(Modelica.SIunits.Conversions.from_deg(lat)) - sin(dec)) / (cos(Modelica.SIunits.Conversions.from_deg(lat)) * sin(zen))) outside the domain -1.0 <= %g <= 1.0", tmp2);
    }
    _azi = (((modelica_real)sign(_hra))) * (fabs(acos(tmp2)));
  }
  else
  {
    tmp3 = (cos(omc_Modelica_SIunits_Conversions_from__deg(threadData, _lat))) * (sin(_zen));
    if (tmp3 == 0) {throwStreamPrint(threadData, "Division by zero %s", "(cos(zen) * sin(Modelica.SIunits.Conversions.from_deg(lat)) - sin(dec)) / (cos(Modelica.SIunits.Conversions.from_deg(lat)) * sin(zen))");}
    tmp4 = ((cos(_zen)) * (sin(omc_Modelica_SIunits_Conversions_from__deg(threadData, _lat))) - sin(_dec)) / tmp3;
    if(!(tmp4 >= -1.0 && tmp4 <= 1.0))
    {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert(threadData, info, "Model error: Argument of acos((cos(zen) * sin(Modelica.SIunits.Conversions.from_deg(lat)) - sin(dec)) / (cos(Modelica.SIunits.Conversions.from_deg(lat)) * sin(zen))) outside the domain -1.0 <= %g <= 1.0", tmp4);
    }
    _azi = (((modelica_real)sign(_hra))) * (fabs(-3.141592653589793 + acos(tmp4)));
  }
  _return: OMC_LABEL_UNUSED
  return _azi;
}
modelica_metatype boxptr_SolarTherm_Models_Sources_SolarFunctions_solarAzimuth(threadData_t *threadData, modelica_metatype _dec, modelica_metatype _hra, modelica_metatype _lat)
{
  modelica_real tmp1;
  modelica_real tmp2;
  modelica_real tmp3;
  modelica_real _azi;
  modelica_metatype out_azi;
  tmp1 = mmc_unbox_real(_dec);
  tmp2 = mmc_unbox_real(_hra);
  tmp3 = mmc_unbox_real(_lat);
  _azi = omc_SolarTherm_Models_Sources_SolarFunctions_solarAzimuth(threadData, tmp1, tmp2, tmp3);
  out_azi = mmc_mk_rcon(_azi);
  return out_azi;
}

DLLExport
modelica_real omc_SolarTherm_Models_Sources_SolarFunctions_solarZenith(threadData_t *threadData, modelica_real _dec, modelica_real _hra, modelica_real _lat)
{
  modelica_real _zen;
  modelica_real tmp1;
  _tailrecursive: OMC_LABEL_UNUSED
  // _zen has no default value.
  tmp1 = (cos(omc_Modelica_SIunits_Conversions_from__deg(threadData, _lat))) * ((cos(_dec)) * (cos(_hra))) + (sin(omc_Modelica_SIunits_Conversions_from__deg(threadData, _lat))) * (sin(_dec));
  if(!(tmp1 >= -1.0 && tmp1 <= 1.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert(threadData, info, "Model error: Argument of acos(cos(Modelica.SIunits.Conversions.from_deg(lat)) * cos(dec) * cos(hra) + sin(Modelica.SIunits.Conversions.from_deg(lat)) * sin(dec)) outside the domain -1.0 <= %g <= 1.0", tmp1);
  }
  _zen = acos(tmp1);
  _return: OMC_LABEL_UNUSED
  return _zen;
}
modelica_metatype boxptr_SolarTherm_Models_Sources_SolarFunctions_solarZenith(threadData_t *threadData, modelica_metatype _dec, modelica_metatype _hra, modelica_metatype _lat)
{
  modelica_real tmp1;
  modelica_real tmp2;
  modelica_real tmp3;
  modelica_real _zen;
  modelica_metatype out_zen;
  tmp1 = mmc_unbox_real(_dec);
  tmp2 = mmc_unbox_real(_hra);
  tmp3 = mmc_unbox_real(_lat);
  _zen = omc_SolarTherm_Models_Sources_SolarFunctions_solarZenith(threadData, tmp1, tmp2, tmp3);
  out_zen = mmc_mk_rcon(_zen);
  return out_zen;
}

DLLExport
modelica_real omc_SolarTherm_Models_Sources_SolarModel__omcQSun_24sun_solarPosition(threadData_t *threadData, modelica_real _t, modelica_real _lon, modelica_real _lat, modelica_real _t_zone, modelica_integer _year, modelica_real *out_hra)
{
  modelica_real _dec;
  modelica_real _hra;
  modelica_real _declination;
  modelica_real _hourangle;
  modelica_real _zenithangle;
  modelica_real _azimuth;
  modelica_real _twopi;
  modelica_real _rad;
  modelica_real _earthmeanradius;
  modelica_real _astronomicalunit;
  modelica_real _elapsedjuliandays;
  modelica_real _aux;
  modelica_real _eclipticlongitude;
  modelica_real _eclipticobliquity;
  modelica_real _sineclipticlongitude;
  modelica_real _y;
  modelica_real _x;
  modelica_real _rightascension;
  modelica_real _greenwichmeansiderealtime;
  modelica_real _localmeansiderealtime;
  modelica_real _latitudeinradians;
  modelica_real _coslatitude;
  modelica_real _sinlatitude;
  modelica_real _coshourangle;
  modelica_real _parallax;
  modelica_integer _intaux;
  modelica_real _longitude;
  modelica_real _latitude;
  modelica_real _t_zone_int;
  modelica_real _julianday;
  modelica_real tmp1;
  modelica_real tmp2;
  modelica_real tmp3;
  _tailrecursive: OMC_LABEL_UNUSED
  // _dec has no default value.
  // _hra has no default value.
  // _declination has no default value.
  // _hourangle has no default value.
  // _zenithangle has no default value.
  // _azimuth has no default value.
  _twopi = 6.283185307179586;
  _rad = 0.0174532925199433;
  _earthmeanradius = 6371.01;
  _astronomicalunit = 149597890.0;
  // _elapsedjuliandays has no default value.
  // _aux has no default value.
  // _eclipticlongitude has no default value.
  // _eclipticobliquity has no default value.
  // _sineclipticlongitude has no default value.
  // _y has no default value.
  // _x has no default value.
  // _rightascension has no default value.
  // _greenwichmeansiderealtime has no default value.
  // _localmeansiderealtime has no default value.
  // _latitudeinradians has no default value.
  // _coslatitude has no default value.
  // _sinlatitude has no default value.
  // _coshourangle has no default value.
  // _parallax has no default value.
  // _intaux has no default value.
  _longitude = _lon;
  _latitude = _lat;
  _t_zone_int = ((modelica_real)(sign(_t_zone)) * (((modelica_integer)floor(fabs(_t_zone)))));
  _julianday = omc_SolarTherm_Models_Sources_SolarFunctions_julianDay(threadData, _year, ((modelica_integer) 1), ((modelica_integer) 1), (0.0002777777777777778) * (_t) - _t_zone_int);
  _elapsedjuliandays = -2451545.0 + _julianday;

  _aux = (0.0172021241615) * (_elapsedjuliandays);

  _eclipticlongitude = 4.894969024 + (_elapsedjuliandays) * (0.017202791697 + (5.78262765229295e-09) * (cos(2.67824 + _aux))) + (0.03341656) * (cos(4.6693 + _aux)) + (0.00034894) * (cos(4.6261 + (0.03440424832) * (_elapsedjuliandays))) + (-8.339e-05) * (sin(2.1824 + (-0.00092421755) * (_elapsedjuliandays))) + (3.934e-05) * (cos(2.7441 + (0.01575190938) * (_elapsedjuliandays))) + (3.461e-05) * (cos(2.8289 + (9.64572211e-06) * (_elapsedjuliandays))) + (3.136e-05) * (cos(3.6277 + (0.21276871047) * (_elapsedjuliandays))) + (2.676e-05) * (cos(4.4181 + (0.02152065544) * (_elapsedjuliandays))) + (3.046e-05) * (cos(6.1352 + (0.01076032772) * (_elapsedjuliandays)));

  _eclipticobliquity = 0.409092804039597 + (-6.21395528282155e-09) * (_elapsedjuliandays) + (4.4596737135516e-05) * (cos(2.18295428698789 + (-0.000924169576470094) * (_elapsedjuliandays))) + (-2.78266331083708e-06) * (cos(87.60120254057659 + (-0.0344055570784386) * (_elapsedjuliandays))) + (1.04358121667584e-07) * (cos(167.419645046537 + (-0.06987875019856921) * (_elapsedjuliandays)));

  _sineclipticlongitude = sin(_eclipticlongitude);

  _y = (cos(_eclipticobliquity)) * (_sineclipticlongitude);

  _x = cos(_eclipticlongitude);

  _rightascension = atan2(_y, _x);

  if((_rightascension < 0.0))
  {
    _rightascension = 6.283185307179586 + _rightascension;
  }

  tmp1 = (sin(_eclipticobliquity)) * (_sineclipticlongitude);
  if(!(tmp1 >= -1.0 && tmp1 <= 1.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert(threadData, info, "Model error: Argument of asin(sin(eclipticobliquity) * sineclipticlongitude) outside the domain -1.0 <= %g <= 1.0", tmp1);
  }
  _declination = asin(tmp1);

  _greenwichmeansiderealtime = -60053.302628 + (24.065709825) * (_elapsedjuliandays) + (-0.000292222) * (sin(0.9574 + (0.0009242) * (_elapsedjuliandays)));

  _localmeansiderealtime = (0.0174532925199433) * ((15.0) * (_greenwichmeansiderealtime) + _longitude);

  _hourangle = _localmeansiderealtime - _rightascension;

  _latitudeinradians = (0.0174532925199433) * (_latitude);

  _coslatitude = cos(_latitudeinradians);

  _sinlatitude = sin(_latitudeinradians);

  _coshourangle = cos(_hourangle);

  tmp2 = (_coslatitude) * ((_coshourangle) * (cos(_declination))) + (sin(_declination)) * (_sinlatitude);
  if(!(tmp2 >= -1.0 && tmp2 <= 1.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert(threadData, info, "Model error: Argument of acos(coslatitude * coshourangle * cos(declination) + sin(declination) * sinlatitude) outside the domain -1.0 <= %g <= 1.0", tmp2);
  }
  _zenithangle = acos(tmp2);

  _y = (-sin(_hourangle));

  _x = (tan(_declination)) * (_coslatitude) - ((_sinlatitude) * (_coshourangle));

  _azimuth = atan2(_y, _x);

  if((_azimuth < 0.0))
  {
    _azimuth = 6.283185307179586 + _azimuth;
  }

  _parallax = (4.258756590751381e-05) * (sin(_zenithangle));

  _zenithangle = _zenithangle + _parallax;

  tmp3 = 6.283185307179586;
  if (tmp3 == 0) {throwStreamPrint(threadData, "Division by zero %s", "mod(3.141592653589793 + hourangle, 6.283185307179586)");}
  _hourangle = -3.141592653589793 + modelica_real_mod(3.141592653589793 + _hourangle, tmp3);

  _dec = _declination;

  _hra = _hourangle;
  _return: OMC_LABEL_UNUSED
  if (out_hra) { *out_hra = _hra; }
  return _dec;
}
modelica_metatype boxptr_SolarTherm_Models_Sources_SolarModel__omcQSun_24sun_solarPosition(threadData_t *threadData, modelica_metatype _t, modelica_metatype _lon, modelica_metatype _lat, modelica_metatype _t_zone, modelica_metatype _year, modelica_metatype *out_hra)
{
  modelica_real tmp1;
  modelica_real tmp2;
  modelica_real tmp3;
  modelica_real tmp4;
  modelica_integer tmp5;
  modelica_real _hra;
  modelica_real _dec;
  modelica_metatype out_dec;
  tmp1 = mmc_unbox_real(_t);
  tmp2 = mmc_unbox_real(_lon);
  tmp3 = mmc_unbox_real(_lat);
  tmp4 = mmc_unbox_real(_t_zone);
  tmp5 = mmc_unbox_integer(_year);
  _dec = omc_SolarTherm_Models_Sources_SolarModel__omcQSun_24sun_solarPosition(threadData, tmp1, tmp2, tmp3, tmp4, tmp5, &_hra);
  out_dec = mmc_mk_rcon(_dec);
  if (out_hra) { *out_hra = mmc_mk_rcon(_hra); }
  return out_dec;
}

SolarTherm_Models_Sources_Weather_Metadata omc_SolarTherm_Models_Sources_Weather_Metadata(threadData_t *threadData, modelica_string omc_name, modelica_real omc_lat, modelica_real omc_lon, modelica_real omc_elev, modelica_real omc_tzone, modelica_real omc_tstart)
{
  SolarTherm_Models_Sources_Weather_Metadata tmp1;
  tmp1._name = omc_name;
  tmp1._lat = omc_lat;
  tmp1._lon = omc_lon;
  tmp1._elev = omc_elev;
  tmp1._tzone = omc_tzone;
  tmp1._tstart = omc_tstart;
  return tmp1;
}

modelica_metatype boxptr_SolarTherm_Models_Sources_Weather_Metadata(threadData_t *threadData, modelica_metatype _name, modelica_metatype _lat, modelica_metatype _lon, modelica_metatype _elev, modelica_metatype _tzone, modelica_metatype _tstart)
{
  return mmc_mk_box7(3, &SolarTherm_Models_Sources_Weather_Metadata__desc, _name, _lat, _lon, _elev, _tzone, _tstart);
}

DLLExport
modelica_boolean omc_SolarTherm_Models_Sources_Weather_checkVersion(threadData_t *threadData, modelica_string _file)
{
  modelica_boolean _pass;
  modelica_string _metal = NULL;
  modelica_string _metau = NULL;
  modelica_string _tablel = NULL;
  modelica_string _tableu = NULL;
  modelica_integer _ncol;
  modelica_string _line = NULL;
  modelica_integer _nr;
  modelica_integer _nc;
  modelica_integer _i;
  _tailrecursive: OMC_LABEL_UNUSED
  // _pass has no default value.
  _metal = _OMC_LIT38;
  _metau = _OMC_LIT39;
  _tablel = _OMC_LIT40;
  _tableu = _OMC_LIT41;
  _ncol = ((modelica_integer) 9);
  // _line has no default value.
  // _nr has no default value.
  // _nc has no default value.
  // _i has no default value.
  _pass = (((((stringEqual(omc_Modelica_Utilities_Streams_readLine(threadData, _file, ((modelica_integer) 1), NULL), _OMC_LIT42)) && (stringEqual(omc_Modelica_Utilities_Streams_readLine(threadData, _file, ((modelica_integer) 3), NULL), _OMC_LIT38))) && (stringEqual(omc_Modelica_Utilities_Streams_readLine(threadData, _file, ((modelica_integer) 4), NULL), _OMC_LIT39))) && (stringEqual(omc_Modelica_Utilities_Streams_readLine(threadData, _file, ((modelica_integer) 5), NULL), _OMC_LIT40))) && (stringEqual(omc_Modelica_Utilities_Streams_readLine(threadData, _file, ((modelica_integer) 6), NULL), _OMC_LIT41)));

  if(_pass)
  {
    _line = omc_Modelica_Utilities_Streams_readLine(threadData, _file, ((modelica_integer) 2), NULL);

    _i = omc_Modelica_Utilities_Strings_find(threadData, _line, _OMC_LIT43, ((modelica_integer) 1), 1);

    _nr = omc_Modelica_Utilities_Strings_scanInteger(threadData, _line, ((modelica_integer) 1) + _i, 0, _OMC_LIT20 ,&_i);

    _i = omc_Modelica_Utilities_Strings_find(threadData, _line, _OMC_LIT44, ((modelica_integer) 1), 1);

    _nc = omc_Modelica_Utilities_Strings_scanInteger(threadData, _line, ((modelica_integer) 1) + _i, 0, _OMC_LIT20 ,&_i);

    _pass = (_nc == ((modelica_integer) 9));
  }

  omc_Modelica_Utilities_Streams_close(threadData, _file);
  _return: OMC_LABEL_UNUSED
  return _pass;
}
modelica_metatype boxptr_SolarTherm_Models_Sources_Weather_checkVersion(threadData_t *threadData, modelica_metatype _file)
{
  modelica_boolean _pass;
  modelica_metatype out_pass;
  _pass = omc_SolarTherm_Models_Sources_Weather_checkVersion(threadData, _file);
  out_pass = mmc_mk_icon(_pass);
  return out_pass;
}

DLLExport
SolarTherm_Models_Sources_Weather_Metadata omc_SolarTherm_Models_Sources_Weather_getMetadata(threadData_t *threadData, modelica_string _file)
{
  SolarTherm_Models_Sources_Weather_Metadata _meta;
  modelica_string _line = NULL;
  modelica_integer _i;
  modelica_integer _j;
  static int tmp1 = 0;
  static int tmp2 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  _tailrecursive: OMC_LABEL_UNUSED
  SolarTherm_Models_Sources_Weather_Metadata_construct(threadData, _meta); // _meta has no default value.
  // _line has no default value.
  // _i has no default value.
  // _j has no default value.
  _line = omc_Modelica_Utilities_Streams_readLine(threadData, _file, ((modelica_integer) 7), NULL);

  omc_Modelica_Utilities_Streams_close(threadData, _file);

  _i = omc_Modelica_Utilities_Strings_find(threadData, _line, _OMC_LIT44, ((modelica_integer) 1), 1);

  {
    if(!(_i > ((modelica_integer) 0)))
    {
      tmpMeta[0] = stringAppend(_OMC_LIT45,_file);
      {
        FILE_INFO info = {"/home/cparrado/.openmodelica/libraries/SolarTherm/Models/Sources/Weather/getMetadata.mo",17,2,17,50,0};
        omc_assert(threadData, info, MMC_STRINGDATA(tmpMeta[0]));
      }
    }
  }

  {
    if(!(stringEqual(omc_Modelica_Utilities_Strings_substring(threadData, _line, ((modelica_integer) 1), ((modelica_integer) -1) + _i), _OMC_LIT46)))
    {
      tmpMeta[0] = stringAppend(_OMC_LIT45,_file);
      {
        FILE_INFO info = {"/home/cparrado/.openmodelica/libraries/SolarTherm/Models/Sources/Weather/getMetadata.mo",18,2,19,37,0};
        omc_assert(threadData, info, MMC_STRINGDATA(tmpMeta[0]));
      }
    }
  }

  _j = omc_Modelica_Utilities_Strings_find(threadData, _line, _OMC_LIT44, ((modelica_integer) 1) + _i, 1);

  _meta._name = omc_Modelica_Utilities_Strings_substring(threadData, _line, ((modelica_integer) 1) + _i, ((modelica_integer) -1) + _j);

  tmpMeta[0] = stringAppend(_OMC_LIT45,_file);
  _meta._lat = omc_Modelica_Utilities_Strings_scanReal(threadData, _line, ((modelica_integer) 1) + _j, 0, tmpMeta[0] ,&_j);

  tmpMeta[0] = stringAppend(_OMC_LIT45,_file);
  _meta._lon = omc_Modelica_Utilities_Strings_scanReal(threadData, _line, ((modelica_integer) 1) + _j, 0, tmpMeta[0] ,&_j);

  tmpMeta[0] = stringAppend(_OMC_LIT45,_file);
  _meta._elev = omc_Modelica_Utilities_Strings_scanReal(threadData, _line, ((modelica_integer) 1) + _j, 0, tmpMeta[0] ,&_j);

  tmpMeta[0] = stringAppend(_OMC_LIT45,_file);
  _meta._tzone = omc_Modelica_Utilities_Strings_scanReal(threadData, _line, ((modelica_integer) 1) + _j, 0, tmpMeta[0] ,&_j);

  tmpMeta[0] = stringAppend(_OMC_LIT45,_file);
  _meta._tstart = omc_Modelica_Utilities_Strings_scanReal(threadData, _line, ((modelica_integer) 1) + _j, 0, tmpMeta[0] ,&_j);
  _return: OMC_LABEL_UNUSED
  return _meta;
}
modelica_metatype boxptr_SolarTherm_Models_Sources_Weather_getMetadata(threadData_t *threadData, modelica_metatype _file)
{
  SolarTherm_Models_Sources_Weather_Metadata _meta;
  modelica_metatype out_meta;
  modelica_metatype tmpMeta[6] __attribute__((unused)) = {0};
  _meta = omc_SolarTherm_Models_Sources_Weather_getMetadata(threadData, _file);
  /* skip box _meta._name; String */
  tmpMeta[1] = mmc_mk_rcon(_meta._lat);
  tmpMeta[2] = mmc_mk_rcon(_meta._lon);
  tmpMeta[3] = mmc_mk_rcon(_meta._elev);
  tmpMeta[4] = mmc_mk_rcon(_meta._tzone);
  tmpMeta[5] = mmc_mk_rcon(_meta._tstart);
  out_meta = mmc_mk_box7(3, &SolarTherm_Models_Sources_Weather_Metadata__desc, _meta._name, tmpMeta[1], tmpMeta[2], tmpMeta[3], tmpMeta[4], tmpMeta[5]);
  return out_meta;
}

DLLExport
modelica_string omc_SolarTherm_Models_Sources_Weather_weatherFileChecker(threadData_t *threadData, modelica_string _file)
{
  modelica_string _file_name = NULL;
  modelica_string _dir = NULL;
  modelica_string _name = NULL;
  modelica_string _ext = NULL;
  modelica_integer _result;
  static int tmp1 = 0;
  static int tmp2 = 0;
  static int tmp3 = 0;
  modelica_metatype tmpMeta[2] __attribute__((unused)) = {0};
  _tailrecursive: OMC_LABEL_UNUSED
  // _file_name has no default value.
  // _dir has no default value.
  // _name has no default value.
  // _ext has no default value.
  // _result has no default value.
  _dir = omc_Modelica_Utilities_Files_splitPathName(threadData, _file ,&_name ,&_ext);

  if((stringEqual(_ext, _OMC_LIT49)))
  {
    {
      if(!omc_SolarTherm_Models_Sources_Weather_checkVersion(threadData, _file))
      {
        tmpMeta[0] = stringAppend(_OMC_LIT51,_file);
        {
          FILE_INFO info = {"/home/cparrado/.openmodelica/libraries/SolarTherm/Models/Sources/Weather/weatherFileChecker.mo",15,3,16,52,0};
          omc_assert(threadData, info, MMC_STRINGDATA(tmpMeta[0]));
        }
      }
    }

    _file_name = _file;
  }
  else
  {
    tmpMeta[0] = stringAppend(_OMC_LIT47,_file);
    _result = omc_Modelica_Utilities_System_command(threadData, tmpMeta[0]);

    {
      if(!(_result == ((modelica_integer) 0)))
      {
        tmpMeta[0] = stringAppend(_OMC_LIT48,_file);
        {
          FILE_INFO info = {"/home/cparrado/.openmodelica/libraries/SolarTherm/Models/Sources/Weather/weatherFileChecker.mo",20,3,20,64,0};
          omc_assert(threadData, info, MMC_STRINGDATA(tmpMeta[0]));
        }
      }
    }

    tmpMeta[0] = stringAppend(_dir,_name);
    tmpMeta[1] = stringAppend(tmpMeta[0],_OMC_LIT49);
    _file_name = tmpMeta[1];

    {
      if(!omc_SolarTherm_Models_Sources_Weather_checkVersion(threadData, _file_name))
      {
        tmpMeta[0] = stringAppend(_OMC_LIT50,_file_name);
        {
          FILE_INFO info = {"/home/cparrado/.openmodelica/libraries/SolarTherm/Models/Sources/Weather/weatherFileChecker.mo",22,3,23,16,0};
          omc_assert(threadData, info, MMC_STRINGDATA(tmpMeta[0]));
        }
      }
    }
  }
  _return: OMC_LABEL_UNUSED
  return _file_name;
}

SolarTherm_Models_Storage_Tank__omcQTank_24tankCold_Medium_ThermodynamicState omc_SolarTherm_Models_Storage_Tank__omcQTank_24tankCold_Medium_ThermodynamicState(threadData_t *threadData, modelica_real omc_p, modelica_real omc_h)
{
  SolarTherm_Models_Storage_Tank__omcQTank_24tankCold_Medium_ThermodynamicState tmp1;
  tmp1._p = omc_p;
  tmp1._h = omc_h;
  return tmp1;
}

modelica_metatype boxptr_SolarTherm_Models_Storage_Tank__omcQTank_24tankCold_Medium_ThermodynamicState(threadData_t *threadData, modelica_metatype _p, modelica_metatype _h)
{
  return mmc_mk_box3(3, &SolarTherm_Models_Storage_Tank__omcQTank_24tankCold_Medium_ThermodynamicState__desc, _p, _h);
}

SolarTherm_Models_Storage_Tank__omcQTank_24tankHot_Medium_ThermodynamicState omc_SolarTherm_Models_Storage_Tank__omcQTank_24tankHot_Medium_ThermodynamicState(threadData_t *threadData, modelica_real omc_p, modelica_real omc_h)
{
  SolarTherm_Models_Storage_Tank__omcQTank_24tankHot_Medium_ThermodynamicState tmp1;
  tmp1._p = omc_p;
  tmp1._h = omc_h;
  return tmp1;
}

modelica_metatype boxptr_SolarTherm_Models_Storage_Tank__omcQTank_24tankHot_Medium_ThermodynamicState(threadData_t *threadData, modelica_metatype _p, modelica_metatype _h)
{
  return mmc_mk_box3(3, &SolarTherm_Models_Storage_Tank__omcQTank_24tankHot_Medium_ThermodynamicState__desc, _p, _h);
}

#ifdef __cplusplus
}
#endif
