/*
 * Picviz - Parallel coordinates ploter
 * Copyright (C) 2008-2009 Sebastien Tricaud <sebastien@honeynet.org>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation version 3.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * $Id$
 */

#include <Python.h>

#include <stdio.h>
#include <picviz.h>

#include "py-picviz.h"
#include "py-picviz_pgdl.h"

PyObject *pypicviz_pgdl_save(PyObject *self, PyObject *args)
{
#if 0
	PyObject *image_o;
	/* Axes */
	PyObject *axes_o;
	PyObject *axeslist;
	Py_ssize_t axeslist_size;
	PyObject *axisitem;
	PyObject *axesorder;
	Py_ssize_t axesorder_size;
	PyObject *axisorderitem;
	char *axis_name;
	char *axis_type;
	/* Various */
	FILE     *pgdl_fd;
	char     *pgdl_file;
	unsigned int counter = 0;

	if ( ! PyArg_ParseTuple(args, "Os", &image_o, &pgdl_file)) {
		Py_RETURN_FALSE;
	}

	pgdl_fd = fopen(pgdl_file, "w");
	if (!pgdl_fd) {
		fprintf(stderr,"[pypicviz:%s]: Cannot open '%s' for writing. Check permissions.\n", __FUNCTION__, pgdl_file);
		Py_RETURN_FALSE;
	}

	fprintf(pgdl_fd, "# Autogenerated by Picviz Python v.%s\n", PICVIZ_PYTHON_VERSION);
	fprintf(pgdl_fd, "header {\n");
	fprintf(pgdl_fd, "    title = \"%s\";\n", PyString_AS_STRING(PyDict_GetItemString(image_o, "title")));
	fprintf(pgdl_fd, "}\n");

	axes_o = PyDict_GetItemString(image_o, "axes");
	axeslist = PyDict_Items(axes_o);
	axeslist_size = PyList_Size(axeslist);
	axesorder = PyDict_GetItemString(image_o, "axeslist");
	axesorder_size = PyList_Size(axesorder);
	fprintf(pgdl_fd, "axes {\n");
	counter = 0;
        while (counter < axesorder_size) {
       		axisorderitem = PyList_GetItem(axesorder, counter);
		axis_name = PyString_AS_STRING(axisorderitem);
		/* printf("name='%s'\n",axis_name); */
		/* PyObject_Print(axeslist, pgdl_fd, 0); */
		axisitem = PyList_GetItem(axeslist, axis_name);
		PyObject_Print(axisitem, pgdl_fd, 0);
		/* axis_type = PyString_AS_STRING(PyDict_GetItemString(axeslist, "type")); */
		/* fprintf(pgdl_fd, "    %s %s;\n", axis_type, axis_name); */
		/* fprintf(pgdl_fd, "\n"); */
		counter++;
	}
	fprintf(pgdl_fd, "}\n");
	fprintf(pgdl_fd, "data {\n");
	fprintf(pgdl_fd, "}\n");

	fclose(pgdl_fd);

	Py_RETURN_TRUE;
#endif

	Py_RETURN_NONE;

}
