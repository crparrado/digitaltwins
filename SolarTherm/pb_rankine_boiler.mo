within SolarTherm;

model pb_rankine_boiler

Parameter boil_teff = 0.99;

Modelica.Fluid.Interfaces.FluidPort_a fluid_as_hot(redeclare package Medium = Medium) annotation (Placement(
        visible = true,transformation(extent = {{-100, 48}, {-80, 68}}, rotation = 0),  iconTransformation(origin = {-106, 68}, extent = {{-14, -12}, {14, 12}}, rotation = 0)));

Modelica.Fluid.Interfaces.FluidPort_a fluid_as_cold(redeclare package Medium = Medium) annotation (Placement(
        visible = true,transformation(extent = {{-102, 10}, {-82, 30}}, rotation = 0),  iconTransformation(origin = {-104, 26}, extent = {{-14, -12}, {14, 12}}, rotation = 0)));

Modelica.Fluid.Interfaces.FluidPort_b fluid_bs(redeclare package Medium = Medium) annotation (Placement(
        visible = true,transformation(extent = {{80, 40}, {100, 60}}, rotation = 0),  iconTransformation(origin = {98, 61}, extent = {{-14, -15}, {14, 15}}, rotation = 0)));

Modelica.Fluid.Interfaces.FluidPort_a fluid_aw(redeclare package Medium = Medium) annotation (Placement(
        visible = true,transformation(extent = {{-100, -60}, {-80, -40}}, rotation = 0),  iconTransformation(origin = {-100, -61}, extent = {{-10, -13}, {10, 13}}, rotation = 0)));

Modelica.Fluid.Interfaces.FluidPort_b fluid_bw(redeclare package Medium = Medium) annotation (Placement(
        visible = true,transformation(extent = {{80, -60}, {100, -40}}, rotation = 0),  iconTransformation(origin = {101, -54}, extent = {{-13, -12}, {13, 12}}, rotation = 0)));
 
Real Q_boil_loss;
Real SaltMix_T;

 Modelica.Fluid.Fittings.TeeJunctionIdeal salt_mixer annotation(
    Placement(visible = true, transformation(origin = {-37, 21}, extent = {{-13, -13}, {13, 13}}, rotation = 0)));
 Modelica.Fluid.Sensors.TemperatureTwoPort salt_mix_temp annotation(
    Placement(visible = true, transformation(origin = {16, 22}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
 Modelica.Blocks.Interfaces.RealOutput W_elec annotation(
    Placement(visible = true, transformation(origin = {16, 106}, extent = {{10, -10}, {-10, 10}}, rotation = -90), iconTransformation(origin = {0, 104}, extent = {{-14, -14}, {14, 14}}, rotation = 90)));
equation

// BALANCE DE MASA
  fluid_as_hot.m_flow + fluid_as_cold.m_flow = fluid_bs.m_flow;  
fluid_aw.m_flow = fluid_bw.m_flow;
// PERDIDAS
  Q_boil_loss = (1 - boil_teff) * (fluid_as_hot.m_flow * fluid_as_hot.h_outflow + fluid_aw.m_flow * fluid_aw.h_outflow);
// BALANCE DE ENERGIA
  fluid_as_hot.m_flow * fluid_as_hot.h_outflow + fluid_aw.m_flow * fluid_aw.h_outflow + fluid_bs.m_flow * fluid_bs.h_outflow + fluid_bw.m_flow * fluid_bw.h_outflow + Q_boil_loss = 0;
 connect(fluid_as_hot, salt_mixer.port_3) annotation(
    Line(points = {{-90, 58}, {-37, 58}, {-37, 34}}));
 connect(fluid_as_cold, salt_mixer.port_1) annotation(
    Line(points = {{-92, 20}, {-50, 20}, {-50, 22}, {-50, 22}}));
 connect(salt_mixer.port_2, salt_mix_temp.port_a) annotation(
    Line(points = {{-24, 22}, {6, 22}}, color = {0, 127, 255}));
 connect(salt_mix_temp.port_b, fluid_bs) annotation(
    Line(points = {{26, 22}, {58, 22}, {58, 50}, {90, 50}}, color = {0, 127, 255}));
 connect(salt_mix_temp.T, SaltMix_T) annotation(
    Line(points = {{16, 34}, {16, 106}}, color = {0, 0, 127}));
end pb_rankine_boiler;