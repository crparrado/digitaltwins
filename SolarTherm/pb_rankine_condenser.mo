within SolarTherm;

model pb_rankine_condenser

Parameter cond_teff = 0.98;

Modelica.Fluid.Interfaces.FluidPort_a fluid_aw(redeclare package Medium = Medium) annotation (Placement(
        visible = true,transformation(extent = {{-102, -2}, {-82, 18}}, rotation = 0),  iconTransformation(origin = {-89, 0}, extent = {{-15, -12}, {15, 12}}, rotation = 0)));

Modelica.Fluid.Interfaces.FluidPort_b fluid_bw(redeclare package Medium = Medium) annotation (Placement(
        visible = true,transformation(extent = {{78, -2}, {98, 18}}, rotation = 0),  iconTransformation(origin = {92, 0}, extent = {{-14, -12}, {14, 12}}, rotation = 0)));

Real Q_cond_in;
Real Q_cond_loss;

equation

// BALANCE DE MASA
fluid_aw.m_flow = fluid_bw.m_flow;

// CALOR ENTRANTE
Q_cond_in = fluid_as.m_flow*fluid_as.h_outflow;
// GENERACION
Q_cond_loss = (1-cond_teff)*Q_cond_in;
 
// BALANCE DE ENERGIA
fluid_aw.m_flow*fluid_aw.h_outflow + fluid_bw.m_flow*fluid_bw.h_outflow + Q_boil_loss = 0;

end pb_rankine_condenser;