#include "rclcpp/rclcpp.hpp"
#include <chrono>

using namespace std::chrono_literals;

class HelloNode : public rclcpp::Node
{
public:
  HelloNode()
  : Node("hello_world_node") // 1. Initialize Node with name
  {
    // 2. Create a timer that fires every 1000ms
    timer_ = this->create_wall_timer(
      1000ms, std::bind(&HelloNode::timer_callback, this));
  }

private:
  void timer_callback()
  {
    // 3. Print "Hello, World!" to the logger
    RCLCPP_INFO(this->get_logger(), "Hello, World!");
  }

  rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<HelloNode>());
  rclcpp::shutdown();
  return 0;
}