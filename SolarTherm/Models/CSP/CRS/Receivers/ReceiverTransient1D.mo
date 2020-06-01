within SolarTherm.Models.CSP.CRS.Receivers;
model ReceiverTransient1D
  extends Interfaces.Models.ReceiverFluid;
  Medium.BaseProperties medium;
  SI.SpecificEnthalpy h_in;
  SI.SpecificEnthalpy h_out( start=h_0);
  parameter String file_perf_rec = Modelica.Utilities.Files.loadResource("modelica://SolarTherm/new_feature_functions/acciona_tables/motab_acciona/rec_perf.motab");
  parameter String perf_table = "rec_perf";

  parameter SI.Length H_rcv=14.63 "Receiver height" annotation(Dialog(group="Technical data"));
  parameter SI.Diameter D_rcv=14 "Receiver diameter" annotation(Dialog(group="Technical data"));
  parameter Integer N_pa = 1 "Number of panels" annotation(Dialog(group="Technical data"));
  parameter SI.Diameter D_tb=1 "Tube outer diameter" annotation(Dialog(group="Technical data"));
  parameter SI.Thickness t_tb=1 "Tube wall thickness" annotation(Dialog(group="Technical data"));
  parameter SI.Efficiency ab=1 "Coating absortance" annotation(Dialog(group="Technical data"));
  parameter SI.Efficiency em=1 "Coating Emitance" annotation(Dialog(group="Technical data"));
  
  // Geometrical Parameters
  parameter Integer n = 20 "Number of pipe discrete elements";
  parameter SI.Length L = 1.5 "Pipe length (m)";
  parameter SI.Diameter Do = 25.4/1000 "Outer pipe diameter (m)";
  parameter SI.Diameter Di = 23.4/1000 "Inner pipe diameter (m)";
  parameter SI.Diameter Dm=0.5*(Do+Di) "Average pipe diameter";
  parameter SI.Length dz = L/n "Uniform axial mesh size (m)";
  parameter SI.Volume V_w = pi*(Do^2 - Di^2)/4*dz "Element volume (m3)";
  parameter SI.Area Ai = pi*Di^2/4 "Pipe internal area (m2)";
  parameter SI.Area At = 1/4*pi*(Do^2 - Di^2) "Pipe transversal area (m2)";

  // Pipe material properties
  parameter SI.Density rho_w=8238 "Pipe density (kg/m3)";
  parameter SI.ThermalConductivity k=20 "Pipe thermal conductivity (W/(m.K))";
  parameter SI.SpecificHeatCapacity Cp=500 "Tube Heat capacity (J/(kg.K))";
  parameter SI.Mass mw = rho_w*V_w "Element mass";

  // Fluid properties
  parameter SI.Temperature Tf_in = from_degC(290); // Fluid inlet temperature (K)

  SI.Temperature T_in=Medium.temperature(state_in) "Temperature at inlet";
  SI.Temperature T_out=Medium.temperature(state_out) "Temperature at outlet";
  Medium.ThermodynamicState state_in=Medium.setState_phX(fluid_a.p,h_in);
  Medium.ThermodynamicState state_out=Medium.setState_phX(fluid_b.p,h_out);
  SI.Efficiency out_rec_perf;
  SI.HeatFlowRate Q_inc;
  SI.HeatFlowRate q_loss_tb;
  //SI.SpecificEnthalpy hfi = Media.MoltenSalt.MoltenSalt_utilities.h_T(Tf_in); // (J/kg)

  Real Ref[n]; //HTF Reynolds number
  Real Prf[n]; //HTF Prandtl number
  SI.Temperature Tw[n];
  SI.Temperature Tw_s[n];
  SI.Temperature Tw_i[n];
  SI.Temperature Tw_ib[n];
  SI.Temperature Twb[n];
  SI.Temperature Tf[n];
  SI.CoefficientOfHeatTransfer hi[n]; // W/(m2.K)
  SI.Density rhof[n]; // (kg/m3)  
  SI.SpecificEnthalpy hfo[n]; // (J/kg)
  SI.ThermalConductivity kf[n]; // (J/kg)
  SI.DynamicViscosity muf[n];  // (Pa.s)
  SI.SpecificHeatCapacity Cpf[n]; // (J/(kg.K))

  Modelica.Blocks.Interfaces.RealOutput T(final quantity="ThermodynamicTemperature", final unit = "K", displayUnit = "degC", min=0) annotation (Placement(transformation(
        extent={{-10,-10},{10,10}},
        rotation=0,
        origin={94,0}), iconTransformation(
        extent={{-10,-10},{10,10}},
        rotation=0,
        origin={30,0})));

  //SI.HeatFlowRate Q_loss;
  //SI.HeatFlowRate Q_rcv;
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

  Modelica.Blocks.Sources.RealExpression in_inc_power(y=Q_inc);
  
  Modelica.Blocks.Tables.CombiTable2D rec_perf_tab(
    tableOnFile=true,
    tableName=perf_table,
    smoothness=Modelica.Blocks.Types.Smoothness.ContinuousDerivative,
    fileName=file_perf_rec);

protected
  parameter SI.Length w_pa=D_rcv*pi/N_pa "Panel width";
  parameter Real N_tb_pa=div(w_pa,D_tb) "Number of tubes";
  parameter SI.Volume V_rcv=N_pa*N_tb_pa*H_rcv*pi*(D_tb/2-t_tb)^2;
  parameter SI.Area A=N_pa*N_tb_pa*H_rcv*pi*D_tb/2 "Area";
  parameter Medium.ThermodynamicState state_0=Medium.setState_pTX(1e5,T_0);
  parameter SI.SpecificEnthalpy h_0=Medium.specificEnthalpy(state_0);
  parameter SI.Temperature T_0=from_degC(290) "Start value of temperature";

initial equation
  Tf = linspace(Tf_in,Tf_in,n);
  Tw = linspace(Tf_in,Tf_in,n);
  Twb = linspace(Tf_in,Tf_in,n);

equation
  connect(Wspd, rec_perf_tab.u2);
  connect(in_inc_power.y, rec_perf_tab.u1);

  // First Element
  0.5*mw*Cp*der(Tw[1]) = - 0.5*k*At*(Tw[1]-Tw[2])/dz + 0.5*k*2*pi*dz*(Tw_s[1]-Tw[1])/log(Do/Dm) - 0.5*k*2*pi*dz*(Tw[1] - Tw_i[1])/log(Dm/Di);
  ab*heat.Q_flow/n/N_tb_pa*(1-out_rec_perf) = 0.5*k*2*pi*dz*(Tw_s[1]-Tw[1])/log(Do/Dm);
  hi[1]*0.5*pi*Di*dz*(Tw_i[1]-Tf[1]) = 0.5*k*2*pi*dz*(Tw[1]-Tw_i[1])/log(Dm/Di);
  rhof[1]*pi*Ai*dz*Cpf[1]*der(Tf[1]) = fluid_a.m_flow/2/N_tb_pa*(h_in-hfo[1])- kf[1]*Ai*(Tf[1]-Tf[2])/dz + hi[1]*0.5*pi*Di*dz*(Tw_i[1]-Tf[1]) + hi[1]*0.5*pi*Di*dz*(Tw_ib[1]-Tf[1]);
  hi[1]*0.5*pi*Di*dz*(Tw_ib[1]-Tf[1]) = 0.5*k*2*pi*dz*(Twb[1]-Tw_ib[1])/log(Dm/Di);
  0.5*mw*Cp*der(Twb[1]) = - 0.5*k*At*(Twb[1]-Twb[2])/dz - 0.5*k*2*pi*dz*(Twb[1]-Tw_ib[1])/log(Dm/Di);

  // Fluid properties  
  hfo[1] = Media.MoltenSalt.MoltenSalt_utilities.h_T(Tf[1]); // Outlet Enthalpy (J/kg)
  hi[1] = kf[1]/Di*(5.6+0.0165*(Ref[1]*Prf[1])^0.85*Prf[1]^0.01); // Internal heat transfer coefficient
  Ref[1] = fluid_a.m_flow/2/N_tb_pa*Di/(Ai*muf[1]); // Fluid Reynolds number
  Prf[1] = Cpf[1]*muf[1]/kf[1]; // Fluid Prandtl number
  rhof[1] = Media.MoltenSalt.MoltenSalt_utilities.rho_T(Tf[1]); // HTF outlet Density (kg/m3)
  muf[1] = Media.MoltenSalt.MoltenSalt_utilities.eta_T(Tf[1]); // HTF Dynamic Viscosity (Pa.s)
  Cpf[1] = Media.MoltenSalt.MoltenSalt_utilities.cp_T(Tf[1]); // HTF Specific Heat Capacity (J/(kg.K))
  kf[1] = Media.MoltenSalt.MoltenSalt_utilities.lamda_T(Tf[1]); // HTF Thermal Conductivity (W/(m.K))
  
  // Intermediate element
  for j in 2:n-1 loop
    0.5*mw*Cp*der(Tw[j]) = -0.5*k*At*(Tw[j]-Tw[j-1])/dz - 0.5*k*At*(Tw[j]-Tw[j+1])/dz + 0.5*k*2*pi*dz*(Tw_s[j]-Tw[j])/log(Do/Dm) - 0.5*k*2*pi*dz*(Tw[j] - Tw_i[j])/log(Dm/Di);
    ab*heat.Q_flow/n/N_tb_pa*(1-out_rec_perf) = 0.5*k*2*pi*dz*(Tw_s[j]-Tw[j])/log(Do/Dm);
    hi[j]*0.5*pi*Di*dz*(Tw_i[j]-Tf[j]) = 0.5*k*2*pi*dz*(Tw[j]-Tw_i[j])/log(Dm/Di);    
    rhof[j]*pi*Ai*dz*Cpf[j]*der(Tf[j]) = fluid_a.m_flow/2/N_tb_pa*(hfo[j-1]-hfo[j]) -kf[j]*Ai*(Tf[j]-Tf[j-1])/dz - kf[j]*Ai*(Tf[j]-Tf[j+1])/dz + hi[j]*0.5*pi*Di*dz*(Tw_i[j]-Tf[j]) + hi[j]*0.5*pi*Di*dz*(Tw_ib[j]-Tf[j]);
    hi[j]*0.5*pi*Di*dz*(Tw_ib[j]-Tf[j]) = 0.5*k*2*pi*dz*(Twb[j]-Tw_ib[j])/log(Dm/Di);
    0.5*mw*Cp*der(Twb[j]) = -0.5*k*At*(Twb[j]-Twb[j-1])/dz - 0.5*k*At*(Twb[j]-Twb[j+1])/dz - 0.5*k*2*pi*dz*(Twb[j]-Tw_ib[j])/log(Dm/Di);
    // Fluid properties
    hfo[j] = Media.MoltenSalt.MoltenSalt_utilities.h_T(Tf[j]); // HTF outlet Enthalpy (J/kg)
    hi[j] = kf[j]/Di*(5.6+0.0165*(Ref[j]*Prf[j])^0.85*Prf[j]^0.01);  // HTF Internal HTC
    Ref[j] = fluid_a.m_flow/2/N_tb_pa*Di/(Ai*muf[j]); // Fluid Reynolds number
    Prf[j] = Cpf[j]*muf[j]/kf[j]; // Fluid Prandtl number  
    rhof[j] = Media.MoltenSalt.MoltenSalt_utilities.rho_T(Tf[j]); // HTF outlet Density (kg/m3)
    muf[j] = Media.MoltenSalt.MoltenSalt_utilities.eta_T(Tf[j]);  // HTF Dynamic Viscosity (Pa.s)
    Cpf[j] = Media.MoltenSalt.MoltenSalt_utilities.cp_T(Tf[j]);   // HTF Specific Heat Capacity (J/(kg.K))
    kf[j] = Media.MoltenSalt.MoltenSalt_utilities.lamda_T(Tf[j]); // HTF Thermal Conductivity (W/(m.K))
  end for;
  
  // Last element
  0.5*mw*Cp*der(Tw[end]) = -0.5*k*At*(Tw[end]-Tw[end-1])/dz + 0.5*k*2*pi*dz*(Tw_s[end]-Tw[end])/log(Do/Dm) - 0.5*k*2*pi*dz*(Tw[end] - Tw_i[end])/log(Dm/Di);
  ab*heat.Q_flow/n/N_tb_pa*(1-out_rec_perf) = 0.5*k*2*pi*dz*(Tw_s[end]-Tw[end])/log(Do/Dm);
  hi[end]*0.5*pi*Di*dz*(Tw_i[end]-Tf[end]) = 0.5*k*2*pi*dz*(Tw[end]-Tw_i[end])/log(Dm/Di);
  rhof[end]*pi*Ai*dz*Cpf[end]*der(Tf[end]) = fluid_a.m_flow/2/N_tb_pa*(hfo[end-1]-hfo[end])-kf[end]*Ai*(Tf[end]-Tf[end-1])/dz + hi[end]*0.5*pi*Di*dz*(Tw_i[end]-Tf[end]) + hi[end]*0.5*pi*Di*dz*(Tw_ib[end]-Tf[end]);
  hi[end]*0.5*pi*Di*dz*(Tw_ib[end]-Tf[end]) = 0.5*k*2*pi*dz*(Twb[end]-Tw_ib[end])/log(Dm/Di);
  0.5*mw*Cp*der(Twb[end]) = -0.5*k*At*(Twb[end]-Twb[end-1])/dz - 0.5*k*2*pi*dz*(Twb[end]-Tw_ib[end])/log(Dm/Di);  
  
  // Fluid properties
  hfo[end] = Media.MoltenSalt.MoltenSalt_utilities.h_T(Tf[end]); // HTF outlet Enthalpy (J/kg)
  hi[end] = kf[end]/Di*(5.6+0.0165*(Ref[end]*Prf[end])^0.85*Prf[end]^0.01);  // HTF Internal HTC
  Ref[end] = fluid_a.m_flow/2/N_tb_pa*Di/(Ai*muf[end]); // Fluid Reynolds number
  Prf[end] = Cpf[end]*muf[end]/kf[end]; // Fluid Prandtl number  
  rhof[end] = Media.MoltenSalt.MoltenSalt_utilities.rho_T(Tf[end]); // HTF outlet Density (kg/m3)
  muf[end] = Media.MoltenSalt.MoltenSalt_utilities.eta_T(Tf[end]); // HTF Dynamic Viscosity (Pa.s)
  Cpf[end] = Media.MoltenSalt.MoltenSalt_utilities.cp_T(Tf[end]); // HTF Specific Heat Capacity (J/(kg.K))
  kf[end] = Media.MoltenSalt.MoltenSalt_utilities.lamda_T(Tf[end]); // HTF Thermal Conductivity (W/(m.K))
  //End 1D model  

  Q_inc = heat.Q_flow/1e6;
  q_loss_tb = heat.Q_flow*(1-out_rec_perf)/n/N_tb_pa;

  out_rec_perf = max(0,rec_perf_tab.y);
  h_out = hfo[end];

  medium.h=(h_in+h_out)/2;
  h_in=inStream(fluid_a.h_outflow);
  fluid_b.h_outflow=max(h_0,h_out);
  fluid_a.h_outflow=0;
  T = T_out;

  heat.T=medium.T;
  fluid_b.m_flow=-fluid_a.m_flow;
  fluid_a.p=medium.p;
  fluid_b.p=medium.p;

  //Q_loss=-A*sigma*em*(medium.T^4-Tamb^4);
  //0=ab*heat.Q_flow+Q_loss+fluid_a.m_flow*(h_in-h_out);
  //Q_rcv=fluid_a.m_flow*(h_out-h_in);
end ReceiverTransient1D;