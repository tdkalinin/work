model Boat
  import Modelica.Constants.{pi};
  type Angle = Real(unit="radian");
  type Distance = Real(unit="m");
  type Speed = Real(unit="m/s");
  
  parameter Distance k = 10.5*1000;
  parameter Speed v = 50*5/18;
  parameter Distance x1 = 210/67*1000;
  parameter Distance x2 = 105/53*1000;
  parameter Angle phi = 55/180*pi;
  
  Distance ro;
  Distance xkat, ykat;
  Distance xlod, ylod;
  Angle theta;

initial equation
  theta = 0;
  ro = x1;
  
equation
  der(ro) = v;
  ro*der(theta) = sqrt(17.49)*v;
  
  xkat = ro*cos(theta);
  ykat = ro*sin(theta);
  
  xlod = ro*cos(phi);
  ylod = ro*sin(phi);
  
end Boat;
