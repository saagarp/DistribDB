//
//  Node.h
//  DistribDB
//
//  Generic class used as a parent for any type of database node.
//
//  Created by Saagar Patel on 3/25/13.
//  Copyright (c) 2013 Saagar Patel. All rights reserved.
//

#ifndef __DistribDB__Node__
#define __DistribDB__Node__

#include <iostream>
#include <boost/signals2.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <limits.h>

#include "Host.h"

namespace DistribDB
{
    namespace Parameter
    {
        class Group;
        
        class Node : public boost::enable_shared_from_this<Node>
        {
            /*
             * types
             */
        public:
            // Parameter identifiers are a 64-bit unsigned integer.
            typedef long long unsigned Identifier;
            
            // Pointer type
            typedef boost::shared_ptr< Node > ptr;
            
            // List type
            typedef std::vector< ptr > list;
            
            // event Signal type
            typedef boost::signals2::signal<void (ptr)> OnUpdate;
            
            // event Slot type
            typedef OnUpdate::slot_type OnUpdateSlotType;
            
            /*
             * constants
             */
        public:
            static const Identifier INVALID = ULLONG_MAX;
            
            /*
             * constructors
             */
        public:
            Node(Identifier id,
                 std::string name,
                 DistribDB::Network::Host::Identifier owner,
                 boost::shared_ptr<Group> parent);
            
            /*
             * member functions
             */
        public:
            // Identify owner of this parameter.
            virtual const DistribDB::Network::Host::Identifier getOwner() const;
            
            // Unique identifier of this node.
            virtual const Identifier getIdentifier() const;
            
            // Human-readable name of this node.
            virtual const std::string& getName() const;
            
            // Get parent group
            virtual boost::shared_ptr<Group> getParent();
            
            // Register a handler for updates
            virtual boost::signals2::connection addHandler(const OnUpdateSlotType &slot);
            
        protected:
            OnUpdate signal;
            
            // Notify all subscribers to this node that its structure or
            // contents have been updated
            virtual void notify();
            
        private:
            // Parameter metadata
            DistribDB::Network::Host::Identifier    owner;
            Identifier                              id;
            std::string                             name;
            boost::shared_ptr<Group>                parent;
            
            // Assign this parameter to a different parent group. This does not trigger
            // any events since the contents of this node are unchanged.
            virtual void setParent(boost::shared_ptr<Group> parent);
            
            friend class Group;
        };
    }
}

#endif /* defined(__DistribDB__Node__) */
