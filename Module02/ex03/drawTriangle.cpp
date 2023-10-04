/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawTriangle.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 10:04:56 by gwolf             #+#    #+#             */
/*   Updated: 2023/10/04 10:14:18 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GL/glut.h"
#include "Point.hpp"

extern Point *points[4];
extern bool inside;

void	display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_TRIANGLES);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2f(points[0]->get_xf(), points[0]->get_yf());
	glVertex2f(points[1]->get_xf(), points[1]->get_yf());
	glVertex2f(points[2]->get_xf(), points[2]->get_yf());
	glEnd();

	glBegin(GL_POINTS);
	if (inside)
		glColor3f(0.0, 1.0, 0.0);
	else
		glColor3f(1.0, 0.0, 0.0);
	glVertex2f(points[3]->get_xf(), points[3]->get_yf());
	glEnd();

	glFlush();
}

void	init(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutCreateWindow("Triangle and Point");
	glutDisplayFunc(display);
	glutMainLoop();
}