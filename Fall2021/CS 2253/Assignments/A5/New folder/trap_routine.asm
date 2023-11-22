        .ORIG x3000
        LEA R0,MESS
        PUTS
        LD R0,LOC
        TRAP x26 ; string stored at x3100
        PUTS
        HALT
MESS    .STRINGZ "enter line: "
LOC     .FILL x3100
        .END

        
        .ORIG x028A
        ADD R2, R0, #0
INPUT   GETC
        OUT
        ADD R5, R0, #-10
        BRnp STORE
        RTI

STORE   STR R0, R2, #0
        ADD R2, R2, #1
        BR INPUT
        .END
