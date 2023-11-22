        .ORIG x3000
        LEA R0,MESS
        PUTS
        LD R0,LOC
        TRAP x26 ; string STd at x3100
        PUTS
        HALT
MESS    .STRINGZ "enter line: "
LOC     .FILL x3100
        .END

        
        .ORIG x028A
        ADD R4, R0, #0
UI   GETC
        OUT
        ADD R3, R0, #-10
        BRnp KP
        RTI

KP   STR R0, R4, #0
        ADD R4, R4, #1
        BR UI
        .END
