model test_tablefuncs
  receiver_perftab rec_eff annotation(
    Placement(visible = true, transformation(origin = {-16, 80}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  rankine_cycle_efftab rankine_eff annotation(
    Placement(visible = true, transformation(origin = {-16, -14}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  bop_auxloadtab aux_load annotation(
    Placement(visible = true, transformation(origin = {-16, -86}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.RealExpression inc_power(y = 700)  annotation(
    Placement(visible = true, transformation(origin = {-82, 90}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.RealExpression wspd(y = 7)  annotation(
    Placement(visible = true, transformation(origin = {-82, 70}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.RealExpression load_perc(y = 50)  annotation(
    Placement(visible = true, transformation(origin = {-86, -44}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.RealExpression t_amb(y = 20)  annotation(
    Placement(visible = true, transformation(origin = {-86, -60}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.IntegerExpression state_loads(y = 0)  annotation(
    Placement(visible = true, transformation(origin = {-32, -62}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  pump_consumptions pump_cons annotation(
    Placement(visible = true, transformation(origin = {-14, 28}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.RealExpression mass_flow(y = 1000) annotation(
    Placement(visible = true, transformation(origin = {-84, 28}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
equation
  connect(inc_power.y, rec_eff.in_inc_power) annotation(
    Line(points = {{-71, 90}, {-45.5, 90}, {-45.5, 85}, {-25, 85}}, color = {0, 0, 127}));
  connect(wspd.y, rec_eff.in_wspd) annotation(
    Line(points = {{-71, 70}, {-39.5, 70}, {-39.5, 75}, {-25, 75}}, color = {0, 0, 127}));
  connect(t_amb.y, rankine_eff.in_t_amb) annotation(
    Line(points = {{-75, -60}, {-62, -60}, {-62, -22}, {-25, -22}, {-25, -19}}, color = {0, 0, 127}));
  connect(load_perc.y, rankine_eff.in_load_perc) annotation(
    Line(points = {{-75, -44}, {-58, -44}, {-58, -9}, {-25, -9}}, color = {0, 0, 127}));
  connect(t_amb.y, aux_load.in_t_amb) annotation(
    Line(points = {{-75, -60}, {-62, -60}, {-62, -92}, {-25, -92}, {-25, -91}}, color = {0, 0, 127}));
  connect(load_perc.y, aux_load.in_load_perc) annotation(
    Line(points = {{-75, -44}, {-58, -44}, {-58, -81}, {-25, -81}}, color = {0, 0, 127}));
  connect(state_loads.y, aux_load.in_state) annotation(
    Line(points = {{-21, -62}, {-16, -62}, {-16, -77}}, color = {255, 127, 0}));
  connect(mass_flow.y, pump_cons.in_flow_hot) annotation(
    Line(points = {{-72, 28}, {-58, 28}, {-58, 36}, {-23, 36}}, color = {0, 0, 127}));
  connect(mass_flow.y, pump_cons.in_flow_cold) annotation(
    Line(points = {{-72, 28}, {-23, 28}}, color = {0, 0, 127}));
  connect(mass_flow.y, pump_cons.in_flow_attemperation) annotation(
    Line(points = {{-72, 28}, {-58, 28}, {-58, 20}, {-23, 20}}, color = {0, 0, 127}));
protected
  annotation(
    uses(Modelica(version = "3.2.2")));
end test_tablefuncs;