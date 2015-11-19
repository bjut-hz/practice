#include <Python.h>
#include <stdio.h>
int main(){
	Py_Initialize();
	if( !Py_IsInitialized() ){
		return -1;
	}

	PyRun_SimpleString( "import sys" );
	PyRun_SimpleString( "sys.path.append('./')");
	PyObject *p_module, *p_func, *p_para, *p_retval;

	if( !(p_module = PyImport_ImportModule( "python_test" ) ) ){
		return -1;
	}

	if( !( p_func = PyObject_GetAttrString( p_module, "add" ) ) ){
		return -2;
	}

	p_para = Py_BuildValue( "ii", 45, 55 );
	p_retval = PyEval_CallObject( p_func, p_para );

	int result = 0;
	PyArg_Parse( p_retval, "i", &result );

	printf("%s\n", "test");
	printf("%d\n", result );
 
    	Py_DECREF( p_module );   
    	Py_DECREF( p_func );
    	Py_DECREF( p_retval ); 

	Py_Finalize();
	return 0;
}