within SolarTherm;

block NewPI
import Modelica.Blocks.Types.InitPID;
  import Modelica.Blocks.Types.Init;
  extends Modelica.Blocks.Interfaces.SISO;


  parameter Real k(unit="1")=1 "Gain";
  parameter Real Nd(min=Modelica.Constants.small) = 10
    "The higher Nd, the more ideal the derivative block";
  parameter Real xi_start=0
    "Initial or guess value for integrator output (= integrator state)"
    annotation (Dialog(group="Initialization"));
  parameter Real xd_start=0
    "Initial or guess value for state of derivative block"
    annotation (Dialog(group="Initialization"));
  //parameter Real k(unit="1")=1 "Gain";
  parameter Modelica.SIunits.Time Ti(min=Modelica.Constants.small, start=0.5)
    "Time Constant of Integrator";
  parameter Modelica.SIunits.Time Td(min=0, start=0.1)
    "Time Constant of Derivative block";
  parameter Modelica.Blocks.Types.InitPID initType= Modelica.Blocks.Types.InitPID.InitialOutput
    "Type of initialization (1: no init, 2: steady state, 3: initial state, 4: initial output)"
                                     annotation(Evaluate=true,
      Dialog(group="Initialization"));
  parameter Real y_start=0 "Initial value of output"
    annotation(Dialog(enable=initType == InitPID.InitialOutput, group=
          "Initialization"));
  constant Modelica.SIunits.Time unitTime=1 annotation (HideResult=true);
  parameter Real Kp,  uMax, uMin;
  parameter Modelica.SIunits.Time Tt;
  Modelica.Blocks.Math.Add3 Add annotation(
    Placement(visible = true, transformation(extent = {{-2, -10}, {18, 10}}, rotation = 0)));
  Modelica.Blocks.Continuous.Integrator I(initType = if initType == InitPID.SteadyState then Init.SteadyState else if initType == InitPID.InitialState or initType == InitPID.DoNotUse_InitialIntegratorState then Init.InitialState else Init.NoInit, k = unitTime / Ti, y_start = xi_start) annotation(
    Placement(visible = true, transformation(extent = {{-82, -20}, {-42, 20}}, rotation = 0)));
  Modelica.Blocks.Math.Gain Gain(k = k) annotation(
    Placement(visible = true, transformation(extent = {{38, -10}, {58, 10}}, rotation = 0)));
  Modelica.Blocks.Continuous.Derivative D(T = max([Td / Nd, 100 * Modelica.Constants.eps]), initType = if initType == InitPID.SteadyState or initType == InitPID.InitialOutput then Init.SteadyState else if initType == InitPID.InitialState then Init.InitialState else Init.NoInit, k = Td / unitTime, x_start = xd_start) annotation(
    Placement(visible = true, transformation(extent = {{-82, -100}, {-42, -60}}, rotation = 0)));
  Modelica.Blocks.Math.Gain P(k = 1) annotation(
    Placement(visible = true, transformation(extent = {{-82, 60}, {-42, 100}}, rotation = 0)));
  Modelica.Blocks.Nonlinear.Limiter limiter(uMax = uMax, uMin = uMin) annotation(
    Placement(visible = true, transformation(extent = {{70, -8}, {86, 8}}, rotation = 0)));
initial equation
//   if initType==InitPID.InitialOutput then
//      y = y_start;
//   end if;

equation
  connect(I.y, Add.u2) annotation(
    Line(points = {{-40, 0}, {-4, 0}}, color = {0, 0, 127}));
  connect(D.y, Add.u3) annotation(
    Line(points = {{-40, -80}, {-4, -80}, {-4, -8}}, color = {0, 0, 127}));
  connect(P.y, Add.u1) annotation(
    Line(points = {{-40, 80}, {-4, 80}, {-4, 8}}, color = {0, 0, 127}));
  connect(Add.y, Gain.u) annotation(
    Line(points = {{19, 0}, {36, 0}}, color = {0, 0, 127}));
  connect(u, I.u) annotation(
    Line(points = {{-120, 0}, {-88, 0}, {-88, 0}, {-86, 0}}, color = {0, 0, 127}));
  connect(Gain.y, limiter.u) annotation(
    Line(points = {{60, 0}, {68, 0}, {68, 0}, {68, 0}}, color = {0, 0, 127}));
  connect(limiter.y, y) annotation(
    Line(points = {{86, 0}, {102, 0}, {102, 0}, {110, 0}}, color = {0, 0, 127}));
  annotation(
    defaultComponentName = "PID",
    Icon(coordinateSystem(preserveAspectRatio = false, initialScale = 0.1), graphics = {Line(points = {{-80, 78}, {-80, -90}}, color = {192, 192, 192}), Polygon(lineColor = {192, 192, 192}, fillColor = {192, 192, 192}, fillPattern = FillPattern.Solid, points = {{-80, 90}, {-88, 68}, {-72, 68}, {-80, 90}}), Line(points = {{-90, -80}, {82, -80}}, color = {192, 192, 192}), Polygon(lineColor = {192, 192, 192}, fillColor = {192, 192, 192}, fillPattern = FillPattern.Solid, points = {{90, -80}, {68, -72}, {68, -88}, {90, -80}}), Line(points = {{-80, -80}, {-80, -20}, {60, 80}}, color = {0, 0, 127}), Text(lineColor = {192, 192, 192}, extent = {{-20, -60}, {80, -20}}, textString = "PID"), Text(extent = {{-150, -150}, {150, -110}}, textString = "Ti=%Ti")}),
    Documentation(info = "<HTML>
<p>
This is the text-book version of a PID-controller.
For a more practically useful PID-controller, use
block LimPID.
</p>

<p>
The PID block can be initialized in different
ways controlled by parameter <b>initType</b>. The possible
values of initType are defined in
<a href=\"modelica://Modelica.Blocks.Types.InitPID\">Modelica.Blocks.Types.InitPID</a>.
This type is identical to
<a href=\"modelica://Modelica.Blocks.Types.Init\">Types.Init</a>,
with the only exception that the additional option
<b>DoNotUse_InitialIntegratorState</b> is added for
backward compatibility reasons (= integrator is initialized with
InitialState whereas differential part is initialized with
NoInit which was the initialization in version 2.2 of the Modelica
standard library).
</p>

<p>
Based on the setting of initType, the integrator (I) and derivative (D)
blocks inside the PID controller are initialized according to the following table:
</p>

<table border=1 cellspacing=0 cellpadding=2>
  <tr><td valign=\"top\"><b>initType</b></td>
      <td valign=\"top\"><b>I.initType</b></td>
      <td valign=\"top\"><b>D.initType</b></td></tr>

  <tr><td valign=\"top\"><b>NoInit</b></td>
      <td valign=\"top\">NoInit</td>
      <td valign=\"top\">NoInit</td></tr>

  <tr><td valign=\"top\"><b>SteadyState</b></td>
      <td valign=\"top\">SteadyState</td>
      <td valign=\"top\">SteadyState</td></tr>

  <tr><td valign=\"top\"><b>InitialState</b></td>
      <td valign=\"top\">InitialState</td>
      <td valign=\"top\">InitialState</td></tr>

  <tr><td valign=\"top\"><b>InitialOutput</b><br>
          and initial equation: y = y_start</td>
      <td valign=\"top\">NoInit</td>
      <td valign=\"top\">SteadyState</td></tr>

  <tr><td valign=\"top\"><b>DoNotUse_InitialIntegratorState</b></td>
      <td valign=\"top\">InitialState</td>
      <td valign=\"top\">NoInit</td></tr>
</table>

<p>
In many cases, the most useful initial condition is
<b>SteadyState</b> because initial transients are then no longer
present. If initType = InitPID.SteadyState, then in some
cases difficulties might occur. The reason is the
equation of the integrator:
</p>

<pre>
   <b>der</b>(y) = k*u;
</pre>

<p>
The steady state equation \"der(x)=0\" leads to the condition that the input u to the
integrator is zero. If the input u is already (directly or indirectly) defined
by another initial condition, then the initialization problem is <b>singular</b>
(has none or infinitely many solutions). This situation occurs often
for mechanical systems, where, e.g., u = desiredSpeed - measuredSpeed and
since speed is both a state and a derivative, it is natural to
initialize it with zero. As sketched this is, however, not possible.
The solution is to not initialize u or the variable that is used
to compute u by an algebraic equation.
</p>

</html>"),
    Diagram(coordinateSystem(preserveAspectRatio = false, extent = {{-100, -100}, {100, 100}})));


end NewPI;