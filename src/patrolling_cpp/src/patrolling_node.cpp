#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/pose_with_covariance_stamped.hpp"

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = rclcpp::Node::make_shared("publisher_node");

    // Cambiamos el tipo de mensaje
    auto publisher = node->create_publisher<geometry_msgs::msg::PoseWithCovarianceStamped>("/goal_pose", 10);

    geometry_msgs::msg::PoseWithCovarianceStamped msg;
    msg.header.frame_id = "map";
    msg.pose.pose.position.x = 2.0;
    msg.pose.pose.position.y = 3.0;
    msg.pose.pose.position.z = 0.0;
    msg.pose.pose.orientation.w = 1.0;

    publisher->publish(msg);
    RCLCPP_INFO(node->get_logger(), "Meta publicada en /goal_pose con PoseWithCovarianceStamped");

    rclcpp::shutdown();
    return 0;
}

