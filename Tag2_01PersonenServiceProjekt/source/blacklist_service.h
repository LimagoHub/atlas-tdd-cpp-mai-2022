//
// Created by JoachimWagner on 31.05.2022.
//

#ifndef PERSONENSERVICE_BLACKLIST_SERVICE_H
#define PERSONENSERVICE_BLACKLIST_SERVICE_H
#include "person.h"
class blacklist_service {
public:
    virtual bool is_blacklisted(const person& person_) const = 0;
};

#endif //PERSONENSERVICE_BLACKLIST_SERVICE_H
