model rankine_cycle_efftab "define la eficiencia de la turbina de rankine acorde a la temperatura ambiente y el porcentaje de carga (load percentage)"
  
  import SI = Modelica.SIunits;
  
  parameter String file = "/home/karbo/AAA_PROYECTOS/csp/sunaicl-solartherm/SolarTherm/new_feature_functions/acciona_tables/motab_acciona/rankine_eff.motab" ".motab file with rankine cycle efficiency data";
  parameter String table_name = "rankine_eff";
  Modelica.Blocks.Interfaces.RealInput in_t_amb annotation(
    Placement(visible = true, transformation(origin = {-90, -50}, extent = {{-10, -10}, {10, 10}}, rotation = 0), iconTransformation(origin = {-90, -50},extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Interfaces.RealInput in_load_perc annotation(
    Placement(visible = true, transformation(origin = {-88, 50}, extent = {{-10, -10}, {10, 10}}, rotation = 0), iconTransformation(origin = {-88, 50},extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  //SI.Temp_C temperature_ambient "Ambient Temperature in (°C)"; // invalid connector  :(
  //Real load_percentage "Load Percentage (%)"; // invalid connector  :(
  
  Modelica.Blocks.Interfaces.RealOutput out_rankine_eff annotation(
    Placement(visible = true, transformation(origin = {90, 10}, extent = {{-10, -10}, {10, 10}}, rotation = 0), iconTransformation(origin = {90, 10},extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  //Real rankine_eff; // invalid connector  :(
  
  Modelica.Blocks.Tables.CombiTable2D rankine_eff_tab(
    tableOnFile = true, 
    tableName = table_name, 
    smoothness = Modelica.Blocks.Types.Smoothness.ContinuousDerivative, 
    fileName = file);

equation
  connect(in_t_amb, rankine_eff_tab.u2) annotation(
    Line);
  connect(in_load_perc, rankine_eff_tab.u1);
  
  out_rankine_eff = max(0, rankine_eff_tab.y);
  //connect(rankine_eff,out_rankine_eff); // invalid connector  :(
  //connect(in_t_amb, t_amb); // invalid connector  :(
  //connect(in_load_perc, load_perc); // invalid connector  :(
  
annotation(
    Diagram);
end rankine_cycle_efftab;