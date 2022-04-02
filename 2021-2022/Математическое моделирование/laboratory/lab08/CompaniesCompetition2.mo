model CompaniesCompetition2
  parameter Real pcr=26, tau1=25, tau2=14, p1=5.5, p2=11, N=33, q=1;
  parameter Real a1 = pcr/(tau1*tau1*p1*p1*N*q);
  parameter Real a2 = pcr/(tau2*tau2*p2*p2*N*q);
  parameter Real b = pcr/(tau1*tau1*p1*p1*tau2*tau2*p2*p2*N*q);
  parameter Real c1 = (pcr-p1)/(tau1*p1);
  parameter Real c2 = (pcr-p2)/(tau2*p2);
  
  Real M1(start=3.3), M2(start=2.2);
equation
  der(M1) = M1-b/c1*M1*M2-a1/c1*M1*M1;
  der(M2) = c2/c1*M2-(b/c1+0.00033)*M1*M2-a2/c1*M2*M2;
end CompaniesCompetition2;
