within SolarTherm;

model SaltTwoTanks_Acciona_2
  import SolarTherm.{Models,Media};
  import Modelica.SIunits.Conversions.from_degC;
  import SI = Modelica.SIunits;
  import nSI = Modelica.SIunits.Conversions.NonSIunits;
  import CN = Modelica.Constants;
  import CV = Modelica.SIunits.Conversions;
  import FI = SolarTherm.Models.Analysis.Finances;
  import SolarTherm.Types.Solar_angles;
  import SolarTherm.Types.Currency;
  extends Modelica.Icons.Example;
  // Input Parameters
  // *********************
  replaceable package Medium = Media.MoltenSalt.MoltenSalt_ph "Medium props for molten salt";
  parameter String pri_file = Modelica.Utilities.Files.loadResource("modelica://SolarTherm/Data/Prices/aemo_vic_2014.motab") "Electricity price file";
  parameter Currency currency = Currency.USD "Currency used for cost analysis";
  parameter Boolean const_dispatch = false "Constant dispatch of energy";
  parameter String sch_file = Modelica.Utilities.Files.loadResource("modelica://SolarTherm/Data/Schedules/sch_acciona.motab") if not const_dispatch "Discharging schedule from a file";
  // Weather data
  parameter String wea_file_sch = Modelica.Utilities.Files.loadResource("modelica://SolarTherm/Data/Weather/tmy_acc_sch.motab");
  parameter String wea_file = Modelica.Utilities.Files.loadResource("modelica://SolarTherm/Data/Weather/tmy_acc_mod.motab");
  parameter Real wdelay[8] = {0, 0, 0, 0, 0, 0, 0, 0} "Weather file delays";
  parameter nSI.Angle_deg lon = -69.46620 "Longitude (+ve East)";
  parameter nSI.Angle_deg lat = -22.77510 "Latitude (+ve North)";
  parameter nSI.Time_hour t_zone = -3 "Local time zone (UCT=0)";
  parameter Integer year = 2016 "Meteorological year";
  // Field
  parameter String opt_file = Modelica.Utilities.Files.loadResource("modelica://SolarTherm/new_feature_functions/acciona_tables/motab_acciona/field_opt_eff_4ms.motab");
  parameter Solar_angles angles = Solar_angles.ele_azi "Angles used in the lookup table file";
  parameter Real SM = R_des / Q_flow_des "Solar multiple";
  parameter Real land_mult = 6.16783860571 "Land area multiplier";
  parameter SI.Area A_heliostat = 141.8 "Heliostat module reflective area";
  parameter Real he_av_design = 0.8782 "Helisotats availability"; //See which losses are already included in the optical efficiency matrix, the remaining losses should be captured by this term
  parameter SI.Area A_field = n_heliostat * A_heliostat "Heliostat field reflective area";
  parameter Integer n_heliostat = 10600 "Number of heliostats";
  parameter SI.Length H_tower = 220 "Tower height";
  parameter SI.Area A_land = land_mult * A_field + 197434.207385281 "Land area";
  // Receiver
  parameter SI.HeatFlowRate R_des = 710e6 "Receiver design thermal power (with heat losses)";
  parameter SI.Diameter D_receiver = 20.59 "Receiver diameter";
  parameter SI.Length H_receiver = 18.4 "Receiver height";
  parameter SI.Area A_receiver = CN.pi * D_receiver * H_receiver "Receiver aperture area";
  parameter Integer N_pa_rec = 22 "Number of panels in receiver";
  parameter SI.Thickness t_tb_rec = 1.25e-3 "Receiver tube wall thickness";
  parameter SI.Diameter D_tb_rec = 50e-3 "Receiver tube outer diameter";
  parameter Real ar_rec = 18.67 / 15 "Height to diameter aspect ratio of receiver aperture";
  parameter SI.Efficiency ab_rec = 0.94 "Receiver coating absorptance";
  parameter SI.Efficiency em_rec = 0.88 "Receiver coating emissivity";
  parameter Real rec_fr = 1.0 - 0.9569597659257708 "Receiver loss fraction of radiance at design point";
  parameter SI.Temperature rec_T_amb_des = 298.15 "Ambient temperature at design point";
  // Storage
  parameter Real t_storage(unit = "h") = 16 "Hours of storage";
  parameter SI.Energy E_max = t_storage * 3600 * Q_flow_des "Maximum tank stored energy";
  parameter SI.Mass m_max = E_max / (h_hot_set - h_cold_set) "Max salt mass in tanks";
  parameter SI.SpecificEnthalpy h_cold_set = Medium.specificEnthalpy(state_cold_set) "Cold salt specific enthalpy at design";
  parameter SI.SpecificEnthalpy h_hot_set = Medium.specificEnthalpy(state_hot_set) "Hot salt specific enthalpy at design";
  parameter SI.Density rho_cold_set = Medium.density(state_cold_set) "Cold salt density at design";
  parameter SI.Density rho_hot_set = Medium.density(state_hot_set) "Hot salt density at design";
  parameter SI.Volume V_max = m_max / ((rho_hot_set + rho_cold_set) / 2) "Max salt volume in tanks";
  //  parameter SI.Length H_storage = ceil((4 * V_max * tank_ar ^ 2 / CN.pi) ^ (1 / 3)) "Storage tank height";
  //  parameter SI.Diameter D_storage = H_storage / tank_ar "Storage tank diameter";
  parameter SI.Length H_storage_hot = 13.55 "Storage tank height";
  parameter SI.Diameter D_storage_hot = 50.4 "Storage tank diameter";
  parameter SI.Length H_storage_cold = 12.7883 "Storage tank height";
  parameter SI.Diameter D_storage_cold = 51.34 "Storage tank diameter";
  parameter SI.Temperature T_cold_set = CV.from_degC(290) "Cold tank target temperature";
  parameter SI.Temperature T_hot_set = CV.from_degC(565) "Hot tank target temperature";
  parameter SI.Temperature T_cold_start = CV.from_degC(290) "Cold tank starting temperature";
  parameter SI.Temperature T_hot_start = CV.from_degC(565) "Hot tank starting temperature";
  parameter SI.Temperature T_cold_aux_set = CV.from_degC(280) "Cold tank auxiliary heater set-point temperature";
  parameter SI.Temperature T_hot_aux_set = CV.from_degC(500) "Hot tank auxiliary heater set-point temperature";
  parameter Medium.ThermodynamicState state_cold_set = Medium.setState_pTX(Medium.p_default, T_cold_set) "Cold salt thermodynamic state at design";
  parameter Medium.ThermodynamicState state_hot_set = Medium.setState_pTX(Medium.p_default, T_hot_set) "Hold salt thermodynamic state at design";
  parameter Real tnk_fr = 0.01 "Tank loss fraction of tank in one day at design point";
  parameter SI.Temperature tnk_T_amb_des = 298.15 "Ambient temperature at design point";
  parameter Real split_cold = 0.7 "Starting medium fraction in cold tank";
  parameter Boolean tnk_use_p_top = true "true if tank pressure is to connect to weather file";
  parameter Boolean tnk_enable_losses = true "true if the tank heat loss calculation is enabled";
  parameter SI.CoefficientOfHeatTransfer alpha = 3 "Tank constant heat transfer coefficient with ambient";
  parameter SI.SpecificEnergy k_loss_cold = 0.15e3 "Cold pump parasitic power coefficient";
  parameter SI.SpecificEnergy k_loss_hot = 0.55e3 "Hot pump parasitic power coefficient";
  parameter SI.Power W_heater_hot = 30e8 "Hot tank heater capacity";
  parameter SI.Power W_heater_cold = 30e8 "Cold tank heater capacity";
  parameter Real tank_ar = 20 / 18.667 "storage aspect ratio";
  // Power block
  replaceable model Cycle = Models.PowerBlocks.Correlation.Rankine "Rankine cycle regression model";
  replaceable model Cooling = Models.PowerBlocks.Cooling.SAM "PB cooling model";
  parameter SI.Power P_gross = 113.9e6 "Power block gross rating at design point";
  parameter SI.Efficiency eff_blk = 0.43 "Power block efficiency at design point";
  parameter Real par_fr = 0.099099099 "Parasitics fraction of power block rating at design point";
  parameter Real par_fix_fr = 0.0055 "Fixed parasitics as fraction of gross rating";
  parameter Boolean blk_enable_losses = true "true if the power heat loss calculation is enabled";
  parameter Boolean external_parasities = true "true if there is external parasitic power losses";
  parameter Real nu_min_blk = 0.5 "minimum allowed part-load mass flow fraction to power block";
  parameter SI.Power W_base_blk = par_fix_fr * P_gross "Power consumed at all times in power block";
  parameter SI.AbsolutePressure p_blk = 10e6 "Power block operating pressure";
  parameter SI.Temperature blk_T_amb_des = 316.15 "Ambient temperature at design for power block";
  parameter SI.Temperature par_T_amb_des = 298.15 "Ambient temperature at design point";
  parameter Real nu_net_blk = 0.9 "Gross to net power conversion factor at the power block";
  parameter SI.Temperature T_in_ref_blk = from_degC(565) "HTF inlet temperature to power block at design";
  parameter SI.Temperature T_out_ref_blk = from_degC(290) "HTF outlet temperature to power block at design";
  parameter SI.HeatFlowRate Q_flow_des = P_gross / eff_blk "Heat to power block at design";
  parameter SI.MassFlowRate m_flow_blk = Q_flow_des / (h_hot_set - h_cold_set) "Mass flow rate to power block at design point";
  parameter SI.Power P_net = (1 - par_fr) * P_gross "Power block net rating at design point";
  parameter SI.Power P_name = P_net "Nameplate rating of power block";
  // Control
  parameter SI.Angle ele_min = Modelica.SIunits.Conversions.from_deg(0) "Heliostat stow deploy angle";
  parameter Boolean use_wind = true "true if using wind stopping strategy in the solar field";
  parameter SI.Velocity Wspd_max = 15 if use_wind "Wind stow speed";
  parameter Real nu_start = 0 "Minimum energy start-up fraction to start the receiver";
  parameter Real nu_min_sf = 0.125 "Minimum turn-down energy fraction to stop the receiver";
  parameter Real nu_defocus = 0.6 "0.42Energy fraction to the receiver at defocus state";
  parameter Real hot_tnk_empty_lb = 5 "Hot tank empty trigger lower bound (Level below which to stop disptach)";
  parameter Real hot_tnk_empty_ub = 10 "Hot tank empty trigger upper bound (Level above which to start disptach)";
  parameter Real hot_tnk_full_lb = 80 "Hot tank full trigger lower bound";
  parameter Real hot_tnk_full_ub = 90 "Hot tank full trigger upper bound";
  parameter Real cold_tnk_defocus_lb = 5 "Cold tank empty trigger lower bound (Level below which to stop disptach)";
  parameter Real cold_tnk_defocus_ub = 7 "Cold tank empty trigger upper bound (Level above which to start disptach)";
  parameter Real cold_tnk_crit_lb = 0 "Cold tank critically empty trigger lower bound (Level below which to stop disptach)";
  parameter Real cold_tnk_crit_ub = 30 "Cold tank critically empty trigger upper bound (Level above which to start disptach)";
  parameter Real Ti = 1000 "Time constant for integral component of receiver control";
  parameter Real Kp = -10 "Gain of proportional component in receiver control";
  //  parameter Real Ti = 1e-4 "Time constant for integral component of receiver control";
  //  parameter Real Kp = 5e-8 "Gain of proportional component in receiver control";
  parameter SI.MassFlowRate m_flow_fac = SM * Q_flow_des / (h_hot_set - h_cold_set) "Mass flow rate to receiver at design point";
  parameter SI.MassFlowRate m_flow_rec_max = 2000 "Maximum mass flow rate to receiver";
  parameter SI.MassFlowRate m_flow_rec_start = m_flow_fac "Initial or guess value of mass flow rate to receiver in the feedback controller";
  // Cost data in USD (default) or AUD
  parameter Real r_disc = 0.07 "Real discount rate";
  parameter Real r_i = 0.03 "Inflation rate";
  parameter Integer t_life(unit = "year") = 27 "Lifetime of plant";
  parameter Integer t_cons(unit = "year") = 3 "Years of construction";
  parameter Real r_cur = 0.71 "The currency rate from AUD to USD";
  parameter Real f_Subs = 0 "Subsidies on initial investment costs";
  parameter FI.AreaPrice pri_field = if currency == Currency.USD then 180 else 180 / r_cur "Field cost per design aperture area";
  parameter FI.AreaPrice pri_site = if currency == Currency.USD then 20 else 20 / r_cur "Site improvements cost per area";
  parameter FI.EnergyPrice pri_storage = if currency == Currency.USD then 37 / (1e3 * 3600) else 37 / (1e3 * 3600) / r_cur "Storage cost per energy capacity";
  parameter FI.PowerPrice pri_block = if currency == Currency.USD then 1000 / 1e3 else 1000 / r_cur "Power block cost per gross rated power";
  parameter FI.PowerPrice pri_bop = if currency == Currency.USD then 350 / 1e3 else 350 / 1e3 / r_cur "Balance of plant cost per gross rated power";
  parameter FI.AreaPrice pri_land = if currency == Currency.USD then 10000 / 4046.86 else 10000 / 4046.86 / r_cur "Land cost per area";
  parameter Real pri_om_name(unit = "$/W/year") = if currency == Currency.USD then 56.715 / 1e3 else 56.715 / 1e3 / r_cur "Fixed O&M cost per nameplate per year";
  parameter Real pri_om_prod(unit = "$/J/year") = if currency == Currency.USD then 5.7320752 / (1e6 * 3600) else 5.7320752 / (1e6 * 3600) / r_cur "Variable O&M cost per production per year";
  parameter FI.Money C_field = pri_field * A_field "Field cost";
  parameter FI.Money C_site = pri_site * A_field "Site improvements cost";
  parameter FI.Money C_tower = if currency == Currency.USD then 3117043.67 * exp(0.0113 * H_tower) else 3117043.67 * exp(0.0113 * H_tower) / r_cur "Tower cost";
  parameter FI.Money C_receiver = if currency == Currency.USD then 71708855 * (A_receiver / 879.8) ^ 0.7 else 71708855 * (A_receiver / 879.8) ^ 0.7 / r_cur "Receiver cost";
  parameter FI.Money C_storage = pri_storage * E_max "Storage cost";
  parameter FI.Money C_block = pri_block * P_gross "Power block cost";
  parameter FI.Money C_bop = pri_bop * P_gross "Balance of plant cost";
  parameter FI.Money C_cap_dir_sub = (1 - f_Subs) * (C_field + C_site + C_tower + C_receiver + C_storage + C_block + C_bop) "Direct capital cost subtotal";
  parameter FI.Money C_contingency = 0.07 * C_cap_dir_sub "Contingency costs";
  parameter FI.Money C_cap_dir_tot = C_cap_dir_sub + C_contingency "Direct capital cost total";
  parameter FI.Money C_EPC = 0.11 * C_cap_dir_tot "Engineering, procurement and construction(EPC) and owner costs";
  parameter FI.Money C_land = pri_land * A_land "Land cost";
  parameter FI.Money C_cap = C_cap_dir_tot + C_EPC + C_land "Total capital (installed) cost";
  parameter FI.MoneyPerYear C_year = pri_om_name * P_name "Fixed O&M cost per year";
  parameter Real C_prod(unit = "$/J/year") = pri_om_prod "Variable O&M cost per production per year";
  // System components
  // *********************
  //Weather Source Scheduler
  SolarTherm.Models.Sources.Weather.WeatherSource wea(file = wea_file_sch);
  //Weather data
  SolarTherm.Models.Sources.DataTable.DataTable data(lon = lon, lat = lat, t_zone = t_zone, year = year, file = wea_file) annotation(
    Placement(visible = true, transformation(extent = {{-132, -56}, {-102, -28}}, rotation = 0)));
  //DNI_input
  Modelica.Blocks.Sources.RealExpression DNI_input(y = data.DNI) annotation(
    Placement(transformation(extent = {{-140, 60}, {-120, 80}})));
  //Tamb_input
  Modelica.Blocks.Sources.RealExpression Tamb_input(y = data.Tdry) annotation(
    Placement(transformation(extent = {{140, 70}, {120, 90}})));
  //WindSpeed_input
  Modelica.Blocks.Sources.RealExpression Wspd_input(y = data.Wspd) annotation(
    Placement(transformation(origin = {-127, 29.54}, extent = {{-13, -10}, {13, 10}})));
  //pressure_input
  Modelica.Blocks.Sources.RealExpression Pres_input(y = data.Pres) annotation(
    Placement(visible = true, transformation(extent = {{76, 20}, {56, 40}}, rotation = 0)));
  //parasitic inputs
  Modelica.Blocks.Sources.RealExpression parasities_input(y = heliostatsField.W_loss + pumpHot.W_loss + pumpCold.W_loss + tankHot.W_loss) annotation(
    Placement(visible = true, transformation(origin = {117, 58}, extent = {{-13, -10}, {13, 10}}, rotation = -90)));
  // Or block for defocusing
  Modelica.Blocks.Logical.Or or1 annotation(
    Placement(transformation(extent = {{-102, 4}, {-94, 12}})));
  //Sun
  SolarTherm.Models.Sources.SolarModel.Sun sun(lon = data.lon, lat = data.lat, t_zone = data.t_zone, year = data.year, redeclare function solarPosition = Models.Sources.SolarFunctions.PSA_Algorithm) annotation(
    Placement(transformation(extent = {{-82, 60}, {-62, 80}})));
  // Solar field
  SolarTherm.Models.CSP.CRS.HeliostatsField.HeliostatsField heliostatsField(n_h = n_heliostat, lon = data.lon, lat = data.lat, ele_min(displayUnit = "deg") = ele_min, use_wind = use_wind, Wspd_max = Wspd_max, he_av = he_av_design, use_on = true, use_defocus = true, A_h = A_heliostat, nu_defocus = nu_defocus, nu_min = nu_min_sf, Q_design = R_des, nu_start = nu_start, redeclare model Optical = Models.CSP.CRS.HeliostatsField.Optical.Table(angles = angles, file = opt_file)) annotation(
    Placement(transformation(extent = {{-88, 2}, {-56, 36}})));
  // Receiver
  SolarTherm.Models.CSP.CRS.Receivers.ReceiverTransient receiver(em = em_rec, redeclare package Medium = Medium, H_rcv = H_receiver, D_rcv = D_receiver, N_pa = N_pa_rec, t_tb = t_tb_rec, D_tb = D_tb_rec, ab = ab_rec) annotation(
    Placement(transformation(extent = {{-46, 4}, {-10, 40}})));
  // Three-way Valve
  SolarTherm.Models.Fluid.Valves.ValveControl Valve1(redeclare package Medium = Medium) annotation(
    Placement(transformation(origin = {0, 109}, extent = {{-7.5, 0}, {7.5, 7.5}})));
  // Tee
  Modelica.Fluid.Fittings.TeeJunctionIdeal Tee annotation(
    Placement(visible = true, transformation(origin = {96, 42}, extent = {{-6, 6}, {6, -6}}, rotation = 0)));
  // Hot tank 1
  SolarTherm.Models.Storage.Tank.Tank tankHot(redeclare package Medium = Medium, D = D_storage_hot, H = H_storage_hot, L_start = 7, T_set = T_hot_aux_set, T_start = T_hot_start, W_max = W_heater_hot, alpha = alpha, enable_losses = tnk_enable_losses, use_L = true, use_p_top = tnk_use_p_top) annotation(
    Placement(transformation(extent = {{16, 54}, {36, 74}})));
  // Hot tank 2
  SolarTherm.Models.Storage.Tank.Tank tankHot2(redeclare package Medium = Medium, D = D_storage_hot, H = H_storage_hot, L_start = (1 - split_cold) * 100, T_set = T_hot_aux_set, T_start = T_hot_start, W_max = W_heater_hot, alpha = alpha, enable_losses = tnk_enable_losses, use_L = true, use_p_top = tnk_use_p_top) annotation(
    Placement(transformation(origin = {16, 98}, extent = {{0, 0}, {20, 20}})));
  // Pump hot 1
  SolarTherm.Models.Fluid.Pumps.PumpSimple pumpHot(redeclare package Medium = Medium, k_loss = k_loss_hot) annotation(
    Placement(transformation(extent = {{66, 38}, {78, 50}})));
  // Pump hot 2
  // Cold tank
  // Pump cold
  SolarTherm.Models.Fluid.Pumps.PumpSimple pumpCold(redeclare package Medium = Medium, k_loss = k_loss_cold) annotation(
    Placement(transformation(extent = {{10, -30}, {-2, -18}})));
  // PowerBlockControl
  // ReceiverControl
  // Power block
  // Price
  SolarTherm.Models.Analysis.Market market(redeclare model Price = Models.Analysis.EnergyPrice.Constant) annotation(
    Placement(visible = true, transformation(extent = {{144, 4}, {164, 24}}, rotation = 0)));
  // TODO Needs to be configured in instantiation if not const_dispatch. See SimpleResistiveStorage model
  SolarTherm.Models.Sources.Schedule.Scheduler sch_fixed(file = sch_file, ndaily = 1, wmap = {{1, 1, 1, 1, 1, 1, 1}}, mmap = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}) if not const_dispatch;
  // Variables:
  SI.Power P_elec "Output power of power block";
  SI.Energy E_elec(start = 0, fixed = true, displayUnit = "MW.h") "Generate electricity";
  FI.Money R_spot(start = 0, fixed = true) "Spot market revenue";
  SolarTherm.Tank_Cold_Acciona tank_Cold_Acciona(D = D_storage_cold, H = H_storage_cold, L_start = 93, T_set = T_cold_aux_set, T_start = T_cold_start, W_max = W_heater_cold, alpha = alpha, use_L = true) annotation(
    Placement(visible = true, transformation(origin = {66, -22}, extent = {{10, -10}, {-10, 10}}, rotation = 0)));
  SolarTherm.PB_Control_Acciona pB_Control_Acciona(L_df_off = hot_tnk_full_lb, L_df_on = hot_tnk_full_ub, L_off = hot_tnk_empty_lb, L_on = hot_tnk_empty_ub, m_flow_on = m_flow_blk) annotation(
    Placement(visible = true, transformation(origin = {56, 72}, extent = {{-8, 8}, {8, -8}}, rotation = 0)));
  SolarTherm.Models.Fluid.Pumps.PumpSimple pumpSimple(k_loss = k_loss_hot) annotation(
    Placement(visible = true, transformation(extent = {{60, 8}, {72, 20}}, rotation = 0)));
  SolarTherm.PB_Acciona_New_2 pB_Acciona_New_2 annotation(
    Placement(visible = true, transformation(origin = {119, 9}, extent = {{-23, -23}, {23, 23}}, rotation = 0)));
  SolarTherm.NewReceiverControl_Acciona newReceiverControl_Acciona(Kp = Kp, L_df_off = 10, L_df_on = 5, L_off = cold_tnk_crit_lb, L_on = cold_tnk_crit_ub, T_ref = T_hot_set, Ti = Ti, m_flow_max = m_flow_rec_max, y_start = m_flow_rec_start) annotation(
    Placement(visible = true, transformation(origin = {18, 4}, extent = {{10, -10}, {-10, 10}}, rotation = 0)));
equation
//Connections scheduler
  connect(wea.wbus, sch_fixed.wbus);
//Connections from data
  connect(DNI_input.y, sun.dni) annotation(
    Line(points = {{-119, 70}, {-102, 70}, {-102, 69.8}, {-82.6, 69.8}}, color = {0, 0, 127}, pattern = LinePattern.Dot));
  connect(Wspd_input.y, receiver.Wspd) annotation(
    Line(points = {{-112.7, 29.54}, {-100, 29.54}, {-100, 40}, {-31.5, 40}, {-31.5, 37}}, color = {0, 0, 127}, pattern = LinePattern.Dot));
  connect(Wspd_input.y, heliostatsField.Wspd) annotation(
    Line(points = {{-112.7, 29.54}, {-87.68, 29.54}}, color = {0, 0, 127}, pattern = LinePattern.Dot));
  connect(Pres_input.y, tankHot.p_top) annotation(
    Line(points = {{55, 30}, {8, 30}, {8, 78}, {30.5, 78}, {30.5, 73.7}}, color = {0, 0, 127}, pattern = LinePattern.Dot));
  connect(Pres_input.y, tankHot2.p_top) annotation(
    Line(points = {{55, 30}, {8, 30}, {8, 130}, {30.5, 130}, {30.5, 118}}, color = {0, 0, 127}, pattern = LinePattern.Dot));
  connect(Tamb_input.y, tankHot.T_amb) annotation(
    Line(points = {{119, 80}, {21.9, 80}, {21.9, 73.7}}, color = {0, 0, 127}, pattern = LinePattern.Dot));
  connect(Tamb_input.y, tankHot2.T_amb) annotation(
    Line(points = {{119, 80}, {110, 80}, {110, 135}, {21.9, 135}, {21.9, 119}}, color = {0, 0, 127}, pattern = LinePattern.Dot));
  connect(receiver.Tamb, tankHot.T_amb) annotation(
    Line(points = {{-28, 36.04}, {-28, 80}, {21.9, 80}, {21.9, 73.7}}, color = {0, 0, 127}, pattern = LinePattern.Dot));
// Fluid connections
  connect(pumpCold.fluid_b, receiver.fluid_a) annotation(
    Line(points = {{-24.4, 5.8}, {-14.2, 5.8}, {-14.2, -24}, {-2, -24}}, color = {0, 127, 255}));
  connect(receiver.fluid_b, Valve1.fluid_a) annotation(
    Line(points = {{-22, 31}, {-15, 31}, {-15, 113}, {-4, 113}}, color = {0, 127, 255}));
  connect(Valve1.fluid_b1, tankHot2.fluid_a) annotation(
    Line(points = {{3, 113}, {16, 113}}, color = {0, 127, 255}));
  connect(Valve1.fluid_b2, tankHot.fluid_a) annotation(
    Line(points = {{0, 108}, {0, 69}, {16, 69}}, color = {0, 127, 255}));
  connect(tankHot.fluid_b, pumpHot.fluid_a) annotation(
    Line(points = {{36, 57}, {36, 52}, {36, 44}, {48, 44}, {48, 43.88}, {66, 43.88}}, color = {0, 127, 255}));
  connect(pumpHot.fluid_b, Tee.port_1) annotation(
    Line(points = {{78, 44}, {84, 44}, {84, 42}, {90, 42}}, color = {0, 127, 255}));
// controlCold connections
// controlHot connections
//Solar field connections i.e. solar.heat port and control
  connect(sun.solar, heliostatsField.solar) annotation(
    Line(points = {{-72, 60}, {-72, 36}}, color = {255, 128, 0}));
  connect(heliostatsField.heat, receiver.heat) annotation(
    Line(points = {{-55.68, 27.5}, {-54.82, 27.5}, {-54.82, 27.4}, {-46, 27.4}}, color = {191, 0, 0}));
  connect(or1.y, heliostatsField.defocus) annotation(
    Line(points = {{-93.6, 8}, {-92, 8}, {-92, 8.8}, {-87.68, 8.8}}, color = {255, 0, 255}, pattern = LinePattern.Dash));
//PowerBlock connections
  P_elec = pB_Acciona_New_2.W_net;
  E_elec = pB_Acciona_New_2.E_net;
  R_spot = market.profit;
  connect(tank_Cold_Acciona.fluid_b, pumpCold.fluid_a) annotation(
    Line(points = {{56, -29}, {16, -29}, {16, -24}, {10, -24}}, color = {0, 127, 255}));
  connect(Pres_input.y, tank_Cold_Acciona.p_top) annotation(
    Line(points = {{55, 30}, {52, 30}, {52, 0}, {61.5, 0}, {61.5, -12}}, color = {0, 0, 127}));
  connect(Tamb_input.y, tank_Cold_Acciona.T_amb) annotation(
    Line(points = {{120, 80}, {100, 80}, {100, 10}, {70, 10}, {70, -12}}, color = {0, 0, 127}));
//  connect(pB_Control_Acciona.m_flow, pumpHot.m_flow) annotation(
//    Line(points = {{65, 74}, {72, 74}, {72, 50}}, color = {0, 0, 127}));
//  connect(tankHot.L, pB_Control_Acciona.L_mea) annotation(
//    Line(points = {{36, 68}, {40, 68}, {40, 76}, {47, 76}}, color = {0, 0, 127}));
  connect(pumpCold.m_flow, pB_Control_Acciona.m_flow_in) annotation(
    Line(points = {{4, -18}, {4, 38}, {42, 38}, {42, 68}, {47, 68}}, color = {0, 0, 127}));
  connect(pB_Control_Acciona.m_pump2, Valve1.m_flow) annotation(
    Line(points = {{65, 70}, {92, 70}, {92, 130}, {0, 130}, {0, 116}}, color = {0, 0, 127}));
  connect(pB_Control_Acciona.defocus, or1.u1) annotation(
    Line(points = {{56, 81}, {56, 88}, {-108, 88}, {-108, 8}, {-102, 8}}, color = {255, 0, 255}));
  connect(tank_Cold_Acciona.fluid_b2, pumpSimple.fluid_a) annotation(
    Line(points = {{56, -23}, {46, -23}, {46, 14}, {60, 14}}, color = {0, 127, 255}));
  connect(pB_Control_Acciona.m_flow_cold, pumpSimple.m_flow) annotation(
    Line(points = {{64, 66}, {78, 66}, {78, 56}, {50, 56}, {50, 24}, {66, 24}, {66, 19}}, color = {0, 0, 127}));
  connect(tank_Cold_Acciona.L, pB_Control_Acciona.level_cold) annotation(
    Line(points = {{56, -18}, {40, -18}, {40, 64}, {48, 64}}, color = {0, 0, 127}));
  connect(pB_Control_Acciona.m_flow_hot, pumpHot.m_flow) annotation(
    Line(points = {{64, 74}, {72, 74}, {72, 50}, {72, 50}}, color = {0, 0, 127}));
  connect(tankHot.L, pB_Control_Acciona.level_hot) annotation(
    Line(points = {{36, 68}, {40, 68}, {40, 76}, {48, 76}, {48, 76}}, color = {0, 0, 127}));
  connect(pumpSimple.fluid_b, Tee.port_3) annotation(
    Line(points = {{72, 14}, {96, 14}, {96, 36}, {96, 36}}, color = {0, 127, 255}));
  connect(Tee.port_2, pB_Acciona_New_2.fluid_a) annotation(
    Line(points = {{102, 42}, {104, 42}, {104, 18}, {109, 18}, {109, 17}}, color = {0, 127, 255}));
  connect(Tamb_input.y, pB_Acciona_New_2.T_amb) annotation(
    Line(points = {{120, 80}, {108, 80}, {108, 26}, {114, 26}, {114, 22}, {114, 22}}, color = {0, 0, 127}));
  connect(parasities_input.y, pB_Acciona_New_2.parasities) annotation(
    Line(points = {{118, 44}, {116, 44}, {116, 30}, {124, 30}, {124, 22}, {124, 22}}, color = {0, 0, 127}));
  connect(pB_Acciona_New_2.W_net, market.W_net) annotation(
    Line(points = {{130, 8}, {136, 8}, {136, 14}, {144, 14}, {144, 14}}, color = {0, 0, 127}));
  connect(pB_Acciona_New_2.fluid_b, tank_Cold_Acciona.fluid_a) annotation(
    Line(points = {{106, -2}, {86, -2}, {86, -17}, {76, -17}}, color = {0, 127, 255}));
  connect(pB_Acciona_New_2.T, pB_Control_Acciona.T) annotation(
    Line(points = {{106, 4}, {42, 4}, {42, 72}, {46, 72}, {46, 72}, {48, 72}}, color = {0, 0, 127}));
  connect(pB_Control_Acciona.P_SP, pB_Acciona_New_2.P_SP) annotation(
    Line(points = {{52, 64}, {52, 64}, {52, 36}, {48, 36}, {48, 10}, {108, 10}, {108, 10}}, color = {0, 0, 127}));
  connect(newReceiverControl_Acciona.m_flow, pumpCold.m_flow) annotation(
    Line(points = {{7, 4}, {4, 4}, {4, -18}}, color = {0, 0, 127}));
  connect(newReceiverControl_Acciona.defocus, or1.u2) annotation(
    Line(points = {{18, -7}, {18, -12}, {-124, -12}, {-124, 4}, {-102, 4}}, color = {255, 0, 255}));
  connect(heliostatsField.on, newReceiverControl_Acciona.sf_on) annotation(
    Line(points = {{-72, 2}, {-72, -14}, {42, -14}, {42, -2}, {29, -2}}, color = {255, 0, 255}));
  connect(receiver.T, newReceiverControl_Acciona.T_mea) annotation(
    Line(points = {{-22, 22}, {40, 22}, {40, 10}, {29, 10}}, color = {0, 0, 127}));
  connect(receiver.T, newReceiverControl_Acciona.T_mea) annotation(
    Line(points = {{-22, 22}, {38, 22}, {38, 12}, {30, 12}, {30, 14}, {28, 14}}, color = {0, 0, 127}));
  connect(tank_Cold_Acciona.L, newReceiverControl_Acciona.L_mea) annotation(
    Line(points = {{56, -18}, {46, -18}, {46, 4}, {29, 4}}, color = {0, 0, 127}));
  annotation(
    Diagram(coordinateSystem(extent = {{-140, -120}, {160, 140}}, initialScale = 0.1), graphics = {Text(lineColor = {217, 67, 180}, extent = {{-96, 92}, {-60, 90}}, textString = "defocus strategy", fontSize = 9), Text(lineColor = {217, 67, 180}, extent = {{-50, -40}, {-14, -40}}, textString = "on/off strategy", fontSize = 9), Text(origin = {2, 2}, extent = {{-52, 8}, {-4, -12}}, textString = "Receiver", fontSize = 9), Text(origin = {12, 4}, extent = {{-110, 4}, {-62, -16}}, textString = "Heliostats Field", fontSize = 9), Text(origin = {4, -8}, extent = {{-80, 86}, {-32, 66}}, textString = "Sun", fontSize = 9), Text(origin = {20, 50}, extent = {{-10, -5}, {10, 5}}, textString = "Hot Tank", fontSize = 9), Text(extent = {{30, -24}, {78, -44}}, textString = "Cold Tank", fontSize = 9), Text(origin = {4, -2}, extent = {{80, 12}, {128, -8}}, textString = "Power Block", fontSize = 9), Text(origin = {6, 0}, extent = {{112, 16}, {160, -4}}, textString = "Market", fontSize = 9), Text(origin = {2, 4}, extent = {{-6, 20}, {42, 0}}, textString = "Rec Control", fontSize = 9), Text(origin = {55, 55}, extent = {{-15, -5}, {15, 5}}, textString = "PB Control", fontSize = 9), Text(origin = {8, -26}, extent = {{-146, -26}, {-98, -46}}, textString = "Data Source", fontSize = 9)}),
    Icon(coordinateSystem(extent = {{-140, -120}, {160, 140}})),
    experiment(StopTime = 31536000, StartTime = 0, Tolerance = 0.0001, Interval = 60),
    __Dymola_experimentSetupOutput,
    Documentation(revisions = "<html>
	<ul>
	<li> A. Fontalvo Lascano (Marzo 2020) :<br>Released first version. </li>
	</ul>

	</html>"));
end SaltTwoTanks_Acciona_2;