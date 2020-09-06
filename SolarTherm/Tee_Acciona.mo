within SolarTherm;

model Tee_Acciona
  extends Modelica.Fluid.Fittings.BaseClasses.PartialTeeJunction;
  parameter String file_ref_10min = Modelica.Utilities.Files.loadResource("modelica://SolarTherm/new_feature_functions/acciona_tables/motab_acciona/outputs_10min_v2.motab");
  parameter String refi_table = "outputs";
  //SI.MassFlowRate m_flow_sgp;
  //Real m_flow;
   Modelica.Blocks.Sources.CombiTimeTable ref_table(tableOnFile = true, tableName = refi_table, smoothness = Modelica.Blocks.Types.Smoothness.ContinuousDerivative, fileName = file_ref_10min, columns = 1:39);
initial equation
port_2.m_flow = ref_table.y[12];
equation
  connect(port_1, port_2) annotation (Line(
      points={{-100,0},{100,0}}, color={0,127,255}));
  connect(port_1, port_3) annotation (Line(
      points={{-100,0},{0,0},{0,100}}, color={0,127,255}));
  annotation(Documentation(info="<html>
This model is the simplest implementation for a splitting/joining component for
three flows. Its use is not required. It just formulates the balance
equations in the same way that the connect semantics would formulate them anyways.
The main advantage of using this component is, that the user does not get
confused when looking at the specific enthalpy at each port which might be confusing
when not using a splitting/joining component. The reason for the confusion is that one examines the mixing
enthalpy of the infinitesimal control volume introduced with the connect statement when
looking at the specific enthalpy in the connector which
might not be equal to the specific enthalpy at the port in the \"real world\".</html>"));


//m_flow = m_flow_sgp;
//port_2.m_flow = m_flow_sgp;

end Tee_Acciona;