        .ORIG x3000
INPUT   LDI R5, FFE00
        BRzp INPUT
        LDI R0, FFE02
REPEAT    LDI R5, FFE04
        BRzp REPEAT
        STI R0, FFE06
        JSR ISALPHA
        HALT
        

FFS    AND R0, R0, #0
        LD R5, MEMR5
        LD R4, MEMR4
        RET
CHK  LD R5, LS
        ADD R4, R0, R5
        BRn FFS
        LD R5, LE
        ADD R4, R0, R5
        BRp FFS
        AND R0, R0, #0
        ADD R0, R0, #1
        LD R5, MEMR5
        LD R4, MEMR4
        RET
ISALPHA ST R5, MEMR5
        ST R4, MEMR4
        LD R5, US
        ADD R4, R0, R5
        BRn FFS
        LD R5, UE
        ADD R4, R0, R5
        BRp CHK
        AND R0, R0, #0
        ADD R0, R0, #1
        RET
        

        
FFE00    .FILL xFE00
FFE06     .FILL xFE06
FFE04     .FILL xFE04
FFE02    .FILL xFE02

LS  .FILL #-97
US  .FILL #-65
UE  .FILL #-90
LE  .FILL #-122

MEMR5  .BLKW 1
MEMR4  .BLKW 1

        .END