#include "gdexample.h"
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/engine.hpp>

using namespace godot;

void GDExample::_bind_methods() {
    ClassDB::bind_method(D_METHOD("set_sample_val", "val"), &GDExample::set_sample_val);
    ClassDB::bind_method(D_METHOD("get_sample_val"), &GDExample::get_sample_val);
    ClassDB::add_property("GDExample", PropertyInfo(Variant::INT, "sample_value"), "set_sample_val", "get_sample_val");
}

GDExample::GDExample() {
    // Initialize any variables here.
    time_passed = 0.0;
    sample_value = 0;
}

GDExample::~GDExample() {
    // Add your cleanup here.
}

void GDExample::_process(double delta) {
    // Check to see if the rendition is happening in the editor / IDE. To do this we invoke: Engine::get_singleton()->is_editor_hint()
    // This normally returns true if it is in the editor
    if (!Engine::get_singleton()->is_editor_hint()) {
        // This script will only be executed when the project is being run and not when in edit mode
        time_passed += delta;
        Vector2 new_position = Vector2(10.0 + (10.0 * sin(time_passed * 2.0)), 10.0 + (10.0 * cos(time_passed * 1.5)));
        set_position(new_position);
    }
}

void GDExample::_ready() {
    // Override of _ready()
    sample_value = 15;
}

void GDExample::set_sample_val(int val) {
    sample_value = val;
}

int GDExample::get_sample_val() {
    return sample_value;
}