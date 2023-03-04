//
// Copyright (c) 2023 ThatOneGameDev.com
// All rights reserved.
//

#ifndef GDEXTENSION_TEMPLATE_MOVEMENT_H_
#define GDEXTENSION_TEMPLATE_MOVEMENT_H_

#include <cstdint>
#include <godot_cpp/godot.hpp>
#include <godot_cpp/classes/node2d.hpp>

namespace godot {

class Movement : public Node2D {
  GDCLASS(Movement, Node2D)

 public:
  static void _bind_methods();

  void _process(double_t delta) override;

  void set_speed(float_t speed) {
	m_Speed = speed;
  }

  [[nodiscard]] float_t get_speed() const {
	return m_Speed;
  }

 private:
  Vector2 m_Velocity;
  float_t m_Speed = 500.0f;
  void process_movement(double_t delta);
};

}

#endif //GDEXTENSION_TEMPLATE_MOVEMENT_H_
