struct Block {
	unsigned long index;
	const char* message;
	unsigned int amount;
	unsigned char* prev_hash;
};

struct Chain {
        int length;
        void** block_addrs[];
};

