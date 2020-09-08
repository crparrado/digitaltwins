within SolarTherm;

model pb_rankine_real


Modelica.Fluid.Interfaces.FluidPort_a fluid_as_hot(redeclare package Medium = Medium) annotation (Placement(
        visible = true,transformation(extent = {{-110, 70}, {-90, 90}}, rotation = 0),  iconTransformation(origin = {-70, 72}, extent = {{-14, -12}, {14, 12}}, rotation = 0)));

Modelica.Fluid.Interfaces.FluidPort_a fluid_as_cold(redeclare package Medium = Medium) annotation (Placement(
        visible = true,transformation(extent = {{-110, 30}, {-90, 50}}, rotation = 0),  iconTransformation(origin = {-76, 32}, extent = {{-14, -12}, {14, 12}}, rotation = 0)));


Modelica.Fluid.Interfaces.FluidPort_b fluid_bs(redeclare package Medium = Medium) annotation (Placement(
        visible = true,transformation(extent = {{-110, -6}, {-90, 14}}, rotation = 0),  iconTransformation(origin = {-98, -65}, extent = {{-14, -15}, {14, 15}}, rotation = 0)));


  SolarTherm.pb_rankine_boiler boiler annotation(
    Placement(visible = true, transformation(origin = {-28, 58}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  SolarTherm.pb_rankine_turbine turbine annotation(
    Placement(visible = true, transformation(origin = {44, 52}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  SolarTherm.pb_rankine_condenser condenser annotation(
    Placement(visible = true, transformation(origin = {70, -8}, extent = {{10, -10}, {-10, 10}}, rotation = 0)));
  Modelica.Fluid.Sources.FixedBoundary water_sink(T = from_degC(25), nPorts = 1)  annotation(
    Placement(visible = true, transformation(origin = {40, -78}, extent = {{-10, -10}, {10, 10}}, rotation = 90)));
  Modelica.Fluid.Sensors.MassFlowRate massflow_output annotation(
    Placement(visible = true, transformation(origin = {40, -18}, extent = {{-10, 10}, {10, -10}}, rotation = -90)));
  Modelica.Fluid.Sources.Boundary_pT water_source(T = From_degC(25))  annotation(
    Placement(visible = true, transformation(origin = {-46, -74}, extent = {{-10, -10}, {10, 10}}, rotation = 90)));
  Modelica.Fluid.Machines.Pump water_pump annotation(
    Placement(visible = true, transformation(origin = {-46, -18}, extent = {{-10, 10}, {10, -10}}, rotation = 90)));
  Modelica.Blocks.Interfaces.RealOutput water_temp annotation(
    Placement(visible = true, transformation(origin = {-28, 106}, extent = {{10, -10}, {-10, 10}}, rotation = -90), iconTransformation(origin = {-92, -12}, extent = {{-14, -14}, {14, 14}}, rotation = 180)));
  Modelica.Blocks.Interfaces.RealOutput W_Turbine annotation(
    Placement(visible = true, transformation(origin = {44, 106}, extent = {{10, -10}, {-10, 10}}, rotation = -90), iconTransformation(origin = {90, 6}, extent = {{-14, -14}, {14, 14}}, rotation = 0)));
equation
  connect(boiler.fluid_bw, turbine.fluid_aw) annotation(
    Line(points = {{-18, 53}, {34.5, 53}}, color = {0, 127, 255}));
  connect(condenser.fluid_aw, turbine.fluid_bw) annotation(
    Line(points = {{79, -8}, {92, -8}, {92, 53}, {53, 53}}));
  connect(fluid_as, boiler.fluid_as) annotation(
    Line(points = {{-102, 54}, {-46, 54}, {-46, 56}}));
  connect(fluid_bs, fluid_bs.fluid_bs) annotation(
    Line(points = {{-100, -78}, {-100, -78}}));
  connect(fluid_bs, boiler.fluid_bs) annotation(
    Line(points = {{-100, 4}, {-6, 4}, {-6, 64}, {-18, 64}}));
  connect(fluid_as_hot, boiler.fluid_as_hot) annotation(
    Line(points = {{-100, 80}, {-80, 80}, {-80, 64}, {-39, 64}, {-39, 65}}));
  connect(fluid_as_cold, boiler.fluid_as_cold) annotation(
    Line(points = {{-100, 40}, {-80, 40}, {-80, 60}, {-38, 60}}));
  connect(condenser.fluid_bw, massflow_output.port_a) annotation(
    Line(points = {{61, -8}, {40, -8}}, color = {0, 127, 255}));
  connect(massflow_output.port_b, water_sink.ports[1]) annotation(
    Line(points = {{40, -28}, {40, -68}}, color = {0, 127, 255}));
  connect(water_source.ports[1], water_pump.port_a) annotation(
    Line(points = {{-46, -64}, {-46, -28}}, color = {0, 127, 255}));
  connect(water_pump.port_b, boiler.fluid_aw) annotation(
    Line(points = {{-46, -8}, {-46, 52}, {-38, 52}}, color = {0, 127, 255}));
  connect(massflow_output.m_flow, water_pump.shaft) annotation(
    Line(points = {{29, -18}, {-36, -18}}, color = {0, 0, 127}));
  connect(boiler.W_elec, water_temp) annotation(
    Line(points = {{-28, 68}, {-28, 68}, {-28, 106}, {-28, 106}}, color = {0, 0, 127}));
  connect(turbine.W_elec, W_Turbine) annotation(
    Line(points = {{44, 62}, {44, 62}, {44, 106}, {44, 106}}, color = {0, 0, 127}));
annotation(
    Icon(graphics = {Polygon(origin = {2, -2}, fillColor = {122, 122, 122}, pattern = LinePattern.None, fillPattern = FillPattern.Solid, points = {{-66, 96}, {68, 96}, {98, -70}, {-102, -98}, {-66, 96}}), Polygon(fillColor = {255, 255, 0}, pattern = LinePattern.None, fillPattern = FillPattern.Solid, points = {{-74, -28}, {14, 6}, {-4, 30}, {-74, -28}}), Polygon(origin = {-10, 16}, fillColor = {255, 255, 0}, pattern = LinePattern.None, fillPattern = FillPattern.Solid, points = {{52, 58}, {-20, 14}, {-2, -18}, {52, 58}}), Text(origin = {13, -55}, extent = {{-105, 57}, {89, -29}}, textString = "REAL")}, coordinateSystem(initialScale = 0.1)));
end pb_rankine_real;