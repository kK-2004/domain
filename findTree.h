#pragma once
#include "headers.h"
#include "tools.h"

// 查找一个域名，返回对应的节点（完整匹配）
Node* findExactNode(Node* node, const char* domain);
void findVagueNode(Node* node, const char* domain);