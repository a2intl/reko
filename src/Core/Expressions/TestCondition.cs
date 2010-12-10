#region License
/* 
 * Copyright (C) 1999-2010 John K�ll�n.
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

using Decompiler.Core.Types;
using System;
using System.Collections.Generic;
using System.Text;

namespace Decompiler.Core.Expressions
{
    /// <summary>
    /// Represents testing the expression to see if the condition code is true, and generating a
    /// boolean value.
    /// </summary>
    /// <remarks>
    /// This is a very low-level expression modelling the condition codes of certain processor
    /// architectures, and should be rewritten by the later decompiler stages to a boolean expression.
    /// </remarks>
    public class TestCondition : Expression
    {
        public TestCondition(ConditionCode cc, Expression expr)
            : base(PrimitiveType.Bool)
        {
            this.ConditionCode = cc;
            this.Expression = expr;
        }

        public ConditionCode ConditionCode { get; set; }
        public Expression Expression { get; set; }

        public override Expression Accept(IExpressionTransformer xform)
        {
            return xform.TransformTestCondition(this);
        }

        public override T Accept<T>(ExpressionVisitor<T> visitor)
        {
            return visitor.VisitTestCondition(this);
        }

        public override void Accept(IExpressionVisitor visitor)
        {
            visitor.VisitTestCondition(this);
        }

        public override Expression CloneExpression()
        {
            return new TestCondition(ConditionCode, Expression);
        }

        public override Expression Invert()
        {
            ConditionCode cc;
            switch (this.ConditionCode)
            {
            case ConditionCode.EQ: cc = ConditionCode.NE; break;
            case ConditionCode.NE: cc = ConditionCode.EQ; break;
            default: throw new NotImplementedException("Invert of Test(" + ConditionCode + ") not implemented");
            }
            return new TestCondition(cc, Expression);
        }
    }
}