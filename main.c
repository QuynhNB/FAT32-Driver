#include <stdio.h>
#include <stdlib.h>

#include "fatstruc.h"
#include "fatfunc.h"

int main()
{
    FILE* img = fopen("drive.bin", "rb");
    FAT32_MBR* mbr = malloc(sizeof(FAT32_MBR));
    FAT32_FILE files[6];

    //Read our bios-block into our FAT32_MBR struct
    fseek(img, 0, SEEK_SET);
    fread(mbr, 1, sizeof(FAT32_MBR), img);
    rewind(img);


    uint32_t root = fat_rootdir(mbr);
    fseek(img, root, SEEK_SET);

    for(int i = 0; i < 6; i++)
    {
        fread(&files[i], 1, sizeof(FAT32_FILE), img);
    }
    rewind(img);

    uint32_t clus = (files[2].fat_clushi << 8) | files[2].fat_cluslo;
    uint32_t sect = ((clus - 2) * (mbr->fat_bps * mbr->fat_spc) + root);

    char buff[0x200];

    fseek(img, sect, SEEK_SET);
    fread(buff, 1, 0x200, img);

    printf("%s", buff);

    return 0;
}
