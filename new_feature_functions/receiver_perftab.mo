model receiver_perftab

  import SI = Modelica.SIunits;
  
  parameter String file "File where optical data matrix is stored";
  
  input Modelica.Blocks.RealInput wspd;
  input Modelica.Blocks.RealInput inc_pow; 
  
  SI.Velocity wind_speed "incident wind speed in (m/s)";
  SI.Power incident_power "incident thermal  power in (W)";

  Modelica.Blocks.Tables.CombiTable2D rec_perf_tab(
  tableOnFile=true,
  tableName="receiver_performance_table",
  smoothness=Modelica.Blocks.Types.Smoothness.ContinuousDerivative,
  fileName=file);
  
equation
  connect(wind_speed, rec_perf_tab.u2);
  connect(incident_power, rec_perf_tab.u1);
  nu = max(0,rec_perf_tab.y);
  
  connect(wspd, wind_speed);
  connect(inc_pow, incident_power);
  
end receiver_perftab;