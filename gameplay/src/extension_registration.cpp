//
// Copyright (c) 2023 Paper Cranes Ltd.
// All rights reserved.
//
#include <godot_cpp/godot.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <movement.h>

void register_gameplay_types(godot::ModuleInitializationLevel p_level) {
  if (p_level != godot::ModuleInitializationLevel::MODULE_INITIALIZATION_LEVEL_SCENE) {
	return;
  }

  godot::ClassDB::register_class<godot::Movement>();
}

void unregister_gameplay_types(godot::ModuleInitializationLevel p_level) {
}

extern "C" {

GDExtensionBool GDE_EXPORT gameplay_library_init(const GDExtensionInterface *p_interface, GDExtensionClassLibraryPtr p_library, GDExtensionInitialization *r_initialization) {
  godot::GDExtensionBinding::InitObject init_object(p_interface, p_library, r_initialization);

  init_object.register_initializer(register_gameplay_types);
  init_object.register_terminator(unregister_gameplay_types);
  init_object.set_minimum_library_initialization_level(godot::ModuleInitializationLevel::MODULE_INITIALIZATION_LEVEL_SCENE);

  return init_object.init();
}

}




