// Copyright 2020 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef CORE_INTERNAL_MEDIUMS_WEBRTC_STUB_H_
#define CORE_INTERNAL_MEDIUMS_WEBRTC_STUB_H_

#include <cstddef>
#include <functional>
#include <memory>
#include <string>

#include "core/internal/mediums/webrtc_peer_id.h"
#include "core/internal/mediums/webrtc_socket_stub.h"
#include "platform/base/cancellation_flag.h"
#include "platform/base/listeners.h"
#include "proto/connections/offline_wire_formats.pb.h"

namespace location {
namespace nearby {
namespace connections {
namespace mediums {
// Callback that is invoked when a new connection is accepted.
struct AcceptedConnectionCallback {
  std::function<void(WebRtcSocketWrapper socket)> accepted_cb =
      DefaultCallback<WebRtcSocketWrapper>();
};
// Entry point for connecting a data channel between two devices via WebRtc.
class WebRtc {
 public:
  WebRtc();
  ~WebRtc();

  // Gets the default two-letter country code associated with current locale.
  // For example, en_US locale resolves to "US".
  const std::string GetDefaultCountryCode();

  // Returns if WebRtc is available as a medium for nearby to transport data.
  // Runs on @MainThread.
  bool IsAvailable();

  // Returns if the device is accepting connection with specific service id.
  // Runs on @MainThread.
  bool IsAcceptingConnections(const std::string& service_id);

  // Prepares the device to accept incoming WebRtc connections. Returns a
  // boolean value indicating if the device has started accepting connections.
  // Runs on @MainThread.
  bool StartAcceptingConnections(const std::string& service_id,
                                 const WebrtcPeerId& self_peer_id,
                                 const LocationHint& location_hint,
                                 AcceptedConnectionCallback callback);

  // Try to stop (accepting) the specific connection with provided service id.
  // Runs on @MainThread
  void StopAcceptingConnections(const std::string& service_id);

  // Initiates a WebRtc connection with peer device identified by |peer_id|
  // with internal retry for maximum attempts of kConnectAttemptsLimit.
  // Runs on @MainThread.
  WebRtcSocketWrapper Connect(const std::string& service_id,
                              const WebrtcPeerId& peer_id,
                              const LocationHint& location_hint,
                              CancellationFlag* cancellation_flag);
};

}  // namespace mediums
}  // namespace connections
}  // namespace nearby
}  // namespace location

#endif  // CORE_INTERNAL_MEDIUMS_WEBRTC_STUB_H_
