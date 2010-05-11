struct blockinfo {
    bool occupied;
    int vm;
    int block;

};

struct pagingtable {

    blockinfo table[4096];

};
