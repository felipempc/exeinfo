#ifndef DOSEXEINFO_H
#define DOSEXEINFO_H

typedef unsigned char byte;     // 8 bits
typedef unsigned short word;     // 16 bits
typedef unsigned int dword;     // 32 bits
typedef unsigned long qword;     // 64 bits

#define MZSIGNATURE 0x5A4D


struct mzheader {
    word ID;
    word nbytespage;
    word totalpages;
    word nrelocentries;
    word headersizeparagraphs;
    word minparagmem;
    word maxparag;
    word initssrelstart;
    word initsp;
    word checksum;
    dword csip_start;
    word offsetreloctable;
    word overlaynumber;
};


#endif // !EXEINFOMAIN_H