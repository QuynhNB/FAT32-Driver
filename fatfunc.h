/*+===================================================================
  File:

  Summary:

  Author:

  Rev History:

----------------------------------------------------------------------
  Copyright 2015-2016 Radial Technologies, Pty Ltd
===================================================================+*/

#pragma once
#include "fatstruc.h"

//Handy FAT32 macro functions!
#define SECTOR2OFFSET(mbr, sectnum)            (sectnum * bps)
#define CLUST2OFFSET(mbr, clustnum)            (((mbr.bps * mbr.spc) * clustnum)) //Cluster Number to offset
#define CLUST2OFFSETR(mbr, clustnum, rootdir)  (((mbr.fat_bps * mbr.fat_spc) * clustnum) + rootdir) //Give the offset of the file on the disk


uint32_t    fat_rootdir(FAT32_MBR* mbr); //Offset into the disk our root directory lies
uint8_t     fat_initvolume32(FAT32_MBR* mbr);


