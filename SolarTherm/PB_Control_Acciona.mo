within SolarTherm;

model PB_Control_Acciona
extends SolarTherm.Icons.Control;
  parameter Modelica.SIunits.MassFlowRate m_flow_on = 1400 "Constant mass flow rate on";
  parameter Modelica.SIunits.MassFlowRate m_flow_off = 0 "Constant mass flow rate off";
  parameter Real L_on = 90 "Level of start discharge";
  parameter Real L_off = 10 "Level of stop discharge";
  parameter Real L_df_on = 99 "Level of start defocus";
  parameter Real L_df_off = 96 "Level of stop defocus";
  Modelica.Blocks.Interfaces.RealInput L_mea annotation(
    Placement(transformation(extent = {{-128, -70}, {-88, -30}})));
  Modelica.Blocks.Interfaces.RealOutput m_flow annotation(
    Placement(transformation(extent = {{92, -20}, {132, 20}})));
  Modelica.Blocks.Interfaces.RealOutput m_pump2 annotation(
    Placement(visible = true, transformation(extent = {{92, 32}, {132, 72}}, rotation = 0), iconTransformation(extent = {{92, 32}, {132, 72}}, rotation = 0)));
  Modelica.Blocks.Interfaces.RealOutput m_tank2 annotation(
    Placement(visible = true, transformation(extent = {{92, -75}, {132, -35}}, rotation = 0), iconTransformation(extent = {{92, -75}, {132, -35}}, rotation = 0)));
  Modelica.Blocks.Sources.RealExpression m_pump_2(y = 0.001) annotation(
    Placement(visible = true, transformation(origin = {51, -55}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.RealExpression m_tank_2(y = 0.001) annotation(
    Placement(visible = true, transformation(origin = {51, 52}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  //  Modelica.Blocks.Interfaces.RealInput L_mea_tk2 annotation(
  //    Placement(transformation(extent = {{-128, -18}, {-88, 22}}, rotation = 0), iconTransformation(extent = {{-128, -18}, {-88, 22}}, rotation = 0)));
  //  Modelica.Blocks.Interaction.Show.RealValue realValue annotation(
  //    Placement(transformation(extent = {{-68, -8}, {-28, 22}}, rotation = 0), iconTransformation(extent = {{-128, -18}, {-88, 22}}, rotation = 0)));
  SolarTherm.Models.Control.Level2Logic defocus_logic(y(start = false), level_max = L_df_on, level_min = L_df_off) annotation(
    Placement(transformation(extent = {{-17, -10}, {17, 10}}, rotation = -90, origin = {-3.55271e-015, -51})));
  Modelica.Blocks.Interfaces.BooleanOutput defocus annotation(
    Placement(transformation(extent = {{20, -20}, {-20, 20}}, rotation = 90, origin = {0, -114})));
  Modelica.Blocks.Interfaces.RealInput m_flow_in annotation(
    Placement(transformation(extent = {{-20, -20}, {20, 20}}, rotation = 0, origin = {-108, 50})));
  SolarTherm.Models.Control.StartUpLogic5 logic(m_flow_max = m_flow_on, m_flow_startup = m_flow_on / 2, level_on = L_on, level_off = L_off, m_flow_standby = 0) annotation(
    Placement(transformation(extent = {{-10, -10}, {10, 10}})));
equation
  connect(defocus_logic.level_ref, L_mea) annotation(
    Line(points = {{-4.44089e-016, -34}, {0, -34}, {0, -20}, {-38, -20}, {-38, -50}, {-108, -50}}, color = {0, 0, 127}));
  connect(defocus_logic.y, defocus) annotation(
    Line(points = {{-2.22045e-015, -69.36}, {-2.22045e-015, -69.36}, {-2.22045e-015, -82}, {0, -82}, {0, -114}}, color = {255, 0, 255}));
  connect(logic.level, L_mea) annotation(
    Line(points = {{-10.8, 0}, {-38, 0}, {-38, -50}, {-64, -50}, {-64, -50}, {-108, -50}, {-108, -50}}, color = {0, 0, 127}));
  connect(logic.m_flow_in, m_flow_in) annotation(
    Line(points = {{0, 10.4}, {0, 50}, {0, 50}, {-108, 50}}, color = {0, 0, 127}));
  connect(logic.m_flow, m_flow) annotation(
    Line(points = {{11, 0}, {52, 0}, {112, 0}}, color = {0, 0, 127}));
  connect(m_pump_2.y, m_pump2) annotation(
    Line(points = {{61, -55}, {92, -55}}, color = {0, 0, 127}));
  connect(m_tank_2.y, m_tank2) annotation(
    Line(points = {{61, 52}, {92, 52}}, color = {0, 0, 127}));
//  connect(L_mea_tk2, realValue.number)
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
//  Modelica.Blocks.Interfaces.RealInput L_mea annotation(
//    Placement(transformation(extent = {{-128, -70}, {-88, -30}})));
//  Modelica.Blocks.Interfaces.RealInput L_mea2 annotation(
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
//   when L_mea>L_on and L_mea2>L_on and L_mea>L_mea2 then
//      on_discharge_tk1 := true;
//      on_discharge_tk2 := false;
//   elsewhen L_mea>L_on and L_mea2>L_on and L_mea2>L_mea then
//      on_discharge_tk1 := false;
//      on_discharge_tk2 := true;
//   elsewhen L_mea>L_on and L_mea2<L_off then
//     on_discharge_tk1 := true;
//     on_discharge_tk2 := false;
//   elsewhen L_mea<L_off and L_mea2>L_on then
//     on_discharge_tk1 := false;
//     on_discharge_tk2 := true;
//   elsewhen L_mea<L_off and L_mea2<L_off then
//     on_discharge_tk1 := false;
//     on_discharge_tk2 := false;
//   end when;
//  when L_mea < L_df_on and L_mea2 < L_df_on and L_mea >= L_mea2 then // si ambos estan habiles para ser cargados, cargue el mas lleno
//        charge_tnk1:=true;
//        charge_tnk2:=false;
//  elsewhen L_mea < L_df_on and L_mea2 < L_df_on and L_mea < L_mea2 then
//        charge_tnk1:=false;
//        charge_tnk2:=true; // sino, cargue el que este bajo los niveles  permitidos
//  elsewhen (L_mea >= L_df_on) and (L_mea2 < L_df_on) then
//    charge_tnk1:=false; // Si el tk1 esta lleno, llene el tk2 si se puede
//    charge_tnk2:=true;
//  elsewhen (L_mea < L_df_on) and (L_mea2 >= L_df_on) then
//    charge_tnk1:=true;  // Si el tk2 esta lleno, llene el tk1 si se puede
//    charge_tnk2:=false;
//  elsewhen (L_mea >= L_df_on) and (L_mea2 >= L_df_on) then
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
  annotation(
    Documentation(revisions = "<html>
<ul>
<li>Alberto de la Calle:<br>Released first version. </li>
</ul>
</html>"));

end PB_Control_Acciona;