#pragma once

struct checksum_stri
{
    unsigned int checksum;
};

struct checksum_stri_pair
{
    const char* str;
    checksum_stri str_checksum;
};