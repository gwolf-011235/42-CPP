/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawTriangle.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 10:04:56 by gwolf             #+#    #+#             */
/*   Updated: 2023/10/02 11:31:23 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GL/glut.h"
#include "Point.hpp"

extern Point* a;
extern Point* b;
extern Point* c;
extern Point* p;
extern bool inside;

void	display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_TRIANGLES);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2f((*a).get_xf(), (*a).get_yf());
	glVertex2f((*b).get_xf(), (*b).get_yf());
	glVertex2f((*c).get_xf(), (*c).get_yf());
	glEnd();

	glBegin(GL_POINTS);
	if (inside)
		glColor3f(0.0, 1.0, 0.0);
	else
		glColor3f(1.0, 0.0, 0.0);
	glVertex2f((*p).get_xf(), (*p).get_yf());
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