// src/f3staging/f3blk_00b80000_o2.cpp - Fallout 3 STAGING unit (f3_staging_units.py, 3 Nov 2026) for functions with no New Vegas counterpart
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include "../../include/fnv_asm_helpers.h"

// @f3 0x00b9be60 (community match, verified in this file)
namespace f3m_00b9be60 {
// Adapted for f3decomp from the published zlib 1.2.1 inflate implementation.
// Original authors: Jean-loup Gailly and Mark Adler. This altered C++ version
// expands macros, renames the reserved C identifier "this", and binds helpers.
// Payload checksum handling follows the observed game variant; gzip header CRC remains.
// Upstream: https://github.com/madler/zlib/tree/v1.2.1
/* zlib.h -- interface of the 'zlib' general purpose compression library
  version 1.2.1, November 17th, 2003

  Copyright (C) 1995-2003 Jean-loup Gailly and Mark Adler

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.

  Jean-loup Gailly        Mark Adler
  jloup@gzip.org          madler@alumni.caltech.edu

  The data format used by the zlib library is described by RFCs (Request for
  Comments) 1950 to 1952 in the files http://www.ietf.org/rfc/rfc1950.txt
  (zlib format), rfc1951.txt (deflate format) and rfc1952.txt (gzip format).
*/

typedef unsigned char Byte;
typedef unsigned char Bytef;
typedef unsigned int uInt;
typedef unsigned long uLong;
typedef void* voidpf;
typedef void* (*alloc_func)(void*,uInt,uInt);
typedef void (*free_func)(void*,void*);
struct internal_state;
typedef struct z_stream_s {
    Bytef    *next_in;  
    uInt     avail_in;  
    uLong    total_in;  

    Bytef    *next_out; 
    uInt     avail_out; 
    uLong    total_out; 

    char     *msg;      
    struct internal_state  *state; 

    alloc_func zalloc;  
    free_func  zfree;   
    voidpf     opaque;  

    int     data_type;  
    uLong   adler;      
    uLong   reserved;   
} z_stream;
typedef z_stream* z_streamp;
typedef struct {
    unsigned char op;           
    unsigned char bits;         
    unsigned short val;         
} code;
typedef enum {
    CODES,
    LENS,
    DISTS
} codetype;
typedef enum {
    HEAD,       

    FLAGS,      
    TIME,       
    OS,         
    EXLEN,      
    EXTRA,      
    NAME,       
    COMMENT,    
    HCRC,       

    DICTID,     
    DICT,       
        TYPE,       
        TYPEDO,     
        STORED,     
        COPY,       
        TABLE,      
        LENLENS,    
        CODELENS,   
            LEN,        
            LENEXT,     
            DIST,       
            DISTEXT,    
            MATCH,      
            LIT,        
    CHECK,      

    LENGTH,     

    DONE,       
    BAD,        
    MEM,        
    SYNC        
} inflate_mode;
struct inflate_state {
    inflate_mode mode;          
    int last;                   
    int wrap;                   
    int havedict;               
    int flags;                  
    unsigned long check;        
    unsigned long total;        
        
    unsigned wbits;             
    unsigned wsize;             
    unsigned whave;             
    unsigned write;             
    unsigned char  *window;  
        
    unsigned long hold;         
    unsigned bits;              
        
    unsigned length;            
    unsigned offset;            
        
    unsigned extra;             
        
    code const  *lencode;    
    code const  *distcode;   
    unsigned lenbits;           
    unsigned distbits;          
        
    unsigned ncode;             
    unsigned nlen;              
    unsigned ndist;             
    unsigned have;              
    code  *next;             
    unsigned short lens[320];   
    unsigned short work[288];   
    code codes[1440];         
};
unsigned long __cdecl FUN_00b9f650(unsigned long,const unsigned char*,unsigned int);
unsigned long __cdecl FUN_00b9f270(unsigned long,const unsigned char*,unsigned int);
int __cdecl FUN_00b9ed90(codetype,unsigned short*,unsigned,code**,unsigned*,unsigned short*);
void __cdecl FUN_00b9e8d0(z_streamp,unsigned);
static int updatewindow(z_streamp,unsigned);
void* __cdecl FUN_00bffa60(void*,const void*,unsigned int);

static void fixedtables(inflate_state* state)
{

    static const code lenfix[512] = {
        {96,7,0},{0,8,80},{0,8,16},{20,8,115},{18,7,31},{0,8,112},{0,8,48},
        {0,9,192},{16,7,10},{0,8,96},{0,8,32},{0,9,160},{0,8,0},{0,8,128},
        {0,8,64},{0,9,224},{16,7,6},{0,8,88},{0,8,24},{0,9,144},{19,7,59},
        {0,8,120},{0,8,56},{0,9,208},{17,7,17},{0,8,104},{0,8,40},{0,9,176},
        {0,8,8},{0,8,136},{0,8,72},{0,9,240},{16,7,4},{0,8,84},{0,8,20},
        {21,8,227},{19,7,43},{0,8,116},{0,8,52},{0,9,200},{17,7,13},{0,8,100},
        {0,8,36},{0,9,168},{0,8,4},{0,8,132},{0,8,68},{0,9,232},{16,7,8},
        {0,8,92},{0,8,28},{0,9,152},{20,7,83},{0,8,124},{0,8,60},{0,9,216},
        {18,7,23},{0,8,108},{0,8,44},{0,9,184},{0,8,12},{0,8,140},{0,8,76},
        {0,9,248},{16,7,3},{0,8,82},{0,8,18},{21,8,163},{19,7,35},{0,8,114},
        {0,8,50},{0,9,196},{17,7,11},{0,8,98},{0,8,34},{0,9,164},{0,8,2},
        {0,8,130},{0,8,66},{0,9,228},{16,7,7},{0,8,90},{0,8,26},{0,9,148},
        {20,7,67},{0,8,122},{0,8,58},{0,9,212},{18,7,19},{0,8,106},{0,8,42},
        {0,9,180},{0,8,10},{0,8,138},{0,8,74},{0,9,244},{16,7,5},{0,8,86},
        {0,8,22},{64,8,0},{19,7,51},{0,8,118},{0,8,54},{0,9,204},{17,7,15},
        {0,8,102},{0,8,38},{0,9,172},{0,8,6},{0,8,134},{0,8,70},{0,9,236},
        {16,7,9},{0,8,94},{0,8,30},{0,9,156},{20,7,99},{0,8,126},{0,8,62},
        {0,9,220},{18,7,27},{0,8,110},{0,8,46},{0,9,188},{0,8,14},{0,8,142},
        {0,8,78},{0,9,252},{96,7,0},{0,8,81},{0,8,17},{21,8,131},{18,7,31},
        {0,8,113},{0,8,49},{0,9,194},{16,7,10},{0,8,97},{0,8,33},{0,9,162},
        {0,8,1},{0,8,129},{0,8,65},{0,9,226},{16,7,6},{0,8,89},{0,8,25},
        {0,9,146},{19,7,59},{0,8,121},{0,8,57},{0,9,210},{17,7,17},{0,8,105},
        {0,8,41},{0,9,178},{0,8,9},{0,8,137},{0,8,73},{0,9,242},{16,7,4},
        {0,8,85},{0,8,21},{16,8,258},{19,7,43},{0,8,117},{0,8,53},{0,9,202},
        {17,7,13},{0,8,101},{0,8,37},{0,9,170},{0,8,5},{0,8,133},{0,8,69},
        {0,9,234},{16,7,8},{0,8,93},{0,8,29},{0,9,154},{20,7,83},{0,8,125},
        {0,8,61},{0,9,218},{18,7,23},{0,8,109},{0,8,45},{0,9,186},{0,8,13},
        {0,8,141},{0,8,77},{0,9,250},{16,7,3},{0,8,83},{0,8,19},{21,8,195},
        {19,7,35},{0,8,115},{0,8,51},{0,9,198},{17,7,11},{0,8,99},{0,8,35},
        {0,9,166},{0,8,3},{0,8,131},{0,8,67},{0,9,230},{16,7,7},{0,8,91},
        {0,8,27},{0,9,150},{20,7,67},{0,8,123},{0,8,59},{0,9,214},{18,7,19},
        {0,8,107},{0,8,43},{0,9,182},{0,8,11},{0,8,139},{0,8,75},{0,9,246},
        {16,7,5},{0,8,87},{0,8,23},{64,8,0},{19,7,51},{0,8,119},{0,8,55},
        {0,9,206},{17,7,15},{0,8,103},{0,8,39},{0,9,174},{0,8,7},{0,8,135},
        {0,8,71},{0,9,238},{16,7,9},{0,8,95},{0,8,31},{0,9,158},{20,7,99},
        {0,8,127},{0,8,63},{0,9,222},{18,7,27},{0,8,111},{0,8,47},{0,9,190},
        {0,8,15},{0,8,143},{0,8,79},{0,9,254},{96,7,0},{0,8,80},{0,8,16},
        {20,8,115},{18,7,31},{0,8,112},{0,8,48},{0,9,193},{16,7,10},{0,8,96},
        {0,8,32},{0,9,161},{0,8,0},{0,8,128},{0,8,64},{0,9,225},{16,7,6},
        {0,8,88},{0,8,24},{0,9,145},{19,7,59},{0,8,120},{0,8,56},{0,9,209},
        {17,7,17},{0,8,104},{0,8,40},{0,9,177},{0,8,8},{0,8,136},{0,8,72},
        {0,9,241},{16,7,4},{0,8,84},{0,8,20},{21,8,227},{19,7,43},{0,8,116},
        {0,8,52},{0,9,201},{17,7,13},{0,8,100},{0,8,36},{0,9,169},{0,8,4},
        {0,8,132},{0,8,68},{0,9,233},{16,7,8},{0,8,92},{0,8,28},{0,9,153},
        {20,7,83},{0,8,124},{0,8,60},{0,9,217},{18,7,23},{0,8,108},{0,8,44},
        {0,9,185},{0,8,12},{0,8,140},{0,8,76},{0,9,249},{16,7,3},{0,8,82},
        {0,8,18},{21,8,163},{19,7,35},{0,8,114},{0,8,50},{0,9,197},{17,7,11},
        {0,8,98},{0,8,34},{0,9,165},{0,8,2},{0,8,130},{0,8,66},{0,9,229},
        {16,7,7},{0,8,90},{0,8,26},{0,9,149},{20,7,67},{0,8,122},{0,8,58},
        {0,9,213},{18,7,19},{0,8,106},{0,8,42},{0,9,181},{0,8,10},{0,8,138},
        {0,8,74},{0,9,245},{16,7,5},{0,8,86},{0,8,22},{64,8,0},{19,7,51},
        {0,8,118},{0,8,54},{0,9,205},{17,7,15},{0,8,102},{0,8,38},{0,9,173},
        {0,8,6},{0,8,134},{0,8,70},{0,9,237},{16,7,9},{0,8,94},{0,8,30},
        {0,9,157},{20,7,99},{0,8,126},{0,8,62},{0,9,221},{18,7,27},{0,8,110},
        {0,8,46},{0,9,189},{0,8,14},{0,8,142},{0,8,78},{0,9,253},{96,7,0},
        {0,8,81},{0,8,17},{21,8,131},{18,7,31},{0,8,113},{0,8,49},{0,9,195},
        {16,7,10},{0,8,97},{0,8,33},{0,9,163},{0,8,1},{0,8,129},{0,8,65},
        {0,9,227},{16,7,6},{0,8,89},{0,8,25},{0,9,147},{19,7,59},{0,8,121},
        {0,8,57},{0,9,211},{17,7,17},{0,8,105},{0,8,41},{0,9,179},{0,8,9},
        {0,8,137},{0,8,73},{0,9,243},{16,7,4},{0,8,85},{0,8,21},{16,8,258},
        {19,7,43},{0,8,117},{0,8,53},{0,9,203},{17,7,13},{0,8,101},{0,8,37},
        {0,9,171},{0,8,5},{0,8,133},{0,8,69},{0,9,235},{16,7,8},{0,8,93},
        {0,8,29},{0,9,155},{20,7,83},{0,8,125},{0,8,61},{0,9,219},{18,7,23},
        {0,8,109},{0,8,45},{0,9,187},{0,8,13},{0,8,141},{0,8,77},{0,9,251},
        {16,7,3},{0,8,83},{0,8,19},{21,8,195},{19,7,35},{0,8,115},{0,8,51},
        {0,9,199},{17,7,11},{0,8,99},{0,8,35},{0,9,167},{0,8,3},{0,8,131},
        {0,8,67},{0,9,231},{16,7,7},{0,8,91},{0,8,27},{0,9,151},{20,7,67},
        {0,8,123},{0,8,59},{0,9,215},{18,7,19},{0,8,107},{0,8,43},{0,9,183},
        {0,8,11},{0,8,139},{0,8,75},{0,9,247},{16,7,5},{0,8,87},{0,8,23},
        {64,8,0},{19,7,51},{0,8,119},{0,8,55},{0,9,207},{17,7,15},{0,8,103},
        {0,8,39},{0,9,175},{0,8,7},{0,8,135},{0,8,71},{0,9,239},{16,7,9},
        {0,8,95},{0,8,31},{0,9,159},{20,7,99},{0,8,127},{0,8,63},{0,9,223},
        {18,7,27},{0,8,111},{0,8,47},{0,9,191},{0,8,15},{0,8,143},{0,8,79},
        {0,9,255}
    };

    static const code distfix[32] = {
        {16,5,1},{23,5,257},{19,5,17},{27,5,4097},{17,5,5},{25,5,1025},
        {21,5,65},{29,5,16385},{16,5,3},{24,5,513},{20,5,33},{28,5,8193},
        {18,5,9},{26,5,2049},{22,5,129},{64,5,0},{16,5,2},{23,5,385},
        {19,5,25},{27,5,6145},{17,5,7},{25,5,1537},{21,5,97},{29,5,24577},
        {16,5,4},{24,5,769},{20,5,49},{28,5,12289},{18,5,13},{26,5,3073},
        {22,5,193},{64,5,0}
    };

    state->lencode = lenfix;
    state->lenbits = 9;
    state->distcode = distfix;
    state->distbits = 5;
}

// pdb: updatewindow | inflate.obj | fnv360_0822_debug, call_seq + bridge(call_gap|call_gap) + skyrim(call_dedup), high
static int updatewindow(z_streamp strm,unsigned out)
{
    struct inflate_state  *state;
    unsigned copy, dist;

    state = (struct inflate_state  *)strm->state;

    if (state->window == 0) {
        state->window = (unsigned char  *)
                        (*((strm)->zalloc))((strm)->opaque, (1U << state->wbits), (sizeof(unsigned char)));
        if (state->window == 0) return 1;
    }

    if (state->wsize == 0) {
        state->wsize = 1U << state->wbits;
        state->write = 0;
        state->whave = 0;
    }

    copy = out - strm->avail_out;
    if (copy >= state->wsize) {
        FUN_00bffa60(state->window, strm->next_out - state->wsize, state->wsize);
        state->write = 0;
        state->whave = state->wsize;
    }
    else {
        dist = state->wsize - state->write;
        if (dist > copy) dist = copy;
        FUN_00bffa60(state->window + state->write, strm->next_out - copy, dist);
        copy -= dist;
        if (copy) {
            FUN_00bffa60(state->window, strm->next_out - copy, copy);
            state->write = copy;
            state->whave = state->wsize;
        }
        else {
            state->write += dist;
            if (state->write == state->wsize) state->write = 0;
            if (state->whave < state->wsize) state->whave += dist;
        }
    }
    return 0;
}

// pdb: inflate | inflate.obj | fnv360_0822_retail, ustr + bridge(ustr|ustr) + skyrim(ustr), high
int __cdecl inflate(z_streamp strm,int flush)
{
    struct inflate_state  *state;
    unsigned char  *next;    
    unsigned char  *put;     
    unsigned have, left;        
    unsigned long hold;         
    unsigned bits;              
    unsigned in, out;           
    unsigned copy;              
    unsigned char  *from;    
    code here;                  
    code last;                  
    unsigned len;               
    int ret;                    

    unsigned char hbuf[4];      

    static const unsigned short order[19] = 
        {16, 17, 18, 0, 8, 7, 9, 6, 10, 5, 11, 4, 12, 3, 13, 2, 14, 1, 15};

    if (strm == 0 || strm->state == 0 || strm->next_out == 0 ||
        (strm->next_in == 0 && strm->avail_in != 0))
        return (-2);

    state = (struct inflate_state  *)strm->state;
    if (state->mode == TYPE) state->mode = TYPEDO;      
    do { put = strm->next_out; left = strm->avail_out; next = strm->next_in; have = strm->avail_in; hold = state->hold; bits = state->bits; } while (0);
    in = have;
    out = left;
    ret = 0;
    for (;;)
        switch (state->mode) {
        case HEAD:
            if (state->wrap == 0) {
                state->mode = TYPEDO;
                break;
            }
            do { while (bits < (unsigned)(16)) do { if (have == 0) goto inf_leave; have--; hold += (unsigned long)(*next++) << bits; bits += 8; } while (0); } while (0);

            if ((state->wrap & 2) && hold == 0x8b1f) {  
                state->check = FUN_00b9f650(0L, 0, 0);
                do { hbuf[0] = (unsigned char)(hold); hbuf[1] = (unsigned char)((hold) >> 8); state->check = FUN_00b9f650(state->check, hbuf, 2); } while (0);
                do { hold = 0; bits = 0; } while (0);
                state->mode = FLAGS;
                break;
            }
            state->flags = 0;           
            if (!(state->wrap & 1) ||   

                ((((unsigned)hold & ((1U << (8)) - 1)) << 8) + (hold >> 8)) % 31) {
                strm->msg = (char *)"incorrect header check";
                state->mode = BAD;
                break;
            }
            if (((unsigned)hold & ((1U << (4)) - 1)) != 8) {
                strm->msg = (char *)"unknown compression method";
                state->mode = BAD;
                break;
            }
            do { hold >>= (4); bits -= (unsigned)(4); } while (0);
            if (((unsigned)hold & ((1U << (4)) - 1)) + 8 > state->wbits) {
                strm->msg = (char *)"invalid window size";
                state->mode = BAD;
                break;
            }
            strm->adler = state->check = FUN_00b9f270(0L, 0, 0);
            state->mode = hold & 0x200 ? DICTID : TYPE;
            do { hold = 0; bits = 0; } while (0);
            break;

        case FLAGS:
            do { while (bits < (unsigned)(16)) do { if (have == 0) goto inf_leave; have--; hold += (unsigned long)(*next++) << bits; bits += 8; } while (0); } while (0);
            state->flags = (int)(hold);
            if ((state->flags & 0xff) != 8) {
                strm->msg = (char *)"unknown compression method";
                state->mode = BAD;
                break;
            }
            if (state->flags & 0xe000) {
                strm->msg = (char *)"unknown header flags set";
                state->mode = BAD;
                break;
            }
            if (state->flags & 0x0200) do { hbuf[0] = (unsigned char)(hold); hbuf[1] = (unsigned char)((hold) >> 8); state->check = FUN_00b9f650(state->check, hbuf, 2); } while (0);
            do { hold = 0; bits = 0; } while (0);
            state->mode = TIME;
        case TIME:
            do { while (bits < (unsigned)(32)) do { if (have == 0) goto inf_leave; have--; hold += (unsigned long)(*next++) << bits; bits += 8; } while (0); } while (0);
            if (state->flags & 0x0200) do { hbuf[0] = (unsigned char)(hold); hbuf[1] = (unsigned char)((hold) >> 8); hbuf[2] = (unsigned char)((hold) >> 16); hbuf[3] = (unsigned char)((hold) >> 24); state->check = FUN_00b9f650(state->check, hbuf, 4); } while (0);
            do { hold = 0; bits = 0; } while (0);
            state->mode = OS;
        case OS:
            do { while (bits < (unsigned)(16)) do { if (have == 0) goto inf_leave; have--; hold += (unsigned long)(*next++) << bits; bits += 8; } while (0); } while (0);
            if (state->flags & 0x0200) do { hbuf[0] = (unsigned char)(hold); hbuf[1] = (unsigned char)((hold) >> 8); state->check = FUN_00b9f650(state->check, hbuf, 2); } while (0);
            do { hold = 0; bits = 0; } while (0);
            state->mode = EXLEN;
        case EXLEN:
            if (state->flags & 0x0400) {
                do { while (bits < (unsigned)(16)) do { if (have == 0) goto inf_leave; have--; hold += (unsigned long)(*next++) << bits; bits += 8; } while (0); } while (0);
                state->length = (unsigned)(hold);
                if (state->flags & 0x0200) do { hbuf[0] = (unsigned char)(hold); hbuf[1] = (unsigned char)((hold) >> 8); state->check = FUN_00b9f650(state->check, hbuf, 2); } while (0);
                do { hold = 0; bits = 0; } while (0);
            }
            state->mode = EXTRA;
        case EXTRA:
            if (state->flags & 0x0400) {
                copy = state->length;
                if (copy > have) copy = have;
                if (copy) {
                    if (state->flags & 0x0200)
                        state->check = FUN_00b9f650(state->check, next, copy);
                    have -= copy;
                    next += copy;
                    state->length -= copy;
                }
                if (state->length) goto inf_leave;
            }
            state->mode = NAME;
        case NAME:
            if (state->flags & 0x0800) {
                if (have == 0) goto inf_leave;
                copy = 0;
                do {
                    len = (unsigned)(next[copy++]);
                } while (len && copy < have);
                if (state->flags & 0x02000)
                    state->check = FUN_00b9f650(state->check, next, copy);
                have -= copy;
                next += copy;
                if (len) goto inf_leave;
            }
            state->mode = COMMENT;
        case COMMENT:
            if (state->flags & 0x1000) {
                if (have == 0) goto inf_leave;
                copy = 0;
                do {
                    len = (unsigned)(next[copy++]);
                } while (len && copy < have);
                if (state->flags & 0x02000)
                    state->check = FUN_00b9f650(state->check, next, copy);
                have -= copy;
                next += copy;
                if (len) goto inf_leave;
            }
            state->mode = HCRC;
        case HCRC:
            if (state->flags & 0x0200) {
                do { while (bits < (unsigned)(16)) do { if (have == 0) goto inf_leave; have--; hold += (unsigned long)(*next++) << bits; bits += 8; } while (0); } while (0);
                if (hold != (state->check & 0xffff)) {
                    strm->msg = (char *)"header crc mismatch";
                    state->mode = BAD;
                    break;
                }
                do { hold = 0; bits = 0; } while (0);
            }
            strm->adler = state->check = FUN_00b9f650(0L, 0, 0);
            state->mode = TYPE;
            break;

        case DICTID:
            do { while (bits < (unsigned)(32)) do { if (have == 0) goto inf_leave; have--; hold += (unsigned long)(*next++) << bits; bits += 8; } while (0); } while (0);
            strm->adler = state->check = ((((hold) >> 24) & 0xff) + (((hold) >> 8) & 0xff00) + (((hold) & 0xff00) << 8) + (((hold) & 0xff) << 24));
            do { hold = 0; bits = 0; } while (0);
            state->mode = DICT;
        case DICT:
            if (state->havedict == 0) {
                do { strm->next_out = put; strm->avail_out = left; strm->next_in = next; strm->avail_in = have; state->hold = hold; state->bits = bits; } while (0);
                return 2;
            }
            strm->adler = state->check = FUN_00b9f270(0L, 0, 0);
            state->mode = TYPE;
        case TYPE:
            if (flush == 5) goto inf_leave;
        case TYPEDO:
            if (state->last) {
                do { hold >>= bits & 7; bits -= bits & 7; } while (0);
                state->mode = CHECK;
                break;
            }
            do { while (bits < (unsigned)(3)) do { if (have == 0) goto inf_leave; have--; hold += (unsigned long)(*next++) << bits; bits += 8; } while (0); } while (0);
            state->last = ((unsigned)hold & ((1U << (1)) - 1));
            do { hold >>= (1); bits -= (unsigned)(1); } while (0);
            switch (((unsigned)hold & ((1U << (2)) - 1))) {
            case 0:                             
                ;
                state->mode = STORED;
                break;
            case 1:                             
                fixedtables(state);
                state->mode = LEN;              
                break;
            case 2:                             
                ;
                state->mode = TABLE;
                break;
            case 3:
                strm->msg = (char *)"invalid block type";
                state->mode = BAD;
            }
            do { hold >>= (2); bits -= (unsigned)(2); } while (0);
            break;
        case STORED:
            do { hold >>= bits & 7; bits -= bits & 7; } while (0);                         
            do { while (bits < (unsigned)(32)) do { if (have == 0) goto inf_leave; have--; hold += (unsigned long)(*next++) << bits; bits += 8; } while (0); } while (0);
            if ((hold & 0xffff) != ((hold >> 16) ^ 0xffff)) {
                strm->msg = (char *)"invalid stored block lengths";
                state->mode = BAD;
                break;
            }
            state->length = (unsigned)hold & 0xffff;
            do { hold = 0; bits = 0; } while (0);
            state->mode = COPY;
        case COPY:
            copy = state->length;
            if (copy) {
                if (copy > have) copy = have;
                if (copy > left) copy = left;
                if (copy == 0) goto inf_leave;
                FUN_00bffa60(put, next, copy);
                have -= copy;
                next += copy;
                left -= copy;
                put += copy;
                state->length -= copy;
                break;
            }
            state->mode = TYPE;
            break;
        case TABLE:
            do { while (bits < (unsigned)(14)) do { if (have == 0) goto inf_leave; have--; hold += (unsigned long)(*next++) << bits; bits += 8; } while (0); } while (0);
            state->nlen = ((unsigned)hold & ((1U << (5)) - 1)) + 257;
            do { hold >>= (5); bits -= (unsigned)(5); } while (0);
            state->ndist = ((unsigned)hold & ((1U << (5)) - 1)) + 1;
            do { hold >>= (5); bits -= (unsigned)(5); } while (0);
            state->ncode = ((unsigned)hold & ((1U << (4)) - 1)) + 4;
            do { hold >>= (4); bits -= (unsigned)(4); } while (0);

            if (state->nlen > 286 || state->ndist > 30) {
                strm->msg = (char *)"too many length or distance symbols";
                state->mode = BAD;
                break;
            }

            state->have = 0;
            state->mode = LENLENS;
        case LENLENS:
            while (state->have < state->ncode) {
                do { while (bits < (unsigned)(3)) do { if (have == 0) goto inf_leave; have--; hold += (unsigned long)(*next++) << bits; bits += 8; } while (0); } while (0);
                state->lens[order[state->have++]] = (unsigned short)((unsigned)hold & ((1U << (3)) - 1));
                do { hold >>= (3); bits -= (unsigned)(3); } while (0);
            }
            while (state->have < 19)
                state->lens[order[state->have++]] = 0;
            state->next = state->codes;
            state->lencode = (code const  *)(state->next);
            state->lenbits = 7;
            ret = FUN_00b9ed90(CODES, state->lens, 19, &(state->next),
                                &(state->lenbits), state->work);
            if (ret) {
                strm->msg = (char *)"invalid code lengths set";
                state->mode = BAD;
                break;
            }
            state->have = 0;
            state->mode = CODELENS;
        case CODELENS:
            while (state->have < state->nlen + state->ndist) {
                for (;;) {
                    here = state->lencode[((unsigned)hold & ((1U << (state->lenbits)) - 1))];
                    if ((unsigned)(here.bits) <= bits) break;
                    do { if (have == 0) goto inf_leave; have--; hold += (unsigned long)(*next++) << bits; bits += 8; } while (0);
                }
                if (here.val < 16) {
                    do { while (bits < (unsigned)(here.bits)) do { if (have == 0) goto inf_leave; have--; hold += (unsigned long)(*next++) << bits; bits += 8; } while (0); } while (0);
                    do { hold >>= (here.bits); bits -= (unsigned)(here.bits); } while (0);
                    state->lens[state->have++] = here.val;
                }
                else {
                    if (here.val == 16) {
                        do { while (bits < (unsigned)(here.bits + 2)) do { if (have == 0) goto inf_leave; have--; hold += (unsigned long)(*next++) << bits; bits += 8; } while (0); } while (0);
                        do { hold >>= (here.bits); bits -= (unsigned)(here.bits); } while (0);
                        if (state->have == 0) {
                            strm->msg = (char *)"invalid bit length repeat";
                            state->mode = BAD;
                            break;
                        }
                        len = state->lens[state->have - 1];
                        copy = 3 + ((unsigned)hold & ((1U << (2)) - 1));
                        do { hold >>= (2); bits -= (unsigned)(2); } while (0);
                    }
                    else if (here.val == 17) {
                        do { while (bits < (unsigned)(here.bits + 3)) do { if (have == 0) goto inf_leave; have--; hold += (unsigned long)(*next++) << bits; bits += 8; } while (0); } while (0);
                        do { hold >>= (here.bits); bits -= (unsigned)(here.bits); } while (0);
                        len = 0;
                        copy = 3 + ((unsigned)hold & ((1U << (3)) - 1));
                        do { hold >>= (3); bits -= (unsigned)(3); } while (0);
                    }
                    else {
                        do { while (bits < (unsigned)(here.bits + 7)) do { if (have == 0) goto inf_leave; have--; hold += (unsigned long)(*next++) << bits; bits += 8; } while (0); } while (0);
                        do { hold >>= (here.bits); bits -= (unsigned)(here.bits); } while (0);
                        len = 0;
                        copy = 11 + ((unsigned)hold & ((1U << (7)) - 1));
                        do { hold >>= (7); bits -= (unsigned)(7); } while (0);
                    }
                    if (state->have + copy > state->nlen + state->ndist) {
                        strm->msg = (char *)"invalid bit length repeat";
                        state->mode = BAD;
                        break;
                    }
                    while (copy--)
                        state->lens[state->have++] = (unsigned short)len;
                }
            }

            state->next = state->codes;
            state->lencode = (code const  *)(state->next);
            state->lenbits = 9;
            ret = FUN_00b9ed90(LENS, state->lens, state->nlen, &(state->next),
                                &(state->lenbits), state->work);
            if (ret) {
                strm->msg = (char *)"invalid literal/lengths set";
                state->mode = BAD;
                break;
            }
            state->distcode = (code const  *)(state->next);
            state->distbits = 6;
            ret = FUN_00b9ed90(DISTS, state->lens + state->nlen, state->ndist,
                            &(state->next), &(state->distbits), state->work);
            if (ret) {
                strm->msg = (char *)"invalid distances set";
                state->mode = BAD;
                break;
            }
            state->mode = LEN;
        case LEN:
            if (have >= 6 && left >= 258) {
                do { strm->next_out = put; strm->avail_out = left; strm->next_in = next; strm->avail_in = have; state->hold = hold; state->bits = bits; } while (0);
                FUN_00b9e8d0(strm, out);
                do { put = strm->next_out; left = strm->avail_out; next = strm->next_in; have = strm->avail_in; hold = state->hold; bits = state->bits; } while (0);
                break;
            }
            for (;;) {
                here = state->lencode[((unsigned)hold & ((1U << (state->lenbits)) - 1))];
                if ((unsigned)(here.bits) <= bits) break;
                do { if (have == 0) goto inf_leave; have--; hold += (unsigned long)(*next++) << bits; bits += 8; } while (0);
            }
            if (here.op && (here.op & 0xf0) == 0) {
                last = here;
                for (;;) {
                    here = state->lencode[last.val +
                            (((unsigned)hold & ((1U << (last.bits + last.op)) - 1)) >> last.bits)];
                    if ((unsigned)(last.bits + here.bits) <= bits) break;
                    do { if (have == 0) goto inf_leave; have--; hold += (unsigned long)(*next++) << bits; bits += 8; } while (0);
                }
                do { hold >>= (last.bits); bits -= (unsigned)(last.bits); } while (0);
            }
            do { hold >>= (here.bits); bits -= (unsigned)(here.bits); } while (0);
            state->length = (unsigned)here.val;
            if ((int)(here.op) == 0) {
                state->mode = LIT;
                break;
            }
            if (here.op & 32) {
                state->mode = TYPE;
                break;
            }
            if (here.op & 64) {
                strm->msg = (char *)"invalid literal/length code";
                state->mode = BAD;
                break;
            }
            state->extra = (unsigned)(here.op) & 15;
            state->mode = LENEXT;
        case LENEXT:
            if (state->extra) {
                do { while (bits < (unsigned)(state->extra)) do { if (have == 0) goto inf_leave; have--; hold += (unsigned long)(*next++) << bits; bits += 8; } while (0); } while (0);
                state->length += ((unsigned)hold & ((1U << (state->extra)) - 1));
                do { hold >>= (state->extra); bits -= (unsigned)(state->extra); } while (0);
            }
            state->mode = DIST;
        case DIST:
            for (;;) {
                here = state->distcode[((unsigned)hold & ((1U << (state->distbits)) - 1))];
                if ((unsigned)(here.bits) <= bits) break;
                do { if (have == 0) goto inf_leave; have--; hold += (unsigned long)(*next++) << bits; bits += 8; } while (0);
            }
            if ((here.op & 0xf0) == 0) {
                last = here;
                for (;;) {
                    here = state->distcode[last.val +
                            (((unsigned)hold & ((1U << (last.bits + last.op)) - 1)) >> last.bits)];
                    if ((unsigned)(last.bits + here.bits) <= bits) break;
                    do { if (have == 0) goto inf_leave; have--; hold += (unsigned long)(*next++) << bits; bits += 8; } while (0);
                }
                do { hold >>= (last.bits); bits -= (unsigned)(last.bits); } while (0);
            }
            do { hold >>= (here.bits); bits -= (unsigned)(here.bits); } while (0);
            if (here.op & 64) {
                strm->msg = (char *)"invalid distance code";
                state->mode = BAD;
                break;
            }
            state->offset = (unsigned)here.val;
            state->extra = (unsigned)(here.op) & 15;
            state->mode = DISTEXT;
        case DISTEXT:
            if (state->extra) {
                do { while (bits < (unsigned)(state->extra)) do { if (have == 0) goto inf_leave; have--; hold += (unsigned long)(*next++) << bits; bits += 8; } while (0); } while (0);
                state->offset += ((unsigned)hold & ((1U << (state->extra)) - 1));
                do { hold >>= (state->extra); bits -= (unsigned)(state->extra); } while (0);
            }
            if (state->offset > state->whave + out - left) {
                strm->msg = (char *)"invalid distance too far back";
                state->mode = BAD;
                break;
            }
            state->mode = MATCH;
        case MATCH:
            if (left == 0) goto inf_leave;
            copy = out - left;
            if (state->offset > copy) {         
                copy = state->offset - copy;
                if (copy > state->write) {
                    copy -= state->write;
                    from = state->window + (state->wsize - copy);
                }
                else
                    from = state->window + (state->write - copy);
                if (copy > state->length) copy = state->length;
            }
            else {                              
                from = put - state->offset;
                copy = state->length;
            }
            if (copy > left) copy = left;
            left -= copy;
            state->length -= copy;
            do {
                *put++ = *from++;
            } while (--copy);
            if (state->length == 0) state->mode = LEN;
            break;
        case LIT:
            if (left == 0) goto inf_leave;
            *put++ = (unsigned char)(state->length);
            left--;
            state->mode = LEN;
            break;
        case CHECK:
            if (state->wrap) {
                do { while (bits < (unsigned)(32)) do { if (have == 0) goto inf_leave; have--; hold += (unsigned long)(*next++) << bits; bits += 8; } while (0); } while (0);
                out -= left;
                strm->total_out += out;
                state->total += out;
                if (out)
                    strm->adler = state->check =
                        0L;
                out = left;

                do { hold = 0; bits = 0; } while (0);
            }

            state->mode = LENGTH;
        case LENGTH:
            if (state->wrap && state->flags) {
                do { while (bits < (unsigned)(32)) do { if (have == 0) goto inf_leave; have--; hold += (unsigned long)(*next++) << bits; bits += 8; } while (0); } while (0);
                if (hold != (state->total & 0xffffffffUL)) {
                    strm->msg = (char *)"incorrect length check";
                    state->mode = BAD;
                    break;
                }
                do { hold = 0; bits = 0; } while (0);
            }

            state->mode = DONE;
        case DONE:
            ret = 1;
            goto inf_leave;
        case BAD:
            ret = (-3);
            goto inf_leave;
        case MEM:
            return (-4);
        case SYNC:
        default:
            return (-2);
        }

  inf_leave:
    do { strm->next_out = put; strm->avail_out = left; strm->next_in = next; strm->avail_in = have; state->hold = hold; state->bits = bits; } while (0);
    if (state->wsize || (state->mode < CHECK && out != strm->avail_out))
        if (updatewindow(strm, out)) {
            state->mode = MEM;
            return (-4);
        }
    in -= strm->avail_in;
    out -= strm->avail_out;
    strm->total_in += in;
    strm->total_out += out;
    state->total += out;
    if (state->wrap && out)
        strm->adler = state->check =
            0L;
    strm->data_type = state->bits + (state->last ? 64 : 0) +
                      (state->mode == TYPE ? 128 : 0);
    if (((in == 0 && out == 0) || flush == 4) && ret == 0)
        ret = (-5);
    return ret;
}
}   // namespace f3m_00b9be60
