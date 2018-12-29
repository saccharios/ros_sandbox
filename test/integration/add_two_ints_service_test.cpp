#include <beginner_tutorials/AddTwoInts.h>
#include <gtest/gtest.h>
#include "ros/ros.h"

class AddTwoIntsTest : public testing::Test
{
public:
    void run_test(int x, int y)
    {
        ros::NodeHandle n;
        ros::ServiceClient client = n.serviceClient<beginner_tutorials::AddTwoInts>("add_two_ints");
        ros::service::waitForService("/add_two_ints", -1);
        beginner_tutorials::AddTwoInts srv;
        srv.request.a = x;
        srv.request.b = y;
        bool success = client.call(srv);
        EXPECT_TRUE(success);
        EXPECT_EQ(srv.response.sum, x+y);
    }
};


TEST_F(AddTwoIntsTest, Add_1_0)
{
    run_test(1,0);
}
TEST_F(AddTwoIntsTest, Add_2_m3)
{
    run_test(2,-3);
}
TEST_F(AddTwoIntsTest, Add_0_0)
{
    run_test(0,0);
}
TEST_F(AddTwoIntsTest, Add_9871_197)
{
    run_test(9871,197);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    ros::init(argc, argv, "add_two_ints_service_test_node");
    return RUN_ALL_TESTS();
}
