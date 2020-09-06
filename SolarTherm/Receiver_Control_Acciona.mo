within SolarTherm;

model Receiver_Control_Acciona
  extends Icons.Control;
  parameter SI.Temperature T_ref = from_degC(570) "Setpoint of temperature";
  parameter SI.MassFlowRate m_flow_max = 1400 "Maximum mass flow rate";
  parameter SI.MassFlowRate m_flow_min = 0 "Mass flow rate when control off";
  parameter Real L_on = 30 "Level of start discharge";
  parameter Real L_off = 10 "Level of stop discharge";
  parameter Real L_df_on = 99 "Level of start defocus";
  parameter Real L_df_off = 96 "Level of stop defocus";
  parameter Real y_start = 300 "Initial value of output";
  parameter Real Ti = 1 "Integer constant";
  parameter Real Kp = -10 "Proportional constant";
  Modelica.Blocks.Interfaces.RealInput level_hot annotation(
    Placement(visible = true, transformation(extent = {{-18, 76}, {22, 116}}, rotation = 0), iconTransformation(origin = {78, 100}, extent = {{-20, -20}, {20, 20}}, rotation = -90)));
  Modelica.Blocks.Interfaces.RealInput level_cold annotation(
    Placement(visible = true, transformation(extent = {{-126, 68}, {-86, 108}}, rotation = 0), iconTransformation(extent = {{-126, 62}, {-86, 102}}, rotation = 0)));
  Modelica.Blocks.Interfaces.RealInput Sun_elev annotation(
    Placement(visible = true, transformation(extent = {{-76, 74}, {-36, 114}}, rotation = 0), iconTransformation(origin = {20, 102}, extent = {{-20, -20}, {20, 20}}, rotation = -90)));
  Modelica.Blocks.Interfaces.RealInput Recpower(final quantity = "Power", final unit = "MW", displayUnit = "MW", min = 0) annotation(
    Placement(visible = true, transformation(extent = {{32, 78}, {72, 118}}, rotation = 0), iconTransformation(origin = {-34, 100}, extent = {{-20, -20}, {20, 20}}, rotation = -90)));
  Modelica.Blocks.Logical.Switch switch annotation(
    Placement(visible = true, transformation(extent = {{54, -4}, {66, 8}}, rotation = 0)));
  Modelica.Blocks.Sources.RealExpression m_flow_off_input(y = 0) annotation(
    Placement(transformation(extent = {{6, -34}, {32, -10}})));
  //  Modelica.Blocks.Interfaces.RealInput L_mea
  //    annotation (Placement(visible = true, transformation(extent = {{-128, -20}, {-88, 20}}, rotation = 0), iconTransformation(extent = {{-126, -38}, {-86, 2}}, rotation = 0)));
  Modelica.Blocks.Interfaces.RealOutput m_flow annotation(
    Placement(transformation(extent = {{94, -18}, {130, 18}})));
  Modelica.Blocks.Interfaces.BooleanInput sf_on annotation(
    Placement(visible = true, transformation(extent = {{-130, -80}, {-90, -40}}, rotation = 0), iconTransformation(extent = {{-130, -80}, {-90, -40}}, rotation = 0)));
  //  Modelica.Blocks.Interfaces.RealInput T_mea
  //    annotation (Placement(visible = true, transformation(extent = {{-130, 22}, {-90, 62}}, rotation = 0), iconTransformation(extent = {{-126, 12}, {-86, 52}}, rotation = 0)));
  Modelica.Blocks.Logical.And and1 annotation(
    Placement(transformation(extent = {{-34, -22}, {-14, -2}})));
  Modelica.Blocks.Interfaces.BooleanOutput defocus annotation(
    Placement(transformation(extent = {{-20, -20}, {20, 20}}, rotation = -90, origin = {0, -114})));
  SolarTherm.Level2Logic_Acciona hot_tank_logic(level_max = 10.2, level_min = 10) annotation(
    Placement(visible = true, transformation(origin = {-64, 0}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  SolarTherm.Level2Logic_Acciona defocus_logic(level_max = L_df_off, level_min = L_df_on) annotation(
    Placement(visible = true, transformation(origin = {-20, -44}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  SolarTherm.Control_Cold_Tank control_Cold_Tank annotation(
    Placement(visible = true, transformation(origin = {-16, 42}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Logical.Not not1 annotation(
    Placement(visible = true, transformation(origin = {0, -74}, extent = {{-6, -6}, {6, 6}}, rotation = -90)));
equation
  connect(m_flow_off_input.y, switch.u3) annotation(
    Line(points = {{33.3, -22}, {44, -22}, {44, -3}, {53, -3}}, color = {0, 0, 127}));
  connect(and1.y, switch.u2) annotation(
    Line(points = {{-13, -12}, {-6, -12}, {-6, 2}, {53, 2}}, color = {255, 0, 255}));
  connect(and1.u2, sf_on) annotation(
    Line(points = {{-36, -20}, {-64, -20}, {-64, -60}, {-110, -60}}, color = {255, 0, 255}));
  connect(switch.y, m_flow) annotation(
    Line(points = {{67, 2}, {89.3, 2}, {89.3, 0}, {112, 0}}, color = {0, 0, 127}));
//  connect(L_mea, hot_tank_logic.level_ref) annotation(
//    Line(points = {{-108, 0}, {-74, 0}}, color = {0, 0, 127}));
  connect(hot_tank_logic.y, and1.u1) annotation(
    Line(points = {{-54, 0}, {-46, 0}, {-46, -12}, {-36, -12}, {-36, -12}}, color = {255, 0, 255}));
//  connect(L_mea, defocus_logic.level_ref) annotation(
//    Line(points = {{-108, 0}, {-82, 0}, {-82, -44}, {-30, -44}, {-30, -44}}, color = {0, 0, 127}));
  connect(level_cold, hot_tank_logic.level_ref) annotation(
    Line(points = {{-106, 88}, {-80, 88}, {-80, 0}, {-74, 0}, {-74, 0}}, color = {0, 0, 127}));
  connect(level_cold, defocus_logic.level_ref) annotation(
    Line(points = {{-106, 88}, {-80, 88}, {-80, -44}, {-30, -44}, {-30, -44}}, color = {0, 0, 127}));
  connect(control_Cold_Tank.m_flow_cold, switch.u1) annotation(
    Line(points = {{-4, 36}, {42, 36}, {42, 6}, {53, 6}, {53, 7}}, color = {0, 0, 127}));
  connect(Recpower, control_Cold_Tank.Recpower) annotation(
    Line(points = {{52, 98}, {66, 98}, {66, 56}, {-40, 56}, {-40, 50}, {-26, 50}, {-26, 50}}, color = {0, 0, 127}));
  connect(Sun_elev, control_Cold_Tank.Sun_elev) annotation(
    Line(points = {{-56, 94}, {-32, 94}, {-32, 66}, {-48, 66}, {-48, 44}, {-26, 44}, {-26, 44}}, color = {0, 0, 127}));
  connect(level_hot, control_Cold_Tank.level_hot) annotation(
    Line(points = {{2, 96}, {24, 96}, {24, 50}, {-58, 50}, {-58, 40}, {-26, 40}, {-26, 40}}, color = {0, 0, 127}));
  connect(level_cold, control_Cold_Tank.level_cold) annotation(
    Line(points = {{-106, 88}, {-72, 88}, {-72, 34}, {-26, 34}, {-26, 34}}, color = {0, 0, 127}));
  connect(defocus_logic.y, not1.u) annotation(
    Line(points = {{-10, -44}, {0, -44}, {0, -66}, {0, -66}}, color = {255, 0, 255}));
  connect(not1.y, defocus) annotation(
    Line(points = {{0, -80.6}, {0, -114}}, color = {255, 0, 255}));
  annotation(
    Documentation(revisions = "<html>
<ul>
<li>Alberto de la Calle:<br>Released first version. </li>
</ul>
</html>"));
end Receiver_Control_Acciona;