model bop_auxloadtab "define la eficiencia de la turbina de rankine acorde a la temperatura ambiente y el porcentaje de carga (load percentage)"
  
  import SI = Modelica.SIunits;
  
  // data de matriz de consumo e:n operacion normal funcion de (%carga, t_amb)
  parameter String bop_auxload_matrix_file = "/home/karbo/AAA_PROYECTOS/csp/sunaicl-solartherm/SolarTherm/new_feature_functions/acciona_tables/motab_acciona/aux_loads/bop_auxload_matrix.motab" ".motab file with auxiliary load matrix data";
  parameter String bop_auxload_matrix_table_name = "bop_auxload_matrix";
  // data consumo en: synchronization and auxiliary steam
  parameter String cons_auxsteam_synchro_file = "/home/karbo/AAA_PROYECTOS/csp/sunaicl-solartherm/SolarTherm/new_feature_functions/acciona_tables/motab_acciona/aux_loads/cons_auxsteam_synchro.motab";
  parameter String cons_auxsteam_synchro_table_name = "cons_auxsteam_synchro";
  // data de consumo en: longterm hold
  parameter String cons_longtermhold_file = "/home/karbo/AAA_PROYECTOS/csp/sunaicl-solartherm/SolarTherm/new_feature_functions/acciona_tables/motab_acciona/aux_loads/cons_longtermhold.motab";
  parameter String cons_longtermhold_table_name = "cons_longtermhold";
  // data de consumo en: overnight hold
  parameter String cons_overnighthold_file = "/home/karbo/AAA_PROYECTOS/csp/sunaicl-solartherm/SolarTherm/new_feature_functions/acciona_tables/motab_acciona/aux_loads/cons_overnighthold.motab";
  parameter String cons_overnighthold_table_name = "cons_overnighthold";
  // data de consumo en: preheating
  parameter String cons_preheating_file = "/home/karbo/AAA_PROYECTOS/csp/sunaicl-solartherm/SolarTherm/new_feature_functions/acciona_tables/motab_acciona/aux_loads/cons_preheating.motab";
  parameter String cons_preheating_table_name = "cons_preheating";
  
  Modelica.Blocks.Interfaces.IntegerInput in_state annotation(
    Placement(visible = true, transformation(origin = {0, 88}, extent = {{-8, -8}, {8, 8}}, rotation = -90), iconTransformation(origin = {0, 90},extent = {{-10, -10}, {10, 10}}, rotation = -90))); 
  
  Modelica.Blocks.Interfaces.RealInput in_t_amb annotation(
    Placement(visible = true, transformation(origin = {-90, -50}, extent = {{-10, -10}, {10, 10}}, rotation = 0), iconTransformation(origin = {-90, -50},extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Interfaces.RealInput in_load_perc annotation(
    Placement(visible = true, transformation(origin = {-88, 50}, extent = {{-10, -10}, {10, 10}}, rotation = 0), iconTransformation(origin = {-88, 50},extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  //Real t_amb "Ambient Temperature in (°C)"; // invalid connector  :(
  //Real load_perc "Load Percentage (%)"; // invalid connector  :(
  
  //SI.Power load_out; // invalid connector  :(
  Modelica.Blocks.Interfaces.RealOutput out_load_out annotation(
    Placement(visible = true, transformation(origin = {90, 10}, extent = {{-10, -10}, {10, 10}}, rotation = 0), iconTransformation(origin = {90, 10},extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  
  Modelica.Blocks.Tables.CombiTable2D bop_auxload_matrix_tab(
    tableOnFile = true, 
    tableName = bop_auxload_matrix_table_name, 
    smoothness = Modelica.Blocks.Types.Smoothness.ContinuousDerivative, 
    fileName = bop_auxload_matrix_file);
    
  Modelica.Blocks.Tables.CombiTable1Ds cons_auxsteam_synchro_tab(
    tableOnFile = true,
    tableName = cons_auxsteam_synchro_table_name, 
    smoothness = Modelica.Blocks.Types.Smoothness.ContinuousDerivative, 
    fileName = cons_auxsteam_synchro_file);
    
  Modelica.Blocks.Tables.CombiTable1Ds cons_longtermhold_tab(
    tableOnFile = true,
    tableName = cons_longtermhold_table_name, 
    smoothness = Modelica.Blocks.Types.Smoothness.ContinuousDerivative, 
    fileName = cons_longtermhold_file);

  Modelica.Blocks.Tables.CombiTable1Ds cons_overnighthold_tab(
    tableOnFile = true,
    tableName = cons_overnighthold_table_name, 
    smoothness = Modelica.Blocks.Types.Smoothness.ContinuousDerivative, 
    fileName = cons_overnighthold_file);

  Modelica.Blocks.Tables.CombiTable1Ds cons_preheating_tab(
    tableOnFile = true,
    tableName = cons_preheating_table_name, 
    smoothness = Modelica.Blocks.Types.Smoothness.ContinuousDerivative, 
    fileName = cons_preheating_file);

algorithm
  if in_state == 1 then // state 1: auxiliary steam and synchronization
    out_load_out := max(0, cons_auxsteam_synchro_tab.y[1]);
  elseif in_state == 2 then // state 2: long term hold
    out_load_out := max(0, cons_longtermhold_tab.y[1]);
  elseif in_state == 3 then // state 3: overnight hold
    out_load_out := max(0, cons_overnighthold_tab.y[1]);
  elseif in_state == 4 then // state 4: preheating
    out_load_out := max(0, cons_preheating_tab.y[1]);
  else // state [any other value]: normal operation
    out_load_out := max(0, bop_auxload_matrix_tab.y);
  end if;

equation
  //connect(in_t_amb, t_amb); // invalid connector  :(
  //connect(in_load_perc, load_perc) // invalid connector  :(

  connect(in_t_amb, bop_auxload_matrix_tab.u2);
  connect(in_load_perc, bop_auxload_matrix_tab.u1);
  
  connect(in_t_amb, cons_auxsteam_synchro_tab.u);
  connect(in_t_amb, cons_longtermhold_tab.u);
  connect(in_t_amb, cons_overnighthold_tab.u);
  connect(in_t_amb, cons_preheating_tab.u);
  
annotation(
    Diagram);
end bop_auxloadtab;