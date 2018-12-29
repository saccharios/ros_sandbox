#include <beginner_tutorials/AddTwoInts.h>
#include <gtest/gtest.h>
#include "ros/ros.h"

TEST(AddTwoIntsTest, AddTwoIntsTest)
{
    ros::NodeHandle n;
    ros::ServiceClient client = n.serviceClient<beginner_tutorials::AddTwoInts>("add_two_ints");

    ros::service::waitForService("/add_two_ints", -1);

    beginner_tutorials::AddTwoInts srv;
    srv.request.a = 3;
    srv.request.b = 4;
    bool success = client.call(srv);
    EXPECT_TRUE(success);
    EXPECT_EQ(srv.response.sum, 3+4);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    ros::init(argc, argv, "add_two_ints_service_test_node");
    return RUN_ALL_TESTS();
}
