within SolarTherm;

model pb_rankine_turbine

Parameter turb_teff = 0.4;

Modelica.Fluid.Interfaces.FluidPort_a fluid_aw(redeclare package Medium = Medium) annotation (Placement(
        visible = true,transformation(extent = {{-102, -2}, {-82, 18}}, rotation = 0),  iconTransformation(origin = {-95, 10}, extent = {{-11, -10}, {11, 10}}, rotation = 0)));

Modelica.Fluid.Interfaces.FluidPort_b fluid_bw(redeclare package Medium = Medium) annotation (Placement(
        visible = true,transformation(extent = {{78, -2}, {98, 18}}, rotation = 0),  iconTransformation(origin = {93, 11}, extent = {{-11, -11}, {11, 11}}, rotation = 0)));

Real Q_turb_in;
Modelica.Blocks.Interfaces.RealOutput W_elec annotation(
    Placement(visible = true, transformation(origin = {0, 100}, extent = {{10, -10}, {-10, 10}}, rotation = -90), iconTransformation(origin = {0, 104}, extent = {{-14, -14}, {14, 14}}, rotation = 90)));

  Modelica.Blocks.Interfaces.RealOutput W_elec annotation (Placement(visible = true,
    transformation(origin={-58, -16},extent={{10, -10}, {-10, 10}}, rotation=0), iconTransformation(
        origin={-55, -23},extent={{-5, -5}, {5, 5}}, rotation= 180)));

equation

// BALANCE DE MASA
fluid_aw.m_flow = fluid_bw.m_flow;

// CALOR ENTRANTE
Q_turb_in = fluid_as.m_flow*fluid_as.h_outflow;
// GENERACION
W_elec = turb_teff*Q_turb_in;
 
// BALANCE DE ENERGIA
fluid_aw.m_flow*fluid_aw.h_outflow + fluid_bw.m_flow*fluid_bw.h_outflow + Q_boil_loss = 0;

end pb_rankine_turbine;