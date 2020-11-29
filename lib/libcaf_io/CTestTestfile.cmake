# CMake generated Testfile for 
# Source directory: /home/muhamed/projects/actor-framework/libcaf_io
# Build directory: /home/muhamed/projects/actor-framework/build/libcaf_io
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(io.basp.message_queue "/home/muhamed/projects/actor-framework/build/bin/caf-io-test" "-r300" "-n" "-v5" "-s\"^io.basp.message_queue\$\"")
add_test(io.basp_broker "/home/muhamed/projects/actor-framework/build/bin/caf-io-test" "-r300" "-n" "-v5" "-s\"^io.basp_broker\$\"")
add_test(io.broker "/home/muhamed/projects/actor-framework/build/bin/caf-io-test" "-r300" "-n" "-v5" "-s\"^io.broker\$\"")
add_test(io.http_broker "/home/muhamed/projects/actor-framework/build/bin/caf-io-test" "-r300" "-n" "-v5" "-s\"^io.http_broker\$\"")
add_test(io.network.default_multiplexer "/home/muhamed/projects/actor-framework/build/bin/caf-io-test" "-r300" "-n" "-v5" "-s\"^io.network.default_multiplexer\$\"")
add_test(io.network.ip_endpoint "/home/muhamed/projects/actor-framework/build/bin/caf-io-test" "-r300" "-n" "-v5" "-s\"^io.network.ip_endpoint\$\"")
add_test(io.receive_buffer "/home/muhamed/projects/actor-framework/build/bin/caf-io-test" "-r300" "-n" "-v5" "-s\"^io.receive_buffer\$\"")
add_test(io.remote_actor "/home/muhamed/projects/actor-framework/build/bin/caf-io-test" "-r300" "-n" "-v5" "-s\"^io.remote_actor\$\"")
add_test(io.remote_group "/home/muhamed/projects/actor-framework/build/bin/caf-io-test" "-r300" "-n" "-v5" "-s\"^io.remote_group\$\"")
add_test(io.remote_spawn "/home/muhamed/projects/actor-framework/build/bin/caf-io-test" "-r300" "-n" "-v5" "-s\"^io.remote_spawn\$\"")
add_test(io.unpublish "/home/muhamed/projects/actor-framework/build/bin/caf-io-test" "-r300" "-n" "-v5" "-s\"^io.unpublish\$\"")
add_test(io.worker "/home/muhamed/projects/actor-framework/build/bin/caf-io-test" "-r300" "-n" "-v5" "-s\"^io.worker\$\"")
