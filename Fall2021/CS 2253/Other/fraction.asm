        .ORIG x3000
        LD  R0, NUM
        LD  R1, DEN
        JSR GCD
        ADD R4, R1, #0
        ADD R1, R2, #0
        JSR DIVIDE
        ST R2, NUM
        ADD R0, R4, #0
        JSR DIVIDE
        ST R2, DEN
        HALT
; you can try other values for NUM and DEN by replacing these values in the simulator
NUM     .FILL #200 ; you can try other values for NUM and DEN by replacing 
DEN     .FILL #30

; Divide R0 by R1, putting quotient in R2 and remainder in R3
DIVIDE  ST R0, OrgR0
        ST R1, OrgR1
        AND R2, R2, #0
        AND R3, R3, #0
        NOT R1, R1
        ADD R1, R1, #1
LOOP1   ADD R2, R2, #1
        ADD R0, R0, R1
        BRzp LOOP1
        ADD R2, R2, #-1
        ADD R1, R1, #-1
        NOT R1, R1
        ADD R0, R0, R1
        ADD R3, R0, #0

        RET
OrgR0   .BLKW 1
OrgR1   .BLKW 1

; Euclid's algorithm for GCD of R0 and R1, result in R2
GCD     ST R0, OrggR0
        ST R1, OrggR1
        ADD R6, R7, #0
LOOP2   JSR DIVIDE
        ADD R0, R1, #0
        ADD R1, R3, #0
        BRp LOOP2
        ADD R2, R0, #0
        LD R0, OrggR0
        LD R1, OrggR1
        JMP R6
OrggR0  .BLKW 1
OrggR1  .BLKW 1
        .END