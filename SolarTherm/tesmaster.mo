within SolarTherm;

model tesmaster
  Modelica.Blocks.Sources.Ramp ramp(duration = 3600, height = 565, offset = 273.15)  annotation(
    Placement(visible = true, transformation(origin = {-72, 26}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  SolarTherm.TestPBMasterControl_3_CRI_cold testPBMasterControl_3_CRI_cold annotation(
    Placement(visible = true, transformation(origin = {-16, -36}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  SolarTherm.TestPBMasterControl_3_CRI_hot testPBMasterControl_3_CRI_hot annotation(
    Placement(visible = true, transformation(origin = {-16, 24}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  Modelica.Blocks.Sources.Ramp ramp1(duration = 3600, height = 300, offset = 273.15) annotation(
    Placement(visible = true, transformation(origin = {-76, -32}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
equation
  connect(ramp.y, testPBMasterControl_3_CRI_hot.T_mea) annotation(
    Line(points = {{-60, 26}, {-46, 26}, {-46, 24}, {-26, 24}, {-26, 24}}, color = {0, 0, 127}));
  connect(ramp1.y, testPBMasterControl_3_CRI_cold.T_mea) annotation(
    Line(points = {{-64, -32}, {-25, -32}}, color = {0, 0, 127}));
end tesmaster;