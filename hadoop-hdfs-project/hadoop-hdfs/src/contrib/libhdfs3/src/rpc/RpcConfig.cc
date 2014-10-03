/**
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "RpcConfig.h"

#include <vector>

namespace hdfs {
namespace internal {

size_t RpcConfig::hash_value() const {
    size_t values[] = { Int32Hasher(maxIdleTime), Int32Hasher(pingTimeout),
                        Int32Hasher(connectTimeout), Int32Hasher(readTimeout), Int32Hasher(
                            writeTimeout), Int32Hasher(maxRetryOnConnect), Int32Hasher(
                            lingerTimeout), Int32Hasher(rpcTimeout), BoolHasher(tcpNoDelay)
                      };
    return CombineHasher(values, sizeof(values) / sizeof(values[0]));
}

}
}
