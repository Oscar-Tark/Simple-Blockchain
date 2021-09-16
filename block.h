struct Chain {
	unsigned int current_internal_length;
	struct Block* block_addrs[0];
};

struct Block {
	unsigned long index;
	const char* message;
	unsigned int amount;
	unsigned char* prev_hash;
};
