model oscillations
  parameter Real omega1 = 17;
  parameter Real omega2 = 6;
  parameter Real omega3 = 8;
  parameter Real gamma2 = 1.7;
  parameter Real gamma3 = 3.6;
  Real x1, y1;
  Real x2, y2;
  Real x3, y3;
initial equation
  x1 = 0.3;
  y1 = 0.7;
  
  x2 = 0.3;
  y2 = 0.7;
  
  x3 = 0.3;
  y3 = 0.7;
equation
  der(x1) = y1;
  der(y1) = -omega1*x1;
  
  der(x2) = y2;
  der(y2) = -gamma2*y2-omega2*x2;
  
  der(x3) = y3;
  der(y3) = -gamma3*y3-omega3*x3+0.6*cos(3*time);
end oscillations;
