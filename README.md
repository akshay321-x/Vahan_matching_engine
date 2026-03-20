Vahan_matching_engine
This project is step by step implementation of a ride matching engine inspired by system like a Uber.

Current Progress 
Step-1: Basic Protobuf Setup
-Defined Ride_request and 'Cab' Messages.
-Generated pb.c and pb.h using protobuc.

----------------------------------------------------------------------------------------
Step-2: Serialization
-Converted Ride request into binary format using protobuf.
-Verified Data Size.
------------------------------------------------------------------------------------------
Step-3: Distance Calculation
-Implemented **Euclidean Distance**.
-Selected Nearest Cab.

How to run:

```bash(command to run)
protoc --cpp_out=. rider.proto
g++ main.cpp rider.pb.cc -o main $(pkg-config --cflags --libs protobuf)
./main
<img width="1407" height="611" alt="image" src="https://github.com/user-attachments/assets/ef7ababa-cb49-41cd-8364-cf37727f60fb" />




