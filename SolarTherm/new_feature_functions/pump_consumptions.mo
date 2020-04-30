model pump_consumptions "define los consumos de cada bomba"
  
  import SI = Modelica.SIunits;
  // data consumo de: bomba de sales frias (Cold Pump)
  parameter String cons_cold_pump_file = "/home/karbo/AAA_PROYECTOS/csp/sunaicl-solartherm/SolarTherm/new_feature_functions/acciona_tables/motab_acciona/pump_cons/cold_pump.motab";
  parameter String cons_cold_pump_table_name = "cons_cold_pump";
  // data de consumo de: bomba de sales calientes (Hot Pump)
  parameter String cons_hot_pump_file = "/home/karbo/AAA_PROYECTOS/csp/sunaicl-solartherm/SolarTherm/new_feature_functions/acciona_tables/motab_acciona/pump_cons/hot_pump.motab";
  parameter String cons_hot_pump_table_name = "cons_hot_pump";
  // data de consumo de: bomba de atemperacion de sales (?) (Attemperation Pumps)
  parameter String cons_attemperation_pump_file = "/home/karbo/AAA_PROYECTOS/csp/sunaicl-solartherm/SolarTherm/new_feature_functions/acciona_tables/motab_acciona/pump_cons/attemperation_pump.motab";
  parameter String cons_attemperation_pump_table_name = "cons_attemperation_pump";
  
  Modelica.Blocks.Interfaces.RealInput in_flow_hot annotation(
    Placement(visible = true, transformation(origin = {-80, 80}, extent = {{-10, -10}, {10, 10}}, rotation = 0), iconTransformation(origin = {-90, 80},extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Interfaces.RealInput in_flow_cold annotation(
    Placement(visible = true, transformation(origin = {-80, 0}, extent = {{-10, -10}, {10, 10}}, rotation = 0), iconTransformation(origin = {-90, 0},extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Interfaces.RealInput in_flow_attemperation annotation(
    Placement(visible = true, transformation(origin = {-80, -80}, extent = {{-10, -10}, {10, 10}}, rotation = 0), iconTransformation(origin = {-90, -80},extent = {{-10, -10}, {10, 10}}, rotation = 0)));

  Modelica.Blocks.Interfaces.RealOutput cons_hot_out annotation(
    Placement(visible = true, transformation(origin = {90, 80}, extent = {{-10, -10}, {10, 10}}, rotation = 0), iconTransformation(origin = {110, 80},extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Interfaces.RealOutput cons_cold_out annotation(
    Placement(visible = true, transformation(origin = {90, 0}, extent = {{-10, -10}, {10, 10}}, rotation = 0), iconTransformation(origin = {110, 0},extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Interfaces.RealOutput cons_attemperation_out annotation(
    Placement(visible = true, transformation(origin = {90, -80}, extent = {{-10, -10}, {10, 10}}, rotation = 0), iconTransformation(origin = {110, -80},extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  
  Modelica.Blocks.Tables.CombiTable1Ds cons_cold_pump_tab(
    tableOnFile = true,
    tableName = cons_cold_pump_table_name, 
    smoothness = Modelica.Blocks.Types.Smoothness.ContinuousDerivative, 
    fileName = cons_cold_pump_file);

  Modelica.Blocks.Tables.CombiTable1Ds cons_hot_pump_tab(
    tableOnFile = true,
    tableName = cons_hot_pump_table_name, 
    smoothness = Modelica.Blocks.Types.Smoothness.ContinuousDerivative, 
    fileName = cons_hot_pump_file);

  Modelica.Blocks.Tables.CombiTable1Ds cons_attemperation_pump_tab(
    tableOnFile = true,
    tableName = cons_attemperation_pump_table_name, 
    smoothness = Modelica.Blocks.Types.Smoothness.ContinuousDerivative, 
    fileName = cons_attemperation_pump_file);

equation
  connect(in_flow_hot, cons_hot_pump_tab.u) annotation(
    Line);
  connect(in_flow_cold, cons_cold_pump_tab.u) annotation(
    Line);
  connect(in_flow_attemperation, cons_attemperation_pump_tab.u) annotation(
    Line);
  
  connect(cons_hot_out, cons_hot_pump_tab.y[1]) annotation(
    Line);
  connect(cons_cold_out, cons_cold_pump_tab.y[1]) annotation(
    Line);
  connect(cons_attemperation_out, cons_attemperation_pump_tab.y[1]) annotation(
    Line);

end pump_consumptions;