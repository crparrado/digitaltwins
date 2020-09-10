within SolarTherm;

model PB_test
  import Modelica.SIunits.Conversions.*;
  replaceable package Medium = SolarTherm.Media.MoltenSalt.MoltenSalt_ph;
  Modelica.Fluid.Sources.Boundary_pT boundary(replaceable package Medium = Medium, nPorts = 1) annotation(
    Placement(visible = true, transformation(origin = {-48, -34}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.RealExpression realExpression(y = from_degC(20))  annotation(
    Placement(visible = true, transformation(origin = {10, 82}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.RealExpression parasities(y = 20000)  annotation(
    Placement(visible = true, transformation(origin = {66, 86}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Fluid.Sources.MassFlowSource_T source(replaceable package Medium = Medium, T = from_degC(565), nPorts = 1, use_m_flow_in = true) annotation(
    Placement(visible = true, transformation(origin = {-48, 54}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.Ramp ramp(duration = 3600, height = 466.678)  annotation(
    Placement(visible = true, transformation(origin = {-120, 64}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  SolarTherm.PB_Acciona_Real pB_Acciona_Real annotation(
    Placement(visible = true, transformation(origin = {35, 21}, extent = {{-25, -25}, {25, 25}}, rotation = 0)));
equation
  connect(ramp.y, source.m_flow_in) annotation(
    Line(points = {{-108, 64}, {-60, 64}, {-60, 62}, {-58, 62}}, color = {0, 0, 127}));
//  connect(source.ports[1], pB_Acciona_Real.fluid_a2) annotation(
//    Line(points = {{-38, 54}, {0, 54}, {0, 20}, {22, 20}, {22, 20}}, color = {0, 127, 255}));
  
  connect(realExpression.y, pB_Acciona_Real.T_amb) annotation(
    Line(points = {{22, 82}, {30, 82}, {30, 36}, {30, 36}}, color = {0, 0, 127}));
  connect(parasities.y, pB_Acciona_Real.parasities) annotation(
    Line(points = {{78, 86}, {84, 86}, {84, 48}, {40, 48}, {40, 36}, {40, 36}}, color = {0, 0, 127}));
  connect(pB_Acciona_Real.fluid_b, boundary.ports[1]) annotation(
    Line(points = {{20, 10}, {6, 10}, {6, -34}, {-38, -34}, {-38, -34}}, color = {0, 127, 255}));
  connect(source.ports[1], pB_Acciona_Real.fluid_a) annotation(
    Line(points = {{-38, 54}, {6, 54}, {6, 30}, {24, 30}, {24, 30}}, color = {0, 127, 255}));
end PB_test;