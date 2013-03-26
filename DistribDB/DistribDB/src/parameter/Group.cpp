//
//  Group.cpp
//  DistribDB
//
//  Created by Saagar Patel on 3/25/13.
//  Copyright (c) 2013 Saagar Patel. All rights reserved.
//

#include "Group.h"

using namespace DistribDB::Parameter;


Node::list Group::getChildren()
{
    return Parameter::Node::list(); // XXX
}

// Obtain subparameter by name
Node::ptr Group::getChild(std::string name)
{
    GroupStorageByName &byName = store.get<hash_name>();
    GroupStorageByName::iterator i( byName.find(name) );
    
    if(i == byName.end())
        return Node::ptr();
    else
        return *i;
}

// Obtain subparameter by ID
Node::ptr Group::getChild(Identifier id)
{
    GroupStorageByID &byID = store.get<hash_id>();
    GroupStorageByID::iterator i( byID.find(id) );
    
    if(i == byID.end())
        return Node::ptr();
    else
        return *i;
}

// Add subparameter
void Group::addChild(Node::ptr child)
{
    store.insert(child);
    child->setParent(boost::enable_shared_from_this<Group>::shared_from_this());
    notify();
}