.comment "just a basic living prog"
.name      "civn"

 l2:		sti r1,                      %:label  ,   %1
		and r1,%0,r1
label:
		live %1
		zjmp  %:label

# Executable compile:
#test
# 0x0b,0x68,0x01,0x00,0x0f,0x00,0x01
# 0x06,0x64,0x01,0x00,0x00,0x00,0x00,0x01
# 0x01,0x00,0x00,0x00


#;
#; l2:		sti r1,  %:label  ,   %1
#; l2:
#; sti
#; r1,  %:label  ,   %1
