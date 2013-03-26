//
//  Group.h
//  DistribDB
//
//  Created by Saagar Patel on 3/25/13.
//  Copyright (c) 2013 Saagar Patel. All rights reserved.
//

#ifndef __DistribDB__Group__
#define __DistribDB__Group__

#include <iostream>
#include <boost/multi_index_container.hpp>
#include <boost/multi_index/mem_fun.hpp>
#include <boost/multi_index/hashed_index.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/enable_shared_from_this.hpp>

#include "Node.h"
#include "Parameter.h"

namespace DistribDB
{
    namespace Parameter
    {
        class Group : public Node, public boost::enable_shared_from_this<Group>
        {
            /*
             * types
             */
        public:
            // Use boost shared pointers
            typedef boost::shared_ptr<Group> ptr;
            
            // Group lists are vectors of Group shared pointers
            typedef std::vector< ptr > list;

        private:
            // Tags
            struct ordered;
            struct hash_id;
            struct hash_name;

            // Child storage structure
            typedef boost::multi_index_container<
                boost::shared_ptr<DistribDB::Parameter::Node>,
                boost::multi_index::indexed_by<
                    boost::multi_index::ordered_unique<
                        boost::multi_index::tag<ordered>,
                        boost::multi_index::const_mem_fun<
                            DistribDB::Parameter::Node,
                            const DistribDB::Parameter::Node::Identifier,
                            &DistribDB::Parameter::Node::getIdentifier
                        >
                    >,
                    boost::multi_index::hashed_unique<
                        boost::multi_index::tag<hash_id>,
                        boost::multi_index::const_mem_fun<
                            DistribDB::Parameter::Node,
                            const DistribDB::Parameter::Node::Identifier,
                            &DistribDB::Parameter::Node::getIdentifier
                        >
                    >,
                    boost::multi_index::hashed_non_unique<
                        boost::multi_index::tag<hash_name>,
                        boost::multi_index::const_mem_fun<
                            DistribDB::Parameter::Node,
                            const std::string&,
                            &DistribDB::Parameter::Node::getName
                        >
                    >
                >
            > GroupStorage;
            
            typedef GroupStorage::index<ordered>::type   GroupStorageOrdered;
            typedef GroupStorage::index<hash_name>::type GroupStorageByName;
            typedef GroupStorage::index<hash_id>::type   GroupStorageByID;

        public:
            // Obtain list of members
            virtual Parameter::Node::list getChildren();
            
            // Obtain subparameter by name
            virtual Parameter::Node::ptr getChild(std::string name);
            
            // Obtain subparameter by ID
            virtual Parameter::Node::ptr getChild(DistribDB::Parameter::Node::Identifier id);

            // Add subparameter
            virtual void addChild(Parameter::Node::ptr node);

        private:
            GroupStorage store;
        };
    }
}

#endif /* defined(__DistribDB__Group__) */
