.ORIG x3000
        LD R1, ARRAY
        LD R2, SIZE
        LDR R3, R1, #0
        ADD R1, R1, #1
        ADD R2, R2, #-1
TOP     BRp DONE
        LDR R0, R1, #0
        ADD R1,R1,#1
        ADD R4, R4, #1
        ADD R4, R4, R0
        BRnz SKIP
        LDR R3, R4, #0
SKIP    ADD R2, R2, #-1
        BR TOP
DONE    STI R3, MAX
        HALT
ARRAY   .FILL x4000
MAX     .FILL x3400
SIZE    .FILL #100
        .END