//
//  Node.cpp
//  DistribDB
//
//  Created by Saagar Patel on 3/25/13.
//  Copyright (c) 2013 Saagar Patel. All rights reserved.
//

#include "Node.h"
#include "Group.h"

using DistribDB::Parameter::Node;
using DistribDB::Parameter::Group;
using DistribDB::Network::Host;

Node::Node(Identifier i,
     std::string n,
     DistribDB::Network::Host::Identifier o,
     Group::ptr p)
{
    id = i;
    name = n;
    owner = o;
    parent = p;
}

Group::ptr Node::getParent()
{
    return parent;
}

void Node::setParent(Group::ptr adoptee)
{
    parent = adoptee;
}

const Host::Identifier Node::getOwner() const
{
    return owner;
}

const Node::Identifier Node::getIdentifier() const
{
    return id;
}

const std::string& Node::getName() const
{
    return name;
}

boost::signals2::connection Node::addHandler(const OnUpdateSlotType &slot)
{
    return signal.connect(slot);
}

void Node::notify()
{
    signal(shared_from_this());
}