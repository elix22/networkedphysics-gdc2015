#include "Common.h"
#include "Memory.h"

using namespace protocol;

#include "Block.h"

void test_block()
{
    printf( "test_block\n" );

    memory::initialize();
    {
        const int BlockSize = 256 * 1024;
        Allocator & a = memory::default_allocator();
        Block * block = PROTOCOL_NEW( a, Block, a, BlockSize );
        assert( block );
        assert( block->GetAllocator() == &memory::default_allocator() );
        assert( block->GetSize() == BlockSize );
        assert( block->IsValid() );
        uint8_t * data = block->GetData();
        memset( data, 0, BlockSize );
        PROTOCOL_DELETE( a, Block, block );
    }
    memory::shutdown();
}