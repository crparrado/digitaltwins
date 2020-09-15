within SolarTherm;

model mflow2powerbloc

//  Modelica.Blocks.Interfaces.RealInput level_hot annotation(
//    Placement(transformation(extent = {{-128, -20}, {-88, 20}})));
  
  Modelica.Blocks.Interfaces.RealOutput m_flow_hot annotation(
    Placement(visible = true, transformation(extent = {{90, -20}, {130, 20}}, rotation = 0), iconTransformation(extent = {{90, 12}, {130, 52}}, rotation = 0)));
  Modelica.Blocks.Interfaces.RealInput T(final quantity = "ThermodynamicTemperature", final unit = "K", displayUnit = "degC", min = 0) annotation(
    Placement(visible = true, transformation(origin = {-112, -60}, extent = {{20, -20}, {-20, 20}}, rotation = 180), iconTransformation(origin = {-109, 81}, extent = {{19, -19}, {-19, 19}}, rotation = 180)));
 
 parameter Real T_ref = from_degC(400);
 parameter Real m_flow_startup = 200;
 
algorithm
//when on_charge or on_discharge then
//     t_on = time;
//   end when; 
 
initial equation
 
m_flow_hot = m_flow_startup;

equation

if T  > T_ref then

//m_flow = 0.077*time;
m_flow_hot = 648.1;

else

m_flow_hot = m_flow_startup ;

end if;


end mflow2powerbloc;