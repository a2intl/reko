﻿#region License
/* 
 * Copyright (C) 1999-2013 John Källén.
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

using Decompiler.Core;
using Decompiler.Core.Expressions;
using Decompiler.Core.Lib;
using Decompiler.Core.Machine;
using Decompiler.Core.Types;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Decompiler.Arch.Sparc
{
    public static class Registers
    {
        public static RegisterStorage g0;
        public static RegisterStorage g1;
        public static RegisterStorage g2;
        public static RegisterStorage g3;
        public static RegisterStorage g4;
        public static RegisterStorage g5;
        public static RegisterStorage g6;
        public static RegisterStorage g7;

        public static RegisterStorage o0;   // outgoing paramter 0 / return valie from callee
        public static RegisterStorage o1;
        public static RegisterStorage o2;
        public static RegisterStorage o3;
        public static RegisterStorage o4;
        public static RegisterStorage o5;
        public static RegisterStorage sp;   // stack pointer
        public static RegisterStorage o7;

        public static RegisterStorage l0;
        public static RegisterStorage l1;
        public static RegisterStorage l2;
        public static RegisterStorage l3;
        public static RegisterStorage l4;
        public static RegisterStorage l5;
        public static RegisterStorage lp;
        public static RegisterStorage l7;

        public static RegisterStorage i0;   // incoming parameters / return value to caller
        public static RegisterStorage i1;
        public static RegisterStorage i2;
        public static RegisterStorage i3;
        public static RegisterStorage i4;
        public static RegisterStorage i5;
        public static RegisterStorage i6;   // frame pointer
        public static RegisterStorage i7;   // return address - 8

        public static RegisterStorage f0; 
        public static RegisterStorage f1;
        public static RegisterStorage f2;
        public static RegisterStorage f3;
        public static RegisterStorage f4;
        public static RegisterStorage f5;
        public static RegisterStorage f6; 
        public static RegisterStorage f7;

        public static RegisterStorage f8;
        public static RegisterStorage f9;
        public static RegisterStorage f10;
        public static RegisterStorage f11;
        public static RegisterStorage f12;
        public static RegisterStorage f13;
        public static RegisterStorage f14;
        public static RegisterStorage f15;

        public static RegisterStorage f16;
        public static RegisterStorage f17;
        public static RegisterStorage f18;
        public static RegisterStorage f19;
        public static RegisterStorage f20;
        public static RegisterStorage f21;
        public static RegisterStorage f22;
        public static RegisterStorage f23;

        public static RegisterStorage f24;
        public static RegisterStorage f25;
        public static RegisterStorage f26;
        public static RegisterStorage f27;
        public static RegisterStorage f28;
        public static RegisterStorage f29;
        public static RegisterStorage f30;
        public static RegisterStorage f31;


        private static RegisterStorage[] iRegs;
        private static RegisterStorage[] fRegs;

        static Registers()
        {
            g0 = new RegisterStorage("g0", 0, PrimitiveType.Word32);
            g1 = new RegisterStorage("g1", 0, PrimitiveType.Word32);
            g2 = new RegisterStorage("g2", 0, PrimitiveType.Word32);
            g3 = new RegisterStorage("g3", 0, PrimitiveType.Word32);
            g4 = new RegisterStorage("g4", 0, PrimitiveType.Word32);
            g5 = new RegisterStorage("g5", 0, PrimitiveType.Word32);
            g6 = new RegisterStorage("g6", 0, PrimitiveType.Word32);
            g7 = new RegisterStorage("g7", 0, PrimitiveType.Word32);

            o0 = new RegisterStorage("o0", 0, PrimitiveType.Word32);   // outgoing paramter 0 / return valie from callee
            o1 = new RegisterStorage("o1", 0, PrimitiveType.Word32);
            o2 = new RegisterStorage("o2", 0, PrimitiveType.Word32);
            o3 = new RegisterStorage("o3", 0, PrimitiveType.Word32);
            o4 = new RegisterStorage("o4", 0, PrimitiveType.Word32);
            o5 = new RegisterStorage("o5", 0, PrimitiveType.Word32);
            sp = new RegisterStorage("sp", 0, PrimitiveType.Word32);   // stack pointer
            o7 = new RegisterStorage("o7", 0, PrimitiveType.Word32);

            l0 = new RegisterStorage("l0", 0, PrimitiveType.Word32);
            l1 = new RegisterStorage("l1", 0, PrimitiveType.Word32);
            l2 = new RegisterStorage("l2", 0, PrimitiveType.Word32);
            l3 = new RegisterStorage("l3", 0, PrimitiveType.Word32);
            l4 = new RegisterStorage("l4", 0, PrimitiveType.Word32);
            l5 = new RegisterStorage("l5", 0, PrimitiveType.Word32);
            lp = new RegisterStorage("lp", 0, PrimitiveType.Word32);
            l7 = new RegisterStorage("l7", 0, PrimitiveType.Word32);

            i0 = new RegisterStorage("i0", 0, PrimitiveType.Word32);   // incoming parameters / return value to caller
            i1 = new RegisterStorage("i1", 0, PrimitiveType.Word32);
            i2 = new RegisterStorage("i2", 0, PrimitiveType.Word32);
            i3 = new RegisterStorage("i3", 0, PrimitiveType.Word32);
            i4 = new RegisterStorage("i4", 0, PrimitiveType.Word32);
            i5 = new RegisterStorage("i5", 0, PrimitiveType.Word32);
            i6 = new RegisterStorage("i6", 0, PrimitiveType.Word32);   // frame pointer
            i7 = new RegisterStorage("i7", 0, PrimitiveType.Word32);   // return address - 8

            f0 = new RegisterStorage("f0", 0,  PrimitiveType.Real32);
            f1 = new RegisterStorage("f1", 1,  PrimitiveType.Real32);
            f2 = new RegisterStorage("f2", 2,  PrimitiveType.Real32);
            f3 = new RegisterStorage("f3", 3,  PrimitiveType.Real32);
            f4 = new RegisterStorage("f4", 4,  PrimitiveType.Real32);
            f5 = new RegisterStorage("f5", 5,  PrimitiveType.Real32);
            f6 = new RegisterStorage("f6", 6,  PrimitiveType.Real32);
            f7 = new RegisterStorage("f7", 7,  PrimitiveType.Real32);
                
            f8 = new RegisterStorage("f8", 8,  PrimitiveType.Real32);
            f9 = new RegisterStorage("f9", 9,  PrimitiveType.Real32);
            f10= new RegisterStorage("f10", 10, PrimitiveType.Real32);
            f11= new RegisterStorage("f11", 11, PrimitiveType.Real32);
            f12= new RegisterStorage("f12", 12, PrimitiveType.Real32);
            f13= new RegisterStorage("f13", 13, PrimitiveType.Real32);
            f14= new RegisterStorage("f14", 14, PrimitiveType.Real32);
            f15= new RegisterStorage("f15", 15, PrimitiveType.Real32);
                                              
            f16= new RegisterStorage("f16", 16, PrimitiveType.Real32);
            f17= new RegisterStorage("f17", 17, PrimitiveType.Real32);
            f18= new RegisterStorage("f18", 18, PrimitiveType.Real32);
            f19= new RegisterStorage("f19", 19, PrimitiveType.Real32);
            f20= new RegisterStorage("f20", 20, PrimitiveType.Real32);
            f21= new RegisterStorage("f21", 21, PrimitiveType.Real32);
            f22= new RegisterStorage("f22", 22, PrimitiveType.Real32);
            f23= new RegisterStorage("f23", 23, PrimitiveType.Real32);
                                              
            f24= new RegisterStorage("f24", 24, PrimitiveType.Real32);
            f25= new RegisterStorage("f25", 25, PrimitiveType.Real32);
            f26= new RegisterStorage("f26", 26, PrimitiveType.Real32);
            f27= new RegisterStorage("f27", 27, PrimitiveType.Real32);
            f28= new RegisterStorage("f28", 28, PrimitiveType.Real32);
            f29= new RegisterStorage("f29", 29, PrimitiveType.Real32);
            f30= new RegisterStorage("f30", 30, PrimitiveType.Real32);
            f31= new RegisterStorage("f31", 31, PrimitiveType.Real32);

            iRegs = new RegisterStorage[]
            {
                g0, 
                g1, 
                g2, 
                g3, 
                g4, 
                g5, 
                g6, 
                g7, 

                o0,  
                o1, 
                o2, 
                o3, 
                o4, 
                o5, 
                sp, 
                o7, 

                l0, 
                l1, 
                l2, 
                l3, 
                l4, 
                l5, 
                lp, 
                l7, 

                i0,  
                i1, 
                i2, 
                i3, 
                i4, 
                i5, 
                i6, 
                i7, 
            };

            fRegs = new RegisterStorage[] {
                f0 ,
                f1 ,
                f2 ,
                f3 ,
                f4 ,
                f5 ,
                f6 ,
                f7 ,
   
                f8 ,
                f9 ,
                f10,
                f11,
                f12,
                f13,
                f14,
                f15,
   
                f16,
                f17,
                f18,
                f19,
                f20,
                f21,
                f22,
                f23,
   
                f24,
                f25,
                f26,
                f27,
                f28,
                f29,
                f30,
                f31,
            };
        }

        public static RegisterStorage GetRegister(uint r)
        {
            return iRegs[r & 0x1F];
        }

        public static RegisterStorage GetFpuRegister(uint f)
        {
            return fRegs[f];
        }
    }
}
