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

namespace @NAMESPACE@ {
    
    enum class LocalScope {
        on_stack,
        on_heap
    };
        
    enum class Scopes {
        literal,      // a literal value, has not even an adress
        local,        // a local value. only valid in local scope
        owned,        // a heap allocated value. Only owner has access.
        shared,       // a value which might be shared inside a single thread/task
        communicate,  // a value used to communicate between threads/tasks/processes. TODO in progress
    };


    enum class Accessibilit {
        constant,
        view,
        mutable_
    };

    
    enum class ValueOrReference {
        value,
        __cpp_rvalue_references
        
    };
    
    // TODO
    using Byte = unsigned char;

    template<Scopes _scope>
    class Scope {
        static constexpr Scopes scope = _scope;

    };

    using Literal = Scope<Scopes::literal>; 
    using Const = Scope<Scopes::constLocal>; 
    using Mutale = Scope<Scopes::mutableLocal>; 
    using Owned = Scope<Scopes::Owned>; 
    using Shared = Scope<Scopes::shared>; 
    using Communicator = Scope<Scopes::communicate>; 

    
}
