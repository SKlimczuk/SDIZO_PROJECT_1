//
//  Array.hpp
//  SDIZO_PROJECT_1
//
//  Created by Szymon Klimczuk on 24.02.2018.
//  Copyright © 2018 Szymon Klimczuk. All rights reserved.
//

#ifndef Array_hpp
#define Array_hpp

#include <stdio.h>

class Array
{
public:
    void addAtBegin();
    void addAtMiddle();
    void addAtBottom();
    
    void deleteFirst();
    void deleteMiddle();
    void deleteLast();
    
    void findElement();
};

#endif /* Array_hpp */
