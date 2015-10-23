// Copyright 2015 Google Inc. All rights reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef BREADBOARD_EVENT_SYSTEM_H_
#define BREADBOARD_EVENT_SYSTEM_H_

#include <string>
#include <unordered_map>

#include "breadboard/module.h"

namespace breadboard {

// The event system keeps track of all registered types, modules and nodes that
// are going to be used to construct graphs.
class EventSystem {
 public:
  // Adds a new module with the given name to the EventSystem. A module is
  // simply a collection of related nodes.
  Module* AddModule(const std::string& module_name);

  // Returns a pointer to a module given its name.
  const Module* GetModule(const std::string& module_name) const;

 private:
  typedef std::unordered_map<std::string, Module> ModuleDictionary;

  // TODO: Consider changing over to using integer keys instead of std::strings.
  ModuleDictionary modules_;
};

}  // breadboard

#endif  // BREADBOARD_EVENT_SYSTEM_H_
