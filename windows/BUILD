# Copyright 2020 Google LLC
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     https://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
load("//third_party/msvc:build_windows.bzl", "cc_windows_dll")

licenses(["notice"])

# Build with --config=lexan
cc_windows_dll(
    name = "core_adapter",
    srcs = [
        "advertising_options.cc",
        "connection_options.cc",
        "core_adapter.cc",
        "discovery_options.cc",
    ],
    hdrs = [
        "advertising_options.h",
        "connection_options.h",
        "core_adapter.h",
        "discovery_options.h",
    ],
    copts = ["-DCORE_ADAPTER_BUILD_DLL -DCOMPILING_CORE"],
    defines = ["CORE_ADAPTER_DLL"],
    tags = ["windows-dll"],
    deps = [
        "//absl/strings",
        "//third_party/dart_lang/v2:dart_api_dl",
        "//core",
        "//platform/impl/windows",
        "//webrtc/api:create_peerconnection_factory",
    ],
)

# Build with --config=lexan
# TODO(b/203019344) Move this configuration under dart folder and create a BUILD there.
cc_windows_dll(
    name = "core_adapter_dart",
    srcs = [
        "advertising_options.cc",
        "connection_options.cc",
        "core_adapter.cc",
        "dart/core_adapter_dart.cc",
        "discovery_options.cc",
    ],
    hdrs = [
        "advertising_options.h",
        "connection_options.h",
        "core_adapter.h",
        "dart/core_adapter_dart.h",
        "discovery_options.h",
    ],
    copts = ["-DCORE_ADAPTER_DART_BUILD_DLL -DCORE_ADAPTER_DLL -DCOMPILING_CORE"],
    defines = ["CORE_ADAPTER_DART_DLL"],
    tags = ["windows-dll"],
    deps = [
        "//absl/strings",
        "//third_party/dart_lang/v2:dart_api_dl",
        "//core",
        "//platform/impl/windows",
        "//webrtc/api:create_peerconnection_factory",
    ],
)
