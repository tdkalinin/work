model combat
  parameter Real a = 0.44;
  parameter Real b = 0.78;
  parameter Real c = 0.56;
  parameter Real h = 0.66;
  
  parameter Real a2 = 0.37;
  parameter Real b2 = 0.79;
  parameter Real c2 = 0.27;
  parameter Real h2 = 0.78;
  
  Real P;
  Real Q;
  
  Real P2;
  Real Q2;
  
  Real x(start = 33700);
  Real y(start = 22400);
  
  Real x2(start = 33700);
  Real y2(start = 22400);
equation
  P = sin(3*time)+1;
  Q = cos(3*time)+1;
  
  P2 = sin(2*time)+1;
  Q2 = cos(2*time)+1;

  der(x)=-a*x-b*y+P;
  der(y)=-c*x-h*y+Q;
  
  der(x2)=-a2*x2-b2*y2+P2;
  der(y2)=-c2*x2*y2-h2*y+Q2;
end combat;
