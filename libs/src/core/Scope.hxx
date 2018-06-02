/*
 * <one line to give the program's name and a brief idea of what it does.>
 * Copyright (C) 2017  <copyright holder> <email>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <catch.hpp>


namespace NAMESPACE {

enum class ScopeCardinal {
    literal_,    // a literal value, has not even an adress
    const_,      // a value with an adress, but it is not changeable after being constructed.
    view_,       // a read only value. May be changed by someone else
    owned_,      // a local or heap allocated value. Only owner has access
    shared_,     // a value which might be shared inside a single thread/task
    sync_,       // a value used to communicate between threads/tasks/processes. TODO in progress
    distributed_ // a distributed value, might be (partly and temporarly) out of sync TODO in progress
};

using Byte = unsigned char;

template<ScopeCardinal _scope>
enum class Scope {
    ScopeCardinal scope = _scope;

    constexpr bool isLiteral = (scope == literal_);
    constexpr bool isConst = (scope <= const_);
    constexpr bool isMutable = !isConst(scope >= owned_);
    constexpr bool isOnHeap = (scope == view_);
    constexpr bool isOwn = (scope == owned_);
    constexpr bool isConst = (scope == const_);
    constexpr bool isConst = (scope == const_);
    constexpr bool isConst = (scope == const_);

};

using Literal = Scope<literal_>; 

}
