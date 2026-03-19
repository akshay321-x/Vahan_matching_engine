#include<bits/stdc++.h>
#include "rider.pb.h"
using namespace std;
using namespace vahan_mesh;
 double min_distance=1e9;
   vahan_mesh::RideRequest request;
      //vector to store cab info
  vector<Cab>cab_pool;
 Cab*nearest_cab=nullptr;
 void find(vector<Cab>arr){
   for(auto &cab:arr){
    double lat1=request.pickup_lat();
    double long1=request.pickup_long();
    double lat2=cab.lat();
    double long2=cab.lon();
    //calculate euclidean distance
    double distance=sqrt(pow(lat2-lat1,2))+pow(long2-long1,2);
    cout<<"Distance to"<<cab.cab_id()<<":"<<distance<<endl;
    if(distance<min_distance){
        min_distance=distance;
        nearest_cab=&cab;
    }
   }
   if(nearest_cab!=NULL){
    cout<<"Match Found! Nearest cab"<<nearest_cab->cab_id()<<endl;
 }
}
int main(){
    //vector to store cab info
    //Function to add cab easily
    auto add_cab=[&](string id,double lat,double lon){
         vahan_mesh::Cab c;
         c.set_cab_id(id);
         c.set_lat(lat);
         c.set_lon(lon);
         c.set_is_available(true);
         cab_pool.push_back(c);
    };

    // Add 5 Members with different locations
    add_cab("CAB_01",18.5204,73.85);
    add_cab("CAB_02",18.5300,73.8600);
    add_cab("CAB_03",18.6000,73.9000);
    add_cab("CAB_04",18.7000,73.8400);
    add_cab("CAB_05",18.5250,73.8500);
    request.set_rider_id("RIDER_45");
    request.set_pickup_lat(18.5204);
    request.set_pickup_long(73.587);
    // serialization
    string output;
    request.SerializeToString(&output);
    cout<<"Rider id:" <<request.rider_id()<<"is Ready!"<<endl;
    cout<<"Data size in binary:"<<output.size()<<"bytes"<<endl;
    find(cab_pool);
    return 0;
}
