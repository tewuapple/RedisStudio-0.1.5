﻿#ifndef SSDBHashModel_INCLUDED
#define SSDBHashModel_INCLUDED

#include "AbstractSSDBModel.h"

class SSDBHashModel : public AbstractSSDBModel
{
public:
    SSDBHashModel(ssdb::Client* client);

    virtual bool GetData(const std::string& key, RedisResult& results);

    virtual bool UpdateData(const std::string& key,      
        const std::string& oldValue,  
        const std::string& newValue,
        int idx,
        const std::string& field="");
};

#endif
