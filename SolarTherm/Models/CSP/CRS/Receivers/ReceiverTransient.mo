within SolarTherm.Models.CSP.CRS.Receivers;
model ReceiverTransient
  extends Interfaces.Models.ReceiverFluid;
  Medium.BaseProperties medium;
  SI.SpecificEnthalpy h_in;
  SI.SpecificEnthalpy h_out(start=h_0);
  parameter String file_perf_rec = Modelica.Utilities.Files.loadResource("modelica://SolarTherm/new_feature_functions/acciona_tables/motab_acciona/rec_perf.motab");
  parameter String perf_table = "rec_perf";
  
  parameter String file_ref_10min = Modelica.Utilities.Files.loadResource("modelica://SolarTherm/new_feature_functions/acciona_tables/motab_acciona/outputs_10min_v2.motab");
  parameter String refi_table = "outputs";
  
  parameter SI.Length H_rcv=1 "Receiver height" annotation(Dialog(group="Technical data"));
  parameter SI.Diameter D_rcv=1 "Receiver diameter" annotation(Dialog(group="Technical data"));
  parameter Integer N_pa = 1 "Number of panels" annotation(Dialog(group="Technical data"));
  parameter SI.Diameter D_tb=1 "Tube outer diameter" annotation(Dialog(group="Technical data"));
  parameter SI.Thickness t_tb=1 "Tube wall thickness" annotation(Dialog(group="Technical data"));
  parameter SI.Efficiency ab=1 "Coating absortance" annotation(Dialog(group="Technical data"));
  parameter SI.Efficiency em=1 "Coating Emitance" annotation(Dialog(group="Technical data"));
  parameter Real N_tb_pa=div(w_pa,D_tb) "Number of tubes";
  parameter SI.Length w_pa=D_rcv*sin(pi/N_pa) "Panel width"; //w_pa=D_rcv*pi/N_pa
  parameter SI.Volume V_rcv=N_pa*N_tb_pa*H_rcv*pi*(D_tb/2-t_tb)^2;
  parameter SI.Area A=N_pa*N_tb_pa*H_rcv*pi*D_tb/2 "Area";
  
  SI.Temperature T_in=Medium.temperature(state_in) "Temperature at inlet";
  SI.Temperature T_out=Medium.temperature(state_out) "Temperature at outlet";
  Medium.ThermodynamicState state_in=Medium.setState_phX(fluid_a.p,h_in);
  Medium.ThermodynamicState state_out=Medium.setState_phX(fluid_b.p,fluid_b.h_outflow);
  Real Q_inc;
  Real Q_perd;
  
  Modelica.Blocks.Sources.CombiTimeTable ref_table(tableOnFile = true, tableName = refi_table, smoothness = Modelica.Blocks.Types.Smoothness.ContinuousDerivative, fileName = file_ref_10min, columns = 1:39);

  Modelica.Blocks.Interfaces.RealOutput T(final quantity="ThermodynamicTemperature",
                                          final unit = "K", displayUnit = "degC", min=0) annotation (Placement(visible = true,transformation(
        
        origin={94,0},extent={{-10,-10},{10,10}},
        rotation=0), iconTransformation(
        
        origin={30, 0},extent={{-10,-10},{10,10}},
        rotation=0)));

  Modelica.Blocks.Interfaces.RealOutput Recpower annotation(
    Placement(visible = true, transformation(extent = {{-126, 74}, {-86, 114}}, rotation = 0), iconTransformation(origin = {30, -38}, extent = {{-10, -10}, {10, 10}}, rotation = 0)));
  
//   Modelica.Blocks.Interfaces.RealOutput Sun_elev annotation(
//    Placement(visible = true, transformation(extent = {{92, -20}, {132, 20}}, rotation = 0), iconTransformation(extent = {{92, -40}, {132, 0}}, rotation = 0)));
  
  SI.HeatFlowRate Q_loss;
  SI.HeatFlowRate Q_rcv;
  SI.Efficiency eta_rec;

  Modelica.Blocks.Interfaces.RealInput Tamb annotation (Placement(
        transformation(
        extent={{-12,-12},{12,12}},
        rotation=-90,
        origin={0,84}), iconTransformation(
        extent={{-6,-6},{6,6}},
        rotation=-90,
        origin={0,78})));

  Modelica.Blocks.Interfaces.RealInput Wspd annotation (Placement(
        transformation(
        extent={{-12,-12},{12,12}},
        rotation=-90,
        origin={-20,84}), iconTransformation(
        extent={{-6,-6},{6,6}},
        rotation=-90,
        origin={-20,78})));

  Modelica.Blocks.Sources.RealExpression q_in(y=heat.Q_flow/1e6);

  Modelica.Blocks.Tables.CombiTable2D rec_perf_tab(
    tableOnFile=true,
    tableName=perf_table,
    smoothness=Modelica.Blocks.Types.Smoothness.ContinuousDerivative,
    fileName=file_perf_rec);

  parameter Medium.ThermodynamicState state_0=Medium.setState_pTX(1e5,T_0);
  parameter SI.SpecificEnthalpy h_0=Medium.specificEnthalpy(state_0);
  parameter SI.Temperature T_0=from_degC(290) "Start value of temperature"; 
  
  Real RTOM(unit = "MWt");
initial equation
  medium.h = h_0;
equation
  connect(Wspd, rec_perf_tab.u2);
  connect(q_in.y, rec_perf_tab.u1);

  RTOM = ref_table.y[28];
  
  medium.h=(h_in+h_out)/2;
  h_in=inStream(fluid_a.h_outflow);
  fluid_b.h_outflow=max(h_0,h_out);
  fluid_a.h_outflow=h_in;
  T = T_out;

  heat.T=medium.T;
  fluid_b.m_flow=-fluid_a.m_flow;
  fluid_a.p=medium.p;
  //fluid_b.p=medium.p;
  fluid_a.p = fluid_b.p;

  eta_rec = max(0,rec_perf_tab.y);
  Q_rcv = ab*heat.Q_flow + fluid_a.m_flow*(h_out-h_in) - Q_loss; //medium.d*V_rcv*der(medium.u) + medium.u*V_rcv*der(medium.d);
  Q_loss = if heat.Q_flow > 1e-3 then ab*heat.Q_flow*(1-eta_rec) else A*sigma*em*(medium.T^4-Tamb^4);

  Q_inc = heat.Q_flow/1e6;
  Q_perd = Q_loss/1e6;
  

  medium.d*V_rcv*der(medium.u) + medium.u*V_rcv*der(medium.d) = ab*heat.Q_flow - Q_loss + fluid_a.m_flow*(h_in-h_out);
  
  Recpower = Q_inc;
annotation(
    experiment(StartTime = 0, StopTime = 1, Tolerance = 1e-6, Interval = 0.002));
end ReceiverTransient;