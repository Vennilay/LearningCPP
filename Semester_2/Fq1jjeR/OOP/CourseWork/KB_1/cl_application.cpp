#include "cl_application.h"
#include <iostream>
#include <vector>

using namespace std;

cl_application::cl_application(cl_base* p_head_obj) : cl_base(p_head_obj) {}

void cl_application::build_tree_objects() {
    string s_head, s_sub;
    cl_base* p_head;
    cl_base* p_sub;

    cin >> s_head;
    this->set_object_name(s_head);

    p_head = this;
    bool use_first_derived = true;

    while(true) {
        cin >> s_head >> s_sub;
        if(s_head == s_sub) break;

        cl_base* p_found_head = p_head->find_subordinate_by_name(s_head);
        if(p_found_head != nullptr && p_head->get_count_subordinate_objects() > 0 &&
           p_found_head == p_head->find_subordinate_by_index(p_head->get_count_subordinate_objects())) {
            p_head = p_found_head;
        }

        if((p_head != this && p_head->get_object_name() != s_head) ||
           p_head->find_subordinate_by_name(s_head) != nullptr ||
           p_head->find_subordinate_by_name(s_sub) != nullptr) {
            continue;
        }

        if(use_first_derived) {
            p_sub = new cl_derived(p_head, s_sub);
        } else {
            p_sub = new cl_derived(p_head, s_sub);
        }
        use_first_derived = !use_first_derived;
    }
}

int cl_application::exec_app() {
    cout << this->get_object_name() << endl;

    vector<cl_base*> queue;
    queue.push_back(this);
    int idx = 0;
    while(idx < (int)queue.size()) {
        cl_base* current = queue[idx++];
        if(current->get_count_subordinate_objects() > 0) {
            cout << current->get_object_name();
            for(int i = 0; i < current->get_count_subordinate_objects(); ++i) {
                cl_base* child = current->find_subordinate_by_index(i + 1);
                cout << "  " << child->get_object_name();
            }
            cout << endl;
        }
        for(int i = 0; i < current->get_count_subordinate_objects(); ++i) {
            queue.push_back(current->find_subordinate_by_index(i + 1));
        }
    }
    cout << endl;

    int level, index;
    string new_name;
    while(cin >> level) {
        if(level == 0) break;
        cin >> index >> new_name;

        int depth = 1;
        cl_base* p_head = this;
        if(level == 1 && index == 1) {
            this->set_object_name(new_name);
            continue;
        }
        while(true) {
            if(depth < level - 1) {
                if(p_head->get_count_subordinate_objects() > 0)
                    p_head = p_head->find_subordinate_by_index(p_head->get_count_subordinate_objects());
                depth++;
                continue;
            }
            if(p_head != nullptr && p_head->find_subordinate_by_index(index) != nullptr) {
                p_head->find_subordinate_by_index(index)->set_object_name(new_name);
            }
            break;
        }
    }

    cout << this->get_object_name() << endl;
    queue.clear();
    queue.push_back(this);
    idx = 0;
    while(idx < (int)queue.size()) {
        cl_base* current = queue[idx++];
        if(current->get_count_subordinate_objects() > 0) {
            cout << current->get_object_name();
            for(int i = 0; i < current->get_count_subordinate_objects(); ++i) {
                cl_base* child = current->find_subordinate_by_index(i + 1);
                cout << "  " << child->get_object_name();
            }
            cout << endl;
        }
        for(int i = 0; i < current->get_count_subordinate_objects(); ++i) {
            queue.push_back(current->find_subordinate_by_index(i + 1));
        }
    }

    return 0;
}