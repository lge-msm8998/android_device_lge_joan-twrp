/*
   Copyright (C) 2007-2023, The Android Open Source Project
   Copyright (c) 2016, The CyanogenMod Project
   Copyright (c) 2017, The LineageOS Project

   SPDX-License-Identifier: Apache-2.0
 */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

#include <android-base/file.h>
#include <android-base/logging.h>
#include <android-base/properties.h>
#include <android-base/strings.h>

#define _REALLY_INCLUDE_SYS__SYSTEM_PROPERTIES_H_
#include <sys/_system_properties.h>

#include "property_service.h"

using android::base::Trim;
using android::base::GetProperty;

namespace android {
namespace init {

void property_override(const std::string& name, const std::string& value)
{
    size_t valuelen = value.size();

    prop_info* pi = (prop_info*) __system_property_find(name.c_str());
    if (pi != nullptr) {
        __system_property_update(pi, value.c_str(), valuelen);
    }
    else {
        int rc = __system_property_add(name.c_str(), name.size(), value.c_str(), valuelen);
        if (rc < 0) {
            LOG(ERROR) << "property_set(\"" << name << "\", \"" << value << "\") failed: "
                       << "__system_property_add failed";
        }
    }
}

void init_target_properties()
{
    std::string model;
    std::string cmdline;
    bool unknownDevice = true;
    bool dualSim = false;

    android::base::ReadFileToString("/proc/cmdline", &cmdline);

    for (const auto& entry : android::base::Split(android::base::Trim(cmdline), " ")) {
        std::vector<std::string> pieces = android::base::Split(entry, "=");
        if (pieces.size() == 2) {
            if(pieces[0].compare("androidboot.vendor.lge.model.name") == 0)
            {
                model = pieces[1];
                unknownDevice = false;
            } else if(pieces[0].compare("lge.dsds") == 0 && pieces[1].compare("dsds") == 0)
            {
                dualSim = true;
            }
        }
    }

    if(unknownDevice)
    {
        model = "UNKNOWN";
    }

    if(dualSim)
    {
        property_override("persist.radio.multisim.config", "dsds");
    }

    property_override("ro.product.model", model);
    property_override("ro.product.odm.model", model);
    property_override("ro.product.product.model", model);
    property_override("ro.product.system.model", model);
    property_override("ro.product.vendor.model", model);

    /*
        H932 is generally a different ROM, because firmware is signed with a 
        different key.
        Unified builds that work around the firmware signing also checks for 
        h932 in asserts either way, so this shouldn't break anything?
    */
    if(model.find("932") != std::string::npos)
        property_override("ro.product.device", "h932");
}

void vendor_load_properties(void) {
    LOG(INFO) << "Loading vendor specific properties";
    init_target_properties();
}

} // namespace android
} // namespace init
