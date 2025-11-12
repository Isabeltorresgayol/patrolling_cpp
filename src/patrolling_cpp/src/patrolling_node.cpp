#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = rclcpp::Node::make_shared("publisher_node");
    auto publisher = node->create_publisher<geometry_msgs::msg::PoseStamped>("/goal_pose", 10);

    geometry_msgs::msg::PoseStamped msg;
    msg.header.frame_id = "map";
    msg.pose.position.x = 2.0;
    msg.pose.position.y = 3.0;
    msg.pose.position.z = 0.0;
    msg.pose.orientation.w = 1.0;

    publisher->publish(msg);
    RCLCPP_INFO(node->get_logger(), "Meta publicada en /goal_pose");

    rclcpp::shutdown();
    return 0;
}
