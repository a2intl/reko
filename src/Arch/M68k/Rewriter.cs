﻿#region License
/* 
 * Copyright (C) 1999-2016 John Källén.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; see the file COPYING.  If not, write to
 * the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.
 */
#endregion

using Reko.Core;
using Reko.Core.Expressions;
using Reko.Core.Operators;
using Reko.Core.Machine;
using Reko.Core.Rtl;
using Reko.Core.Types;
using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;

namespace Reko.Arch.M68k
{
    /// <summary>
    /// Rewrites <seealso cref="M68kInstruction"/>s to <see cref="RtlInstructionCluster"/>s.
    /// </summary>
    /// http://www.easy68k.com/paulrsm/doc/trick68k.htm
    public partial class Rewriter : IEnumerable<RtlInstructionCluster>
    {
        private static Dictionary<int, double> fpuRomConstants;

        // These fields are internal so that the OperandRewriter can use them.
        internal M68kArchitecture arch;
        internal Frame frame;
        internal M68kInstruction di;
        internal RtlEmitter emitter;
        private M68kState state;
        private IRewriterHost host;
        private IEnumerator<M68kInstruction> dasm;
        private RtlInstructionCluster ric;
        private OperandRewriter orw;

        public Rewriter(M68kArchitecture m68kArchitecture, ImageReader rdr, M68kState m68kState, Frame frame, IRewriterHost host)
        {
            this.arch = m68kArchitecture;
            this.state = m68kState;
            this.frame = frame;
            this.host = host;
            this.dasm = arch.CreateDisassemblerImpl(rdr).GetEnumerator();
        }

        public IEnumerator<RtlInstructionCluster> GetEnumerator()
        {
            while (dasm.MoveNext())
            {
                di = dasm.Current;
                ric = new RtlInstructionCluster(di.Address, di.Length);
                ric.Class = RtlClass.Linear;
                emitter = new RtlEmitter(ric.Instructions);
                orw = new OperandRewriter(arch, this.emitter, this.frame, di.dataWidth);
                switch (di.code)
                {
                case Opcode.add: RewriteBinOp((s, d) => emitter.IAdd(d, s), FlagM.CVZNX); break;
                case Opcode.adda: RewriteBinOp((s, d) => emitter.IAdd(d, s)); break;
                case Opcode.addi: RewriteArithmetic((s, d) => emitter.IAdd(d, s)); break;
                case Opcode.addq: RewriteAddSubq((s, d) => emitter.IAdd(d, s)); break;
                case Opcode.addx: RewriteAddSubx(emitter.IAdd); break;
                
                case Opcode.and: RewriteLogical((s, d) => emitter.And(d, s)); break;
                case Opcode.andi: RewriteLogical((s, d) => emitter.And(d, s)); break;
                case Opcode.asl: RewriteArithmetic((s, d) => emitter.Shl(d, s)); break;
                case Opcode.asr: RewriteShift((s, d) => emitter.Sar(d, s)); break;
/*
 * 
 * Mnemonic Condition Encoding Test
T* True 0000 1
F* False 0001 0
HI High 0010 C L Z
LS Low or Same 0011 C V Z
VC Overflow Clear 1000 V
VS Overflow Set 1001 V
 */
                case Opcode.bclr: RewriteBclrBset("__bclr"); break;
                case Opcode.bcc: RewriteBcc(ConditionCode.UGE, FlagM.CF); break;
                case Opcode.bcs: RewriteBcc(ConditionCode.ULT, FlagM.CF); break;
                case Opcode.beq: RewriteBcc(ConditionCode.EQ, FlagM.ZF); break;
                case Opcode.bge: RewriteBcc(ConditionCode.GE, FlagM.NF | FlagM.VF); break;
                case Opcode.bgt: RewriteBcc(ConditionCode.GT, FlagM.NF | FlagM.VF | FlagM.ZF); break;
                case Opcode.bhi: RewriteBcc(ConditionCode.UGT, FlagM.CF | FlagM.ZF); break;
                case Opcode.ble: RewriteBcc(ConditionCode.LE, FlagM.NF | FlagM.VF | FlagM.ZF); break;
                case Opcode.blt: RewriteBcc(ConditionCode.LT, FlagM.CF | FlagM.ZF); break;
                case Opcode.bls: RewriteBcc(ConditionCode.ULE, FlagM.VF | FlagM.ZF); break;
                case Opcode.bmi: RewriteBcc(ConditionCode.LT, FlagM.NF); break;
                case Opcode.bne: RewriteBcc(ConditionCode.NE, FlagM.ZF); break;
                case Opcode.bpl: RewriteBcc(ConditionCode.GT, FlagM.NF); break;
                case Opcode.bvs: RewriteBcc(ConditionCode.OV, FlagM.VF); break;
                case Opcode.bchg: RewriteBchg(); break;
                case Opcode.bra: RewriteBra(); break;
                case Opcode.bset: RewriteBclrBset("__bset"); break;
                case Opcode.bsr: RewriteBsr(); break;
                case Opcode.btst: RewriteBtst(); break;
                case Opcode.clr: RewriteClr(); break;
                case Opcode.cmp: RewriteCmp(); break;
                case Opcode.cmpa: RewriteCmp(); break;
                case Opcode.cmpi: RewriteCmp(); break;
                case Opcode.cmpm: RewriteCmp(); break;
                case Opcode.dbeq: RewriteDbcc(ConditionCode.EQ, FlagM.ZF); break;
                case Opcode.dble: RewriteDbcc(ConditionCode.GT, FlagM.NF | FlagM.VF | FlagM.ZF); break;
                case Opcode.dbhi: RewriteDbcc(ConditionCode.ULE, FlagM.CF | FlagM.ZF); break;
                case Opcode.dbne: RewriteDbcc(ConditionCode.NE, FlagM.ZF); break;
                case Opcode.dbra: RewriteDbcc(ConditionCode.None, 0); break;
                case Opcode.divs: RewriteDiv(emitter.SDiv, PrimitiveType.Int16); break;
                case Opcode.divu: RewriteDiv(emitter.UDiv, PrimitiveType.UInt16); break;
                case Opcode.eor: RewriteLogical((s, d) => emitter.Xor(d, s)); break;
                case Opcode.eori: RewriteLogical((s, d) => emitter.Xor(d, s)); break;
                case Opcode.exg: RewriteExg(); break;
                case Opcode.ext: RewriteExt(); break;
                case Opcode.extb: RewriteExtb(); break;
                case Opcode.fadd: RewriteFBinOp((s, d) => emitter.FAdd(d, s)); break;
                    //$REVIEW: the following don't respect NaN, but NaN typically doesn't exist in HLLs.
                case Opcode.fbnge: RewriteFbcc(ConditionCode.LT); break;
                case Opcode.fbnlt: RewriteFbcc(ConditionCode.GE); break;
                case Opcode.fbnle: RewriteFbcc(ConditionCode.GT); break;
                case Opcode.fcmp: RewriteFcmp(); break;
                case Opcode.fdiv: RewriteFBinOp((s, d) => emitter.FDiv(d, s)); break;
                case Opcode.fmove: RewriteFmove(); break;
                case Opcode.fmovecr: RewriteFmovecr(); break;
                case Opcode.fmovem: RewriteMovem(i => arch.GetRegister(i+Registers.fp0.Number)); break;
                case Opcode.fmul: RewriteFBinOp((s, d) => emitter.FMul(d,s)); break;
                case Opcode.fneg: RewriteFUnaryOp(emitter.Neg); break;
                case Opcode.fsub: RewriteFBinOp((s, d) => emitter.FSub(d, s)); break;

                case Opcode.illegal: if (!RewriteIllegal()) goto default; break;
                case Opcode.jmp: RewriteJmp(); break;
                case Opcode.jsr: RewriteJsr(); break;
                case Opcode.lea: RewriteLea(); break;
                case Opcode.link: RewriteLink(); break;
                case Opcode.lsl: RewriteShift((s, d) => emitter.Shl(d, s)); break;
                case Opcode.lsr: RewriteShift((s, d) => emitter.Shr(d, s)); break;
                case Opcode.move: RewriteMove(true); break;
                case Opcode.movea: RewriteMove(false); break;
                case Opcode.moveq: RewriteMoveq(); break;
                case Opcode.movem: RewriteMovem(arch.GetRegister); break;
                case Opcode.muls: RewriteMul((s, d) => emitter.SMul(d, s)); break;
                case Opcode.mulu: RewriteMul((s, d) => emitter.UMul(d, s)); break;
                case Opcode.neg: RewriteUnary(s => emitter.Neg(s), AllConditions); break;
                case Opcode.negx: RewriteUnary(RewriteNegx, AllConditions); break;
                case Opcode.nop: emitter.Nop(); break;
                case Opcode.not: RewriteUnary(s => emitter.Comp(s), LogicalConditions); break;
                case Opcode.or: RewriteLogical((s, d) => emitter.Or(d, s)); break;
                case Opcode.ori: RewriteLogical((s, d) => emitter.Or(d, s)); break;
                case Opcode.pea: RewritePea(); break;
                case Opcode.rol: RewriteRotation(PseudoProcedure.Rol); break;
                case Opcode.ror: RewriteRotation(PseudoProcedure.Ror);  break;
                case Opcode.roxl: RewriteRotationX(PseudoProcedure.RolC);  break;
                case Opcode.roxr: RewriteRotationX(PseudoProcedure.RorC);  break;
                case Opcode.rts: RewriteRts(); break;
                case Opcode.scc: RewriteScc(ConditionCode.UGE, FlagM.CF); break;
                case Opcode.scs: RewriteScc(ConditionCode.ULT, FlagM.CF); break;
                case Opcode.seq: RewriteScc(ConditionCode.EQ, FlagM.ZF); break;
                case Opcode.sge: RewriteScc(ConditionCode.GE, FlagM.NF | FlagM.VF); break;
                case Opcode.sgt: RewriteScc(ConditionCode.GT, FlagM.NF | FlagM.VF | FlagM.ZF); break;
                case Opcode.shi: RewriteScc(ConditionCode.UGT, FlagM.CF | FlagM.ZF); break;
                case Opcode.sle: RewriteScc(ConditionCode.LE, FlagM.NF | FlagM.VF | FlagM.ZF); break;
                case Opcode.slt: RewriteScc(ConditionCode.LT, FlagM.CF | FlagM.ZF); break;
                case Opcode.sls: RewriteScc(ConditionCode.ULE, FlagM.VF | FlagM.ZF); break;
                case Opcode.smi: RewriteScc(ConditionCode.LT, FlagM.NF); break;
                case Opcode.sne: RewriteScc(ConditionCode.NE, FlagM.ZF); break;
                case Opcode.spl: RewriteScc(ConditionCode.GT, FlagM.NF); break;
                case Opcode.st: orw.RewriteMoveDst(di.op1, di.Address, PrimitiveType.Bool, Constant.True()); break;
                case Opcode.sf: orw.RewriteMoveDst(di.op1, di.Address, PrimitiveType.Bool, Constant.False()); break;
                case Opcode.sub: RewriteArithmetic((s, d) => emitter.ISub(d, s)); break;
                case Opcode.suba: RewriteArithmetic((s, d) => emitter.ISub(d, s)); break;
                case Opcode.subi: RewriteArithmetic((s, d) => emitter.ISub(d, s)); break;
                case Opcode.subq: RewriteAddSubq((s, d) => emitter.ISub(d, s)); break;
                case Opcode.subx: RewriteArithmetic((s, d) => emitter.ISub(emitter.ISub(d, s), frame.EnsureFlagGroup(Registers.ccr, (uint)FlagM.XF, "X", PrimitiveType.Bool))); break;
                case Opcode.swap: RewriteSwap(); break;
                case Opcode.tst: RewriteTst(); break;
                case Opcode.unlk: RewriteUnlk(); break;
                default:
                    throw new AddressCorrelatedException(
                        di.Address,
                        "Rewriting M68k opcode '{0}' is not supported yet.",
                        di.code);
                }
                yield return ric;
            }
            yield break;
        }

        IEnumerator IEnumerable.GetEnumerator()
        {
            return GetEnumerator();
        }

        private RegisterStorage GetRegister(MachineOperand op)
        {
            var rOp = op as RegisterOperand;
            return rOp != null ? rOp.Register : null;
        }

        static Rewriter()
        {
            fpuRomConstants = new Dictionary<int, double>
            {
                { 0x00, Math.PI   } ,
                { 0x0B, Math.Log10(2)  } ,
                { 0x0C, Math.E } ,
                { 0x0D, 1.0 / Math.Log(2) } ,   // Log2(E)
                { 0x0E, Math.Log10(Math.E) } ,
                { 0x0F, 0.0       } ,
                { 0x30, Math.Log(2)     } ,
                { 0x31, Math.Log(10)    } ,
                { 0x32, 100       } ,
                { 0x33, 1e1       } ,
                { 0x34, 1e2       } ,
                { 0x35, 1e4       } ,
                { 0x36, 1e8       } ,
                { 0x37, 1e16      } ,
                { 0x38, 1e32      } ,
                { 0x39, 1e64      } ,
                { 0x3A, 1e128     } ,
                { 0x3B, 1e256     } ,
                // These cannot be represented in a 64-bit IEEE constant,
                // which is the limit of C#.
                //{ 0x3C, 1e512     } ,
                //{ 0x3D, 1e1024    } ,
                //{ 0x3E, 1e2048    } ,
                //{ 0x3F, 1e4096 } }  ,
            };
        }
    }
}
