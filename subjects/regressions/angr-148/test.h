// test.h
// Generated by decompiling test
// using Reko decompiler version 0.6.1.0.

/*
// Equivalence classes ////////////
Eq_1: (struct "Globals" (40053D Eq_23 t40053D) (400550 Eq_26 t400550) (4005C0 Eq_27 t4005C0) (600E10 (arr Eq_200) a600E10) (600E20 word64 qw600E20) (600FF8 word64 qw600FF8) (601040 byte b601040))
	globals_t (in globals : (ptr (struct "Globals")))
Eq_13: (fn void ())
	T_13 (in rdx : (ptr Eq_13))
	T_28 (in rtld_fini : (ptr (fn void ())))
Eq_16: (fn void (ptr64))
	T_16 (in __align : ptr64)
Eq_21: (fn int32 ((ptr Eq_23), Eq_24, (ptr (ptr char)), (ptr Eq_26), (ptr Eq_27), (ptr Eq_13), (ptr void)))
	T_21 (in __libc_start_main : ptr64)
	T_22 (in signature of __libc_start_main : void)
Eq_23: (fn int32 (int32, (ptr (ptr char)), (ptr (ptr char))))
	T_23 (in main : (ptr (fn int32 (int32, (ptr (ptr char)), (ptr (ptr char))))))
	T_30 (in 0x000000000040053D : word64)
Eq_24: (union "Eq_24" (int32 u0) (word64 u1))
	T_24 (in argc : int32)
	T_31 (in qwArg00 : word64)
Eq_26: (fn void ())
	T_26 (in init : (ptr (fn void ())))
	T_33 (in 0x0000000000400550 : word64)
Eq_27: (fn void ())
	T_27 (in fini : (ptr (fn void ())))
	T_34 (in 0x00000000004005C0 : word64)
Eq_38: (fn void ())
	T_38 (in __hlt : ptr64)
Eq_62: (union "Eq_62" (word32 u0) ((ptr code) u1))
	T_62 (in 0x00000000 : word32)
Eq_70: (union "Eq_70" (int64 u0) (uint64 u1))
	T_70 (in rax_5 >> 0x0000000000000003 : word64)
Eq_73: (union "Eq_73" (int64 u0) (uint64 u1))
	T_73 (in rax_15 : Eq_73)
	T_75 (in (rax_5 >> 0x0000000000000003) + rdx_14 : word64)
Eq_74: (union "Eq_74" (int64 u0) (uint64 u1))
	T_74 (in rax_5 >> 0x0000000000000003 : word64)
Eq_90: (union "Eq_90" (word32 u0) ((ptr code) u1))
	T_90 (in 0x00000000 : word32)
Eq_98: (fn word64 (word64))
	T_98 (in deregister_tm_clones : ptr64)
	T_99 (in signature of deregister_tm_clones : void)
Eq_119: (fn void (word64))
	T_119 (in register_tm_clones : ptr64)
	T_120 (in signature of register_tm_clones : void)
	T_144 (in register_tm_clones : ptr64)
Eq_134: (union "Eq_134" (ptr64 u0) (word32 u1))
	T_134 (in rbp : word64)
	T_135 (in dwLoc04 : word32)
	T_136 (in qwLoc04 : word64)
	T_137 (in DPB(qwLoc04, dwLoc04, 0) : word64)
	T_140 (in fp - 0x0000000000000004 : word64)
Eq_141: (union "Eq_141" (word32 u0) ((ptr code) u1))
	T_141 (in 0x00000000 : word32)
Eq_148: (fn int32 (Eq_150))
	T_148 (in putchar : ptr64)
	T_149 (in signature of putchar : void)
Eq_150: (union "Eq_150" (int32 u0) (word64 u1))
	T_150 (in ch : int32)
	T_153 (in DPB(rdi, 0x00000078, 0) : word64)
Eq_160: (fn word64 (word64))
	T_160 (in f : ptr64)
	T_161 (in signature of f : void)
Eq_167: (fn void ())
	T_167 (in _init : ptr64)
	T_168 (in signature of _init : void)
Eq_200: (union "Eq_200" (word32 u0) ((ptr code) u1))
	T_200 (in r12_19[rbx_28 * 0x00000008] : word32)
// Type Variables ////////////
globals_t: (in globals : (ptr (struct "Globals")))
  Class: Eq_1
  DataType: (ptr Eq_1)
  OrigDataType: (ptr (struct "Globals"))
T_2: (in rax_5 : word64)
  Class: Eq_2
  DataType: word64
  OrigDataType: word64
T_3: (in 0000000000600FF8 : ptr64)
  Class: Eq_3
  DataType: (ptr word64)
  OrigDataType: (ptr (struct (0 T_6 t0000)))
T_4: (in 0x0000000000000000 : word64)
  Class: Eq_4
  DataType: word64
  OrigDataType: word64
T_5: (in 0x0000000000600FF8 + 0x0000000000000000 : word64)
  Class: Eq_5
  DataType: ptr64
  OrigDataType: ptr64
T_6: (in Mem0[0x0000000000600FF8 + 0x0000000000000000:word64] : word64)
  Class: Eq_2
  DataType: word64
  OrigDataType: word64
T_7: (in SZO_6 : byte)
  Class: Eq_7
  DataType: byte
  OrigDataType: byte
T_8: (in cond(rax_5) : byte)
  Class: Eq_7
  DataType: byte
  OrigDataType: byte
T_9: (in 0x0000000000000000 : word64)
  Class: Eq_2
  DataType: word64
  OrigDataType: word64
T_10: (in rax_5 == 0x0000000000000000 : bool)
  Class: Eq_10
  DataType: bool
  OrigDataType: bool
T_11: (in __gmon_start__ : ptr64)
  Class: Eq_11
  DataType: (ptr code)
  OrigDataType: (ptr code)
T_12: (in rax : word64)
  Class: Eq_12
  DataType: word64
  OrigDataType: word64
T_13: (in rdx : (ptr Eq_13))
  Class: Eq_13
  DataType: (ptr Eq_13)
  OrigDataType: (ptr (fn void ()))
T_14: (in qwArg00 : word64)
  Class: Eq_14
  DataType: word64
  OrigDataType: word64
T_15: (in dwArg04 : word32)
  Class: Eq_15
  DataType: word32
  OrigDataType: word32
T_16: (in __align : ptr64)
  Class: Eq_16
  DataType: (ptr Eq_16)
  OrigDataType: (ptr (fn T_20 (T_19)))
T_17: (in fp : ptr64)
  Class: Eq_17
  DataType: (ptr void)
  OrigDataType: (ptr void)
T_18: (in 0x0000000000000008 : word64)
  Class: Eq_18
  DataType: int64
  OrigDataType: int64
T_19: (in fp + 0x0000000000000008 : word64)
  Class: Eq_19
  DataType: ptr64
  OrigDataType: ptr64
T_20: (in __align(fp + 0x0000000000000008) : void)
  Class: Eq_20
  DataType: void
  OrigDataType: void
T_21: (in __libc_start_main : ptr64)
  Class: Eq_21
  DataType: (ptr Eq_21)
  OrigDataType: (ptr (fn T_35 (T_30, T_31, T_32, T_33, T_34, T_13, T_17)))
T_22: (in signature of __libc_start_main : void)
  Class: Eq_21
  DataType: (ptr Eq_21)
  OrigDataType: 
T_23: (in main : (ptr (fn int32 (int32, (ptr (ptr char)), (ptr (ptr char))))))
  Class: Eq_23
  DataType: (ptr Eq_23)
  OrigDataType: 
T_24: (in argc : int32)
  Class: Eq_24
  DataType: Eq_24
  OrigDataType: 
T_25: (in ubp_av : (ptr (ptr char)))
  Class: Eq_25
  DataType: (ptr (ptr char))
  OrigDataType: 
T_26: (in init : (ptr (fn void ())))
  Class: Eq_26
  DataType: (ptr Eq_26)
  OrigDataType: 
T_27: (in fini : (ptr (fn void ())))
  Class: Eq_27
  DataType: (ptr Eq_27)
  OrigDataType: 
T_28: (in rtld_fini : (ptr (fn void ())))
  Class: Eq_13
  DataType: (ptr Eq_13)
  OrigDataType: 
T_29: (in stack_end : (ptr void))
  Class: Eq_17
  DataType: (ptr void)
  OrigDataType: 
T_30: (in 0x000000000040053D : word64)
  Class: Eq_23
  DataType: (ptr Eq_23)
  OrigDataType: (ptr (fn int32 (int32, (ptr (ptr char)), (ptr (ptr char)))))
T_31: (in qwArg00 : word64)
  Class: Eq_24
  DataType: Eq_24
  OrigDataType: (union (int32 u1) (word64 u0))
T_32: (in fp + 0x0000000000000008 : word64)
  Class: Eq_25
  DataType: (ptr (ptr char))
  OrigDataType: (ptr (ptr char))
T_33: (in 0x0000000000400550 : word64)
  Class: Eq_26
  DataType: (ptr Eq_26)
  OrigDataType: (ptr (fn void ()))
T_34: (in 0x00000000004005C0 : word64)
  Class: Eq_27
  DataType: (ptr Eq_27)
  OrigDataType: (ptr (fn void ()))
T_35: (in __libc_start_main(&globals->t40053D, qwArg00, fp + 0x0000000000000008, 0x0000000000400550, 0x00000000004005C0, rdx, fp) : int32)
  Class: Eq_35
  DataType: int32
  OrigDataType: int32
T_36: (in DPB(rax, __libc_start_main(&globals->t40053D, qwArg00, fp + 0x0000000000000008, 0x0000000000400550, 0x00000000004005C0, rdx, fp), 0) : word64)
  Class: Eq_36
  DataType: word64
  OrigDataType: word64
T_37: (in rax_20 : word64)
  Class: Eq_36
  DataType: word64
  OrigDataType: word64
T_38: (in __hlt : ptr64)
  Class: Eq_38
  DataType: (ptr Eq_38)
  OrigDataType: (ptr (fn T_39 ()))
T_39: (in __hlt() : void)
  Class: Eq_39
  DataType: void
  OrigDataType: void
T_40: (in rsp : ptr64)
  Class: Eq_40
  DataType: ptr64
  OrigDataType: word64
T_41: (in r8 : word64)
  Class: Eq_41
  DataType: word64
  OrigDataType: word64
T_42: (in rax_5 : uint64)
  Class: Eq_42
  DataType: uint64
  OrigDataType: uint64
T_43: (in rax : word64)
  Class: Eq_43
  DataType: word64
  OrigDataType: word64
T_44: (in 0x00601047 : word32)
  Class: Eq_44
  DataType: word32
  OrigDataType: word32
T_45: (in DPB(rax, 0x00601047, 0) : word64)
  Class: Eq_42
  DataType: uint64
  OrigDataType: word64
T_46: (in SCZO_11 : byte)
  Class: Eq_46
  DataType: byte
  OrigDataType: byte
T_47: (in 0x000000000000000E : word64)
  Class: Eq_42
  DataType: uint64
  OrigDataType: uint64
T_48: (in rax_5 - 0x000000000000000E : word64)
  Class: Eq_48
  DataType: word64
  OrigDataType: word64
T_49: (in cond(rax_5 - 0x000000000000000E) : byte)
  Class: Eq_46
  DataType: byte
  OrigDataType: byte
T_50: (in rax_5 > 0x000000000000000E : bool)
  Class: Eq_50
  DataType: bool
  OrigDataType: bool
T_51: (in rax_38 : word64)
  Class: Eq_51
  DataType: word64
  OrigDataType: word64
T_52: (in 0x00000000 : word32)
  Class: Eq_52
  DataType: word32
  OrigDataType: word32
T_53: (in DPB(rax, 0x00000000, 0) : word64)
  Class: Eq_51
  DataType: word64
  OrigDataType: word64
T_54: (in SZO_39 : byte)
  Class: Eq_54
  DataType: byte
  OrigDataType: byte
T_55: (in cond(rax_38) : byte)
  Class: Eq_54
  DataType: byte
  OrigDataType: byte
T_56: (in 0x0000000000000000 : word64)
  Class: Eq_51
  DataType: word64
  OrigDataType: word64
T_57: (in rax_38 == 0x0000000000000000 : bool)
  Class: Eq_57
  DataType: bool
  OrigDataType: bool
T_58: (in fp : ptr64)
  Class: Eq_58
  DataType: ptr64
  OrigDataType: ptr64
T_59: (in 0x0000000000000004 : word64)
  Class: Eq_59
  DataType: int64
  OrigDataType: int64
T_60: (in fp + 0x0000000000000004 : word64)
  Class: Eq_40
  DataType: ptr64
  OrigDataType: ptr64
T_61: (in rsp_45 : ptr64)
  Class: Eq_40
  DataType: ptr64
  OrigDataType: word64
T_62: (in 0x00000000 : word32)
  Class: Eq_62
  DataType: word32
  OrigDataType: (union (word32 u0) ((ptr code) u1))
T_63: (in r8 : word64)
  Class: Eq_63
  DataType: word64
  OrigDataType: word64
T_64: (in rax_5 : int64)
  Class: Eq_64
  DataType: int64
  OrigDataType: int64
T_65: (in rax : word64)
  Class: Eq_65
  DataType: word64
  OrigDataType: word64
T_66: (in 0x00601040 : word32)
  Class: Eq_66
  DataType: word32
  OrigDataType: word32
T_67: (in DPB(rax, 0x00601040, 0) : word64)
  Class: Eq_64
  DataType: int64
  OrigDataType: word64
T_68: (in rdx_14 : uint64)
  Class: Eq_68
  DataType: uint64
  OrigDataType: uint64
T_69: (in 0x0000000000000003 : word64)
  Class: Eq_69
  DataType: word64
  OrigDataType: word64
T_70: (in rax_5 >> 0x0000000000000003 : word64)
  Class: Eq_70
  DataType: Eq_70
  OrigDataType: (union (int64 u0) (uint64 u1))
T_71: (in 0x000000000000003F : word64)
  Class: Eq_71
  DataType: word64
  OrigDataType: word64
T_72: (in rax_5 >> 0x0000000000000003 >> 0x000000000000003F : word64)
  Class: Eq_68
  DataType: uint64
  OrigDataType: uint64
T_73: (in rax_15 : Eq_73)
  Class: Eq_73
  DataType: Eq_73
  OrigDataType: (union (int64 u0) (uint64 u1))
T_74: (in rax_5 >> 0x0000000000000003 : word64)
  Class: Eq_74
  DataType: Eq_74
  OrigDataType: (union (int64 u0) (uint64 u1))
T_75: (in (rax_5 >> 0x0000000000000003) + rdx_14 : word64)
  Class: Eq_73
  DataType: Eq_73
  OrigDataType: uint64
T_76: (in SCZO_17 : byte)
  Class: Eq_76
  DataType: byte
  OrigDataType: byte
T_77: (in 0x0000000000000001 : word64)
  Class: Eq_77
  DataType: word64
  OrigDataType: word64
T_78: (in rax_15 >> 0x0000000000000001 : word64)
  Class: Eq_78
  DataType: int64
  OrigDataType: int64
T_79: (in cond(rax_15 >> 0x0000000000000001) : byte)
  Class: Eq_76
  DataType: byte
  OrigDataType: byte
T_80: (in rax_15 >> 0x0000000000000001 : word64)
  Class: Eq_80
  DataType: int64
  OrigDataType: int64
T_81: (in 0x0000000000000000 : word64)
  Class: Eq_80
  DataType: int64
  OrigDataType: word64
T_82: (in rax_15 >> 0x0000000000000001 != 0x0000000000000000 : bool)
  Class: Eq_82
  DataType: bool
  OrigDataType: bool
T_83: (in rdx_46 : uint64)
  Class: Eq_83
  DataType: uint64
  OrigDataType: uint64
T_84: (in 0x00000000 : word32)
  Class: Eq_84
  DataType: word32
  OrigDataType: word32
T_85: (in DPB(rdx_14, 0x00000000, 0) : word64)
  Class: Eq_83
  DataType: uint64
  OrigDataType: uint64
T_86: (in SZO_47 : byte)
  Class: Eq_86
  DataType: byte
  OrigDataType: byte
T_87: (in cond(rdx_46) : byte)
  Class: Eq_86
  DataType: byte
  OrigDataType: byte
T_88: (in 0x0000000000000000 : word64)
  Class: Eq_83
  DataType: uint64
  OrigDataType: word64
T_89: (in rdx_46 == 0x0000000000000000 : bool)
  Class: Eq_89
  DataType: bool
  OrigDataType: bool
T_90: (in 0x00000000 : word32)
  Class: Eq_90
  DataType: word32
  OrigDataType: (union (word32 u0) ((ptr code) u1))
T_91: (in r8 : word64)
  Class: Eq_41
  DataType: word64
  OrigDataType: word64
T_92: (in 0000000000601040 : ptr64)
  Class: Eq_92
  DataType: (ptr byte)
  OrigDataType: (ptr (struct (0 T_95 t0000)))
T_93: (in 0x0000000000000000 : word64)
  Class: Eq_93
  DataType: word64
  OrigDataType: word64
T_94: (in 0x0000000000601040 + 0x0000000000000000 : word64)
  Class: Eq_94
  DataType: ptr64
  OrigDataType: ptr64
T_95: (in Mem0[0x0000000000601040 + 0x0000000000000000:byte] : byte)
  Class: Eq_95
  DataType: byte
  OrigDataType: byte
T_96: (in 0x00 : byte)
  Class: Eq_95
  DataType: byte
  OrigDataType: byte
T_97: (in *&globals->b601040 != 0x00 : bool)
  Class: Eq_97
  DataType: bool
  OrigDataType: bool
T_98: (in deregister_tm_clones : ptr64)
  Class: Eq_98
  DataType: (ptr Eq_98)
  OrigDataType: (ptr (fn T_100 (T_91)))
T_99: (in signature of deregister_tm_clones : void)
  Class: Eq_98
  DataType: (ptr Eq_98)
  OrigDataType: 
T_100: (in deregister_tm_clones(r8) : word64)
  Class: Eq_100
  DataType: word64
  OrigDataType: word64
T_101: (in 0x01 : byte)
  Class: Eq_101
  DataType: byte
  OrigDataType: byte
T_102: (in 0000000000601040 : ptr64)
  Class: Eq_102
  DataType: (ptr byte)
  OrigDataType: (ptr (struct (0 T_105 t0000)))
T_103: (in 0x0000000000000000 : word64)
  Class: Eq_103
  DataType: word64
  OrigDataType: word64
T_104: (in 0x0000000000601040 + 0x0000000000000000 : word64)
  Class: Eq_104
  DataType: ptr64
  OrigDataType: ptr64
T_105: (in Mem18[0x0000000000601040 + 0x0000000000000000:byte] : byte)
  Class: Eq_101
  DataType: byte
  OrigDataType: byte
T_106: (in r8 : word64)
  Class: Eq_63
  DataType: word64
  OrigDataType: word64
T_107: (in fp : ptr64)
  Class: Eq_107
  DataType: ptr64
  OrigDataType: ptr64
T_108: (in rsp : word64)
  Class: Eq_107
  DataType: ptr64
  OrigDataType: ptr64
T_109: (in 0000000000600E20 : ptr64)
  Class: Eq_109
  DataType: (ptr word64)
  OrigDataType: (ptr (struct (0 T_112 t0000)))
T_110: (in 0x0000000000000000 : word64)
  Class: Eq_110
  DataType: word64
  OrigDataType: word64
T_111: (in 0x0000000000600E20 + 0x0000000000000000 : word64)
  Class: Eq_111
  DataType: ptr64
  OrigDataType: ptr64
T_112: (in Mem0[0x0000000000600E20 + 0x0000000000000000:word64] : word64)
  Class: Eq_112
  DataType: word64
  OrigDataType: word64
T_113: (in 0x0000000000000000 : word64)
  Class: Eq_113
  DataType: word64
  OrigDataType: word64
T_114: (in *&globals->qw600E20 - 0x0000000000000000 : word64)
  Class: Eq_114
  DataType: word64
  OrigDataType: word64
T_115: (in cond(*&globals->qw600E20 - 0x0000000000000000) : byte)
  Class: Eq_115
  DataType: byte
  OrigDataType: byte
T_116: (in SCZO : byte)
  Class: Eq_115
  DataType: byte
  OrigDataType: byte
T_117: (in Z : byte)
  Class: Eq_115
  DataType: byte
  OrigDataType: byte
T_118: (in Test(EQ,Z) : bool)
  Class: Eq_118
  DataType: Eq_118
  OrigDataType: 
T_119: (in register_tm_clones : ptr64)
  Class: Eq_119
  DataType: (ptr Eq_119)
  OrigDataType: (ptr (fn T_121 (T_106)))
T_120: (in signature of register_tm_clones : void)
  Class: Eq_119
  DataType: (ptr Eq_119)
  OrigDataType: 
T_121: (in register_tm_clones(r8) : void)
  Class: Eq_121
  DataType: void
  OrigDataType: void
T_122: (in 0x00000000 : word32)
  Class: Eq_122
  DataType: word32
  OrigDataType: word32
T_123: (in eax : word32)
  Class: Eq_122
  DataType: word32
  OrigDataType: word32
T_124: (in rax : word64)
  Class: Eq_124
  DataType: ui64
  OrigDataType: ui64
T_125: (in DPB(rax, eax, 0) : word64)
  Class: Eq_124
  DataType: ui64
  OrigDataType: word64
T_126: (in rax & rax : word64)
  Class: Eq_126
  DataType: ui64
  OrigDataType: ui64
T_127: (in cond(rax & rax) : byte)
  Class: Eq_115
  DataType: byte
  OrigDataType: byte
T_128: (in SZO : byte)
  Class: Eq_115
  DataType: byte
  OrigDataType: byte
T_129: (in false : bool)
  Class: Eq_129
  DataType: bool
  OrigDataType: bool
T_130: (in C : byte)
  Class: Eq_129
  DataType: bool
  OrigDataType: bool
T_131: (in Test(EQ,Z) : bool)
  Class: Eq_131
  DataType: Eq_131
  OrigDataType: 
T_132: (in 0x0000000000000004 : word64)
  Class: Eq_132
  DataType: ui64
  OrigDataType: ui64
T_133: (in fp - 0x0000000000000004 : word64)
  Class: Eq_107
  DataType: ptr64
  OrigDataType: ptr64
T_134: (in rbp : word64)
  Class: Eq_134
  DataType: Eq_134
  OrigDataType: ptr64
T_135: (in dwLoc04 : word32)
  Class: Eq_134
  DataType: Eq_134
  OrigDataType: (union (ptr64 u0) (word32 u1))
T_136: (in qwLoc04 : word64)
  Class: Eq_134
  DataType: Eq_134
  OrigDataType: word64
T_137: (in DPB(qwLoc04, dwLoc04, 0) : word64)
  Class: Eq_134
  DataType: Eq_134
  OrigDataType: word64
T_138: (in 0x00600E20 : word32)
  Class: Eq_138
  DataType: word32
  OrigDataType: word32
T_139: (in edi : word32)
  Class: Eq_138
  DataType: word32
  OrigDataType: word32
T_140: (in fp - 0x0000000000000004 : word64)
  Class: Eq_134
  DataType: Eq_134
  OrigDataType: ptr64
T_141: (in 0x00000000 : word32)
  Class: Eq_141
  DataType: word32
  OrigDataType: (union (word32 u0) ((ptr code) u1))
T_142: (in 0x0000000000000004 : word64)
  Class: Eq_142
  DataType: int64
  OrigDataType: int64
T_143: (in fp + 0x0000000000000004 : word64)
  Class: Eq_107
  DataType: ptr64
  OrigDataType: ptr64
T_144: (in register_tm_clones : ptr64)
  Class: Eq_119
  DataType: (ptr Eq_119)
  OrigDataType: (ptr (fn T_145 (T_106)))
T_145: (in register_tm_clones(r8) : void)
  Class: Eq_121
  DataType: void
  OrigDataType: void
T_146: (in rsp : ptr64)
  Class: Eq_146
  DataType: ptr64
  OrigDataType: word64
T_147: (in rax : word64)
  Class: Eq_147
  DataType: word64
  OrigDataType: word64
T_148: (in putchar : ptr64)
  Class: Eq_148
  DataType: (ptr Eq_148)
  OrigDataType: (ptr (fn T_154 (T_153)))
T_149: (in signature of putchar : void)
  Class: Eq_148
  DataType: (ptr Eq_148)
  OrigDataType: 
T_150: (in ch : int32)
  Class: Eq_150
  DataType: Eq_150
  OrigDataType: 
T_151: (in rdi : word64)
  Class: Eq_151
  DataType: word64
  OrigDataType: word64
T_152: (in 0x00000078 : word32)
  Class: Eq_152
  DataType: word32
  OrigDataType: word32
T_153: (in DPB(rdi, 0x00000078, 0) : word64)
  Class: Eq_150
  DataType: Eq_150
  OrigDataType: (union (int32 u1) (word64 u0))
T_154: (in putchar(DPB(rdi, 0x00000078, 0)) : int32)
  Class: Eq_154
  DataType: int32
  OrigDataType: int32
T_155: (in DPB(rax, putchar(DPB(rdi, 0x00000078, 0)), 0) : word64)
  Class: Eq_155
  DataType: word64
  OrigDataType: word64
T_156: (in rax_12 : word64)
  Class: Eq_155
  DataType: word64
  OrigDataType: word64
T_157: (in fp : ptr64)
  Class: Eq_157
  DataType: ptr64
  OrigDataType: ptr64
T_158: (in 0x0000000000000004 : word64)
  Class: Eq_158
  DataType: int64
  OrigDataType: int64
T_159: (in fp + 0x0000000000000004 : word64)
  Class: Eq_146
  DataType: ptr64
  OrigDataType: ptr64
T_160: (in f : ptr64)
  Class: Eq_160
  DataType: (ptr Eq_160)
  OrigDataType: (ptr (fn T_165 (T_164)))
T_161: (in signature of f : void)
  Class: Eq_160
  DataType: (ptr Eq_160)
  OrigDataType: 
T_162: (in rax : word64)
  Class: Eq_162
  DataType: word64
  OrigDataType: word64
T_163: (in 0x00000000 : word32)
  Class: Eq_163
  DataType: word32
  OrigDataType: word32
T_164: (in DPB(rax, 0x00000000, 0) : word64)
  Class: Eq_147
  DataType: word64
  OrigDataType: word64
T_165: (in f(DPB(rax, 0x00000000, 0)) : word64)
  Class: Eq_165
  DataType: word64
  OrigDataType: word64
T_166: (in rsi : word64)
  Class: Eq_166
  DataType: word64
  OrigDataType: word64
T_167: (in _init : ptr64)
  Class: Eq_167
  DataType: (ptr Eq_167)
  OrigDataType: (ptr (fn T_169 ()))
T_168: (in signature of _init : void)
  Class: Eq_167
  DataType: (ptr Eq_167)
  OrigDataType: 
T_169: (in _init() : void)
  Class: Eq_169
  DataType: void
  OrigDataType: void
T_170: (in r12_19 : (arr Eq_200))
  Class: Eq_170
  DataType: (ptr (arr Eq_200))
  OrigDataType: (ptr (struct (0 (arr T_204) a0000)))
T_171: (in 0000000000600E10 : ptr64)
  Class: Eq_170
  DataType: (ptr (arr Eq_200))
  OrigDataType: ptr64
T_172: (in rbp_26 : int64)
  Class: Eq_172
  DataType: int64
  OrigDataType: int64
T_173: (in 0000000000600E18 : ptr64)
  Class: Eq_173
  DataType: ptr64
  OrigDataType: ptr64
T_174: (in 0x0000000000600E18 - r12_19 : word64)
  Class: Eq_172
  DataType: int64
  OrigDataType: 
T_175: (in r15d_65 : word32)
  Class: Eq_175
  DataType: word32
  OrigDataType: word32
T_176: (in edi : word32)
  Class: Eq_175
  DataType: word32
  OrigDataType: word32
T_177: (in r14_11 : word64)
  Class: Eq_166
  DataType: word64
  OrigDataType: word64
T_178: (in r13_16 : word64)
  Class: Eq_178
  DataType: word64
  OrigDataType: word64
T_179: (in rdx : word64)
  Class: Eq_178
  DataType: word64
  OrigDataType: word64
T_180: (in rbx_28 : ui64)
  Class: Eq_180
  DataType: ui64
  OrigDataType: ui64
T_181: (in rbx : word64)
  Class: Eq_181
  DataType: word64
  OrigDataType: word64
T_182: (in 0x00000000 : word32)
  Class: Eq_182
  DataType: word32
  OrigDataType: word32
T_183: (in DPB(rbx, 0x00000000, 0) : word64)
  Class: Eq_180
  DataType: ui64
  OrigDataType: word64
T_184: (in SCZO_31 : byte)
  Class: Eq_184
  DataType: byte
  OrigDataType: byte
T_185: (in fp : ptr64)
  Class: Eq_185
  DataType: ptr64
  OrigDataType: ptr64
T_186: (in 0x0000000000000020 : word64)
  Class: Eq_186
  DataType: ui64
  OrigDataType: ui64
T_187: (in fp - 0x0000000000000020 : word64)
  Class: Eq_187
  DataType: ptr64
  OrigDataType: ptr64
T_188: (in cond(fp - 0x0000000000000020) : byte)
  Class: Eq_184
  DataType: byte
  OrigDataType: byte
T_189: (in SZO_32 : byte)
  Class: Eq_189
  DataType: byte
  OrigDataType: byte
T_190: (in 0x0000000000000003 : word64)
  Class: Eq_190
  DataType: word64
  OrigDataType: word64
T_191: (in rbp_26 >> 0x0000000000000003 : word64)
  Class: Eq_191
  DataType: int64
  OrigDataType: int64
T_192: (in cond(rbp_26 >> 0x0000000000000003) : byte)
  Class: Eq_189
  DataType: byte
  OrigDataType: byte
T_193: (in rbp_26 >> 0x0000000000000003 : word64)
  Class: Eq_193
  DataType: int64
  OrigDataType: int64
T_194: (in 0x0000000000000000 : word64)
  Class: Eq_193
  DataType: int64
  OrigDataType: word64
T_195: (in rbp_26 >> 0x0000000000000003 == 0x0000000000000000 : bool)
  Class: Eq_195
  DataType: bool
  OrigDataType: bool
T_196: (in rbp_75 : word64)
  Class: Eq_196
  DataType: word64
  OrigDataType: word64
T_197: (in rbx_79 : word64)
  Class: Eq_197
  DataType: word64
  OrigDataType: word64
T_198: (in 0x00000008 : word32)
  Class: Eq_198
  DataType: ui32
  OrigDataType: ui32
T_199: (in rbx_28 * 0x00000008 : word64)
  Class: Eq_199
  DataType: ui64
  OrigDataType: ui64
T_200: (in r12_19[rbx_28 * 0x00000008] : word32)
  Class: Eq_200
  DataType: Eq_200
  OrigDataType: (union (word32 u0) ((ptr code) u1))
T_201: (in 0x0000000000000001 : word64)
  Class: Eq_201
  DataType: word64
  OrigDataType: word64
T_202: (in rbx_79 + 0x0000000000000001 : word64)
  Class: Eq_196
  DataType: word64
  OrigDataType: word64
T_203: (in rbx_79 + 0x0000000000000001 != rbp_75 : bool)
  Class: Eq_203
  DataType: bool
  OrigDataType: bool
T_204:
  Class: Eq_204
  DataType: Eq_200
  OrigDataType: (struct 0008 (0 T_200 t0000))
*/
typedef struct Globals {
	Eq_23 t40053D;	// 40053D
	Eq_26 t400550;	// 400550
	Eq_27 t4005C0;	// 4005C0
	Eq_200 a600E10[];	// 600E10
	word64 qw600E20;	// 600E20
	word64 qw600FF8;	// 600FF8
	byte b601040;	// 601040
} Eq_1;

typedef void (Eq_13)();

typedef void (Eq_16)(ptr64);

typedef int32 (Eq_21)( *, Eq_24, char * *,  *,  *,  *, void);

typedef int32 (Eq_23)(int32 rdi, char * * rsi, char * * rdx);

typedef union Eq_24 {
	int32 u0;
	word64 u1;
} Eq_24;

typedef void (Eq_26)();

typedef void (Eq_27)();

typedef void (Eq_38)();

typedef union Eq_62 {
	word32 u0;
	<anonymous> * u1;
} Eq_62;

typedef union Eq_70 {
	int64 u0;
	uint64 u1;
} Eq_70;

typedef union Eq_73 {
	int64 u0;
	uint64 u1;
} Eq_73;

typedef union Eq_74 {
	int64 u0;
	uint64 u1;
} Eq_74;

typedef union Eq_90 {
	word32 u0;
	<anonymous> * u1;
} Eq_90;

typedef word64 (Eq_98)(word64);

typedef void (Eq_119)(word64);

typedef union Eq_134 {
	ptr64 u0;
	word32 u1;
} Eq_134;

typedef union Eq_141 {
	word32 u0;
	<anonymous> * u1;
} Eq_141;

typedef int32 (Eq_148)(Eq_150);

typedef union Eq_150 {
	int32 u0;
	word64 u1;
} Eq_150;

typedef word64 (Eq_160)(word64);

typedef void (Eq_167)();

typedef union Eq_200 {
	word32 u0;
	<anonymous> * u1;
} Eq_200;

