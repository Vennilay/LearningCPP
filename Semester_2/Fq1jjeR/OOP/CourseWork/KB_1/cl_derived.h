#ifndef CL_DERIVED_H
#define CL_DERIVED_H

#include "cl_base.h"

class cl_derived : public cl_base {
public:
    cl_derived(cl_base* p_head_object, string s_object_name = "Derived object");
};

#endif // CL_DERIVED_H