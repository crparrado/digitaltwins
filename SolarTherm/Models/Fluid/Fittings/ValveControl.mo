within SolarTherm.Models.Fluid.Fittings;
model ValveControl "Three-way valve controled by mass flow rate"

  parameter Modelica.SIunits.Pressure p_fixed = 1e5 "operation pressure";
  replaceable package Medium = SolarTherm.Media.MoltenSalt.MoltenSalt_ph
    constrainedby Modelica.Media.Interfaces.PartialMedium "Medium in the component" annotation (choicesAllMatching = true);

  Modelica.Fluid.Interfaces.FluidPort_a fluid_b2(redeclare package Medium = Medium) annotation (Placement(transformation(extent={{-10,0},{10,20}}),
        iconTransformation(extent={{-10,0},{10,20}})));

  Modelica.Fluid.Interfaces.FluidPort_a fluid_a(redeclare package Medium = Medium) annotation (Placement(transformation(extent={{-60,60},{-40,80}}),
        iconTransformation(extent={{-60,60},{-40,80}})));

  Modelica.Fluid.Interfaces.FluidPort_b fluid_b1(redeclare package Medium = Medium) annotation (Placement(transformation(extent={{40,60},{60,80}}),
        iconTransformation(extent={{40,60},{60,80}})));

equation
   fluid_a.p = p_fixed;
   fluid_b2.p = p_fixed;   
   fluid_b1.p = p_fixed;

   fluid_a.h_outflow=0;
   fluid_b2.h_outflow=0;

   fluid_a.Xi_outflow=inStream(fluid_a.Xi_outflow);
   fluid_b2.Xi_outflow=inStream(fluid_a.Xi_outflow);
   fluid_b1.Xi_outflow=inStream(fluid_a.Xi_outflow);

   fluid_b1.m_flow = -(fluid_b2.m_flow + fluid_a.m_flow);
   fluid_b1.h_outflow = (fluid_a.m_flow*inStream(fluid_a.h_outflow) + fluid_b2.m_flow*inStream(fluid_b2.h_outflow))/(fluid_b2.m_flow + fluid_a.m_flow);

  annotation (Diagram(coordinateSystem(preserveAspectRatio=false, extent={{-100,0},
            {100,100}})),              Icon(coordinateSystem(extent={{-100,0},{100,
            100}}, preserveAspectRatio=false), graphics={
        Polygon(
          points={{50,100},{50,40},{0,70},{50,100}},
          lineColor={0,0,0},
          smooth=Smooth.None,
          fillPattern=FillPattern.Solid,
          fillColor={0,0,0}),
        Polygon(
          points={{-50,100},{-50,40},{0,70},{-50,100}},
          lineColor={0,0,0},
          smooth=Smooth.None,
          fillColor={0,0,0},
          fillPattern=FillPattern.Solid),
        Polygon(
          points={{0,70},{-40,10},{40,10},{0,70}},
          lineColor={0,0,0},
          smooth=Smooth.None,
          fillColor={0,0,0},
          fillPattern=FillPattern.Solid)}),
    Documentation(revisions="<html>
<ul>
<li>Alberto de la Calle:<br>Released first version. </li>
</ul>
</html>"));
end ValveControl;
