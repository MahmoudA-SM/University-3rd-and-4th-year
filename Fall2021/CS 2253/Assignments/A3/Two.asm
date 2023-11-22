.ORIG   x3000
AND R0, R0, #0
AND R1, R1, #0
AND R2, R2, #0
AND R3, R3, #0
AND R4, R4, #0
AND R5, R5, #0
AND R6, R6, #0
AND R7, R7, #0
LD R0, LPTR
LD R1, LPTR
ADD R1, R1, #1
CHECK   LDR R2, R0, #0
        LDR R3, R1, #0
        NOT R4, R3
        ADD R4, R4, #1
        ADD R5, R2, R4
        BRN INORDER
        BRP NOTINORDER

INORDER     AND R7, R7, #1
            STI R7, STORE
            ADD R1, R1, #1
            ADD R0, R0, #1
            BRP CHECK
NOTINORDER  AND R6, R6, #0
            STI R6, STORE
HALT
STORE   .FILL   x4000
LPTR    .FILL   #10
.END