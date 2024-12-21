#pragma once
#include "headers.h"

char* removeSubdomain(const char* subdomain, const char* fullDomain);
char* reverseDomainParts(const char* input);
void printSubtreeReversed(Node* node, char* path, int depth);
void printNodesAtDepth(Node* node, int targetDepth);
Node* findNodeAtDepth(Node* node, const char* name, int targetDepth);