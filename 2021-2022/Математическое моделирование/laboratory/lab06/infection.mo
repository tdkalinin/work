model infection
  parameter Real alpha = 0.01;
  parameter Real beta = 0.02;
  
  Real I(start = 280);
  Real R(start = 51);
  Real S(start = 11800-280-51);
  
  Real I2(start = 280);
  Real R2(start = 51);
  Real S2(start = 11800-280-51);
equation
  der(S) = 0;
  der(I) = -beta*I;
  der(R) = beta*I;
  
  der(S2) = -alpha*S2;
  der(I2) = alpha*S2-beta*I2;
  der(R2) = beta*I2;
end infection;
