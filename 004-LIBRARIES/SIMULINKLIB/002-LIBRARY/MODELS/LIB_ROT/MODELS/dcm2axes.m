function [ Bx_A, By_A, Bz_A ] = dcm2axes( A_B )
   %#codegen
  Bx_A = A_B*[1; 0; 0];
  By_A = A_B*[0; 1; 0];
  Bz_A = A_B*[0; 0; 1];
  
  
end

