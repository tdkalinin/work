model ads
  Real n1(start=3), n2(start=3), n3(start=3);
  parameter Real N = 805;
equation
  der(n1) = (0.14+0.00004*n1)*(N-n1);
  der(n2) = (0.000015+0.29*n2)*(N-n2);
  der(n3) = (0.5*sin(0.5*time)+0.7*cos(0.7*time)*n3)*(N-n3);
end ads;
