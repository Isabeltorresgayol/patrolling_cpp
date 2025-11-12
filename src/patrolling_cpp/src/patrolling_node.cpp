#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/pose_with_covariance_stamped.hpp"
#include <vector>

struct Goal { double x; double y; };

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = rclcpp::Node::make_shared("publisher_node");

    auto publisher = node->create_publisher<geometry_msgs::msg::PoseWithCovarianceStamped>("/goal_pose", 10);

    // Vector de metas
    std::vector<Goal> goals = {
	{ 8.31, -0.52 },
        { 3.15, 4.97 },
        { -4.23, 0.72 },
        { 0.12, 4.40 },
        { 0.16, -0.22 }
    };

    for (size_t i = 0; i < goals.size(); i++) {
        geometry_msgs::msg::PoseWithCovarianceStamped msg;
        msg.header.stamp = node->now();
        msg.header.frame_id = "map";
        msg.pose.pose.position.x = goals[i].x;
        msg.pose.pose.position.y = goals[i].y;
        msg.pose.pose.orientation.w = 1.0;

        publisher->publish(msg);
        RCLCPP_INFO(node->get_logger(), "Meta %zu publicada: (%.2f, %.2f)", i + 1, goals[i].x, goals[i].y);
        rclcpp::sleep_for(std::chrono::milliseconds(500)); // Pequeño delay
    }

    rclcpp::shutdown();
    return 0;
}

