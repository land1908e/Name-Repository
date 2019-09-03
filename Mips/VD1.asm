addi $s0,$0,0x7acd
addi $s1,$0,0x3c4d
add $s2,$s1,$s0
sub $s3,$1,$s0
la $s6, 0x1001000c
sw $s2, 4($s6)
sw $s3, -8($s6)
lw $s4 , 4($s6)
