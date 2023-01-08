/* config */

#include <memory>
#include "farm.h"


const char *producer_name = "127.0.0.1";
const char *consumer_name = "127.0.0.1";
const char *device_name = "mlx5_0";


// use port and port + 1
uint16_t port = 12344;






FarmParameter param{0, 80};

// in bytes
size_t msg_size_list[] = {64, 512, 4 * 1024, 32 * 1024, 256 * 1024, 1 * 1024 * 1024};


// feel free to change thput_data_size during your debugging
// but it has to be set to 100GB when testing.
size_t thput_data_size = 1LL * 1024 * 1024 * 1024 /* 1GB */;

inline uint64_t get_iterations(size_t _msg_size) {
    return thput_data_size / _msg_size;
}

// return the size of ringbuffer, in bytes
size_t get_ringbuffer_size(size_t msgsize) {
    return 2048 * msgsize;
}

// if you want to verify all data being tranfered, enable this macro.
// otherwise, the benchmark will only put a pair of guard.

// #define VERIFY_ALL 1