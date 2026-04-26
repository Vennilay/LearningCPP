#include "cl_base.h"
#include <iostream>

using namespace std;

cl_base::cl_base(cl_base* p_head_object, string s_object_name) {
    this->p_head_object = p_head_object;
    this->s_object_name = s_object_name;
    if (p_head_object != nullptr) {
        p_head_object->subordinate_objects.push_back(this);
    }
}

bool cl_base::set_object_name(string new_name) {
    if (p_head_object != nullptr) {
        for (int i = 0; i < p_head_object->subordinate_objects.size(); ++i) {
            if (p_head_object->subordinate_objects[i]->get_object_name() == new_name) {
                return false;
                }
        }
    }
    s_object_name = new_name;
    return true;
}

string cl_base::get_object_name() {
    return s_object_name;
}

cl_base* cl_base::get_head_object() {
    return p_head_object;
}

int cl_base::get_count_subordinate_objects() {
    return (int)subordinate_objects.size();
}

void cl_base::print_tree_structure() {
    if (subordinate_objects.size() != 0) {
        cout << endl << this->get_object_name();
        for (int i = 0; i < subordinate_objects.size(); ++i)
        {
            cout << "  " << subordinate_objects[i]->get_object_name();
            subordinate_objects[i]->print_tree_structure();
        }
    }
}

cl_base* cl_base::find_subordinate_by_name(string name) {
    for (int i = 0; i < subordinate_objects.size(); ++i) {
        if (subordinate_objects[i]->get_object_name() == name) {
            return subordinate_objects[i];
        }
    }
    return nullptr;
}

cl_base* cl_base::find_subordinate_by_index(int index) {
    if (index >= 1 && index <= (int)subordinate_objects.size()) {
        return subordinate_objects[index - 1];
    }
    return nullptr;
}

cl_base::~cl_base() {
    for (int i = 0; i < subordinate_objects.size(); ++i) {
        delete subordinate_objects[i];
    }
    subordinate_objects.clear();
}
