within SolarTherm;

model PB_Control_Acciona
  extends SolarTherm.Icons.Control;
  parameter Modelica.SIunits.MassFlowRate m_flow_on = 1400 "Constant mass flow rate on";
  parameter Modelica.SIunits.MassFlowRate m_flow_off = 0 "Constant mass flow rate off";
  parameter Real L_on = 90 "Level of start discharge";
  parameter Real L_off = 10 "Level of stop discharge";
  parameter Real L_df_on = 99 "Level of start defocus";
  parameter Real L_df_off = 96 "Level of stop defocus";
  Modelica.Blocks.Interfaces.RealInput level_hot annotation(
    Placement(transformation(extent = {{-128, -70}, {-88, -30}})));
  Modelica.Blocks.Interfaces.RealInput level_cold annotation(
    Placement(visible = true, transformation(extent = {{-126, 68}, {-86, 108}}, rotation = 0), iconTransformation(extent = {{-126, 68}, {-86, 108}}, rotation = 0)));
  Modelica.Blocks.Interfaces.RealOutput m_flow_hot annotation(
    Placement(visible = true, transformation(extent = {{92, -20}, {132, 20}}, rotation = 0), iconTransformation(extent = {{92, -40}, {132, 0}}, rotation = 0)));
  Modelica.Blocks.Interfaces.RealOutput m_pump2 annotation(
    Placement(visible = true, transformation(extent = {{92, 32}, {132, 72}}, rotation = 0), iconTransformation(extent = {{92, 8}, {132, 48}}, rotation = 0)));
  Modelica.Blocks.Interfaces.RealOutput m_tank2 annotation(
    Placement(visible = true, transformation(extent = {{92, -75}, {132, -35}}, rotation = 0), iconTransformation(extent = {{92, -95}, {132, -55}}, rotation = 0)));
  Modelica.Blocks.Interfaces.RealOutput m_flow_cold annotation(
    Placement(visible = true, transformation(extent = {{94, 64}, {134, 104}}, rotation = 0), iconTransformation(extent = {{92, 58}, {132, 98}}, rotation = 0)));
  Modelica.Blocks.Interfaces.RealInput T(final quantity = "ThermodynamicTemperature", final unit = "K", displayUnit = "degC", min = 0) annotation(
    Placement(visible = true, transformation(origin = {-106, 2}, extent = {{20, -20}, {-20, 20}}, rotation = 180), iconTransformation(origin = {-109, -3}, extent = {{19, -19}, {-19, 19}}, rotation = 180)));
  Modelica.Blocks.Sources.RealExpression m_pump_2(y = 0.001) annotation(
    Placement(visible = true, transformation(origin = {51, -55}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.RealExpression m_tank_2(y = 0.001) annotation(
    Placement(visible = true, transformation(origin = {51, 52}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  //  Modelica.Blocks.Interfaces.RealInput level_hot_tk2 annotation(
  //    Placement(transformation(extent = {{-128, -18}, {-88, 22}}, rotation = 0), iconTransformation(extent = {{-128, -18}, {-88, 22}}, rotation = 0)));
  //  Modelica.Blocks.Interaction.Show.RealValue realValue annotation(
  //    Placement(transformation(extent = {{-68, -8}, {-28, 22}}, rotation = 0), iconTransformation(extent = {{-128, -18}, {-88, 22}}, rotation = 0)));
  SolarTherm.Models.Control.Level2Logic defocus_logic(y(start = false), level_max = L_df_on, level_min = L_df_off) annotation(
    Placement(transformation(extent = {{-17, -10}, {17, 10}}, rotation = -90, origin = {-3.55271e-015, -51})));
  Modelica.Blocks.Interfaces.BooleanOutput defocus annotation(
    Placement(transformation(extent = {{20, -20}, {-20, 20}}, rotation = 90, origin = {0, -114})));
  Modelica.Blocks.Interfaces.RealInput m_flow_in annotation(
    Placement(transformation(extent = {{-20, -20}, {20, 20}}, rotation = 0, origin = {-108, 50})));
  SolarTherm.Logic_PB_Acciona logic_PB_Acciona annotation(
    Placement(visible = true, transformation(origin = {-6, 25}, extent = {{-16, -19}, {16, 19}}, rotation = 0)));
equation
  connect(defocus_logic.level_ref, level_hot) annotation(
    Line(points = {{-4.44089e-016, -34}, {0, -34}, {0, -20}, {-38, -20}, {-38, -50}, {-108, -50}}, color = {0, 0, 127}));
  connect(defocus_logic.y, defocus) annotation(
    Line(points = {{-2.22045e-015, -69.36}, {-2.22045e-015, -69.36}, {-2.22045e-015, -82}, {0, -82}, {0, -114}}, color = {255, 0, 255}));
  connect(m_pump_2.y, m_pump2) annotation(
    Line(points = {{61, -55}, {92, -55}}, color = {0, 0, 127}));
  connect(m_tank_2.y, m_tank2) annotation(
    Line(points = {{61, 52}, {92, 52}}, color = {0, 0, 127}));
//  connect(level_hot_tk2, realValue.number)
//    annotation (Line(points={{-88,2},{-80,2},{-80,7},{-74,7}}, color={0,0,127}));
//  extends SolarTherm.Icons.Control;
//  parameter Modelica.SIunits.MassFlowRate m_flow_on = 1400 "Constant mass flow rate on";
//  parameter Modelica.SIunits.MassFlowRate m_flow_off = 0 "Constant mass flow rate off";
//  parameter Real L_on = 10 "Level of start discharge";
//  parameter Real L_off = 5 "Level of stop discharge";
//  parameter Real L_df_on = 80 "Level of start defocus";
//  parameter Real L_df_off = 70 "Level of stop defocus";
//  parameter SI.SpecificEnergy k_loss = 0.55e3 "Hot tank parasitic power coefficient";
//  parameter Real dispatch_factor = 1 "Operation strategy dispatch factor";
//  SI.Power W_loss;
//  Boolean on_discharge_tk1;
//  Boolean on_discharge_tk2;
//  Boolean charge_tnk1;
//  Boolean charge_tnk2;
//  // Level measurement
//  Modelica.Blocks.Interfaces.RealInput level_hot annotation(
//    Placement(transformation(extent = {{-128, -70}, {-88, -30}})));
//  Modelica.Blocks.Interfaces.RealInput level_hot2 annotation(
//    Placement(transformation(extent = {{-128, -18}, {-88, 22}}, rotation = 0), iconTransformation(extent = {{-128, -18}, {-88, 22}}, rotation = 0)));
//  // Flow measurement
//  Modelica.Blocks.Interfaces.BooleanOutput defocus annotation(
//    Placement(transformation(extent = {{20, -20}, {-20, 20}}, rotation = 90, origin = {0, -114})));
//  Modelica.Blocks.Interfaces.RealInput m_flow_in annotation(
//    Placement(transformation(extent = {{-20, -20}, {20, 20}}, rotation = 0, origin = {-108, 50})));
//  Modelica.Blocks.Interfaces.RealOutput m_flow2 annotation(
//    Placement(visible = true, transformation(extent = {{92, 32}, {132, 72}}, rotation = 0), iconTransformation(extent = {{92, 32}, {132, 72}}, rotation = 0)));
//  Modelica.Blocks.Interfaces.RealOutput m_flow annotation(
//    Placement(visible = true, transformation(extent = {{92, -20}, {132, 20}}, rotation = 0), iconTransformation(extent = {{92, -20}, {132, 20}}, rotation = 0)));
//  Modelica.Blocks.Interfaces.RealOutput m_flow_charge_tk2 annotation(
//    Placement(visible = true, transformation(extent = {{92, -75}, {132, -35}}, rotation = 0), iconTransformation(extent = {{92, -75}, {132, -35}}, rotation = 0)));
//algorithm
//   when level_hot>L_on and level_hot2>L_on and level_hot>level_hot2 then
//      on_discharge_tk1 := true;
//      on_discharge_tk2 := false;
//   elsewhen level_hot>L_on and level_hot2>L_on and level_hot2>level_hot then
//      on_discharge_tk1 := false;
//      on_discharge_tk2 := true;
//   elsewhen level_hot>L_on and level_hot2<L_off then
//     on_discharge_tk1 := true;
//     on_discharge_tk2 := false;
//   elsewhen level_hot<L_off and level_hot2>L_on then
//     on_discharge_tk1 := false;
//     on_discharge_tk2 := true;
//   elsewhen level_hot<L_off and level_hot2<L_off then
//     on_discharge_tk1 := false;
//     on_discharge_tk2 := false;
//   end when;
//  when level_hot < L_df_on and level_hot2 < L_df_on and level_hot >= level_hot2 then // si ambos estan habiles para ser cargados, cargue el mas lleno
//        charge_tnk1:=true;
//        charge_tnk2:=false;
//  elsewhen level_hot < L_df_on and level_hot2 < L_df_on and level_hot < level_hot2 then
//        charge_tnk1:=false;
//        charge_tnk2:=true; // sino, cargue el que este bajo los niveles  permitidos
//  elsewhen (level_hot >= L_df_on) and (level_hot2 < L_df_on) then
//    charge_tnk1:=false; // Si el tk1 esta lleno, llene el tk2 si se puede
//    charge_tnk2:=true;
//  elsewhen (level_hot < L_df_on) and (level_hot2 >= L_df_on) then
//    charge_tnk1:=true;  // Si el tk2 esta lleno, llene el tk1 si se puede
//    charge_tnk2:=false;
//  elsewhen (level_hot >= L_df_on) and (level_hot2 >= L_df_on) then
//    charge_tnk1:=true;
//    charge_tnk2:=false;
//    defocus := true;
//  end when;
//equation
//  W_loss = (abs(m_flow_in - m_flow) + m_flow) * k_loss;
////  if on_discharge_tk1 then
////    m_flow = dispatch_factor*m_flow_on;
////    m_flow2 = 0;
////  elseif on_discharge_tk2 then
////    m_flow2 = dispatch_factor*m_flow_on;
////    m_flow = 0;
////  end if;
////  if charge_tnk1 then
////    m_flow_charge_tk2 = 0;
////  elseif charge_tnk2 then
////    m_flow_charge_tk2 = m_flow_in;
////  end if;
//  annotation(
//    Documentation(revisions = "<html>
//<ul>
//<li>Alberto de la Calle:<br>Released first version. </li>
//</ul>
//</html>"));
  connect(level_cold, logic_PB_Acciona.level_cold) annotation(
    Line(points = {{-106, 88}, {-52, 88}, {-52, 15}, {-23, 15}}, color = {0, 0, 127}));
  connect(logic_PB_Acciona.level_hot, level_hot) annotation(
    Line(points = {{-23, 25}, {-62, 25}, {-62, -50}, {-108, -50}}, color = {0, 0, 127}));
  connect(m_flow_in, logic_PB_Acciona.m_flow_in) annotation(
    Line(points = {{-108, 50}, {-62, 50}, {-62, 66}, {-6, 66}, {-6, 45}}, color = {0, 0, 127}));
  connect(T, logic_PB_Acciona.t_sgs) annotation(
    Line(points = {{-106, 2}, {-68, 2}, {-68, 35}, {-23, 35}}, color = {0, 0, 127}));
  connect(logic_PB_Acciona.m_flow_cold, m_flow_cold) annotation(
    Line(points = {{12, 15.5}, {32, 15.5}, {32, 86}, {114, 86}, {114, 84}}, color = {0, 0, 127}));
  connect(logic_PB_Acciona.m_flow_hot, m_flow_hot) annotation(
    Line(points = {{12, 25}, {50, 25}, {50, 0}, {112, 0}}, color = {0, 0, 127}));
  annotation(
    Documentation(revisions = "<html>
<ul>
<li>Alberto de la Calle:<br>Released first version. </li>
</ul>
</html>"));
end PB_Control_Acciona;