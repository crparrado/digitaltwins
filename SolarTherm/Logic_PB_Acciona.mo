within SolarTherm;

model Logic_PB_Acciona
  //power block startup+ time of standby
  // Inputs y Outputs
  Modelica.Blocks.Interfaces.RealInput level_hot annotation(
    Placement(transformation(extent = {{-128, -20}, {-88, 20}})));
  Modelica.Blocks.Interfaces.RealOutput m_flow_hot(max = 1400, min = 0) annotation(
    Placement(transformation(extent = {{90, -20}, {130, 20}})));
   parameter String file_ref_10min = Modelica.Utilities.Files.loadResource("modelica://SolarTherm/new_feature_functions/acciona_tables/motab_acciona/outputs_10min_v2.motab");
  parameter String refi_table = "outputs";
  Modelica.Blocks.Interfaces.RealInput level_cold annotation(
    Placement(visible = true, transformation(extent = {{-128, -72}, {-88, -32}}, rotation = 0), iconTransformation(extent = {{-128, -72}, {-88, -32}}, rotation = 0)));
 Modelica.Blocks.Interfaces.RealInput P_SP(final quantity = "Power", final unit = "MW", displayUnit = "MW", min = 0) annotation(
    Placement(visible = true, transformation(extent = {{-126, 74}, {-86, 114}}, rotation = 0), iconTransformation(extent = {{-60, 78}, {-20, 118}}, rotation = 0)));
  
  Modelica.Blocks.Interfaces.RealOutput m_flow_cold annotation(
    Placement(visible = true, transformation(extent = {{92, -70}, {132, -30}}, rotation = 0), iconTransformation(extent = {{92, -70}, {132, -30}}, rotation = 0)));
  Modelica.Blocks.Interfaces.RealInput t_sgs annotation(
    Placement(visible = true, transformation(extent = {{-126, 34}, {-86, 74}}, rotation = 0), iconTransformation(extent = {{-126, 34}, {-86, 74}}, rotation = 0)));
  
  //////
  // Universal parameters
  parameter Modelica.SIunits.Time t_start = 0.5 * 3600;
  parameter Modelica.SIunits.Time t_standby = 2 * 3600;
  parameter Real m_flow_max;
  parameter Real m_flow_startup;
  parameter Real m_flow_standby;
//  parameter Real level_on = 20;
//  parameter Real level_off = 5;
  parameter Real level_hot_min = 10;
  parameter Real level_cold_max = 70;
  //  Boolean standby;
  //  Boolean startup(start=false, fixed=true);
  //  Boolean on_charge;
  //  Boolean on_discharge;
//  discrete Modelica.SIunits.Time t_off;
//  discrete Modelica.SIunits.Time t_on;
  ///////////
  // States parameters
  //  Integer con_state(min=1, max=5) "Concentrator state";
  Integer blk_state(min = 1, max = 6) "Power block state";
  //Integer sch_state(min=1, max=n_sched_states) "Schedule state";
  //SI.HeatFlowRate Q_flow_sched "Discharge schedule";
  //  SI.HeatFlowRate Q_flow_dis "Heat flow out of tank";
  //  SI.Power P_elec "Output power of power block";
  parameter SI.Efficiency eff_blk = 0.48 "Power block efficiency";
  parameter SI.Power P_name = 100000 "Nameplate rating of power block";
  parameter Real t_storage(unit="h") = 5 "Hours of storage";
  parameter SI.Energy E_max = P_name*t_storage*3600/eff_blk "Max stored energy";
  parameter SI.Energy E_up_u = 0.95 * E_max "Upper energy limit";
  parameter SI.Energy E_up_l = 0.93 * E_max "Upper energy limit";
  parameter SI.Energy E_low_u = 0.07 * E_max "Lower energy limit";
  parameter SI.Energy E_low_l = 0.05 * E_max "Lower energy limit";
  parameter SI.Irradiance dni_stop = 100 "DNI at which concentrator stops";
  parameter SI.Irradiance dni_start = 200 "DNI at which concentrator starts";
  parameter SI.Time t_con_on_delay = 20 * 60 "Delay until concentrator starts";
  parameter SI.Time t_con_off_delay = 15 * 60 "Delay until concentrator shuts off";
  parameter SI.Time t_blk_on_delay = 15 * 60 "Delay until power block starts";
  parameter SI.Time t_blk_off_delay = 10 * 60 "Delay until power block shuts off";
  parameter Integer ramp_order = 1 "ramping filter order";
  parameter SI.Time time_sinchro = 14*60;
  //Schedule
  
  	parameter Integer n_sched_states = 1 "Number of schedule states";
	parameter Integer sch_state_start(min=1, max=n_sched_states) = 1 "Starting schedule state";
	parameter SI.Time t_sch_next_start = 0 "Time to next schedule change";
	parameter SI.HeatFlowRate Q_flow_sched_val[n_sched_states] = {
			P_name/eff_blk
			} "Heat flow at schedule states";
	parameter SI.Time t_delta[n_sched_states] = {
			24*3600
			} "Time differences between schedule states";
  
  
  //Boolean full "True if the storage tank is full";
  //SI.Energy E(min = 0, max = E_max) "Stored energy";
  //  SolarTherm.Utilities.Transition.Ramp ramp_up_con(ramp_order=ramp_order, t_dur= t_con_on_delay, up=true);
  //  SolarTherm.Utilities.Transition.Ramp ramp_down_con(ramp_order=ramp_order, t_dur= t_con_off_delay, up=false);
  //Real fr_ramp_con(min = 0.0, max = 1.0) "ramping transition rate for the concentrator";
//  SolarTherm.Utilities.Transition.Ramp ramp_up_blk(ramp_order = ramp_order, t_dur = t_blk_on_delay, up = true);
//  SolarTherm.Utilities.Transition.Ramp ramp_down_blk(ramp_order = ramp_order, t_dur = t_blk_off_delay, up = false);
//  Real fr_ramp_blk(min = 0.0, max = 1.0) "ramping transition rate for the power block";
  //  SI.Time  t_con_w_now "Time of concentrator current warm-up event";
  //  SI.Time  t_con_w_next "Time of concentrator next warm-up event";
  //  SI.Time  t_con_c_now "Time of concentrator current cool-down event";
  //  SI.Time  t_con_c_next "Time of concentrator next cool-down event";
  SI.Time t_blk_w_now "Time of power block current warm-up event";
  SI.Time t_blk_w_next "Time of power block next warm-up event";
  SI.Time t_blk_c_now "Time of power block current cool-down event";
  SI.Time t_blk_c_next "Time of power block next cool-down event";
  SI.Time t_blk_synchro;
  //SI.Time  t_sch_next "Time of next schedule change";
  //////
  Modelica.Blocks.Interfaces.RealInput m_flow_in annotation(
    Placement(visible = true, transformation(origin = {0, 104}, extent = {{-20, -20}, {20, 20}}, rotation = -90), iconTransformation(extent = {{28, 76}, {68, 116}}, rotation = -90)));
//  Modelica.Blocks.Interfaces.RealInput m_flow_in annotation(
//    Placement(transformation(extent = {{-20, -20}, {20, 20}}, rotation = -90, origin = {0, 104})));

 Modelica.Blocks.Sources.CombiTimeTable ref_table(tableOnFile = true, tableName = refi_table, smoothness = Modelica.Blocks.Types.Smoothness.ContinuousDerivative, fileName = file_ref_10min, columns = 1:39);
//   SI.MassFlowRate m_flow_col;
//   SI.HeatFlowRate P_SGS;
//   SI.Power Net_power;

initial equation
//  pre(t_off) = 0;
//  pre(t_on) = 0;
////Initial equations states
//  E = E_low_l;
//  t_con_w_now = 0;
//  t_con_w_next = 0;
//  t_con_c_now = 0;
//  t_con_c_next = 0;
//Q_flow_sched = Q_flow_sched_val[sch_state_start];
//sch_state = sch_state_start;
//t_sch_next = t_sch_next_start;
  blk_state = 1;
  t_blk_w_now = 0;
  t_blk_w_next = 0;
  t_blk_c_now = 0;
  t_blk_c_next = 0;
  t_blk_synchro = 0;
//  if E > E_up_u then
//    full = true;
//  elseif E < E_up_l then
//    full = false;
//  else
//    full = true;
//  end if;
//////
//Antiguo
//initial equation
//  on_discharge= (level>level_on) and (level>level_off);
////////////////////
// Algoritmo States
algorithm
  //Power Block
  when blk_state == 1 and m_flow_in >= 0 and time > 3600 then
    blk_state := 2;
  elsewhen blk_state == 2 and (time-t_blk_w_now) > 392*60 then
    blk_state := 3;
  elsewhen blk_state == 3 and level_hot >= 1.5*level_hot_min and level_cold < level_cold_max and P_SP >= 10 then
    blk_state := 4;
  elsewhen blk_state == 4 and t_sgs > from_degC(400) then
    blk_state := 5;
  elsewhen blk_state == 5 and (time - t_blk_synchro) > time_sinchro then
    blk_state := 6;
  //elsewhen blk_state == 6 and E <= E_low_l and t_blk_off_delay <= 0 then
//    blk_state := 1;
//  elsewhen blk_state == 2 and time >= t_blk_w_next then
//    blk_state := 3;
//  elsewhen blk_state == 1 and Q_flow_sched > 0 and E >= E_low_u and t_blk_on_delay > 0 then
//    blk_state := 2;
//  elsewhen blk_state == 1 and Q_flow_sched > 0 and E >= E_low_u and t_blk_on_delay <= 0 then
//    blk_state := 3;
//  elsewhen blk_state == 4 and time >= t_blk_c_next then
//    blk_state := 1;
  end when;
  ///////
  
// turn off (or stop ramping) due to no demand
// turn off (or stop ramping) due to empty tank
// ramp down due to no demand
// turn off (no ramp-down) due to no demand
// ramp down due to empty tank
// turn off (no ramp down) due to empty tank
// operational, ramp-up completed
// ramp up, demand and tank has capacity
// operational (no ramp-up)
// turn off after the ramp-down is complete
//	when time >= t_sch_next then
//		sch_state := mod(pre(sch_state), n_sched_states) + 1;
//	end when;
//	when con_state == 2 then
//		t_con_w_now := time;
//		t_con_w_next := time + t_con_on_delay;
//	end when;
//	when con_state == 5 then
//		t_con_c_now := time;
//		t_con_c_next := time + t_con_off_delay;
//	end when;
  when blk_state == 2 then
    t_blk_w_now := time;
    t_blk_w_next := time + t_blk_on_delay;
  end when;
  
  when blk_state == 4 then
    t_blk_c_now := time;
    t_blk_c_next := time + t_blk_off_delay;
  end when;
  
  when blk_state == 5 then
    t_blk_synchro := time;
    //t_blk_w_next := time + t_blk_on_delay;
  end when;
//	for i in 1:n_sched_states loop
//		when sch_state == i then
//			Q_flow_sched := Q_flow_sched_val[i];
//			t_sch_next := time + t_delta[i];
//		end when;
//	end for;
	
//  when E > E_up_u then
//    full := true;
//  elsewhen E < E_up_l then
//    full := false;
//  end when;
//	if con_state == 2 then
//		fr_ramp_con := if ramp_order == 0 then 0.0 else abs(ramp_up_con.y);
//	elseif con_state == 5 then
//		fr_ramp_con := if ramp_order == 0 then 0.0 else abs(ramp_down_con.y);
//	else
//		fr_ramp_con := 0;
//	end if;
//  if blk_state == 2 then
//    fr_ramp_blk := if ramp_order == 0 then 0.0 else abs(ramp_up_blk.y);
//  elseif blk_state == 4 then
//    fr_ramp_blk := if ramp_order == 0 then 0.0 else abs(ramp_down_blk.y);
//  else
//    fr_ramp_blk := 0;
//  end if;
//////////
equation
//Nuevo Control
//  ramp_up_con.x = t_con_w_now;
//  ramp_down_con.x = t_con_c_now;
//  ramp_up_blk.x = t_blk_w_now;
//  ramp_down_blk.x = t_blk_c_now;
//  Q_flow_chg = eff_rec*Q_flow_rec;
//  der(E) = Q_flow_chg - Q_flow_dis;
//	if con_state <= 1 then
//		Q_flow_rec = 0;
//		fr_dfc = 0;
//	elseif con_state == 2 then
//		Q_flow_rec = fr_ramp_con * max(C*wea.wbus.dni*A_rec, 0);
//		fr_dfc = if ramp_order == 0 then 0 else 1;
//	elseif con_state == 5 then
//		Q_flow_rec = fr_ramp_con * max(C*wea.wbus.dni*A_rec, 0);
//		fr_dfc = if ramp_order == 0 then 0 else 1;
//	else
//		if full then
//			if eff_rec*(C*wea.wbus.dni*A_rec) > Q_flow_dis then
//				Q_flow_rec = min(Q_flow_dis/eff_rec, max(C*wea.wbus.dni*A_rec, 0));
//				fr_dfc = Q_flow_dis / (max(C*wea.wbus.dni*A_rec, 0) + 1e-10);
//			else
//				Q_flow_rec = max(C*wea.wbus.dni*A_rec, 0);
//				fr_dfc = 1;
//			end if;
//		else
//			Q_flow_rec = max(C*wea.wbus.dni*A_rec, 0);
//			fr_dfc = 1;
//		end if;
//	end if;
  if blk_state <= 1 then
//Q_flow_dis = 0;
//P_elec = 0;
    m_flow_hot = 0;
    m_flow_cold = 0;
  elseif blk_state == 2 then
//    Q_flow_dis = if ramp_order == 0 then Q_flow_sched else fr_ramp_blk * Q_flow_sched;
//    P_elec = eff_blk * Q_flow_dis;
    //m_flow = m_flow_in;
    m_flow_hot = 0;
    m_flow_cold = 185;
  elseif blk_state == 4 then
//    Q_flow_dis = fr_ramp_blk * Q_flow_sched;
//    P_elec = eff_blk * Q_flow_dis;
  //  m_flow = min(m_flow_in, m_flow_max);
    m_flow_hot = 0.2*658.1;
    m_flow_cold = 0;
    elseif blk_state == 5 then
//    Q_flow_dis = if ramp_order == 0 then Q_flow_sched else fr_ramp_blk * Q_flow_sched;
//    P_elec = eff_blk * Q_flow_dis;
    //m_flow = m_flow_in;
    m_flow_hot = 658.1;
    m_flow_cold = 0;
    
    elseif blk_state == 6 then
//    Q_flow_dis = if ramp_order == 0 then Q_flow_sched else fr_ramp_blk * Q_flow_sched;
//    P_elec = eff_blk * Q_flow_dis;
    //m_flow = m_flow_in;
    m_flow_hot = 658.1;
    m_flow_cold = 0;
  else
//    Q_flow_dis = Q_flow_sched;
//    P_elec = eff_blk * Q_flow_dis;
    m_flow_hot = 0;
    m_flow_cold = 185;
  end if;
//  der(E_elec) = P_elec;
//	der(R_spot) = P_elec*pri.price;
////////////////////////////////////////////
// Antiguo
//  on_charge = m_flow_in > 0;
//  on_discharge=level>level_min;
//  when
//   when level>level_on then
//     on_discharge = true;
//   elsewhen level<level_off then
//     on_discharge = false;
//   end when;
//   when on_charge or on_discharge then
//     t_on = time;
//   end when;
//   when not (on_charge or on_discharge) then
//     t_off = time;
//   end when;
//
//   when t_on-(t_off+t_standby)>0 then
//     startup=true;
//   elsewhen (time-t_on)>t_start then
//     startup=false;
//   end when;
//   standby = (time-t_off)<t_standby;
//   y =if level then (if (startup) then y_start else y_des) else 0;
//  if on_charge or on_discharge then
//    if startup then
//      m_flow = m_flow_startup;
//    else
//      if on_discharge then
//        m_flow = m_flow_max;
//      else
//        m_flow = min(m_flow_in, m_flow_max);
//      end if;
//    end if;
//  else
//    if standby then
//      m_flow = m_flow_standby;
//    else
//      m_flow = 0;
//    end if;
//  end if;
///////////////////////////
  annotation(
    experiment(StartTime = 0.0, StopTime = 31536000.0, Interval = 60, Tolerance = 1e-06));
  annotation(
    Icon(coordinateSystem(preserveAspectRatio = false)),
    Diagram(coordinateSystem(preserveAspectRatio = false)),
    uses(Modelica(version = "3.2.2")));
end Logic_PB_Acciona;