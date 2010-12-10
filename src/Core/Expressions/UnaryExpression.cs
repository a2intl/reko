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

using Decompiler.Core.Operators;
using Decompiler.Core.Types;
using System;
using System.IO;

namespace Decompiler.Core.Expressions
{
	public class UnaryExpression : Expression
	{
		public UnaryOperator op;
		private Expression expression;

		public UnaryExpression(UnaryOperator op, DataType type, Expression expr) : base(type)
		{
			this.op = op; this.Expression = expr;
		}

		public override Expression Accept(IExpressionTransformer xform)
		{
			return xform.TransformUnaryExpression(this);
		}

        public override T Accept<T>(ExpressionVisitor<T> v)
        {
            return v.VisitUnaryExpression(this);
        }


		public override void Accept(IExpressionVisitor v)
		{
			v.VisitUnaryExpression(this);
		}

		public override Expression CloneExpression()
		{
			throw new NotImplementedException();
		}

        public Expression Expression
        {
            get { return expression; }
            set { expression = value; }
        }

		public override Expression Invert()
		{
			if (op == Operator.Not)
				return Expression;
			else 
				return new UnaryExpression(Operator.Not, PrimitiveType.Bool, this);
		}
	}
}