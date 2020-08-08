#pragma once

struct xml_element
{
    const char* name;
    xml_element* next;
    xml_element* elements;
    char* text;
};