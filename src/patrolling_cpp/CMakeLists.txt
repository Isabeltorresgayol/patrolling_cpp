cmake_minimum_required(VERSION 3.8)
project(patrolling_cpp)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)

add_executable(patrolling_node src/patrolling_node.cpp)
ament_target_dependencies(patrolling_node rclcpp geometry_msgs)

install(TARGETS
  patrolling_node
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()

