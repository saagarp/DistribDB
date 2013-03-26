//
//  Parameter.h
//  DistribDB
//
//  Created by Saagar Patel on 3/25/13.
//  Copyright (c) 2013 Saagar Patel. All rights reserved.
//

#ifndef __DistribDB__Parameter__
#define __DistribDB__Parameter__

#include <iostream>
#include <boost/signals2.hpp>
#include "Group.h"

namespace DistribDB
{
    namespace Parameter
    {
        class Parameter : public Node
        {
            // types
        public:
            // Parameter value structure
            typedef boost::variant<int, std::string> ValueType;
            
            // Use boost shared pointers
            typedef boost::shared_ptr<Parameter> ptr;
            
            // Parameter lists are vectors of Parameter shared pointers
            typedef std::vector< ptr > list;
            
        public:
                        
            // Update parameter value
            virtual void set(ValueType what);
            
            // Retreive parameter value
            virtual ValueType get();
                        
        protected:
            ValueType value;
        };
    }
}

#endif /* defined(__DistribDB__Parameter__) */
