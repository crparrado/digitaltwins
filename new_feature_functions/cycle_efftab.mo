model cycle_efftab

  import SI = Modelica.SIunits;
  
  parameter String file "File where optical data matrix is stored";
  
  input Modelica.Blocks.RealInput t_amb;
  input Modelica.Blocks.RealInput load_perc; 
  
  SI.Temp_C temperature_ambient "Ambient Temperature in (°C)";
  Real load_percentage "Load Percentage (%)";
  SI.Power out_load;

  Modelica.Blocks.Tables.CombiTable2D cycle_eff_tab(
  tableOnFile=true,
  tableName="cycle_efficiency_table",
  smoothness=Modelica.Blocks.Types.Smoothness.ContinuousDerivative,
  fileName=file);
  
equation
  connect(temperature_ambient, cycle_eff_tab.u2);
  connect(load_percentage, cycle_eff_tab.u1);
  
  out_load = max(0,cycle_eff_tab.y);
  
  connect(t_amb, temperature_ambient);
  connect(load_perc, load_percentage);
  
end cycle_efftab;