#ifndef DOSEXEINFO_H
#define DOSEXEINFO_H

typedef unsigned char byte;
typedef unsigned short word;
typedef unsigned int dword;
typedef unsigned long qword;

#define MZSIGNATURE 0x4D5A


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