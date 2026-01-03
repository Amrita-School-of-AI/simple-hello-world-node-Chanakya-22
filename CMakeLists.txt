cmake_minimum_required(VERSION 3.8)
project(ros2_hello_world)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# 1. Find the ROS2 C++ library
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)

# 2. Define the executable (hello_node) and its source file
add_executable(hello_node src/hello_node.cpp)

# 3. Link the executable to rclcpp
ament_target_dependencies(hello_node rclcpp)

# 4. Install the executable to the package directory
install(TARGETS hello_node
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()