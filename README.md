## GDExtension Trial Project

Reference: [GDExtension C++ example](https://docs.godotengine.org/en/stable/tutorials/scripting/gdextension/gdextension_cpp_example.html)

## Notes

Checking to see if the node is running in the editor:

```gdscript
// Include this file:
#include <godot_cpp/classes/engine.hpp>

void GDExample::_process(double delta) {
    if (Engine::get_singleton()->is_editor_hint()) {
        // This will run if the project is being edited in the editor
    else {
        // This will be executed only when the project is in run mode
    }
}
```