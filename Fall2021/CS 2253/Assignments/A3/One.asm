.ORIG X3000
AND R0, R0, #0 ;USED TO STORE THE SUM OF THE POSITIVE NUMBERS
AND R1, R1, #0 ;USED TO STORE THE SUM OF THE POSITIVE NUMBERS
LD R2, LPTR
CHECK   LDR R3, R2, #0 
        BRP PVESUM
        BRN NVESUM
        BRZ TERSO
PVESUM  ADD R0, R0, R3
        ADD R2, R2, #1
        BRP CHECK
NVESUM  ADD R1, R1, R3
        ADD R2, R2, #1
        BRP CHECK
TERSO   ST R0, PVESTORE
        ST R1, NVESTORE
HALT

PVESTORE    .FILL   X4000
NVESTORE    .FILL   X4001
LPTR        .FILL   X4002
            .END