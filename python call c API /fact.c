#include <Python.h>

int fact( int n ){
	return fact_tail( n, 1 );
}

int fact_tail( int n, int result ){
	if( 0  > n ){
		return 0;
	} else if( 0 == n ){
		return 1;
	} else if( 1 == n ){
		return result;
	} else {
		return fact_tail( n - 1, n * result );
	}
}

PyObject* wrap_fact( PyObject* self, PyObject* args ){
	int n, result;

	if( !PyArg_ParseTuple( args, "i:fact", &n ))
		return NULL;
	result = fact( n );
	return Py_BuildValue( "i", result );
}

static PyMethodDef exampleMethods[] = {
	{ "fact", wrap_fact, METH_VARARGS, "Calculte N!"},
	{ NULL, NULL }
};

void initexample(){
	PyObject* m;
	m = Py_InitModule( "example", exampleMethods );
}