model receiver_perftab "define la eficiencia del recibidor termico acorde a la velocidad del viento y la potencia incidente)"

  import SI = Modelica.SIunits;
  
  parameter String file = "/home/karbo/AAA_PROYECTOS/csp/sunaicl-solartherm/SolarTherm/new_feature_functions/acciona_tables/motab_acciona/rec_perf.motab" ".motab file with rankine cycle efficiency data";
  parameter String table_name = "rec_perf";
  Modelica.Blocks.Interfaces.RealInput in_wspd annotation(
    Placement(visible = true, transformation(origin = {-90, -50}, extent = {{-10, -10}, {10, 10}}, rotation = 0), iconTransformation(origin = {-90, -50},extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Interfaces.RealInput in_inc_power annotation(
    Placement(visible = true, transformation(origin = {-88, 50}, extent = {{-10, -10}, {10, 10}}, rotation = 0), iconTransformation(origin = {-88, 50},extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  //SI.Velocity wspd "incident wind speed in (m/s)"; // invalid connector  :(
  //SI.Power inc_power "incident thermal  power in (MWt)"; // invalid connector  :(
  
  Modelica.Blocks.Interfaces.RealOutput out_rec_perf annotation(
    Placement(visible = true, transformation(origin = {90, 10}, extent = {{-10, -10}, {10, 10}}, rotation = 0), iconTransformation(origin = {90, 10},extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  //Real rec_perf;
  
  Modelica.Blocks.Tables.CombiTable2D rec_perf_tab(
    tableOnFile=true,
    tableName=table_name,
    smoothness=Modelica.Blocks.Types.Smoothness.ContinuousDerivative,
    fileName=file);

equation
  connect(in_wspd, rec_perf_tab.u2);
  connect(in_inc_power, rec_perf_tab.u1);
  
  out_rec_perf = max(0,rec_perf_tab.y);
  //connect(rec_perf,out_rec_perf);  // invalid connector  :(
  
  //connect(in_wspd, wspd); // invalid connector  :(
  //connect(in_inc_power, inc_power); // invalid connector  :(
  
annotation(
    Diagram);

end receiver_perftab;