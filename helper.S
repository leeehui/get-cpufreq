
.text
.align 32
.global add_calibration_x86
add_calibration_x86:
	sub  $0x1, %rdi
	sub  $0x1, %rdi
	jge add_calibration_x86
	ret
