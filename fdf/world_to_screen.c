/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_to_screen.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooz <ozomerfaruk009@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 02:25:06 by ooz               #+#    #+#             */
/*   Updated: 2022/03/01 22:11:29 by ooz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_Quaternion	quaternion_conjugate(t_Quaternion q)
{
	t_Quaternion	r;

	r.w = q.w;
	r.x = -q.x;
	r.y = -q.y;
	r.z = -q.z;
	return (r);
}

t_Quaternion	quaternion_multiplay(t_Quaternion q1, t_Quaternion q2)
{
	t_Quaternion	qr;

	qr.x = (q1.w * q2.x) + (q1.x * q2.w) + (q1.y * q2.z) - (q1.z * q2.y);
	qr.y = (q1.w * q2.y) - (q1.x * q2.z) + (q1.y * q2.w) + (q1.z * q2.x);
	qr.z = (q1.w * q2.z) + (q1.x * q2.y) - (q1.y * q2.x) + (q1.z * q2.w);
	qr.w = (q1.w * q2.w) - (q1.x * q2.x) - (q1.y * q2.y) - (q1.z * q2.z);
	return (qr);
}

t_Quaternion	to_quaternion(t_vector3 angle)
{
	t_vector3		c;
	t_vector3		s;
	t_Quaternion	q;

	c.x = cos(angle.z * 0.5);
	s.x = sin(angle.z * 0.5);
	c.y = cos(angle.y * 0.5);
	s.y = sin(angle.y * 0.5);
	c.z = cos(angle.x * 0.5);
	s.z = sin(angle.x * 0.5);
	q.w = c.x * c.y * c.z + s.x * s.y * s.z;
	q.x = s.x * c.y * c.z - c.x * s.y * s.z;
	q.y = c.x * s.y * c.z + s.x * c.y * s.z;
	q.z = c.x * c.y * s.z - s.x * s.y * c.z;
	return (q);
}

t_vector3	rotate(t_vector3 pos, t_vector3 angle)
{
	t_Quaternion	q;
	t_Quaternion	v;
	t_vector3		radian;
	t_vector3		r;

	radian.x = angle.x * ANGLE_TO_RADIAN;
	radian.y = angle.y * ANGLE_TO_RADIAN;
	radian.z = angle.z * ANGLE_TO_RADIAN;
	v.w = 0;
	v.x = pos.x;
	v.y = pos.y;
	v.z = pos.z;
	q = to_quaternion(radian);
	v = quaternion_multiplay(quaternion_multiplay(q, v) \
	, quaternion_conjugate(q));
	r.x = v.x;
	r.y = v.y;
	r.z = v.z;
	return (r);
}

unsigned int	col_lerp(unsigned int a, unsigned int b, float i)
{
	unsigned int	rc;
	unsigned int	gc;
	unsigned int	bc;

	rc = (a & 0X00FF0000) * (1 - i) + (b & 0X00FF0000) * i;
	gc = (a & 0X0000FF00) * (1 - i) + (b & 0X0000FF00) * i;
	bc = (a & 0X000000FF) * (1 - i) + (b & 0X000000FF) * i;
	rc = rc & 0X00FF0000;
	gc = gc & 0X0000FF00;
	return (rc | gc | bc);
}
