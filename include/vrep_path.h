//
// Created by kganguly on 5/15/18.
//

#pragma once

#include<string>
#include <iostream>
#include <map>

#include <vector>
#include <Eigen/Dense>

extern "C" {
#include "extApi.h"
#include "extApiPlatform.h"
}

namespace vrep_path {
    float _percent_of_path;
    std::string _path_name;
    std::string _path_function;
    int _path_handle;
    int _count_floats_from_server;
    float *_floats_from_server;
    float _path_increment;

    std::vector<float> fetch_path_data_from_relative_position(int &clientID);

    void
    move_object_on_path(int &clientID, int &object1_handle,
                        std::vector<float> &object1_pose,
                        std::map<int, bool> &isStreamingInitialized);

    Eigen::Matrix3f rotation_matrix_from_euler(Eigen::Vector3f euler);

    std::vector<float>
    fetch_object_pose_xyzeuler(int &clientID, int &object_handle, std::map<int, bool> &isStreamingInitialized);
}