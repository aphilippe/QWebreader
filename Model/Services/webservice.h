#ifndef WEBSERVICEa_H
#define WEBSERVICEa_H

#include <string>

class Web;

class WebService
{
public:
    WebService();
    Web* createWebWithUrl(const std::string& url);
};

#endif // WEBSERVICEa_H
