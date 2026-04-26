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

    bool use_first_derived = true;

    while(true) {
        cin >> s_head >> s_sub;

        if(s_head == s_sub)
            break;

        cl_base* p_found_head = nullptr;
        vector<cl_base*> bfs_queue;
        bfs_queue.push_back(this);
        int bfs_idx = 0;

        while(bfs_idx < (int)bfs_queue.size()) {
            cl_base* current = bfs_queue[bfs_idx++];
            if(current->get_object_name() == s_head) {
                p_found_head = current;
                break;
            }
            for(int i = 0; i < current->get_count_subordinate_objects(); ++i) {
                bfs_queue.push_back(current->find_subordinate_by_index(i + 1));
            }
        }

        if(p_found_head == nullptr) {
            continue;
        }

        if(p_found_head->find_subordinate_by_name(s_sub) != nullptr) {
            continue;
        }

        if(use_first_derived) {
            p_sub = new cl_derived(p_found_head, s_sub);
        } else {
            p_sub = new cl_derived(p_found_head, s_sub);
        }
        use_first_derived = !use_first_derived;

    }
}

int cl_application::exec_app() {
    cout << this->get_object_name() << endl;

    vector<cl_base*> queue;
    queue.push_back(this);
    int idx = 0;
    while (idx < (int)queue.size()) {
        cl_base* current = queue[idx++];
        if (current->get_count_subordinate_objects() > 0) {
            cout << current->get_object_name();
            for (int i = 0; i < current->get_count_subordinate_objects(); ++i) {
                cl_base* child = current->find_subordinate_by_index(i + 1);
                cout << "  " << child->get_object_name();
            }
            cout << endl;
        }
        for (int i = 0; i < current->get_count_subordinate_objects(); ++i) {
            queue.push_back(current->find_subordinate_by_index(i + 1));
        }
    }

    int level, index;
    string new_name;
    while (cin >> level) {
        if (level == 0) break;
        cin >> index >> new_name;

        vector<cl_base*> nodes_at_level;
        vector<cl_base*> bfs_queue;
        vector<int> levels;
        bfs_queue.push_back(this);
        levels.push_back(1);
        int bfs_idx = 0;

        while (bfs_idx < (int)bfs_queue.size()) {
            cl_base* current = bfs_queue[bfs_idx];
            int current_level = levels[bfs_idx++];

            if (current_level == level) {
                nodes_at_level.push_back(current);
            } else if (current_level < level) {
                for (int i = 0; i < current->get_count_subordinate_objects(); ++i) {
                    bfs_queue.push_back(current->find_subordinate_by_index(i + 1));
                    levels.push_back(current_level + 1);
                }
            }
        }

        if (index >= 1 && index <= (int)nodes_at_level.size()) {
            nodes_at_level[index - 1]->set_object_name(new_name);
        }
    }

    cout << this->get_object_name() << endl;

    queue.clear();
    queue.push_back(this);
    idx = 0;
    while (idx < (int)queue.size()) {
        cl_base* current = queue[idx++];
        if (current->get_count_subordinate_objects() > 0) {
            cout << current->get_object_name();
            for (int i = 0; i < current->get_count_subordinate_objects(); ++i) {
                cl_base* child = current->find_subordinate_by_index(i + 1);
                cout << "  " << child->get_object_name();
            }
            cout << endl;
        }
        for (int i = 0; i < current->get_count_subordinate_objects(); ++i) {
            queue.push_back(current->find_subordinate_by_index(i + 1));
        }
    }

    return 0;
}
