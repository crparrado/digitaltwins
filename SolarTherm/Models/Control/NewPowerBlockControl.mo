within SolarTherm.Models.Control;

model NewPowerBlockControl
  extends SolarTherm.Icons.Control;
  parameter Modelica.SIunits.MassFlowRate m_flow_on = 1400 "Constant mass flow rate on";
  parameter Modelica.SIunits.MassFlowRate m_flow_off = 0 "Constant mass flow rate off";
  parameter Real L_on = 90 "Level of start discharge";
  parameter Real L_off = 10 "Level of stop discharge";
  parameter Real L_df_on = 99 "Level of start defocus";
  parameter Real L_df_off = 96 "Level of stop defocus";
  parameter Real m_flow_max = 1000 "Maximum flow to the power block";
  parameter Real m_flow_min = 0 "Minimum flow to the power block";
  parameter Real y_start = 300 "Initial value of output";
  parameter Real Ti = 1 "Integer constant";
  parameter Real Kp = -10 "Proportional constant";
  parameter SI.Temperature T_ref = from_degC(570) "Setpoint of temperature";

  Modelica.Blocks.Interfaces.RealInput L_mea annotation(
    Placement(transformation(extent = {{-128, -70}, {-88, -30}})));

  Modelica.Blocks.Interfaces.RealOutput m_flow annotation(
    Placement(transformation(extent = {{92, -20}, {132, 20}})));

  Modelica.Blocks.Interfaces.RealOutput m_pump2 annotation(
    Placement(visible = true, transformation(extent = {{92, 32}, {132, 72}}, rotation = 0), 
    iconTransformation(extent = {{92, 32}, {132, 72}}, rotation = 0)));

  Modelica.Blocks.Interfaces.RealOutput m_tank2 annotation(
    Placement(visible = true, transformation(extent = {{92, -75}, {132, -35}}, rotation = 0), 
    iconTransformation(extent = {{92, -75}, {132, -35}}, rotation = 0)));

  Modelica.Blocks.Sources.RealExpression m_pump_2(y = 0.001) annotation(
    Placement(visible = false, transformation(origin = {51, -55}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));

  Modelica.Blocks.Sources.RealExpression m_tank_2(y = 0.001) annotation(
    Placement(visible = false, transformation(origin = {51, 52}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));

  SolarTherm.Models.Control.Level2Logic defocus_logic(
    y(start = false), 
    level_max = L_df_on, 
    level_min = L_df_off) annotation(
    Placement(transformation(extent = {{-17, -10}, {17, 10}}, rotation = -90, origin = {0, -51})));

  Modelica.Blocks.Interfaces.BooleanOutput defocus annotation(
    Placement(transformation(extent = {{20, -20}, {-20, 20}}, rotation = 90, origin = {0, -114})));

  Modelica.Blocks.Interfaces.RealInput m_flow_in annotation(
    Placement(transformation(extent = {{-20, -20}, {20, 20}}, rotation = 0, origin = {-108, 50})));

  SolarTherm.Models.Control.NewStartUpLogic5 logic(
    m_flow_max = m_flow_on, 
    m_flow_startup = m_flow_on / 2, 
    level_on = L_on, 
    level_off = L_off, 
    m_flow_standby = 0) annotation(
    Placement(transformation(extent = {{-10, -10}, {10, 10}})));

  SolarTherm.Models.Control.PID_AW_reset3 PID(
    Tt = 1, 
    uMax = m_flow_max, 
    uMin = m_flow_min, 
    initType = Modelica.Blocks.Types.InitPID.InitialOutput, 
    y_start = y_start, 
    Ti = Ti, 
    Kp = Kp) annotation(
    Placement(visible = true, transformation(origin = {30, 80}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));

  Modelica.Blocks.Interfaces.RealInput T_mea annotation(
    Placement(visible = true, transformation(origin = {-108, 80}, extent = {{-20, -20}, {20, 20}}, rotation = 0)));

  Modelica.Blocks.Interfaces.RealInput L_cold annotation(
    Placement(visible = true, transformation(origin = {-108, 15}, extent = {{-20, -20}, {20, 20}}, rotation = 0)));

  Modelica.Blocks.Interfaces.RealInput L_hot_2 annotation(
    Placement(visible = true, transformation(origin = {-108, -15}, extent = {{-20, -20}, {20, 20}}, rotation = 0)));

  Modelica.Blocks.Math.Feedback feedback annotation(
    Placement(visible = true, transformation(origin = {-40, 80}, extent = {{-10, -10}, {10, 10}})));

  Modelica.Blocks.Sources.RealExpression T_ref_input(y = T_ref) annotation(
    Placement(visible = true, transformation(origin = {-70, 60}, extent = {{-10, -10}, {10, 10}})));

  Modelica.Blocks.Sources.BooleanExpression ireset annotation(
    Placement(visible = true, transformation(origin = {-10, 72}, extent = {{-10, 10}, {10, -10}}, rotation = 0)));

  Modelica.Blocks.Logical.Switch switch annotation(
    Placement(visible = true, transformation(origin = {66, 0}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));

equation
  connect(defocus_logic.level_ref, L_mea) annotation(
    Line(points = {{0, -34}, {0, -34}, {0, -20}, {-38, -20}, {-38, -50}, {-108, -50}}, color = {0, 0, 127}));
  connect(defocus_logic.y, defocus) annotation(
    Line(points = {{0, -69.36}, {0, -69.36}, {0, -82}, {0, -82}, {0, -114}}, color = {255, 0, 255}));
  connect(logic.level, L_mea) annotation(
    Line(points = {{-10.8, 0}, {-38, 0}, {-38, -50}, {-64, -50}, {-64, -50}, {-108, -50}, {-108, -50}}, color = {0, 0, 127}));
  connect(logic.m_flow_in, m_flow_in) annotation(
    Line(points = {{0, 10.4}, {0, 50}, {0, 50}, {-108, 50}}, color = {0, 0, 127}));
  connect(m_pump_2.y, m_pump2);
  connect(m_tank_2.y, m_tank2);
  connect(T_mea, feedback.u1) annotation(
    Line(points = {{-108, 80}, {-50, 80}, {-50, 80}, {-48, 80}}, color = {0, 0, 127}));
  connect(T_ref_input.y, feedback.u2) annotation(
    Line(points = {{-58, 60}, {-40, 60}, {-40, 72}, {-40, 72}}, color = {0, 0, 127}));
  connect(feedback.y, PID.u) annotation(
    Line(points = {{-30, 80}, {18, 80}}, color = {0, 0, 127}));
  connect(ireset.y, PID.reset) annotation(
    Line(points = {{1, 72}, {17, 72}}, color = {255, 0, 255}));
  connect(logic.m_flow, switch.u3) annotation(
    Line(points = {{12, 0}, {32, 0}, {32, -8}, {54, -8}, {54, -8}}, color = {0, 0, 127}));
  connect(PID.y, switch.u1) annotation(
    Line(points = {{40, 80}, {47, 80}, {47, 8}, {54, 8}}, color = {0, 0, 127}));
  connect(switch.y, m_flow) annotation(
    Line(points = {{78, 0}, {94, 0}, {94, 0}, {112, 0}}, color = {0, 0, 127}));
  connect(logic.switch, switch.u2) annotation(
    Line(points = {{12, 5}, {44, 5}, {44, 0}, {54, 0}, {54, 0}}, color = {255, 0, 255}));
  annotation(
    Documentation(revisions = "<html>
<ul>
<li>Alberto de la Calle:<br>Released first version. </li>
</ul>
</html>"));
end NewPowerBlockControl;