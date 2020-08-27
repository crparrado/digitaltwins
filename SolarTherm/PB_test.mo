within SolarTherm;

model PB_test
  import Modelica.SIunits.Conversions.*;
  replaceable package Medium = SolarTherm.Media.MoltenSalt.MoltenSalt_ph;
  SolarTherm.PB_Acciona_New pB_Acciona_New annotation(
    Placement(visible = true, transformation(origin = {64, 0}, extent = {{-32, -32}, {32, 32}}, rotation = 0)));
  Modelica.Fluid.Sources.Boundary_pT boundary(replaceable package Medium = Medium, nPorts = 1)  annotation(
    Placement(visible = true, transformation(origin = {-48, -34}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.RealExpression realExpression(y = from_degC(20))  annotation(
    Placement(visible = true, transformation(origin = {10, 82}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.RealExpression parasities(y = 20000)  annotation(
    Placement(visible = true, transformation(origin = {66, 86}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Fluid.Sources.MassFlowSource_T source(replaceable package Medium = Medium, T = from_degC(565), nPorts = 1, use_m_flow_in = true) annotation(
    Placement(visible = true, transformation(origin = {-48, 54}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Fluid.Sources.MassFlowSource_T boundary1(replaceable package Medium = Medium, T = from_degC(288), nPorts = 1, use_m_flow_in = true) annotation(
    Placement(visible = true, transformation(origin = {-48, 12}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.Ramp ramp(duration = 3600, height = 466.678)  annotation(
    Placement(visible = true, transformation(origin = {-120, 64}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.Ramp ramp1(duration = 3600, height = 0) annotation(
    Placement(visible = true, transformation(origin = {-120, 20}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
equation
  connect(parasities.y, pB_Acciona_New.parasities) annotation(
    Line(points = {{78, 86}, {92, 86}, {92, 30}, {70, 30}, {70, 19}}, color = {0, 0, 127}));
  connect(realExpression.y, pB_Acciona_New.T_amb) annotation(
    Line(points = {{22, 82}, {58, 82}, {58, 19}}, color = {0, 0, 127}));
  connect(source.ports[1], pB_Acciona_New.fluid_a2) annotation(
    Line(points = {{-38, 54}, {30, 54}, {30, 0}, {48, 0}, {48, -1}}, color = {0, 127, 255}));
  connect(boundary1.ports[1], pB_Acciona_New.fluid_a) annotation(
    Line(points = {{-38, 12}, {-6, 12}, {-6, 11}, {50, 11}}, color = {0, 127, 255}));
  connect(boundary.ports[1], pB_Acciona_New.fluid_b) annotation(
    Line(points = {{-38, -34}, {4, -34}, {4, -14}, {45, -14}}, color = {0, 127, 255}));
  connect(ramp.y, source.m_flow_in) annotation(
    Line(points = {{-108, 64}, {-60, 64}, {-60, 62}, {-58, 62}}, color = {0, 0, 127}));
  connect(ramp1.y, boundary1.m_flow_in) annotation(
    Line(points = {{-108, 20}, {-58, 20}, {-58, 20}, {-58, 20}}, color = {0, 0, 127}));
end PB_test;