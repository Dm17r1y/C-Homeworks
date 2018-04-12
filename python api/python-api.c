#include <Python.h>

static PyObject *counter_countLinks(PyObject *self, PyObject *args) {
	
	PyObject *object;
	
	if (!PyArg_ParseTuple(args, "O", &object)) {
        return NULL;
	}
	return Py_BuildValue("i", object->ob_refcnt);
}

static PyMethodDef counter_methods[] = {
    {"count_links", (PyCFunction)counter_countLinks, METH_VARARGS, "Count links of python object"},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef counter_def = {
	PyModuleDef_HEAD_INIT,
	"counter",
	NULL,
	-1,
	counter_methods,
};

PyMODINIT_FUNC PyInit_counter(void) {
    return PyModule_Create(&counter_def);
}
