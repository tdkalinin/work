model predator_prey
  parameter Real a=0.45, b=0.045, c=0.35, d=0.035;
  Real x(start=xc), y(start=yc);
  parameter Real xc=a/b, yc=c/d;
equation
  der(x) = -a*x+b*x*y;
  der(y) = c*y-d*x*y;
end predator_prey;
