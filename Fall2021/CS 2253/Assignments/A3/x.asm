.ORIG x3000
         LD R2, ZERO
         LD R0, M0
         LD R1, M1
LOOP     BRz DONE
         ADD R2, R2, R0
         ADD R1, R1, #-1
         BR LOOP
DONE     ST R2, RESULT
         HALT
RESULT   .FILL x0000 
ZERO     .FILL x0000
M0       .FILL x0003
M1       .FILL x0803
         .END