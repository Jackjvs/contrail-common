/*
 * Copyright (c) 2013 Juniper Networks, Inc. All rights reserved.
 */

#ifndef __HTTP_REQUEST_H__
#define __HTTP_REQUEST_H__

#include <map>
#include <string>

#include "http_parser/http_parser.h"

class HttpRequest {
public:
    typedef std::map<std::string, std::string> HeaderMap;

    HttpRequest();

    void SetMethod(http_method method) { method_ = method; }
    // clobbers argument
    void SetUrl(std::string *url) {
	url_.swap(*url);
    }
    void PushHeader(const std::string &key, const std::string &value) {
	headers_.insert(make_pair(key, value));
    }

    std::string ToString() const;

    std::string UrlPath() const;
    std::string UrlQuery() const;
private:
    http_method method_;
    std::string url_;
    HeaderMap headers_;
};

#endif
