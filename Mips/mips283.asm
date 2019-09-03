lui $s3, 0x1001
ori $s3, $s3, 0X0004
lui $s0, 0x1234
ori $s0, $s0, 0xabcd
sw $s0, 0($s3)
lb $t0, 0($s3)
lbu $t1, 0($s3)
lh $t2, 0($s3)
lhu $t3, 0($s3)