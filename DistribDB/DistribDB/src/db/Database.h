//
//  Database.h
//  DistribDB
//
//  Basic database implementation on top of Group/Parameter/Node.
//  Allows for access of members and submembers by string key, including
//  automatic creation of any needed parent groups or members.
//
//  Created by Saagar Patel on 3/25/13.
//  Copyright (c) 2013 Saagar Patel. All rights reserved.
//

#ifndef __DistribDB__Database__
#define __DistribDB__Database__

#include <iostream>
#include "Group.h"
#include "Parameter.h"

namespace DistribDB
{
    namespace Database
    {
        class Database
        {
        public:
            // Does a key exist in the system?
            void exists(std::string path);
            
            // Look up an existing key, or exception if not found
            DistribDB::Parameter::Parameter::ValueType lookup(std::string path);
            
            // Create a new key, or exception if already exists
            void create(std::string path, DistribDB::Parameter::Parameter::ValueType value);
            
            // Modify an existing key, or exception if it doesn't exist
            void modify(std::string path, DistribDB::Parameter::Parameter::ValueType value);
            
            // Delete an existing key, or exception if it doesn't exist
            DistribDB::Parameter::Parameter::ValueType remove(std::string path);
            
            // Dump database structure to stream
            void dump(std::ostream &where);
            
        private:
            DistribDB::Parameter::Group::ptr root;
        };
    }
}

#endif /* defined(__DistribDB__Database__) */
